#include "loottables.h"

LootTables::LootTables()
{

}


QString LootTables::generateSpellbook(int tier)
{
    int qty;
    QString spells;
    if (tier == 1) {
        qty = Dice::roll(1,4) + 1;
        spells = "Cantrips:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(0) + ", ";
        }
        spells += "\n1st Level:\n";
        qty = Dice::roll(1,2);
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(1) + ", ";
        }
        qty = Dice::roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n2nd Level: \n";
        spells += wizardSpells(2);

        qty = Dice::roll(1,100);
        if (qty < 75) { return spells; }
        spells += "\n3rd Level: \n";
        spells += wizardSpells(3);

        return spells;
    }
    else if (tier == 2) {
        qty = Dice::roll(1,2);
        spells = "1st Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(1) + ", ";
        }

        qty = Dice::roll(1,4) + 1;
        spells += "\n2nd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(2) + ", ";
        }

        qty = Dice::roll(1,2) + 1;
        spells += "\n3rd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(3) + ", ";
        }

        spells += "\n4th Level:\n" +wizardSpells(4) + "\n";

        qty = Dice::roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n5th Level: \n";
        spells += wizardSpells(5);

        qty = Dice::roll(1,100);
        if (qty < 75) { return spells; }
        spells += "\n6th Level: \n";
        spells += wizardSpells(6);

        return spells;
    }
    else if (tier == 3) {
        qty = Dice::roll(1,2);
        spells = "3rd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(3) + ", ";
        }

        qty = Dice::roll(1,4) + 1;
        spells += "\n4th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(4) + ", ";
        }

        qty = Dice::roll(1,2) + 1;
        spells += "\n5th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(5) + ", ";
        }

        qty = Dice::roll(1,2);
        spells += "\n6th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(6) + ", ";
        }

        spells += "\n7th Level:\n" +wizardSpells(7) + "\n";

        qty = Dice::roll(1,2) - 1;
        qty = Dice::roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n8th Level: \n";
        spells += wizardSpells(8);

        return spells;
    }
    else {
        qty = Dice::roll(1,2);
        spells = "4rd Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(4) + ", ";
        }

        qty = Dice::roll(1,4) + 1;
        spells += "\n5th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(5) + ", ";
        }

        qty = Dice::roll(1,2) + 1;
        spells += "\n6th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(6) + ", ";
        }

        qty = Dice::roll(1,2);
        spells += "\n7th Level:\n";
        for (int i = 0; i < qty; ++i) {
            spells += wizardSpells(7) + ", ";
        }

        spells += "\n8th Level:\n" +wizardSpells(8) + "\n";

        qty = Dice::roll(1,100);
        if (qty < 50) { return spells; }
        spells += "\n9th Level: \n";
        spells += wizardSpells(9);

        return spells;
    }
}

QString LootTables::wizardSpells(int level)
{
    RandomTable table;

    if (level == 0) {
        table.addEntry("Acid Splash");
        table.addEntry("Blade Ward");
        table.addEntry("Chill Touch");
        table.addEntry("Dancing Lights");
        table.addEntry("Fire Bolt");
        table.addEntry("Friends");
        table.addEntry("Light");
        table.addEntry("Mage Hand");
        table.addEntry("Mending");
        table.addEntry("Message");
        table.addEntry("Minor Illusion");
        table.addEntry("Poison Spray");
        table.addEntry("Prestidigitation");
        table.addEntry("Ray of Frost");
        table.addEntry("Shocking Grasp");
        table.addEntry("True Strike");
        table.addEntry("Control Flames (XGE)");
        table.addEntry("Create bonfire (XGE)");
        table.addEntry("Frostbite (XGE)");
        table.addEntry("Gust (XGE)");
        table.addEntry("Infestation (XGE)");
        table.addEntry("Mold earth (XGE)");
        table.addEntry("Shape Water (XGE)");
        table.addEntry("Thunderclap (XGE)");
        table.addEntry("Toll the Dead (XGE)");
        table.addEntry("Booming blade (SCA)");
        table.addEntry("Green-flame blade (SCA)");
        table.addEntry("Lightning Lure (SCA)");
        table.addEntry("Sword Burst (SCA)");
    }
    else if (level ==1) {
        table.addEntry("Alarm");
        table.addEntry("Burning Hands");
        table.addEntry("Charm Person");
        table.addEntry("Chromatic Orb");
        table.addEntry("Color Spray");
        table.addEntry("Comprehend Languages");
        table.addEntry("Detect Magic", 3);
        table.addEntry("Disguise Self");
        table.addEntry("Expedius Retreat");
        table.addEntry("False Life");
        table.addEntry("Feather Fall");
        table.addEntry("Find Familiar");
        table.addEntry("Fog Cloud");
        table.addEntry("Grease");
        table.addEntry("Identify", 3);
        table.addEntry("Illusory Script");
        table.addEntry("Jump");
        table.addEntry("Logstrider");
        table.addEntry("Mage Armor");
        table.addEntry("Magic Missile");
        table.addEntry("Protection from Evil and Good");
        table.addEntry("Ray of Sickness");
        table.addEntry("Shield");
        table.addEntry("Silent Image");
        table.addEntry("Sleep");
        table.addEntry("Tasha's Hideous Laughter");
        table.addEntry("Tenser's Floating Disk");
        table.addEntry("Thunderwave");
        table.addEntry("Unseen Servant");
        table.addEntry("Witch Bolt");
        table.addEntry("Absorb Elements (XGE)");
        table.addEntry("Catapult (XGE)");
        table.addEntry("Cause Fear (XGE)");
        table.addEntry("Earth tremor (XGE)");
        table.addEntry("Ice Knife (XGE)");
        table.addEntry("Snare (XGE)");
    }
    else if (level == 2) {
        table.addEntry("Alter Self");
        table.addEntry("Arcane Lock");
        table.addEntry("Blindness/Deafness");
        table.addEntry("Blur");
        table.addEntry("Cloud of Daggers");
        table.addEntry("Continual Flame");
        table.addEntry("Crown of Madness");
        table.addEntry("Darkness");
        table.addEntry("Darkvision");
        table.addEntry("Detect Thoughts");
        table.addEntry("Enlarge/Reduce");
        table.addEntry("Flaming Sphere");
        table.addEntry("Gentle Repose");
        table.addEntry("Gust of Wind");
        table.addEntry("Hold Person");
        table.addEntry("Invisibility");
        table.addEntry("Knock");
        table.addEntry("Levitate");
        table.addEntry("Locate Object");
        table.addEntry("Magic Mouth");
        table.addEntry("Magic Weapon");
        table.addEntry("Melf's Acid Arrow");
        table.addEntry("Mirror Image");
        table.addEntry("Misty Step");
        table.addEntry("Nystul's Magic Aura");
        table.addEntry("Phantasmal Force");
        table.addEntry("Ray of Enfeeblement");
        table.addEntry("Rope Trick");
        table.addEntry("Scorching Ray");
        table.addEntry("See Invisibility");
        table.addEntry("Shatter");
        table.addEntry("Spider Climb");
        table.addEntry("Suggestion");
        table.addEntry("Web");
        table.addEntry("Aganazzar's Scorcher (XGE)");
        table.addEntry("Dragon's Breath (XGE)");
        table.addEntry("Dust Devil (XGE)");
        table.addEntry("Earthbind (XGE)");
        table.addEntry("Maximilian's Earthen Grasp (XGE)");
        table.addEntry("Mind Spike (XGE)");
        table.addEntry("Pyrotechnics (XGE)");
        table.addEntry("Shadow Blade (XGE)");
        table.addEntry("Skywrite (XGE)");
        table.addEntry("Snilloc's Snowball Swarm (XGE)");
        table.addEntry("Warding Wind (XGE)");
    }
    else if (level == 3) {
        table.addEntry("Animate Dead");
        table.addEntry("Bestow Curse");
        table.addEntry("Blink");
        table.addEntry("Clairvoyance");
        table.addEntry("Counterspell");
        table.addEntry("Dispel Magic");
        table.addEntry("Fear");
        table.addEntry("Feign Death");
        table.addEntry("Fireball");
        table.addEntry("Fly");
        table.addEntry("Gaseous Form");
        table.addEntry("Glyph of Warding");
        table.addEntry("Haste");
        table.addEntry("Hypnotic Pattern");
        table.addEntry("Leomund's Tiny Hut");
        table.addEntry("Lightning Bolt");
        table.addEntry("Magic Circle");
        table.addEntry("Major Image");
        table.addEntry("Nondetection");
        table.addEntry("Phantom Steed");
        table.addEntry("Protection from Energy");
        table.addEntry("Remove Curse");
        table.addEntry("Sending");
        table.addEntry("Sleet Storm");
        table.addEntry("Slow");
        table.addEntry("Stinking Cloud");
        table.addEntry("Tongues");
        table.addEntry("Vampiric Touch");
        table.addEntry("Water Breathing");
        table.addEntry("Catnap (XGE)");
        table.addEntry("Enemies Abound (XGE)");
        table.addEntry("Erupting Earth (XGE)");
        table.addEntry("Flame Arrows (XGE)");
        table.addEntry("Life Transference (XGE)");
        table.addEntry("Melf's Minute Meteors (XGE)");
        table.addEntry("Summon Lesser Demons (XGE)");
        table.addEntry("Thunder Step (XGE)");
        table.addEntry("Tidal Wave (XGE)");
        table.addEntry("Tiny Servant (XGE)");
        table.addEntry("Wall of Sand (XGE)");
        table.addEntry("Wall of Water (XGE)");
    }
    else if (level == 4) {
        table.addEntry("Arcane Eye");
        table.addEntry("Banishment");
        table.addEntry("Blight");
        table.addEntry("Confusion");
        table.addEntry("Conjure Minor Elementals");
        table.addEntry("Control Water");
        table.addEntry("Dimension Door");
        table.addEntry("Evard's Black Tentacles");
        table.addEntry("Fabricate");
        table.addEntry("Fire Shield");
        table.addEntry("Greater Invisibility");
        table.addEntry("Hallucinary Terrain");
        table.addEntry("Ice Storm");
        table.addEntry("Leomund's Secret Chest");
        table.addEntry("Locate Creature");
        table.addEntry("Mordenkainen's Faithful Hound");
        table.addEntry("Mordenkainen's Private Sanctum");
        table.addEntry("Otiluke's Resilient Sphere");
        table.addEntry("Phantasmal Killer");
        table.addEntry("Polymorph");
        table.addEntry("Stone Shape");
        table.addEntry("Stoneskin");
        table.addEntry("Wall of Fire");
        table.addEntry("Charm Monster (XGE)");
        table.addEntry("Elemental Bane (XGE)");
        table.addEntry("Sickening Radiance (XGE)");
        table.addEntry("Storm Sphere (XGE)");
        table.addEntry("Summon Greater Demon (XGE)");
        table.addEntry("Vitrolic Sphere (XGE)");
        table.addEntry("Watery Sphere (XGE)");
    }
    else if (level == 5) {

        table.addEntry("Animate Objects");
        table.addEntry("Bigby's Hand");
        table.addEntry("Cloudkill");
        table.addEntry("Cone of Cold");
        table.addEntry("Conjure Elemental");
        table.addEntry("Contact Other Plane");
        table.addEntry("Creation");
        table.addEntry("Dominate Person");
        table.addEntry("Dream");
        table.addEntry("Geas");
        table.addEntry("Hold Monster");
        table.addEntry("Legend Lore");
        table.addEntry("Mislead");
        table.addEntry("Modify Memory");
        table.addEntry("Passwall");
        table.addEntry("Planar Binding");
        table.addEntry("Rary's Telepathic Bond");
        table.addEntry("Scrying");
        table.addEntry("Seeming");
        table.addEntry("Telekinesis");
        table.addEntry("Teleportation Circle");
        table.addEntry("Wall of Force");
        table.addEntry("Wall of Stone");
        table.addEntry("Control Winds (XGE)");
        table.addEntry("Danse Macabre (XGE)");
        table.addEntry("Dawn (XGE)");
        table.addEntry("Enervation (XGE)");
        table.addEntry("Far Step (XGE)");
        table.addEntry("Immolation (XGE)");
        table.addEntry("Infernal Calling (XGE)");
        table.addEntry("Negative Energy Flood (XGE)");
        table.addEntry("Skill Empowerment (XGE)");
        table.addEntry("Steel Wind Strike (XGE)");
        table.addEntry("Synaptic Static (XGE)");
        table.addEntry("Transmute Rock (XGE)");
        table.addEntry("Wall of Light (XGE)");
    }
    else if (level == 6) {

        table.addEntry("Arcane Gate");
        table.addEntry("Chain Lightning");
        table.addEntry("Circle of Death");
        table.addEntry("Contingency");
        table.addEntry("Create Undead");
        table.addEntry("Disintegrate");
        table.addEntry("Drawmij's Instant Summons");
        table.addEntry("Eyebite");
        table.addEntry("Flesh to Stone");
        table.addEntry("Globe of Invulnerability");
        table.addEntry("Guards and Wards");
        table.addEntry("Magic Jar");
        table.addEntry("Mass Suggestion");
        table.addEntry("Move Earth");
        table.addEntry("Otiluke's Freezing Sphere");
        table.addEntry("Otto's Irresistible Dance");
        table.addEntry("Programmed Illusion");
        table.addEntry("Sunbeam");
        table.addEntry("True Seeing");
        table.addEntry("Wall of Ice");
        table.addEntry("Create Homonuculus (XGE)");
        table.addEntry("Investiture of Flame (XGE)");
        table.addEntry("Investiture of Ice (XGE)");
        table.addEntry("Investiture of Stone (XGE)");
        table.addEntry("Investiture of Wind (XGE)");
        table.addEntry("Mental Prison (XGE)");
        table.addEntry("Scatter (XGE)");
        table.addEntry("Soul Cage (XGE)");
        table.addEntry("Tenser's Transformation (XGE)");
    }
    else if (level == 7) {
        table.addEntry("Delayed Blast Fireball");
        table.addEntry("Etherealness");
        table.addEntry("Finger of Death");
        table.addEntry("Forcecage");
        table.addEntry("Mirage Arcana");
        table.addEntry("Mordenkainen's Magnificent Mansion");
        table.addEntry("Mordenkainen's Sword");
        table.addEntry("Plane Shift");
        table.addEntry("Prismatic Spray");
        table.addEntry("Project Image");
        table.addEntry("Reverse Gravity");
        table.addEntry("Sequester");
        table.addEntry("Simulacrum");
        table.addEntry("Symbol");
        table.addEntry("Teleport");
        table.addEntry("Crown of Stars (XGE)");
        table.addEntry("Power Word Pain (XGE)");
        table.addEntry("Whirlwind (XGE)");
    }
    else if (level == 8) {
        table.addEntry("Antimagic Field");
        table.addEntry("Antipathy/Sympathy");
        table.addEntry("Clone");
        table.addEntry("Control Weather");
        table.addEntry("Demiplane");
        table.addEntry("Dominate Monster");
        table.addEntry("Feeblemind");
        table.addEntry("Incendiary Cloud");
        table.addEntry("Maze");
        table.addEntry("Mind Blank");
        table.addEntry("Power Word Stun");
        table.addEntry("Sunburst");
        table.addEntry("Telepathy");
        table.addEntry("Trap the Soul");
        table.addEntry("Abi-Dalzim's Horrid Wilting (XGE)");
        table.addEntry("Illusory Dragon (XGE)");
        table.addEntry("Maddening Darkness (XGE)");
        table.addEntry("Mighty Fortress (XGE)");
    }
    else {
        table.addEntry("Astral Projection");
        table.addEntry("Foresight");
        table.addEntry("Gate");
        table.addEntry("Imprisonment");
        table.addEntry("Meteor Swarm");
        table.addEntry("Power Word Kill");
        table.addEntry("Prismatic Wall");
        table.addEntry("Shapechange");
        table.addEntry("Time Stop");
        table.addEntry("True Polymorph");
        table.addEntry("Weird");
        table.addEntry("Wish");
        table.addEntry("Invulnerability (XGE)");
        table.addEntry("Mass Polymorph (XGE)");
        table.addEntry("Psychic Scream (XGE)");
    }

    return table.getRollTableEntry();
}

