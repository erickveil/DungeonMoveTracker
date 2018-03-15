#ifndef COMPLEXTRAP_H
#define COMPLEXTRAP_H

#include "randomtable.h"
#include "traptables.h"

class complexTrap
{

public:
    complexTrap();

    static QString generateTrap(int tier);

    static QString effectDivision();
    static QString trigger(int tier);
    static QString initiative(int tier);
    static QString ActiveElements(QString severity, int tier);
    static QString DynamicElements(int tier);
    static QString ConstantElements(QString severity, int tier);
    static QString Countermeasures(int tier);
    static QString Experience(int tier);
};

#endif // COMPLEXTRAP_H
