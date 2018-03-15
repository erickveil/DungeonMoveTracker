#include "traptables.h"

TrapTables::TrapTables()
{

}


QString TrapTables::generateTrap(int tier)
{
    QString description;
    QString severity = trapSeverityLevel(tier);
    QString effects = trapSeverityStats(severity, tier);
    description = trapEffects(severity, tier)
            + ",\nTRIGGER: " + trapTrigger()
            + ".\nSEVERITY: " + severity + " " + effects
            + ".\nDISARM: " + trapDisarm();

    return description;
}

QString TrapTables::trapSeverityLevel(int tier)
{
    ++tier;
    RandomTable table;
    table.addEntry("Setback", 2);
    table.addEntry("Dangerous", 3);
    table.addEntry("Deadly");
    return table.getRollTableEntry();
}

QString TrapTables::trapSeverityStats(QString severity, int tier)
{
    QString dc;
    QString att;
    QString damage;
    QString detail;

    if (severity == "Setback") {
        dc = QString::number(Dice::randomNumber(10, 11));
        att = QString::number(Dice::randomNumber(3, 5));

        if (tier == 1) { damage = "1d10"; }
        else if (tier == 2) { damage = "2d10"; }
        else if (tier == 3) { damage = "4d10"; }
        else { damage = "10d10"; }

        detail = " DC: " + dc + ", attk: " + att + ", dmg: " + damage;
        return detail;
    }

    else if (severity == "Dangerous") {
        dc = QString::number(Dice::randomNumber(12, 15));
        att = QString::number(Dice::randomNumber(6, 8));

        if (tier == 1) { damage = "2d10"; }
        else if (tier == 2) { damage = "4d10"; }
        else if (tier == 3) { damage = "10d10"; }
        else { damage = "18d10"; }

        detail = " DC: " + dc + ", attk: +" + att + ", dmg: " + damage;
        return detail;
    }

    else {
        dc = QString::number(Dice::randomNumber(16, 20));
        att = QString::number(Dice::randomNumber(9, 12));

        if (tier == 1) { damage = "4d10"; }
        else if (tier == 2) { damage = "10d10"; }
        else if (tier == 3) { damage = "18d10"; }
        else { damage = "24d10"; }

        detail = " DC: " + dc + ", attk: " + att + ", dmg: " + damage;
        return detail;
    }
}

QString TrapTables::trapSpell(QString severity, int tier)
{
    QString spell;
    QString detail;

    if (severity == "Setback") {
        if (tier == 1) {
            spell = LootTables::wizardSpells(0) + " or " + LootTables::wizardSpells(0);
        }
        else if (tier == 2) {
            spell = LootTables::wizardSpells(1) + " or " + LootTables::wizardSpells(1);
        }
        else if (tier == 3) {
            spell = LootTables::wizardSpells(3) + " or " + LootTables::wizardSpells(3);
        }
        else {
            spell = LootTables::wizardSpells(6) + " or " + LootTables::wizardSpells(6);
        }
        detail = "Spell effect: " + spell;

        return detail;
    }

    else if (severity == "Dangerous") {
        if (tier == 1) {
            spell = LootTables::wizardSpells(1) + " or " + LootTables::wizardSpells(1);
        }
        else if (tier == 2) {
            spell = LootTables::wizardSpells(3) + " or " + LootTables::wizardSpells(3);
        }
        else if (tier == 3) {
            spell = LootTables::wizardSpells(6) + " or " + LootTables::wizardSpells(6);
        }
        else {
            spell = LootTables::wizardSpells(9) + " or " + LootTables::wizardSpells(9);
        }
        detail = "Spell effect: " + spell;

        return detail;
    }

    else {
        if (tier == 1) {
            spell = LootTables::wizardSpells(2) + " or " + LootTables::wizardSpells(2);
        }
        else if (tier == 2) {
            spell = LootTables::wizardSpells(6) + " or " + LootTables::wizardSpells(6);
        }
        else if (tier == 3) {
            spell = LootTables::wizardSpells(9) + " or " + LootTables::wizardSpells(9);
        }
        else {
            spell = LootTables::wizardSpells(9) + " and " + LootTables::wizardSpells(5) + " or "
            + LootTables::wizardSpells(9) + " and " + LootTables::wizardSpells(5);
        }
        detail = "Spell effect: " + spell;

        return detail;
    }
}


