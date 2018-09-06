#include "odndcastles.h"

ODnDCastles::ODnDCastles()
{

}

bool ODnDCastles::isOccupantsComingOut(int distanceInHexes)
{
    if (distanceInHexes == 0) {
        return Dice::roll(1,6) <= 3;
    }
    else if (distanceInHexes == 1) {
        return Dice::roll(1,6) <= 2;
    }
    else if (distanceInHexes == 2) {
        return Dice::roll(1,6) <= 1;
    }
    else {
        return false;
    }
}

bool ODnDCastles::isOccupantsHostile()
{
    return Dice::roll(1,6) <= 3;
}

ODnDCastleOccupants ODnDCastles::choseCastleOccupants()
{
    ODnDCastleOccupants occupantObj;
    int occupantRoll = Dice::roll(1,6);
    int retainerRoll = Dice::roll(1,4);
    int numOfGuards = Dice::roll(3,6) * 10;
    occupantObj.NumOfHeavyFoot = static_cast<int>(round(numOfGuards / 2));
    occupantObj.NumOfLightCrossbow = static_cast<int>(round(numOfGuards / 2));

    auto toll = QString::number(Dice::roll(1,6) * 100);
    auto fighterAction = QString("Challenges to a duel or charges ")
            + toll + " gp toll. Will take loser's armor if wins, or if loses, "
            + "will host party up to 1 month, supply with 2 weeks rations, and "
              "provide heavy warhorses if the party requires.";
    toll = QString::number(Dice::roll(1,4) * 1000);
    auto mageAction = QString("Geas party to get treasure if not hostile, and will ")
            + "take half, and first choice of magic items (Priority: misc, "
              "wand/staff, rings). Evil will require magic item as a toll, or "
            + toll + " gp.";
    auto priestAction = QString("Takes a tighe of 10% of all money and jewels.")
            + "otherwise will cast Quest on the party, or slay them if evil.";


    switch(occupantRoll) {
    case 1:
        occupantObj.Leader = "Lord (Level 10 fighter)";
        occupantObj.Activity = fighterAction;
        switch(retainerRoll) {
        case 1:
            occupantObj.Retainers = "Champions (Level 7 Fighters)";
            occupantObj.NumOfRetainers = Dice::roll(1,8);
            break;
        case 2:
            occupantObj.Retainers = "Heros (level 4 Fighters) riding Griffons";
            occupantObj.NumOfRetainers = Dice::roll(1,6);
            break;
        case 3:
            occupantObj.Retainers = "Myrmidons (level 6 Fighters)";
            occupantObj.NumOfRetainers = Dice::roll(1, 10);
            break;
        default:
            occupantObj.Retainers = "Giants";
            occupantObj.NumOfRetainers = Dice::roll(1,4);
            break;
        }
        break;
    case 2:
        occupantObj.Leader = "Superhero (Level 8 Fighter)";
        occupantObj.Activity = fighterAction;
        switch(retainerRoll) {
        case 1:
            occupantObj.Retainers = "Myrmidons (level 6 Fighters)";
            occupantObj.NumOfRetainers = Dice::roll(1,8);
            break;
        case 2:
            occupantObj.Retainers = "Heros (level 4 Fighters) riding Rocs";
            occupantObj.NumOfRetainers = Dice::roll(1,4);
            break;
        case 3:
            occupantObj.Retainers = "Ogres";
            occupantObj.NumOfRetainers = Dice::roll(1, 4);
            break;
        default:
            occupantObj.Retainers = "Swashbucklers";
            occupantObj.NumOfRetainers = Dice::roll(1,8);
            break;
        }
        break;
    case 3:
        occupantObj.Leader = "Wizard";
        occupantObj.Activity = mageAction;
        switch(retainerRoll) {
        case 1:
            occupantObj.Retainers = "Dragons";
            occupantObj.NumOfRetainers = Dice::roll(1,4);
            break;
        case 2:
            occupantObj.Retainers = "Chimeras";
            occupantObj.NumOfRetainers = Dice::roll(1,4);
            break;
        case 3:
            occupantObj.Retainers = "Wyverns";
            occupantObj.NumOfRetainers = Dice::roll(1, 4);
            break;
        default:
            occupantObj.Retainers = "Basilisks";
            occupantObj.NumOfRetainers = Dice::roll(1,4);
            break;
        }
        break;
    case 4:
        occupantObj.Leader = "Necromancer";
        occupantObj.Activity = mageAction;
        switch(retainerRoll) {
        case 1:
            occupantObj.Retainers = "Chimeras";
            occupantObj.NumOfRetainers = Dice::roll(1,4);
            break;
        case 2:
            occupantObj.Retainers = "Manticores";
            occupantObj.NumOfRetainers = Dice::roll(1,6);
            break;
        case 3:
            occupantObj.Retainers = "Lycanthropes";
            occupantObj.NumOfRetainers = Dice::roll(1, 12);
            break;
        default:
            occupantObj.Retainers = "Gargoyles";
            occupantObj.NumOfRetainers = Dice::roll(1,12);
            break;
        }
        break;
    case 5:
        occupantObj.Leader = "Patriarch (level 8 cleric)";
        occupantObj.Activity = priestAction;
        switch(retainerRoll) {
        case 1:
            occupantObj.Retainers = "Heroes";
            occupantObj.NumOfRetainers = Dice::roll(1,20);
            break;
        case 2:
            occupantObj.Retainers = "Superheroes";
            occupantObj.NumOfRetainers = Dice::roll(1,6);
            break;
        case 3:
            occupantObj.Retainers = "Treants";
            occupantObj.NumOfRetainers = Dice::roll(1, 10);
            break;
        default:
            occupantObj.Retainers = "Heroes riding Hippogriffs";
            occupantObj.NumOfRetainers = Dice::roll(1,8);
            break;
        }
        break;
    default:
        occupantObj.Leader = "Evil High Priest";
        occupantObj.Activity = priestAction;
        switch(retainerRoll) {
        case 1:
            occupantObj.Retainers = "Trolls";
            occupantObj.NumOfRetainers = Dice::roll(1,10);
            break;
        case 2:
            occupantObj.Retainers = "Vampires";
            occupantObj.NumOfRetainers = Dice::roll(1,6);
            break;
        case 3:
            occupantObj.Retainers = "White Apes";
            occupantObj.NumOfRetainers = Dice::roll(1, 20);
            break;
        default:
            occupantObj.Retainers = "Spectres";
            occupantObj.NumOfRetainers = Dice::roll(1,10);
            break;
        }
        break;
    }
    return occupantObj;

}

QString ODnDCastles::toString(int distance)
{
    auto occupants = choseCastleOccupants();
    QString comingOut = (isOccupantsComingOut(distance))
                ? "- Retainers will ride out with demands.\n"
                : "";
    QString hostility = (isOccupantsHostile())
                  ? "- Residents are hostile to party."
                  : "- Residents are neutral to party.";

    QString str = occupants.toString() + "\n" + comingOut + hostility;
    return str;
}


