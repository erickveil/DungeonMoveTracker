#ifndef ODNDCASTLEOCCUPANTS_H
#define ODNDCASTLEOCCUPANTS_H

#include <QString>

class ODnDCastleOccupants
{
public:
    QString Leader;
    QString Retainers;
    int NumOfRetainers;
    int NumOfLightCrossbow;
    int NumOfHeavyFoot;
    QString Activity;

    ODnDCastleOccupants();
    QString toString();
};

#endif // ODNDCASTLEOCCUPANTS_H
