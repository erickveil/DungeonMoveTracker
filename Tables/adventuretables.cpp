#include "adventuretables.h"

AdventureTables::AdventureTables()
{

}


QString AdventureTables::adventureHook()
{
    RandomTable table;

    table.addEntry("Town Crier");
    table.addEntry("Billboard");
    table.addEntry("Mysterious stranger approaches party");
    table.addEntry("Messenger boy");
    table.addEntry("Ad in paper");
    table.addEntry("Overheard rumor");
    table.addEntry("Wild eyed person looking for help");
    table.addEntry("Commotion outside");
    table.addEntry("Drafted by nearby guard or authorities");
    table.addEntry("Recruiter for an organization");
    table.addEntry("Nearby cry for help");
    table.addEntry("Wealthy patron recognizes the party as adventurous");
    table.addEntry("Find a hidden note");
    table.addEntry("Someone acting suspicious");
    table.addEntry("Secret code in rot13. Investigation check reveals the code method.");
    table.addEntry("Failed attempt to rob PCs and robber turns out to be desperate and in need of help");
    table.addEntry("One of the PCs professions is needed for a task specific to it");
    table.addEntry("an acquaintance of the party seeks them out for aid");
    table.addEntry("a wealthy noble is searching all the usual spots for an adventuring party to hire");
    table.addEntry("an old kook that nobody believes tells a wild tale of adventure to be had.");
    table.addEntry("a troublesome agent challenges or attacks the party, bearing the adventure hook on his body");
    table.addEntry("A suspicious person is making a drop, not noticing he is being watched, he removes a loose brick and places a small scroll inside and leaves. A little while later, another person arrives and checks the wrong loose brick. Scratching his head and a little irritated, he leaves. The scroll contains the hook or a lead to the hook.");
    table.addEntry("An inscription on an item, wall, or piece of furniture. May start the quest directly, or direct the party to someone who does.");
    table.addEntry("Faction or guild agent looking for adventurers");

    return table.getRollTableEntry();
}

QString AdventureTables::adventureHookMethod()
{
    RandomTable table;

    table.addEntry(" has paid a Town Crier to deliver hook");
    table.addEntry(" has posted hook to Billboard");
    table.addEntry(" approaches party as a mysterious stranger with a hook");
    table.addEntry(" sends a Messenger boy to party with hook");
    table.addEntry(" places an Ad in paper");
    table.addEntry(" is spreading a rumor, overheard by the party");
    table.addEntry(" is a Wild eyed person looking for help");
    table.addEntry(" leads a Press gang");
    table.addEntry(" causes a Commotion outside");
    table.addEntry(" drafts the party as an official capacity for the Watch or authorities.");
    table.addEntry(" is a Recruiter for an organization");
    table.addEntry(" shouts a Nearby cry for help");
    table.addEntry(" recognizes the party as adventurous");
    table.addEntry(" delivers a hidden note");
    table.addEntry(" is acting suspicious");
    table.addEntry(" delivers a Secret code in rot13. Investigation check reveals the code method.");
    table.addEntry(" commits a Failed attempt to rob PCs and robber turns out to be desperate and in need of help");
    table.addEntry(" related to One of the PCs professions is needed for a task specific to it");
    table.addEntry(" is an acquaintance of the party seeks them out for aid");
    table.addEntry(" is searching all the usual spots for an adventuring party to hire");
    table.addEntry(" acts as an old kook that nobody believes tells a wild tale of adventure to be had.");
    table.addEntry(" challenges or attacks the party, bearing the adventure hook on his body");
    table.addEntry(" is a suspicious person is making a drop, not noticing he is being watched, he removes a loose brick and places a small scroll inside and leaves. A little while later, another person arrives and checks the wrong loose brick. Scratching his head and a little irritated, he leaves. The scroll contains the hook or a lead to the hook.");
    table.addEntry(" is a Faction or guild agent looking for adventurers");

    return table.getRollTableEntry();


}

QString AdventureTables::hookSource()
{
    RandomTable table;

    table.addEntry("Retired adventurer");
    table.addEntry("Local ruler");
    table.addEntry("Military officer");
    table.addEntry("Temple official");
    table.addEntry("Sage");
    table.addEntry("Respected elder");
    table.addEntry("Deity or celestial");
    table.addEntry("Mysterious fey");
    table.addEntry("Old friend");
    table.addEntry("Former teacher");
    table.addEntry("Parent or other family member");
    table.addEntry("Desperate commoner");
    table.addEntry("Embattled merchant");
    table.addEntry("Villain posing as a patron");
    table.addEntry("Friendly NPC adventurer");
    table.addEntry("An employer of mercenaries");
    table.addEntry("A local wizard");

    return table.getRollTableEntry();
}

