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
    switch(occupantRoll) {
    case 1:
        occupantObj.Leader = "Lord (Level 10 fighter)";
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
    }
    return occupantObj;

}
