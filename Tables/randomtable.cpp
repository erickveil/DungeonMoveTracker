#include "randomtable.h"

RandomTable::RandomTable()
{

}

void RandomTable::_addEntry(TableEntry entry)
{
    _possibleEntries.append(entry);
}

void RandomTable::addEntry(QString entry, int weight)
{
    TableEntry record(entry, weight);
    _possibleEntries.append(record);
}

TableEntry RandomTable::rollTable()
{
    // populate full table
    QList<TableEntry> fullTable;
    TableEntry entry;
    foreach (entry, _possibleEntries) {
        for (int i = 0; i < entry.weight(); ++i) {
            fullTable.append(entry);
        }
    }

    // select from table
    int min = 0;
    int max = fullTable.size();
    //int index = (qrand() % ((max) - min) + min);
    int index = Dice::randomNumber(min, max-1);

    return fullTable[index];
}

QString RandomTable::getRollTableEntry()
{
    return rollTable().result();
}