QString AdventureTables::hookMission()
{
    RandomTable table;

    // dungeon goals
    table.addEntry("Stop the dungeon's inhabitants from raiding the "
                   "surface world.");
    table.addEntry("Foil a villain's evil scheme.");
    table.addEntry("Destroy a magical threat inside a dungeon.");
    table.addEntry("Acquire treasure.");
    table.addEntry("Find a particular item for a specific purpose.");
    table.addEntry("Retrieve a stolen item hidden in the dungeon.");
    table.addEntry("Find information needed for a special purpose.");
    table.addEntry("Rescue a captive.");
    table.addEntry("Discover the fate of a previous adventuring party.");
    table.addEntry("Find an NPC who disappeared in the area.");
    table.addEntry("Slay a dragon or other challenging monster.");
    table.addEntry("Discover the nature and origin of a strange location "
                   "or phenomenon.");
    table.addEntry("Pursue fleeing foes taking refuge in the dungeon.");
    table.addEntry("Escape from captivity in the dungeon");
    table.addEntry("Clear a ruin so it can be rebuilt and reoccupied.");
    table.addEntry("Discover why a villain is interested in a dungeon.");
    table.addEntry("Parley with a villain in the dungeon.");

    // wilderness goals
    table.addEntry("Locate a dungeon or other site of interest");
    table.addEntry("Assess the scope of a natual or unatural disaster");
    table.addEntry("Escort an NPC to a destination");
    table.addEntry("Arrive at a destination without being seen by the "
                   "villain's forces");
    table.addEntry("Stop monsters from raiding caravans and farms.");
    table.addEntry("Establish trade with a distant town.");
    table.addEntry("Protect a caravan traveling to a distant town.");
    table.addEntry("Map a new land.");
    table.addEntry("Find a place to establish a colony.");
    table.addEntry("Find a natural resource.");
    table.addEntry("Hunt a specific monster.");
    table.addEntry("Obtain information from a reclusive hermit.");
    table.addEntry("Find an object that was lost in the wilds");
    table.addEntry("Discover the fate of a missing group of wilderness "
                   "explorers");
    table.addEntry("Pursue fleeing foes over land");
    table.addEntry("Assess the size of an approaching army.");
    table.addEntry("Protect a wilderness site from attackers.");

    // other goals
    table.addEntry("Sieze control of a fortified location such as a "
                   "fortress, town, or ship");
    table.addEntry("Defend a location from attackers");
    table.addEntry("Retrieve an object from inside a secure location in "
                   "a settlement");
    table.addEntry("Retrieve an object from a caravan");
    table.addEntry("Salvage an object or goods from a lost vessel or caravan");
    table.addEntry("Break a prisoner out of a jail or prison camp");
    table.addEntry("Escape from a jail or prison camp");
    table.addEntry("Infiltrate a fortified location");
    table.addEntry("Find the source of strange occurrences in a haunted "
                   "house or other location.");
    table.addEntry("Interfere with the operation of a business");
    table.addEntry("Rescue a character, monster, or object from a "
                   "natural or unnatural disaster.");

    // event based goals
    table.addEntry("Bring a villain to justice");
    table.addEntry("Clear the name of an innocent NPC");
    table.addEntry("Protect or hide an NPC");
    table.addEntry("Protect an object");
    table.addEntry("Discover the nature and origin of a strange "
                   "phenomenon that might be the villain's doing");
    table.addEntry("Find a wanted fugitive");
    table.addEntry("Overthrow a tyrant");
    table.addEntry("Uncover a conspiracy to overthrow a ruler");
    table.addEntry("Negotiate peace between enemy nations or feuding "
                   "families");
    table.addEntry("Secure aid from a ruler or council");
    table.addEntry("Help a villain find redemption");
    table.addEntry("Parley with a villain");
    table.addEntry("Smuggle weapons to rebel forces");
    table.addEntry("Stop a band of smugglers");
    table.addEntry("Gather intellegence on an enemy force");
    table.addEntry("Determine the villain's identity");
    table.addEntry("Locate a stolen item");
    table.addEntry("Make sure a wedding goes off without a hitch");

    return table.getRollTableEntry();
}

