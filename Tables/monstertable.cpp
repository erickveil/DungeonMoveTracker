#include "monstertable.h"

MonsterTable::MonsterTable()
{

}

QString MonsterTable::encounterLevel()
{
    RandomTable table;

    table.addEntry("Easy", 4);
    table.addEntry("Medium", 8);
    table.addEntry("Hard", 2);
    table.addEntry("Deadly");

    return table.getRollTableEntry();
}


QString MonsterTable::dungeonMonster(int tier)
{
    RandomTable table;
    QString qty;
    QString qty2;

    // tier 1
    table.addEntry("1 Mind Flayer Arcanist" + _intellegentBlock());
    table.addEntry("1 shreiker");
    table.addEntry("1 swarm of insects");
    table.addEntry("1 deep gnome" + _raceBlock());
    table.addEntry("1 rust monster" + _animalBlock());
    table.addEntry("1 dwarf prospector (scout) looking for gold"
                   + _motivatedBlock());
    table.addEntry("1 carrion crawler" + _animalBlock());
    table.addEntry("1 hell hound" + _animalBlock());
    table.addEntry("1 ochre jelly");
    table.addEntry("1 nothic" + _raceBlock());
    table.addEntry("1 giant toad" + _animalBlock());
    table.addEntry("1 Minotaur" + _animalBlock());
    table.addEntry("1 Minotaur Skeleton");
    table.addEntry("1 mimic");
    table.addEntry("1 doppleganger" + _npcCommonerBlock());
    table.addEntry("1 intellect devourer" + _animalBlock());
    table.addEntry("1 spectator");
    table.addEntry("1 gibbering mouther");
    table.addEntry("1 water wierd");
    table.addEntry("1 giant constrictor snake" + _animalBlock());
    table.addEntry("1 chuul" + _intellegentBlock());
    table.addEntry("1 salamander" + _intellegentBlock());
    table.addEntry("1 ghost" + _npcCommonerBlock());
    table.addEntry("1 flameskull");
    table.addEntry("1 wraith");
    table.addEntry("1 druid with 1 polar bear (cave bear)" + _npcCommonerBlock());
    table.addEntry("1 earth elemental");
    table.addEntry("1 black pudding");
    table.addEntry("1 beholder zombie");
    table.addEntry("1 bone naga");
    table.addEntry("1 otyugh");
    table.addEntry("1 roper");
    table.addEntry("1 vampire spawn" + _raceBlock());
    table.addEntry("1 chimera" + _animalBlock());
    table.addEntry("1 mind flayer" + _intellegentBlock());
    table.addEntry("1 spirit naga" + _intellegentBlock());
    table.addEntry("1 Babau Demon (VGM)" + _intellegentBlock());
    table.addEntry("1 Slithering Tracker (VGM)");
    table.addEntry(NpcTables::adventuringParty(tier));
    table.addEntry(NpcTables::generateAdventurer(tier));

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " gray oozes");
    table.addEntry(qty + " gargoyles");
    table.addEntry(qty + " Cave Fishers(VGM)");
    table.addEntry(qty + " Choldrith (VGM)" + _intellegentBlock());
    table.addEntry(qty + " Flail snails (VGM)" + _animalBlock());
    table.addEntry(qty + " Trappers (VGM)");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " giant lizards" + _animalBlock());
    table.addEntry(qty + " spectres" + _npcCommonerBlock());
    table.addEntry(qty + " grells");
    table.addEntry(qty + " ettins" + _raceBlock());
    table.addEntry(qty + " hook horrors" + _animalBlock());
    table.addEntry("1 quaggoth thonot with " + qty + " quaggoths" + _raceBlock());
    table.addEntry(qty + " Meenlocks (VGM)");
    table.addEntry(qty + " Shadow Mastiffs (VGM)" + _animalBlock());

    qty = QString::number(Dice::roll(1,3) + 1);
    table.addEntry(qty + " giant poisonous snakes" + _animalBlock());

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " violet fungi");
    table.addEntry(qty + " bugbears" + _raceBlock());
    table.addEntry(qty + " fire snakes" + _animalBlock());
    qty2 = QString::number(Dice::roll(5,4));
    table.addEntry(qty + " myconid adults with " + qty2 + " myconid sprouts" +_intellegentBlock());
    table.addEntry(qty + " wights" + _npcCommonerBlock());
    table.addEntry(qty + " ogres" + _raceBlock());
    table.addEntry(qty + " dwarf explorers (veterans)" + _raceBlock());
    table.addEntry(qty + " phase spiders" + _animalBlock());
    qty2 = QString::number(Dice::roll(2,10));
    table.addEntry("1 hobgoblin captain with " + qty + " half-ogres and "
                   + qty2 + " hobgoblins" + _raceBlock());
    qty = QString::number(Dice::roll(1,4));
    qty2 = QString::number(Dice::roll(2,8));
    table.addEntry("1 orc Eye of Gruumsh with " + qty + " orogs and " + qty2
                   + " orcs" + _intellegentBlock());
    qty = QString::number(Dice::roll(1,4));
    qty2 = QString::number(Dice::roll(1,10));
    table.addEntry(qty + " ghasts with " + qty2 + " ghouls");
    table.addEntry(qty + " Vargouilles (VGM)");

    qty = QString::number(Dice::roll(1,4) + 3);
    table.addEntry(qty + " swarms of bats");

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty + " giant fire beetles");
    table.addEntry(qty + " kobolds" + _intellegentBlock());
    table.addEntry(qty + " humans (tribal warriors) seeking the way to the "
                         "surface, fleeing thier Underdark oppressors"
                   + _motivatedBlock());
    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty + " grimlocks" + _raceBlock());
    table.addEntry(qty + " piercers");
    table.addEntry("1 goblin boss with " + qty + " goblins" + _intellegentBlock());

    qty = QString::number(Dice::roll(4,4));
    table.addEntry(qty + " grimlocks" + _raceBlock());

    qty = QString::number(Dice::roll(5,4));
    table.addEntry(qty + " duergar" + _raceBlock());

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " giant spiders");
    table.addEntry(qty + " Gazers (VGM)");
    table.addEntry(qty + " Chitines (VGM)" + _intellegentBlock());
    table.addEntry(qty + " Darklings (VGM)" + _raceBlock());
    table.addEntry("1 Darkling Elder and " + qty + " Darklings (VGM)"
                   + _raceBlock());
    table.addEntry(qty + " Firenewts (VGM)" + _intellegentBlock());
    table.addEntry("1 Firenewt Warlock of Imix and " + qty
                   + " Firenewts (VGM)" + _intellegentBlock());
    table.addEntry(qty + " Swarm of Rot Grubs (VGM)");

    qty = QString::number(Dice::roll(1,6) + 3);
    table.addEntry(qty + " hobgoblins" + _raceBlock());

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty + " stirges");
    table.addEntry(qty + " kobolds" + _intellegentBlock());
    table.addEntry(qty + " kuo-toa" + _intellegentBlock());
    table.addEntry(qty + " drow" + _raceBlock());

    qty = QString::number(Dice::roll(1,8));
    table.addEntry(qty + " darkmantles");

    qty = QString::number(Dice::roll(1,8) + 1);
    table.addEntry(qty + " flumphs");
    table.addEntry(qty + " stirges");
    table.addEntry(qty + " drow" + _raceBlock());
    table.addEntry(qty + " giant bats");
    table.addEntry(qty + " orcs" + _intellegentBlock());
    table.addEntry(qty + " quaggoth spore servants" + _intellegentBlock());
    table.addEntry("1 kuo-toa monitor with " + qty + " kuo-toa whips"
                   + _intellegentBlock());

    qty = QString::number(Dice::roll(2,8) + 1);
    table.addEntry(qty + " troglodytes" + _intellegentBlock());

    qty = QString::number(Dice::roll(1,10));
    table.addEntry(qty + " troglodytes" + _intellegentBlock());
    table.addEntry(qty + " goblins" + _intellegentBlock());

    qty = QString::number(Dice::roll(1,10) + 5);
    table.addEntry(qty + " winged kobolds" + _intellegentBlock());

    qty = QString::number(Dice::roll(2,10));
    table.addEntry(qty + " giant centipedes");

    qty = QString::number(Dice::roll(1,12));
    table.addEntry(qty + " giant rats" + _animalBlock());
    table.addEntry(qty + " kuo-toa" + _intellegentBlock());
    table.addEntry(qty + " gas spores");

    qty = QString::number(Dice::roll(1,19));
    table.addEntry(qty + " shadows");

    return table.getRollTableEntry() + _loot(tier);
}

QString MonsterTable::undermountainMonster(int tier)
{
    int normalUnderdarkChance = 85;
    bool isNormalUnderdark = Dice::roll(1, 100) < normalUnderdarkChance;
    if (isNormalUnderdark) { return dungeonMonster(tier); }


    RandomTable table;

    table.addEntry("Rat spy of the Sewer Rats");
    table.addEntry("NPC party: Wyvernroost Feduciary");
    table.addEntry("Bloodfist Goblin expedition: A lasher leads a unit of "
                   "hunters in search of prey.");
    table.addEntry("Drakefinger Kobold Treasure Hunters: The Dragon Shield "
                   "leads a unit of kobods on a treasure scavenging expedition "
                   "for their draconic master.");
    table.addEntry("Belorem Deoblood: Powerful archmage apprentice of Halaster "
                   "and his apprentice necromancer. Will geas the party into "
                   "finding a MacGuffin for him on this level.");
    table.addEntry("A wererat rogue of the Sewer Rats tails the party, hoping "
                   "to pilfer some gear. A second one might cause a "
                   "distraction, giving him advantage.");
    table.addEntry("A guard, leading commoner 'adventurers' on an expedition "
                   "for the Wyvernroost", 2);
    table.addEntry("A group of bandits looking for plunder", 3);
    table.addEntry("A commoner prisoner being led by thugs or bandits to sell "
                   "as slaves to the bloodfist goblins", 2);
    table.addEntry("Wight Warrior encounter: A wight leading a pack of zombies "
                   "unleashes them to slay the party, then moves on.");

    return table.getRollTableEntry();
}

