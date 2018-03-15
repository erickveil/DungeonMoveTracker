#include "hexcrawltables.h"

HexcrawlTables::HexcrawlTables()
{

}

QString HexcrawlTables::keyHex(int tier)
{
    int trackMod = 11 - Dice::roll(1, 21);
    int lairMod = 11 - Dice::roll(1, 21);
    int trackChance = 50 + trackMod;
    int lairChance = 21 + lairMod;
    QString key = "Main Feature:\n";
    key += mainFeature(tier) + "\n\n";
    key += "Wandering Encounter:\n";
    key += wanderingEncounter(tier) + "\n";
    key += "Chance of Tracks: " + QString::number(trackChance) + "%\n";
    key += "Tracks type: " + tracks() + "\n";
    key += "Chance of Lair: " + QString::number(lairChance) + "%\n\n";
    key += "Resource:\n";
    key += mineralResource() + "\n";
    return key;
}

QString HexcrawlTables::keyNauticalHex(int tier)
{
    QString key = "Main Feature:\n";
    key += mainNauticalFeature(tier) + "\n\n";
    key += "Wandering Encounter:\n";
    key += wanderingNauticalEncounter(tier) + "\n";
    return key;
}

QString HexcrawlTables::mainFeature(int tier)
{
    RandomTable table;

    table.addEntry("Lair: " + lair(tier), 4);
    table.addEntry("Remote Structure: " + remoteStructure(tier), 34-5);
    table.addEntry("Ruined Structure: " + ruinedStructure(tier), 71-34);
    table.addEntry("Natural Structure: " + naturalStructure(tier), 98-71);
    table.addEntry("Remarkable Event or Feature: " + remarkableEvent(tier),
                   100-98);

    return table.getRollTableEntry();
}

QString HexcrawlTables::mainNauticalFeature(int tier)
{
    RandomTable table;

    table.addEntry("Area of magnetic disruption. Affects compases: Navigate "
                   "at disadvantage in this area.");

    RandomTable graveyard;
    graveyard.addEntry("Uninhabited");
    graveyard.addEntry("Haunted by ghosts");
    graveyard.addEntry("Haunted by skeletons");
    graveyard.addEntry("Occupied by pirate scavengers");
    graveyard.addEntry("Haunted by ghosts, with treasure horde: "
                       + LootTables::generateTreasureHorde(tier));
    graveyard.addEntry("Haunted by skeletons, with treasure horde: "
                       + LootTables::generateTreasureHorde(tier));
    graveyard.addEntry("Occupied by pirate scavengers looking for treasure "
                       "horde: " + LootTables::generateTreasureHorde(tier));
    graveyard.addEntry("Uninhabited with treasure horde: "
                       + LootTables::generateTreasureHorde(tier));
    table.addEntry("Shipwreck graveyard: " + graveyard.getRollTableEntry());

    table.addEntry("Undersea city - ruins");
    table.addEntry("Undersea city/lair - sahuagin");
    table.addEntry("Undersea city - merfolk");
    table.addEntry("Undersea city - merfolk");
    table.addEntry("Undersea caves - submerged");
    table.addEntry("Undersea caves - air filled");
    table.addEntry("Undersea ruins - submerged");
    table.addEntry("Undersea ruins - air filled");
    table.addEntry("Undersea dungeon - air filled");
    table.addEntry("Undersea dungeon - submerged");

    table.addEntry("Coral threatens hull");
    table.addEntry("Claimed waters: naval vessels attack on sight");
    table.addEntry("Claimed waters: naval vessels warn party to stay out or "
                   "go around");
    QString dc = QString::number(tier + 14);
    table.addEntry("Large iceberg: Navigate DC " + dc + " or damage hull");

    RandomTable malestrom;
    malestrom.addEntry("Ship is destroyed and joins a shipwreck graveyard at "
                       "the bottom of the sea ("
                       + graveyard.getRollTableEntry() + ")");
    malestrom.addEntry("Ship is safely gated to the Plane of Water in a bubble.");
    malestrom.addEntry("Ship is deposited into an underdark sea cavern, "
                       "sustaining moderate damage.");
    QString hex = QString::number(Dice::roll(1,100));
    malestrom.addEntry("Ship is gated to another sea hex: " + hex);
    malestrom.addEntry("Ship escapes, but is now automatically lost.");

    table.addEntry("Malestrom: Navigate DC " + dc + " or get caught: "
                   + malestrom.getRollTableEntry());

    table.addEntry("Region is permanently encased in a thick fog. Navigate at "
                   "disadvantage.");
    table.addEntry("Region is permanently windless. Must use oars to move or "
                   "be trapped.");
    table.addEntry("Sunken treasure deep below the waves: "
                   + LootTables::generateTreasureHorde(tier));

    RandomTable biome;
    biome.addEntry("Desert - all sand and no life");
    biome.addEntry("Jungle");
    biome.addEntry("Forest");
    biome.addEntry("Hilly grass");
    biome.addEntry("Swamp");

    RandomTable islandType;
    islandType.addEntry("Normal", 7);
    QString height = QString::number(Dice::roll(1,100) * 100);
    islandType.addEntry("Earth mote floating " + height + " feet in the air");
    islandType.addEntry("Back of large, sleeping creature");
    islandType.addEntry("Floating/moving island");
    islandType.addEntry("Completely artificial structure");
    islandType.addEntry("Volcano");
    islandType.addEntry("Hidden or hard to find");
    islandType.addEntry("Situated in the calm eye of a perpetual, volent storm");

    QString islandGuards = " Guarded by: " + nauticalGuard();

    RandomTable inhabitants;
    inhabitants.addEntry("Uninhabited");
    inhabitants.addEntry("Animal life only");
    inhabitants.addEntry("Monsters");
    inhabitants.addEntry("Primitive tribe");
    inhabitants.addEntry("Pirate hideout" + islandGuards);
    inhabitants.addEntry("Pirate traders' cove" + islandGuards);
    inhabitants.addEntry("Cultured civilization" + islandGuards);
    inhabitants.addEntry("Alien/unusual civilization" + islandGuards);
    inhabitants.addEntry("Boss monster hideout with minions");
    inhabitants.addEntry("Castaways");
    inhabitants.addEntry("Penal colony");
    inhabitants.addEntry("Morkoth Island Lair (vgm)");

    RandomTable contents;
    contents.addEntry("Nothing out of the ordinary");
    contents.addEntry("Ruins");
    contents.addEntry("Caves");
    contents.addEntry("Village");
    contents.addEntry("Town");
    contents.addEntry("Abandoned camp");
    contents.addEntry("Normal camp");
    contents.addEntry("Castle or stronhold");
    contents.addEntry("Lighthouse");
    contents.addEntry("Wizard Tower");
    contents.addEntry("Lair");
    contents.addEntry("Shipwreck");
    contents.addEntry("Buried treasure: "
                      + LootTables::generateTreasureHorde(tier));

    RandomTable size;
    size.addEntry("Small (< 1 mile)");
    size.addEntry("Medium (1-3 mile)");
    size.addEntry("Large (3-10 mile)");

    table.addEntry("Island:\nBiome: " + biome.getRollTableEntry()
                   + "\nSize: " + size.getRollTableEntry()
                   + "\nType: " + islandType.getRollTableEntry()
                   + "\nInhabitants: " + inhabitants.getRollTableEntry()
                   + "\nContents: " + contents.getRollTableEntry(), 8);

    QString treasure = (Dice::roll(1,100) < 50)
            ? " with treasure:\n" + LootTables::generateTreasureHorde(tier)
            : "";
    table.addEntry("Sunken galleon" + treasure);
    table.addEntry("An underwater, empty castle made from coral");
    table.addEntry("An underwater statue of a squatting humanoid, with bat "
                   "wings on its back and tentacles sprouting from its "
                   "face");
    table.addEntry("A 1 mile radius sphere of effervescent water that allows "
                   "air breathing creatures to breathe water while within the "
                   "sphere");
    table.addEntry("An underwater, shimmering, blue-green portal to the "
                   "Elemental plane of Water");
    table.addEntry("Undersea aboleth lair");
    table.addEntry("Undersea kraken lair");

    return table.getRollTableEntry();

}