QString LootTables::minorCommonMagicItems()
{
    RandomTable table;

    table.addEntry("Armor of gleaming");
    table.addEntry("Bead of nourishment");
    table.addEntry("Bead of refreshment");
    table.addEntry("Boots of false tracks");
    table.addEntry("Candle of the deep");
    table.addEntry("Cast-off armor");
    table.addEntry("Charlatan's die");
    table.addEntry("Cloak of billowing");
    table.addEntry("Cloak of many fashions");
    table.addEntry("Clockwork amulet");
    table.addEntry("Clothes of mending");
    table.addEntry("Dark shard amulet");
    table.addEntry("Dread helm");
    table.addEntry("Ear horn of hearing");
    table.addEntry("Enduring spellbook");
    table.addEntry("Ersatz eye");
    table.addEntry("Hat of vermin");
    table.addEntry("Hat of wizardry");
    table.addEntry("Heward's handy spice pouch");
    table.addEntry("Horn of silent alarm");
    table.addEntry("Instrument of illusions");
    table.addEntry("Instrument of scribing");
    table.addEntry("Lock of trickery");
    table.addEntry("Moon-touched sword");
    table.addEntry("Mystery key");
    table.addEntry("Orb of direction");
    table.addEntry("Orb of time");
    table.addEntry("Perfume of bewitching");
    table.addEntry("Pipe of smoke monsters");
    table.addEntry("Pole of angling");
    table.addEntry("Pole of collapsing");
    table.addEntry("Pot of awakening");
    table.addEntry("Potion of climbing (" + potionDescription() + ")");
    table.addEntry("Potion of healing (" + potionDescription() + ")", 10);
    table.addEntry("Rope of mending");
    table.addEntry("Ruby of the war mage");
    table.addEntry("Shield of expression");
    table.addEntry("Smoldering armor");
    table.addEntry("Spell scroll: " + wizardSpells(0), 4);
    table.addEntry("Spell scroll: " + wizardSpells(1), 4);
    table.addEntry("Staff of adornment");
    table.addEntry("Staff of birdcalls");
    table.addEntry("Staff of flowers");
    table.addEntry("Talking doll");
    table.addEntry("Tankard of sobriety");
    table.addEntry("Unbreakable arrow");
    table.addEntry("Veteran's cane");
    table.addEntry("Walloping ammunition");
    table.addEntry("Wand of conducting");
    table.addEntry("Wand of pyrotechnics");
    table.addEntry("Wand of scowls");
    table.addEntry("Wand of smiles");

    return table.getRollTableEntry() + " (minor, common)";
}

QString LootTables::minorUncommonMagicItems()
{
    RandomTable table;

    table.addEntry("Alchemy jug");
    table.addEntry("Ammunition +1");
    table.addEntry("Bag of holding");
    table.addEntry("Cap of water breathing");
    table.addEntry("Cloak of the manta ray");
    table.addEntry("Decanter of endless water");
    table.addEntry("Driftglobe");
    table.addEntry("Dust of disappearance");
    table.addEntry("Dust of dryness");
    table.addEntry("Dust of sneezing and choking");
    table.addEntry("Elemental gem");
    table.addEntry("Eyes of minute seeing");
    table.addEntry("Goggles of night");
    table.addEntry("Helm of comprehending languages");
    table.addEntry("Immovable rod");
    table.addEntry("Keoghtom's ointment");
    table.addEntry("Lantern of revealing");
    table.addEntry("Mariner's armor");
    table.addEntry("Mithral armor");
    table.addEntry("Oil of slipperiness");
    table.addEntry("Periapt of health");
    table.addEntry("Philter of love");
    table.addEntry("Potion of animal friendship (" + potionDescription() + ")");
    table.addEntry("Potion of fire breath(" + potionDescription() + ")");
    table.addEntry("Potion of greater healing (" + potionDescription() + ")", 10);
    table.addEntry("Potion of growth (" + potionDescription() + ")");
    table.addEntry("Potion of hill giant strength (" + potionDescription() + ")");
    table.addEntry("Potion of poison (" + potionDescription() + ")", 6);
    table.addEntry("Potion of resistance (" + potionDescription() + ")");
    table.addEntry("Potion of water breathing (" + potionDescription() + ")", 4);
    table.addEntry("Ring os swimming");
    table.addEntry("Robe of useful items");
    table.addEntry("Rope of climbing");
    table.addEntry("Saddle of the cavalier");
    table.addEntry("Sending stones");
    table.addEntry("Spell Scroll: " + wizardSpells(2), 4);
    table.addEntry("Spell Scroll: " + wizardSpells(3), 4);
    table.addEntry("Wand of magic detection");
    table.addEntry("Wand of secrets");

    return table.getRollTableEntry() + " (minor, uncommon)";
}

