#include "randomchambers.h"

RandomChambers::RandomChambers()
{

}

QString RandomChambers::generateGeneralRoom(int tier)
{

    QString description;
    description = generalDungeonRoomType() + "\n";
    description += "LIGHT: " + lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier)
            + ".\n";

    return description;
}

QString RandomChambers::generateDeathTrapRoom(int dungeonLevel)
{
    QString description;
    description = deathTrapRoomType() + "\n";
    description += "LIGHT: " + lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(dungeonLevel)
            + ".\n";

    return description;
}

QString RandomChambers::generateLairRoom(int dungeonLevel)
{
    QString description;
    description = lairRoomType() + "\n";
    description += "LIGHT: " + lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(dungeonLevel)
            + ".\n";

    return description;
}

QString RandomChambers::generateMineRoom(int tier)
{
    QString description;
    description = mineRoomType() + "\n";
    description += "LIGHT: " + lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generatePlanarGateRoom(int tier)
{
    QString description;
    description = planarGateRoomType() + "\n";
    description += "LIGHT: " + lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generateMazeRoomType(int tier)
{
    QString description;
    description = mazeRoomType() + "\n";
    description += "LIGHT: " + lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;


}

QString RandomChambers::generateStrongholdRoom(int tier)
{
    QString description;
    description = strongholdRoom() + "\n";
    description += "LIGHT: " + lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generateTempleRoom(int tier)
{
    QString description;
    description = templeRoom() + "\n";
    description += "LIGHT: " + lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generateToomb(int tier)
{
    QString description;
    description = tombRoom() + "\n";
    description += "LIGHT: " + lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generateTreasureVault(int tier)
{
    QString description;
    description = treasureVaultRoom() + "\n";
    description += "LIGHT: " + lighting() + "\n";
    description += "FEATURE: " + primaryFeature() + "\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + "\n";
    description += "CONTENTS:\n" + chamberContents(tier) + "\n";

    return description;

}

QString RandomChambers::generateHallwayContents(int tier)
{
    QString sound = (Dice::roll(1,8) == 1) ? "\nSOUND: " + noises() : "";
    QString smell = (Dice::roll(1,8) == 1) ? "\nSMELL: " + odors() : "";
    QString feature = (Dice::roll(1,8) == 1) ? "\nFEATURE: " + primaryFeature()
                                       : "";

    bool isEncounter = Dice::roll(1, 6) == 1;
    if (!isEncounter) {
        return "Hallway all clear." + sound +  smell + feature;
    }

    RandomTable table;

    QString motivation = "\nMOTIVATION: " + EncounterTables::motivation();

    QString monster = MonsterTable::undermountainMonster(tier);
    QString guard = MonsterTable::guardianFoe(tier);
    QString activity = EncounterTables::generateActivity();
    QString hazard = dungeonHazards();
    QString monster_loot = LootTables::generateIndividualTreasure(tier);


    table.addEntry("\nMONSTER (dominant inhabitant or "
                   + monster + ")"
                   + "\nLoot: " + monster_loot
                   + motivation + "\n"
                   + activity
                   + sound +  smell + feature
                   , 8);

    table.addEntry("\nMONSTER (pet or allied creature): "
                   + monster
                   + "\nLoot: " + monster_loot
                   + motivation + "\n"
                   + activity
                   + sound +  smell + feature
                   , 12);
    table.addEntry("\nMONSTER (random): "
                   + monster
                   + "\nLoot: + monster_loot"
                   + motivation + "\n"
                   + activity
                   + sound +  smell + feature
                   , 9);

    QString obstacle = obstacles();
    table.addEntry("\nOBSTACLE: " + obstacle + sound +  smell + feature, 5);

    QString trap = TrapTables::generateTrap(tier);
    table.addEntry("\nTRAP: " + trap + sound +  smell + feature, 10);

    QString trick = TrapTables::generateTrick();
    table.addEntry("\nTRICK: " + trick + sound +  smell + feature, 4);

    table.addEntry("\nHAZARD: " + hazard + sound +  smell + feature, 6);


    return table.getRollTableEntry();
}

QString RandomChambers::generateLibraryRoom(int tier)
{
    QString description;
    description = "ROOM: " + libraryRoom() + ".\n";
    description += "DOORS: " + doorType() + ".\n";
    description += "LIGHT: " + lighting() + ".\n";
    description += "FEATURE: " + primaryFeature() + ".\n";
    description += "SOUND: " + noises() + "\n";
    description += "SMELL: " + odors() + "\n";
    description += "STATE: " + currentChamberState() + ".\n";
    description += "CONTENTS:\n" + chamberContents(tier) + ".\n";

    return description;
}

QString RandomChambers::generateCavernRoom(int tier)
{
    QString description;
    bool isNetwork = Dice::roll(1,100) < 40;
    description = "ROOM: " + cavern() + ".\n";

    if (isNetwork) {
        description += "This is a network of caves.\n";
    }
    else {
        description += "SOUND: " + noises() + "\n";
        description += "SMELL: " + odors() + "\n";
        description += "CONTENTS:\n" + chamberContents(tier) + ".\n";
    }

    return description;
}

QString RandomChambers::generalDungeonRoomType()
{
    RandomTable table;
    table.addEntry("Antechamber");
    table.addEntry("Armory", 2);
    table.addEntry("Audience Chamber");
    table.addEntry("Aveiary");
    table.addEntry("Banquet Room", 2);
    table.addEntry("Barracks", 3);
    table.addEntry("Bath or Latrine");
    table.addEntry("Bedroom");
    table.addEntry("Bestiary");
    table.addEntry("Cell", 3);
    table.addEntry("Chantry");
    table.addEntry("Chapel");
    table.addEntry("Cistern", 2);
    table.addEntry("Classroom");
    table.addEntry("Closet");
    table.addEntry("Conjuring Room", 2);
    table.addEntry("Court", 2);
    table.addEntry("Crypt", 3);
    table.addEntry("Dining Room", 2);
    table.addEntry("Divination Room", 2);
    table.addEntry("Dormitory");
    table.addEntry("Dressing Room");
    table.addEntry("Entry Room or Vestibule");
    table.addEntry("Gallery", 2);
    table.addEntry("Game Room", 2);
    table.addEntry("Guardroom", 3);
    table.addEntry("Hall", 2);
    table.addEntry("Great Hall", 2);
    table.addEntry("Kennel");
    table.addEntry("Kitchen", 2);
    table.addEntry("Laboratory", 2);
    table.addEntry("Library", 3);
    table.addEntry("Lounge", 2);
    table.addEntry("Meditation Chamber");
    table.addEntry("Observatory");
    table.addEntry("Office");
    table.addEntry("Pantry", 2);
    table.addEntry("Pen or Prison", 2);
    table.addEntry("Reception Room", 2);
    table.addEntry("Refectory", 2);
    table.addEntry("Robing Room");
    table.addEntry("Salon");
    table.addEntry("Shrine", 2);
    table.addEntry("Sitting Room", 2);
    table.addEntry("Smithy", 2);
    table.addEntry("Stable");
    table.addEntry("Storage Room", 2);
    table.addEntry("Storage Room or Vault", 2);
    table.addEntry("Study", 2);
    table.addEntry("Temple", 3);
    table.addEntry("Throne Room", 2);
    table.addEntry("Torture Chamber");
    table.addEntry("Training or Exercise Room", 2);
    table.addEntry("Trophy Room or Museum", 2);
    table.addEntry("Waiting Room");
    table.addEntry("Nursery or Schoolroom");
    table.addEntry("Well");
    table.addEntry("Workshop", 2);

    return table.getRollTableEntry();
}

QString RandomChambers::deathTrapRoomType()
{
    RandomTable table;

    table.addEntry("Antechamber or waiting room"
                   "\nfor spectators");
    table.addEntry("Guardroom\nfortified against intruders", 6);
    table.addEntry("Vault\n for holding important treasures, accessible only by "
                   "locked or secret door.", 3);
    table.addEntry("Puzzle\nRoom containing a puzzle that must be solved to bypass a "
                   "trap or monster", 3);
    table.addEntry("Trap Room\ndesigned to kill or capture creatures", 5);
    table.addEntry("Observation room\nallowing guards or spectators to observe "
                   "creatures moving through the dungeon");

    return table.getRollTableEntry();
}

QString RandomChambers::lairRoomType()
{
    RandomTable table;

    table.addEntry("Armory\nstocked with weapons and armor");
    table.addEntry("Audience\n chamber, used to receive guests");
    table.addEntry("Banquet\nroom for important celebrations");
    table.addEntry("Barracks\nwhere the lair's defenders are quartered");
    table.addEntry("Bedroom\nfor use by leaders");
    table.addEntry("Chapel\nwhere the lair's inhabitants worship");
    table.addEntry("Cistern\nor well for drinking water");
    table.addEntry("Guardroom\nfor the defense of the lair", 2);
    table.addEntry("Kennel\nfor pets or guard beasts");
    table.addEntry("Kitchen\nfor food storage and preparation");
    table.addEntry("Pen or prison\nwhere captives are held");
    table.addEntry("Storage\nmostly nonperishable goods", 2);
    table.addEntry("Throne Room\nwhere the lair's leaders hold court");
    table.addEntry("Torture chamber");
    table.addEntry("Training and exercise room");
    table.addEntry("Trophy room or museum");
    table.addEntry("Latrine or bath");
    table.addEntry("Workshop for the construction of weapons, armor, tools, and "
                   "other goods");

    return table.getRollTableEntry();
}

QString RandomChambers::mazeRoomType()
{
    RandomTable table;

    table.addEntry("Conjuring room, used to summon creatures that guard the "
                   "maze.");
    table.addEntry("Guardroom for sentinesl that patrol the maze.", 4);
    table.addEntry("Lair for guard beasts that patrol the maze.", 4);
    table.addEntry("Pen or prison accessible only by secret door, used to "
                   "hold captives condemned to the maze.");
    table.addEntry("Shrine dedicated to a god or other entity.");
    table.addEntry("Storage for food, as well as tools used by the maze's "
                   "guardians to keep the complex in working order.", 2);
    table.addEntry("Trap to confound or kill those sent into the maze.", 4);
    table.addEntry("Well that provides drinking water.");
    table.addEntry("Workshop where doors, torch sconces, and other "
                   "furnishings are repaired and maintained.");

    return table.getRollTableEntry();
}

QString RandomChambers::mineRoomType()
{
    RandomTable table;

    table.addEntry("Barracks for miners", 2);
    table.addEntry("Bedroom for a supervisor or manager");
    table.addEntry("Chapel dedicated to a patron deity of miners, earth, or"
                   "protection");
    table.addEntry("Cistern providing drinking water for miners");
    table.addEntry("Guardroom", 2);
    table.addEntry("Kitchen used to feed workers");
    table.addEntry("Laboratory used to conduct tests on strange nimerals "
                   "extracted from the mine");
    bool isDepleted = Dice::roll(1, 100) < 75;
    QString depleted = isDepleted ? "(Depleted)" : "(Still viable)";
    table.addEntry("Lode where metal ore is mined " + depleted, 6);
    table.addEntry("Office used by the mine supervisor");
    table.addEntry("Smithy for repairing damaged tools");
    table.addEntry("Storage for tools and other equipment", 2);
    table.addEntry("Strong room or vault used to store ore for transport to "
                   "the surface");

    return table.getRollTableEntry();
}

QString RandomChambers::planarGateRoomType()
{
    RandomTable table;

    table.addEntry("Decorated foyer or antechamber", 3);
    table.addEntry("Armory used by the portal's guardians", 5);
    table.addEntry("Audience chamber for receiving visitors", 2);
    table.addEntry("Barracks used by the portal's guards", 9);
    table.addEntry("Bedroom for use by the high-ranking members of the order "
                   "that guards the portal", 4);
    table.addEntry("Chapel dedicatd to a deity or deities related to the portal "
                   "and its defenders", 7);
    table.addEntry("Cistern providing fresh water", 5);
    table.addEntry("Classroom for use of initiates learning about the portal's "
                   "secrets", 3);
    table.addEntry("Conjuring room for summoning creatures used to investigate "
                   "or defend the portal");
    table.addEntry("Crypt where the remains of those that died guarding the "
                   "portal are kept", 2);
    table.addEntry("Dining room", 6);
    table.addEntry("Divination room used to investigate the portal and events "
                   "tied to it", 3);
    table.addEntry("Dormitory for visitors and guards", 5);
    table.addEntry("Entry room or vesibule", 2);
    table.addEntry("Gallery for displaying trophies and objects related to the "
                   "portal and those that guard it", 2);
    table.addEntry("Guardroom to protect or watch over the portal", 8);
    table.addEntry("Kitchen", 5);
    table.addEntry("Laboratory for conducting exoperiments relating to the "
                   "portal and creatures that emerge from it", 5);
    table.addEntry("Library holding books about the portal's history", 3);
    table.addEntry("Pen or prison for holding captives or creatures that "
                   "emerge from the portal", 5);

    bool isActive = Dice::roll(1, 100) < 25;
    QString active = isActive ? " (Still active)" : "";
    table.addEntry("Planar junction, where the gate to another plane stands"
                   + active, 2);

    table.addEntry("Storage", 3);
    table.addEntry("Strong room or vault, for guarding valuable treasures "
                   "connecet to the portal or funds used to pay the planar "
                   "gate's guardians");
    table.addEntry("Study", 2);
    table.addEntry("Torture chamber, for questioning creatures that pass"
                   "through the portal or that attmept to clandestinely use it",
                   1);
    table.addEntry("Latrine or bath", 3);
    table.addEntry("Workshop for constructing tools and gear needed to study"
                   "the portal", 2);

    return table.getRollTableEntry();
}

QString RandomChambers::strongholdRoom()
{
    RandomTable table;

    table.addEntry("Antechamber where visitors seeking access wait", 2);
    table.addEntry("Armory hoding high-quality gear, including light "
                   "seige weapons such as ballistas.", 3);
    table.addEntry("Audience chamber used by the master of the stronghold "
                   "to receive visitors");
    table.addEntry("Aviary or zoo for keeping exotic creatures");
    table.addEntry("Banquet room for hosting celebrations and guests", 4);
    table.addEntry("Barracks used by elite guards", 4);
    table.addEntry("Bath outfitted with a marble floor and other "
                   "luxurious accoutrements");
    table.addEntry("Bedroom for use by the stronghold's master or "
                   "important guests");
    table.addEntry("Chapel dedicated to a deity associated with the "
                   "stronhold's master");
    table.addEntry("Cistern providing drinking water", 3);
    table.addEntry("Dining room for intimate gatherings or informal "
                   "meals", 4);
    table.addEntry("Dressing room featuring a nunber of wardrobes");
    table.addEntry("Gallery for the display of expensive works of art "
                   "and trophies", 3);
    table.addEntry("Game room used to entertain visitors", 3);
    table.addEntry("Guardroom", 18);
    table.addEntry("Kennel where monsters or trained animals that "
                   "protect the stronghold are kept");
    table.addEntry("Kitchen designed to prepare exotic foods for large "
                   "numbers of guests", 6);
    table.addEntry("Library with an extensive collection of rare books", 4);
    table.addEntry("Lounge used to entertain guests");
    table.addEntry("Pantry, including cellar for wine or spirits", 8);
    table.addEntry("Sitting room for family and intimate guests", 4);
    table.addEntry("Stable", 5);
    table.addEntry("Storage for mundane goods and supplies", 8);
    table.addEntry("Strong room or vault for protecting important "
                   "treasures (75% chance of being hidden behind a secret "
                   "door");
    table.addEntry("Study, including a writing desk", 5);
    table.addEntry("Throne room , elaborately decorated");
    table.addEntry("Waiting room where lesser guests are held before "
                   "receiving an audience", 3);
    table.addEntry("Latrine or bath", 2);
    table.addEntry("Crypt belonging to the stronghold's master or "
                   "someone else of importance", 2);

    return table.getRollTableEntry();
}

QString RandomChambers::templeRoom()
{
    RandomTable table;

    table.addEntry("Armory filled with weapons and armor, battle "
                   "banners, and pennants", 3);
    table.addEntry("Audience chamber where priests of the temple "
                   "receive commoners and low-ranking visitors", 2);
    table.addEntry("Banquet room used for celebrations and holy days", 2);
    table.addEntry("Barracks for the temple's military arm or its hired"
                   "guards", 3);
    table.addEntry("Cells where the faithful cna sit in quiet contemplation",
                   4);
    table.addEntry("Central temple build to accomodate rituals", 10);
    table.addEntry("Chapel dedicated to a lesser deity associated with the "
                   "temple's major deity", 4);
    table.addEntry("Classroom used to train initiates and priests", 4);
    table.addEntry("Conjuring room, specially sanctified and used to summon "
                   "extraplanar creatures", 13);
    table.addEntry("Crypt for a high priest or similar figure, hidden and "
                   "heavily guarded by creatures and traps", 6);
    table.addEntry("Dining room (large) for the temple's servants and "
                   "lesser priests");
    table.addEntry("Dining room (small) for the temple's high priests");
    table.addEntry("Divination room, inscribed with runes and stocked with "
                   "soothsaying implements", 3);
    table.addEntry("Dormitory for lesser priests or students", 4);
    table.addEntry("Guardroom", 6);
    table.addEntry("Kennel for animals or monsters associated with the "
                   "temple's deity");
    table.addEntry("Kitchen (might bear a disturbing resemblance to a "
                   "torture chamber in an evil temple", 3);
    table.addEntry("Library, well stocked with religious treasties", 5);
    table.addEntry("Prison for captured enemies (in good or neutral "
                   "temples) or those designates as sacrifices (in evil "
                   "temples)", 3);
    table.addEntry("Robing room containing ceremonial outfits and items", 5);
    table.addEntry("Stable for riding horses and mounts belonging "
                   "to the temple, or for visiting messengers and caravans");
    table.addEntry("Storage holding mundane supplies", 5);
    table.addEntry("Strong room or vault holding important relics and "
                   "ceremonial items, heavily trapped");
    table.addEntry("Torture chamber, used in inquisitions (in good or "
                   "neutral tamples with a lawful bent) or for the sheer "
                   "joy of causing pain (evil temples)", 2);
    table.addEntry("Trophy room where are celebrating key figures and "
                   "events from mythology is displayed", 7);
    table.addEntry("Latrine or bath");
    table.addEntry("Well for drinking water, defendable in the case of "
                   "attack or seige", 5);
    table.addEntry("Workshop for repairing or creating weapons, "
                   "religious item, and tools", 6);

    return table.getRollTableEntry();
}

QString RandomChambers::tombRoom()
{
    RandomTable table;

    table.addEntry("Antechamber for those that have come to pay "
                   "respects to the dead or prepare themselves for "
                   "burial rituals");
    table.addEntry("Chapel dedicated to deities that watch over the dead "
                   "and protect their resting places", 2);
    table.addEntry("Crypt for less important burials", 5);
    table.addEntry("Divination room, used in rituals to contact the dead "
                   "for guidance");
    table.addEntry("False crypt (trapped) to kill or capture thieves");
    table.addEntry("Gallery to display the deeds of the deceased");
    table.addEntry("Grand crypt for a noble, high priest, or other "
                   "important individual");
    table.addEntry("Guardroom, usually guarded by undead, "
                   "constructs, or other creatures that don't need to "
                   "eat or sleep", 2);
    table.addEntry("Robing room for priests to prepare for burial rituals");
    table.addEntry("Storage, stocked with tools for maintaining the "
                   "tomb and preparing the dead for burial", 2);
    table.addEntry("Tomb where the wealthiest and most important "
                   "folk are interred, protected by secret doors and "
                   "traps");
    table.addEntry("Workshop for embalming the dead", 2);

    return table.getRollTableEntry();
}

QString RandomChambers::treasureVaultRoom()
{
    RandomTable table;

    table.addEntry("Antechamber for visiting dignitaries");
    table.addEntry("Armory containing mundane and magic gear used "
                   "by the treasure vault's guards");
    table.addEntry("Barracks for guards", 2);
    table.addEntry("Cistern providing fresh water");
    table.addEntry("Guardroom to defend against intruders", 4);
    table.addEntry("Kennel for trained beasts used to guard the "
                   "treasure vault");
    table.addEntry("Kitchen for feeding guards");
    table.addEntry("Watch room that allows guards to observe those "
                   "who approach the dungeon");
    table.addEntry("Prison for holding captured intruders");
    table.addEntry("Stron room or vault, for guarding the treasure "
                   "hidden in the dungeon, accessible ony by locked "
                   "or secret door", 2);
    table.addEntry("Torture chamber for extracting information from captured "
                   "intruders");
    table.addEntry("Trap or other trick designed to kill or capture "
                   "creatures that enter the dungeon");

    return table.getRollTableEntry();
}

QString RandomChambers::libraryRoom()
{
    RandomTable table;

    table.addEntry("Circulation desk");
    table.addEntry("Maze of shelves");
    table.addEntry("Classroom");
    table.addEntry("Summoning room");
    table.addEntry("Divination room");
    table.addEntry("Reference books");
    table.addEntry("Rare and restricted books");
    table.addEntry("Book sorting");
    table.addEntry("Archives");
    table.addEntry("Journals");
    table.addEntry("Directory");
    table.addEntry("Break room for librarians");
    table.addEntry("Activities room");
    table.addEntry("Museum room");
    table.addEntry("Artifact display");
    table.addEntry("Themed display presentation");
    table.addEntry("Guard room for secure section of library");
    table.addEntry("Guard barraks");
    table.addEntry("Study");
    table.addEntry("Alchemy lab");
    table.addEntry("Bedroom");
    table.addEntry("Cell or jail for those who break library rules");
    table.addEntry("Conference room");
    table.addEntry("Ballroom");

    return table.getRollTableEntry();
}

QString RandomChambers::cavern()
{
    RandomTable table;

    table.addEntry("Stelagtites and Stelagmites");
    table.addEntry("Fungal forrest");
    table.addEntry("Crystal clusters (OotA, p. 26)");
    table.addEntry("Subterranian sea or lake");
    table.addEntry("Submerged caves");
    table.addEntry("Dungeon entrance");
    table.addEntry("Lair or den of subterranian creatures");
    table.addEntry("Ancient ruins");
    table.addEntry("Inhabited region");
    table.addEntry("Faerzress: a region of dim, glowing light with other abilities (OotA, p. 21)");
    table.addEntry("Boneyard (OotA, p. 25)");
    QString depth = QString::number(Dice::roll(2,4) * 100);
    table.addEntry("Gorge, " + depth + " feet deep.");
    depth = QString::number(Dice::roll(2,6) * 10);
    table.addEntry("High ledge that skirts a ravine " + depth + " feet deep");
    table.addEntry("Lava cave");
    table.addEntry("Muck Pit - 3 foot deep muck fills the cavern");
    table.addEntry("Unstable cavern, falling rocks");
    QString width= QString::number(Dice::roll(2,4) * 10);
    depth = QString::number(Dice::roll(2,4) * 10);
    table.addEntry("Rope bridge over ravine that is " + width + " feet wide and "
                   + depth + " feet deep");
    table.addEntry("Dry cave that is easily defended. Long rest possible");
    table.addEntry("Sinhole");
    table.addEntry("Slime of moldy cave");
    table.addEntry("Poison gas caves");
    table.addEntry("Steam vents");
    table.addEntry("Underground stream");
    table.addEntry("Web-filled cave");
    table.addEntry("Stelagmite and column forrest");
    table.addEntry("Mine");
    table.addEntry("Fungal growth - knee high. Sometimes grazed by subterranian animals");
    table.addEntry("Abandoned battlefield");
    table.addEntry("Active battlefield");
    table.addEntry("Outpost");
    table.addEntry("Driftlight caves");
    table.addEntry("Purple worm or ankheg tunnels");
    table.addEntry("Carved tunnels");
    table.addEntry("Large, cathedral caverns");
    table.addEntry("Sunken swamp");
    table.addEntry("Vortex to an elemental plane");
    table.addEntry("Windy caverns");
    table.addEntry("Abandoned remanents of an ancient society");

    return table.getRollTableEntry();
}

QString RandomChambers::doorType()
{
    RandomTable table;
    table.addEntry("Wooden", 10);
    table.addEntry("Wooden, barred or locked", 2);
    table.addEntry("Stone");
    table.addEntry("Stone, barred or locked");
    table.addEntry("Iron");
    table.addEntry("Iron, barred or locked");
    table.addEntry("Portcullis");
    table.addEntry("Portcullis, locked in place");
    table.addEntry("Secret door");
    table.addEntry("Secret door, barred or locked");

    return table.getRollTableEntry();
}


QString RandomChambers::currentChamberState()
{
    RandomTable table;

    table.addEntry("Rubble, ceiling partially collapsed.", 3);
    table.addEntry("Holes, floor partially collapsed", 2);
    table.addEntry("Ashes, contents mostly burned", 2);
    table.addEntry("Used as a campsite", 2);
    table.addEntry("Pool of water; chamber's original contents are water "
                   "damaged", 2);
    table.addEntry("Furniture wrecked but still present", 5);
    QString newUse = generalDungeonRoomType();
    table.addEntry("Converted to some other use: " + newUse, 2);
    table.addEntry("Stripped bare");
    table.addEntry("Pristine and in original state");

    return table.getRollTableEntry();
}

QString RandomChambers::chamberContents(int tier)
{
    RandomTable table;


    QString monster = MonsterTable::dungeonMonster(tier);
    QString guard = MonsterTable::guardianFoe(tier);
    QString treasure = LootTables::generateTreasureHorde(tier);
    QString hazard = dungeonHazards();
    QString obstacle = obstacles();
    QString trap = TrapTables::generateTrap(tier);
    QString trick = TrapTables::generateTrick();
    QString complexTrap = complexTrap::generateTrap(tier);

    table.addEntry("MONSTER (dominant inhabitant or " + monster + ")" , 8);
    table.addEntry("MONSTER (dominant inhabitant or "
                   + monster + ") with treasure" + treasure, 7);
    table.addEntry("MONSTER (pet or allied creature): " + monster , 12);
    table.addEntry("MONSTER (pet or allied creature) guarding treasure: "
                   + guard + "\n" + treasure, 6);
    table.addEntry("MONSTER (random): " + monster, 9);
    table.addEntry("MONSTER (random) with treasure: " + monster + "\n"
                   + treasure, 8);
    table.addEntry("HAZARD (" + hazard + ") with incidental treasure\n"
                   + LootTables::generateIndividualTreasure(tier), 7);
    table.addEntry("OBSTACLE: " + obstacle, 5);
    table.addEntry("TRAP: " + trap, 10);
    table.addEntry("TRAP protecting treasure: " + trap + "\n" + treasure, 3);
    table.addEntry("TRICK: " + trick, 4);
    table.addEntry("EMPTY ROOM", 8);
    table.addEntry("HAZARD: " + hazard, 6);
    table.addEntry(treasure, 6);
    table.addEntry(complexTrap);

    return table.getRollTableEntry();
}

QString RandomChambers::dungeonHazards()
{
    RandomTable table;

    table.addEntry("Brown mold (DMG 104)", 3);
    table.addEntry("Green slime", 5);
    table.addEntry("Shrieker", 2);
    table.addEntry("Spiderwebs", 6);
    table.addEntry("Violet fungus", 2);
    table.addEntry("Yellow mold", 3);
    table.addEntry("Russet Mold (VGM vegegympy)", 1);

    RandomTable gasTable;
    gasTable.addEntry("Only effect is to obscure vision when passing through.");
    gasTable.addEntry("Blinds for 1d6 turns after passing through.");
    gasTable.addEntry("Fear: Con save vs DC 10 or run back 120 feet");
    gasTable.addEntry("Sleep: party sound asleep for 1d6 turns (sleep spell)");
    gasTable.addEntry("Strength: adds 1d6 points of strength for 1 to 10 hours.");
    gasTable.addEntry("Sickness: Add 2 levels of exhaustion.");

    table.addEntry("Gas hazard: " + gasTable.getRollTableEntry(), 3);

    return table.getRollTableEntry();
}

QString RandomChambers::obstacles()
{
    RandomTable table;

    int radius = Dice::roll(1, 10) * 10;
    table.addEntry("Antilife aura with radius of "
                   + QString::number(radius)
                   + " feet; while in the aura, living creatures can't regain "
                     "hit points.");
    table.addEntry("Battering winds reduce speed by half, impose disadvantage "
                   "on ranged attack rolls");
    table.addEntry("Blade Barrier blocks passage");
    table.addEntry("Cave-in", 9);
    int width = Dice::roll(1, 4) * 10;
    int deep = Dice::roll(2, 6) * 10;
    table.addEntry("Chasm "
                   + QString::number(width) + " feet wide and "
                   + QString::number(deep)
                   + " feet deep, possibly connected to other levels of the "
                     "dungeon");
    deep = Dice::roll(2, 10);
    table.addEntry("Flooding leaves " + QString::number(deep)
                   + "ft. of water in the area; create nearby upward-sloping "
                     "passages, raised floors, or rising stairs to contain the "
                     "water.", 2);
    bool isBridge = Dice::roll(1, 100) < 50;
    QString bridge = isBridge? ". A stone bridge crosses it." : "";
    table.addEntry("Lava flows through the area" + bridge);
    bool isHazard = Dice::roll(1, 100) < 25;
    QString hazard = isHazard? ". " + dungeonHazards() + " is among them." : "";
    table.addEntry("Overgrown mushrooms block progress and must be hacked down"
                   + hazard);
    table.addEntry("Poisonous gas deals 1d6 poison damage per minute of "
                   "esposure");
    table.addEntry("Reverse Gravity spell effect causes creatures to fall "
                   "toward the ceiling");
    table.addEntry("Wall of Fire spell blocks passage");
    table.addEntry("Wall of Force spell blocks passage");

    return table.getRollTableEntry();
}

QString RandomChambers::poolEffects()
{
    RandomTable attribute;
    attribute.addEntry("Strength");
    attribute.addEntry("Dexterity");
    attribute.addEntry("Constitution");
    attribute.addEntry("Intellegence");
    attribute.addEntry("Wisdom");
    attribute.addEntry("Charisma");

    RandomTable table;

    table.addEntry("Mundane", 10);
    table.addEntry("Heals 2d8 hp.");
    table.addEntry("Drains 2d8 hp.");
    table.addEntry("Makes bather 2d8 years younger");
    table.addEntry("Makes bather 2d8 years older");
    table.addEntry("Changes gender (only works once on each bather)");
    table.addEntry("Add 1 point to " + attribute.getRollTableEntry() + " for 1 day");
    table.addEntry("Add 1 level to all spells cast for 1 day");
    table.addEntry("Add 1 AC for day");
    table.addEntry("Drain 1 point from " + attribute.getRollTableEntry() + " for 1 day");
    table.addEntry("All spells cast as 1 level lower for 1 day.");
    table.addEntry("Removes all exhaustion");
    table.addEntry("Adds 1 level of exhaustion");
    table.addEntry("Adds poisoned state");
    table.addEntry("Bather glows with faerie fire for 1 day");
    table.addEntry("Weapons dipped in pool act as magical +1 for a day");
    table.addEntry("Actually a gate to another place");
    table.addEntry("Gate to the plane of water");
    table.addEntry("Bather gains Poisoned condition");
    table.addEntry("Bather gains inspiration");
    table.addEntry("Anything placed in the pool is mended and cleaned, bathers are made immediately clean.");
    table.addEntry("Anything placed in the pool becomes soiled and smells of sewage. Bathers increase wandering monster checks.");

    return table.getRollTableEntry();
}

QString RandomChambers::poolContents()
{
    RandomTable table;

    table.addEntry("Empty (needs to be filled to gain effect.)", 5);
    table.addEntry("Clean Water", 10);
    table.addEntry("Blood");
    table.addEntry("Dirty Water", 10);
    table.addEntry("Green slime");
    table.addEntry("Black pudding");
    table.addEntry("Gelatinous cube settled to look like water unless examined");
    table.addEntry("Muddy water");
    table.addEntry("Thick mud");
    table.addEntry("Boiling water");
    table.addEntry("Ale");
    table.addEntry("Wine");
    table.addEntry("Bubbling hot mud");
    table.addEntry("Ofal, guts");
    table.addEntry("Oil (cool)");
    table.addEntry("Boiling oil");
    table.addEntry("Lava");
    table.addEntry("Green water (algae)");
    table.addEntry("Harmless, opaque, colored slime");
    table.addEntry("Feces and urine");
    table.addEntry("A shimmering, liquid-like energy");
    table.addEntry("An inpenetrable dark, cold fluid");
    table.addEntry("Frozen solid ice");
    table.addEntry("Molten adamantine (looks like lava, and cools to a permanent solid in 1d6 rounds if removed)");
    table.addEntry("Mercury (bathers float on top unless pushed down with force)");

    return table.getRollTableEntry();
}


QString RandomChambers::noises()
{
    RandomTable table;

    table.addEntry("Bang or slam");
    table.addEntry("Bellowing");
    table.addEntry("Buzzing");
    table.addEntry("Chanting");
    table.addEntry("Chiming");
    table.addEntry("Chirping");
    table.addEntry("Clanking");
    table.addEntry("Clashing");
    table.addEntry("Clicking");
    table.addEntry("Coughing");
    table.addEntry("Creaking");
    table.addEntry("Drumming");
    table.addEntry("Footsteps ahead");
    table.addEntry("Footsteps approaching");
    table.addEntry("Footsteps behind");
    table.addEntry("Footsteps receding");
    table.addEntry("Footsteps to the side");
    table.addEntry("Faint Giggling");
    table.addEntry("Gong");
    table.addEntry("Grating");
    table.addEntry("Groaning");
    table.addEntry("Grunting");
    table.addEntry("Hissing");
    table.addEntry("Horn or trumpet sounding");
    table.addEntry("Howling");
    table.addEntry("Humming");
    table.addEntry("Jingling");
    table.addEntry("Knocking");
    table.addEntry("Laughter");
    table.addEntry("Moaning");
    table.addEntry("Murmuring");
    table.addEntry("Music");
    table.addEntry("Rattling");
    table.addEntry("Ringing");
    table.addEntry("Rustling");
    table.addEntry("Scratching or scrabbling");
    table.addEntry("Screaming");
    table.addEntry("Scuttling");
    table.addEntry("Shuffling");
    table.addEntry("Slithering");
    table.addEntry("Snapping");
    table.addEntry("Sneezing");
    table.addEntry("Sobbing");
    table.addEntry("Splashing");
    table.addEntry("Splintering");
    table.addEntry("Squeaking");
    table.addEntry("Squealing");
    table.addEntry("Tapping");
    table.addEntry("Thud");
    table.addEntry("Thumping");
    table.addEntry("Tinkling");
    table.addEntry("Twanging");
    table.addEntry("Whining");
    table.addEntry("Whispering");
    table.addEntry("Whistling");

    return table.getRollTableEntry();

}

QString RandomChambers::odors()
{
    RandomTable table;

    table.addEntry("Acrid");
    table.addEntry("Chlorine");
    table.addEntry("Dank or moldy");
    table.addEntry("Earthy");
    table.addEntry("Manure");
    table.addEntry("Metallic");
    table.addEntry("Ozone");
    table.addEntry("Putrid");
    table.addEntry("Rotting vegetation");
    table.addEntry("Salty and wet");
    table.addEntry("Smoky");
    table.addEntry("Stale");
    table.addEntry("Sulfurous");
    table.addEntry("Urine");

    return table.getRollTableEntry();
}

QString RandomChambers::primaryFeature()
{
    RandomTable table;

    table.addEntry("None", 80);
    table.addEntry("Pool of " + poolContents() + ". Effect on bathers: "
                   + poolEffects(), 32);
    table.addEntry("Chains hang from ceiling");
    table.addEntry("Cobwebs");
    table.addEntry("Ceiling cracks");
    table.addEntry("Floor cracks");
    table.addEntry("Wall cracks");
    table.addEntry("Dripping wet ceiling");
    table.addEntry("Damp walls");
    table.addEntry("Dried blood");
    table.addEntry("Dung");
    table.addEntry("Thick dust");
    table.addEntry("Common fungi");
    table.addEntry("Lever with non-obvious use");
    table.addEntry("Common mold");
    table.addEntry("Leaves and twigs");
    table.addEntry("Harmless slime");
    table.addEntry("Floor spikes, rusted and immobile");
    table.addEntry("Straw");
    table.addEntry("Wall scratchings");
    table.addEntry("Altar");
    table.addEntry("Armchair");
    table.addEntry("Armoire");
    table.addEntry("Curtain");
    table.addEntry("Bed");
    table.addEntry("Brazier and charcoal");
    table.addEntry("Huge, 125 galon cask");
    table.addEntry("Chandelier");
    table.addEntry("Large, empty chest");
    table.addEntry("Couch");
    table.addEntry("Pile of cussions");
    table.addEntry("Dais");
    table.addEntry("Desk");
    table.addEntry("Fireplace and wood");
    table.addEntry("Fireplace with mantel");
    table.addEntry("Fountain");
    table.addEntry("Fresco");
    table.addEntry("Grindstone");
    table.addEntry("Large idol");
    table.addEntry("Painting");
    table.addEntry("Pedestal");
    table.addEntry("Pool");
    table.addEntry("Rug");
    table.addEntry("Shrine");
    table.addEntry("Statue");
    table.addEntry("Large Table");
    table.addEntry("Throne");
    table.addEntry("Tapestry");
    table.addEntry("Tub");
    table.addEntry("Urn");
    table.addEntry("Workbench");
    table.addEntry("Large bell");
    table.addEntry("Chimes");
    table.addEntry("Pillars");
    table.addEntry("Font");
    table.addEntry("Gong");
    table.addEntry("Holy or unholy symbol");
    table.addEntry("Holy or unholy writings");
    table.addEntry("Lectern");
    table.addEntry("Mosaic");
    table.addEntry("Pews");
    table.addEntry("Pulpit");
    table.addEntry("Book");
    table.addEntry("Large bowl");
    table.addEntry("Cage");
    table.addEntry("Cauldron");
    table.addEntry("Crystal Ball (mundane)");
    table.addEntry("Large Horn");
    table.addEntry("Magic Circle");
    table.addEntry("Large skull");
    table.addEntry("Giant hourglass");
    table.addEntry("Mirror");
    table.addEntry("Two copper pipes along one wall from floor to ceiling, one steaming, one frosty.");
    table.addEntry("A large stone pipe opening in wall drips greenish fluid onto floor.");
    table.addEntry("A large stone wheel set on one wall, clicks when turned.");
    table.addEntry("A stone sundial in center of room under ceiling painted to look like the sky.");
    table.addEntry("The walls are lined with stone flower boxes filled with unsettling-scented green and purple flowers.");
    table.addEntry("A natural spring in the center of the room surrounded by glowing mushrooms.");
    table.addEntry("Several 4'-long rose-quartz outcroppings from the ceiling.");
    table.addEntry("The floor is covered in upright, magnetized needles (10d10).");
    table.addEntry("An alcove on one wall is filled with neatly-stacked, empty wooden mugs.");
    table.addEntry("A giant red 'X' has been sloppily painted in the center of the floor.");
    table.addEntry("'Chog loves Jessika' is scratched in charcoal on one wall.");
    table.addEntry("The ceiling is covered in upside-down furniture, bolted to the stone.");
    table.addEntry("One wall has been painted to look like three windows looking out into a lovely garden.");
    table.addEntry("The skeleton of a small dog is curled forlornly around a well-gnawed scorpion tail.");
    table.addEntry("A pale white pine tree sprouts from the floor in one corner.");
    table.addEntry("The skeleton of a monkey lies in a far corner, its hand in a ceramic jar wrapped around a gem.");
    table.addEntry("A brass lever is set into the middle of one wall. 'Do not pull' is scrawled next to it.");
    table.addEntry("A stone frame in the ceiling hangs above a pile of broken pieces of mirror.");
    table.addEntry("A comfy chair sits in one corner with a table beside it. On the table are a pair of broken spectacles and a book called 'For Doom, the Fell Trolls'.");
    table.addEntry("An unlit chandelier hangs from the ceiling. It holds thirteen black candles and is creepy as hell.");
    table.addEntry("A brass hookah is here, surrounded by seven overstuffed ottomans.");
    table.addEntry("A massive gong in the center of the room with a bone striker.");
    table.addEntry("Bloody footprints lead from the entrance of the room to stop at a seemingly blank wall.");
    table.addEntry("Three big wooden buckets filled with smashed grapes sit on one side of the room.");
    table.addEntry("Bloated, pale vines hang from the dirt ceiling here.");
    table.addEntry("A pair of human eyes float in a jar left in a corner of the room. Did they just move!?");
    table.addEntry("The hilt and 6 inches of the blade of a sword jut from the solid stone floor of the room.");
    table.addEntry("An intricate water clock has been installed on one side of this room. Instead of water, it appears to have been filled with vinegar.");
    table.addEntry("One wall of this room appears to be made entirely of smoky quartz, and shapes seem to writhe and twist within it.");
    table.addEntry("A small stone pyramid is built into the ceiling, pointing down.");
    table.addEntry("This room is choked with stinging, prickly weeds.");
    table.addEntry("The hollow carapace of a great beetle nearly fills this room. A doorway appears to have been cut into its side.");
    table.addEntry("Plaintive music seems to come from somewhere beyond the ceiling of this room.");
    table.addEntry("A large, black, wood-and-hide drum sits in the middle of the room.");
    table.addEntry("A porcelain bathtub, filled with steaming water, sits invitingly in the corner.");
    table.addEntry("A strange hole in one wall, no more than 5 inches wide, emits an odd odor.");
    table.addEntry("Three dead kobolds, dressed as human children, lay side-by-side in front of a smoldering fireplace.");
    table.addEntry("An empty bookcase has been smashed to bits in this room.");
    table.addEntry("A tiny door, only 2' tall, is set into one wall of this room.");
    table.addEntry("A dartboard hangs on one wall, full of manticore spines.");
    table.addEntry("A small hibachi sizzles merrily on a stout oak table.");
    table.addEntry("Three tiny alcoves set high on the wall near the ceiling each containing a grinning imp sculpture.");
    table.addEntry("A large roll of black silk lies in one corner. If unrolled, a human corpse falls out.");
    table.addEntry("A massive harp, with strings all broken, sits by a stool in the center of the room.");
    table.addEntry("A small bar with several stools sits on one side of the room.");
    table.addEntry("A broken birdcage lies in a corner. A copious amount of blood has been splashed on the walls of this room.");
    table.addEntry("A still-smoking pipe sits in an ashtray on a small table here.");
    table.addEntry("A nest containing three purple eggs sits on a high ledge near the ceiling.");
    table.addEntry("An extensive set of wooden toy blocks has been set up on the floor of this room. The layout vaguely reminds you of your home town, but a hideous stone idol squats in the main square.");
    table.addEntry("A stinking pile of refuse is heaped in front of the entrance to this room. Ugh!");
    table.addEntry("A torn bag of sand has been scattered around the room. Huge footsteps are visible in it here and there.");
    table.addEntry("A marble pedestal sits in the center of the room, with a hand-shaped depression in its center.");
    table.addEntry("A stack of hand-written papers sits in a corner, 200 sheets in all, with the words 'This is not the way' written over and over again on them.");
    table.addEntry("A mannequin hangs from a noose in this room. It is crawling with flies!");
    table.addEntry("Something that leaves a slimy trail has dug a 3' wide tunnel into the floor of this room.");
    table.addEntry("Two stone dogs sit at attention on either side of the entrance of this room. One has a struggling mouse beneath one supposedly-immobile stone paw.");
    table.addEntry("A giant mousetrap, 6' x 3', sits in the center of the room with a human arm on the trigger.");
    table.addEntry("Half a human face, and one limp hand, jut from the solid stone wall of this room.");
    table.addEntry("The odor of brimstone hangs in the air of this room. A magic circle has been inscribed on the floor with salt.");
    table.addEntry("A filthy torn dress lies on the floor, along with a silver holy symbol on a chain.");
    table.addEntry("An iron cage sits in the room. A skeleton lies half in and half out of it between the bars.");
    table.addEntry("A red rune has been painted in the ceiling of the room. An empty wardrobe sits beneath a white sheet with several weird symbols burned into it.");
    table.addEntry("A drooping potted plant sits in one corner with a single glossy red fruit.");
    table.addEntry("A fishbowl sits on a wooden pedestal with three piranha floating lazily within it.");
    table.addEntry("A ledge near the ceiling is crowded with noisy pigeons.");
    table.addEntry("A mannequin stands in one corner wearing a surcoat made from fresh meat.");
    table.addEntry("A stained oak box, 4' to a side, sits in the center of the room. It is carved with grinning imps and has no visible lid or opening.");
    table.addEntry("A stack of wooden doors, each with a brass knocker shaped like a hand, sits along one wall.");
    table.addEntry("A small canvas tent has been set up in this room. Inside is clothing, food, and other personal effects.");
    table.addEntry("A circular glass plate, like a window, is set into one wall, but nothing but stone is visible beyond it.");
    table.addEntry("The walls, floor, and ceiling of this room are covered in frost. Its freezing in here!");
    table.addEntry("The corners of this room seem to be off. Trying to figure out these unnatural angles is nauseating!");
    table.addEntry("A black hole, 5' across, yawns in the center of the room, with no bottom in sight.");
    table.addEntry("A marble head, as if broken off a statue, lies on the floor here. The room stinks of urine.");
    table.addEntry("A crushed halfling, looking for all the world like a mouse regurgitated by some huge owl, lies on the floor.");
    table.addEntry("Five red, wooden, creepy, horned masks, hang on the wall here.");
    table.addEntry("A barrel of stagnant water sits in a corner. Something moves within it!");
    table.addEntry("A human foot, still wearing a blue velvet slipper, lies on the floor, covered in ants.");
    table.addEntry("A quivering chunk of Gelatinous Cube sits on a ceramic plate on a small wooden table with a knife and fork beside it.");
    table.addEntry("A framed painting of a trio of dancing nymphs in a garden adorns one wall. A dark face is barely visible in the foliage behind them, ripe with evil intent.");
    table.addEntry("A massive granite sphynx lies on its side in this room. A narrow stair descends into the floor where it used to sit.");
    table.addEntry("A ring of pale green toadstools grows in the center of the floor here.");
    table.addEntry("The rough stone figurine of a leering frog-deity lies in an empty, stained tub.");
    table.addEntry("The rank mold growing on one wall gives off scorching heat.");
    table.addEntry("A pool of blood spreads on the floor, fed by a slow dripping from the ceiling above.");
    table.addEntry("A fireplace on one wall has been stuffed with defaced books.");
    table.addEntry("Four lit incense burners swing from chains fixed to the ceiling.");
    table.addEntry("An icy copper bell hangs from a wooden frame on one wall. It is numbing to the touch.");
    table.addEntry("A deep throbbing, like a heartbeat, can be felt in the floor here.");
    table.addEntry("A dome of black glass rises from the center of the room. Viewing it fills you with a sense of dread.");
    table.addEntry("A mage's star-adorned pointy hat has been pinned to the wall with a dagger here.");
    table.addEntry("A maiden lies in an unnatural slumber on a divan here, wearing the gauzy dress of a harem girl.");
    table.addEntry("A pair of ridiculous clown-like shoes sits by the doorway.");
    table.addEntry("A rude collection of hand-drawn orc erotica has been hidden behind a loose stone.");
    table.addEntry("A crystal ball floats at eye-level in the center of the room, giving off intermittent flashes of red and green light.");

    return table.getRollTableEntry();
}

QString RandomChambers::lighting()
{
    RandomTable table;

    table.addEntry("Unlit");
    table.addEntry("Torch, lit");
    table.addEntry("Torch, unlit");
    table.addEntry("Torch holders, empty");
    table.addEntry("Candles, lit");
    table.addEntry("Candles, unlit");
    table.addEntry("Wax blobs, unlit");
    table.addEntry("Oil lantern, lit");
    table.addEntry("Oil lantern, full but unlit");
    table.addEntry("Oil lantern, empty");
    table.addEntry("Floating, glowing glass sphere");
    table.addEntry("Chandelier, lit");
    table.addEntry("Chandelier, unlit");
    table.addEntry("Candelabra, lit");
    table.addEntry("Candelabra, unlit");
    table.addEntry("Errie, glowing mold");
    table.addEntry("Light spell");
    table.addEntry("Magical darkness spell");
    table.addEntry("Brazier, burning coal");
    table.addEntry("Brazier, burning wood");
    table.addEntry("Brazier, smoldering ash");
    table.addEntry("Brazier, coal, unlit");
    table.addEntry("Brazier, wood, unlit");
    table.addEntry("Brazier, empty");
    table.addEntry("Burning fireplace");
    table.addEntry("Fireplace, with wood, unlit");
    table.addEntry("Fireplace, smoldering embers");
    table.addEntry("Fireplace, empty");
    table.addEntry("Burning firepit");
    table.addEntry("Firepit, wood, unlit");
    table.addEntry("Firepit, smoldering embers");
    table.addEntry("Firepit, empty");

    return table.getRollTableEntry();
}
