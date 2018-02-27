#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <qmath.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString _lastCrawl;
    QTime _sinceLastRest;
    QTime _lightLit;
    QString _lightSource;
    QString _lastMessage;
    QString _lastTime;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_AddMin1_clicked();

    void on_AddMin10_clicked();

    void on_AddMin30_clicked();

    void on_AddHr1_clicked();

    void on_AddHr4_clicked();

    void on_AddHr8_clicked();

    void on_pbShortRest_clicked();

    void on_pbLongRest_clicked();

    void on_pbDungeonMove_clicked();

    void on_pbHexMove_clicked();

    void on_pbUrbanMove_clicked();

    void on_pbForceRest_clicked();

    void on_pbTorch_clicked();

    void on_pbCandle_clicked();

    void on_pbLamp_clicked();

    void on_pushButton_clicked();

    void on_cbMoveMode_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QTime _getTime();
    int _randomNumber(int min, int max);
    int _roll(int number, int sides);
    void _checkForFatigue();
    void _timeOfDay();
    void _bluffPerception();
    void _checkLight();
    void _backupLast();
    float _factorTerrainInMove(float baseMove);
    float _factorMoveConditions(float baseMove);
    void _doNavigation();
    void _doTracking();
};

#endif // MAINWINDOW_H