QString TrapTables::trapTrigger()
{
    RandomTable table;

    table.addEntry("stepping on (floor, stairs)");
    table.addEntry("moving through (doorway, hallway)");
    table.addEntry("touching (doorknob, statue)");
    table.addEntry("opening (door, chest)");
    table.addEntry("looking at (mural, arcane symbol)");
    table.addEntry("moving (cart, stone block)");
    table.addEntry("tripping on wire");
    table.addEntry("stepping on loose stone block");
    table.addEntry("disturbing spider webs");
    table.addEntry("breaking beam of light");
    table.addEntry("pulling the wrong lever");
    table.addEntry("living being enters the area");
    table.addEntry("touching or dispelling the illusionary treasure");
    table.addEntry("attacking the illusionary monster");
    table.addEntry("disarming decoy tripwire");

    return table.getRollTableEntry();
}

QString TrapTables::doorTrapTrigger()
{
    RandomTable table;

    table.addEntry("stepping on plate in exit");
    table.addEntry("moving through exit");
    table.addEntry("touching doorknob");
    table.addEntry("opening door");
    table.addEntry("examining door and failing save");
    table.addEntry("tripping on wire across exit");
    table.addEntry("disturbing spider webs over exit");
    table.addEntry("pulling lever next to door");
    table.addEntry("disarming decoy tripwire");

    return table.getRollTableEntry();
}

