#include "npctables.h"

NpcTables::NpcTables()
{

}

QString NpcTables::generateAdventurer(int tier)
{
    RandomTable table;
    QString gender = npcGender();
    QString advClass = AdventurerClass(tier);
    QString composite = gender + " " + advClass + " (" + AdventurerRace() + ")";
    QString package = adventurerPackage(tier);
    QString loot = LootTables::generateIndividualTreasure(tier);

    table.addEntry(composite, 6);
    table.addEntry(package);
    int spellbookChance = 5;
    bool isCaster = (
                advClass == "Apprentice Wizard (vge)"
                || advClass == "Enchanter (vge)"
                || advClass == "Transmuter (vge)"
                || advClass == "Mage"
                || advClass == "Conjurer (vge)"
                || advClass == "Diviner (vge)"
                || advClass == "Abjurer (vge)"
                || advClass == "Evoker (vge)"
                || advClass == "Necromancer (vge)"
                || advClass == "Archmage"
                );
    if (isCaster) spellbookChance = 30;
    bool hasSpellbook = Dice::roll(1,100) < spellbookChance;
    if (hasSpellbook) {
         loot += "\nSpellbook:\n" + LootTables::generateSpellbook(tier);
    }

    return table.getRollTableEntry() + "\nLoot: " + loot;
}

QString NpcTables::generateMotivatedAdventurer(int tier)
{
    QString npc = generateAdventurer(tier);
    QString disposition = npcDisposition();
    if (disposition == "friendly") {
        disposition += " -" + EncounterTables::friendlyHumanoidUrbanActivity();
    }
    return npc + "\n(" + disposition + ")";
}

QString NpcTables::adventuringParty(int tier)
{
    int numMembers = Dice::roll(1,4) + 2;
    QString party = "NPC Party: \n========\n";
    for (int i=0; i < numMembers; ++i) {
        party += generateAdventurer(tier);
        party += "\n------\n";
    }
    return party;
}

QString NpcTables::AdventurerRace()
{
    RandomTable table;

    table.addEntry(commonRace(), 8);
    table.addEntry(uncommonRace(), 2);
    table.addEntry(rareRace());

    return table.getRollTableEntry();
}

QString NpcTables::AdventurerClass(int tier)
{
    RandomTable table;

    table.addEntry("Commoner"); // 0
    table.addEntry("Bandit"); // 1/8
    table.addEntry("Cultist"); // 1/8
    table.addEntry("Guard"); // 1/8
    table.addEntry("Tribal Warrior"); // 1/8
    table.addEntry("Noble"); // 1/8
    table.addEntry("Acolyte"); // 1/4
    table.addEntry("Apprentice Wizard (vge)"); // 1/4
    table.addEntry("Scout"); // 1/2
    table.addEntry("Thug"); // 1/2
    table.addEntry("Spy"); // 1

    if (tier > 1) {
        table.addEntry("Bandit Captain"); // 2
        table.addEntry("Berzerker"); // 2
        table.addEntry("Cult Fanatic"); // 2
        table.addEntry("Druid"); // 2
        table.addEntry("Priest"); // 2
        table.addEntry("Wererat"); // 2
        table.addEntry("Bard (vge)"); // 2
    }

    else if (tier > 2) {
        table.addEntry("Knight"); // 3
        table.addEntry("Veteran"); // 3
        table.addEntry("Werewolf"); // 3
        table.addEntry("Doppleganger"); // 3
        table.addEntry("Archer (vge)"); // 3
        table.addEntry("Illusionist (vge)"); // 3
        table.addEntry("Martial Arts Adept (vge)"); // 3
        table.addEntry("Swashbuckler (vge)"); // 3
        table.addEntry("Wereboar"); // 4
        table.addEntry("Weretiger"); // 4
        table.addEntry("Warlock of the Archfey (vge)"); // 4
    }

    else if (tier > 3){
        table.addEntry("Gladiator"); // 5
        table.addEntry("Werebear"); // 5
        table.addEntry("Vampire Spawn"); // 5
        table.addEntry("Enchanter (vge)"); // 5
        table.addEntry("Master Thief (vge)"); // 5
        table.addEntry("Transmuter (vge)"); // 5
        table.addEntry("Mage"); // 6
        table.addEntry("Conjurer (vge)"); // 6
        table.addEntry("Warlock of the Great Old One (vge)"); // 6
        table.addEntry("Warlock of the Fiend (vge)"); // 7
        table.addEntry("Assassin"); // 8
        table.addEntry("Blackguard (vge)"); // 8
        table.addEntry("Diviner (vge)"); // 8
        table.addEntry("Abjurer (vge)"); // 9
        table.addEntry("Champion (vge)"); // 9
        table.addEntry("Evoker (vge)"); // 9
        table.addEntry("Necromancer (vge)"); // 9
        table.addEntry("War Priest (vge)"); // 9
        table.addEntry("Archmage"); // 12
        table.addEntry("Archdruid (vge)"); // 12
        table.addEntry("Warlord (vge)"); // 12
        table.addEntry("Vampire"); // 13
    }

    return table.getRollTableEntry();
}

