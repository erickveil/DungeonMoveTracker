#ifndef ADVENTURETABLES_H
#define ADVENTURETABLES_H

#include <QString>
#include "randomtable.h"
#include "dungeontables.h"
#include "monstertable.h"
#include "randomchambers.h"


class AdventureTables
{
public:
    AdventureTables();

    static QString adventureHook();
    static QString adventureHookMethod();

    static QString hookSource();
    static QString hookMission();
    static QString hookVillains();
    static QString villainScheme();
    static QString villainMethods();
    static QString fullAdventureGen();

    static QString dungeonGoals();
    static QString generateRandomAdventure(int tier, QString type);

    static QString patronFaction();
    static QString guild();

};

#endif // ADVENTURETABLES_H
