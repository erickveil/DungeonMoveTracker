#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <QString>

class TableEntry
{
    QString _result;
    int _weight;

public:
    TableEntry();
    TableEntry(QString _result, int _weight);
    QString result() const;
    int weight() const;
};

#endif // TABLEENTRY_H
