#ifndef ENCOUNTERTABLES_H
#define ENCOUNTERTABLES_H

#include <QString>
#include "randomtable.h"
#include "dice.h"
#include "monstertable.h"
#include "adventuretables.h"

class EncounterTables
{
public:
    EncounterTables();

    static QString generateActivity();
    static QString monsterDowntime();
    static QString animalDowntime();
    static QString humanoidAttacksUrban();
    static QString creatureAttacksUrban();
    static QString motivation();

    static QString generateUrbanEncounter(int tier);
    static QString generateUrbanEncounterNight(int tier);
    static QString friendlyHumanoidUrbanActivity();
};

#endif // ENCOUNTERTABLES_H
