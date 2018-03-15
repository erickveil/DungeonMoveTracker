#ifndef TREASUREMAPS_H
#define TREASUREMAPS_H

#include "randomtable.h"
#include "dice.h"
#include "randomchambers.h"

/*
 * Where is the treasure:
 *
 * - Same dungeon
 * 		- x levels up
 * 		- same level - x doors away
 * 		- x levels down
 *
 * - Another dungeon
 * 		- located at hex # 1d100
 * 		- located in same hex
 * 		- wilderness location not specified
 *
 * - Wilderness buried treasure (chance of guardian)
 * 		- located at hex # 1d100
 *
 * - Nautical
 *
 * - Another plane (map leads to gate)
 *
 * - Megadungeon: level 1d6
 * 		- Undermountain
 * 		- Stonehell
 * 		- House of Stone
 *
 * - Ruined city
 * 		- lcoated at hex # 1d100
 *
 * - Vault
 * 		- located at hex # 1d100
 *
 * - Waterdeep
 * 		- located in random neighborhood
 *
 * - Earthmote
 *
 * What language is the map written in? (must know language or cast comprehend
 * languages before using)
 *
 * Number of waypoints to the dungeon: 1d4
 *
 * Landmark at each waypoint (including start)
 *
 * - Wilderness
 * 		- Peculiar standing stone
 * 		- Statue
 * 		- Ruin
 * 		- Natural landmark
 * 		- Astrological landmark (only visible at specific time of year)
 * 		- Solar landmark (only visible at specific time of day)
 * 		- Lunar landmark (only visible at specific time of month)
 * 		- City/town/village
 * 		- Castle/fortress
 * 		- Magical effect/trigger
 * 		- Gate to another plane
 * 		- Gate to a foreign wilderness
 * 		- Gate to a dungeon
 *
 * - Dungeon
 * 		- Specific statue
 * 		- Trap
 * 		- Dungeon room feature
 * 		- Sigil etched on wall or hidden in room
 * 		- Magic mouth/triggered signal
 * 		- Door matching key
 *  	- Gate to another plane
 * 		- Gate to a foreign wilderness
 * 		- Gate to another part of the dungeon
 * 		- Gate to another dungeon
 * 		- Gate to a local hex
 *
 * Determine treasure
 *
 * Chance map is fake
 *
 * Value of map to a buyer
 *
 * Map type:
 * - normal, written on parchment
 * - magic compass directs bearer between waypoints
 * - Immovable scale model of area or dungeon
 * - painted on a wall
 * - tattooed on a creature or npc
 * - inside a spellbook
 * - inside a journal
 * - puzzle: only 1 of 1d4 map sections
 * - puzzle: requires special viewing device/decoder used at one or more waypoints
 * - dream item: object causes bearer to dream visions of next waypoint
 * - crystal ball: shows visions to viewer of next waypoint
 * - etched on a stone tablet
 * - location of scheduled gate(s) and clues to schedule(s)
 *
 */

class treasureMaps
{
public:
    treasureMaps();
    int _waypoints;

    static QString generateMap();
    static QString whereIsTreasure();
    static QString language();
    static QString wildernessLandmarks();
    static QString dungeonLandmarks();
    static QString mapType();
    static QString genWaypoints(QString type);
    static QString nauticalWaypoint();
    static QString nauticalDetails();
    static QString proximity();
    static QString hidden();
};

#endif // TREASUREMAPS_H