QString HexcrawlTables::wanderingEncounter(int tier)
{
    RandomTable table;

    table.addEntry("NPC: " + npcEncounter(tier), 2);
    table.addEntry("Animal Herd: " + animalHerd(), 2);
    // TODO: Biome monster tables
    table.addEntry("Wandering Monster", 5);
    table.addEntry("Past event: " + pastEvent(tier));
    table.addEntry("Current event: " + currentEvent(tier));
    table.addEntry("Lost item: " + lostItem(tier));
    table.addEntry("Remarkable event or feature: " + remarkableEvent(tier));

    return table.getRollTableEntry();
}

QString HexcrawlTables::wanderingNauticalEncounter(int tier)
{
    RandomTable table;

    table.addEntry("Monster attack: " + MonsterTable::nauticalEncounter(tier));
    table.addEntry("Pirates: Run up the flag and let you pass after you "
                   "jettison your cargo");
    table.addEntry("Marauders: Ram your ship and grapple the sides, board and "
                   "murder your crew, loot the wreckage, then shove off");
    table.addEntry("Raiders: Prefer to raid coastal and island villages");
    table.addEntry("Hijackers: Out to take the whole ship intact. Will take "
                   "turncoats as crew or prisoners who surrender to sell as "
                   "slaves");
    table.addEntry("Stowaways revealed");
    table.addEntry("St Elmo's fire: Navigate at advantage for 24 hours");
    table.addEntry("Magnetic disruption affects compasses: Navigate at "
                   "disadvantage while in area");
    table.addEntry("Thick fog: navigate at disadvantage");

    QString direction = QString::number(Dice::roll(1,12)) + " o'clock";
    QString distance = QString::number(Dice::roll(1,2));

    table.addEntry("Dangerous storm: batten down the hatches. Navigation "
                   "impossible. Lost afterwords, and moved " + distance
                   + " hexes at " + direction + " off course");
    table.addEntry("Armada en route to battle");

    RandomTable shipType;
    shipType.addEntry("Submarine");
    shipType.addEntry("Flying ship");
    shipType.addEntry("Caravel (sailing ship)");
    shipType.addEntry("Cargo Ship (should be near a shoreline)");
    shipType.addEntry("Cog (improved cargo ship)");
    shipType.addEntry("Curragh (primitive ship of stretched skins and one sail)");
    shipType.addEntry("Drakkar (dragon ship - large viking longship)");
    shipType.addEntry("Dromond (war ship)");
    shipType.addEntry("Fishing boat");
    shipType.addEntry("Galley (very advanced: oars and three masts)");
    shipType.addEntry("Knarr (open sea cargo ship with oars and sails)");
    shipType.addEntry("Longship (viking)");
    shipType.addEntry("Penteconter (galley with 2 banks of oars and outriggers "
                      "and ram");
    shipType.addEntry("Sohar (middle eastern merchant ship with 3 masts)");
    shipType.addEntry("Trireme (three banks of oars and single mast, and little "
                      "room for supplies)");

    RandomTable sos;
    sos.addEntry("Sinking ship");
    sos.addEntry("Crew mostly dead from illness (contagion possible)");
    sos.addEntry("Crew mostly dead from pirates");
    sos.addEntry("Trick ambush by pirates");
    sos.addEntry("Wreckage with survivors");
    sos.addEntry("Wreckage with no survivors");
    sos.addEntry("Lost at sea, out of provisions");

    RandomTable hail;
    hail.addEntry("Merchant ship requires escort");
    hail.addEntry("Warning about danger in area (pirates or monster)");
    hail.addEntry("Trick ambush by pirates");
    hail.addEntry("Adventurer aid required on nearest shore");
    hail.addEntry("Need directions");
    hail.addEntry("Warning of trespassing");

    RandomTable mission;
    mission.addEntry("Merchant, Guarded by: " + nauticalGuard(), 5);
    mission.addEntry("Passengers, Guarded by: " + nauticalGuard(), 5);
    mission.addEntry("Fishermen", 3);
    mission.addEntry("Pirates", 5);
    mission.addEntry("Privateers", 3);
    mission.addEntry("Adventurers:\n" + NpcTables::adventuringParty(tier),2);
    mission.addEntry("Navy", 2);
    mission.addEntry("Mercenary", 3);
    mission.addEntry("Explorers", 2);
    mission.addEntry("Diplomatic", 4);
    mission.addEntry("Smuggling", 5);
    mission.addEntry("Orc merauders");
    mission.addEntry("Hobgoblin pirates", 3);
    mission.addEntry("Kuo-toan hijackers", 2);
    mission.addEntry("Treasure hunters", 3);
    mission.addEntry("Illithid with thral crew");
    mission.addEntry("Kraken cultists");
    mission.addEntry("Aboleth minions");
    mission.addEntry("Beholder with minion crew");

    QString treasure = "Treasure: " + (Dice::roll(1,100) < tier * 20)
            ? LootTables::generateTreasureHorde(tier)
            : "None";

    table.addEntry("Ghost ship filled with ghosts: "
                   + shipType.getRollTableEntry()
                   + "\n" + treasure);

    table.addEntry("Ghost ship filled with zombies: "
                   + shipType.getRollTableEntry()
                   + "\n" + treasure);

    table.addEntry("Ghost ship filled with skeletons: "
                   + shipType.getRollTableEntry()
                   + "\n" + treasure);

    table.addEntry("Ship in distress sos: " + sos.getRollTableEntry()
                   + shipType.getRollTableEntry()
                   + "\nMission: " + mission.getRollTableEntry()
                   + "\n" + treasure);

    table.addEntry("Ship hail: " + hail.getRollTableEntry()
                   + shipType.getRollTableEntry()
                   + "\nMission: " + mission.getRollTableEntry()
                   + "\n" + treasure);

    table.addEntry("Ship turns and runs away: "
                   + shipType.getRollTableEntry()
                   + "\nMission: " + mission.getRollTableEntry()
                   + "\n" + treasure);

    table.addEntry("Ship quietly maintains course: "
                   + shipType.getRollTableEntry()
                   + "\nMission: " + mission.getRollTableEntry()
                   + "\n" + treasure);

    table.addEntry("Flotsam scattered about surface (a recent sunken ship)");
    table.addEntry("Flotsam scattered about surface (a recent sunken ship with "
                   "sunken treasure)\n"
                   + LootTables::generateTreasureHorde(tier));
    table.addEntry("Jetsam: an abandoned cargo: "
                   + LootTables::generateTreasureHorde(tier));
    table.addEntry("Floating corpses of sailors");
    table.addEntry("Abandoned bathysphere");

    return table.getRollTableEntry();
}

