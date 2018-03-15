#ifndef DUNGEONTABLES_H
#define DUNGEONTABLES_H

#include <QString>
#include "randomtable.h"
#include "npctables.h"

class DungeonTables
{
public:
    DungeonTables();
    static QString dungeonType();
    static QString dungeonLocation();
    static QString dungeonCreator();
    static QString dungeonHistory();
};

#endif // DUNGEONTABLES_H