QString TrapTables::trapEffects(QString severity, int tier)
{
    RandomTable table;

    table.addEntry(trapSpell(severity, tier), 8);

    table.addEntry("Magic missiles shoot from a statue or object", 4);
    table.addEntry("Collapsing staircase creates a ramp that deposits "
                   "characters into a pit at its lower end", 2);
    table.addEntry("Ceiling block falls, or entire ceiling collapses", 2);
    table.addEntry("Celing lowers slowly in locked room", 2);
    table.addEntry("Chute opens in floor", 2);
    table.addEntry("Clanging noise attracts nearby monsters", 2);
    table.addEntry("Disintegrate Spell", 3);
    table.addEntry("Contact Poison", 3);
    table.addEntry("Fire shoots out from a wall, floor, or object", 3);
    table.addEntry("Flesh to stone spell", 3);
    table.addEntry("Floor collapses or is an illusion", 3);

    RandomTable gasSubtable;
    gasSubtable.addEntry("blinding");
    gasSubtable.addEntry("acidic");
    gasSubtable.addEntry("obscuring");
    gasSubtable.addEntry("paralyzing");
    gasSubtable.addEntry("poisonous");
    gasSubtable.addEntry("sleep-inducing");
    QString gasType = gasSubtable.getRollTableEntry();

    table.addEntry("Vent releases " + gasType + " gas.", 3);
    table.addEntry("Floor tiles are electrified", 3);
    table.addEntry("Glyph of warding", 3);
    table.addEntry("Huge wheeld statue rolls down corridor", 3);
    table.addEntry("Lightning bolt shoots from wall or object", 3);
    table.addEntry("Locked room floods with water or acid", 3);
    table.addEntry("Darts shoot out", 3);
    table.addEntry("A weapon, suit of armor, or rug animates and attacks "
                   "(Animated Object)", 3);
    table.addEntry("Pendulum, either bladed or weighted as a maul, swings "
                   "across the room or hall", 3);
    table.addEntry("Hidden pit opens beneath characters (25% chance that a "
                   "black pudding or gelatinous cube fills the bottom of the "
                   "pit)", 5);
    table.addEntry("Hidden pit floods with acid of fire", 3);
    table.addEntry("Locking pit floods with water", 3);
    table.addEntry("Scything blade emerges from wall or object", 4);
    table.addEntry("Spears (possibly poisoned) spring out", 4);
    table.addEntry("Brittle stairs collapse over spikes", 3);
    table.addEntry("Thunderwave spell knocks characters into a pit of spikes",
                   2);
    table.addEntry("Steel or stone jaws restrain a character", 3);
    table.addEntry("Stone block smashes across hallway", 3);
    table.addEntry("Blade Trap in Corridor: The trigger release flying blades "
                   "from slots in the walls. Creatures in the passageway are "
                   "caught in the hail of blades, which clatter loudly against "
                   "the stone.");
    table.addEntry("Crossbow Trap in Corridor: Trigger activate a crossbow "
                   "trap (four attacks against random targets in the "
                   "passage).");
    table.addEntry("Poison Glyph Trap: Triggers a cloud of poison erupts from "
                   "the center of the room. Before the cloud dissipates, each "
                   "creature in the area takes poison damage (Constitution "
                   "saving throw for half damage).");
    table.addEntry("Necrotic Glyph Trap: Triggered is subject to a wave of "
                   "necrotic energy (half damage on a miss).");
    table.addEntry("Duplicate of trap previously used in this dungeon.");
    table.addEntry("Magic Obelisk: This obelisk dates back nearly two thousand "
                   "years but maintains its magic. The Elven runes are "
                   "unintelligible, but a DC 10 History check reveals that "
                   "they are millennia old. Once per day, a creature that "
                   "touches the obelisk is overcome with a vision of elves "
                   "doing battle with devils within a vast and ancient elven "
                   "city. The creature must succeed on a Wisdom saving throw "
                   "or take psychic damage from the vision. On a successful "
                   "save, the creature gains advantage on Wisdom checks for "
                   "24 hours.");
    table.addEntry("Stalactite Collapse: Small flying creatures attack and "
                   "retreat back to the ceiling (drawing attacks of "
                   "opportunity). Any ranged or area attack aimed toward "
                   "the ceiling has a chance of dislodging the fragile "
                   "stalactites in this area. Whenever a character makes a "
                   "ranged attack against a flying creature and misses, "
                   "roll a d6. On a result of 4-6, a stalactite splinters "
                   "and falls directly down beneath the target of the attack, "
                   "spraying fragments in a 5-foot-radius burst. Any area "
                   "attack that hits the ceiling brings down a hail of rock "
                   "in a burst equal to the area of the original attack. Any "
                   "creature in a stalactite burst makes a Dexterity saving "
                   "throw. On a failed save, falls prone.");
    table.addEntry("Blinding Alarm: Magical darkness that foils even "
                   "darkvision fills the area and a loud gong sound echos "
                   "throughout the dungeon. Only those who were in the area "
                   "when the trap was triggered are affected by the darkness, "
                   "while newcomers are not. Leaving the area restores sight "
                   "but the selective darkness still hangs in the area.");
    table.addEntry("Explosive Alchemy: The experiments in this area are "
                   "incredibly volatile. Whenever a creature makes an attack "
                   "that misses by 5 or more, that attacker must make a "
                   "Dexterity saving throw. On a failed save, the attack "
                   "disturbs the alchemical equipment and triggers an "
                   "explosion. Any creature in the room takes fire damage "
                   "(Dexterity saving throw for half damage).");
    table.addEntry("Fire Trap: a sheet of flame issues forth from an object. "
                   "The magical fire does not harm the room, but deals fire "
                   "damage to any creature in the area (Dexterity saving "
                   "throw for half damage). The trap resets 30 minutes after "
                   "it is triggered.");
    table.addEntry("Marbles spill out onto the floor. Dex save to move "
                   "through the room without falling down.");

    RandomTable trapDoorContentsSubtable;

    trapDoorContentsSubtable.addEntry("poisonous snakes");
    trapDoorContentsSubtable.addEntry("poisonous spiders");
    trapDoorContentsSubtable.addEntry("offal (attracts predators until "
                                      "cleaned)");
    trapDoorContentsSubtable.addEntry("acid vials");
    trapDoorContentsSubtable.addEntry("oil vials and a stone that sparks when "
                                      "it lands");
    trapDoorContentsSubtable.addEntry("enough water to flood the whole room");
    trapDoorContentsSubtable.addEntry("green slime");
    trapDoorContentsSubtable.addEntry("gelatinous cube");
    trapDoorContentsSubtable.addEntry("bones or rocks");
    trapDoorContentsSubtable.addEntry("something sticky then a bunch of "
                                      "feathers");
    trapDoorContentsSubtable.addEntry("a bucket of blood (character leaves "
                                      "bloody footprints that attracts hunters "
                                      "for 1000 feet)");
    trapDoorContentsSubtable.addEntry("nothing!?");

    QString drops = trapDoorContentsSubtable.getRollTableEntry();
    table.addEntry("Trap door in ceiling drops " + drops);

    RandomTable symbolSubtable;
    symbolSubtable.addEntry("Death");
    symbolSubtable.addEntry("Discord");
    symbolSubtable.addEntry("Fear");
    symbolSubtable.addEntry("Hopelessness");
    symbolSubtable.addEntry("Insanity");
    symbolSubtable.addEntry("Pain");
    symbolSubtable.addEntry("Sleep");
    symbolSubtable.addEntry("Stunning");
    QString symbolType = symbolSubtable.getRollTableEntry();

    table.addEntry(symbolType + " Symbol spell", 3);
    table.addEntry("Walls slide together", 3);
    table.addEntry("Whirling blades make an attack agains each creature in the "
                   "area");
    table.addEntry("Crushing pillars require dex save. On failure, take damage "
                   "and knocked prone. On success, take half damage and avoid "
                   "being knocked prone.");
    table.addEntry("Rune of fear: Wis save each round. Failure must use "
                   "reaction and immediately move its speed away and cannot "
                   "approach until it succeeds a save.");
    table.addEntry("Specific nodes become highly magnetic for 1 round then "
                   "release for 1 round. Anyone in metal armor is pulled to "
                   "them (Dex save or take bludgeoning damage) and stuck in "
                   "place. Str save to hold onto weapons - fail more than 5 "
                   "and lose the weapon, fail less than 5 and be pulled to the "
                   "nearest node, succeed and attack with disadvantage.");
    table.addEntry("Gravity reverses each round. Take falling damage each time "
                   "unless a Dex save is made to hold onto the iron bars on "
                   "the walls and/or floor/ceilings");
    table.addEntry("One or more monsters are added to the room through a "
                   "portal, gate, or well.");
    table.addEntry("1d4 Portals open in the floor under random occupants' "
                   "feet. Dex save or fall in, and exit out a portal on the "
                   "ceiling elsewhere, dropping for falling damage and "
                   "changing their position.");
    table.addEntry("Occupants are teleported to different locations in the "
                   "room or dungeon.");
    table.addEntry("A section of the wall rapidly slides across the room, "
                   "smashing anyone caught in it. The section is from the "
                   "floor, up to 1d6 feet high (different each round). PCs "
                   "must make a standing high jump movement check to get on "
                   "top of it. It recedes the next round.");
    table.addEntry("A chain that stretches from one end of the room to the "
                   "other rapidly moves across the room, tripping or catching "
                   "occupants. Chain is 1d4 feet off the ground. Dex Save to "
                   "drop prone to the floor under it at least 2 feet high, or "
                   "standing high jump movement to get over it. Fail more than "
                   "5 and get caught in the chain and pinned to the far wall "
                   "behind it for damage. Fail for less than 5 and knocked "
                   "prone. Chain moves back in the opposite direction next "
                   "round.");

    return table.getRollTableEntry();


}