QString HexcrawlTables::nauticalGuard()
{
    RandomTable guardShips;
    guardShips.addEntry("None", 3);
    guardShips.addEntry("Local navy", 3);
    guardShips.addEntry("Mercenary", 4);
    guardShips.addEntry("Privately owned navy", 2);
    guardShips.addEntry("Pirates", 2);
    guardShips.addEntry("Adventurers",2);
    guardShips.addEntry("Sea monster/supernatural");

    return guardShips.getRollTableEntry();
}

QString HexcrawlTables::remoteStructure(int tier)
{
    RandomTable table;

    RandomTable houseTable;
    houseTable.addEntry("Hermit");
    houseTable.addEntry("Single Family");
    int numFamilies = Dice::roll(3,4) + 1;
    houseTable.addEntry("Commune - " + QString::number(numFamilies)
                        + " Families");
    houseTable.addEntry("Druid");
    houseTable.addEntry("Herbalist");
    houseTable.addEntry("Witch");
    houseTable.addEntry("Werecreature");
    int numCultists = Dice::roll(1,3);
    houseTable.addEntry(QString::number(numCultists) + " Cultists");
    houseTable.addEntry("Hunter");
    houseTable.addEntry("Bandit/Criminal");

    int outpostChance = 50;
    bool isOutpost = Dice::roll(1,100) < outpostChance;
    if (isOutpost) {
        table.addEntry("Single House (" + houseTable.getRollTableEntry()
                       + ") or Outpost if on road", 9);
    }
    else {
        table.addEntry("Single House (" + houseTable.getRollTableEntry() + ")",
                       9);
    }
    table.addEntry("Small Castle", 13-10);
    table.addEntry("Large Castle", 16-13);
    table.addEntry("Temple", 20-16);
    table.addEntry("Travellers' Respite Hut", 25-20);

    RandomTable farmTable;
    farmTable.addEntry("Farm stead & fields on road");
    farmTable.addEntry("Hamlet on road");
    farmTable.addEntry("Minor Village on road");
    table.addEntry("Farm stead and small farm fields (if road hex: "
                   + farmTable.getRollTableEntry() + ")", 40-25);

    table.addEntry("Stone Well - still in use", 50-40);

    RandomTable towerTable;
    towerTable.addEntry("Isolated fighters' guild", 19);
    towerTable.addEntry("Mage", 30-20);

    int numMounts = Dice::roll(1,4,6);
    towerTable.addEntry("Small watch tower (10 guards & "
                        + QString::number(numMounts) + " mounts)", 50-30);

    towerTable.addEntry("Religious Commune (NPCs - Acolytes/Priest)", 90-50);

    int numSages = Dice::roll(3,4) + 1;
    towerTable.addEntry("Isolated Library (" + QString::number(numSages)
                        + " researchers)", 100-90);
    table.addEntry("Tower - " + towerTable.getRollTableEntry(), 55-50);

    table.addEntry("Shallow Grave with makeshift tombstone"
                   + minorItemChance(), 60-55);

    table.addEntry("Stone statue of a " + statue() + minorItemChance());

    RandomTable poleTable;
    poleTable.addEntry("picture glyphs", 24);
    poleTable.addEntry("feathers", 50-25);
    poleTable.addEntry("small animalskulls", 75-50);
    poleTable.addEntry("tattered weathered woven scarves", 100-75);
    table.addEntry("Old tall - thick wooden pole inscribed with "
                   + poleTable.getRollTableEntry(), 66-63);

    // Todo: cannot recursively populate a table
    table.addEntry("Inn/Road house (if no road chose something else)", 79-68);

    RandomTable minerTable;
    minerTable.addEntry("Humans");
    minerTable.addEntry("Goblins");
    minerTable.addEntry("Dwarves");
    minerTable.addEntry("Kobolds");
    table.addEntry("Working mine - " + minerTable.getRollTableEntry()
                   + ", " + mineralResource(), 83-79);

    int trapChance = 10;
    bool isTrapped = Dice::roll(1,100) < trapChance;
    table.addEntry("Stone altar"
                   + minorItemChance()
                   + QString((isTrapped)
                             ? ", trapped:\n" + TrapTables::generateTrap(tier)
                             : ""),
                   87-83);

    table.addEntry("Stone dias with pillars" + minorItemChance(), 91-87);
    table.addEntry("Outlaw/Criminal camp (tents)", 96-91);
    table.addEntry("Bandit camp (tents)", 100-96);

    return table.getRollTableEntry();
}

