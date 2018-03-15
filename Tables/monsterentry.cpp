#include "monsterentry.h"

MonsterEntry::MonsterEntry(QString name, QList<int> tier, QList<Biome> biome,
                           Intellect intellect, int qty,
                           int weight)
{
    _name = name;
    _tier = tier;
    _biome = biome;
    _intellect = intellect;
    _qty = qty;
    _weight = weight;
}


QList<int> MonsterEntry::tier() const
{
    return _tier;
}

Intellect MonsterEntry::intellect() const
{
    return _intellect;
}

int MonsterEntry::qty() const
{
    return _qty;
}

int MonsterEntry::weight() const
{
    return _weight;
}

QString MonsterEntry::name() const
{
    return _name;
}