QString AdventureTables::hookVillains()
{
    RandomTable table;

    // todo: moar detail
    table.addEntry("Beast or monstrosity with no particular agenda");
    table.addEntry("Aberration bent on corruption or domination");
    table.addEntry("Fiend bent on corruption or destrucion");
    table.addEntry("Dragon bent on domination and plunder");
    table.addEntry("Giant bent on plunder");
    table.addEntry("Undead with any agenda");
    table.addEntry("Fey with a mysterious goal");
    table.addEntry("Humanoid cultist");
    table.addEntry("Humanoid seeking revenge");
    table.addEntry("Humanoid schemer seeking to rule");
    table.addEntry("Humanoid criminal mastermind");
    table.addEntry("Humanoid raider or ravager");
    table.addEntry("Humanoid under a curse");
    table.addEntry("Misguided humanoid zealot");

    return table.getRollTableEntry();
}

QString AdventureTables::villainScheme()
{
    RandomTable table;

    table.addEntry("Acquire a legendary item to prolong life");
    table.addEntry("Ascend to godhood");
    table.addEntry("Become undead or obtain a younger body");
    table.addEntry("Steal a planar creature's essence to gain immortality");
    table.addEntry("Seize a postion of power or title");
    table.addEntry("Win a contest or tournament");
    table.addEntry("Place a pawn in a position of power");
    table.addEntry("Obtain an ancient artifact");
    table.addEntry("Build a construct or magical device");
    table.addEntry("Carry out a deity's wishes");
    table.addEntry("Offer sacrifices to a deity");
    table.addEntry("Contact a lost deity or power");
    table.addEntry("Open a gate to another world");
    table.addEntry("Fulfill an apocalyptic prophecy");
    table.addEntry("Enact the vengeful will of a god or patron");
    table.addEntry("Spread a vile contagion");
    table.addEntry("Overthrow a government");
    table.addEntry("Trigger a natural disaster");
    table.addEntry("Utterly destroy a bloodline or clan");
    table.addEntry("Prolong the life of a loved one");
    table.addEntry("Prove worthy of another person's love");
    table.addEntry("Raise or restore a dead loved one");
    table.addEntry("Destroy rivals for another person's affection");
    table.addEntry("Conquer a region or incite a rebellion");
    table.addEntry("Seize control of an army");
    table.addEntry("Become the power behind the throne");
    table.addEntry("Gain the favor of a ruler");
    table.addEntry("Avenge a past humiliation or insult");
    table.addEntry("Avenge a past imprisonment or injury");
    table.addEntry("Avenge the death of a loved one");
    table.addEntry("Retrieve stolen property and punish the thief");
    table.addEntry("Control natural resources or trade");
    table.addEntry("Marry into wealth");
    table.addEntry("Plunder ancient ruins");
    table.addEntry("Steal land, goods, or money");

    return table.getRollTableEntry();
}