QString HexcrawlTables::ruinedStructure(int tier)
{
    RandomTable table;

    table.addEntry("Dry well", 4);
    table.addEntry("Ancient stone pillars", 10-5);
    table.addEntry("Collapsed and half walls", 15-10);
    table.addEntry("Scattered stone blocks", 5);
    int num = Dice::roll(1,4);
    table.addEntry(QString::number(num) + " Fallen statues - " + statue(), 5);
    table.addEntry("Small ruins", 35-25);
    table.addEntry("Runined building", 44-35);

    table.addEntry("Abandoned mine", 50-44);

    int cellarChance = 25;
    bool hasCellar = Dice::roll(1,100) < cellarChance;
    table.addEntry("Ruined small house" + (hasCellar) ? " with cellar" : "", 5);

    int dungeonChance = 50;
    bool hasDungeon = Dice::roll(1,100) < dungeonChance;
    table.addEntry("Ruined small tower" + (hasDungeon) ? " with dungeon" : "",
                   5);

    dungeonChance = 75;
    hasDungeon = Dice::roll(1,100) < dungeonChance;
    table.addEntry("Ruined small keep" + (hasDungeon) ? " with dungeon" : "",
                   5);

    table.addEntry("Ruined stone walls and stairs into small dungeon", 5);
    table.addEntry("Abandoned and dusty cottage. Belongings still there", 5);

    num = Dice::roll(1,3);
    table.addEntry(QString::number(num) + " Massive (30' high) statues of "
                   + statue() + " - still standing - Ancient", 3);

    int hauntedChance = 30;
    bool isHaunted = Dice::roll(1,100) < hauntedChance;
    table.addEntry("Large ruins" + (isHaunted) ? " (haunted)" : "", 96-79);

    RandomTable cryptTable;
    cryptTable.addEntry("Empty", 19);
    int itemChance = 50;
    bool hasItem = Dice::roll(1,100) < itemChance;
    cryptTable.addEntry("Dead body" + (hasItem) ? " - random item" : "", 90-20);

    itemChance = 30;
    hasItem = Dice::roll(1,100) < itemChance;
    QString magicItem = LootTables::selectMagicItemByTier(tier);
    cryptTable.addEntry("Undead" + (hasItem) ? " - magic item:\n"
                                               + magicItem : "" , 10);
    table.addEntry("Ancient Mausoleum: " + cryptTable.getRollTableEntry(), 4);

    return table.getRollTableEntry();
}

QString HexcrawlTables::naturalStructure(int tier)
{
    RandomTable table;

    RandomTable caveTable;
    caveTable.addEntry("Empty",9);

    int featureChance = 30;
    bool hasFeature = Dice::roll(1,100) < featureChance;
    caveTable.addEntry("Small cave"
                       + (hasFeature) ? " - " + RandomChambers::primaryFeature() : "", 50);

    caveTable.addEntry("Animals", 10);
    caveTable.addEntry("Bandits", 10);
    caveTable.addEntry("Monsters", 10);
    caveTable.addEntry("Old straw bed and tattered blanket/clothes", 8);

    int trappedChance = 50;
    bool isTrapped = Dice::roll(1,100) < trappedChance;
    int emptyChance = 50;
    bool isEmpty = Dice::roll(1,100) < emptyChance;
    QString treasure;
    if (isTrapped) {
        treasure += "(trapped)\n" + TrapTables::generateTrap(tier);
    }
    treasure += "\n"
            + (isEmpty) ? "Chest is Empty!" : LootTables::generateTreasureHorde(1);
    caveTable.addEntry("Locked chest: " + treasure);

    caveTable.addEntry("Dug mound - buried sack with "
                       + LootTables::selectMagicItemByTier(tier));
    table.addEntry("Cave into ground with small number of caverns: "
                   + caveTable.getRollTableEntry());

    table.addEntry("Glowing fungus found (worth 50 sp to a herbalist)", 2);
    table.addEntry("Animal graveyard - lots of bones of many large animals", 3);

    int num = Dice::roll(1,4);
    table.addEntry("Animal nest (in tree/bush) - " + QString::number(num)
                   + " large rare eggs worth 20 sp each", 4);

    table.addEntry("Large pond (or oaisis if desert)", 4);

    num = Dice::roll(1,3);
    RandomTable fruitTable;
    fruitTable.addEntry("berries");
    fruitTable.addEntry("apples");
    fruitTable.addEntry("pears");
    table.addEntry(QString::number(num) + " provisions of: "
                   + fruitTable.getRollTableEntry(), 4);

    table.addEntry("Wild flowers", 3);
    table.addEntry("One large ancient tree surrounded by 12 smaller trees in "
                   "a circle" + minorItemChance(), 5);
    table.addEntry("Small lake (or oaisis if desert)", 5);
    table.addEntry("Bad smell - sulphur", 4);
    table.addEntry("Large scattered boulders and rocky outcrops", 5);
    table.addEntry("Spring of drinkable water" + minorItemChance(), 5);
    table.addEntry("Hot spring (non-drinkable)", 5);

    // TODO: wilderness dressing by biome
    //table.addEntry("Dressing", 35);

    num = Dice::roll(1,3) * 100;
    table.addEntry("Ancient massive crater, " + QString::number(num)
                   + " feet across", 5);

    return table.getRollTableEntry();
}

