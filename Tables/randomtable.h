#ifndef RANDOMTABLE_H
#define RANDOMTABLE_H

#include <QList>
#include <QtGlobal>

#include "tableentry.h"
#include "dice.h"

class RandomTable
{
    QList<TableEntry> _possibleEntries;
    uint _seed;


public:
    RandomTable();
    void addEntry(QString entry, int weight = 1);
    TableEntry rollTable();
    QString getRollTableEntry();
private:

    void _addEntry(TableEntry entry);
};

#endif // RANDOMTABLE_H
