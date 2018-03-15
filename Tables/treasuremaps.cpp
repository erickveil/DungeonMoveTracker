#include "treasuremaps.h"

treasureMaps::treasureMaps()
{

}

QString treasureMaps::generateMap()
{
    QString forgeryDc = QString::number(Dice::roll(2,4) + 12);
    QString fake = Dice::roll(1,100) < 25
            ? "(fake: investigate DC " + forgeryDc + ")"
            : "";
    QString desc = "Treasure map: " + fake;

    desc += "\nType: " + mapType();
    desc += "\nLanguage: " + language();
    desc += "\nLocation: " + whereIsTreasure();

    desc += "\nMax Sell Value: " + QString::number(Dice::roll(2,20)) + " gp";

    return desc;
}

QString treasureMaps::whereIsTreasure()
{
    RandomTable table;

    RandomTable sameDungeon;
    QString levels = QString::number(Dice::roll(1,3));
    sameDungeon.addEntry("1 level up");
    sameDungeon.addEntry(levels + " levels down");
    sameDungeon.addEntry("same level");
    sameDungeon.addEntry("Secret sub-level");

    table.addEntry("Same dungeon: " + sameDungeon.getRollTableEntry()
                   + genWaypoints("dungeon"));

    levels = QString::number(Dice::roll(1,4));
    QString hex = QString::number(Dice::roll(1,100));
    table.addEntry("Another dungeon: level " + levels + " located at hex "
                   + hex + genWaypoints("hex"));
    table.addEntry("Another dungeon (hidden): level " + levels
                   + " located at hex " + hex + genWaypoints("hex"));

    table.addEntry("Nautical (" + nauticalDetails() + ")" + genWaypoints("nautical"));

    RandomTable megadungeon;
    megadungeon.addEntry("Undermountain");
    megadungeon.addEntry("Stonehell");
    megadungeon.addEntry("House of Stone");

    levels = QString::number(Dice::roll(1,6));
    table.addEntry("Megadungeon: " + megadungeon.getRollTableEntry()
                   + " level: " + levels
                   + "\nProximity: " + proximity() + "\n"
                   + genWaypoints("dungeon"));

    table.addEntry("Ruined city in hex " + hex + genWaypoints("hex"));
    table.addEntry("Vault located at hex " + hex + genWaypoints("hex"));
    QString height = QString::number(Dice::roll(1,100) * 100);
    table.addEntry("In an earthmote, floating " + height + " feet above hex "
                   + hex + genWaypoints("hex"));

    QString neighborhood = QString::number(Dice::roll(1,86));
    table.addEntry("Waterdeep, neighborhood " + neighborhood);

    return table.getRollTableEntry();
}

QString treasureMaps::language()
{
    RandomTable table;

    table.addEntry("Common");
    table.addEntry("Dwarvish");
    table.addEntry("Elvish");
    table.addEntry("Infernal (devil)");
    table.addEntry("Celestial");
    table.addEntry("Draconic");
    table.addEntry("Giant");
    table.addEntry("Gnomish");
    table.addEntry("Goblin");
    table.addEntry("Halfling");
    table.addEntry("Orc");
    table.addEntry("Deep Speech (Illithid, Beholder, etc)");
    table.addEntry("Abyssal (demon)");
    table.addEntry("Primordial (elemental)");
    table.addEntry("Sylvan");
    table.addEntry("Undercommon");
    table.addEntry("Rot13 cipher");
    table.addEntry("Atbash cipher");
    table.addEntry("Polybius Square cipher");
    table.addEntry("Pictures and symbols only (no language requirements)");

    return table.getRollTableEntry();
}

QString treasureMaps::wildernessLandmarks()
{
    RandomTable table;

    table.addEntry("Peculiar standing stone");
    table.addEntry("Statue");
    table.addEntry("Ruin");
    table.addEntry("Natural landmark");
    QString month = QString::number(Dice::roll(1,12));
    table.addEntry("Astrological landmark (only visible during month " + month
                   + " of the year)");
    QString day = QString::number(Dice::roll(1,30));
    table.addEntry("Lunar landmark (only visible during evening " + day
                   + " of the month)");
    QString hour = QString::number(Dice::roll(1,24));
    table.addEntry("Solar landmark (only visible during hour " + hour
                   + " of the day");
    table.addEntry("City, town, or village");
    table.addEntry("Castle/stronghold");
    table.addEntry("Magic effect/trigger");

    RandomTable gate;
    gate.addEntry("another plane");
    gate.addEntry("a foreign wilderness");
    gate.addEntry("a dungeon");
    table.addEntry("Gate to " + gate.getRollTableEntry());

    table.addEntry("Entrance to a dungeon - must pass through and out the "
                   "other side");

    return table.getRollTableEntry();
}