QString HexcrawlTables::remarkableEvent(int tier)
{
    RandomTable table;
    tier = tier+1;

    RandomTable effectTable;
    effectTable.addEntry("Feather fall", 60);
    effectTable.addEntry("Detect magic", 30);
    effectTable.addEntry("Jump", 10);
    QString effect = effectTable.getRollTableEntry();
    table.addEntry("Stone well with arcane ruins (water gives " + effect
                   + " effect)", 5);

    RandomTable effectTable2;
    effectTable2.addEntry("Cure wounds", 60);
    effectTable2.addEntry("Bless", 30);
    effectTable2.addEntry("Protection from evil", 10);
    effect = effectTable2.getRollTableEntry();
    table.addEntry("Stone Well with Symbol of Good God (water gives " + effect
                   + " effect)", 5);

    RandomTable effectTable3;
    effectTable3.addEntry("Detect poison and disease", 60);
    effectTable3.addEntry("Bane", 30);
    effectTable3.addEntry("Protection from good", 10);
    effect = effectTable3.getRollTableEntry();
    table.addEntry("Stone Well with Symbol of Evil God (water gives " + effect
                   + " effect)", 5);

    RandomTable effectTable4;
    effectTable4.addEntry("Changes sex", 2);
    effectTable4.addEntry("Blessing - gain inspiration", 20);
    effectTable4.addEntry("Ages 4d4 years older", 5);
    effectTable4.addEntry("Arcane blast - take 2d5 damage", 48-23);
    effectTable4.addEntry("Heals - Fully heals and gain 1d8 temporary hp", 58-43);
    effectTable4.addEntry("Ages 1d4 years younger", 63-58);
    effectTable4.addEntry("Gates in random creature", 10);
    effectTable4.addEntry("Random ability score increase +1 for 1d6 days", 10);
    effectTable4.addEntry("Random ability score decrease -1 for 1d4 days", 10);
    effectTable4.addEntry("Changed alignment: " + NpcTables::determineAlignment(),
                          2);
    effectTable4.addEntry("Random magical item appears", 5);
    effect = effectTable4.getRollTableEntry();
    table.addEntry("Ancient glowing stone pillar - glyphs - if touched: "
                   + effect + " (Stops glowing and functioning on first touch. "
                              "Doesn't work again for one year.", 5);

    RandomTable effectTable5;
    effectTable5.addEntry("Poison", 40);
    effectTable5.addEntry("Healing Liquid (Cure wounds)", 20);
    effectTable5.addEntry("Strength liquid", 10);
    effectTable5.addEntry("Mind affecting drug (as strong alcohol)", 20);
    effect = effectTable5.getRollTableEntry();
    table.addEntry("Ancient black tree with twisted branches, red liquid "
                   "oozes: " + effect, 5);

    table.addEntry("Moonwell (1d8 + wis mod) heals; or poisons if person has "
                   "threatened nature. If full moon, also lesser restoration",
                   5);
    table.addEntry("Earth quake - small crack opens in ground", 5);
    table.addEntry("Meteor strike on the horizon", 5);
    table.addEntry("Arcane diffusement - off pitch hum causes 20% spell failure "
                   "and cannot use higher level spell slots for 1 day.",1);
    table.addEntry("Arcane enrichment - low pich hum: spell DCs +5, spells "
                   "treated as spell slot +1 for 1 day.", 1);
    return table.getRollTableEntry();
}