QString MonsterTable::urbanEncounterXge(int tier)
{
    RandomTable table;

    QString animalMotive = " - " + EncounterTables::animalDowntime();
    QString creatureMotive = " - " + EncounterTables::creatureAttacksUrban();
    QString humanoidMotive = " - " + EncounterTables::humanoidAttacksUrban();


    QString qty;
    QString qty2;
    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty +" cats" + animalMotive);

    qty = QString::number(Dice::roll(2,10));
    table.addEntry(qty +" rats" + creatureMotive, 2);

    table.addEntry("1 raven perched on a signpost");

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty +" mastiffs");

    table.addEntry("1 pseudodragon" + creatureMotive);

    qty = QString::number(Dice::roll(1,6,6));
    table.addEntry(qty +" flying snakes" + creatureMotive);

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty +" kobolds" + humanoidMotive);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty +" giant centipedes" + creatureMotive);

    qty = QString::number(Dice::roll(1,8,1));
    table.addEntry(qty +" skeletons" + creatureMotive);

    qty = QString::number(Dice::roll(1,6,2));
    table.addEntry(qty +" swarms of rats" + creatureMotive, 2);

    qty = QString::number(Dice::roll(1,12));
    table.addEntry(qty +" zombies" + creatureMotive);

    table.addEntry("1 giant wasp" + creatureMotive);

    table.addEntry("1 warhorse" + animalMotive, 2);

    qty = QString::number(Dice::roll(3,4));
    table.addEntry(qty +" giant rats" + creatureMotive, 2);

    qty = QString::number(Dice::roll(2,8));
    table.addEntry(qty +" stirges" + creatureMotive);

    qty = QString::number(Dice::roll(1,3,2));
    table.addEntry(qty +" giant poisonous snakes" + creatureMotive);

    qty = QString::number(Dice::roll(1,4,2));
    table.addEntry(qty +" swarms of bats" + animalMotive);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty +" winged kobolds" + humanoidMotive);

    table.addEntry("1 crocodile" + creatureMotive);

    table.addEntry("1 swarm of insects" + creatureMotive);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty +" kenku" + humanoidMotive);

    qty = QString::number(Dice::roll(1,6,2));
    table.addEntry(qty +" smoke mephits" + creatureMotive);

    qty = QString::number(Dice::roll(1,8,1));
    table.addEntry(qty +" swarms of ravens" + animalMotive);

    table.addEntry("1 mimic", 2);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty +" ghouls" + creatureMotive, 2);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty +" spectres" + creatureMotive, 2);

    qty = QString::number(Dice::roll(1,10));
    table.addEntry(qty +" shadows" + creatureMotive, 2);

    table.addEntry("1 ghast" + creatureMotive, 2);

    table.addEntry("1 will-o-wisp" + creatureMotive, 2);

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty +" giant spiders" + creatureMotive);

    table.addEntry("1 cambion" + humanoidMotive);

    table.addEntry("1 couatl" + creatureMotive);

    table.addEntry("1 revenant" + creatureMotive);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(qty +" gargoyles" + creatureMotive);

    table.addEntry("1 invisible stalker" + creatureMotive);

    qty = QString::number(Dice::roll(1,8,1));
    table.addEntry(qty +" phase spiders" + creatureMotive);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " shadow mastiff (xge) " + creatureMotive);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " slithering trackers (xge)" + creatureMotive);

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " vargouilles (xge)" + creatureMotive);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " meenlocks (xge)" + creatureMotive);


    table.addEntry("1 water wierd" + creatureMotive);

    table.addEntry("1 wight" + creatureMotive);

    // Urban NPCs
    QString npc = "NPCs: ";
    QString npcRace = NpcTables::commonerRace();
    QString gender = NpcTables::npcGender();
    QString disposition = NpcTables::npcDisposition();
    if (disposition == "friendly") {
        disposition += " -" + friendlyHumanoidUrbanActivity();
    }
    else {
        disposition += " -" + EncounterTables::humanoidAttacksUrban();
    }

    table.addEntry(NpcTables::adventuringParty(tier) + "\n" + disposition);
    table.addEntry(NpcTables::generateAdventurer(tier) + " " + disposition);


    table.addEntry("1 shield guardian " + disposition);

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(npc + "1 " + gender + " " + npcRace + " commoner with "
                   + qty +" goats " + disposition, 2);

    table.addEntry("1 " + gender + " " + npcRace
                   + " commoner on a draft horse (" + disposition + ")");

    qty = QString::number(Dice::roll(1,2));
    qty2 = QString::number(Dice::roll(1,4));
    table.addEntry(npc + qty + " " + gender + " " + npcRace
                   + " commoners leading " + qty2 + " mules or ponies." + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace + " spy" + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace  + " Archer (xge)"
                   + "(" + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace  + " Bard (xge)"
                   + "(" + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Enchanter (xge)" + "(" + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Illusionist (xge)" + "(" + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Martial Arts Adepts (xge)" + "(" + disposition + ")");

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Master Thief (xge)" + "(" + disposition + ")", 3);

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Swashbuckler (xge)" + "(" + disposition + ")", 3);

    table.addEntry(npc + "1 " + " " + gender + " " + npcRace
                   + " Warlock of the Archfey (xge)" + "(" + disposition + ")");

    qty = QString::number(Dice::roll(1,8,1));
    table.addEntry(npc + qty +" " + " " + gender + " " + npcRace
                   + " acolytes" + "(" + disposition + ")", 2);

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(npc + qty +" " + " " + gender + " " + npcRace
                   + " bandits " + humanoidMotive, 2);

    qty = QString::number(Dice::roll(1,3,2));
    qty2 = QString::number(Dice::roll(1,10));
    table.addEntry(npc + qty + " " + gender
                   + " nobles on riding horses with an escort of " + qty2
                   + " guards" + "(" + disposition + ")", 2);

    table.addEntry(npc + "1" + " " + gender + " wererat" + humanoidMotive, 2);

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(npc + qty + " " + gender + "  half ogres" + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " priest" + "("
                   + disposition + ")", 2);

    table.addEntry(npc + "1 " + gender + " vampire spawn" + humanoidMotive);

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " ghost"
                   + disposition);

    table.addEntry(npc + "1 " + gender + " " + " succubus/incubus"
                   + humanoidMotive);

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(npc + "1 " + gender + " " + npcRace
                   + " bandit captain with " + qty + " bandits"
                   + humanoidMotive);

    qty = QString::number(Dice::roll(1,4,1));
    table.addEntry(npc + qty + " " + gender + " " + npcRace
                   + " cult fanatics" + humanoidMotive);

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " knight" + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " veteran" + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " mage" + "("
                   + disposition + ")");

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " gladiator" + "("
                   + disposition + ")");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(npc + qty +" " + gender + " " + npcRace
                   + " yuan-ti purebloods" + humanoidMotive, 2);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(npc + qty +" " + gender + " " + npcRace  + " thugs", 2);

    table.addEntry(npc + "A " + gender + " " + npcRace
                   + " doomsayer who preaches the end of the world from a "
                   "street corner", 3);

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(npc + qty +" dopplegangers (" + npcRace  + ", " + gender
                   + ")" + humanoidMotive);

    table.addEntry(npc + "1 " + gender + " oni" + humanoidMotive);

    table.addEntry(npc + "1 " + gender + " " + npcRace  + " assassin"
                   + humanoidMotive);

    qty = QString::number(Dice::roll(2,4));
    table.addEntry(npc + qty + " " + gender + " " + " darklings (XGE)"
                   + humanoidMotive);

    qty = QString::number(Dice::roll(2,3));
    table.addEntry(npc + "1 " + gender + " Darkling Elder and " + qty
                   + " darklings (XGE)" + humanoidMotive);

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(npc + "1 " + gender + " Noble with " + qty + " "
                   + guardianFoe(tier) + "(" + disposition + ")");

    qty = QString::number(Dice::roll(2,3));
    table.addEntry(npc + qty + " " + gender + " " + npcRace
                   + " apprentice mages (xge)" + "(" + disposition + ")");

    qty = QString::number(Dice::roll(2,8));
    table.addEntry(npc + qty +" " + gender + " " + npcRace  + " cultists"
                   + humanoidMotive);

    return table.getRollTableEntry();
}

/* Possibilities:
 * XGE monster table
 * unique encounter table - not what it seems/exactly what it looks like (day only)
 * side quest hook
 * NPC - needs help/hostile
 * Town crier with news/hook
 * Town watchs: friendly/hostile
 * City landmark
 * neighborhood adventure
 */


