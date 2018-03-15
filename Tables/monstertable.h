#ifndef MONSTERTABLE_H
#define MONSTERTABLE_H

#include <QList>
#include "tableentry.h"
#include "randomtable.h"
#include "monsterentry.h"
#include "dice.h"
#include "npctables.h"
#include "adventuretables.h"
#include "loottables.h"
#include "traptables.h"
#include "complextrap.h"



class MonsterTable
{
    const static int ANY_TIER = -1;

public:
    MonsterTable();

    static QString encounterLevel();
    static QString dungeonMonster(int tier);
    static QString undermountainMonster(int tier);
    static QString urbanEncounterXge(int tier);
    static QString urbanEncountersUnique();
    static QString sewerEncounter(int tier);
    static QString coastalEncounter(int tier);
    static QString forestEncounter(int tier);
    static QString grasslandsEncounter(int tier);
    static QString hillEncounter(int tier);
    static QString mountainEncounter(int tier);

    /**
     * @brief nauticalEncounter
     * Sea adventures *while on a ship* use underwater encounters when players
     * enter the water.
     * @param tier
     * @return
     */
    static QString nauticalEncounter(int tier);

    static QString guardianFoe(int tier);

    static QString generateUrbanEncounter(int tier);
    static QString generateUrbanEncounterNight(int tier);
    static QString friendlyHumanoidUrbanActivity();

private:
    // don't need race or gender
    static QString _intellegentBlock();
    // don't need race
    static QString _raceBlock();
    // only class provided
    static QString _npcAdventurerBlock();
    // only class provided - normal races
    static QString _npcCommonerBlock();
    // intelegent with motivation provided
    static QString _motivatedBlock();
    // animals
    static QString _animalBlock();
    // loot only
    static QString _loot(int tier);

};

#endif // MONSTERTABLE_H