QString HexcrawlTables::lair(int tier)
{
    tier = tier+1;
    RandomTable table;
    RandomTable lairTypeTable;
    lairTypeTable.addEntry("Caves");
    lairTypeTable.addEntry("Dungeon");
    lairTypeTable.addEntry("Ruins");
    lairTypeTable.addEntry("Constructed buildings");
    lairTypeTable.addEntry("Huts");
    lairTypeTable.addEntry("Constructed tunnels");
    lairTypeTable.addEntry("Defeated village");
    lairTypeTable.addEntry("City");
    lairTypeTable.addEntry("Abandoned temple");
    lairTypeTable.addEntry("Mines");
    lairTypeTable.addEntry("Tombs");
    lairTypeTable.addEntry("Castle");
    lairTypeTable.addEntry("Fort");
    lairTypeTable.addEntry("Manor");
    lairTypeTable.addEntry("Pyramid");
    lairTypeTable.addEntry("Zigurat");
    lairTypeTable.addEntry("Tower");
    QString lairType = lairTypeTable.getRollTableEntry();

    int num = Dice::roll(1,4) * 10;
    table.addEntry(QString::number(num) + " Bugbears" + " in " + lairType, 8);
    num = Dice::roll(2,4) * 10;
    table.addEntry(QString::number(num) + " Gnolls" + " in " + lairType, 8);
    num = Dice::roll(5,3) * 10;
    table.addEntry(QString::number(num) + " Goblins" + " in " + lairType, 8);
    num = Dice::roll(2,4) * 10;
    table.addEntry(QString::number(num) + " Hobgoblins" + " in " + lairType, 8);
    num = Dice::roll(3,4) * 10;
    table.addEntry(QString::number(num) + " Kobolds" + " in " + lairType, 8);
    num = Dice::roll(2,4) * 10;
    table.addEntry(QString::number(num) + " Lizardfolk" + " in " + lairType, 8);
    num = Dice::roll(2,4) * 10;
    table.addEntry(QString::number(num) + " Orcs" + " in " + lairType, 8);
    num = Dice::roll(1,4, 1)/2 * 10;
    table.addEntry(QString::number(num) + " Ankhegs" + " in " + lairType, 4);
    num = 1;
    table.addEntry(QString::number(num) + " Troll" + " in " + lairType, 4);
    table.addEntry(QString::number(num) + " Roc" + " in " + lairType, 4);
    num = Dice::roll(2,4, 1)/2 * 10;
    table.addEntry(QString::number(num) + " Yuan-ti" + " in " + lairType, 4);
    num = 1;
    table.addEntry(QString::number(num) + " Aboleth" + " in " + lairType
                   + " with subterranean lake");
    table.addEntry(QString::number(num) + " Beholder" + " in " + lairType);
    table.addEntry(QString::number(num) + " Death tyrant" + " in " + lairType);
    table.addEntry(QString::number(num) + " Demi-lich" + " in " + lairType);
    table.addEntry(QString::number(num) + " Black dragon" + " in " + lairType
                   + " near swamp");
    table.addEntry(QString::number(num) + " Blue dragon" + " in " + lairType);
    table.addEntry(QString::number(num) + " Green dragon" + " in " + lairType
                   + " near woods");
    table.addEntry(QString::number(num) + " Red dragon" + " in " + lairType
                   + " near lava");
    table.addEntry(QString::number(num) + " White dragon" + " in " + lairType
                   + " near (possibly unseasonal) snow and ice");
    table.addEntry(QString::number(num) + " Brass dragon" + " in " + lairType);
    table.addEntry(QString::number(num) + " Bronze dragon" + " in " + lairType);
    table.addEntry(QString::number(num) + " Copper dragon" + " in " + lairType);
    table.addEntry(QString::number(num) + " Gold dragon" + " in " + lairType);
    table.addEntry(QString::number(num) + " Silver dragon" + " in " + lairType);
    table.addEntry(QString::number(num) + " Lich" + " in " + lairType);
    table.addEntry(QString::number(num) + " Mummy lord" + " in " + lairType);
    table.addEntry(QString::number(num) + " Unicorn" + " in " + lairType);
    table.addEntry(QString::number(num) + " Vampire" + " in " + lairType);

    return table.getRollTableEntry();
}

QString HexcrawlTables::pastEvent(int tier)
{
    RandomTable table;
    RandomTable freshnessTable;
    RandomTable bodyTypeTable;
    RandomTable symbolTable;

    freshnessTable.addEntry("Fresh - today");
    freshnessTable.addEntry("Within last week");
    freshnessTable.addEntry("Within last few months");
    freshnessTable.addEntry("Very old");
    bodyTypeTable.addEntry("monster");
    bodyTypeTable.addEntry("humanoid");
    bodyTypeTable.addEntry("adventurer");
    symbolTable.addEntry("invoking an evil god or summoning");
    symbolTable.addEntry("invoking a good god or summoning");
    symbolTable.addEntry("protective ward - no longer active");

    int num = Dice::roll(1,6) / 3;

    table.addEntry(QString::number(num) + " Dead body: "
                   + freshnessTable.getRollTableEntry() + ", "
                   + bodyTypeTable.getRollTableEntry());

    table.addEntry("Large pool of blood");
    table.addEntry("Dead animal");
    table.addEntry("Area of fire/destruction (see smoke in distance)"
                   + minorItemChance());
    table.addEntry("Signs of ground being dug up and old sacks laying around."
                   + minorItemChance());

    int trapChance = 10;
    bool isTrapped = Dice::roll(1,100) < trapChance;

    table.addEntry("Altar with bloody body"
                   + (isTrapped) ? ", trapped:\n" + TrapTables::generateTrap(tier)
                                 : "");
    table.addEntry("Campsite with smoldering fire, a few hours old"
                   + minorItemChance());
    table.addEntry("Scene of recent skirmish - dead humans/humanoids & "
                   "monsters" + minorItemChance());
    table.addEntry("Smoldering and smoking remains - large funeral pyre - "
                   "burnt body");
    table.addEntry("Dead adventurer - in gear - arrows sticking out of him"
                   + itemAndBanditChance());
    table.addEntry("Dead body hanging (noose) from tree branch: "
                   + freshnessTable.getRollTableEntry() + ", "
                   + bodyTypeTable.getRollTableEntry());
    table.addEntry("Burnt arcane symbols on tree/boulder: "
                   + symbolTable.getRollTableEntry());
    table.addEntry("Large giant skull" + minorItemChance());
    table.addEntry("Wandering riding horse with saddle looks injured and "
                   "tired.");

    return table.getRollTableEntry();
}