QString LootTables::minorRareMagicIterms()
{
    RandomTable table;

    table.addEntry("Ammunition +2");
    table.addEntry("Bag of beans");
    table.addEntry("Bead of force");
    table.addEntry("Chime of opening");
    table.addEntry("Elixer of health");
    table.addEntry("Folding boat");
    table.addEntry("Heward's handy haversack");
    table.addEntry("Horseshoes of speed");
    table.addEntry("Necklace of fireballs");
    table.addEntry("Oil of etherealness");
    table.addEntry("Portable hole");
    table.addEntry("Potion of clairvoyance (" + potionDescription() + ")");
    table.addEntry("Potion of diminution (" + potionDescription() + ")");
    table.addEntry("Potion of fire giant strength (" + potionDescription() + ")");
    table.addEntry("Potion of frost giant strength (" + potionDescription() + ")");
    table.addEntry("Potion of gaseous form (" + potionDescription() + ")");
    table.addEntry("Potion of heroism (" + potionDescription() + ")");
    table.addEntry("Potion of invulnerability (" + potionDescription() + ")");
    table.addEntry("Potion of mind reading (" + potionDescription() + ")");
    table.addEntry("Potion of stone giant strength (" + potionDescription() + ")");
    table.addEntry("Potion of superior healing (" + potionDescription() + ")", 6);
    table.addEntry("Quaal's feather token");
    table.addEntry("Scroll of protection", 4);
    table.addEntry("Spell scroll: " + wizardSpells(4), 4);
    table.addEntry("Spell scroll: " + wizardSpells(5), 4);

    return table.getRollTableEntry() + " (minor, Rare)";
}

QString LootTables::minorVeryRareMagicItems()
{
    RandomTable table;

    table.addEntry("Ammunition +3");
    table.addEntry("Arrow of slaying");
    table.addEntry("Bag of devouring");
    table.addEntry("Horseshoes of a zephyr");
    table.addEntry("Nolzur's marvelous pigments");
    table.addEntry("Oil of sharpness");
    table.addEntry("Potion of cloud giant strength (" + potionDescription() + ")");
    table.addEntry("Potion of flying (" + potionDescription() + ")");
    table.addEntry("Potion of invisibility (" + potionDescription() + ")");
    table.addEntry("Potion of longevity (" + potionDescription() + ")");
    table.addEntry("Potion of speed (" + potionDescription() + ")");
    table.addEntry("Potion of supreme healing (" + potionDescription() + ")");
    table.addEntry("Potion of vitality (" + potionDescription() + ")");
    table.addEntry("Spell scroll: " + wizardSpells(6));
    table.addEntry("Spell scroll: " + wizardSpells(7));
    table.addEntry("Spell scroll: " + wizardSpells(8));

    return table.getRollTableEntry() + " (minor, very rare)";
}

QString LootTables::minorLegendaryMagicItems()
{
    RandomTable table;

    table.addEntry("Potion of storm giant strength (" + potionDescription() + ")");
    table.addEntry("Sovereign glue");
    table.addEntry("Spell scroll: " + wizardSpells(9));
    table.addEntry("Universal solvent");

    return table.getRollTableEntry() + " (minor, legendary)";
}

QString LootTables::majorUncommonMagicItems()
{
    RandomTable table;

    table.addEntry("Adamantine armor");
    table.addEntry("Amulet of proof against detection and location");
    table.addEntry("Bag of tricks");
    table.addEntry("Boots of elvenkind");
    table.addEntry("Boots of striding and springing");
    table.addEntry("Boots of the winterlands");
    table.addEntry("Bracers of archery");
    table.addEntry("Brooch of shielding");
    table.addEntry("Broom of flying");
    table.addEntry("Circlet of blasting");
    table.addEntry("Cloak of elvenkind");
    table.addEntry("Cloak of protection");
    table.addEntry("Deck of illusions");
    table.addEntry("Eversmoking bottle");
    table.addEntry("Eyes of charming");
    table.addEntry("Eyes of the eagle");
    table.addEntry("Figurine of wonderous power (silver raven)");
    table.addEntry("Gauntlets of ogre power");
    table.addEntry("Gem of brightness");
    table.addEntry("Gloves of missile sharing");
    table.addEntry("Gloves of swimming and climbing");
    table.addEntry("Gloves of thievery");
    table.addEntry("Hat of disguise");
    table.addEntry("Headband of intellect");
    table.addEntry("Helm of telepathy");
    table.addEntry("Instrument of the bards (Doss lute)");
    table.addEntry("Instrument of the bards (Fochlucan bandore)");
    table.addEntry("Instrument of the bards (Mac-Fulmidh cittern)");
    table.addEntry("Javelin of lightning");
    table.addEntry("Medallion of thoughts");
    table.addEntry("Necklace of adaptation");
    table.addEntry("Pearl of power");
    table.addEntry("Periapt of wound closure");
    table.addEntry("Pipes of haunting");
    table.addEntry("Pipes of the sewers");
    table.addEntry("Quiver of Ehlonna");
    table.addEntry("Ring of jumping");
    table.addEntry("Ring of mind shielding");
    table.addEntry("Ring of warmth");
    table.addEntry("Ring of water walking");
    table.addEntry("Rod of the pact keeper +1");
    table.addEntry("Sentinel shield");
    table.addEntry("Shield +1", 8);
    table.addEntry("Slippers of spider climbing");
    table.addEntry("Staff of the adder");
    table.addEntry("Staff of the python");
    table.addEntry("Stone of good luck (luckstone)");
    table.addEntry("Sword of vengeance");
    table.addEntry("Trident of fish command");
    table.addEntry("Wand of magic missiles");
    table.addEntry("Wand of the war mage +1");
    table.addEntry("Wand of web");
    table.addEntry("Weapon of warning");
    table.addEntry("Weapon +1", 8);
    table.addEntry("Wind fan");
    table.addEntry("Winged boots");

    return table.getRollTableEntry() + " (major, uncommon)";
}

QString LootTables::majorRareMagicItems()
{
    RandomTable table;

    table.addEntry("Amulet of health");
    table.addEntry("Armor of resistance");
    table.addEntry("Armor of vulnerability");
    table.addEntry("Armor +1", 8);
    table.addEntry("Arrow-catching shield");
    table.addEntry("Belt of dwarvenkind");
    table.addEntry("Belt of hill giant strength");
    table.addEntry("Berserker axe");
    table.addEntry("Boots of levitation");
    table.addEntry("Boots of speed");
    table.addEntry("Bowl of commanding water elementals");
    table.addEntry("Bracers of defense");
    table.addEntry("Brazier of commanding fire elementals");
    table.addEntry("Cape of the mountainbank");
    table.addEntry("Censer of controlling air elementals");
    table.addEntry("Cloak of displacement");
    table.addEntry("Cloak of the bat");
    table.addEntry("Cube of force");
    table.addEntry("Daern's instant fortress");
    table.addEntry("Dagger of venom");
    table.addEntry("Dimensional shackles");
    table.addEntry("Dragon slayer");
    table.addEntry("Elven chain");

    RandomTable figureTable;
    figureTable.addEntry("bronze griffon");
    figureTable.addEntry("ebony fly");
    figureTable.addEntry("golden lion");
    figureTable.addEntry("evory goats");
    figureTable.addEntry("marble elephant");
    figureTable.addEntry("onyx dog");
    figureTable.addEntry("serpentine owl");

    QString figure = table.getRollTableEntry();

    table.addEntry("Figurine of wonderous power (" + figure + ")");
    table.addEntry("Flame tongue");
    table.addEntry("Gem of seeing");
    table.addEntry("Giant slayer");
    table.addEntry("Glamoured studded leather");
    table.addEntry("Helm of teleportation");
    table.addEntry("Horn of blasting");
    table.addEntry("Horn of Valhalla, Silver");
    table.addEntry("Horn of Valhalla, Brass");
    table.addEntry("Instrument of the bards (Cli lyrre)");
    table.addEntry("Instrument of the bards (Canaith mandolin)");
    table.addEntry("Ioun stone (awareness)");
    table.addEntry("Ioun stone (protection)");
    table.addEntry("Ioun stone (sustenance)");
    table.addEntry("Ioun stone (reserve)");
    table.addEntry("Ioun bands of Bilarro");
    table.addEntry("Mace of disruption");
    table.addEntry("Mace of smiting");
    table.addEntry("Mace of terror");
    table.addEntry("Mantle of spell resistance");
    table.addEntry("Necklace of prayer beads");
    table.addEntry("Periapt of proof aginst poison");
    table.addEntry("Ring of animal influence");
    table.addEntry("Ring of evasion");
    table.addEntry("Ring of feather falling");
    table.addEntry("Ring of free aciton");
    table.addEntry("Ring of protection");
    table.addEntry("Ring of resistance");
    table.addEntry("Ring of spell storing");
    table.addEntry("Ring of the ram");
    table.addEntry("Ring of X-ray vision");
    table.addEntry("Robe of eyes");
    table.addEntry("Rod of rulership");
    table.addEntry("Rod of the pact keeper +2");
    table.addEntry("Rope of entanglement");
    table.addEntry("Shield of missile attraction");
    table.addEntry("Shield +2", 8);
    table.addEntry("Staff of charming");
    table.addEntry("Staff of healing");
    table.addEntry("Staff of swarming insects");
    table.addEntry("Staff of the woodlands");
    table.addEntry("Staff of withering");
    table.addEntry("Stone of controlling earth elementals");
    table.addEntry("Sun blade");
    table.addEntry("Sword of life stealing");
    table.addEntry("Sword of wounding");
    table.addEntry("Tentacle rod");
    table.addEntry("Vicious weapon");
    table.addEntry("Wand of binding");
    table.addEntry("Wand of enemy detection");
    table.addEntry("Wand of fear");
    table.addEntry("Wand of fireballs");
    table.addEntry("Wand of lightning bolts");
    table.addEntry("Wand of paralysis");
    table.addEntry("Wand of the war mage +2");
    table.addEntry("Wand of wonder");
    table.addEntry("Weapon +2", 8);
    table.addEntry("Wings of flying");

    return table.getRollTableEntry() + " (major, rare)";
}

