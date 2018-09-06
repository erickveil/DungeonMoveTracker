#ifndef ODNDCASTLES_H
#define ODNDCASTLES_H

#include "tabletemplate.h"

class ODnDCastleOccupants
{
public:
    QString Leader;
    QString LeaderRace;
    QString Retainers;
    int NumOfRetainers;

    ODnDCastleOccupants();
};

/**
 * White box pdf p. 102 - Monsters and Traps, pg. 15.
 * @brief The ODnDCastles class
 */
class ODnDCastles
{
public:
    ODnDCastles();
    bool isOccupantsComingOut(int distanceInHexes);
    bool isOccupantsHostile();
    ODnDCastleOccupants choseCastleOccupants();
};

#endif // ODNDCASTLES_H
