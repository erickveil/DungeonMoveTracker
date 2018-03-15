#ifndef DICE_H
#define DICE_H


#include <QtGlobal>
#include <QDateTime>

class Dice
{
public:
    Dice();
    static int randomNumber(int min, int max);
    static int roll(int number, int sides, int mod = 0);

};

#endif // DICE_H