QString MonsterTable::urbanEncountersUnique()
{
    RandomTable table;

    table.addEntry("A pickpocket takes a random item or coin from the PCs and runs");
    table.addEntry("A street is closed off due to a parade in honor of one of the gods.");
    table.addEntry("People on the street dash out of the way as two youths race horses from one end to another, the party is right in their path.");
    table.addEntry("The door to a saloon bursts open and a person goes flying out to land in the street, unconscious. A large NPC stands in the doorway a moment, glaring and rubbing his fist before silently turning back inside.");
    table.addEntry("A section of the street is seeing heavy wagon traffic. A little old lady who is slow to move is having a hard time crossing.");
    table.addEntry("A wagon rushes by without stopping, its wheels hitting a mud puddle. Dex saves to avoid getting splashed.");
    table.addEntry("A street vendor yells, 'Stop, thief!'");
    table.addEntry("A cat meows at the party. After a quick stretch, it leaves its spot in the sun to rub on the grumpiest PC's leg.");
    table.addEntry("A large dog without a leash rushes up to the weakest PC and sniffs their crotch. Its owner comes running after, out of breath. He scolds the dog and swats it on the head with a rolled up bundle of papers.");
    table.addEntry("A small child is staring at one of the PCs. When he gets eye contact, he smiles and waves. His mother scolds him and quickly ushers him away, giving the PC a dirty look.");
    table.addEntry("A laborer is hauling a cart of crates and one falls off in front of the party. The laborer doesn't notice.");
    table.addEntry("A shady potion dealer approaches the party, selling colored liquid in vials from a case strapped around his neck, claiming various healing and other properties at a discount. The potions are actually expired, and fail to work 30% of the time.");
    table.addEntry("A pair of officers from the Watch stop the party for a random search. They don't say what they are searching for, and not finding it, they let the party on their way as long as they cooperate.");
    table.addEntry("An unleashed dog dashes from a residence, barking at the passing PCs for entering its territory. Unless they walk swiftly in the opposite direction, it will attack. Otherwise, it will follow them, barking for a block, then turn back home.");
    table.addEntry("A pack of stray dogs dart from one alley for another, noses down, on the trail of something.");
    table.addEntry("A musician sits on the curb with a hat out, containing a few coppers. He's jamming on his lute.");
    table.addEntry("A group of ruffians shout a challenge to the PCs to prove themselves in combat right there in the street. A crowd gathers around them.");
    table.addEntry("A magical duel between two rival wizards breaks out. Magic missiles and acid arrows fly across the street as the crowd runs for cover.");
    table.addEntry("A pair of noblemen face off for a duel of rapiers against one another for the sake of honor. They fight to first blood as a crowd watches, blocking the street.");
    table.addEntry("The street is blocked off by a street fair. Temporary barriers block the way in  and guards at the entrance require an entry fee, otherwise, the party will have to go around.");
    table.addEntry("One of the party notices a dead body, propped up against a wall just inside an alleyway.");
    table.addEntry(" An unsavory-looking person approaches a PC to return a pouch/item that they have dropped. If offered a reward, they decline.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Evil Declining in the Realm”");
    table.addEntry("While passing by a seedy part of town, the PCs see people nailing planks to buildings or painting them. Nearby is a sign that says: “Urban Renewal Project”.");
    table.addEntry("There is a disturbance in the streets and people are milling about loudly.  If the PCs ask what the problem is, someone happily tells them that they just got word that the local lord has announced a cut in taxes.");
    table.addEntry("The PCs see an old man sitting at the side of the street mumbling to himself. He has a tin cup with a few copper pieces in it and a sign that reads: Take One If You Need One”");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Peace Treaty and Trade Agreement With Neighboring Kingdom Signed”");
    table.addEntry("While walking through town a group of filthy urchins surround the PCs, tugging at them. They ask if the PCs could retrieve a ball which has gotten stuck on the roof of a small shop across the way.");
    table.addEntry(" An very large Orc is pushing a cart with several small dogs in it while shouting “Free puppies!”.");
    table.addEntry("A group of 3d6 bald, orange-robed cultists, chanting and dancing, come near. They hand each party member a flower and continue on.");
    table.addEntry("A black-cloaked figure approaches the party, introducing themselves as “The Dark Assassin”. They ask the PCs where the magistrate is so they can turn themselves in.");
    table.addEntry("A Dwarven vendor pushes around a cart with a large barrel and small wooden bowls in it, ringing a bell while yelling “Iced Cream! One Copper!");
    table.addEntry("A street vendor is walking twards the party selling snacks. His fare consists of 'nut sacks' and 'meat sticks'.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Local Monster Retires to Warmer Clime”");
    table.addEntry("A group of people are picking up liter from the streets. One carries a sign that says “Druids For A Clean City”.");
    table.addEntry("In a square, a very large tent is being set up. Nearby is a sign that reads “Battle of the Minstrels Tonight!”");
    table.addEntry("A shabbily-dressed man quickly approaches the party, seemingly from nowhere. They speedily wash the armor/scabbard or shield of a party member and put out their hand as if expecting payment.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Dragon Disaster Averted”");
    table.addEntry("The party see a sign which reads: “Meeting of the Secret Order of Necromancers Midnight Tonight”.");
    table.addEntry("A man hands the PCs a broadsheet whose headline reads: “Good News! Local Pirates Turn to Fishing Instead”");
    table.addEntry("3d6 meowing kittens begin following the PCs");
    table.addEntry("A group of 3d6 peasants approach one of the PCs and start yelling “Hail to the King (or Queen) and begin to bow to and faun upon the PC.");
    table.addEntry("Some interesting type of music that the PCs have never heard before is coming from inside of a cafe. If the PCs investigate they find that it sells bottled flavored water, flavored coffee, small snacks and pastries. The sign above the cafe reads: “The Jazz Gnome”.");
    table.addEntry("An Elf slips a fish into one of the party members pockets/robe.");
    table.addEntry("There is a taxidermy shop called “The Rainbow Rat” that specializes in stuffed rats dyed all colors.");
    table.addEntry("2d6 local guards come by with a cart full of weapons with a sign on it that reads: “Swords for Cash Program”.");
    table.addEntry("A bunch of kids bullying a little kid, having stolen his toy sword. A good chance to get the little kid to look up to the party, maybe bring him into harms way like 5 months later... maybe have the bully's older brothers ambush the party later... no good deed goes unpunished. Depending on how well they handle the issue, maybe the kid's parents help the detectives out on a case later. If they help that is. Just off the street, down an alley some rough looking kids and pushing a younger kid about");
    table.addEntry("A battle erupts of slingshots a fists between two groups of young children -- only they are all out battling for keeps. This is just one scrimmage in a larger war between two factions of street orphans.");
    table.addEntry("A green hag tries selling the party a clearly worthless item for an exorbitant cost. If they refuse, they get cursed (DM's choice). If they purchase it, they get some kind of blessing (I gave mine the equivalent of lucky for a day).");
    table.addEntry("a relentless merchant wont leave you alone until you buy something. He follows and follows, insisting that he has the best gear in the city.");
    table.addEntry("Access to the market area is blocked by a number of burly trade apprentices and a  barricade of wagons. They advise PCs the area is off limits - they should move along. Sounds of combat and cheering can be faintly heard coming from behind the blockade.");
    table.addEntry("During a magical performance by a gnome mage something goes wrong. A simple trick summons a beast from another dimension and it attacks the audience and PCs. After a long battle the PCs must decide what to do with the gnome. Is he the one responsible for all that pain or is there more going on than meets the eye?");
    table.addEntry("A small insect continuously buzzes the PCs' ears. The insect, if listened to closely, can be heard giving warnings, secrets or other vital information to the PCs' quest. The insect can  be an NPC transformed or simply an intelligent being in disguise.");
    table.addEntry("A building or ship explodes as the PCs pass by. Amongst the screams and fire, a badly burnt, wild-eyed man in scorched pirate's garb stumbles over to the PCs and hands them an enormous red ruby. 'It's not the last one, but don't seek the treasure!' he hisses at the PCs before collapsing at their feet.");
    table.addEntry("A child is crying in a dark alley. If PCs decide to help the child, it attacks them, blood covering its face and black eyes. Will the PCs kill a young and innocent child?");
    table.addEntry("several workmen open up the streets diggn a hole, asking people money te cross the boardwalk they made. Harrassing a shopowener etc...");
    table.addEntry("A regiment of the guard clear the street as their column marches down it in haste. In their midst is a liter born on the backs of sturdy men. The curtains are drawn so that the inside is hidden.");
    table.addEntry("A swarm of rats or bats pours out of an abandoned building and onto the street and scatters among the crowd. The street erupts into chaos as everyone runs screaming in every direction.");
    table.addEntry("An exotic monster breaks free of the cage its owner was transporting it in and wreaks havoc. Only the party can stop it.");
    table.addEntry("A pack of zombie cats shambles towards the party to attack.");
    table.addEntry("A band of goblins, disguised as beggars is spotted trying to map out the city in preparation for a future attack");
    table.addEntry("Mooks from the current adventure are causing trouble with some commoners in the street ahead.");
    table.addEntry("A con artist tries to sell the party a fake treasure map.");
    table.addEntry("Smoke rises. Building is on fire");
    table.addEntry("Wine festival at the park");
    table.addEntry("Excitement. Gladiator bout tonight.");
    table.addEntry("From up above, the contents of a chamber pot spills on you.");
    table.addEntry("A Magic-Users summon spell has gone wild and a random creature from another dimension has emerged. ");
    table.addEntry("Dock workers are rioting for better wages.");
    table.addEntry("Protesters block the streets. They don't want non-humans in their city. A counter protest block retreat and closes in. Tensions rise.");
    table.addEntry("Crowd gathers for a public execution.");
    table.addEntry("A small, skinny girl sits on the ground crying he eyes out. If approached she continues cry and begs for food. This is (in part) a scam. Her mother watches from a nearby window and rushes out if the party take too much interest in her daughter.");
    table.addEntry("Graffiti identifying the street as belonging to the Black Run Boys covers one wall.");
    table.addEntry("Overhanging buildings create an area of deep shadow that fills the mouth to a narrow alley. This is a spot ripe for ambush and murder.");
    table.addEntry("A discarded, empty scarlet belt pouch has been trodden into the muddy ground.");
    table.addEntry("A semi-feral pig, bleeding from several superficial cuts, darts passed the party. Moments later, a gaggle of children armed with sharp sticks dashes after it.");
    table.addEntry("As the PCs approach, a messenger whispers something into a guard’s ear. The guard looks at the party before shaking his head. The messenger then returns into the city.");
    table.addEntry("Several beggars—mostly ex-soldiers missing limbs—sit in the shadow of the gate and plead for coins from those passing by. Few stop to donate anything to these desperate souls.");
    table.addEntry("A trio of young pickpockets. They are members of an immense gang that will torment the party for months if a member is harmed.");
    table.addEntry("A haggard, bearded man preaches doom outside an alehouse.");
    table.addEntry("The princess of a fallen noble house now despondently sell her favors as a common streetwalker.");
    table.addEntry("Two old women kick and mock an obese old veteran with no legs.");
    table.addEntry("A dog runs past with an emerald necklace around its neck. A screaming little man chases it.");
    table.addEntry("A ruffian hangs from a rope off a balcony, slowly strangling and pleading with passersby for succor.");
    table.addEntry("A slovenly woman stands in a doorway, waving you in. Two ruffians lurk inside.");
    table.addEntry("A black cat runs out of an alley, crosses your path, and disappears into another alley.");
    table.addEntry("An overturned cart blocks the road, a foot deep in mud and rotting cabbages. An elderly farmer stands beside it and weeps while the locals jeer him.");
    table.addEntry("Four men are beating a drunken fop in an alley.");
    table.addEntry("A drunken woman runs shrieking out of a stable.");
    table.addEntry("Five men in matching floppy red hats walk arrogantly down the avenue, shoving everyone out of their path with stout wooden cudgels.");
    table.addEntry("A man in a wizardly-looking robe and pointed hat offers you a selection of charms and amulets.");
    table.addEntry("A physician works frantically in the street on a man who has been stabbed while onlookers stand around them and whisper.");
    table.addEntry("An unnatural darkness hangs over the mouth of an alley, and a cold breezes issues from out of it.");
    table.addEntry("A high-pitched scream is heard from the topmost floor of a nearby tenement.");
    table.addEntry("A group of musicians marches down the street, loudly playing revolutionary tunes while a dwarf scampers along behind them collecting tips in a hat.");
    table.addEntry("Two muscular men wrestle in a square while onlookers place bets.");
    table.addEntry("A human-looking creature with black eyes growls at you.");
    table.addEntry("A man pulls a cart filled with fresh fish. He offers you a bargain to buy the lot.");
    table.addEntry("A tremendous stench of blood wafts up from a sewer grate.");
    table.addEntry("A maddened horse plunges into a screaming crowd, hooves flailing.");
    table.addEntry("A man hawks peeks at the growling creature within a covered cage.");
    table.addEntry("A buxom woman pulls a cart with a keg of ale, offering to fill tankards for a copper piece.");
    table.addEntry("A pair of heavily armed men stand to either side of a doorway, glaring at passersby.");
    table.addEntry("A line of cultists sway down the street, chanting and waving incense burners on chains.");
    table.addEntry("A solitary soldier leans drunkenly against a wall, his helmet slipping down over his eyes.");
    table.addEntry("A gang of children torment a sickly looking goat.");
    table.addEntry("A hooded man watches you intently from a second floor window.");
    table.addEntry("An airship passes by far overhead. Children run out into the street excitedly to watch it go.");
    table.addEntry("Two toughs chase a young ruffian into a blind alley.");
    table.addEntry("Flames burst out of a pair of store front windows. Everyone starts running and screaming.");
    table.addEntry("An ageless looking man with amber eyes and pointed ears plucks the strings of a harp while a trio of gangsters stand mesmerized.");
    table.addEntry("A unit of the city guard trot down the street in haste, armor jangling with every step. They disappear around a corner up ahead while onlookers whisper to each other.");
    table.addEntry("A deep rumble shakes the ground, and black smoke rises into the air from somewhere up ahead.");
    table.addEntry("A man standing near you gasps and falls to ground, dead, a crossbow bolt jutting from his back.");
    table.addEntry("A fat man kicks a cowering stable boy, accusing him of theft.");
    table.addEntry("Cultists throw books and scrolls onto a raging bonfire in the middle of the street.");
    table.addEntry("A woman in silk garments hawks costume jewelry.");
    table.addEntry("A man tends three barrels of hot water, selling baths for two coppers.");
    table.addEntry("A clanging sound comes from a nearby sewer grate.");
    table.addEntry("A raven follows you down the street, fluttering from rooftop to rooftop, as if spying on you.");
    table.addEntry("A beautiful and fey fairy-like maiden lies dying in an alleyway.");
    table.addEntry("A chimney sweeper hangs by one hand from an eave above you, howling for assistance.");
    table.addEntry("A criminal in stocks loudly proclaims his innocence in between clods of filth.");
    table.addEntry("A bruised and battered looking prostitute collapses in front of you. A strange red jewel rolls out of her hand...");
    table.addEntry("A muttering man in a black robe inscribes a magic circle in the filth of the road with a curvy silver dagger.");
    table.addEntry("An armored bully swaggers through the crowds looking for a fight.");
    table.addEntry("Two rival gangs face off in the middle of the street.");
    table.addEntry("A teary-eyed woman pushes her son at you, pleading for you to take him on as apprentice.");
    table.addEntry("The road in front of you collapses into a tentacle-filled sinkhole!");
    table.addEntry("Hyena chained to a badger ... fight viciously");
    table.addEntry("A lion paces loose");
    table.addEntry("Huge bronze pot that passersby vomit into");
    table.addEntry("A wondrous steam engine explodes killing crowded spectators");
    table.addEntry("A group of guardsmen hang wanted posters on trees. One face looks familiar to a PC.");
    table.addEntry("You find a small leather bag. It smells of moisture, and contains a set of keys and a vellum map to the location of a small keep.");
    table.addEntry("A little girl is watching you from just off the road. The next time you glance over, you see a wolf run away.");
    table.addEntry("An ecstatic farmer presses a cigar into your hands and proclaims, “It’s a girl!”");
    table.addEntry("A scruffy dog trots up to the party, in its mouth is a soggy and slightly chewed dungeon map.");
    table.addEntry("Revisit an old random encounter or NPC and display how times have changed in the city.");
    table.addEntry("An addled old crone crosses the party's path, lost and in need of directions. She is actually the leader of the Watchful Order of Magists & Protectors, in disguise, and she is judging the character of the party.");
    table.addEntry("Gargoyles swoop down and snatch up a bystander. They take her back to a a high gabled roof-top and play with her, tossing her back and fourth with evil glee as she screams for help.");
    table.addEntry("The ground shakes. Buildings sway and commoners scramble for cover. After a long handful of seconds, the earthquake stops. Shortly after, there is a loud creak and a crash as a building collapses nearby. There may be survivors.");
    table.addEntry("The Gray Hands are involved in a battle with a giant demon from the Abyss in the middle of the street! Commoners flee in every direction, and fireball blasts topple buildings. A mage flies around the creature, battering it with magic missiles. A hulking warrior strikes at it with mighty blows. A cleric heals the wounded. You will definitely be hearing about this for days to come.");
    table.addEntry("The Gray Hands parade down the street. The crowd gathers to cheer them on. Confetti is everywhere. Asking around, the party will learn that the heroes have thwarted yet another powerful threat to the city.");

    return table.getRollTableEntry();
}

QString MonsterTable::sewerEncounter(int tier)
{
    RandomTable table;

    QString qty;
    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " Bat swarm");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " Carrion crawler");

    qty = QString::number(Dice::roll(1,6,1));
    table.addEntry("1 leader of the Cellarers' and Plumbers' (noble) Guild and "
                   + qty + " members (commoners), on a maitenance run");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " centipede swarms");

    table.addEntry("1 gray ooze");

    table.addEntry("1 Mimic");

    table.addEntry("1 Ochre Jelly");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " Shadows");

    qty = QString::number(Dice::roll(1,12));
    table.addEntry(qty + " Rat swams");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " shreikers");

    qty = QString::number(Dice::roll(1,4));
    table.addEntry(qty + " Spider swarms");

    qty = QString::number(Dice::roll(1,4,4));
    table.addEntry(qty + " Stirges");

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty + " bandits");

    table.addEntry("1 Violet fungi");

    qty = QString::number(Dice::roll(1,4,1));
    table.addEntry(qty + " wererats");

    qty = QString::number(Dice::roll(2,6));
    table.addEntry(qty + " giant rats");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " chuul");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " crocodiles");

    qty = QString::number(Dice::roll(1,6));
    table.addEntry(qty + " darkmantles");

    table.addEntry("1 Gibbering Mouther");

    qty = QString::number(Dice::roll(3,6));
    table.addEntry(qty + " bandits of the Eye with 1 Thief leader escorting "
                         "some commoner captives to the slave markets below");

    table.addEntry("1 otyugh");

    qty = QString::number(Dice::roll(1,3));
    table.addEntry(qty + " wights");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " will o wisps");

    qty = QString::number(Dice::roll(1,2));
    table.addEntry(qty + " wraiths");

    table.addEntry(NpcTables::adventuringParty(tier));
    table.addEntry(NpcTables::generateAdventurer(tier));

    return table.getRollTableEntry();
}

