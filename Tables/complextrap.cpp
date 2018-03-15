#include "complextrap.h"

complexTrap::complexTrap()
{

}

QString complexTrap::generateTrap(int tier)
{
    QString severity = TrapTables::trapSeverityLevel(tier);
    QString desc = "COMPLEX TRAP:\n"
                   "Threat level: ";
    desc += severity
            + "\n\nTrigger: " + trigger(tier)
            + "\n\nEffect Chain: " + effectDivision()
            + "\n\nInitiative: " + initiative(tier)
            + "\n\nActive Elements:\n" + ActiveElements(severity, tier)
            + "Constant Elements: " + ConstantElements(severity, tier)
            + "\n\nXP: " + Experience(tier);
    return desc;
}

QString complexTrap::effectDivision()
{
    RandomTable table;
    QString time = QString::number(Dice::roll(1,4));
    table.addEntry("Each effect begins " + time
                   + " rounds after the last one. Some countdown or clockwork "
                     "builds the tension.");
    table.addEntry("Each effect is seperated in its own, visually identifiable "
                   "area of the room and are active only if their area is "
                   "occupied.");
    table.addEntry("Each effect begins after the previous one is defeated.");
    table.addEntry("The trap cycles through each effect each time it is "
                   "triggered.");
    table.addEntry("A red hering disarm procedure is presented, which actually "
                   "triggers the next effect.");
    table.addEntry("All effects go off at once, but are segregated to their own "
                   "area.");
    table.addEntry("Each effect takes place after a barrier is passed that makes"
                   " the party think they've gotten through the trap.");
    table.addEntry("Heavy objects must be pushed onto the correct floor switches "
                   "in order to proceed. Incorrect switches trigger traps. "
                   "The swithces are marked with symbols: 3 symbols for each "
                   "correct switch, and one for each trap effect. There are "
                   "multiple of each switch.");
    table.addEntry("Heavy objects must be pushed onto the correct floor switches "
                   "in order to proceed. Incorrect switches trigger traps. "
                   "The swithces are marked with symbols with multiples of "
                   "each, but the symbols themselves mean nothing. Each symbol"
                   "is a different color: One for each correct switch, and one"
                   "color for each trap effect. Each symbol has one of each "
                   "color.");
    table.addEntry("Three wheels with three symbols on them each form 27 possible "
                   "combinations. Any wrong combination sets off a trap effect.");
    table.addEntry("Instead of one room, the trap takes place in a series of "
                   "connected rooms and corridors with one trap element in "
                   "each, but the solution in the wrong room");

    return table.getRollTableEntry();
}

QString complexTrap::trigger(int tier)
{
    ++tier;
    return TrapTables::trapTrigger();
}

QString complexTrap::initiative(int tier)
{
    ++tier;
    RandomTable table;
    table.addEntry("initiative count 10");
    table.addEntry("initiative count 20");
    table.addEntry("initiatie counts 10 and 20");
    return table.getRollTableEntry();
}

QString complexTrap::ActiveElements(QString severity, int tier)
{
    int numEffects = Dice::roll(1, 4) + tier;
    QString effects;
    for (int i = 0; i < numEffects; ++i) {
        effects += "Effect " + QString::number(i+1) + ":\n";
        effects += TrapTables::trapEffects(severity, tier)
                + "\n" + TrapTables::trapSeverityStats(severity, tier)
                + "\nDynamics: " + DynamicElements(tier)
                + "\nCountermeasure: " + Countermeasures(tier)

                + "\n\n";
    }
    return effects;
}

QString complexTrap::DynamicElements(int tier)
{
    tier++;
    RandomTable table;
    int increase = Dice::roll(1,4);
    int increase2 = Dice::roll(1,4);
    int increase3 = Dice::roll(1,4);
    QString dangerIncrease = QString("Attack rolls increase by +")
            + QString::number(increase)
            + " each instance, DC increases +"
            + QString::number(increase2)
            + " each instance, and damage increases by +"
            + QString::number(increase3)
            + " each instance.";
    table.addEntry("The element becomes more dangerous each round it remains "
                   "active. " + dangerIncrease);

    bool succeedOrFail = Dice::roll(1, 100) < 50;
    RandomTable target;
    target.addEntry("this element");
    target.addEntry("other elements");
    target.addEntry("all elements");
    table.addEntry(QString("Each ")
                   + QString((succeedOrFail) ? "failed" : "successful")
                   + " check on an attempt to disable the element makes "
                   + target.getRollTableEntry()
                   + " more dangerous. " + dangerIncrease);

    return table.getRollTableEntry();
}