QString TrapTables::trapDisarm()
{
    RandomTable table;

    table.addEntry("Three successful castings of dispel magic disables the "
                   "device.");
    table.addEntry("PC may make an Intelegence (Arcana) check as an action to "
                   "disable the magic that operates the device.");
    table.addEntry("Rusty chains snake across the ceiling, disappearing "
                   "into holes on either wall.");
    table.addEntry("Three brass floor plates, nearly invisible beneath the "
                   "dust and detritus.");
    table.addEntry("An eroded bas-relief of a grinning Pan-like figure, its "
                   "fingers appear to be moveable.");
    table.addEntry("A shallow gutter runs along the far wall, with a loose "
                   "brick restricting the flow of water through it.");
    table.addEntry("What appears to be a keyhole is discover behind a loose "
                   "stone.");
    table.addEntry("A rusted and jammed lever is found beneath a discarded "
                   "pile of clothing.");
    table.addEntry("A row of fake-emerald buttons on the wall, covered in "
                   "cobwebs.");
    table.addEntry("Three stones are arranged in a circle on a lead pressure "
                   "plate.");
    table.addEntry("A painting of an octopus is found in a far corner, three "
                   "of its arms appear depressible.");
    table.addEntry("A foot-long strip of iron is set into the ceiling, with "
                   "a small magnet at one end.");
    table.addEntry("A small wooden door opens to a panel filled with strange "
                   "metal gears.");
    table.addEntry("Three tiny brass levers in a hand-sized hole in the "
                   "floor.");
    table.addEntry("A moldy rope lies on the floor, leading to a pulley lost "
                   "in the shadows of the ceiling.");
    table.addEntry("Four keyhole sized openings along the bottom of a door.");
    table.addEntry("A magical rune glows red when touched.");
    table.addEntry("A small statuette of an elephant lies beside a small "
                   "stone pedestal.");
    table.addEntry("A loose block in the ceiling appears to be hooked to a "
                   "chain above.");
    table.addEntry("Three counterweights hang on ropes just inside the door.");
    table.addEntry("A bas-relief of a demonic face has depressible eyes.");
    table.addEntry("A camouflaged metal door on one wall conceals a copper "
                   "lever.");
    table.addEntry("A magic mouth appears and demands a password.");
    table.addEntry("Magic runes spell out “Erase Me” with Read Magic.");
    table.addEntry("A statue of a wizened sage has moveable arms.");
    table.addEntry("An abandoned bottle contains a key matching a concealed "
                   "hole in the wall.");
    table.addEntry("A loose brick has fallen out of the wall and must be "
                   "replaced.");
    table.addEntry("A ghostly apparition appears and demands a song be sung "
                   "to him.");
    table.addEntry("A pulley disarms the trap, but the rope is missing.");
    table.addEntry("A empty gourd hangs from a hook on the wall and must be "
                   "filled with water.");
    table.addEntry("Three couplets of an old poem are scrawled on the wall; "
                   "the missing couplet must be recited aloud.");
    table.addEntry("Two orcs are painted on the floor; erasing one disarms, "
                   "erasing the other sets off trap again.");
    table.addEntry("The trap is not disarm-able, but a detailed schematic of "
                   "the next trap is drawn in chalk upon the floor.");
    table.addEntry("Four loose bricks must be straitened.");
    table.addEntry("Water must be poured upon a leather strap hanging over the "
                   "door to loosen it.");
    table.addEntry("A ceramic cap over the disarming panel must be broken "
                   "open.");
    table.addEntry("A filthy wax seal over the panel must be melted away.");
    table.addEntry("A magic mouth appears and demands to know the meaning of "
                   "life.");
    table.addEntry("Five pewter runes in the ceiling must be depressed in "
                   "order.");
    table.addEntry("A console of brass buttons is a decoy; the real trap "
                   "release is hidden beneath.");
    table.addEntry("Detect Magic must be cast to reveal the invisible lever.");
    table.addEntry("A statuette of a dog must be broken open to reveal a key.");
    table.addEntry("A silver floor panel (20gp value) covers a stone lever "
                   "crawling with centipedes.");
    table.addEntry("A stone chest must be opened to a precise degree.");
    table.addEntry("An empty hourglass must be filled with sand and turned "
                   "upside down.");
    table.addEntry("Three wall levers: two set off the trap again, one "
                   "disarms.");
    table.addEntry("A candle in a wall sconce must be burned down to disarm.");
    table.addEntry("A wall sconce must be turned to a right angle.");
    table.addEntry("A chandelier must be pulled down to floor, revolved 180 "
                   "degrees, and sent back up again.");
    table.addEntry("Every candle on a seventeen candle-candelabra must be "
                   "lit; seven candles are missing.");
    table.addEntry("A torch must be applied to a heat-sensitive floor panel.");
    table.addEntry("An invisible statue in the corner must have both arms "
                   "lowered.");
    table.addEntry("An imp appears and demands payment to disarm the trap.");
    table.addEntry("A globe hangs from the ceiling; Light must be cast upon "
                   "it.");
    table.addEntry("A hollow needle emerges from the wall; pricking a finger "
                   "upon it disarms trap.");
    table.addEntry("A ceramic alligator statue with gaping maw: will close "
                   "maw if fed meat and disarm trap.");
    table.addEntry("A snake-filled pit contains the release lever.");
    table.addEntry("A small ochre jelly (1+1HD) must be coerced off the "
                   "pressure plate it rests upon");
    table.addEntry("The open mouth of a gargoyle must be filled with wine or "
                   "beer.");
    table.addEntry("An illusory wall conceals a control panel.");
    table.addEntry("A release lever at the bottom of a sludge-filled well.");
    table.addEntry("Four small toilets line the far wall; all must be flushed.");
    table.addEntry("A dagger must be placed into the hand of the statue of an "
                   "impish child.");
    table.addEntry("A complex set of gears is concealed within an armoire.");
    table.addEntry("A lever is hidden behind a wine rack.");
    table.addEntry("An empty, moveable bookcase conceals a set of rope "
                   "pulleys.");
    table.addEntry("A fake toadstool, among a patch of real ones, may be "
                   "turned like a doorknob.");
    table.addEntry("A patch of mildew conceals a diagram detailing how to "
                   "disarm the trap.");
    table.addEntry("An unlit torch on the wall must be lit.");
    table.addEntry("The release lever has a hive of angry wasps built around "
                   "it.");
    table.addEntry("An acid-filled crystal ewer on a pedestal must be "
                   "carefully emptied.");
    table.addEntry("A row of clever brass gears is concealed just under the "
                   "plaster on one wall.");
    table.addEntry("A wick leading into a hole in the wall must be lit.");
    table.addEntry("A row of skulls upon a ledge high on one wall; one "
                   "contains the detached lever deactivating the trap.");
    table.addEntry("An immense chalk maze drawn into the floor must be "
                   "carefully walked through to completion.");
    table.addEntry("A magic circle scribed into one wall must have a corpse "
                   "placed within it.");
    table.addEntry("A blackened steel wire stretches across the ceiling and "
                   "must be cut.");
    table.addEntry("Forty feet of chain must be pulled from a hole in the "
                   "ceiling; very noisy (check for wandering monsters).");
    table.addEntry("An iron spike must be pulled out of the stone wall it’s "
                   "driven into (very difficult!).");
    table.addEntry("A leprechaun is geased to guard the release and must be "
                   "appeased with gold.");
    table.addEntry("A complex set of archaic runes must be deciphered and "
                   "read aloud.");
    table.addEntry("A frayed rope pull-cord is concealed behind infested "
                   "cobwebs.");
    table.addEntry("A nine-headed hydra statue must have its heads hacked "
                   "off.");
    table.addEntry("Acid must be applied to a soapstone plug.");
    table.addEntry("Seven locks must be picked, or the proper keys found.");
    table.addEntry("A rude drawing of an elven maiden conceals a wall plate.");
    table.addEntry("A magic mouth appears and demands an immediate dance "
                   "recital.");
    table.addEntry("A shallow pool of filthy water conceals rusty mechanism; "
                   "must be dry, clean, and oiled.");
    table.addEntry("A brazier must be filled with coal and lit.");
    table.addEntry("A chair attached to a hidden floor lever must be "
                   "tipped back.");
    table.addEntry("A slimy stone in the wall must be removed, turned, and "
                   "replaced.");
    table.addEntry("A dagger must be placed into a hole; cannot be removed "
                   "afterwards.");
    table.addEntry("A hand-shaped depression in the high ceiling must be "
                   "depressed.");
    table.addEntry("Dust-covered elvish runes on the far wall must be read "
                   "aloud.");
    table.addEntry("A froglike idol must be knelt in front of, depressing a "
                   "hidden floor plate.");
    table.addEntry("A rudely fashioned ceramic face on the wall must be "
                   "broken away to reveal a lever.");
    table.addEntry("Acid must be poured upon a series of thin copper "
                   "filaments.");
    table.addEntry("Three ceiling hooks must be chained together and "
                   "pulled; the chain is missing.");
    table.addEntry("The apparition of a pirate appears and demands a bawdy "
                   "tune.");
    table.addEntry("Three silver wires, nearly invisible, run across the "
                   "floor from either wall.");
    table.addEntry("Five brass levers are concealed behind the painting of "
                   "a grinning ettin.");
    table.addEntry("Rows of colored circles dot the floor. A spinning wheel "
                   "depicts the colors, and hands or feet must be placed on "
                   "the corresponding colors until the trap releases. May "
                   "require multiple participants.");

    return table.getRollTableEntry();
}