QString HexcrawlTables::npcEncounter(int tier)
{
    RandomTable table;
    int chance = 50;
    bool isChance = Dice::roll(1,100) < chance;
    int num = Dice::roll(1,6) / 3;

    QString race = NpcTables::AdventurerRace();

    // TODO: cannot recursive populate table
    table.addEntry("Traveling " + race + " merchant wagon"
                   + QString((isChance)
                             ? QString::number(num) + " guards present"
                             : "")
                   + " (only if on road"
                   + ")");

    num = Dice::roll(1,4);
    table.addEntry(race + " Hunting party of " + QString::number(num));

    num = Dice::roll(1,3);
    table.addEntry(QString::number(num) + " " + race + " Explorers"
                   + ((isChance) ? " on mounts" : ""));

    chance = 80;
    isChance = Dice::roll(1,100) < chance;
    table.addEntry(QString((isChance) ? "Mounted " : "") + "Adventuring party:\n"
                   + NpcTables::adventuringParty(tier)
                   + ", " + NpcTables::determineAlignment());

    table.addEntry(QString((isChance) ? "Mounted " : "") + "Adventurer:\n"
                   + NpcTables::generateAdventurer(tier)
                   + ", " + NpcTables::determineAlignment());

    num = Dice::roll(3,4, 1)/2;
    // TODO: cannot recursive populate table
    table.addEntry("Goods wagon train with " + QString::number(num)
                   + " " + race + " guards"
                   + " (only if on road"
                   + ")");

    num = Dice::roll(1,3);
    table.addEntry(QString::number(num)
                   + " " + race + " Pilgrims, can offer healing (Acolyte)");

    chance = 50;
    isChance = Dice::roll(1,100) < chance;
    table.addEntry("Suspicious character, " + race
                   + QString((isChance) ? ", mounted" : "")
                   + ", " + NpcTables::determineAlignment());

    RandomTable victim;
    victim.addEntry("Adventurer: " + NpcTables::generateAdventurer(tier) + ", "
                    + NpcTables::determineAlignment());
    victim.addEntry(race + " Merchant");
    victim.addEntry(race + " Commoner");
    victim.addEntry(race + "Evil Humanoid");
    table.addEntry("Unconcious " + race + " tied up (victem of bandits): "
                   + victim.getRollTableEntry());

    table.addEntry("Mysterious seated " + race + " wizard, reading a book "
                                                 "(NPC Mage)");
    num = Dice::roll(4,4);
    table.addEntry(QString::number(num) + " travelling " + race
                   + " gypsies on a wagon");
    table.addEntry("Lost " + race
                   + " caravan guard (caravan attacked and got separated)");

    RandomTable shuned;
    shuned.addEntry("Diseased - skin sores");
    shuned.addEntry("Lunatic - shouting random sentances");
    shuned.addEntry("Beggar - asks for coin or food");
    table.addEntry("Shunned one " + race + " in dirty rags: "
                   + shuned.getRollTableEntry());

    table.addEntry("Barbarian (NPC berzerker)");
    table.addEntry("Naked man laying on ground, confused, scratches "
                   "(werewolf)");
    table.addEntry("Naked woman swimming in water");
    table.addEntry("Naked woman swimming in water (succubus)");

    num = Dice::roll(2,3);
    RandomTable watch;
    watch.addEntry("On general patrol");
    watch.addEntry("Looking for escaped prisoner");
    watch.addEntry("Looking for monsters/bandits in area");
    table.addEntry(QString::number(num) + " mounted watch patrol: "
                   + watch.getRollTableEntry());

    return table.getRollTableEntry();
}

QString HexcrawlTables::currentEvent(int tier)
{
    ++tier;
    RandomTable table;
    RandomTable animals;
    RandomTable robbers;
    RandomTable monsters;
    RandomTable body;
    RandomTable flying;

    int num = Dice::roll(1,4, 1)/2;
    int num2 = (Dice::roll(1,4, 1)/2);
    int chance = 50;
    bool isChance = Dice::roll(1,100) < chance;
    QString race = NpcTables::AdventurerRace();
    QString race2 = NpcTables::AdventurerRace();

    animals.addEntry(QString::number(num) + " Wolves");
    animals.addEntry(QString::number(num) + " Black Bear");
    animals.addEntry(QString::number(num) + " Boars");
    animals.addEntry(QString::number(num) + " Brown Bears");
    animals.addEntry(QString::number(num) + " Dire Wolves");
    animals.addEntry(QString::number(num) + " Lions");
    animals.addEntry(QString::number(num) + " Panthers");
    animals.addEntry(QString::number(num) + " Tigers");

    robbers.addEntry("Bandits");
    robbers.addEntry("Thugs");

    monsters.addEntry("Goblins");
    monsters.addEntry("Kobolds");
    monsters.addEntry("Orcs");
    monsters.addEntry("Axe beaks");
    monsters.addEntry("Bugbears");
    monsters.addEntry("Cockatrices");
    monsters.addEntry("Gnolls");
    monsters.addEntry("Hobgoblins");
    monsters.addEntry("Ogres");
    monsters.addEntry("Trolls");

    body.addEntry("Boar");
    body.addEntry("Deer");
    body.addEntry("Horse");
    body.addEntry("Goat");
    body.addEntry("Dog");
    body.addEntry("Goblin");
    body.addEntry("Kobold");
    body.addEntry("Human");
    body.addEntry(NpcTables::AdventurerRace() + " adventurer");

    flying.addEntry("Chimera");
    flying.addEntry("Wyvern");
    flying.addEntry("Giant Eagle");
    flying.addEntry("Griffin");
    flying.addEntry("Hippogriff");
    flying.addEntry("Giant Vulture");
    flying.addEntry("Manticore");
    flying.addEntry("Young green dragon");

    num = Dice::roll(1,6);
    chance = 50;
    isChance = Dice::roll(1,100) < chance;

    table.addEntry("Fire covering " + QString::number(num) + " "
                   + QString((isChance) ? "miles" : "yards")
                   + " (see smoke in distance).");
    table.addEntry(animals.getRollTableEntry() + " attacking " + race
                   + " woman and child");
    table.addEntry(QString::number(num2) + " "
                   + race + " " + robbers.getRollTableEntry() + " attacking "
                   + QString::number(num) + " " + race2 + " travelers");

    table.addEntry(QString::number(num2) + " "
                   + monsters.getRollTableEntry() + " attacking "
                   + QString::number(num) + " " + race + " travelers");

    table.addEntry(animals.getRollTableEntry() + " munching on dead body of "
                   + body.getRollTableEntry());

    // TODO: biome related minor event table
    //table.addEntry("Minor event");

    table.addEntry(flying.getRollTableEntry() + " flying over ahead - dead "
                                                "body in mouth: "
                   + body.getRollTableEntry());
    table.addEntry("Mage duel - two spell casters attacking each other");
    num = Dice::roll(1,3) + 4;
    table.addEntry("Naked female tied on altar. "
                   + QString::number(num) + " cultists around");
    num = (Dice::roll(1,4, 1)/2) + 2;
    table.addEntry("Prisoner being chased by " + QString::number(num)
                   + " guards");

    num = Dice::roll(1,3,2);
    table.addEntry(QString::number(num) + " thugs digging up stolen treasure "
                                          "(sacks in ground):\n"
                   + LootTables::generateTreasureHorde(1));

    return table.getRollTableEntry();
}