QString LootTables::majorVeryRareMagicItems()
{
    RandomTable table;

    table.addEntry("Amulet of the planes");
    table.addEntry("Animated shield");
    table.addEntry("Armor +2", 8);
    table.addEntry("Belt of fire giant strength");
    table.addEntry("Belt of frost giant strength");
    table.addEntry("Belt of stone giant strength");
    table.addEntry("Candle of invocation");
    table.addEntry("Carpet of flying");
    table.addEntry("Cloak of arachnida");
    table.addEntry("Crystal ball (very rare)");
    table.addEntry("Dancing sword");
    table.addEntry("Demon armor");
    table.addEntry("Dragon scale mail");
    table.addEntry("Dwarven plate");
    table.addEntry("Dwarven thrower");
    table.addEntry("Efreeti bottle");
    table.addEntry("Figurine of wondrous power (obsidian steed)");
    table.addEntry("Frost brand");
    table.addEntry("Helm of brilliance");
    table.addEntry("Horn of Valhalla (bronze)");
    table.addEntry("Instrument of the bards (Anstruth harp)");

    RandomTable iounTable;

    iounTable.addEntry("absorption");
    iounTable.addEntry("agility");
    iounTable.addEntry("fortitude");
    iounTable.addEntry("insight");
    iounTable.addEntry("intellect");
    iounTable.addEntry("leadership");
    iounTable.addEntry("strength");

    QString ioun = iounTable.getRollTableEntry();

    table.addEntry("Ioun stone (" + ioun + ")", 4);
    table.addEntry("Manual of bodily health");
    table.addEntry("Manual of gainful exercise");
    table.addEntry("Manual of golems");
    table.addEntry("Manual of quickness of action");
    table.addEntry("Mirror of life trapping");
    table.addEntry("Nine lives stealer");
    table.addEntry("Oathbow");
    table.addEntry("Ring of regenration");
    table.addEntry("Ring of shooting stars");
    table.addEntry("Ring of telekinesis");
    table.addEntry("Robe of scintillating colors");
    table.addEntry("Robe of stars");
    table.addEntry("Rod of absorption");
    table.addEntry("Rod of alertness");
    table.addEntry("Rod of security");
    table.addEntry("Rod of the pact keeper +3");
    table.addEntry("Scimitar of speed");
    table.addEntry("Shield +3", 8);
    table.addEntry("Spellguard shield");
    table.addEntry("Staff of fire");
    table.addEntry("Staff of fire");
    table.addEntry("Staff of frost");
    table.addEntry("Staff of power");
    table.addEntry("Staff of striking");
    table.addEntry("Staff of thunder and lightning");
    table.addEntry("Sword of sharpness");
    table.addEntry("Tome of clear thought");
    table.addEntry("Tome of leadership and influence");
    table.addEntry("Tome of understanding");
    table.addEntry("Wand of plymorph");
    table.addEntry("Wand of the war mage +3");
    table.addEntry("Weapon +3", 8);

    return table.getRollTableEntry() + " (major, very rare)";
}

QString LootTables::majorLegendaryMagicItems()
{
    RandomTable table;

    table.addEntry("Apparatus of Kwalish");
    table.addEntry("Armor of invulnerability");
    table.addEntry("Armor +3", 8);
    table.addEntry("Belt of cloud giant strength");
    table.addEntry("Belt of storm giant strength");
    table.addEntry("Cloak of invisibility");
    table.addEntry("Crystal ball (legendary)");
    table.addEntry("Cubic gate");
    table.addEntry("Deck of many things");
    table.addEntry("Defender");
    table.addEntry("Efreeti chain");
    table.addEntry("Hammer of thunderbolts");
    table.addEntry("Holy avenger");
    table.addEntry("Horn of Valhalla (Iron)");
    table.addEntry("Instrument of the bards (Ollamh harp)");
    table.addEntry("Ioun stone (mastery)");
    table.addEntry("Ioun stone (regeneration)");
    table.addEntry("Iron flask");
    table.addEntry("Luck blade");
    table.addEntry("Plate armor of etherealness");
    table.addEntry("Ring of air elemental command");
    table.addEntry("Ring of djinni summoning");
    table.addEntry("Ring of earth elemental command");
    table.addEntry("Ring of fire elemental command");
    table.addEntry("Ring of invisibility");
    table.addEntry("Ring of spell turning");
    table.addEntry("Ring of three wishes ");
    table.addEntry("Ring of water elemental command");
    table.addEntry("Robe of the archmagi");
    table.addEntry("Rod of lordly might");
    table.addEntry("Rod of resurrection");
    table.addEntry("Scarab of protection");
    table.addEntry("Sphere of annihilation");
    table.addEntry("Staff of the magi");
    table.addEntry("Sword of answering");
    table.addEntry("Talisman of pure good");
    table.addEntry("Talisman of the sphere");
    table.addEntry("Talisman of ultimate evil");
    table.addEntry("Tome of the stilled tongue");
    table.addEntry("Vorpal sword");
    table.addEntry("Well of many worlds");

    return table.getRollTableEntry() + " (major, legendary)";
}

QString LootTables::selectMagicItemByTier(int tier)
{
    RandomTable table;

    if (tier == 1) {
        table.addEntry(minorCommonMagicItems(), 24); // A
        table.addEntry(minorUncommonMagicItems(), 15); // B
        table.addEntry(minorRareMagicIterms(), 10); // C
        table.addEntry(majorUncommonMagicItems(), 12); // F
        table.addEntry(majorRareMagicItems(), 3); // G
    }
    else if (tier == 2) {
        table.addEntry(minorCommonMagicItems(), 16); // A
        table.addEntry(minorUncommonMagicItems(), 19); // B
        table.addEntry(minorRareMagicIterms(), 11); // C
        table.addEntry(minorVeryRareMagicItems(), 6); // D
        table.addEntry(majorUncommonMagicItems(), 14); // F
        table.addEntry(majorRareMagicItems(), 4); // G
        table.addEntry(majorVeryRareMagicItems(), 2); // H
    }
    else if (tier == 3) {
        table.addEntry(minorCommonMagicItems(), 14); // A
        table.addEntry(minorUncommonMagicItems(), 14); // B
        table.addEntry(minorRareMagicIterms(), 21); // C
        table.addEntry(minorVeryRareMagicItems(), 11); // D
        table.addEntry(minorLegendaryMagicItems(), 8); // E
        table.addEntry(majorRareMagicItems(), 8); // G
        table.addEntry(majorVeryRareMagicItems(), 10); // H
        table.addEntry(majorLegendaryMagicItems(), 8); // I
    }
    else {
        table.addEntry(minorRareMagicIterms(), 12); // C
        table.addEntry(minorVeryRareMagicItems(), 31); // D
        table.addEntry(minorLegendaryMagicItems(), 22); // E
        table.addEntry(majorRareMagicItems(), 3); // G
        table.addEntry(majorVeryRareMagicItems(), 8); // H
        table.addEntry(majorLegendaryMagicItems(), 20); // I
    }
    QString creator = itemCreator();
    QString history = itemHistory();
    QString item = table.getRollTableEntry();

    return "MAGIC ITEM: " + item + "\n" + creator + "\n" + history;


}