QString treasureMaps::dungeonLandmarks()
{
    RandomTable table;

    table.addEntry("Specific statue");
    table.addEntry("Trap");
    table.addEntry("Sigil etched on wall or hidden in room");
    table.addEntry("Magic mouth/triggered signal");
    table.addEntry("Door matching key");
    RandomTable gate;
    gate.addEntry("another plane");
    gate.addEntry("a foreign wilderness");
    gate.addEntry("another part of the dungeon");
    gate.addEntry("another dungeon");
    gate.addEntry("a local hex");
    table.addEntry("Gate to " + gate.getRollTableEntry());

    QString dungeonFeature = RandomChambers::primaryFeature();
    while (dungeonFeature == "None") {
        dungeonFeature = RandomChambers::primaryFeature();
    }
    table.addEntry(dungeonFeature, 5);

    return table.getRollTableEntry();
}

QString treasureMaps::mapType()
{
    RandomTable table;

    table.addEntry("Normal, written on parchment", 10);
    table.addEntry("Magic compass directs bearer between waypoints");
    table.addEntry("Immovable scale model of area or dungeon");
    table.addEntry("Painted on a wall");
    QString creature = MonsterTable::urbanEncounterXge(1);
    table.addEntry("Tattooed on a creature or npc: " + creature);
    table.addEntry("Inside a spellbook: "
                   + LootTables::generateSpellbook(Dice::roll(1,2)));
    table.addEntry("Inside a journal");
    QString num = QString::number(Dice::roll(2,4));
    table.addEntry("Puzzle: only 1 of " + num + " pieces of the map");
    table.addEntry("Puzzle: requires a special viewing device or decoder "
                   "to be used at one or more of the waypoints.");
    table.addEntry("Dream item: object causes owner to dream visions of next "
                   "waypoint");
    table.addEntry("Crystal ball: shows visions to viewer of next waypoint");
    table.addEntry("Etched into a heavy, 10 lb, stone tablet");
    table.addEntry("Waypoints involve scheduled gates and map provides clues to "
                   "schedule");
    table.addEntry("Carved into the inside bottom of a locked and trapped "
                   "treasure chest filled with sand.");
    table.addEntry("Hot/cold crystal glows brighter the closer it is brought "
                   "to the next waypoint");

    return table.getRollTableEntry();
}

QString treasureMaps::genWaypoints(QString type)
{
    if (type == "city") { return ""; }
    QString wp = "\nWaypoints: ";
    for (int i = 1; i <= Dice::roll(1,4); ++i) {
        if (type == "dungeon") {
            wp += "\n" + QString::number(i) + ". " + dungeonLandmarks();
        }
        else if (type == "hex") {
            wp += "\n" + QString::number(i) + ". " + wildernessLandmarks();
        }
        else {
            wp += "\n" + QString::number(i) + ". " + nauticalWaypoint();
        }
    }

    return wp;
}

QString treasureMaps::nauticalWaypoint()
{
    QString dist = QString::number(Dice::roll(2,6));
    RandomTable direction;
    direction.addEntry("North");

    // Sailing from west coast
    //direction.addEntry("Northeast");
    //direction.addEntry("East");
    //direction.addEntry("Southeast");

    direction.addEntry("South");
    direction.addEntry("Southwest");
    direction.addEntry("West");
    direction.addEntry("Northwest");
    return "Sail " + dist + " hexes " + direction.getRollTableEntry();
}

QString treasureMaps::nauticalDetails()
{
    QString dist = QString::number(Dice::roll(1,4));
    RandomTable	start;
    start.addEntry("Waterdeep");
    start.addEntry("Port " + dist + " hexes north of Waterdeep");
    start.addEntry("Port " + dist + " hexes south of Waterdeep");

    QString desc = "Starting from: " + start.getRollTableEntry() + " and leading to ";
    RandomTable type;
    type.addEntry("sunken treasure");
    type.addEntry("an island, buried");
    type.addEntry("a dungeon on an island");
    desc += type.getRollTableEntry();

    return desc;
}

QString treasureMaps::proximity()
{
    RandomTable table;

    table.addEntry("5", 5);
    table.addEntry("6", 4);
    table.addEntry("7", 3);
    table.addEntry("8", 2);
    table.addEntry("9");
    table.addEntry("10");
    table.addEntry("More than 10");

    return table.getRollTableEntry() + " rooms away from the level entry";
}

QString treasureMaps::hidden()
{
    RandomTable table;

    table.addEntry("Buried: Need picks and shovels");
    table.addEntry("Under Loose Stones: Need pry bars");
    table.addEntry("Behind wall: Need Sledge hammer");
    table.addEntry("Behind locked panel: Need key or lockpick");
    table.addEntry("Sealed door: Need hammer and pry bars");
    table.addEntry("Sealed door with guardian: Need hammer and pry bars");
    table.addEntry("Locked stairwell: Need key or lockpick");
    table.addEntry("Locked stairwell with guardian: Need key or lockpick");

    return table.getRollTableEntry();
}