QString HexcrawlTables::lostItem(int tier)
{
    RandomTable table;

    table.addEntry("Random weapon");
    table.addEntry("Clothing - robe/shirt/pants/boot/glove");
    table.addEntry(LootTables::generateIndividualTreasure(1));
    table.addEntry("Random utensil (fork/knife/cup)");
    table.addEntry(LootTables::art(tier));
    table.addEntry("Storage - backpack, sack, puch");
    table.addEntry("Random trinket");
    table.addEntry("Diary - leather bound - trivial entries");

    return table.getRollTableEntry();
}

QString HexcrawlTables::animalHerd()
{
    RandomTable table;

    int num = Dice::roll(4,4);
    table.addEntry(QString::number(num) + " Wolves");
    num = Dice::roll(3,4);
    table.addEntry(QString::number(num) + " Boars");
    table.addEntry(QString::number(num) + " Axe Beaks");
    num = Dice::roll(5,4);
    table.addEntry(QString::number(num) + " Deers");
    num = Dice::roll(4,4);
    table.addEntry(QString::number(num) + " Wild horses");
    num = Dice::roll(5,4);
    table.addEntry(QString::number(num) + " Elk");
    num = Dice::roll(5,3);
    table.addEntry(QString::number(num) + " Hyena");
    table.addEntry(QString::number(num) + " Jakal");
    num = Dice::roll(4,3);
    table.addEntry(QString::number(num) + " Elephants");

    return table.getRollTableEntry();
}

QString HexcrawlTables::minorItemChance()
{
    int chance = 10;
    bool hasMinorItem = Dice::roll(1,100) < chance;
    if (!hasMinorItem) {
        return "";
    }

    RandomTable table;
    table.addEntry(LootTables::generateIndividualTreasure(1));
    table.addEntry(LootTables::gem(1));
    table.addEntry(LootTables::art(1));
    table.addEntry(LootTables::minorCommonMagicItems());
    return " with minor item: " + table.getRollTableEntry();
}

QString HexcrawlTables::itemAndBanditChance()
{
    int chance = 20;
    bool hasMinorItem = Dice::roll(1,100) < chance;
    if (!hasMinorItem) {
        return "";
    }

    int num = Dice::roll(1,4) + 4;

    return ". Also, " + QString::number(num) + " bandits with minor item: "
            + minorItemChance();
}

QString HexcrawlTables::tracks()
{
    RandomTable table;

    table.addEntry("Distant sighting (flying across the sun, breifly glimpsed "
                   "on the distant ridge line)");
    table.addEntry("Sounds (snatches of shouting or song down in the valley)");
    table.addEntry("Body parts");
    table.addEntry("Victims");
    table.addEntry("Tracks");
    table.addEntry("Smells and vapors");
    table.addEntry("Environment damage");
    table.addEntry("Intentional markings");
    table.addEntry("Scat/refuse");

    return table.getRollTableEntry();
}

QString HexcrawlTables::statue()
{
    RandomTable statueTable;
    statueTable.addEntry("god", 50);
    statueTable.addEntry("personality", 25);
    statueTable.addEntry("beast/monster", 25);
    return statueTable.getRollTableEntry();
}

QString HexcrawlTables::mineralResource()
{
    RandomTable table;

    table.addEntry("Copper", 30);
    table.addEntry("Tin", 10);
    table.addEntry("Lead", 67-41);
    table.addEntry("Iron", 85-67);
    table.addEntry("Silver", 93-85);
    table.addEntry("Gold", 98-93);
    table.addEntry("Platinum");
    RandomTable mithrilTable;
    mithrilTable.addEntry("Silver (Highest quality)", 5);
    mithrilTable.addEntry("Gold (Highest quality)", 3);
    mithrilTable.addEntry("Platinum (highest quality)");
    mithrilTable.addEntry("Mithril");
    table.addEntry(mithrilTable.getRollTableEntry());
    table.addEntry("Gemstones: " + gemMine());

    return table.getRollTableEntry();
}

QString HexcrawlTables::gemMine()
{
    RandomTable gemTable;
    gemTable.addEntry("Bloodstone", 8);
    gemTable.addEntry("Onyx", 10);
    gemTable.addEntry("Turquoise", 25-19);
    gemTable.addEntry("Agate", 6);
    gemTable.addEntry("Aquamarine", 6);
    gemTable.addEntry("Garnet", 43-37);
    gemTable.addEntry("Jade", 6);
    gemTable.addEntry("Alexandrite", 55-49);
    gemTable.addEntry("Amethyst", 5);
    gemTable.addEntry("Topaz", 5);
    gemTable.addEntry("Jet", 73-67);
    gemTable.addEntry("Opal", 78-73);
    gemTable.addEntry("Ruby", 83-78);
    gemTable.addEntry("Sapphire", 88-83);
    gemTable.addEntry("Diamond", 93-88);
    gemTable.addEntry("Emerald", 97-93);
    // Todo: cannot recursively populate a mine
    gemTable.addEntry("Choose 2", 3);
    gemTable.addEntry("Choose 3");

    return gemTable.getRollTableEntry();
}