QString MonsterTable::coastalEncounter(int tier)
{
    RandomTable table;
    QString num;
    QString num2;

    if (tier == 1) {
        table.addEntry("1 pseudodragon" + _intellegentBlock());
        table.addEntry("A few dozen baby turtles struggling to make their way "
                       "to the sea.");
        table.addEntry("1 Sea Hag" + _intellegentBlock());
        table.addEntry("A momentary formation in the waves that looks like a "
               "human face");
        table.addEntry("1 druid: " + _npcCommonerBlock());
        table.addEntry("A lone hermit (acolyte) sitting on the beach, "
               "contemplating the meaning of the multiverse"
                       + _motivatedBlock());
        table.addEntry("1 banshee" + _intellegentBlock());
        table.addEntry("1 sahuagin baron" + _intellegentBlock());
        table.addEntry("1 water elemental");
        table.addEntry("1 cyclops" + _raceBlock());
        table.addEntry("1 deep scion swashbuckler (vgm)" + _raceBlock());
        table.addEntry("1 young bronze dragon" + _raceBlock());

        num = QString::number(Dice::roll(1, 2));
        table.addEntry(num + " plesiosauruses" + _animalBlock());
        table.addEntry(num + " quetzalcuatlus (vgm)" + _animalBlock());

        num = QString::number(Dice::roll(1, 3));
        table.addEntry(num + " poisonous snakes" + _animalBlock());
        table.addEntry(num + " manticores" + _animalBlock());
        num2= QString::number(Dice::roll(2, 6));
        table.addEntry("1 sahuagin priestess with " + num + " merrow and "
               + num2 + " sahuagin" + _intellegentBlock());

        num = QString::number(Dice::roll(1, 4));
        num2 = QString::number(Dice::roll(2, 6));
        table.addEntry(num + " dimetrodons (vgm)" + _animalBlock());
        table.addEntry(num + " ghouls feeding on corpses aboard the wreck "
             "of a merchant ship. A search uncovers "
               + LootTables::mundaneHorde(tier)
               + " and some mundane cargo.");
        num2 = QString::number(Dice::roll(1, 6) + 1);
        table.addEntry(num + " winged kobolds with " + num2 + " kobolds"
                       + _intellegentBlock());
        table.addEntry(num + " harpies");
        table.addEntry(num + " berserkers: " + _npcCommonerBlock());
        table.addEntry(num + " ogres" + _raceBlock());
        table.addEntry(num + " merrow" + _raceBlock());
        table.addEntry(num + " veterans: " + _npcCommonerBlock());
        table.addEntry(num + " sea spawns (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(1, 4) + 3);
        table.addEntry(num + " griffons" + _animalBlock(), 2);

        num = QString::number(Dice::roll(2, 4));
        table.addEntry(num + " stirges" + _animalBlock());
        table.addEntry(num + " sahuagin" + _intellegentBlock());
        table.addEntry(num + " giant toads" + _animalBlock());
        table.addEntry(num + " scouts: " + _npcCommonerBlock());

        num = QString::number(Dice::roll(2, 4) + 5);
        table.addEntry(num + " blood hawks" + _animalBlock());

        num = QString::number(Dice::roll(3, 4));
        table.addEntry(num + " kobolds" + _intellegentBlock());

        num = QString::number(Dice::roll(1, 6));
        table.addEntry(num + " giant eagles: " + _animalBlock());
        table.addEntry(num + " guards protecting a stranded noble"
                       + _npcCommonerBlock());

        num = QString::number(Dice::roll(1, 6) + 2);
        table.addEntry(num + " giant lizards: " + _animalBlock());
        table.addEntry(num + " scouts: " + _npcCommonerBlock());

        num = QString::number(Dice::roll(1, 6) + 4);
        table.addEntry(num + " giant crabs" + _animalBlock());

        num = QString::number(Dice::roll(2, 6));
        table.addEntry(num + " fishers (commoners): " + _npcCommonerBlock());
        table.addEntry(num + " tribal warriors - " + _npcCommonerBlock());
        table.addEntry("1 bandit captain with " + num + " bandits"
                       + _npcCommonerBlock());

        num = QString::number(Dice::roll(2, 6) + 3);
        table.addEntry(num + " bandits: " + _npcCommonerBlock());

        num = QString::number(Dice::roll(3, 6));
        table.addEntry(num + " sahuagin" + _intellegentBlock());

        num = QString::number(Dice::roll(1, 8) + 1);
        table.addEntry(num + " pteranodons" + _animalBlock());

        num = QString::number(Dice::roll(2, 8));
        table.addEntry(num + " crabs: " + _animalBlock());

        num = QString::number(Dice::roll(2, 10));
        table.addEntry(num + " merfolk - " + _raceBlock());

        num = QString::number(Dice::roll(2, 10)+2);
        table.addEntry(num + " sahuagin" + _intellegentBlock());
    }
    else { // tier 2
        table.addEntry("1 sea hag" + _intellegentBlock());
        table.addEntry("1 pseudodragon chasing gulls through the air");
        table.addEntry("1 commoner singing a dirge"
                       " (day only) or 1 banshee (night only)"
                       + _intellegentBlock());
        table.addEntry("A battle at sea between 2 galleons");
        table.addEntry("3 sea hags" + _intellegentBlock());
        table.addEntry("A severed humanoid hand tangled in a net");
        table.addEntry("1 water elemental" + _intellegentBlock());
        table.addEntry("1 cyclops" + _intellegentBlock());
        table.addEntry("1 young bronze dragon: " + _intellegentBlock());
        table.addEntry("1 young blue dragon: " + _intellegentBlock());
        table.addEntry("1 djinni" + _raceBlock());
        table.addEntry("1 roc" + _animalBlock());
        table.addEntry("1 marid" + _raceBlock());
        table.addEntry("1 storm giant" + _raceBlock());
        table.addEntry("1 storm giant dreamwalker (vgm)" + _raceBlock());
        num = QString::number(Dice::roll(1, 2));
        table.addEntry(num + " druids: " + _npcCommonerBlock());
        table.addEntry(num + " kraken priests (vgm): " + _npcAdventurerBlock());
        num = QString::number(Dice::roll(1, 3));
        num2 = QString::number(Dice::roll(2, 8));
        table.addEntry("1 sahuagin baron with " + num
                       + " sahuagin priestesses and " + num2 + " sahuagin"
                       + _intellegentBlock());
        table.addEntry(num + " cyclopses" + _raceBlock());
        num = QString::number(Dice::roll(1, 4));
        table.addEntry(num + " plesiosauruses" + _animalBlock());
        table.addEntry(num + " manticores" + _animalBlock());
        table.addEntry(num + " banshees (night only)" + _intellegentBlock());
        num = QString::number(Dice::roll(1, 4) + 1);
        table.addEntry(num + " giant toads" + _animalBlock());
        num = QString::number(Dice::roll(1, 4) + 3);
        table.addEntry(num + " merrow" + _raceBlock() );
        num = QString::number(Dice::roll(2, 4));
        table.addEntry(num + " scouts: " + _npcCommonerBlock());
        table.addEntry(num + " veterans: " + _npcCommonerBlock());
        table.addEntry(num + " ogres" + _raceBlock());
        num = QString::number(Dice::roll(2, 4) + 1);
        table.addEntry(num + " giant toads" + _animalBlock());
        num = QString::number(Dice::roll(1, 6) + 2);
        table.addEntry(num + " sahuagin" + _intellegentBlock());
        num = QString::number(Dice::roll(2, 6));
        table.addEntry(num + " giant eagles: " + _animalBlock());
        num = QString::number(Dice::roll(3, 6));
        table.addEntry(num + " pteranodons" + _intellegentBlock());
        table.addEntry(num + " sahuagin" + _intellegentBlock());
        num = QString::number(Dice::roll(1, 8) + 1);
        table.addEntry(num + " harpies");
        num = QString::number(Dice::roll(2, 8));
        table.addEntry(num + " giant wolf spiders" + _animalBlock());
        num = QString::number(Dice::roll(1, 10));
        table.addEntry(num + " griffons" + _animalBlock());
        num = QString::number(Dice::roll(2, 12));
        table.addEntry("A pirate crew consisting of 1 bandit captain, 1 "
                       "druid, 2 berserkers and " + num
                       + " bandits, all searching for burried treasure"
                       + _motivatedBlock());
    }

    return table.getRollTableEntry() + _loot(tier);
}

QString MonsterTable::forestEncounter(int tier)
{
    RandomTable table;
    QString num;
    QString num2;

   if (tier == 1) {
        table.addEntry("1 giant owl: " + _animalBlock());
        table.addEntry("1 owl: " + _animalBlock());
        table.addEntry("1 pseudodragon: " + _intellegentBlock());
        table.addEntry("1 panther: " + _animalBlock());
        table.addEntry("1 giant poisonous snake" + _animalBlock());
        table.addEntry("1 ape" + _animalBlock());
        table.addEntry("1 tiger" + _animalBlock());
        table.addEntry("1 scout: " + _npcCommonerBlock());
        table.addEntry("1 satyr" + _intellegentBlock());
        table.addEntry("1 faerie dragon (yellow or younger): " + _raceBlock());
        table.addEntry("A young woodcutter (scout) racing through the forest on a "
               "hook." + _motivatedBlock());
        table.addEntry("1 swarm of insects");
        table.addEntry("1 brown bear: " + _animalBlock());
        table.addEntry("1 awakened tree: " + _intellegentBlock());
        table.addEntry("1 phase spider" + _animalBlock());
        table.addEntry("1 ettercap" + _intellegentBlock());
        table.addEntry("1 ankheg");
        table.addEntry("1 giant constrictor snake" + _animalBlock());
        table.addEntry("1 pegasus: " + _animalBlock());
        table.addEntry("1 ogre" + _raceBlock());
        table.addEntry("1 faerie dragon (green or older): " + _raceBlock());
        table.addEntry("1 werewolf" + _npcCommonerBlock());
        table.addEntry("1 druid harvesting mistletoe: " + _npcCommonerBlock());
        table.addEntry("1 will-o-wisp");
        table.addEntry("1 giant boar" + _animalBlock());
        table.addEntry("1 owlbear" + _animalBlock());
        table.addEntry("1 giant elk: " + _animalBlock());
        table.addEntry("1 gnoll Fang of Yeenoghu" + _intellegentBlock());
        table.addEntry("1 coutail (day) or 1 banshee (night)"
                       + _intellegentBlock());
        table.addEntry("1 gorgon" + _animalBlock());
        table.addEntry("1 unicorn: " + _animalBlock());
        table.addEntry("1 shambling mound" + _animalBlock());
        table.addEntry("1 yuan-ti abomination" + _raceBlock());
        table.addEntry("1 archer (vgm): " + _npcCommonerBlock());
        table.addEntry("1 flail snail (vgm)" + _animalBlock());
        table.addEntry("1 orc Red Fang of Shargaas (vgm)" + _intellegentBlock());
        table.addEntry("1 redcap (vgm)"  + _intellegentBlock());
        table.addEntry("1 Barghest (vgm)" + _intellegentBlock());
        table.addEntry("1 girallon (vgm)" + _animalBlock());
        table.addEntry("1 hobgoblin devestartor (vgm)" + _raceBlock());
        table.addEntry("1 orc Blade of Ilneval (vgm)" + _intellegentBlock());
        table.addEntry("1 stegasaurus (vgm): " + _animalBlock());
        table.addEntry("1 warlock of the archfey: " + _npcCommonerBlock());
        table.addEntry("1 yeth hound (vgm)" + _animalBlock());
        table.addEntry("1  yuan-ti mind-whisperer (vgm)" + _raceBlock());
        table.addEntry("1  yuan-ti nightmare-speaker (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(1,3));
        table.addEntry(num + " constrictor snakes: " + _animalBlock());
        table.addEntry("A lost, wandering child. If the characters take the "
               "child home, the parents reward them with " + num
               + " healing potions" + _motivatedBlock());
        table.addEntry(num + " black bears: " + _animalBlock());
        num2= QString::number(Dice::roll(1,12));
        table.addEntry(num + " vine blights with " + num2 + " awakened shrubs");
        table.addEntry(num + " dryads" + _intellegentBlock());
        num2 = QString::number(Dice::roll(1,10) + 2);
        table.addEntry("1 Lizardfolk shaman with " + num
               + " swarms of poisonous snakes and " + num2 + " lizardfolk"
                       + _intellegentBlock());
        table.addEntry(num + " green hags" + _intellegentBlock());
        table.addEntry(num + " weretigers: " + _npcCommonerBlock());
        table.addEntry(num + " guard drakes (vgm)" + _animalBlock());
        table.addEntry(num + " hobgoblin iron shadows (vgm)" + _raceBlock());
        table.addEntry(num + " meenloks (vgm)" + _animalBlock());
        table.addEntry(num + " orc hand of Yurtrus (vgm)" + _intellegentBlock());
        table.addEntry(num + " shadow mastiffs(vgm)" + _animalBlock());
        table.addEntry(num + " yuan-ti broodguards (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(1,4));
        table.addEntry(num + " cats: " + _animalBlock());
        table.addEntry("1 badger: " + _animalBlock());
        table.addEntry(num + " poisonous snakes: " + _animalBlock());
        table.addEntry(num + " swarms of ravens: " + _animalBlock());
        table.addEntry(num + " lizardfolk: " + _intellegentBlock());
        table.addEntry(num + " bugbears" + _raceBlock());
        table.addEntry(num + " half-ogres" + _raceBlock());
        table.addEntry(num + " dire wolves" + _animalBlock());
        table.addEntry("1 wereboar: " + _npcCommonerBlock());
        table.addEntry(num + " centaurs: " + _raceBlock());
        table.addEntry(num + " giant elk" + _animalBlock());
        table.addEntry(num + " gricks" + _animalBlock());
        table.addEntry(num + " wererats" + _npcCommonerBlock());
        table.addEntry("1 gnoll pack lord with " + num + " giant hyenas"
                       + _intellegentBlock());
        table.addEntry(num + " veterans: " + _npcCommonerBlock());
        table.addEntry(num + " displacer beasts" + _animalBlock());
        table.addEntry(num + " deinonychus (vgm)" + _animalBlock());
        table.addEntry(num + " gnoll flesh gnawers (vgm)" + _intellegentBlock());
        table.addEntry(num + " grung wildlings (vgm)" + _intellegentBlock());
        table.addEntry(num + " quicklings (vgm): " + _intellegentBlock());
        table.addEntry(num + " vegepygmy thornies (vgm): " + _intellegentBlock());
        table.addEntry("1 darkling elder (vgm) with " + num
                       + " darklings" + _raceBlock());

        num = QString::number(Dice::roll(1,4) + 1);
        table.addEntry(num + " giant lizards: " + _animalBlock());
        num2 = QString::number(Dice::roll(1,6) + 3);
        table.addEntry(num + " needle blights with " + num2 + " twig blights"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(1,4) + 2);
        table.addEntry(num + " giant badgers" + _animalBlock());

        num = QString::number(Dice::roll(1,4) + 3);
        table.addEntry(num + " goblins" + _intellegentBlock());

        num = QString::number(Dice::roll(1,4) + 4);
        table.addEntry(num + " wolves: " + _animalBlock());

        num = QString::number(Dice::roll(2,4));
        table.addEntry(num + " woodcutters (commoners): " + _npcCommonerBlock());
        num2 = QString::number(Dice::roll(1,8));
        table.addEntry(num + " guards with " + num2 + " mastiffs: "
                       + _npcCommonerBlock());
        table.addEntry(num + " kenku" + _raceBlock());
        table.addEntry(num + " blink dogs: " + _animalBlock());
        table.addEntry(num + " giant wolf spiders");
        table.addEntry(num + " blood hawks" + _animalBlock());
        table.addEntry(num + " hobgoblins" + _raceBlock());
        table.addEntry(num + " berzerkers: " + _npcCommonerBlock());
        table.addEntry(num + " boggles (vgm): " + _intellegentBlock());
        table.addEntry(num + "darklings (vgm)" + _raceBlock());
        table.addEntry(num + " orc neutered ones of Yurturus (vgm)"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(2,4) + 2);
        table.addEntry("1 Orc Eye of Gruumsh with " + num + " orcs"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(4,4));
        table.addEntry(num + " kobolds" + _intellegentBlock());
        table.addEntry("1 kobold inventor (vgm) with " + num + " kobolds"
                       + _intellegentBlock());
        table.addEntry("1 kobold dragon shield (vgm) with " + num + " kobolds"
                       + _intellegentBlock());
        table.addEntry("1 kobold scale sorceror (vgm) with " + num + " kobolds"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(1,6));
        table.addEntry(num + " hyenas: " + _animalBlock());
        table.addEntry(num + " harpies");
        table.addEntry(num + " giant toads" + _animalBlock());
        table.addEntry(num + " web cocoons hanging from the branches, "
                 "holding withered carcasses");

        num = QString::number(Dice::roll(1,6) + 1);
        table.addEntry("1 yuan-ti malison with " + num + " yuan-ti purebloods"
                       + _raceBlock());

        num = QString::number(Dice::roll(1,6) + 2);
        table.addEntry(num + " boars" + _animalBlock());
        table.addEntry(num + " giant bats");
        table.addEntry(num + " elk: " + _animalBlock(), 3);
        table.addEntry(num + " pixies: " + _intellegentBlock());
        table.addEntry(num + " giant spiders");

        num = QString::number(Dice::roll(2,6));
        num2 = QString::number(Dice::roll(1,6));
        table.addEntry(num + " tribal warriors with " + num2 + " mastiffs: "
               + _npcCommonerBlock());
        table.addEntry(num + " flying snakes");
        table.addEntry(num + " gnolls" + _intellegentBlock());
        table.addEntry("1 gnoll hunter (vgm) with " + num + " gnolls"
                       + _intellegentBlock());
        num2 = QString::number(Dice::roll(1,4));
        table.addEntry("1 hobgoblin captain with " + num + " hobgoblins and "
               + num2 + " giant boars" + _raceBlock());

        num = QString::number(Dice::roll(2,6) + 1);
        table.addEntry("1 goblin boss with " + num + " goblins"
                       + _intellegentBlock());
        table.addEntry("1 nilbog with " + num + " goblins"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(2,6) + 3);
        table.addEntry(num + " giant weasles" + _animalBlock());
        table.addEntry("1 bandit captain with " + num + " bandits: "
                       + _npcCommonerBlock());

        num = QString::number(Dice::roll(3,6));
        table.addEntry(num + " stirges");
        table.addEntry(num + " bandits: " + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,8) + 1);
        table.addEntry(num + " winged kobolds" + _intellegentBlock());
        table.addEntry(num + " giant frogs" + _animalBlock());
        table.addEntry(num + " sprites: " + _raceBlock());
        table.addEntry(num + " orcs" + _intellegentBlock());

        num = QString::number(Dice::roll(2,8));
        table.addEntry(num + " baboons: " + _animalBlock());
        table.addEntry(num + " gnoll witherlings (vgm)");
        table.addEntry(num + " vegepygmies (vgm): " + _intellegentBlock());
        table.addEntry(num + " velociraptors (vgm)" + _animalBlock());

        num = QString::number(Dice::roll(1,10));
        table.addEntry(num + " giant wasps");

        num = QString::number(Dice::roll(1,10) + 5);
        table.addEntry(num + " giant rats" + _animalBlock());
    }
    else { // tier 2
        table.addEntry("1 faerie dragon (any age)" + _raceBlock());
        table.addEntry("1 brown bear" + _animalBlock());
        table.addEntry("1 couatl" + _animalBlock());
        table.addEntry("1 werebear: " + _npcCommonerBlock());
        table.addEntry("1 yuan-ti abomination: " + _raceBlock());
        table.addEntry("1 oni" + _raceBlock());
        table.addEntry("1 young green dragon" + _raceBlock());
        table.addEntry("1 treant" + _raceBlock());
        table.addEntry("1 guardian naga" + _raceBlock());
        table.addEntry("1 adult gold dragon: " + _npcCommonerBlock());
        table.addEntry("1 Barghest (vgm)" + _intellegentBlock());
        table.addEntry("1 Girallon (vgm)" + _animalBlock());
        table.addEntry("1 hobgoblin devestator (vgm)" + _raceBlock());
        table.addEntry("1 orc blade of illneval (vgm)" + _intellegentBlock());
        table.addEntry("1 stegosarus (vgm): " + _animalBlock());
        table.addEntry("1 warlock of the archfey (vgm)" + _npcCommonerBlock());
        table.addEntry("1 yeth hound (vgm)" + _animalBlock());
        table.addEntry("1 yuan-ti mind whisperer (vgm)" + _raceBlock());
        table.addEntry("1 yuan-ti nightmare speaker (vgm)" + _raceBlock());
        table.addEntry("1 brontosaurus (vgm): " + _animalBlock());
        table.addEntry("1 wood woad (vgm): " + _intellegentBlock());
        table.addEntry("1 yuan-ti pit master (vgm)" + _raceBlock());
        table.addEntry("1 korred (vgm): " + _intellegentBlock());
        table.addEntry("1 Shoosuva (vgm)" + _intellegentBlock());
        table.addEntry("1 Flind (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,3));
        table.addEntry(num + " will-o-wisps");
        num2 = QString::number(Dice::roll(1,8) + 2);
        table.addEntry("1 orc Eye of Gruumsh with " + num + " orogs and "
                       + num2 + " orcs" + _intellegentBlock());
        table.addEntry(num + " constrictor snakes" + _animalBlock());
        table.addEntry(num + " awakened trees (day) or 1 banshee (night)"
                       + _intellegentBlock());
        table.addEntry(num + " green hags" + _intellegentBlock());
        table.addEntry(num + " archers (vgm): " + _npcCommonerBlock());
        table.addEntry(num + " flail snails (vgm)"  + _animalBlock());
        table.addEntry(num + " orc red fang of Shargaas (vgm)"
                       + _intellegentBlock());
        table.addEntry(num + " redcaps (vgm): " + _raceBlock());

        num = QString::number(Dice::roll(1,4));
        table.addEntry(num + " swarms of poisonous snakes");
        table.addEntry(num + " tigers: " + _animalBlock());
        table.addEntry(num + " giant boars: " + _animalBlock());
        table.addEntry(num + " ankhegs");
        table.addEntry(num + " ogres" + _raceBlock());
        table.addEntry(num + " griks" + _animalBlock());
        table.addEntry(num + " giant elk: " + _animalBlock());
        table.addEntry(num + " owlbears" + _animalBlock());
        table.addEntry(num + " werewolves: " + _npcCommonerBlock());
        table.addEntry(num + " veterans: " + _npcCommonerBlock());
        table.addEntry(num + " wereboars: " + _npcCommonerBlock());
        table.addEntry(num + " shambling mounds" + _animalBlock());
        table.addEntry(num + " trolls" + _raceBlock(), 3);
        table.addEntry(num + " unicorns: " + _animalBlock(), 2);
        table.addEntry(num + " gorgons" + _animalBlock());
        table.addEntry(num + " reavenants" + _npcCommonerBlock());
        table.addEntry(num + " giant apes" + _animalBlock());

        num = QString::number(Dice::roll(1,4) + 1);
        table.addEntry("1 gnoll pack lord with " + num + " giant hyenas"
                       + _intellegentBlock());
        table.addEntry("1 darkling elder (vgm) with " + num
                       + " shadow mastiffs (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(2,4));
        table.addEntry(num + " vine blights");
        table.addEntry(num + " apes" + _animalBlock());
        table.addEntry(num + " satyrs: " + _intellegentBlock());
        table.addEntry("1 lizardfolk shaman with " + num + " lizardfolk"
                       + _intellegentBlock());
        table.addEntry(num + " dire wolves" + _animalBlock());
        table.addEntry(num + " bugbears" + _raceBlock());
        table.addEntry(num + " centaurs: " + _raceBlock());
        table.addEntry(num + " displacer beasts" + _animalBlock());
        table.addEntry(num + " yuan-ti malisons" + _raceBlock());
        table.addEntry("1 vegepygmy chief (vgm) with " + num
                       + " vegepygmy thornies (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,6));
        table.addEntry(num + " wererats: " + _npcCommonerBlock());
        table.addEntry(num + " pegasi: " + _animalBlock());
        table.addEntry(num + " grung elete warriors (vgm)" + _intellegentBlock());
        table.addEntry(num + " guard drakes (vgm)" + _animalBlock());
        table.addEntry(num + " hobgoblin iron shadows (vgm)" + _raceBlock());
        table.addEntry(num + " meenlocks (vgm)" + _animalBlock());
        table.addEntry(num + " orc hands of Yurtrus (vgm)" + _intellegentBlock());
        table.addEntry(num + " shadow mastiffs (vgm)" + _animalBlock());
        table.addEntry(num + " yuan-ti brood guards (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(1,6) + 1);
        table.addEntry("1 grik alpha with " + num + " griks" + _animalBlock());

        num = QString::number(Dice::roll(1,6) + 2);
        table.addEntry(num + " black bears: " + _animalBlock());
        table.addEntry(num + " half-ogres" + _raceBlock());
        table.addEntry(num + " dryads: " + _intellegentBlock());
        table.addEntry(num + " weretigers: " + _npcCommonerBlock());
        table.addEntry(num + " gnoll fangs of Yeenoghu" + _intellegentBlock());
        table.addEntry("1 kobold scale sorcerer (vgm) with "
                       + num + " kobold dragonshields (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,6) + 5);
        table.addEntry("1 bandit captain with 1 druid and " + num + " bandits: "
                       + _npcCommonerBlock());
        table.addEntry(num + " deinonychus (vgm)" + _animalBlock());
        table.addEntry(num + " gnoll flesh gnawer (vgm)" + _intellegentBlock());
        table.addEntry(num + " grung wildlings (vgm)" + _intellegentBlock());
        table.addEntry(num + " kobold dragonshields (vgm)" + _intellegentBlock());
        table.addEntry(num + " quicklings (vgm): " + _raceBlock());
        table.addEntry(num + " vegepygmy thornies (vgm): " + _intellegentBlock());

        num = QString::number(Dice::roll(2,6));
        table.addEntry(num + " hobgoblins" + _raceBlock());
        table.addEntry(num + " orcs" + _intellegentBlock());
        table.addEntry("1 Darkling elder (vgm) with "
                       + num + " darklings (vgm)" + _raceBlock());
        table.addEntry(num + " Darklings (vgm) with "
                       "1 shadow mastiff (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(3,6));
        table.addEntry("1 goblin boss with " + num + " goblins"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(1,8) + 1);
        table.addEntry(num + " giant spiders");
        table.addEntry(num + " yuan-ti purebloods" + _raceBlock());
        table.addEntry(num + " harpies");
        table.addEntry(num + " berzerkers: " + _npcCommonerBlock());
        table.addEntry(num + " ettercaps" + _intellegentBlock());
        table.addEntry(num + " phase spiders");

        num = QString::number(Dice::roll(1,10));
        table.addEntry(num + " giant toads" + _animalBlock());

        num = QString::number(Dice::roll(2,10));
        table.addEntry(num + " elk: " + _animalBlock());

        num = QString::number(Dice::roll(3,10));
        table.addEntry(num + " blink dogs: " + _animalBlock());
        num2 = QString::number(Dice::roll(4,12));
        table.addEntry("1 hobgoblin captain with " + num + " hobgoblins and "
                       + num2 + " goblins" + _intellegentBlock());

    }

    return table.getRollTableEntry() + _loot(tier);
}

QString MonsterTable::grasslandsEncounter(int tier)
{
    RandomTable table;

    QString num;
    QString num2;

    if (tier == 1) {
        table.addEntry("1 ankylosaurus" + _animalBlock());
        table.addEntry("1 weretiger" + _npcCommonerBlock());
        table.addEntry("1 phase spider");
        table.addEntry("1 orog" + _intellegentBlock());
        table.addEntry("1 pegasus: " + _animalBlock());
        table.addEntry("1 ankheg");
        table.addEntry("1 chimera" + _animalBlock());
        table.addEntry("1 gorgon" + _animalBlock());
        table.addEntry("1 giant boar" + _animalBlock());
        table.addEntry("1 ogre" + _raceBlock());
        table.addEntry("1 panther (leopard): " + _animalBlock());
        table.addEntry("1 lion: " + _animalBlock());
        table.addEntry("1 giant eagle: " + _animalBlock());
        table.addEntry("1 giant elk: " + _animalBlock());
        table.addEntry("1 triceratops: " + _animalBlock());
        table.addEntry("1 cyclops" + _raceBlock());
        table.addEntry("1 bulette");
        table.addEntry("1 tyranosaurus rex" + _animalBlock());
        table.addEntry("1 Barghest (vgm)" + _intellegentBlock());
        table.addEntry("1 hobgoblin devestartor (vgm)" + _raceBlock());
        table.addEntry("1 orc Blade of Ilneval (vgm)" + _intellegentBlock());
        table.addEntry("1 stegosaurus (vgm): " + _animalBlock());
        table.addEntry("1 yeth hound (vgm)" + _animalBlock());

        num = QString::number(Dice::roll(1,2));
        table.addEntry(num + " couatls" + _animalBlock());
        table.addEntry(num + " giant poisonous snakes");
        table.addEntry(num + " tigers: " + _animalBlock());
        table.addEntry(num + " bugbears" + _raceBlock());
        table.addEntry(num + " aurochs (vgm)" + _animalBlock());
        table.addEntry(num + " hobgoblin iron shadows (vgm)" + _raceBlock());
        table.addEntry(num + " orc hand of Yurtrus (vgm)" + _intellegentBlock());
        table.addEntry(num + " leucrottas (vgm)" + _animalBlock());

        num = QString::number(Dice::roll(1,3));
        table.addEntry(num + " allosauruses" + _animalBlock());
        //table.addEntry(num + " elephants: " + _animalBlock());
        //table.addEntry(num + " rhinoceroses: " + _animalBlock());
        table.addEntry(num + " cockatrices" + _animalBlock());
        table.addEntry(num + " boars: " + _animalBlock());
        table.addEntry("1 gnoll pack lord with " + num + " giant hyenas"
                       + _intellegentBlock());
        table.addEntry(num + " giant vultures" + _animalBlock());
        table.addEntry(num + " hippogriphs" + _animalBlock());
        table.addEntry(num + " thri-kreen" + _intellegentBlock());
        table.addEntry(num + " druids patrolling the wilds: " + _npcCommonerBlock());
        table.addEntry(num + " centaurs: " + _raceBlock());
        table.addEntry(num + " griffons: " + _animalBlock());
        table.addEntry(num + " gnoll fangs of Yeenoghu" + _intellegentBlock());

        num = QString::number(Dice::roll(1,4));
        table.addEntry("1 gnoll pack lord with " + num + " giant hyenas"
                       + _intellegentBlock());
        table.addEntry(num + " jackleweres" + _npcCommonerBlock());
        table.addEntry(num + " scouts: " + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,4) + 1);
        table.addEntry("1 hobgoblin captain with " + num + " hobgoblins"
                       + _raceBlock());
        table.addEntry(num + " manticores" + _animalBlock());
        table.addEntry(num + " deinonychuses (vgm)" + _animalBlock());
        table.addEntry(num + " gnoll flesh gnawers (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,4) + 3);
        table.addEntry(num + " swarms of insects");

        num = QString::number(Dice::roll(2,4));
        table.addEntry(num + " hobgoblins" + _raceBlock());
        table.addEntry(num + " orcs" + _intellegentBlock());
        table.addEntry(num + " gnolls" + _intellegentBlock());
        table.addEntry(num + " goblins" + _intellegentBlock());

        num = QString::number(Dice::roll(2,4) + 1);
        table.addEntry("Orc eye of Gruumsh with " + num + " orcs"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(2,4) + 2);
        table.addEntry(num + " axe beaks: " + _animalBlock());
        table.addEntry(num + " gnoll hunters (vgm)" + _intellegentBlock());
        table.addEntry(num + " orc Nurtured One of Yurtrus (vgm)"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(1,6));
        table.addEntry(num + " scarecrows");
        table.addEntry("1 wereboar" + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,6) + 2);
        table.addEntry(num + " giant wasps");
        table.addEntry(num + " elk: " + _animalBlock());
        table.addEntry(num + " riding horses: " + _animalBlock());
        num2 = QString::number(Dice::roll(1,4) + 3);
        table.addEntry("1 goblin boss with " + num + " goblins and " + num2
               + "wolves" + _intellegentBlock());

        num = QString::number(Dice::roll(1,6) + 3);
        table.addEntry(num + " goblins riding wolves" + _intellegentBlock());

        num = QString::number(Dice::roll(2,6));
        table.addEntry(num + " giant wolf spiders");

        num = QString::number(Dice::roll(3,6));
        table.addEntry(num + " wolves: " + _animalBlock(), 3);
        table.addEntry(num + " Cow (rothe) (vgm): " + _animalBlock(), 3);
        table.addEntry(num + " gnoll witherlings (vgm)" + _intellegentBlock());
        table.addEntry(num + " hadrosauruses (vgm)" + _animalBlock());
        table.addEntry(num + " velociraptors (vgm)" + _animalBlock());

        num = QString::number(Dice::roll(1,8));
        table.addEntry(num + " giant goats: " + _animalBlock());
        table.addEntry(num + " worgs" + _animalBlock());

        num = QString::number(Dice::roll(1,8) + 4);
        table.addEntry(num + " pteranadons" + _animalBlock());
    }
    else { // tier == 2
        table.addEntry("1 chimera" + _animalBlock());
        table.addEntry("1 allosaurus" + _animalBlock());
        table.addEntry("1 tiger: " + _animalBlock());
        table.addEntry("1 ankylosaurus" + _animalBlock());
        table.addEntry("1 bulette" + _animalBlock());
        table.addEntry("1 young gold dragon: " + _npcCommonerBlock());
        table.addEntry("1 barghest (vgm)" + _intellegentBlock());
        table.addEntry("1 flind (vgm)" + _intellegentBlock());
        table.addEntry("1 Shoosuva (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,2));
        table.addEntry(num + " giant eagles: " + _animalBlock());
        table.addEntry(num + " giant vultures" + _animalBlock());
        table.addEntry(num + " pegasi: " + _animalBlock());
        table.addEntry(num + " couatls" + _animalBlock());
        table.addEntry(num + " hobgoblin devestators (vgm)" + _raceBlock());
        table.addEntry(num + " orc Blade of Ilnevals (vgm)" + _intellegentBlock());
        table.addEntry(num + " stegasauruses (vgm): " + _animalBlock());
        table.addEntry(num + " yeth hounds (vgm)" + _animalBlock());
        table.addEntry(num + " brontosauruses (vgm)" + _animalBlock());
        table.addEntry(num + " mouths of Grolantor (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,3));
        table.addEntry(num + " gorgons" + _animalBlock());
        table.addEntry(num + " gnoll fangs of Yeenoghu" + _intellegentBlock());
        table.addEntry(num + " manticores" + _animalBlock());
        table.addEntry(num + " phase spiders");
        table.addEntry(num + " weretigers: " + _npcCommonerBlock());
        table.addEntry(num + " tyranasaurus rex" + _animalBlock());
        table.addEntry(num + " leucrotta (vgm)" + _animalBlock());

        num = QString::number(Dice::roll(1,4));
        table.addEntry(num + " cyclopses" + _raceBlock());
        num2 = QString::number(Dice::roll(1,4));
        table.addEntry(num + " ogres and " + num2 + " orogs" + _raceBlock());
        table.addEntry(num + " triceratops: " + _animalBlock());

        num = QString::number(Dice::roll(1,4) + 1);
        table.addEntry(num + " veterans on riding horses: " + _npcCommonerBlock());
        table.addEntry("1 gnoll pack lord with " + num + " giant hyenas"
                       + _intellegentBlock());
        //table.addEntry(num + " rhinoceroses" + _animalBlock());
        table.addEntry(num + " Aurochs (vgm): " + _animalBlock());
        table.addEntry(num + " hobgoblin iron shadows (vgm)" + _raceBlock());
        table.addEntry(num + " orc hand of Yurtrus (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(2,4));
        table.addEntry(num + " ankhegs");
        table.addEntry(num + " scarecrows");
        table.addEntry("1 goblin boss with " + num + " goblins" + _intellegentBlock());
        table.addEntry(num + " hippogriffs" + _animalBlock());
        table.addEntry(num + " giant elk: " + _animalBlock());

        num = QString::number(Dice::roll(1,6));
        //table.addEntry(num + " elephants: " + _animalBlock());

        num = QString::number(Dice::roll(1,6) + 2);
        table.addEntry(num + " griffons: " + _animalBlock(), 5);
        table.addEntry(num + " giant boars" + _animalBlock());
        table.addEntry(num + " wereboars: " + _npcCommonerBlock());

        num = QString::number(Dice::roll(2,6));
        table.addEntry("1 hobgoblin captain with " + num + " hobgoblins" + _raceBlock());
        table.addEntry(num + " deinonychuses (vgm)" + _animalBlock());
        table.addEntry(num + " gnoll flesh gnawers (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,8) + 1);
        table.addEntry(num + " centaurs" + _raceBlock());
        table.addEntry(num + " bugbears" + _raceBlock());
        table.addEntry("1 eye of Gruumsh with " + num + " orcs" + _intellegentBlock());

        num = QString::number(Dice::roll(1,10));
        table.addEntry(num + " thri-kreen" + _intellegentBlock());

        num = QString::number(Dice::roll(1,12));
        table.addEntry(num + " Lions" + _animalBlock());

        num = QString::number(Dice::roll(2,20) + 20);
        table.addEntry("A tribe of " + num
                       + " nomads (tribal warriors) on "
                         "riding horses following a herd of antelope (deer). "
                         "The nomads are willing to trade food, leather, and "
                         "information for weapons." + _motivatedBlock());

    }

    return table.getRollTableEntry() + _loot(tier);
}

QString MonsterTable::hillEncounter(int tier)
{
    RandomTable table;

    QString num;
    QString num2;

    if (tier == 1) {
        table.addEntry("1 orc Eye of Gruumsh with " + num + " orcs" + _intellegentBlock());
        table.addEntry("1 eagle: " + _animalBlock());
        table.addEntry("1 raven: " + _animalBlock());
        table.addEntry("1 poisonous snake: " + _animalBlock());
        table.addEntry("1 pseudodragon: " + _raceBlock());
        table.addEntry("1 lion: " + _animalBlock());
        table.addEntry("1 panther (cougar): " + _animalBlock());
        table.addEntry("1 hippogriff" + _animalBlock());
        table.addEntry("1 worg" + _animalBlock());
        table.addEntry("1 eagle: " + _animalBlock());
        table.addEntry("An old dwarf sitting on a stump, whittling a piece of "
               "wood: " + _motivatedBlock());
        table.addEntry("1 swarm of insects");
        table.addEntry("1 brown bear: " + _animalBlock());
        table.addEntry("1 scout: " + _npcCommonerBlock());
        table.addEntry("1 ogre" + _raceBlock());
        table.addEntry("1 giant elk: " + _animalBlock());
        table.addEntry("1 werewolf" + _npcCommonerBlock());
        table.addEntry("1 druid: " + _npcAdventurerBlock());
        table.addEntry("1 veteran: " + _npcAdventurerBlock());
        table.addEntry("The corpse of an adventurer that carries an intact "
               "explorers pack and lies atop a longsword");
        table.addEntry("1 green hag" + _intellegentBlock());
        table.addEntry("1 manticore" + _animalBlock());
        table.addEntry("1 phase spider");
        table.addEntry("A pile of droppings from a very large bird");
        table.addEntry("1 gnoll fang of Yeenoghu" + _intellegentBlock());
        table.addEntry("1 ettin" + _raceBlock());
        table.addEntry("1 wereboar" + _npcCommonerBlock());
        table.addEntry("1 cyclops" + _raceBlock());
        table.addEntry("1 stone giant: " + _raceBlock());
        table.addEntry("1 Barghest (vgm)" + _intellegentBlock());
        table.addEntry("1 Hobgoblin devestator (vgm)" + _raceBlock());
        table.addEntry("1 neogi master (vgm)" + _raceBlock());
        table.addEntry("1 orc blade of ilneval (vgm)" + _intellegentBlock());
        table.addEntry("1 yeth hound (vgm)" + _animalBlock());
        table.addEntry("1 orc tanarukk (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,3));
        table.addEntry(num + " griffons" + _animalBlock());
        table.addEntry(num + " perytons" + _animalBlock());
        table.addEntry(num + " trolls" + _raceBlock());
        table.addEntry(num + " giant owls" + _animalBlock());
        table.addEntry(num + " swarms of bats");
        table.addEntry(num + " swarms of ravens");
        table.addEntry(num + " boars: " + _animalBlock());
        table.addEntry(num + " dire wolves" + _animalBlock());
        table.addEntry(num + " giant boars" + _animalBlock());
        table.addEntry(num + " ogres" + _raceBlock());
        table.addEntry("1 gnoll pack lord with " + num + " giant hyenas" + _intellegentBlock());
        num2 = QString::number(Dice::roll(1,2));
        table.addEntry(num + " guards with " + num2 + " mastiffs and 1 mule: "
               + _npcCommonerBlock());
        table.addEntry(num + " aurochs (vgm): " + _animalBlock());
        table.addEntry(num + " hobgoblin iron shadows (vgm)" + _raceBlock());
        table.addEntry(num + " orc hand of Yutrus (vgm)" + _intellegentBlock());
        table.addEntry(num + " quetzalxoatlus (vgm)" + _animalBlock());
        table.addEntry(num + " shadow mastiffs (vgm)" + _animalBlock());
        table.addEntry(num + " neogi (vgm)" + _raceBlock());
        table.addEntry(num + " orc red fang of Shargaas (vgm)" + _intellegentBlock());
        table.addEntry(num + " redcaps (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(1,3) + 1);
        table.addEntry(num + " harpies");

        num = QString::number(Dice::roll(1,4));
        table.addEntry(num + " vultures: " + _animalBlock());
        table.addEntry(num + " pegasi: " + _animalBlock());
        table.addEntry(num + " elk: " + _animalBlock());
        table.addEntry(num + " half-ogres" + _raceBlock());
        table.addEntry(num + " berzerkers: " + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,4) + 3);
        table.addEntry(num + " giant weasles: " + _animalBlock());

        num = QString::number(Dice::roll(2,4));
        table.addEntry(num + " baboons: " + _animalBlock());
        table.addEntry(num + " stirges" + _animalBlock());
        table.addEntry(num + " goblins" + _intellegentBlock());
        table.addEntry(num + " wolves: " + _animalBlock());
        table.addEntry(num + " gnolls" + _intellegentBlock());
        table.addEntry(num + " orcs" + _intellegentBlock());
        table.addEntry("1 hobgoblin captain with " + num + " hobgoblins"
                       + _raceBlock());
        table.addEntry(num + " giant goats: " + _animalBlock());
        table.addEntry("1 bandit captain with " + num + " bandits: "
                       + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,6));
        table.addEntry(num + " bandits: " + _npcCommonerBlock());
        table.addEntry(num + " deinonychuses (vgm)" + _animalBlock());
        table.addEntry("1 firenewt warlock of Imix (vgm) with " + num
                       + " firenewts (vgm)" + _intellegentBlock());
        table.addEntry(num + " giant striders (vgm)" + _animalBlock());
        table.addEntry(num + " gnoll flesh gnawers (vgm)" + _intellegentBlock());
        table.addEntry(num + " kobold dragon shields (vgm)" + _intellegentBlock());
        table.addEntry("1 kobold scale sorcerer (vgm) with " + num
                       + " kobolds" + _intellegentBlock());
        table.addEntry("1 xvart warlock of Raxivort (vgm) with " + num
                       + " xvarts (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(1,6) + 2);
        table.addEntry(num + " giant wolf spiders");
        table.addEntry(num + " hobgoblins" + _raceBlock());

        num = QString::number(Dice::roll(1,6) + 4);
        table.addEntry(num + " blood hawks" + _animalBlock());

        num = QString::number(Dice::roll(1,6) + 5);
        table.addEntry(num + " hyenas: " + _animalBlock());

        num = QString::number(Dice::roll(2,6));
        table.addEntry(num + " bandits: " + _npcCommonerBlock());
        table.addEntry(num + " tribal warriors: " + _npcCommonerBlock());
        table.addEntry("1 goblin boss with " + num + " goblins" + _intellegentBlock());
        table.addEntry(num + " firenewts (vgm)" + _intellegentBlock());
        table.addEntry(num + " gnoll hunters (vgm)" + _intellegentBlock());
        table.addEntry(num + " orc neutered ones of Yurtrus (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,8) + 1);
        table.addEntry(num + " axe beaks" + _animalBlock());

        num = QString::number(Dice::roll(2,8));
        table.addEntry(num + " goats: " + _animalBlock());
        table.addEntry(num + " kobolds" + _intellegentBlock());
        table.addEntry(num + " boggles (vgm): " + _intellegentBlock());
        table.addEntry(num + " neogi hatchlings" + _animalBlock());
        table.addEntry(num + " xvarts (vgm): " + _raceBlock());
        num2 = QString::number(Dice::roll(2,8));
        table.addEntry(num + " gnoll witherlings (vgm) with " + num2
                       + " gnolls" + _intellegentBlock());
        table.addEntry("1 kobold inventor (vgm) with "+ num + " kobolds"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(1,10));
        table.addEntry(num + " commoners: " + _npcCommonerBlock());
        num2 = QString::number(Dice::roll(1,4));
        table.addEntry(num + " winged kobolds with " + num2 + " kobolds"
                       + _intellegentBlock());
    }
    else { // tier 2
        table.addEntry("1 manticore" + _animalBlock());
        table.addEntry("1 chimera" + _animalBlock());
        table.addEntry("1 galeb duhr" + _intellegentBlock());
        table.addEntry("1 bulette");
        table.addEntry("1 wyvern" + _animalBlock());
        table.addEntry("1 young red dragon" + _raceBlock());
        table.addEntry("1 roc" + _animalBlock());
        table.addEntry("1 annis hag (vgm)" + _intellegentBlock());
        table.addEntry("1 flind (vgm)" + _intellegentBlock());
        table.addEntry("1 shoosuva (vgm)" + _intellegentBlock());
        table.addEntry("1 stone giant dreamwalker (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(1,2));
        table.addEntry(num + " gorgons" + _animalBlock());
        table.addEntry(num + " barghests (vgm)" + _intellegentBlock());
        table.addEntry(num + " hobgoblin devestators (vgm)" + _raceBlock());
        table.addEntry(num + " neogi masters (vgm)" + _intellegentBlock());
        table.addEntry(num + " orc blades of Ilneval(vgm)" + _intellegentBlock());
        table.addEntry(num + " yeth hounds (vgm)" + _animalBlock());
        table.addEntry(num + " orc tanarukk (vgm)" + _intellegentBlock());
        table.addEntry(num + " mouths of grolantor (vgm)" + _raceBlock());
        table.addEntry(num + " warlock of the great old ones (vgm): "
                       + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,3));
        table.addEntry(num + " perytons: " + _animalBlock());
        table.addEntry(num + " green hags" + _intellegentBlock());
        table.addEntry(num + " hill giants" + _raceBlock(), 5);
        table.addEntry(num + " young copper dragons: " + _npcCommonerBlock());
        table.addEntry(num + " neogis (vgm)" + _intellegentBlock());
        table.addEntry(num + " orc red fang of Shargaas (vgm)" + _intellegentBlock());
        table.addEntry(num + " redcap (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(1,4));
        table.addEntry(num + " pegasi: " + _animalBlock());
        table.addEntry(num + " lions: " + _animalBlock());
        table.addEntry(num + " brown bears: " + _animalBlock());
        num2 = QString::number(Dice::roll(2,6));
        table.addEntry("1 goblin boss with " + num + " dire wolves and "
                       + num2 + " goblins" + _intellegentBlock());
        table.addEntry(num + " phase spiders");
        table.addEntry(num + " werewolves: " + _npcCommonerBlock());
        table.addEntry(num + " ettins" + _raceBlock());
        table.addEntry(num + " revenants" + _npcCommonerBlock());
        table.addEntry(num + " cyclopses" + _raceBlock());
        table.addEntry(num + " stone giants" + _raceBlock());

        num = QString::number(Dice::roll(1,4) + 1);
        table.addEntry(num + " griffons: " + _animalBlock(), 5);
        table.addEntry(num + " aurochs (vgm): " + _animalBlock());
        table.addEntry(num + " hobgoblin iron shadows (vgm)" + _raceBlock());
        table.addEntry(num + " orc hand of Yurtrus (vgm)" + _intellegentBlock());
        table.addEntry(num + " quetzalcoatlus (vgm)" + _animalBlock());
        table.addEntry(num + " shadow mastiffs (vgm)" + _animalBlock());

        num = QString::number(Dice::roll(1,4) + 3);
        table.addEntry(num + " giant boars" + _animalBlock());

        num = QString::number(Dice::roll(2,4));
        table.addEntry("1 gnoll pack lord with " + num + " giant hyenas"
                       + _intellegentBlock());
        table.addEntry(num + " hippogriffs: " + _animalBlock());
        table.addEntry(num + " orogs" + _raceBlock());
        table.addEntry(num + " wereboars: " + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,6));
        table.addEntry(num + " giant elk: " + _animalBlock());

        num = QString::number(Dice::roll(1,6) + 2);
        table.addEntry(num + " giant goats: " + _animalBlock());
        table.addEntry(num + " worgs" + _animalBlock());
        table.addEntry(num + " harpies" + _animalBlock());
        table.addEntry(num + " ogres" + _animalBlock());
        num2 = QString::number(Dice::roll(2,6));
        table.addEntry(num + " veterans with " + num2 + " berzerkers: "
                       + _npcCommonerBlock());

        num = QString::number(Dice::roll(2,6));
        table.addEntry("1 half-ogre with " + num + " orcs"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(2,6) + 3);
        table.addEntry("1 orc Eye of Gruumsh with " + num + " orcs"
                       + _intellegentBlock());

        num = QString::number(Dice::roll(2,6) + 10);
        table.addEntry(num + " goats with 1 herder (tribal warrior): "
                       + _npcCommonerBlock());

        num = QString::number(Dice::roll(3,6));
        table.addEntry(num + " axe beaks: " + _animalBlock());
        table.addEntry("1 bandit captain with " + num + " bandits: "
                       + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,8) + 1);
        table.addEntry(num + " gnolls" + _intellegentBlock());
        table.addEntry(num + " hobgoblins" + _raceBlock());
        table.addEntry(num + " giant eagles: " + _animalBlock());
        table.addEntry(num + " gnoll fangs of Yeenoghu" + _intellegentBlock());

        num = QString::number(Dice::roll(2,8));
        table.addEntry("1 hobgoblin captain with " + num + " hobgoblins"
                       + _raceBlock());

        num = QString::number(Dice::roll(2,10));
        table.addEntry(num + " winged kobolds" + _intellegentBlock());
    }

    return table.getRollTableEntry() + _loot(tier);
}

QString MonsterTable::mountainEncounter(int tier)
{
    RandomTable table;

    QString num;
    QString num2;

    if (tier == 1) {
        table.addEntry("1 eagle: " + _animalBlock());
        table.addEntry("1 lion: " + _animalBlock());
        table.addEntry("1 giant goat: " + _animalBlock());
        table.addEntry("1 half-ogre" + _raceBlock());
        table.addEntry("1 berzerker: " + _npcCommonerBlock());
        table.addEntry("1 orog" + _raceBlock());
        table.addEntry("1 hell hound" + _animalBlock());
        table.addEntry("1 druid: " + _npcAdventurerBlock());
        table.addEntry("1 peryton" + _animalBlock());
        table.addEntry("1 manticore" + _animalBlock());
        table.addEntry("Enormous footprits left by a giant, which head into the "
               "mountain peaks");
        table.addEntry("1 giant elk: " + _animalBlock());
        table.addEntry("1 veteran: " + _npcAdventurerBlock());
        table.addEntry("1 orc eye of Gruumsh" + _intellegentBlock());
        table.addEntry("1 ogre" + _raceBlock());
        table.addEntry("1 griffon: " + _animalBlock(), 6);
        table.addEntry("1 basilisk" +  _animalBlock());
        table.addEntry("1 saber-toothed tiger" + _animalBlock());
        table.addEntry("1 cyclops" + _raceBlock());
        table.addEntry("1 troll" + _raceBlock());
        table.addEntry("1 galeb duhr" + _intellegentBlock());
        table.addEntry("1 air elemental");
        table.addEntry("1 bulette");
        table.addEntry("1 chimera" + _animalBlock());
        table.addEntry("1 wyvern" + _animalBlock());
        table.addEntry("1 stone giant" + _raceBlock());
        table.addEntry("1 frost giant" + _raceBlock());
        table.addEntry("1 barghest (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,2));
        table.addEntry(num + " hippogriffs" + _animalBlock());
        table.addEntry(num + " ettins" + _raceBlock());
        table.addEntry(num + " orc blade of Ilneval (vgm)" + _intellegentBlock());
        table.addEntry(num + " warlock of the archfey (vgm): " + _npcCommonerBlock());
        table.addEntry(num + " orc tanarukk (vgm)" + _intellegentBlock());
        table.addEntry(num + " warlock of the great old one (vgm): " + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,3));
        table.addEntry(num + " swarms of bats");
        num = QString::number(Dice::roll(1,4));
        table.addEntry(num + " harpies");
        num = QString::number(Dice::roll(2,4));
        table.addEntry(num + " aarakocra" + _raceBlock());
        table.addEntry(num + " orcs" + _raceBlock());
        num = QString::number(Dice::roll(3,4));
        table.addEntry(num + " kobolds" + _intellegentBlock());
        table.addEntry(num + " aurochs (vgm)" + _animalBlock());
        table.addEntry(num + " guard drakes (red)(vgm)" + _animalBlock());
        table.addEntry(num + " orc claw of luthic (vgm)" + _intellegentBlock());
        table.addEntry(num + " orc hand of Yutrus (vgm)" + _intellegentBlock());
        table.addEntry(num + " quetzalcoatlus (vgm)" + _animalBlock());
        table.addEntry(num + " orc red fang of Shargaas (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,6));
        table.addEntry(num + " goats: " + _animalBlock());
        table.addEntry("1 firenewt warlock of Imix with " + num
                       + " firewts (vgm)" + _intellegentBlock());
        table.addEntry(num + " giant striders (vgm)" + _animalBlock());
        table.addEntry(num + "firenewts riding giant striders (vgm)" + _intellegentBlock());
        table.addEntry(num + " kobold dragonshields (vgm)" + _intellegentBlock());
        table.addEntry("kobold scale sorcerer (vgm) with " + num + " kobolds" + _intellegentBlock());
        num = QString::number(Dice::roll(1,6) + 2);
        table.addEntry(num + " scouts: " + _npcCommonerBlock());
        num = QString::number(Dice::roll(1,6) + 3);
        table.addEntry(num + " pteranodons" + _animalBlock());
        num = QString::number(Dice::roll(2,6));
        num2 = QString::number(Dice::roll(1,6));
        table.addEntry(num + " dwarf soldiers (guards) with " + num2
               + " mules laden with iron ore" + _motivatedBlock());
        table.addEntry(num + " firenewts (vgm)" + _intellegentBlock());
        table.addEntry(num + " orc neutered one of yurtrus (vgm)" + _intellegentBlock());
        num = QString::number(Dice::roll(1,8) + 1);
        table.addEntry(num + " winged kobolds" + _intellegentBlock());
        num = QString::number(Dice::roll(2,8) + 1);
        table.addEntry(num + " blood hawks" + _animalBlock());
        num = QString::number(Dice::roll(1,10) + 5);
        table.addEntry(num + " tribal warriors: " + _npcCommonerBlock());
        num = QString::number(Dice::roll(2,10));
        table.addEntry(num + " stirges" + _animalBlock());
        table.addEntry("1 kobold inventor (vgm) with " + num + " kobolds"
                       + _intellegentBlock());
    }
    else { // tier 2
        table.addEntry("1 lion: " + _animalBlock());
        table.addEntry("1 saber-toothed tiger: " + _animalBlock());
        table.addEntry("1 basilisk" + _animalBlock());
        table.addEntry("1 manticore" + _animalBlock());
        table.addEntry("1 galeb duhr" + _intellegentBlock());
        table.addEntry("1 bulette");
        table.addEntry("1 wyvern" + _animalBlock());
        table.addEntry("1 fire giant" + _raceBlock());
        table.addEntry("1 cloud giant" + _raceBlock());
        table.addEntry("1 silver dragon: " + _npcCommonerBlock());
        table.addEntry("1 roc" + _animalBlock());
        table.addEntry("1 young red dragon" + _raceBlock());
        table.addEntry("1 barghest (vgm)" + _intellegentBlock());
        table.addEntry("1 anis hag (vgm)" + _intellegentBlock());
        table.addEntry("1 stone giant dreamwalker (vgm)" + _raceBlock());

        num = QString::number(Dice::roll(1,3));
        table.addEntry(num + " hell hounds" + _animalBlock());
        table.addEntry(num + " orc blade of ilneval (vgm)" + _intellegentBlock());
        table.addEntry(num + " warlock of the archfey (vgm): " + _npcCommonerBlock());
        table.addEntry(num + " orc tarnarukk (vgm)" + _intellegentBlock());
        table.addEntry(num + " warlock of the great old one (vgm): " + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,3) + 1);
        table.addEntry(num + " cyclopses" + _raceBlock());
        table.addEntry(num + " ork red fang of shargaas (vgm)" + _intellegentBlock());

        num = QString::number(Dice::roll(1,4));
        table.addEntry(num + " ettins" + _raceBlock());
        table.addEntry(num + " air elementals");
        table.addEntry(num + " trolls" + _raceBlock(), 5);
        table.addEntry(num + " chimeras" + _animalBlock());
        table.addEntry(num + " stone giants" + _raceBlock());
        table.addEntry(num + " frost giants: " + _raceBlock());
        table.addEntry(num + "aurochs (vgm)" + _animalBlock());
        table.addEntry(num + " guard drakes - red (vgm)" + _animalBlock());
        table.addEntry(num + " orc claw of luthic (vgm)" + _intellegentBlock());
        table.addEntry(num + " orc hand of yurtrus (vgm)" + _intellegentBlock());
        table.addEntry(num + " quetzalcoatlus (vgm)" + _animalBlock());

        num = QString::number(Dice::roll(1,4) + 3);
        table.addEntry(num + " dwarf trailblazers (scouts): "
                       + _motivatedBlock());

        num = QString::number(Dice::roll(2,4));
        table.addEntry(num + " harpies");

        num = QString::number(Dice::roll(1,6));
        num2 = QString::number(Dice::roll(3,6) + 10);
        table.addEntry("1 orc Eye of Gruumsh with " + num + " orogs and "
                       + num2 + " orcs" + _intellegentBlock());

        num = QString::number(Dice::roll(1,6) + 2);
        table.addEntry(num + " orcs" + _intellegentBlock());

        num = QString::number(Dice::roll(1,8) + 1);
        table.addEntry(num + " giant goats: " + _animalBlock());
        table.addEntry(num + " hippogriffs: " + _animalBlock());
        table.addEntry(num + " veterans: " + _npcAdventurerBlock());

        num = QString::number(Dice::roll(2,8) + 1);
        table.addEntry(num + " aarakocra" + _raceBlock());

        num = QString::number(Dice::roll(1,10));
        table.addEntry(num + " giant eagles: " + _animalBlock());
        table.addEntry(num + " berzerkers: " + _npcCommonerBlock());

        num = QString::number(Dice::roll(1,12));
        table.addEntry(num + " half-ogres" + _raceBlock());

    }

    return table.getRollTableEntry();
}

QString MonsterTable::nauticalEncounter(int tier)
{
    RandomTable table;
    QString num;
    QString num2;

    if (tier == 1) {
        table.addEntry("1 giant octopus");
        table.addEntry("1 merrow");
        table.addEntry("1 plesiosaurus");
        table.addEntry("1 giant constrictor snake");
        table.addEntry("1 sea hag");
        table.addEntry("1 giant shark");
        table.addEntry("1 water elemental");
        table.addEntry("1 sahuagin baron");
        table.addEntry("1 deep scion (vgm)");
        table.addEntry("1 slithering tracker (vgm)");

        num = QString::number(Dice::roll(1,4));
        table.addEntry(num + " sahuagin");
        table.addEntry(num + " dimetrodons (vgm)");

        num = QString::number(Dice::roll(2,4));
        table.addEntry(num + " steam mephits");
        table.addEntry("1 sahuagin priestess with " + num + " sahuagin");

        num = QString::number(Dice::roll(2,6));
        table.addEntry(num + "merfolk");

        num = QString::number(Dice::roll(1,10));
        num2= QString::number(Dice::roll(1,3));
        table.addEntry(num + " merfolk with " + num2 + " giant seahorses");
    }
    else if (tier == 2) {
        table.addEntry("1 giant octopus");
        table.addEntry("1 marid");
        table.addEntry("1 storm giant");
        table.addEntry("1 morkoth (vgm)");

        num = QString::number(Dice::roll(1,3));
        num2= QString::number(Dice::roll(2,10));
        table.addEntry(num + " sahuagin priestesses with " + num2 + " sahuagin");
        table.addEntry(num + " slithering trackers (vgm)");

        num = QString::number(Dice::roll(1,4));
        table.addEntry(num + " sea hags");
        table.addEntry(num + " plesiosauruses");
        table.addEntry(num + " giant constrictor snakes");
        table.addEntry(num + " water elementals");
        table.addEntry(num + " giant sharks");
        table.addEntry(num + " deep scions (vgm)");

        num = QString::number(Dice::roll(3,6));
        table.addEntry(num + " steam mephits");

        num = QString::number(Dice::roll(2,8));
        table.addEntry("1 sahuagin baron with " + num + " sahuagin");

        num = QString::number(Dice::roll(1,10));
        table.addEntry(num + " sahuagin");
        table.addEntry(num + " merrow");

        num = QString::number(Dice::roll(2,10));
        num2= QString::number(Dice::roll(1,4));
        table.addEntry(num + " merfolk with " + num2 + " giant seahorses");
        table.addEntry(num + " dimetrodons (vgm)");

    }
    else {
        table.addEntry("1 dragon turtle", 5);
        table.addEntry("1 kraken");
        table.addEntry("1 aboleth");
        table.addEntry("1 froghemoth (vgm)", 5);
        table.addEntry("1 storm giant, quintessent (vgm)");

        num = QString::number(Dice::roll(1,4));
        table.addEntry(num + " storm giants", 5);
        table.addEntry(num + " morkoths (vgm)", 2);

        num = QString::number(Dice::roll(1,4));
        num2= QString::number(Dice::roll(2,10));
        table.addEntry("1 sahuagin baron with " + num
                       + " sahuagin priestesses and " + num2 + " sahuagin", 10);
        table.addEntry(num + " marids", 5);

        num = QString::number(Dice::roll(1,6));
        table.addEntry(num + " giant sharks", 5);

        num = QString::number(Dice::roll(1,10));
        table.addEntry(num + " water elementals", 5);
        table.addEntry(num + " dimetrodons (vgm)", 5);

    }

    return table.getRollTableEntry();
}


QString MonsterTable::guardianFoe(int tier)
{
    RandomTable table;

    if (tier == 1) {
        // tier 1
        // 0
        table.addEntry("Shreiker - cr0", 15);
        // 1/8
        table.addEntry("Mastiff - cr1/8", 14);
        table.addEntry("Guard - cr1/8", 14);
        // 1/4
        table.addEntry("Skeleton - cr1/4", 13);
        table.addEntry("Zombie - cr1/4", 13);
        table.addEntry("Flying Sword - cr1/4", 13);
        // 1
        table.addEntry("Animated Armor - cr1", 12);
        // 2
        table.addEntry("Gargoyle - cr2", 11);
        table.addEntry("Shadow Mastiff (VGE) - cr2", 11);
        table.addEntry("Rug of Smothering - cr2", 11);
        table.addEntry("Mimic - cr2", 11);
        table.addEntry("Minotaur Skeleton - cr2", 11);
        table.addEntry("Gibbering Mouther - cr2", 11);
        table.addEntry("Ogre Zombie - cr2", 11);
        table.addEntry("Guard Drake (VGE) - cr2", 11);
    }
    if (tier == 1 || tier == 2) {
        // 3
        table.addEntry("Spectator Beholder - cr3", 10);
        table.addEntry("Hell Hound - cr3", 10);
        table.addEntry("Basilisk - cr3", 10);
    }
    if (tier == 2) {
        // 4
        table.addEntry("Flameskull - cr4", 9);
        table.addEntry("Helmed Horror - cr4", 9);

        // tier 2
        // 5
        table.addEntry("Flesh Golem - cr5", 8);
        table.addEntry("Otyug - cr5", 8);
        // 6
        table.addEntry("Galeb Duhr - cr6", 7);
        // 7
        table.addEntry("Shield Guardian - cr7", 6);
    }
    if (tier == 2 || tier == 3) {
        // 9
        table.addEntry("Clay Golem - cr9", 5);
        // 10
        table.addEntry("Stone Golem - cr10", 4);

        // tier 3
        // 11
        table.addEntry("Gynosphynx - cr11", 3);
    }
    if (tier == 3 || tier == 4) {
        // 16
        table.addEntry("Iron Golem - cr16", 2);
        // 17
        table.addEntry("Androsphynx - cr17");
    }

    // tier 4

    return table.getRollTableEntry();
}

/* Possibilities:
 * neighborhood adventure
 */
QString MonsterTable::generateUrbanEncounter(int tier)
{
    // 1 on 1d6 during the day, 2 during the night.

    int encounterType = Dice::roll(1,100);
    QString encounter;
    if (encounterType < 50) {
        encounter = urbanEncountersUnique();
        encounter += "\n";
        bool isNormal = Dice::roll(1,6) < 4;
        encounter += (isNormal) ? "- Innocuous" : "- Nefarius";
    }
    else if (encounterType < 75) {
        encounter = urbanEncounterXge(tier);

    }
    //else if (encounterType < 90) {
    else {
        encounter = "City Landmark";
    }
    return encounter;

    /*
    else if (encounterType < 95) {
        // NPC/watch/guard needs help/hostile
    }
    else if (encounterType < 97) {
        encounter = "Side Quest Hook";
    }
    else {
        encounter = "Neighborhood Adventure.";
    }
    */

}

QString MonsterTable::generateUrbanEncounterNight(int tier)
{
        QString encounter = urbanEncounterXge(tier);
        /*
        encounter += "\n- Intellegent motive: " + humanoidAttacksUrban() + "\n";
        encounter += "- Creature motive: " + creatureAttacksUrban() + "\n";
        */
        return encounter;
}

QString MonsterTable::friendlyHumanoidUrbanActivity()
{
    RandomTable table;

    table.addEntry("Trying to avoid enemy that is looking for them.");
    table.addEntry("Fighting enemy and winning");
    table.addEntry("Fighting enmy and losing");
    table.addEntry("Looking for someone");
    table.addEntry("Investigating a case/crime");
    table.addEntry("Looking to hire adventurers");
    table.addEntry("Looking for directions (headded party's way)");
    table.addEntry("Looking to be hired");
    table.addEntry("Needs a favor");
    table.addEntry("Simple greeting");
    table.addEntry("Passing on a rumor or news");
    table.addEntry("New in town, looking for companions");
    table.addEntry("Adventure hook:" + AdventureTables::adventureHook(), 3);

    return table.getRollTableEntry();
}

QString MonsterTable::_intellegentBlock()
{
    return "\nACTIVITY: " + EncounterTables::motivation();
}

QString MonsterTable::_raceBlock()
{
    return "\n" + NpcTables::npcGender() + ", " + NpcTables::npcDisposition()
            + _intellegentBlock();
}

QString MonsterTable::_npcAdventurerBlock()
{
    return "\n" + NpcTables::npcGender() + " " + NpcTables::AdventurerRace()
            + ", " + NpcTables::determineAlignment() + ", "
            + NpcTables::npcDisposition() + _intellegentBlock();
}

QString MonsterTable::_npcCommonerBlock()
{
    return "\n" + NpcTables::npcGender() + " " + NpcTables::commonRace()
            + ", " + NpcTables::determineAlignment() + ", "
            + NpcTables::npcDisposition() + _intellegentBlock();
}

QString MonsterTable::_motivatedBlock()
{
    return "\n" + NpcTables::npcGender() + ", " + NpcTables::npcDisposition();
}

QString MonsterTable::_animalBlock()
{
    return "\nACTIVITY: " + EncounterTables::animalDowntime();
}

QString MonsterTable::_loot(int tier)
{
    return "\nLOOT: " + LootTables::generateIndividualTreasure(tier);
}

