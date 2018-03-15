#include "dungeontables.h"

DungeonTables::DungeonTables()
{

}


QString DungeonTables::dungeonType()
{
    RandomTable table;

    table.addEntry("General Dungeon");
    table.addEntry("Death Trap Dungeon");
    table.addEntry("Lair");
    table.addEntry("Maze");
    table.addEntry("Mine");
    table.addEntry("Planar Gate");
    table.addEntry("Stronghold");
    table.addEntry("Temple");
    table.addEntry("Tomb");
    table.addEntry("Treasure Vault");

    return table.getRollTableEntry();
}

QString DungeonTables::dungeonLocation()
{
    RandomTable table;

    table.addEntry("A building in a city", 5);
    table.addEntry("Catacombs or sewers beneath a city", 4);
    table.addEntry("Beneath a farmhouse", 4);
    table.addEntry("Beneath a graveyard", 4);
    table.addEntry("Beneath a ruined castle", 6);
    table.addEntry("Beneath a ruined city", 4);
    table.addEntry("Beneath a temple", 4);
    table.addEntry("In a chasm", 4);
    table.addEntry("In a cliff face", 4);
    table.addEntry("In a desert", 4);
    table.addEntry("In a forest", 4);
    table.addEntry("In a glacier", 3);
    table.addEntry("In a gorge", 3);
    table.addEntry("In a jungle", 4);
    table.addEntry("In a mountain pass", 4);
    table.addEntry("In a swamp", 4);
    table.addEntry("Beneath or ont top of a mesa", 4);
    table.addEntry("In sea caves", 3);
    table.addEntry("In several connected mesas", 4);
    table.addEntry("On a mountain peak", 4);
    table.addEntry("On a promontary", 4);
    table.addEntry("On an island", 4);
    table.addEntry("Underwater", 4);

    RandomTable exoticLocation;
    exoticLocation.addEntry("Among the branches of a tree");
    exoticLocation.addEntry("Around a geyser");
    exoticLocation.addEntry("Behind a waterfall");
    exoticLocation.addEntry("Burried in an avalanche");
    exoticLocation.addEntry("Burried in a sandstorm");
    exoticLocation.addEntry("Burried in volcanic ash");
    exoticLocation.addEntry("Castle or structure sunken in a swamp");
    exoticLocation.addEntry("Castle or structure at the bottom of a sinkhole");
    exoticLocation.addEntry("Floating on the sea");
    exoticLocation.addEntry("In a meteorite");
    exoticLocation.addEntry("On a demiplane or in a pocket dimension");
    exoticLocation.addEntry("In an area devestated by a magical catastrophe");
    exoticLocation.addEntry("On a cloud");
    exoticLocation.addEntry("In the Feywild");
    exoticLocation.addEntry("In the Shadowfell");
    exoticLocation.addEntry("On an island in an underground sea");
    exoticLocation.addEntry("In a volcano");
    exoticLocation.addEntry("On the back of a gargantuan living creature");
    exoticLocation.addEntry("Sealed inside a magical dome of force");
    exoticLocation.addEntry("Inside a Mordenkaienen's magnificent mansion");
    exoticLocation.addEntry("On an earth mote");
    exoticLocation.addEntry("In a tiny, shrunken world");
    exoticLocation.addEntry("Inside someone's body (requires shrinking)");

    table.addEntry(exoticLocation.getRollTableEntry(), 5);


    return table.getRollTableEntry();
}

QString DungeonTables::dungeonCreator()
{

    RandomTable table;

    table.addEntry("Beholder");

    RandomTable cult;
    cult.addEntry("Demon worshippers");
    cult.addEntry("Devil worshippers");
    cult.addEntry("Elemental Air cult", 2);
    cult.addEntry("Elemental Eargh cult", 2);
    cult.addEntry("Elemental Fire cult", 2);
    cult.addEntry("Elemental Water cult", 2);
    cult.addEntry("Worshippers of an evil deity", 5);
    cult.addEntry("Worshippers of a good deity", 2);
    cult.addEntry("Worshippers of a neutral deity", 3);

    table.addEntry("Cult or religious group: " + cult.getRollTableEntry(), 3);
    table.addEntry("Dwarves", 4);
    table.addEntry("Elves/drow");
    table.addEntry("Giants");
    table.addEntry("Hobgoblins");

    RandomTable npcClass;
    npcClass.addEntry("Barbarian");
    npcClass.addEntry("Bard");
    npcClass.addEntry("Cleric");
    npcClass.addEntry("Druid");
    npcClass.addEntry("Fighter");
    npcClass.addEntry("Monk");
    npcClass.addEntry("Paladin");
    npcClass.addEntry("Ranger");
    npcClass.addEntry("Rogue");
    npcClass.addEntry("Sorcerer");
    npcClass.addEntry("Warlock");
    npcClass.addEntry("Wizard");

    table.addEntry("Humans: " + NpcTables::determineAlignment() + ", "
                   + npcClass.getRollTableEntry(), 4);
    table.addEntry("Kuo-toa");
    table.addEntry("Lich");
    table.addEntry("Mind flayers");
    table.addEntry("Yuan-ti");
    table.addEntry("Natural caverns (no creator)");

    return table.getRollTableEntry();
}

QString DungeonTables::dungeonHistory()
{
    RandomTable table;

    table.addEntry("Abandoned by creators", 3);
    table.addEntry("Abandoned due to plague", 1);
    table.addEntry("Conquered by invaders", 4);
    table.addEntry("Creators destroyed by attacking raiders", 2);
    table.addEntry("Creators destroyed by discovery made within the site", 1);
    table.addEntry("Creators destroyed by internal conflict", 1);
    table.addEntry("Creators destroyed by magical catastorphe");
    table.addEntry("Creators destroyed by natural disaster", 2);
    table.addEntry("Location cursed by the gods and shunned");
    table.addEntry("Original creator still in control", 2);
    table.addEntry("Overrun by planar creatures");
    table.addEntry("Site of a great miracle");

    return table.getRollTableEntry();
}