QString TrapTables::generateTrick()
{
    QString object = trickObject();
    QString random = object + " that " + trick();

    RandomTable table;
    table.addEntry(random, 10);
    QString turns = QString::number(Dice::roll(1,20) + 40);
    table.addEntry("Wall 10' behind slides across passage, blocking it for "
                   + turns + " turns.");
    table.addEntry("Oil (equal to one flask) pours on random person from hole "
                   "in ceiling, followed by flaming cinder (2-12 hp damage, "
                   "Dex save DC 10 for 1-3 damage from splash)");
    table.addEntry("Door falls outward, causing 1d10 damage.");
    table.addEntry("Lodestone exerts magnetic force on all metal items in the room");

    return table.getRollTableEntry();
}

QString TrapTables::trickObject()
{
    RandomTable table;

    table.addEntry("Book");
    table.addEntry("Brain preserved in a jar");
    table.addEntry("Burning Fire");
    table.addEntry("Cracked gem");
    table.addEntry("Door");
    table.addEntry("Fresco");
    table.addEntry("Furniture");
    table.addEntry("Glass Sculpture");
    table.addEntry("Mushroom field");
    table.addEntry("Painting");
    table.addEntry("Plant or tree");
    table.addEntry("Pool of water");
    table.addEntry("Runes engraved on wall or floor");
    table.addEntry("Skull");
    table.addEntry("Sphere of magical energy");
    table.addEntry("Statue");
    table.addEntry("Stone or obelisk");
    table.addEntry("Suit of armor");
    table.addEntry("Tapestry or rug");
    table.addEntry("Target Dummy");

    return table.getRollTableEntry();
}