QString LootTables::itemCreator()
{
    RandomTable table;

    table.addEntry("Aberration. The item was created by aberrations "
                   "in ancient times, possibly for hte use of favored "
                   "humanoid thralls. When seen from the corner of "
                   "the eye, the item seems to be moving.");
    table.addEntry("Human. The item was created during the heyday of "
                   "a fallen human kingdom, or it is tied to a human of "
                   "legend. It might hold writing in a forgotten tongue "
                   "or symbols whose significance is lost to the ages.",
                   3);
    table.addEntry("Celestial. The weapon is half the normal weight "
                   "and inscribed with feathered wings, suns, and "
                   "other symbols of good. Fiends find the item's "
                   "presence repulsive.");
    table.addEntry("Dragon. This item is made from scales and talons "
                   "shed by a dragon. Perhaps it incorporates precious "
                   "metals and gems from the dragon's hoard. It grows "
                   "slightly warm when within 120 feet of a dragon.");
    table.addEntry("Drow. The item is half the normal weight. It is "
                   "black and inscribed with spiders and webs in honor "
                   "of Lolth. It might function poorly, or disintegrate, if "
                   "exposed to sunlight for 1 minute or more.");
    table.addEntry("Dwarf. The item is durable and has Dwarven runes "
                   "worked into its design. It might be associated with "
                   "a clan that would like to see it returned to their "
                   "ancestral halls.", 2);
    table.addEntry("Elemental Air. The item is half the normal weight "
                   "and feels hollow. If it's made of fabric, it is "
                   "diaphanous.");
    table.addEntry("Elemental Earth. The item might be crafted from stone. "
                   "Any cloth or leather elements are studded with finely "
                   "polished rock.");
    table.addEntry("Elemental fire. This item is warm to the touch, "
                   "and any metal parts are crafted from black iron. "
                   "Sigils of flames cover its surface. Shades of red and "
                   "orange are the prominent colors.");
    table.addEntry("Elemental Water. Lustrou fish scales replace "
                   "leather or cloth on this item, and metal portions "
                   "are instead crafted from seashells and worked coral "
                   "as hard as any metal.");
    table.addEntry("Elf, The item is half the normal weight. It is "
                   "adorned with symbols of nature: leaves, vines, stars, and "
                   "the like.", 2);
    table.addEntry("Fey. The item is exquisitely crafted from the "
                   "finest materials and glows with a pale radieance in "
                   "moonlight, shedding dim light in a 5-foot radius. "
                   "Any metal in the item is silver or mithral, rather "
                   "than iron or steel.");
    table.addEntry("Fiend. The item is made of black iron or horn "
                   "inscribed with runes, and any cloth of leather "
                   "components are crafted from the hide of fiends. It "
                   "is warm to the touch and features leering faces or "
                   "vile runes engraved on its surface. Celestials find the "
                   "item's presence repulsive.");
    table.addEntry("Giant. The item is larger than normal and was "
                   "crafter by giants for use by their smaller allies.");
    table.addEntry("Gnome. The item is crafted to appear ordinary and "
                   "it might look worn. It could also incorporate gears "
                   "and mechanical components, even if these aren't "
                   "essential to the item's function.");
    table.addEntry("Undead. The item incorporates imagery of death, "
                   "such a bones and skulls, and it might be crafted from "
                   "parts of corpses. It feels cold to the touch.");
    table.addEntry("Modern. The item is forged of exceptional quality and "
                   "craftsmanship. It bears a maker's mark. Research would "
                   "lead one to a master craftsman, who created the item for "
                   "a wizard to enchant. This wizard might be interested to "
                   "learn the fate of the item they created.");
    table.addEntry("Nondescript. The item looks like any other mundane item "
                   "of its type. Only when it is put to use is its nature "
                   "exposed.");

    return table.getRollTableEntry();
}

QString LootTables::itemHistory()
{
    RandomTable table;

    table.addEntry("Arcane. This item was created for an ancient order "
                   "of spellcasters and bears the order's symbol.");
    table.addEntry("Bane. This item was created by the foes of a "
                   "particular culture or kind of creature. if the culture "
                   "or creatures are still around, they might recognize "
                   "the item and single out the bearer as an enemy.");
    table.addEntry("Heroic. A great hero once wielded this item. "
                   "Anyone who's familiar with the item's history "
                   "expects great deeds from the new owner.");
    table.addEntry("Ornament. The item was created to honor a special "
                   "occasion. Inset gemstones, gold or platinum "
                   "inlays, and gold or silver filigree adorn its surface.");
    table.addEntry("Prophecy. The item features in a prophecy: its "
                   "bearer is destined to play a key role in future "
                   "events. Someone wles who wants to play that role "
                   "might try to steal the item, or someone who wnats "
                   "to prevent the prophecy from being fulfilled might "
                   "try to kill the item's bearer.");
    table.addEntry("Religious. This item was used in religious "
                   "ceremonies dedicated to a particular deity. It has "
                   "holy symbols worked into it. The god's followers "
                   "might try to persuade its owner to donate it to a "
                   "temple, steal the tiem for themselves, or celebrate "
                   "its use by a cleric or paladin of the same deity.");
    table.addEntry("Sinister. This item is linked to a deed of great evil, "
                   "such as a massacre or an assassination. It might have a "
                   "name or be closely associated with a villain "
                   "who used it. Anyone familiar with the item's history "
                   "is likely to treat it an its owner with suspicion.");
    table.addEntry("Symbol of Power. This item was once used as part "
                   "of royal regalia or as a badge of high office. Its "
                   "former owner or that paerson's descendants might "
                   "desire it, or someone might mistakenly assume its "
                   "new owner is the item's legitimate inheritor.");
    table.addEntry("Brand new. This item was recently created, and hasn't "
                   "seen much in the way of action.");
    table.addEntry("Formula for creating the item, instead of the item itself. "
                   "The formula is written in a manuscript that reflects the "
                   "language and traits of the creator.");

    return table.getRollTableEntry();
}

QString LootTables::potionDescription()
{
    RandomTable consistencyTable;
    consistencyTable.addEntry("bubbling");
    consistencyTable.addEntry("cloudy");
    consistencyTable.addEntry("effervescent");
    consistencyTable.addEntry("fuming");
    consistencyTable.addEntry("oily");
    consistencyTable.addEntry("smoky");
    consistencyTable.addEntry("syrupy");
    consistencyTable.addEntry("vaporous");
    consistencyTable.addEntry("viscous");
    consistencyTable.addEntry("watery");

    RandomTable transpearencyTable;
    transpearencyTable.addEntry("clear");
    transpearencyTable.addEntry("flecked");
    transpearencyTable.addEntry("layered");
    transpearencyTable.addEntry("luminous");
    transpearencyTable.addEntry("glowing");
    transpearencyTable.addEntry("phosphorescent");
    transpearencyTable.addEntry("rainbowed");
    transpearencyTable.addEntry("ribboned");
    transpearencyTable.addEntry("translucent");
    transpearencyTable.addEntry("varegated");


    return consistencyTable.getRollTableEntry() + ", "
            + transpearencyTable.getRollTableEntry() + ", "
            + color();
}

QString LootTables::color()
{
    RandomTable colorTable;
    colorTable.addEntry("brassy");
    colorTable.addEntry("bronze");
    colorTable.addEntry("coppery");
    colorTable.addEntry("gold");
    colorTable.addEntry("silvery");
    colorTable.addEntry("steely");
    colorTable.addEntry("fuchsia");
    colorTable.addEntry("heliotrope");
    colorTable.addEntry("lake");
    colorTable.addEntry("lavender");
    colorTable.addEntry("lilac");
    colorTable.addEntry("magenta");
    colorTable.addEntry("mauve");
    colorTable.addEntry("plum");
    colorTable.addEntry("puce");
    colorTable.addEntry("purple");
    colorTable.addEntry("bone-white");
    colorTable.addEntry("colorless");
    colorTable.addEntry("ivory");
    colorTable.addEntry("pearl");
    colorTable.addEntry("amber");
    colorTable.addEntry("citrine");
    colorTable.addEntry("cream");
    colorTable.addEntry("flaxen");
    colorTable.addEntry("ochre");
    colorTable.addEntry("peach");
    colorTable.addEntry("saffron");
    colorTable.addEntry("straw");
    colorTable.addEntry("dove");
    colorTable.addEntry("dun");
    colorTable.addEntry("carmine");
    colorTable.addEntry("cerise");
    colorTable.addEntry("cherry");
    colorTable.addEntry("cinnabar");
    colorTable.addEntry("coral");
    colorTable.addEntry("crimson");
    colorTable.addEntry("madder");
    colorTable.addEntry("maroon");
    colorTable.addEntry("pink");
    colorTable.addEntry("rose");
    colorTable.addEntry("ruby");
    colorTable.addEntry("russet");
    colorTable.addEntry("rust");
    colorTable.addEntry("sanguine");
    colorTable.addEntry("scarlet");
    colorTable.addEntry("vermillion");
    colorTable.addEntry("chocolate");
    colorTable.addEntry("mahogany");
    colorTable.addEntry("tan");
    colorTable.addEntry("terra cotta");
    colorTable.addEntry("aquamarine");
    colorTable.addEntry("emerald");
    colorTable.addEntry("olive");
    colorTable.addEntry("azure");
    colorTable.addEntry("cerulean");
    colorTable.addEntry("indigo");
    colorTable.addEntry("sapphire");
    colorTable.addEntry("turquoise");
    colorTable.addEntry("ultramarine");
    colorTable.addEntry("ebony");
    colorTable.addEntry("inky");
    colorTable.addEntry("pitchy");
    colorTable.addEntry("sable");
    colorTable.addEntry("sooty");
    colorTable.addEntry("apricot");
    colorTable.addEntry("flame");
    colorTable.addEntry("golden");
    colorTable.addEntry("salmon");
    colorTable.addEntry("tawny");

    return colorTable.getRollTableEntry();
}

