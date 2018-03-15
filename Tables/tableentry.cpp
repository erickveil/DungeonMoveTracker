#include "tableentry.h"

QString TableEntry::result() const
{
    return _result;
}

int TableEntry::weight() const
{
    return _weight;
}

TableEntry::TableEntry()
{

}

TableEntry::TableEntry(QString result, int weight=1)
{
    _result = result;
    _weight = weight;

}

