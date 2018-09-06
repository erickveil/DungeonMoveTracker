#ifndef ODNDCASTLES_H
#define ODNDCASTLES_H

#include "tabletemplate.h"
#include "odndcastleoccupants.h"
#include <math.h>

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

    /**
     * Get your results here.
     *
     * @brief toString
     * @param distance
     * @return
     */
    QString toString(int distance);
};

#endif // ODNDCASTLES_H