QString AdventureTables::villainMethods()
{
    RandomTable table;

    table.addEntry("Agricultural blight");
    table.addEntry("Crop failure");
    table.addEntry("Drought");
    table.addEntry("Famine");
    table.addEntry("Assault or beatings");
    table.addEntry("Bounty hunting or assassination");
    table.addEntry("Bribery");
    table.addEntry("Enticement");
    table.addEntry("Eviction");
    table.addEntry("Imprisonment");
    table.addEntry("Kidnapping");
    table.addEntry("Legal intimidation");
    table.addEntry("Press gangs");
    table.addEntry("Shackling");
    table.addEntry("Slavery");
    table.addEntry("Threats or harassment");
    table.addEntry("Breach of contract");
    table.addEntry("Cheating");
    table.addEntry("Fast talking");
    table.addEntry("Fine print");
    table.addEntry("Fraud or swindling");
    table.addEntry("Quackery or tricks");
    table.addEntry("Framing");
    table.addEntry("Gossiping or slander");
    table.addEntry("Humiliation");
    table.addEntry("Libel or insults");
    table.addEntry("Dueling");
    table.addEntry("Beheading");
    table.addEntry("Burning at the stake");
    table.addEntry("Burying alive");
    table.addEntry("Crucifixion");
    table.addEntry("Drawing and quartering");
    table.addEntry("Hanging");
    table.addEntry("Impalement");
    table.addEntry("Living Sacrifice");
    table.addEntry("Impersonation or disguise");
    table.addEntry("Lying or purjury");
    table.addEntry("Hauntings");
    table.addEntry("Illusions");
    table.addEntry("Infernal bargains");
    table.addEntry("Mind control");
    table.addEntry("Petrificaiton");
    table.addEntry("Raising or animating the dead");
    table.addEntry("Summoning monsters");
    table.addEntry("Weather control");
    table.addEntry("Assassination");
    table.addEntry("Cannibalism");
    table.addEntry("Dismemberment");
    table.addEntry("Drowning");
    table.addEntry("Electrocution");
    table.addEntry("Disease");
    table.addEntry("Poisoning");
    table.addEntry("Stabbing");
    table.addEntry("Strangulation or suffocation");
    table.addEntry("Neglect");
    table.addEntry("Political Betrayal or treason");
    table.addEntry("Conspiracy");
    table.addEntry("Espionage or spying");
    table.addEntry("Genocide");
    table.addEntry("Opression");
    table.addEntry("Raising taxes");
    table.addEntry("Curses");
    table.addEntry("Desecration");
    table.addEntry("False gods");
    table.addEntry("Heresy or cults");
    table.addEntry("Stalking");
    table.addEntry("Arson");
    table.addEntry("Blackmail or extortion");
    table.addEntry("Burglury");
    table.addEntry("Counterfeiting");
    table.addEntry("Highway robbery");
    table.addEntry("Looting");
    table.addEntry("Mugging");
    table.addEntry("Poaching");
    table.addEntry("Seizing property");
    table.addEntry("Smuggling");
    table.addEntry("Acid torture");
    table.addEntry("Blinding");
    table.addEntry("Branding");
    table.addEntry("Torture: racking");
    table.addEntry("Thumbscrew torture");
    table.addEntry("Whipping");
    table.addEntry("Adultry");
    table.addEntry("Drugs or alcohol");
    table.addEntry("Gambling");
    table.addEntry("Seduction");
    table.addEntry("Ambush");
    table.addEntry("Invasion");
    table.addEntry("Massacre");
    table.addEntry("Mercinaries");
    table.addEntry("Rebellion");
    table.addEntry("Terrorism");

    return table.getRollTableEntry();
}

QString AdventureTables::fullAdventureGen()
{
    QString desc;

    desc  = "PATRON: " + hookSource() + "\n";
    desc += "PATRON FACTION: " + patronFaction() + "\n";
    desc += "DELIVERY: " + adventureHook() + "\n";
    desc += "MISSION: " + hookMission() + "\n";
    desc += "LOCATION: " + DungeonTables::dungeonLocation() + "\n";
    desc += "VILLAIN: " + hookVillains() + "\n";
    desc += "SCHEME: " + villainScheme() + "\n";
    desc += "METHODS: " + villainMethods() + "\n";

    return desc;
}

QString AdventureTables::dungeonGoals()
{
    RandomTable table;

    table.addEntry("Stop the dungeon's monsterous inhabitants from "
                   "raiding the surface world.");
    // Todo: random villain
    table.addEntry("Foil a villain's evil scheme.");
    table.addEntry("Destroy a magical threat inside the dungeon");
    table.addEntry("Acquire treasure");
    table.addEntry("Find a particular item for a specific purpose");
    table.addEntry("Retreive a stolen item hidden in the dungeon");
    table.addEntry("Find information needed for a special purpose");
    table.addEntry("Rescure a captive");
    table.addEntry("Discover the fate of a previous adventuring party");
    table.addEntry("Find an NPC who disappeared in the area");
    table.addEntry("Slay a dragon or some other challenging monster");
    table.addEntry("Discover the nature and origin of a strange location "
                   "or phenomenon");
    table.addEntry("Pursue fleeing foes taking refuge in the dungeon");
    table.addEntry("Escape from captivity in the dungeon");
    table.addEntry("Clear a ruin so it can be rebuilt and reoccupied");
    // Todo: villain
    table.addEntry("Discover why a villain is interested in the dungeon");
    table.addEntry("Win a bet or complete a rite of passage by surviving in "
                   "the dungeon for a certain amount of time");
    // Todo: villain
    table.addEntry("Parley with a villain in the dungeon");
    table.addEntry("Hide from a threat outside the dungeon");
    //table.addEntry(dungeonGoals() + " and " + dungeonGoals());

    return table.getRollTableEntry();
}


