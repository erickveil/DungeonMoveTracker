#-------------------------------------------------
#
# Project created by QtCreator 2018-01-30T08:37:33
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DungeonMoveTracker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Tables/encountertables.cpp \
    Tables/loottables.cpp \
    Tables/monstertable.cpp \
    Tables/nonencounters.cpp \
    Tables/npctables.cpp \
    Tables/randomtable.cpp \
    Tables/tableentry.cpp \
    Tables/treasuremaps.cpp \
    Tables/dice.cpp \
    Tables/adventuretables.cpp \
    Tables/complextrap.cpp \
    Tables/dungeontables.cpp \
    Tables/monsterentry.cpp \
    Tables/randomchambers.cpp \
    Tables/traptables.cpp \
    Tables/hexcrawltables.cpp \
    Tables/odndcastles.cpp \
    odndcastleoccupants.cpp

HEADERS  += mainwindow.h \
    Tables/encountertables.h \
    Tables/loottables.h \
    Tables/monstertable.h \
    Tables/nonencounters.h \
    Tables/npctables.h \
    Tables/randomtable.h \
    Tables/tableentry.h \
    Tables/treasuremaps.h \
    Tables/dice.h \
    Tables/adventuretables.h \
    Tables/complextrap.h \
    Tables/dungeontables.h \
    Tables/monsterentry.h \
    Tables/randomchambers.h \
    Tables/traptables.h \
    Tables/hexcrawltables.h \
    Tables/tabletemplate.h \
    Tables/tableentrytemplate.h \
    Tables/odndcastles.h \
    odndcastleoccupants.h

FORMS    += mainwindow.ui
