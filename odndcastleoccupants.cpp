#include "odndcastleoccupants.h"

ODnDCastleOccupants::ODnDCastleOccupants()
{

}

QString ODnDCastleOccupants::toString()
{
   QString str = QString("Castle:\n")
           + "Ruled by: " + Leader + "\n"
           + "Retainers: " + QString::number(NumOfRetainers) + " " + Retainers + "\n"
           + "Guards:\n"
           + QString::number(NumOfHeavyFoot) + " heavy foot\n"
           + QString::number(NumOfLightCrossbow) + " light crossbow\n"
           + "Interaction: " + Activity;
   return str;
}



