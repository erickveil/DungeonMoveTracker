#ifndef TABLETEMPLATE_H
#define TABLETEMPLATE_H

#include <QList>
#include <QtGlobal>

#include "tableentrytemplate.h"
#include "dice.h"

enum GroupComposition {NullComp, SoloMook, SoloBoss, BossWithMooks, MookGroup};
enum Difficulty {NullDifficulty, Easy, Moderate, Hard, Deadly};
enum EncounterType {NullEncounterType, Individual, Family, Maleable, Mix, Npc,
                    Boss};
enum Environment {NullEnvironment, Dungeon, Underdark, Urban, Roads, Grasslands,
                  Coastal, Hill, Forest, Mountain, Swamp, Desert, Tundra, Demon,
                  Devil, Fiend, Fey, Elemental, Earth, Air, Fire, Water,
                  Ethereal, Astral, Guardian, Magical, Construct, Undead,
                  Shadow, Divine, Law, Chaos, Sea, Good, Evil, OuterPlanes,
                  InnerPlanes};

/**
 * RandomTable
 *
 * For templates, it works best if all the code is in the h file.
 * For templates that allow enum as a value, the enum should also be in the
 * same file.
 *
 * It has to do with the linker needing everything right there, so that it can
 * use just the template to create the needed class.
 * If the enum is somewhere else, for example, it doesn't know where to look
 * and we get linker errors.
 */
template <class Thing>
class TableTemplate
{
    TableEntryTemplate <Thing> _testEntry;
    QList<TableEntryTemplate <Thing> > _possibleEntries;
    uint _seed;


public:
    TableTemplate()
    {

    }

    void addEntry(Thing entry, int weight = 1)
    {
        TableEntryTemplate<Thing> record(entry, weight);
        _possibleEntries.append(record);
    }

    TableEntryTemplate <Thing> rollTable()
    {
        // populate full table
        QList<TableEntryTemplate <Thing> > fullTable;
        TableEntryTemplate<Thing> entry;
        foreach (entry, _possibleEntries) {
        for (int i = 0; i < entry.weight(); ++i) {
            fullTable.append(entry);
        }
        }

        // select from table
        int min = 0;
        int max = fullTable.size();
        int index = Dice::randomNumber(min, max-1);

        return fullTable[index];
    }

    Thing getRollTableEntry()
    {
        return rollTable().result();
    }

    int size()
    {
        return _possibleEntries.size();
    }

private:

    void _addEntry(TableEntryTemplate <Thing> entry)
    {
        _possibleEntries.append(entry);
    }
};

#endif // TABLETEMPLATE_H
