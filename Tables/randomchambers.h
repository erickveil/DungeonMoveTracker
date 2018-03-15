#ifndef RANDOMCHAMBERS_H
#define RANDOMCHAMBERS_H

#include <QString>
#include "dice.h"
#include "randomtable.h"
#include "monstertable.h"
#include "loottables.h"
#include "traptables.h"

class RandomChambers
{
public:
    RandomChambers();

    static QString generateGeneralRoom(int tier);
    static QString generateDeathTrapRoom(int dungeonLevel);
    static QString generateLairRoom(int dungeonLevel);
    static QString generateMineRoom(int tier);
    static QString generatePlanarGateRoom(int tier);
    static QString generateMazeRoomType(int tier);
    static QString generateStrongholdRoom(int tier);
    static QString generateTempleRoom(int tier);
    static QString generateToomb(int tier);
    static QString generateTreasureVault(int tier);
    static QString generateHallwayContents(int tier);
    static QString generateLibraryRoom(int tier);
    static QString generateCavernRoom(int tier);

    static QString generalDungeonRoomType();
    static QString deathTrapRoomType();
    static QString lairRoomType();
    static QString mazeRoomType();
    static QString mineRoomType();
    static QString planarGateRoomType();
    static QString strongholdRoom();
    static QString templeRoom();
    static QString tombRoom();
    static QString treasureVaultRoom();
    static QString libraryRoom();
    static QString cavern();

    static QString doorType();

    static QString currentChamberState();
    static QString chamberContents(int tier);
    static QString dungeonHazards();
    static QString obstacles();

    static QString poolEffects();
    static QString poolContents();

    static QString noises();
    static QString odors();
    static QString primaryFeature();
    static QString lighting();


};

#endif // RANDOMCHAMBERS_H
