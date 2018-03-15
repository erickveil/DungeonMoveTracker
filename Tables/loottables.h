#ifndef LOOTTABLES_H
#define LOOTTABLES_H

#include <QString>
#include "dice.h"
#include "randomtable.h"
#include "treasuremaps.h"

class LootTables
{
    const static bool _lowHauls = true;
public:
    LootTables();
    static QString generateSpellbook(int tier);
    static QString wizardSpells(int level);

    static QString minorCommonMagicItems();
    static QString minorUncommonMagicItems();
    static QString minorRareMagicIterms();
    static QString minorVeryRareMagicItems();
    static QString minorLegendaryMagicItems();

    static QString majorUncommonMagicItems();
    static QString majorRareMagicItems();
    static QString majorVeryRareMagicItems();
    static QString majorLegendaryMagicItems();
    static QString selectMagicItemByTier(int tier);

    static QString itemCreator();
    static QString itemHistory();
    static QString potionDescription();
    static QString color();

    static QString gem(int tier);
    static QString art(int tier);
    static QString hoardCoins(int tier);

    static QString treasureContainer();
    static QString treasureHiddenBy();

    static QString generateTreasureHorde(int tier);
    static QString generateIndividualTreasure(int tier);
    static QString miscTreasure(int tier);
    static QString mundaneHorde(int tier);
    static QString adventureGear();
    static QString craftingComponents(int tier);
};

#endif // LOOTTABLES_H