QString NpcTables::adventurerPackage(int tier)
{
    RandomTable table;

    table.addEntry("Kobold Inventor (vge)"); // 1/4
    table.addEntry(npcGender() + " Half-ogre"); // 1
    table.addEntry(npcGender() + "Yuan-ti Pureblood"); // 1
    table.addEntry("Kuo-toa Whip"); // 1
    table.addEntry("Kobold Dragonshield (vge)"); // 1
    table.addEntry("Kobold Scale Sorcerer"); // 1

    if (tier > 1) {
        table.addEntry(npcGender() + "Githzerai Monk"); // 2
        table.addEntry("Lizardfolk Shaman"); // 2
        table.addEntry("Orc Eye of Gruumsh"); // 2
        table.addEntry("Quaggoth"); // 2
        table.addEntry(npcGender() + "Hobgoblin Iron Shadow (vge)"); // 2
        table.addEntry("Orc Claw of Luthic (vge)"); // 2
        table.addEntry("Orc Hand of Yurtrus (vge)"); // 2
    }

    else if (tier > 2) {
        table.addEntry(npcGender() + "Githyanki Warrior"); // 3
        table.addEntry("Orc Red Fang of Shargaas (vge)"); // 3
        table.addEntry("Orc War Chief"); // 4
        table.addEntry("Hobgoblin Devastator (vge)"); // 4
        table.addEntry("Orc Blade of Ilneval (vge)"); // 4
    }

    else if (tier > 3){
        table.addEntry(npcGender() + "Drow Elite Warrior"); // 5
        table.addEntry(npcGender() + "Githzerai Zerth"); // 6
        table.addEntry("Kuo-toa Priest"); // 6
        table.addEntry("Drow Mage"); // 7
        table.addEntry("Drow Priestess of Lolth"); // 8
        table.addEntry(npcGender() + "Githyanki Knight"); // 8
    }

    return table.getRollTableEntry();
}

QString NpcTables::commonerRace()
{
    RandomTable raceTable;
    raceTable.addEntry(commonRace(), 2);
    raceTable.addEntry(uncommonRace());
    return raceTable.getRollTableEntry();
}

