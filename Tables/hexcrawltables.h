#ifndef HEXCRAWLTABLES_H
#define HEXCRAWLTABLES_H


#include "randomtable.h"
#include "dice.h"
#include "traptables.h"
#include "dungeontables.h"

class HexcrawlTables
{
public:
    HexcrawlTables();

    static QString keyHex(int tier);
    static QString keyNauticalHex(int tier);

    static QString pregenHex(int tier);
    static QString randomEcnounter(int tier);

    static QString mainFeature(int tier);
    static QString wanderingEncounter(int tier);

    static QString mainNauticalFeature(int tier);
    static QString wanderingNauticalEncounter(int tier);
    static QString nauticalGuard();

    static QString remoteStructure(int tier);
    static QString ruinedStructure(int tier);
    static QString naturalStructure(int tier);
    static QString remarkableEvent(int tier);
    static QString lair(int tier);
    static QString pastEvent(int tier);
    static QString npcEncounter(int tier);
    static QString currentEvent(int tier);
    static QString lostItem(int tier);
    static QString animalHerd();

    static QString minorItemChance();
    static QString itemAndBanditChance();

    static QString tracks();

    static QString statue();

    static QString mineralResource();
    static QString gemMine();
};

#endif // HEXCRAWLTABLES_H