QString complexTrap::ConstantElements(QString severity, int tier)
{
    RandomTable table;
    table.addEntry("Active elements also affect anyone ending their turn "
                   "while within the active area.");
    QString trap = TrapTables::trapEffects(severity, tier) + "\n"
            + TrapTables::trapSeverityStats(severity, tier);
    table.addEntry("Additional trap effect on anyone ending their turn within "
                   "a marked area: " + trap);
    table.addEntry("Entries close and lock, sealing anyone in until disarm "
                   "conditions are met: " + Countermeasures(tier));
    table.addEntry("Entries close and lock, sealing anyone in until the "
                   "trap is defeated.", 2);
    table.addEntry("Mechanisms under the floor rotate sections of it, "
                   "re-configuring the room and moving occupants into hazards");
    table.addEntry("Sections of the floor raise and lower, changing the "
                   "elevation between occupants, and closing off or revealing "
                   "access to different areas.");
    table.addEntry("Elevator room moves up or down each round, revealing and "
                   "concealing doors to halls and rooms that contain parts of "
                   "the trap or means of solving it. Access to the main room "
                   "may be cut off when it leaves the level of the doorway.");
    table.addEntry("Random ray petrifies or restores random occupants of the "
                   "room each round.");
    table.addEntry("A random PC is removed from the room via teleport. If a "
                   "PC is already removed, they are returned in place of the "
                   "newly removed PC. Removed PCs find themselves alone in a "
                   "black void");
    table.addEntry("Electricity chains through the room doing damage to any "
                   "PCs oriented in a straight line of 3 or more.");
    // TODO: random poison
    table.addEntry("Poison gas (random effect) emits from a jet on one side of "
                   "the room and expands at a rate of 5' per round. To stop the "
                   "gas, someone must enter the area and pull the lever next to "
                   "the jet and expose themselves. Gas dissipates 5' per round. "
                   "Pulling the lever activates the same trap on the opposite "
                   "side of the room.");
    table.addEntry("Room starts spinning rapidly with center axis vertical at "
                   "center. After 1 round it gets up to speed and anyone not "
                   "next to a wall is flung there for falling damage if they "
                   "fail a save throw. Movement is halved next to wall, and "
                   "quartered off of it. Rolls are at disadvantage.");
    table.addEntry("Room or corridor begins to roll in one direction, faster and "
                   "faster each round. Dex checks, starting at DC 10 each "
                   "round to remain standing. DC increases by 1 each round.");
    table.addEntry("Room floods with water, rising 2.5 feet per round.");
    table.addEntry("Ceiling lowers 2.5 feet per round.");
    table.addEntry("Alternating sections of the floor turn into trap doors "
                   "each round, randomly leaving some areas solid, some open "
                   "air. Dex check DC 10 to not fall in. Below each room is "
                   "another identical room with the same components.");
    table.addEntry("Room filled 5' with water and oil sits on top. Oil is "
                   "ignited once trap starts. Occupants may either stay under "
                   "water and hold their breath, or surface for 1d6 fire damage "
                   "each round.");
    table.addEntry("High gust of wind circles inside the room, making ranged "
                   "attacks impossible.");
    QString trapEffect = TrapTables::trapEffects(severity, tier) + "("
            + TrapTables::trapSeverityStats(severity, tier) + ")";
    table.addEntry("Sand in an hourglass takes 1d3 rounds to empty into the "
                   "lower chamber. The glass is fixed to an immobile base and "
                   "cannot be broken. It is on a hinge and can be turned. "
                   "It must not be allowed to run out or a trap effect takes "
                   "place. Trap effect: " + trapEffect);
    table.addEntry("Portals in the room must be traversed to access otherwise "
                   "inaccessible parts of the room. The portals are fixed to "
                   "movable frames, and need to be configured to solve the "
                   "room.");
    table.addEntry("Heavy objects must be pushed onto the correct floor "
                   "switches. Incorrect floor switch combinations trigger a "
                   "random trap effect: " + trapEffect);
    table.addEntry("Trap solutions are at the bottom of 60' deep pits filled "
                   "to the top with water.");
    table.addEntry("Series of chains suspended over a 'bottomless' pit must "
                   "be swung on to interact with anything in the room. The "
                   "chains are only 10' long and not nearly long enough to "
                   "reach the bottom. Some of the chains are trap triggers "
                   "when weight is put on them.");
    table.addEntry("Stepping stones suspended in deep water are the only way "
                   "to traverse the room. Dex save each effect to remain "
                   "standing on one. 25% chance any new one stepped on is "
                   "fake and just floating there.");
    table.addEntry("Room appears to be a bridge over lava, but the lava is"
                   "an illusion and the traps are centered on the bridge.");
    table.addEntry("Room is a bridge over lava.");


    return table.getRollTableEntry();
}

QString complexTrap::Countermeasures(int tier)
{
    ++tier;
    RandomTable table;

    QString standard = TrapTables::trapDisarm();
    table.addEntry(standard, 2);
    table.addEntry("Intelegence (Investigation) check as an action allows "
                   "PC to anticipate the trap and avoid it. Effect gets "
                   "disadvantage to hit, or PC gets advantage to DC rolls.");
    table.addEntry("PC may attack the element, giving the element advantage "
                   "on its next attack against them or giving the PC "
                   "disadvantage on saves. Each successful attack reduces "
                   "the damage or effectiveness of the element by 2.");
    table.addEntry("PC may use thieves tools and a dex check against the DC "
                   "of the element to reduce its effectiveness by 2.");
    table.addEntry("The element is not succeptible to countermeasures.");
    table.addEntry("Element is actually an illusion, doing psychic damaged "
                   "unless disbelieved.");
        return table.getRollTableEntry();
}

QString complexTrap::Experience(int tier)
{
    if (tier == 1) { return "650 xp"; }
    if (tier == 2) { return "3,850 xp"; }
    if (tier == 3) { return "11,100 xp"; }
    return "21,500 xp";
}