QString TrapTables::trick()
{
    RandomTable table;

    table.addEntry("Ages the first person to touch the object");
    table.addEntry("Touched object animates, or animates other objects nearby");
    table.addEntry("Asks three skill-testing questions and rewards if all are "
                   "answered correctly.");
    table.addEntry("Bestows resistance or vulnerability");
    table.addEntry("Changes a character's alignment, personality, size, "
                   "appearance, or sex when touched");
    table.addEntry("Changes one substance to another, such as gold to lead or "
                   "metal to brittle crystal");
    table.addEntry("Creates a force field");
    table.addEntry("Creates an illusion");
    table.addEntry("Suppresses magic items for a time");
    table.addEntry("Enlarges or reduces characters");
    table.addEntry("Magic Mouth spell speaks a riddle");
    table.addEntry("Confusion spell all creatures within 10 feet");
    table.addEntry("Gives directions (true or false)");
    table.addEntry("Grants a wish");
    table.addEntry("Flies about to avoid being touched");
    table.addEntry("Casts geas spell on characters");
    table.addEntry("Increases, reduces, negates, or reverses gravity");
    table.addEntry("Induces greed");
    table.addEntry("Contains an imprisoned creature");
    table.addEntry("Locks or unlocks exits");
    table.addEntry("Offers a game of chance, with the promise of a reward "
                   "or valuable information");
    table.addEntry("Helps or harms certain types of creatures");
    table.addEntry("Casts polymorph spell on the characters (1 hour)");
    table.addEntry("Presents a puzzle or riddle");
    table.addEntry("Prevents movement");
    table.addEntry("Releases coins, false coins, gems, false, gems, a "
                   "magic item, or a map");
    table.addEntry("Releases, summons, or turns into a monster");
    table.addEntry("Casts suggestion on the characters");
    table.addEntry("Wails loudly when touched");
    table.addEntry("Talks (normal speech, nonsense, poetry and "
                   "rhymes, singing, spellcasting, or screaming");
    table.addEntry("Teleports characters to another place");
    table.addEntry("Swaps two or more characters' minds");
    table.addEntry("Cursed Magic Item: " , 5);

    return table.getRollTableEntry();
}