QString LootTables::gem(int tier)
{
   RandomTable table;
   if (tier == 1) {

       QString value =  (_lowHauls)? " (10 sp)" : " (10 gp)";

       table.addEntry("Azurite (opaque mottled deep blue)" + value);
       table.addEntry("Banded agate (translucent striped brown, blue, white or red)" + value);
       table.addEntry("Blue quartz (transparent pale blue)" + value);
       table.addEntry("Eye agate (translucent circles of gray, white, brown, blue, or green)" + value);
       table.addEntry("Hematite (opaque gray-black)" + value);
       table.addEntry("Lapis lazuli (opaque light and ddark blue with yellow flecks)" + value);
       table.addEntry("Malachite (opaque striated light and dark green)" + value);
       table.addEntry("Moss agate (translucent pink or yellow-white with mossy gray or green markings)" + value);
       table.addEntry("Obsidian (opaque black)" + value);
       table.addEntry("Rhodochrosite (opaque light pink)" + value);
       table.addEntry("Tiger eye (translucent brown with golden center)" + value);
       table.addEntry("Turquoise (opaque light blue-green)" + value);
   }

   if (tier == 1 || tier == 2) {

       QString value =  (_lowHauls)? " (50 sp)" : " (50 gp)";

       table.addEntry("Bloodstone (opaque dark gray with red flecks)" + value);
       table.addEntry("Carnelian (opaque orange to red-brown)" + value);
       table.addEntry("Chalcedony (opaque white)" + value);
       table.addEntry("Citrine (transparent pale yellow-brown)" + value);
       table.addEntry("Moonstone (translucent white with pale blue glow)" + value);
       table.addEntry("Onyx (opaque bands of black and white, or pure black or white)" + value);
       table.addEntry("Quartz (transparent white, smoky gray, or yellow)" + value);
       table.addEntry("Sardonyx (opaque bands of red and white)" + value);
       table.addEntry("Star rose quartz (translucent rosy stone with white star-shabed center)" + value);
       table.addEntry("Zicron (transparent pale blue-green)" + value);
   }

   if (tier == 2) {

       QString value =  (_lowHauls)? " (100 sp)" : " (100 gp)";

       table.addEntry("Amber (transparent watery gold to rich gold)" + value);
       table.addEntry("Amethyst (transparent deep purple)" + value);
       table.addEntry("Chrysoberyl (transparent yellow-green to pale green)" + value);
       table.addEntry("Coral (opaque crimson)" + value);
       table.addEntry("Garnet (transparent red, brown-green, or violet)" + value);
       table.addEntry("Jade (translucent light green, deep green, or white)" + value);
       table.addEntry("Jet (opaque deep black)" + value);
       table.addEntry("Pearl (opaque lustrous white, yellow, or pink)" + value);
       table.addEntry("Spinel (transparent red, red-brown, or deep green)" + value);
       table.addEntry("Tourmaline (tranparent pale green, blue, brown, or red)" + value);
   }

   if (tier == 3) {

       QString value =  (_lowHauls)? " (500 sp)" : " (500 gp)";

       table.addEntry("Alexandrite (transparent dark green)" + value);
       table.addEntry("Aquamarine (transparent pale blue-green)" + value);
       table.addEntry("Black pearl (opaque pure black)" + value);
       table.addEntry("Blue spinel (transparent deep blue)" + value);
       table.addEntry("Peridot (transparent rich olive green)" + value);
       table.addEntry("Topaz (transparent golden yellow)" + value);
   }

   if (tier == 3 || tier == 4) {

       QString value =  (_lowHauls)? " (1000 sp)" : " (1000 gp)";

       table.addEntry("Black opal (translucent dark green with black mottling and golden flecks)" + value);
       table.addEntry("Blue sapphire (transparent blue-white to medium blue)" + value);
       table.addEntry("Emerald (transparent deep bright green)" + value);
       table.addEntry("Fire opal (translucent firey red)" + value);
       table.addEntry("Opal (translucent pale blue with green and golden mottling)" + value);
       table.addEntry("Star ruby (translucent ruby with white star-shaped center)" + value);
       table.addEntry("Star sapphire (translucent blue sapphire with white star-shaped cenger)" + value);
       table.addEntry("Yellow sapphire (transparent fiery yellow or yellow green)" + value);
   }

   if (tier == 4) {

       QString value =  (_lowHauls)? " (5000 sp)" : " (5000 gp)";

       table.addEntry("Black sapphire (translucent lustrous black with glowing highlights)" + value);
       table.addEntry("Diamond (transparent blue-white, canary, pink, brown, or blue)" + value);
       table.addEntry("Jacinth (transparent firey orange)" + value);
       table.addEntry("Ruby (transparent clear red to deep crimson)" + value);
   }

   return table.getRollTableEntry();
}

QString LootTables::art(int tier)
{
    RandomTable table;

    if (tier == 1 || tier == 2) {
        QString value = (_lowHauls)? " (25 sp)" : " (25 gp)";

        table.addEntry("Selver ewer" + value);
        table.addEntry("Carved bone statuette" + value);
        table.addEntry("Small gold bracelet" + value);
        table.addEntry("Cloth-of-gold vestments" + value);
        table.addEntry("Black velvet mask stitched with silver thread" + value);
        table.addEntry("Copper chalice with silver filigree" + value);
        table.addEntry("Pair of engraved bone dice" + value);
        table.addEntry("Small mirror set in a painted wooden frame" + value);
        table.addEntry("Embroidered silk handkerchief" + value);
        table.addEntry("Gold locket with a painted portrait inside" + value);
        table.addEntry("Silver ring set with " + gem(1) + value);
        table.addEntry("Plain gold pendant" + value);
        table.addEntry("Small marble statuette" + value);
        table.addEntry("Large silver bracelet" + value);
        table.addEntry("Copper circlet" + value);
        table.addEntry("Box of expertly crafted, mahogany game pieces" + value);
        table.addEntry("Antique copper sword, etched with old runes" + value);
        table.addEntry("Silver arrow or bolt");
    }

    if (tier == 2 || tier == 3) {
        QString value = (_lowHauls)? " (250 sp)" : " (250 gp)";

        table.addEntry("Gold ring set with bloodstones" + value);
        table.addEntry("Carved ivory statuette" + value);
        table.addEntry("Large gold bracelet" + value);
        table.addEntry("Silver necklace with a gemstone pendant" + value);
        table.addEntry("Bronze crown" + value);
        table.addEntry("Silk robe with gold embroidery" + value);
        table.addEntry("Large well-made tapestry" + value);
        table.addEntry("Brass mug with jade inlay" + value);
        table.addEntry("Box of turquoise animal figurines" + value);
        table.addEntry("Gold bird cage with electrum filigree" + value);
        table.addEntry("Silvered Dagger");
    }

    if (tier == 3) {
        QString value =(_lowHauls)? " (750 sp)" :  " (750 gp)";

        table.addEntry("Silver chalice set with moonstones" + value);
        table.addEntry("Silver-plated steel longsword with jet set in hilt" + value);
        table.addEntry("Carved harp of exotic wood with ivory inlay and zicron gems" + value);
        table.addEntry("Small gold idol" + value);
        table.addEntry("Gold dragon comb set with red garnets as eyes" + value);
        table.addEntry("Bottle stopper cork embossed with gold leaf and set with amethysts" + value);
        table.addEntry("Ceremonial electrum dagger with a black pearl in the pommel" + value);
        table.addEntry("Silver and gold brooch" + value);
        table.addEntry("Obsidian statuette with gold fittings and inlay" + value);
        table.addEntry("Painted gold war mask" + value);
        table.addEntry("Silvered short sword");
        table.addEntry("Quiver of 20 silvered arrows or bolts");
    }

    if (tier == 4) {
        QString value = (_lowHauls)? " (2500 sp)" : " (2500 gp)";

        table.addEntry("Fine gold chain set with a fire opal" + value);
        table.addEntry("Old masterpiece painting" + value);
        table.addEntry("Embroidered silk and velvet mantle set with numerous moonstones" + value);
        table.addEntry("Platinum bracelet set with a sapphire" + value);
        table.addEntry("Embroidered glove set with jewel chips" + value);
        table.addEntry("Jeweled anklet" + value);
        table.addEntry("Gold music box" + value);
        table.addEntry("Gold circlet set with four aquamarines" + value);
        table.addEntry("Eye patch with a mock eye set in blue sapphire and moonstone" + value);
        table.addEntry("A necklace string of small pink pearls" + value);
        table.addEntry("Silvered long sword");
        table.addEntry("Silvered hand axe");
    }

    if (tier == 4) {
        QString value = (_lowHauls)? " (7500 sp)" : " (7500 gp)";

        table.addEntry("jeweled gold crown" + value);
        table.addEntry("jeweled platinum ring" + value);
        table.addEntry("Small gold statuette set with rubies" + value);
        table.addEntry("Gold cup set with emeralds" + value);
        table.addEntry("Gold jewelry box with platinum filigree" + value);
        table.addEntry("Painted gold child's sarcophagus" + value);
        table.addEntry("Jade game board with solid gold playing pieces" + value);
        table.addEntry("Bejeweled ivory drinking horn with gold filigree" + value);
        table.addEntry("Silvered great sword");
        table.addEntry("Silvered great axe");
    }

    return table.getRollTableEntry();
}

QString LootTables::hoardCoins(int tier)
{
    int cp;
    int sp;
    //int ep;
    int gp;
    int pp;

    if (tier == 1) {
        cp = Dice::roll(6,6) * 100;
        sp = Dice::roll(3, 6) * 100;
        gp = Dice::roll(2, 6) * 10;
        if (_lowHauls) {
            return QString::number((cp/10)+sp) + " cp, "
                + QString::number(gp) + " sp";
        }
        return QString::number(cp) + " cp, " + QString::number(sp) + " sp, "
                + QString::number(gp) + " gp";
    }
    else if (tier == 2) {
        cp = Dice::roll(2, 6) * 100;
        sp = Dice::roll(2, 6) * 1000;
        gp = Dice::roll(6, 6) * 100;
        pp = Dice::roll(3, 6) * 10;
        if (_lowHauls) {
            return QString::number((cp/10)+sp) + " cp, "
                    + QString::number(gp) + " sp, "
                    + QString::number(pp) + " gp";
        }
        return QString::number(cp) + " cp, " + QString::number(sp) + " sp, "
                + QString::number(gp) + " gp, " + QString::number(pp) + " pp";
    }
    else if (tier == 3) {
        gp = Dice::roll(4, 6) * 1000;
        pp = Dice::roll(5, 6) * 100;
        return QString::number(gp) + " gp, " + QString::number(pp) + " pp";
    }
    else {
        gp = Dice::roll(12, 6) * 1000;
        pp = Dice::roll(8, 6) * 1000;
        return QString::number(gp) + " gp, " + QString::number(pp) + " pp";
    }

}

