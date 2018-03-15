#ifndef NONENCOUNTERS_H
#define NONENCOUNTERS_H

#include "randomtable.h"
#include "dice.h"

class NonEncounters
{
public:
    NonEncounters();

    static QString universal();
    static QString mountain();
    static QString plains();
    static QString forest();

};

#endif // NONENCOUNTERS_H
