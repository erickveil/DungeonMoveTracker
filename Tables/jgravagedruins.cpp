#include "jgravagedruins.h"

JGRavagedRuins::JGRavagedRuins()
{

}

QString JGRavagedRuins::buildRuins()
{
    QString msg = choseClass() + "\n"
            + choseCondition() + "\n"
            + choseState() + "\n"
            + choseKeeper() + "\n";
    return msg;
}

QString JGRavagedRuins::choseClass()
{

    TableTemplate<QString> table;
    table.addEntry("Ruins: " + choseRuins());
    table.addEntry("Relics: " + choseRelics());
    table.addEntry("Remains: " + choseRemains());
    table.addEntry("Vestiges: " + choseVestiges());
    table.addEntry("Remnants: " + choseRemnants());
    table.addEntry("Refuse: " + choseRefuse());
    table.addEntry("Wrecks: " + choseWrecks());
    table.addEntry("Skeletons: " + choseSkeletons());
    table.addEntry("Antiques: " + choseAntiques());
    table.addEntry("Artifacts: " + choseArtifacts());
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseCondition()
{

    TableTemplate<QString> table;
    table.addEntry("Partially covered: " + choseCovering());
    table.addEntry("Fully covered: " + choseCovering());
    table.addEntry("Above ground");
    table.addEntry("Rocky Slope");
    table.addEntry("Inside cavern");
    table.addEntry("In crevice");
    table.addEntry("Beneath Overhang");
    table.addEntry("Large Crater");
    table.addEntry("Partially Sunken");
    table.addEntry("Charred & Burnt");
    return table.getRollTableEntry();
}

QString JGRavagedRuins::choseCovering()
{

    TableTemplate<QString> table;
    table.addEntry("Sand");
    table.addEntry("Ashes");
    table.addEntry("Cinders");
    table.addEntry("Earth");
    table.addEntry("Thicket");
    table.addEntry("Mold");
    table.addEntry("Slime");
    table.addEntry("Rocks");
    table.addEntry("Webs & Dust");
    table.addEntry("Vines");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseState()
{

    TableTemplate<QString> table;
    table.addEntry("Crumbled & Decayed");
    table.addEntry("Disfigured & Defaced");
    table.addEntry("Wormeaten");
    table.addEntry("Crystallized & Petrified");
    table.addEntry("Corroded & Eroded");
    table.addEntry("Collapsed & Tumbled");
    table.addEntry("Mouldy & contaminated");
    table.addEntry("Dangerous Operational");
    table.addEntry("Partially Operational");
    table.addEntry("Fully Operational");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseKeeper()
{

    TableTemplate<QString> table;
    table.addEntry("Mechanical");
    table.addEntry("Giant Types");
    table.addEntry("Dragon-Class");
    table.addEntry("Undead-Types");
    table.addEntry("Lycanthropes");
    table.addEntry("True-Giants");
    table.addEntry("Animals");
    table.addEntry("Insects");
    table.addEntry("Trap");
    table.addEntry("None");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseRuins()
{

    TableTemplate<QString> table;
    table.addEntry("Manor: " + choseManor());
    table.addEntry("Village: " + choseVillage());
    table.addEntry("City: " + choseCity());
    table.addEntry("Citadel: " + choseCitadel());
    table.addEntry("Castle: " + choseCastle());
    table.addEntry("Temple: " + choseTemple());
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseManor()
{

    TableTemplate<QString> table;
    table.addEntry("Hut");
    table.addEntry("Hoval");
    table.addEntry("Hall");
    table.addEntry("Villa");
    table.addEntry("Cottage");
    table.addEntry("Palace");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseVillage()
{
    TableTemplate<QString> table;
    QString qty;
    qty = QString::number(Dice::roll(2,6));
    table.addEntry(qty + " Huts");
    qty = QString::number(Dice::roll(4,6));
    table.addEntry(qty + " Hovals");
    qty = QString::number(Dice::roll(6,6));
    table.addEntry(qty + " Cottages");
    table.addEntry(qty + " Cottages & Ditch");
    table.addEntry(qty + " Cottages & Pallisade");
    table.addEntry(qty + " Cottages, Pallisade, & Moat");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseCity()
{

    TableTemplate<QString> table;
    QString qty;
    qty = QString::number(Dice::roll(7,6));
    table.addEntry(qty + "Houses & Citadel: " + choseCitadel());
    qty = QString::number(Dice::roll(8,6));
    table.addEntry(qty + "Houses");
    qty = QString::number(Dice::roll(9,6));
    table.addEntry(qty + "Houses & Wall");
    table.addEntry(qty + "Houses, Wall, & Citadel: " + choseCitadel());
    qty = QString::number(Dice::roll(20,6));
    table.addEntry(qty + "Houses");
    QString qty2 = QString::number(Dice::roll(1,4));
    table.addEntry(qty + "Houses & " + qty2 + " temples");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseCitadel()
{

    TableTemplate<QString> table;
    table.addEntry("Tower");
    table.addEntry("Tower & Outer Wall");
    table.addEntry("Great Keep");
    table.addEntry("Keep & 4 Towers");
    table.addEntry("Keep, 4 Towers, & Outer Wall");
    table.addEntry("Keep, 4 Towers, Outer Wall, & Moat");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseCastle()
{

    TableTemplate<QString> table;
    table.addEntry("Keep & Pallisades");
    table.addEntry("Keep & Moat");
    table.addEntry("Keep, Moat & Walls");
    table.addEntry("Keep, Moat, Walls, & Manor");
    table.addEntry("Keep, Moat, Walls, Manor, & 4 Towers");
    table.addEntry("Keep, Moat, Walls, Manor, 4 Towers, & Outer Wall");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseTemple()
{

    TableTemplate<QString> table;
    table.addEntry("Altar");
    table.addEntry("Shrine");
    table.addEntry("Sanctuary");
    table.addEntry("Oracle");
    table.addEntry("Pantheon");
    table.addEntry("Monastary");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseRelics()
{

    TableTemplate<QString> table;
    table.addEntry("Tools: " + choseTools());
    table.addEntry("Machines: " + choseMachines());
    table.addEntry("Tombs: " + choseTombs());
    table.addEntry("Armor: " + choseArmor());
    table.addEntry("Weapons: " + choseWeapons());
    table.addEntry("Containers: " + choseContainers());
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseTools()
{

    TableTemplate<QString> table;
    table.addEntry("Ladder");
    table.addEntry("Plow");
    table.addEntry("Pick");
    table.addEntry("Hoe");
    table.addEntry("Anvil");
    table.addEntry("Axe");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseMachines()
{

    TableTemplate<QString> table;
    table.addEntry("Loom");
    table.addEntry("Grinding Wheel");
    table.addEntry("Clock");
    table.addEntry("Balance");
    table.addEntry("Potter Wheel");
    table.addEntry("Press");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseTombs()
{

    TableTemplate<QString> table;
    table.addEntry("Grave");
    table.addEntry("Sepulcher");
    table.addEntry("Mausoleum");
    table.addEntry("Catacombs");
    table.addEntry("Vault");
    table.addEntry("Crypt");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseArmor()
{

    TableTemplate<QString> table;
    table.addEntry("Breastplate");
    table.addEntry("Greaves");
    table.addEntry("Gauntlets");
    table.addEntry("Helmet");
    table.addEntry("Chainmail");
    table.addEntry("Shield");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseContainers()
{

    TableTemplate<QString> table;
    table.addEntry("Barrels");
    table.addEntry("Urns");
    table.addEntry("Trunks");
    table.addEntry("Jars");
    table.addEntry("Bottles");
    table.addEntry("Boxes");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseRemains()
{

    TableTemplate<QString> table;
    table.addEntry("Utensils: " + choseUtensils());
    table.addEntry("Apparel: " + choseApparel());
    table.addEntry("Harness: " + choseHarness());
    table.addEntry("Toys: " + choseToys());
    table.addEntry("Optics: " + choseOptics());
    table.addEntry("Tome: " + choseTomes());
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseUtensils()
{

    TableTemplate<QString> table;
    table.addEntry("Eating");
    table.addEntry("Digging");
    table.addEntry("Writing");
    table.addEntry("Navigating");
    table.addEntry("Measuring");
    table.addEntry("Musical");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseApparel()
{

    TableTemplate<QString> table;
    table.addEntry("Hauberk");
    table.addEntry("Boots");
    table.addEntry("Cloak");
    table.addEntry("Tunic");
    table.addEntry("Mask");
    table.addEntry("Breeches");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseHarness()
{

    TableTemplate<QString> table;
    table.addEntry("Swimmer");
    table.addEntry("Flyer");
    table.addEntry("Giant-animal");
    table.addEntry("Small-animal");
    table.addEntry("Man-size");
    table.addEntry("Colossal");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseToys()
{

    TableTemplate<QString> table;
    table.addEntry("Doll");
    table.addEntry("Vehicle");
    table.addEntry("Weapon");
    table.addEntry("Tool");
    table.addEntry("Game");
    table.addEntry("House");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseOptics()
{

    TableTemplate<QString> table;
    table.addEntry("Monocle");
    table.addEntry("Spectacles");
    table.addEntry("Spyglass");
    table.addEntry("Mirror");
    table.addEntry("Colored Pane");
    table.addEntry("Periscope");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseTomes()
{

    TableTemplate<QString> table;
    table.addEntry("Lexicon");
    table.addEntry("Scroll");
    table.addEntry("Manual");
    table.addEntry("Tablet");
    table.addEntry("Book");
    table.addEntry("Codex");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseVestiges()
{

    TableTemplate<QString> table;
    table.addEntry("Pyramid: " + chosePyramid());
    table.addEntry("Mound: " + choseMound());
    table.addEntry("Fountain: " + choseFountain());
    table.addEntry("Totem: " + choseTotem());
    table.addEntry("Sewers: " + choseSewers());
    table.addEntry("Monolith: " + choseMonolith());
    return table.getRollTableEntry();

}

QString JGRavagedRuins::chosePyramid()
{

    QString sides = (Dice::roll(1,6) <= 4) ? " with stepped sides" : " with flat sides";
    TableTemplate<QString> table;
    table.addEntry("Burial Tomb" + sides);
    table.addEntry("Temple" + sides);
    table.addEntry("Observatory" + sides);
    table.addEntry("Palace" + sides);
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseMound()
{

    TableTemplate<QString> table;
    table.addEntry("Sacrificial");
    table.addEntry("Burial");
    table.addEntry("Treasure");
    table.addEntry("Lair");
    table.addEntry("Sacred");
    table.addEntry("Polymorphed");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseFountain()
{

    TableTemplate<QString> table;
    table.addEntry("Giant");
    table.addEntry("Statued");
    table.addEntry("Miniature");
    table.addEntry("Geometric");
    table.addEntry("Wish");
    table.addEntry("Spray");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseTotem()
{

    TableTemplate<QString> table;
    table.addEntry("Mammal");
    table.addEntry("Human");
    table.addEntry("God");
    table.addEntry("Monster");
    table.addEntry("Bird");
    table.addEntry("Snake");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseSewers()
{

    TableTemplate<QString> table;
    table.addEntry("1' Square & Open");
    table.addEntry("2' Square & Open");
    table.addEntry("Closed & 1' Square");
    table.addEntry("Closed & 2' Square");
    table.addEntry("Closed & 4' Square");
    table.addEntry("Closed & 8' Square");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseMonolith()
{

    TableTemplate<QString> table;
    table.addEntry("Column");
    table.addEntry("Hewn Statue");
    table.addEntry("Minaret");
    table.addEntry("Obelisk");
    table.addEntry("Effigy");
    table.addEntry("Monumnent");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseRemnants()
{

    TableTemplate<QString> table;
    table.addEntry("Road: " + choseRoad());
    table.addEntry("Tombstone: " + choseTombstone());
    table.addEntry("Signpost: " + choseSignpost());
    table.addEntry("Channel: " + choseChannel());
    table.addEntry("Masonry: " + choseMasonry());
    table.addEntry("Bridge: " + choseBridge());
    table.addEntry("Wall: " + choseWall());
    table.addEntry("Edifice: " + choseEdifice());
    table.addEntry("Works: " + choseWorks());
    table.addEntry("Structure: " + choseStructure());
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseRoad()
{

    TableTemplate<QString> table;
    table.addEntry("Track");
    table.addEntry("Trail");
    table.addEntry("Gravel");
    table.addEntry("Roman Paved");
    table.addEntry("Asphault");
    table.addEntry("Concrete");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseTombstone()
{

    TableTemplate<QString> table;
    table.addEntry("Plaque");
    table.addEntry("Cairn");
    table.addEntry("Staff");
    table.addEntry("Beacon");
    table.addEntry("Pyre");
    table.addEntry("Stone Pile");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseSignpost()
{

    TableTemplate<QString> table;
    table.addEntry("Guide");
    table.addEntry("Omen");
    table.addEntry("Trade");
    table.addEntry("Warning");
    table.addEntry("Emblem");
    table.addEntry("Boundary");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseChannel()
{

    TableTemplate<QString> table;
    table.addEntry("Tunnel");
    table.addEntry("Pipe");
    table.addEntry("Well");
    table.addEntry("Passage");
    table.addEntry("Canal");
    table.addEntry("Aqueduct");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseMasonry()
{

    TableTemplate<QString> table;
    table.addEntry("Mud bricks");
    table.addEntry("Stone Bricks");
    table.addEntry("Marble blocks");
    table.addEntry("Plaster");
    table.addEntry("Wattle");
    table.addEntry("Stone blocks");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseBridge()
{

    TableTemplate<QString> table;
    table.addEntry("Rope");
    table.addEntry("Wood");
    table.addEntry("Stone");
    table.addEntry("Earth");
    table.addEntry("Natural");
    table.addEntry("Brick");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseEdifice()
{

    TableTemplate<QString> table;
    table.addEntry("Carved Cliff");
    table.addEntry("Sculptured Mound");
    table.addEntry("Colossal Statue");
    table.addEntry("Palace");
    table.addEntry("Mill");
    table.addEntry("Calendar Stone");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseWorks()
{

    TableTemplate<QString> table;
    table.addEntry("Arsenal");
    table.addEntry("Granary");
    table.addEntry("Paved Plaza");
    table.addEntry("Viaduct");
    table.addEntry("Reservoir");
    table.addEntry("Cistern");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseStructure()
{

    TableTemplate<QString> table;
    table.addEntry("Stairway");
    table.addEntry("Ramp");
    table.addEntry("Shaft");
    table.addEntry("Spire");
    table.addEntry("Roof");
    table.addEntry("Tunnel");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseWall()
{

    TableTemplate<QString> table;
    table.addEntry("Stockage");
    table.addEntry("Barricade");
    table.addEntry("Fence");
    table.addEntry("Rampart");
    table.addEntry("Dike");
    table.addEntry("Partition");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseRefuse()
{

    TableTemplate<QString> table;
    table.addEntry("Offal: " + choseOffal());
    table.addEntry("Sewage: " + choseSewage());
    table.addEntry("Parts: " + choseParts());
    table.addEntry("Discards: " + choseDiscards());
    table.addEntry("Food: " + choseFood());
    table.addEntry("Fuel: " + choseFuel());
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseOffal()
{

    TableTemplate<QString> table;
    table.addEntry("Viscere");
    table.addEntry("Bones");
    table.addEntry("Gore");
    table.addEntry("Grizzle");
    table.addEntry("Fat");
    table.addEntry("Talons");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseSewage()
{

    TableTemplate<QString> table;
    table.addEntry("Soap");
    table.addEntry("Body Washes");
    table.addEntry("Oils");
    table.addEntry("Slop");
    table.addEntry("Chemicals");
    table.addEntry("Lint");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseParts()
{

    TableTemplate<QString> table;
    table.addEntry("Buckle");
    table.addEntry("Lacing");
    table.addEntry("Crossbar");
    table.addEntry("Pommels");
    table.addEntry("Arrowhead");
    table.addEntry("Spike");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseDiscards()
{

    TableTemplate<QString> table;
    table.addEntry("Leather Scraps");
    table.addEntry("Papyrus Scraps");
    table.addEntry("Handle");
    table.addEntry("Shield Frame");
    table.addEntry("Pole");
    table.addEntry("Linen Scraps");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseFood()
{

    TableTemplate<QString> table;
    table.addEntry("Fat");
    table.addEntry("Fruit");
    table.addEntry("Seeds");
    table.addEntry("Vegetables");
    table.addEntry("Minerals");
    table.addEntry("Meat");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseFuel()
{

    TableTemplate<QString> table;
    table.addEntry("Wood");
    table.addEntry("Coal");
    table.addEntry("Peat");
    table.addEntry("Dung");
    table.addEntry("Petroleum");
    table.addEntry("Wax");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseWrecks()
{

    TableTemplate<QString> table;
    table.addEntry("Sea Vehicle: " + choseSeaVehicle());
    table.addEntry("Land Vehicle: " + choseLandVehicle());
    table.addEntry("Air Vehicle: " + choseAirVehicle());
    table.addEntry("War Engine: " + choseWarEngine());
    table.addEntry("Submarine: " + choseSubmarine());
    table.addEntry("Subterranian: " + choseSubterranean());
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseSeaVehicle()
{

    TableTemplate<QString> table;
    table.addEntry("Raft");
    table.addEntry("Canoe");
    table.addEntry("Pig Bladder");
    table.addEntry("Longboat");
    table.addEntry("Merchant Ship");
    table.addEntry("Man O War");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseLandVehicle()
{

    TableTemplate<QString> table;
    table.addEntry("Sled");
    table.addEntry("Wagon");
    table.addEntry("Litter");
    table.addEntry("Carriage");
    table.addEntry("Wain");
    table.addEntry("Cariot");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseAirVehicle()
{

    TableTemplate<QString> table;
    table.addEntry("Baloon");
    table.addEntry("Wings");
    table.addEntry("Hang-Glider");
    table.addEntry("Unusual: " + choseUnusualAir());
    table.addEntry("Parachute");
    table.addEntry("Roc Carriage");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseWarEngine()
{

    TableTemplate<QString> table;
    table.addEntry("Onager");
    table.addEntry("Screw");
    table.addEntry("Ram");
    table.addEntry("Siege Tower");
    table.addEntry("Springal");
    table.addEntry("Catapult");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseSubmarine()
{

    TableTemplate<QString> table;
    table.addEntry("Dolphin sled");
    table.addEntry("Sea-horse carrage");
    table.addEntry("Giant Turtle house");
    table.addEntry("Diving bell");
    table.addEntry("Pocket");
    table.addEntry("Nuclear");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseSubterranean()
{

    TableTemplate<QString> table;
    table.addEntry("Mole Sled");
    table.addEntry("Rock Borer");
    table.addEntry("Mine Carg");
    table.addEntry("Earth Borer");
    table.addEntry("Worm Saddle");
    table.addEntry("Rat Chariot");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseSkeletons()
{

    TableTemplate<QString> table;
    table.addEntry("Small: " + choseSmallSkeleton());
    table.addEntry("Man-Size: " + choseManSizeSkeleton());
    table.addEntry("Giant: " + choseGiantSkeleton());
    table.addEntry("Unusual: " + choseUnusualSkeleton());
    table.addEntry("Skulls: " + choseSkulls());
    table.addEntry("Colossal: " + choseColossalSkeleton());
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseUnusualAir()
{

    TableTemplate<QString> table;
    table.addEntry("Propeller driven");
    table.addEntry("Jet");
    table.addEntry("Re-entry capsule");
    table.addEntry("Space Craft");
    table.addEntry("Helicopter");
    table.addEntry("Anti-grav");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseSmallSkeleton()
{

    TableTemplate<QString> table;
    table.addEntry("Miniscule");
    table.addEntry("Dwarven");
    table.addEntry("Pixie");
    table.addEntry("Gnome");
    table.addEntry("Kobold");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseManSizeSkeleton()
{

    TableTemplate<QString> table;
    table.addEntry("Human");
    table.addEntry("Elven");
    table.addEntry("Orc");
    table.addEntry("Troll");
    table.addEntry("Lizard Man");
    table.addEntry("Snake");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseGiantSkeleton()
{

    TableTemplate<QString> table;
    table.addEntry("Ogre");
    table.addEntry("Hobgoblin");
    table.addEntry("True Giant");
    table.addEntry("Dinosaur");
    table.addEntry("Sea Monster");
    table.addEntry("Whale");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseUnusualSkeleton()
{

    TableTemplate<QString> table;
    table.addEntry("Cubic");
    table.addEntry("Crystaline");
    table.addEntry("Multi-limbed");
    table.addEntry("Multi-headed");
    table.addEntry("Winged");
    table.addEntry("Armor-Plated");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseSkulls()
{

    TableTemplate<QString> table;
    table.addEntry("Miniscule");
    table.addEntry("Man-Size: " + choseManSizeSkeleton());
    table.addEntry("Giant: " + choseGiantSkeleton());
    table.addEntry("Colossal: " + choseColossalSkeleton());
    table.addEntry("Multi-horned");
    table.addEntry("Multi-Sockets");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseColossalSkeleton()
{

    TableTemplate<QString> table;
    table.addEntry("Humanoid");
    table.addEntry("Avian");
    table.addEntry("Reptilian");
    table.addEntry("Ursoid");
    table.addEntry("Amphibian");
    table.addEntry("Crustacean");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseAntiques()
{

    TableTemplate<QString> table;
    table.addEntry("Statues");
    table.addEntry("Furniture");
    table.addEntry("Engravings");
    table.addEntry("Idols");
    table.addEntry("Fittings");
    table.addEntry("Handicraft");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseStatues()
{

    TableTemplate<QString> table;
    table.addEntry("Miniature");
    table.addEntry("Half Size");
    table.addEntry("Life Size");
    table.addEntry("Giant Size");
    table.addEntry("Abstract");
    table.addEntry("Magic");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseFurniture()
{

    TableTemplate<QString> table;
    table.addEntry("Throne");
    table.addEntry("Chest");
    table.addEntry("Giantsize");
    table.addEntry("Miniature");
    table.addEntry("Stone Seat");
    table.addEntry("Stone Table");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseEngravings()
{

    TableTemplate<QString> table;
    table.addEntry("Battle Scene");
    table.addEntry("Croronation");
    table.addEntry("Punishment");
    table.addEntry("Religious");
    table.addEntry("Curse");
    table.addEntry("Romantic");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseIdols()
{

    TableTemplate<QString> table;
    table.addEntry("Stone");
    table.addEntry("Plaster");
    table.addEntry("Metal");
    table.addEntry("Wooden");
    return table.getRollTableEntry();
}

QString JGRavagedRuins::choseFittings()
{

    TableTemplate<QString> table;
    table.addEntry("Faucet");
    table.addEntry("Lamp");
    table.addEntry("Bell");
    table.addEntry("Fresco");
    table.addEntry("Hinges");
    table.addEntry("Knocker");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseHandicrafts()
{

    TableTemplate<QString> table;
    table.addEntry("Basket");
    table.addEntry("Vase");
    table.addEntry("Miniature Paining");
    table.addEntry("Abacas");
    table.addEntry("Ship's Figurehead");
    table.addEntry("Bust");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseArtifacts()
{

    TableTemplate<QString> table;
    table.addEntry("Weapon: " + choseWeapons());
    table.addEntry("Entertainment: " + choseEntertainment());
    table.addEntry("Protective Device: " + choseDefensiveDevice());
    table.addEntry("Offensive Device: " + choseOffensiveDevice());
    table.addEntry("Informative Device: " + choseInformativeDevice());
    table.addEntry("Leadership Device: " + choseLeadershipDevice());
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseWeapons()
{

    TableTemplate<QString> table;
    table.addEntry("Sword");
    table.addEntry("Dagger");
    table.addEntry("Hammer");
    table.addEntry("Club");
    table.addEntry("Battleaxe");
    table.addEntry("Javelin");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseEntertainment()
{

    TableTemplate<QString> table;
    table.addEntry("Animated");
    table.addEntry("Musical");
    table.addEntry("Dancing");
    table.addEntry("Serving");
    table.addEntry("Intensfying");
    table.addEntry("Dreaming");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseOffensiveDevice()
{

    TableTemplate<QString> table;
    table.addEntry("Hand");
    table.addEntry("Vase");
    table.addEntry("Eye");
    table.addEntry("Box");
    table.addEntry("Horn");
    table.addEntry("Vat");
    return table.getRollTableEntry();

}

QString JGRavagedRuins::choseDefensiveDevice()
{
    TableTemplate<QString> table;
    table.addEntry("Machine");
    table.addEntry("Staff");
    table.addEntry("Vial");
    table.addEntry("Garment");
    table.addEntry("Talisman");
    table.addEntry("Armor");
    return table.getRollTableEntry();
}

QString JGRavagedRuins::choseInformativeDevice()
{
    TableTemplate<QString> table;
    table.addEntry("Stone");
    table.addEntry("Flask");
    table.addEntry("Orb");
    table.addEntry("Diadem");
    table.addEntry("Crystal Ball");
    table.addEntry("Necklace");
    return table.getRollTableEntry();
}

QString JGRavagedRuins::choseLeadershipDevice()
{
    TableTemplate<QString> table;
    table.addEntry("Ring");
    table.addEntry("Gem");
    table.addEntry("Throne");
    table.addEntry("Rod");
    table.addEntry("Sword");
    table.addEntry("Sceptres");
    return table.getRollTableEntry();
}