QString NpcTables::commonRace()
{
    RandomTable table;

    RandomTable human;
    human.addEntry("Calishite");
    human.addEntry("Chondathan");
    human.addEntry("Damaran");
    human.addEntry("Illuskan");
    human.addEntry("Mulan");
    human.addEntry("Rashemi");
    human.addEntry("Shou");
    human.addEntry("Teghyrian");
    human.addEntry("Turami");
    human.addEntry("Arkaiun");
    human.addEntry("Bedine");
    human.addEntry("Ffolk");
    human.addEntry("Gur");
    human.addEntry("Halruaan");
    human.addEntry("Imaskari");
    human.addEntry("Nar");
    human.addEntry("Shaaran");
    human.addEntry("Tuigan");
    human.addEntry("Ulutiun");

    table.addEntry("Regional or human - " + human.getRollTableEntry(), 5);
    table.addEntry("Human - " + human.getRollTableEntry(),3);

    RandomTable elf;
    elf.addEntry("High");
    elf.addEntry("Wood");
    elf.addEntry("Moon");
    elf.addEntry("Sun");
    table.addEntry("Elf - " + elf.getRollTableEntry());

    RandomTable halfling;
    halfling.addEntry("Lightfoot");
    halfling.addEntry("Stout");
    halfling.addEntry("Strongheart");
    table.addEntry("Halfling - " + halfling.getRollTableEntry());

    RandomTable dwarf;
    dwarf.addEntry("Hill");
    dwarf.addEntry("Mountain");
    dwarf.addEntry("Gold");
    dwarf.addEntry("Shield");
    table.addEntry("Dwarf - " + dwarf.getRollTableEntry());

    return table.getRollTableEntry();
}

QString NpcTables::uncommonRace()
{
    RandomTable table;

    table.addEntry("Drow");
    table.addEntry("Half elf");
    table.addEntry("Half orc");

    RandomTable dragon;
    dragon.addEntry("Black");
    dragon.addEntry("Blue");
    dragon.addEntry("Brass");
    dragon.addEntry("Bronze");
    dragon.addEntry("Copper");
    dragon.addEntry("Gold");
    dragon.addEntry("Green");
    dragon.addEntry("Red");
    dragon.addEntry("Silver");
    dragon.addEntry("White");
    table.addEntry("Dragonborn - " + dragon.getRollTableEntry());

    table.addEntry("Teifling");

    RandomTable gnome;
    gnome.addEntry("Rock");
    gnome.addEntry("Forest");
    table.addEntry("Gnome - " + gnome.getRollTableEntry());

    return table.getRollTableEntry();
}

QString NpcTables::rareRace()
{
    RandomTable table;

    table.addEntry("Aarakocra");
    table.addEntry("Bugbear");
    table.addEntry("Duergar");
    table.addEntry("Githzerai");
    table.addEntry("Deep Gnome");
    table.addEntry("Goblin");
    table.addEntry("Hobgoblin");
    table.addEntry("Kenku");
    table.addEntry("Kobold");
    table.addEntry("Kuo-toa");
    table.addEntry("Lizardfolk");
    table.addEntry("Myconid Adult");
    table.addEntry("Orc");
    table.addEntry("Thri-kreen");
    table.addEntry("Aasimar (vgm)");
    table.addEntry("Firbolg (vgm)");
    table.addEntry("Goliath (vgm)");
    table.addEntry("Tabaxi (vgm)");
    table.addEntry("Darkling (vgm)");

    RandomTable element;
    element.addEntry("Air");
    element.addEntry("Earth");
    element.addEntry("Fire");
    element.addEntry("Water");

    table.addEntry(element.getRollTableEntry() + " Gensai (EE)");
    table.addEntry("Goliath (EE)");

    return table.getRollTableEntry();
}

QString NpcTables::npcGender()
{
    RandomTable table;
    table.addEntry("Male");
    table.addEntry("Female");
    return table.getRollTableEntry();
}

QString NpcTables::npcDisposition()
{
    RandomTable table;
    table.addEntry("friendly");
    table.addEntry("hostile");
    return table.getRollTableEntry();
}


QString NpcTables::determineAlignment()
{
    RandomTable alignment;
    alignment.addEntry("Lawful good");
    alignment.addEntry("Neutral good");
    alignment.addEntry("Chaotic good");
    alignment.addEntry("Lawful neutral");
    alignment.addEntry("Neutral");
    alignment.addEntry("Chaotic neutral");
    alignment.addEntry("Lawful evil");
    alignment.addEntry("Neutral evil");
    alignment.addEntry("Chaotic evil");
    return alignment.getRollTableEntry();
}