QString LootTables::mundaneHorde(int tier)
{
    int totalValue;
    if (tier == 1) {
        totalValue = Dice::roll(1,100) + 100;
    }
    else if (tier == 2) {
        totalValue = Dice::roll(1, 100) + 250;
    }
    else if (tier == 3) {
        totalValue = Dice::roll(1, 100) + 500;
    }
    else {
        totalValue = Dice::roll(1,100) + 1000;
    }

    int numPieces = Dice::roll(3,10);
    int pieceValue = (totalValue * 0.75) / numPieces;
    bool isFullSet = Dice::roll(1, 100) < 50;
    QString value;
    if (isFullSet) {
        value = QString::number(numPieces) + " pieces at "
                + QString::number(pieceValue)
                + " gp each, or a total of "
                + QString::number(totalValue) + " gp as a full set.";
    }
    else {
        int partial = numPieces * 0.25;
        int remainder = numPieces - partial;
        value = "Incomplete set of " + QString::number(partial)
                + " pieces out of " + QString::number(remainder)
                + " valued at "
                + QString::number(pieceValue) + " gp each.";
    }

    RandomTable natureTable;
    natureTable.addEntry("New, never released");
    natureTable.addEntry("Unique");
    natureTable.addEntry("Antique");
    natureTable.addEntry("Masterwork");
    natureTable.addEntry("Limited edition");
    natureTable.addEntry("Crafted by a famous craftsman");
    natureTable.addEntry("Used by a famous person");
    natureTable.addEntry("Historical");
    natureTable.addEntry("Rare");
    natureTable.addEntry("Mint condition");
    natureTable.addEntry("Useful to the right tradesman or collector");
    QString nature = natureTable.getRollTableEntry();

    RandomTable itemTable;
    itemTable.addEntry("Paintings");
    itemTable.addEntry("Statues");
    itemTable.addEntry("Furniture");
    itemTable.addEntry("Tapestries");
    itemTable.addEntry("Spices");
    itemTable.addEntry("Books, scrolls, knowledge, written in a dead language "
                       "only knowable by certain sages.");
    itemTable.addEntry("Tools for a trade");
    itemTable.addEntry("Outfits and clothing");
    itemTable.addEntry("Raw or smelted ore");
    itemTable.addEntry("Deeds and titles for far away properties");
    itemTable.addEntry("Fine China");
    itemTable.addEntry("Stained Glass");
    itemTable.addEntry("Food Stores");
    itemTable.addEntry("Relics of non-valuable materials, but archaeological worth");
    itemTable.addEntry("Old wines, ale casks, or bourbons");
    itemTable.addEntry("A strange variety of non-precious crystals");
    itemTable.addEntry("Maps of unfamiliar lands");
    itemTable.addEntry("Expertly etched or enamled arms, armor, and/or weapons not practical for actual use");
    itemTable.addEntry("Stone tablets, etched with ancient symbols and runes");
    itemTable.addEntry("Cataloged bones of extint animals");
    itemTable.addEntry("A colleciton of non-magical tinctures, remedies, snake-oils, ingredents");
    itemTable.addEntry("Animal or monster parts, preserved in jars");
    itemTable.addEntry("Taxidermy collection");
    itemTable.addEntry("Private zoo of exotic animals or caged experiment subjects");
    itemTable.addEntry("Collection of intricately designed fabrige eggs");
    itemTable.addEntry("Clocks, or clockworks collection");
    itemTable.addEntry("Bills of debt that might or might not be honored with payment if the players present them for collection.");
    itemTable.addEntry("Sea navigation documents: extremely valuable to pilots who keep them like wizards to their spellbooks.");
    itemTable.addEntry("Treatises on magic fundamentals that would be valuable to sages or any wizard's school.");
    itemTable.addEntry("Current merchant house routes and schedules that would be valuable to anyone who wants to intercept a shipment.");
    itemTable.addEntry("Preserved severed heads, or shrunken heads, or skulls of humanoids.");
    itemTable.addEntry("Commemorative plates, limited edition. Collector's pieces.");
    itemTable.addEntry("Wargame miniatures. Possibly with a well-crafted miniature tabletop in the form of the surrounding region");
    itemTable.addEntry("Fancy wardrobe of high-quality clothing for nobles. Possibly from a few generations ago and so might only be of value to a collector. Otherwise the latest styles that will sell well among socialites after minor alterations from their family tailor.");
    itemTable.addEntry("Collection of elaborately decorated boxes and chests. All empty, but valuable in themselves.");
    itemTable.addEntry("Extremely intricate locks and their keys/combinations, all crafted by a master locksmith of this or a past age.");
    itemTable.addEntry("Normal arms or armor, but stamped with the forge symbol of a world renowned dwarven smith, which increases their value significantly to those who know what to look for.");
    itemTable.addEntry("Masterwork quality tools for a particular trade.");
    itemTable.addEntry("Vault of unreleased music or private work of a world famous and recently deceased bard or composer.");
    itemTable.addEntry("The private notes and journal of a world renowned genius (Lenoardo DaVinci level), artist, inventor, scientist, wizard, or craftsman.");
    itemTable.addEntry("A mural or ceiling fresco of a famous artist, but it's part of the walls.");
    itemTable.addEntry("A library of fiction books, normally mundane, but it's value comes from the fact that the library was owned by a famous author when they were alive.");
    itemTable.addEntry("Reams of paper and a whole store of stacks of blank parchment. Vats of black ink. Valuable to the scribe guild who would buy the log, or simply when sold at retail, a unit at a time.");
    itemTable.addEntry("Barrels of gunpowder (Watch those torches!) Unmarked barrels with no other instruments of use around containing the rare, black powder of distinct odor.");
    itemTable.addEntry("Copper or iron pipes in various shapes. Could be sold for scrap metal if no plumbers guild exists.");
    itemTable.addEntry("Various floating globes of colored light. Used as magical interior illumination in wealthier parts of the realms where they are more accustomed to whimsical magic use.");
    itemTable.addEntry("Mechanical Turk. Plays chess poorly or submits a truly random fortune. Might be wind-up or copper coin operated.");
    itemTable.addEntry("A collection of wind-up ladies' music boxes.");
    itemTable.addEntry("A collection of snow globes of all the cities in the north. A common thing in our world, but in the fantasy world, it's a rare and difficult to craft curiosity.");
    itemTable.addEntry("A large collection of children's' toys.");
    itemTable.addEntry("An orchestra's worth of musical instruments. Alternatively, a small collection of extremely well crafted instruments that only a musician can appreciate. To the rest of us, the distinction is lost.");
    itemTable.addEntry("Trappings of a long forgotten religion.");
    itemTable.addEntry("Various types of incense.");
    itemTable.addEntry("Bins of salt rocks. Important, not just for spicing up a giant meal, but for preservation of meats. Salt mines are distant, and salt is heavy to transport, so a store of it would bring a classy copper from the right slaughterhouse or meat packer.");
    itemTable.addEntry("Blocks of ice. Food spoils quickly in the summer, and if you can keep your ice in ice form, you can sell it fairly quickly. These blocks should be tightly packed together in crates, and kept in a cool cellar to prevent them melting. Once they are removed, they will not last long.");
    itemTable.addEntry("A collection of religious relics made of wood or stone, which would only be valuable to the church they belong to.");
    itemTable.addEntry(" collection of various items that emit a strong, magical aura when detection is cast. These devices are ancient and mysterious. What they do or how to access their power is not apparent and is unknown to even to most well-read sage of wizardry in the party. However, these items would be of particular interest to a traveling magic collector from Halruaa -- if one could be found. They travel the world in disguise, in search of such items. If the party puts out word, one is bound to come searching, but also will thieves. The devices themselves might not do much of value to anyone outside a magical society.");

    QString treasure = itemTable.getRollTableEntry() + "\n" + value + "\n"
            + nature;

    return treasure;
}

QString LootTables::adventureGear()
{
    RandomTable table;

    QString num = QString::number(Dice::roll(1, 6));

    table.addEntry(num + " bolts");
    table.addEntry(num + " arrows");
    table.addEntry(num + " sling ammo");
    table.addEntry(num + " darts");
    table.addEntry(num + " iron spikes");
    table.addEntry(num + " torches");
    table.addEntry(num + " candles");


    RandomTable trade;
    trade.addEntry(num+ " lbs of wheat");
    trade.addEntry(num+ " lbs of flour");
    trade.addEntry(num+ " lbs of salt");
    trade.addEntry(num+ " lbs of cinnamon");
    trade.addEntry(num+ " lbs of iron");
    trade.addEntry(num+ " lbs of pepper");
    trade.addEntry(num+ " lbs of cloves");
    table.addEntry(trade.getRollTableEntry());

    table.addEntry("silvered bolt");
    table.addEntry("silvered arrow");
    table.addEntry("vial of acid");
    table.addEntry("flask of alchemists fire");
    table.addEntry("vial of antitoxin");
    table.addEntry("bag of ball bearings");
    table.addEntry(num + " caltrops");
    table.addEntry("flask of oil");
    table.addEntry("vial of basic poison");
    table.addEntry("Piton");
    table.addEntry("10 foot pole");
    table.addEntry("Potion of healing");
    table.addEntry("1 day of rations");

    num = QString::number(Dice::roll(1, 10) * 10);
    table.addEntry(num + " feet of hemp rope");

    table.addEntry("waterskin (full)");
    table.addEntry("wineskin (full)");

    RandomTable tools;
    tools.addEntry("Alchemists supplies");
    tools.addEntry("Brewers supplies");
    tools.addEntry("Calligrapher supplies");
    tools.addEntry("Carpenters tools");
    tools.addEntry("Cartographer tools");
    tools.addEntry("Cobbler tools");
    tools.addEntry("Cook utensils");
    tools.addEntry("Glassblower tools");
    tools.addEntry("Jeweler tools");
    tools.addEntry("Leatherworker tools");
    tools.addEntry("Mason tools");
    tools.addEntry("Painter supplies");
    tools.addEntry("Potters supplies");
    tools.addEntry("Smith tools");
    tools.addEntry("Tinker tools");
    tools.addEntry("Weaver tools");
    tools.addEntry("Woodcarver tools");
    tools.addEntry("Disguise kit");
    tools.addEntry("Forgery kit");
    tools.addEntry("Dice set");
    tools.addEntry("Dragonchess set");
    tools.addEntry("Playing card set");
    tools.addEntry("Three-dragon ante set");
    tools.addEntry("Herbalism kit");
    tools.addEntry("Navigator tools");
    tools.addEntry("Poisoner kit");
    tools.addEntry("Thieves tools");

    table.addEntry(tools.getRollTableEntry());

    return table.getRollTableEntry();

}