QString AdventureTables::generateRandomAdventure(int tier, QString type)
{
    QString desc;
    //desc = "HOOK: " + adventureHook() + "\n";
    //desc += "GOAL: " + dungeonGoals() + "\n";
    //QString type = dungeonType();
    // todo adventure goals tables
    desc += "DUNGEON TYPE: " + type + "\n";
    desc += "LOCATION: " + DungeonTables::dungeonLocation() + "\n";
    desc += "CREATOR: " + DungeonTables::dungeonCreator() + "\n";
    desc += "HISTORY: " + DungeonTables::dungeonHistory() + "\n";
    desc += "CURRENT CONTROLLERS: " + MonsterTable::dungeonMonster(tier) + "\n";
    int layout = Dice::roll(1,10);
    desc += "LAYOUT #: " + QString::number(layout) + "\n";
    desc += "\n";
    int numRooms = (layout <= 3) ? 4 : 5;
    int entranceRoom = Dice::roll(1, numRooms);
    int goalRoom = Dice::roll(1, numRooms);

    // generate rooms
    for (int roomNumber = 1; roomNumber <= numRooms; ++roomNumber) {
        QString enter = (roomNumber == entranceRoom) ? " (ENTRANCE) " : "";
        QString goal = (goalRoom == roomNumber) ? " (GOAL) " : "";
        desc += "ROOM " + QString::number(roomNumber) + enter + goal + ":\n";

        if (type == "General") {
            desc += RandomChambers::generateGeneralRoom(tier);
        }
        else if (type == "Death Trap") {
            desc += RandomChambers::generateDeathTrapRoom(tier);
        }
        else if (type == "Lair") {
            desc += RandomChambers::generateLairRoom(tier);
        }
        else if (type == "Maze") {
            desc += RandomChambers::generateMazeRoomType(tier);
        }
        else if (type == "Planar Gate") {
            desc += RandomChambers::generatePlanarGateRoom(tier);
        }
        else if (type == "Stronghold") {
            desc += RandomChambers::generateStrongholdRoom(tier);
        }
        else if (type == "Temple") {
            desc += RandomChambers::generateTempleRoom(tier);
        }
        else if (type == "Tomb") {
            desc += RandomChambers::generateToomb(tier);
        }
        else if (type == "Treasure Vault") {
            desc += RandomChambers::generateTreasureVault(tier);
        }
        else if (type == "Mine") {
            desc += RandomChambers::generateMineRoom(tier);
        }
        else if (type == "Library") {
            desc += RandomChambers::generateLibraryRoom(tier);
        }
        else if (type == "Caverns") {
            desc += RandomChambers::generateCavernRoom(tier);
        }
        else {
            desc = "Unknown dungeon type: " + type;
        }

        desc += "\n";
    }

    // generate halls
    for (int hall=0; hall < 7; ++hall) {
        char hallId = hall + 97;
        RandomTable hallType;
        hallType.addEntry("Archway access", 4);
        hallType.addEntry("Archway access with stairs up one level", 3);
        hallType.addEntry("Archway access with stairs down one level", 3);
        hallType.addEntry("Archway access with short stairs down", 3);
        hallType.addEntry("Archway access with short stairs up", 3);
        hallType.addEntry("Door access", 5);
        hallType.addEntry("Door access with stairs up one level", 3);
        hallType.addEntry("Door access with stairs down one level", 3);
        hallType.addEntry("Door access with short stairs down", 3);
        hallType.addEntry("Door access with short stairs up", 3);
        hallType.addEntry("Ladder up", 2);
        hallType.addEntry("Ladder down", 2);
        hallType.addEntry("Hatch, floor");
        hallType.addEntry("Hatch, ceiling");
        hallType.addEntry("Open shute/pit, down");
        hallType.addEntry("Open shute/pit, up");
        hallType.addEntry("Trap door connecting rooms, floor");

        desc += "HALL " + QString(hallId) + " " +hallType.getRollTableEntry() +":\n";


        desc += RandomChambers::generateHallwayContents(tier) + "\n\n";
    }

    return desc;

}

