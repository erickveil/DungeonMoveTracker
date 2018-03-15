#ifndef MONSTERENTRY_H
#define MONSTERENTRY_H

#include <QString>
#include <QList>

enum Biome { Any, Underdark, Urban, Plains, Forest, Mountain };
enum Intellect { Beast, Civilized };

class MonsterEntry
{
    QString _name;
    QList<int> _tier;
    QList<Biome> _biome;
    Intellect _intellect;
    int _qty;
    int _weight;

public:

    MonsterEntry(QString name, QList<int> tier, QList<Biome> biome,
                 Intellect intelect = Civilized, int qty=1,
                 int weight=1);
    QString name() const;
    QList<int> tier() const;
    Intellect intellect() const;
    int qty() const;
    int weight() const;
};

#endif // MONSTERENTRY_H