QString LootTables::craftingComponents(int tier)
{
    RandomTable table;
    int chance;

    QString qty = QString::number(Dice::roll(1, 8));
    // very common
    chance = 16;
    table.addEntry(qty + " Glass vial (1 gp)", chance);

    // common
    chance = 8;
    table.addEntry(qty + " Mandrake Root (1 sp)", chance);
    table.addEntry(qty + " lbs of clay", chance);
    table.addEntry("Small bag of ash", chance);

    // uncommon
    chance = 4;
    table.addEntry(qty + " Fruit of Selune", chance);
    table.addEntry(qty + " Jar of blood", chance);
    table.addEntry(qty + " ft copper wire (" + qty + " cp)", chance);

    // rare
    chance = 2;
    table.addEntry("Jewel encrusted dagger (100 gp)", chance);
    table.addEntry(qty + " Moon Tree Seeds", chance);
    table.addEntry("Immature Moon Tree Clone", chance);

    // very rare


    return table.getRollTableEntry();

}

QString LootTables::treasureContainer()
{
    RandomTable table;

    table.addEntry("Bags");
    table.addEntry("Sacks");
    table.addEntry("Small coffers");
    table.addEntry("Chests");
    table.addEntry("Huge chests");
    table.addEntry("Pottery jars");
    table.addEntry("Metal urns");
    table.addEntry("Stone containers");
    table.addEntry("Iron trunks");
    table.addEntry("Loose");
    table.addEntry("Crates");
    table.addEntry("Barrels");
    table.addEntry("Coffins");
    table.addEntry("Display cases");
    table.addEntry("Hollow statues");

    return table.getRollTableEntry();
}

QString LootTables::treasureHiddenBy()
{
    RandomTable table;

    table.addEntry("Invisibility");
    table.addEntry("Illusion to change appearance");
    table.addEntry("Secret space under container");
    table.addEntry("Secret compartment in container");
    table.addEntry("Inside ordinary container");
    table.addEntry("Disguised to appear as something else");
    table.addEntry("Under a heap of trash/dung");
    table.addEntry("Under a loose stone in the floor");
    table.addEntry("Behind a loose stone int the wall");
    table.addEntry("In a secret room nearby");
    table.addEntry("Nothing", 10);

    return table.getRollTableEntry();

}

QString LootTables::generateTreasureHorde(int tier)
{
    QString coin = hoardCoins(tier);

    bool hasGems;
    bool hasArt;
    bool hasMagic;
    int numGems;
    int numArt;
    int numMagic;
    bool hasMundane;
    bool hasMap;
    bool hasAdventure;
    int hasCrafting = Dice::roll(1, 20) <= 7;

    QString treasure;
    treasure = "TREASURE: \nCONTAINER: " + treasureContainer() + "\n"
            + "HIDEN BY: " + treasureHiddenBy() + "\n\n"
            + "COIN: " + coin + "\n";

    if (tier == 1) {
        hasGems = Dice::roll(1,100) < 53;
        hasArt = Dice::roll(1,100) < 41;
        hasMagic = Dice::roll(1,100) < 100-37;
        numGems = hasGems ? Dice::roll(2,6) : 0;
        numArt = hasArt ? Dice::roll(2,4) : 0;
        numMagic = hasMagic ? Dice::roll(1,6) : 0;
        hasMundane = Dice::roll(1,100) < 35;
        hasMap = Dice::roll(1,100) < 20;
        hasAdventure = Dice::roll(1,100) < 50;
    }
    else if (tier == 2) {
        hasGems = Dice::roll(1,100) < 40;
        hasArt = Dice::roll(1,100) < 56;
        hasMagic = Dice::roll(1,100) < 100-29;
        numGems = hasGems ? Dice::roll(3,6) : 0;
        numArt = hasArt ? Dice::roll(2,4) : 0;
        numMagic = hasMagic ? Dice::roll(1,6) : 0;
        hasMundane = Dice::roll(1,100) < 45;
        hasMap = Dice::roll(1,100) < 25;
        hasAdventure = Dice::roll(1,100) < 25;
    }
    else if (tier == 3) {
        hasGems = Dice::roll(1,100) < 47;
        hasArt = Dice::roll(1,100) < 50;
        hasMagic = Dice::roll(1,100) < 100-29;
        numGems = hasGems ? Dice::roll(3,6) : 0;
        numArt = hasArt ? Dice::roll(2,4) : 0;
        numMagic = hasMagic ? Dice::roll(1,6) : 0;
        hasMundane = Dice::roll(1,100) < 55;
        hasMap = Dice::roll(1,100) < 30;
        hasAdventure = Dice::roll(1,100) < 10;
    }
    else {
        hasGems = Dice::roll(1,100) < 42;
        hasArt = Dice::roll(1,100) < 56;
        hasMagic = Dice::roll(1,100) < 98;
        numGems = hasGems ? Dice::roll(3,6) : 0;
        numArt = hasArt ? Dice::roll(1,10) : 0;
        numMagic = hasMagic ? Dice::roll(1,8) : 0;
        hasMundane = Dice::roll(1,100) < 65;
        hasMap = Dice::roll(1,100) < 35;
        hasAdventure = Dice::roll(1,100) < 5;
    }

    int qty = Dice::roll(1,8);
    if (hasAdventure) {
        for (int i=0; i < qty; ++i) {
            treasure += adventureGear() + "\n";
        }
    }
    if (hasCrafting) {
        for (int i=0; i < qty; ++i) {
            treasure += craftingComponents(tier) + "\n";
        }
    }
    if (hasMundane) { treasure += "\n" + mundaneHorde(tier) + "\n"; }

    if (hasArt) { treasure += "\n"; }
    for (int i = 0; i < numArt; ++i) {
        treasure += art(tier) + "\n";
    }

    if (hasGems) { treasure += "\n"; }
    for (int i = 0; i < numGems; ++i) {
        treasure += gem(tier) + "\n";
    }

    if (hasMagic) { treasure += "\n"; }
    for (int i = 0; i < numMagic; ++i) {
        treasure += selectMagicItemByTier(tier) + "\n\n";
    }

    if (hasMap) { treasure += QString("\nMAP:\n")
                + treasureMaps::generateMap(); }

    return treasure;
}

QString LootTables::generateIndividualTreasure(int tier)
{
    int cp = 0;
    int sp = 0;
    int ep = 0;
    int gp = 0;
    int pp = 0;
    int chance = Dice::roll(1,100);
    QString treasure;

    if (tier == 1) {
        if (chance < 31) { cp = Dice::roll(5,6); }
        else if (chance < 61) { sp = Dice::roll(4,6); }
        else if (chance < 71) { ep = Dice::roll(3,6); }
        else if (chance < 96) { gp = Dice::roll(3,6); }
        else { pp = Dice::roll(1,6); }
    }
    if (tier == 2) {
        if (chance < 31) {
            cp = Dice::roll(4,6) * 100;
            ep = Dice::roll(1, 6) * 10;
        }
        else if (chance < 61) {
            sp = Dice::roll(6,6) * 10;
            gp = Dice::roll(2,6) * 10;
        }
        else if (chance < 71) {
            ep = Dice::roll(3,6) * 10;
            gp = Dice::roll(2,6) * 10;
        }
        else if (chance < 96) {
            gp = Dice::roll(4,6) * 10;
        }
        else {
            gp = Dice::roll(2,6) * 10;
            pp = Dice::roll(3,6);
        }
    }
    if (tier == 3) {
        if (chance < 21) {
            sp = Dice::roll(4,6) * 100;
            gp = Dice::roll(1,6) * 100;
        }
        else if (chance < 36) {
            ep = Dice::roll(1,6) * 100;
            gp = Dice::roll(1,6) * 100;
        }
        else if (chance < 76) {
            gp = Dice::roll(2,6) * 100;
            pp = Dice::roll(1,6) * 10;
        }
        else {
            gp = Dice::roll(2,6) * 100;
            pp = Dice::roll(2,6) * 10;
        }
    }
    if (tier == 4) {
        if (chance < 16) {
            ep = Dice::roll(2,6) * 1000;
            gp = Dice::roll(8,6) * 100;
        }
        else if (chance < 56) {
            gp = Dice::roll(1,6) * 1000;
            pp = Dice::roll(1,6) * 100;
        }
        else {
            gp = Dice::roll(1,6) * 1000;
            pp = Dice::roll(2,6) * 100;
        }
    }

    if (_lowHauls) {
        treasure +=
              ((sp==0) ? "" : QString::number(sp + (cp/10)) + " cp, ")
            + ((ep==0) ? "" : QString::number(ep) + " sp, ")
            + ((gp==0) ? "" : QString::number(gp) + " ep, ")
            + ((pp==0) ? "" : QString::number(pp) + " gp, ");
    }
    else {
        treasure +=
              ((cp==0) ? "" : QString::number(cp) + " cp, ")
            + ((sp==0) ? "" : QString::number(sp) + " sp, ")
            + ((ep==0) ? "" : QString::number(ep) + " ep, ")
            + ((gp==0) ? "" : QString::number(gp) + " gp, ")
            + ((pp==0) ? "" : QString::number(pp) + " pp, ");
    }

    int magicChance = tier * 5;
    bool hasMagic = Dice::roll(1,100) < magicChance;
    int jewelChance = tier * 10;
    bool hasJewel = Dice::roll(1,100) < jewelChance;
    int adventureChance = 25;
    bool hasAdventure = Dice::roll(1,100) < adventureChance;
    int mapChance = (tier * 5) + 10;
    bool hasMap = Dice::roll(1,100) < mapChance;
    bool hasCrafting = Dice::roll(1,20) <= 5;

    if (hasCrafting) {
        treasure += "\n" + craftingComponents(tier);
    }
    if (hasMagic) {
        treasure += "\n" + selectMagicItemByTier(tier);
    }
    if (hasJewel) {
        treasure += "\n" + art(tier);
    }
    if (hasAdventure) {
        treasure += "\n" + adventureGear();
    }
    if (hasMap) {
        treasure += "\n\n" + treasureMaps::generateMap();
    }

    return treasure;

}