QString AdventureTables::patronFaction()
{
    RandomTable table;

    table.addEntry("The Watch", 2);
    table.addEntry("The Guard", 2);
    table.addEntry("The Gray Hand");
    table.addEntry("The Blackstaff", 2);
    table.addEntry("Agent of Laerel Silverhand", 2);
    table.addEntry("Agent of the Masked Lords", 2);
    table.addEntry("Humanist Conspirator");
    table.addEntry("A Waterdhavian Noble", 2);
    table.addEntry("Waterdeep Guild: " + guild(), 2);
    table.addEntry("The Knights of the Shield");
    table.addEntry("Represenative of the Common House");
    table.addEntry("The Harpers", 3);
    table.addEntry("The Order of the Gauntlet", 3);
    table.addEntry("The Emerald Enclave", 3);
    table.addEntry("The Lords' Alliance", 3);
    table.addEntry("The Zhentarim", 3);
    table.addEntry("The Moonstars");
    table.addEntry("The Red Sashes");
    table.addEntry("The Cult of Scionel");
    table.addEntry("The Red Wizards");
    table.addEntry("The Eye");
    table.addEntry("The Plague Rats");
    table.addEntry("Uthgardt Barbarian, Elk Tribe");
    table.addEntry("Uthgardt Barbarian, Gray Wolf Tribe");
    table.addEntry("Independent citizen", 3);
    table.addEntry("Magistrate");

    RandomTable ambassador;
    ambassador.addEntry("Neverwinter");
    ambassador.addEntry("Baldurs Gate");
    ambassador.addEntry("Luskan");
    table.addEntry("Foreign ambassador of " + ambassador.getRollTableEntry());

    return table.getRollTableEntry();
}

QString AdventureTables::guild()
{
    RandomTable table;

    table.addEntry("Bakers Guild");
    table.addEntry("Carpenters Roofers and Plasterers Guild");
    table.addEntry("Cellarers and Plumbers Guild", 5);
    table.addEntry("Coopers Guild");
    table.addEntry("Council of Farmers-Grocers");
    table.addEntry("Council of Musicians, Instrument-Makers, and Choristers");
    table.addEntry("Dungsweepers Guild");
    table.addEntry("Fellowship of Bowyers and Fletchers");
    table.addEntry("Carters and coachmen");
    table.addEntry("Fellowship of Innkeepers");
    table.addEntry("Fellowship of Salters, Packers, and Joiners");
    table.addEntry("Fishmongers Fellowship");
    table.addEntry("Guild of Apothecaries and Physicians", 5);
    table.addEntry("Guild of Butchers");
    table.addEntry("Guild of Chandlers and Lamplighters");
    table.addEntry("Guild of fine Carvers");
    table.addEntry("Guild of Glassblowers, Glaziers, and Speculum Makers");
    table.addEntry("Guild of Stonecutters, Masons, Potters, and Tilemakers");
    table.addEntry("Guild of Trusted Pewters and casters");
    table.addEntry("Guild of Watermen");
    table.addEntry("Jewlers Guild", 5);
    table.addEntry("Launderers Guild");
    table.addEntry("League of Basketmakers and Wickerworkers");
    table.addEntry("League of Skinners and Tanners");
    table.addEntry("Master Mariners Guild", 5);
    table.addEntry("Most Careful Order of Skilled Smiths and Metalforgers");
    table.addEntry("Most Diligent League of Sail-Makers and Cordwainers");
    table.addEntry("Most Excellent Order of Weavers and Dyers");
    table.addEntry("Order of Cobblers and Corvisers");
    table.addEntry("Order of Master Shipwrights");
    table.addEntry("Order of Master Teylors, Glovers, and Mercers");
    table.addEntry("Saddlers and Harness-Makers Guild");
    table.addEntry("Scriveners, Scribes, and Clerks Guild", 5);
    table.addEntry("Solemn Order of Recognized Furriers and Woolmen");
    table.addEntry("Splendid Order of Armorers, Locksmiths, and Finesmiths");
    table.addEntry("Stablemasters and Farriers Guild");
    table.addEntry("Stationers Guild");
    table.addEntry("Surveyors, Map, and Chartmakers Guild", 5);
    table.addEntry("Vinters, Distillers, and Brewers Guild");
    table.addEntry("Wagonmakers and Coach Builders Guild");
    table.addEntry("Watchful Order of Magists and Protectors", 5);
    table.addEntry("Wheelwrights Guild");

    return table.getRollTableEntry();
}
