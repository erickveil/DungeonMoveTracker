#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(QTime::currentTime().msec());
    _sinceLastRest.setHMS(0,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddMin1_clicked()
{
    ui->MessageOut->setPlainText("Added 1 minute to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));
}

QTime MainWindow::_getTime()
{
    QTime defaultTime(9,0);
    QString currentTime = ui->TimeDisplay->text();
    QStringList splitTime = currentTime.split(":");
    if (splitTime.size() != 2) {
        ui->MessageOut->setPlainText("Invalid Time Format");
        return defaultTime;
    }
    QString hrStr = splitTime[0];
    bool ok;
    int hour = hrStr.toInt(&ok);
    if (!ok) {
        ui->MessageOut->setPlainText("Invalid Time Hour");
        return defaultTime;
    }
    QString minStr = splitTime[1];
    int minute = minStr.toInt(&ok);
    if (!ok) {
        ui->MessageOut->setPlainText("Invalid Time Minute");
        return defaultTime;
    }
    QTime time(hour, minute);

    return time;
}

int MainWindow::_randomNumber(int min, int max)
{
    return qRound(((double)(qrand() % (max+1 - min)) + (double)min));
}

int MainWindow::_roll(int number, int sides)
{
    int total = 0;
    for (int i = 0; i < number; ++i) {
        total += _randomNumber(1, sides);
    }
    return total;
}

void MainWindow::_checkForFatigue()
{
    QTime fullDay(8, 0);
    if (_sinceLastRest > fullDay) {
        QString msg = ui->MessageOut->toPlainText();
        msg += "\nCheck for exhaustion.";
        ui->MessageOut->setPlainText(msg);
    }
}

void MainWindow::_timeOfDay()
{
    QString msg = ui->MessageOut->toPlainText();
    QTime time = _getTime();

    QTime midnightStart(0, 0);
    QTime moondarkStart(2, 30);
    QTime nightendStart(5, 0);
    QTime dawnStart(7,30);
    QTime morningStart(10, 0);
    QTime highsunStart(12, 0);
    QTime afternoonStart(14, 30);
    QTime duskStart(17, 0);
    QTime sunsetStart(19, 30);
    QTime eveningStart(22, 0);

    QString division;
    if (time >= midnightStart && time < moondarkStart)  {
        division = "Midnight";
    }
    else if (time >= moondarkStart && time < nightendStart) {
        division = "Moondark";
    }
    else if (time >= nightendStart && time < dawnStart) {
        division = "Nightend";
    }
    else if (time >= dawnStart && time < morningStart) {
        division = "Dawn";
    }
    else if (time >= morningStart && time < highsunStart) {
        division = "Morning";
    }
    else if (time >= highsunStart && time < afternoonStart) {
        division = "Highsun";
    }
    else if (time >= afternoonStart && time < duskStart) {
        division = "Afternoon";
    }
    else if (time >= duskStart && time < sunsetStart) {
        division = "Dusk";
    }
    else if (time >= sunsetStart && time < eveningStart) {
        division = "Sunset";
    }
    else {
        division = "Evening";
    }

    msg = division +  "\n" + msg;
    ui->MessageOut->setPlainText(msg);
}

void MainWindow::_bluffPerception()
{
    bool shouldRoll = _roll(1,100) <= 10;
    if (shouldRoll) {
        QString msg = ui->MessageOut->toPlainText();
        msg += "\nHave the party roll for perception (for no reason).";
        ui->MessageOut->setPlainText(msg);
    }
}

void MainWindow::on_AddMin10_clicked()
{
    ui->MessageOut->setPlainText("Added 10 minute to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60 * 10);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

}

void MainWindow::on_AddMin30_clicked()
{
    ui->MessageOut->setPlainText("Added 30 minute to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60 * 30);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

}

void MainWindow::on_AddHr1_clicked()
{
    ui->MessageOut->setPlainText("Added 1 hour to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60 * 60);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

}

void MainWindow::on_AddHr4_clicked()
{
    ui->MessageOut->setPlainText("Added 4 hour to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60 * 60 * 4);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

}

void MainWindow::on_AddHr8_clicked()
{
    ui->MessageOut->setPlainText("Added 8 hour to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60 * 60 * 8);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

}

void MainWindow::on_pbShortRest_clicked()
{
    QString msg = "Short Rest Attempt...";

    // dungeon resting
    if (_lastCrawl == "dungeon") {
        int minutesRested = 0;
        bool restFail = false;
        for (int i = 0; i < 3; ++i) {
            QTime time = _getTime();
            QTime newTime = time.addSecs(60 * 20);
            minutesRested += 20;
            ui->TimeDisplay->setText(newTime.toString("hh:mm"));
            if (_roll(1,8) == 1) {
                restFail = true;
                msg += QString::number(minutesRested)
                    + " minutes pass in dungeon.\nInterrupted: Wandering monster";
                break;
            }
        }
        if (!restFail) {
            msg += "\n1 hour Short Rest in dungeon complete!";
            _bluffPerception();
        }
    }
    else if (_lastCrawl == "hex") {
        bool restFail = false;
        int failTime;
        if (_roll(1,8) == 1) {
            restFail = true;
            failTime = _roll(1,3) * 10;
        }

        QTime time = _getTime();

        if (restFail) {
            QTime newTime = time.addSecs(60 * 20 * failTime);
            ui->TimeDisplay->setText(newTime.toString("hh:mm"));
            msg += QString::number(failTime)
                    + " minutes pass in hex.\nInterrupted: Wandering monster";
        }
        else {
            QTime newTime = time.addSecs(60 * 60);
            ui->TimeDisplay->setText(newTime.toString("hh:mm"));
            msg += "\n1 hour Short Rest in hex complete!";
            _bluffPerception();
        }
    }
    else { // city, other
        QTime time = _getTime();
        QTime newTime = time.addSecs(60 * 60);
        ui->TimeDisplay->setText(newTime.toString("hh:mm"));
        msg += "\n1 hour Short Rest complete!";
            _bluffPerception();
    }

    ui->MessageOut->setPlainText(msg);

    _timeOfDay();
}

void MainWindow::on_pbLongRest_clicked()
{
    QString msg = "Long Rest Attempt...";
    if (_lastCrawl == "dungeon") {
        bool isInterrupted = false;
        for (int turn = 0; turn < 24; ++turn) {
            int totalMinutesRested = turn * 20;
            int hoursRested = qFloor(totalMinutesRested / 60);
            int minutesRested = totalMinutesRested - (hoursRested * 60);
            isInterrupted = _roll(1,8) == 1;
            if (isInterrupted) {
                msg += "\n"
                        + QString::number(hoursRested)
                        + " hours and "
                        + QString::number(minutesRested)
                        + " minutes pass in dungeon.\nInterrupted: Wandering "
                          "monster";
                break;
            }

            QTime time = _getTime();
            QTime newTime = time.addSecs(60 * 20);
            ui->TimeDisplay->setText(newTime.toString("hh:mm"));
        }
        if (!isInterrupted) {
            msg += "\n8 hour dungeon Long Rest complete!";
            _sinceLastRest.setHMS(0,0,0);
            _bluffPerception();
        }
    }
    else if (_lastCrawl == "hex") {
        bool isInterrupted = _roll(1,8) <= 2;
        int hoursRested = (isInterrupted) ? _roll(1,8) : 8;
        QTime time = _getTime();
        QTime newTime = time.addSecs(60 * 60 * hoursRested);
        ui->TimeDisplay->setText(newTime.toString("hh:mm"));
        if (isInterrupted) {
            msg += "\n" + QString::number(hoursRested)
                    + " hours pass in hex.\nInterrupted: Wandering monster";
        }
        else {
            msg += "\n8 hour hex Long Rest complete!";
            _sinceLastRest.setHMS(0,0,0);
            _bluffPerception();
        }
    }
    else {
        msg += "\n8 hour Long Rest complete!";
        QTime time = _getTime();
        QTime newTime = time.addSecs(60 * 60 * 8);
        ui->TimeDisplay->setText(newTime.toString("hh:mm"));
        _sinceLastRest.setHMS(0,0,0);
            _bluffPerception();
    }

    ui->MessageOut->setPlainText(msg);
    _timeOfDay();
}

void MainWindow::on_pbDungeonMove_clicked()
{
    _lastCrawl = "dungeon";
    QString mrStr = ui->MoveRate->text();
    bool ok;
    int moveRate = mrStr.toInt(&ok);
    if (!ok) {
        ui->MessageOut->setPlainText("Invalid Movement Rate");
        ui->MoveRate->setText("30");
        return;
    }

    int turnMoveRate = (moveRate / 6) * 2;
    int turnMoveFeet = turnMoveRate * 10;
    QString turnMoveStr = QString::number(turnMoveRate);
    QString feetMoveStr = QString::number(turnMoveFeet);
    ui->SPT->setText(turnMoveStr);
    QString msg = "Move " + turnMoveStr + " squares (" + feetMoveStr + " feet)";

    if (_roll(1,8) == 1) {
        msg += "\nWandering monster";
    }


    ui->MessageOut->setPlainText(msg);

    QTime startTime = _getTime();
    QTime endTime = startTime.addSecs(60 * 20);
    _sinceLastRest = _sinceLastRest.addSecs(60 * 20);
    _checkForFatigue();
    ui->TimeDisplay->setText(endTime.toString("hh:mm"));
    _timeOfDay();
    _bluffPerception();
}

void MainWindow::on_pbHexMove_clicked()
{
    _lastCrawl = "hex";
    QString mrStr = ui->MoveRate->text();
    bool ok;
    int moveRate = mrStr.toInt(&ok);
    if (!ok) {
        ui->MessageOut->setPlainText("Invalid Movement Rate");
        ui->MoveRate->setText("30");
        return;
    }

    int watchMoveMiles = (moveRate / 2.5);
    double watchMoveHex = watchMoveMiles / 12.0;
    QString watchMoveStr = QString::number(watchMoveMiles);
    QString hexMoveStr = QString::number(watchMoveHex, 'f', 2);
    ui->HPW->setText(hexMoveStr);
    QString msg = "Move " + watchMoveStr + " miles (" + hexMoveStr + " hex)";

    bool isEncounter = _roll(1,8) == 1;
    if (isEncounter) {
        bool isLocation = _roll(1,100) <= 50;
        if (isLocation) {
            msg += "\nHex Location Encounter (make second encounter check if "
                   "location is hidden, or 2 checks if exploring)";
        }
        else {
            int tracks = _roll(1,100);
            int lair = _roll(1,100);
            msg += "\nRandom Encounter. Tracks check: " + QString::number(tracks)
                    + ", Lair check: " + QString::number(lair);
        }
    }

    ui->MessageOut->setPlainText(msg);

    QTime startTime = _getTime();
    QTime endTime = startTime.addSecs(60 * 60 * 4);
    _sinceLastRest = _sinceLastRest.addSecs(60 * 60 * 4);
    _checkForFatigue();
    ui->TimeDisplay->setText(endTime.toString("hh:mm"));

    _timeOfDay();
    _bluffPerception();
}

void MainWindow::on_pbUrbanMove_clicked()
{
    _lastCrawl = "city";
    QString msg = "Move 1 neighborhood";

    QTime startTime = _getTime();
    QTime endTime = startTime.addSecs(60 * 30);
    _sinceLastRest = _sinceLastRest.addSecs(60 * 30);
    ui->TimeDisplay->setText(endTime.toString("hh:mm"));

    bool isEncounter = _roll(1,6) == 1;
    if (isEncounter) {
        bool isLocation = _roll(1,100) <= 10;
        if (isLocation) {
            msg += "\nRandom Hook to neighborhood adventure.";
        }
        else {
            msg += "\nRandom Encounter.";
        }
    }

    ui->MessageOut->setPlainText(msg);
    _timeOfDay();
    _bluffPerception();
}

void MainWindow::on_pbForceRest_clicked()
{
        _sinceLastRest.setHMS(0,0,0);
        ui->MessageOut->setPlainText("The party feels refreshed!");
        _timeOfDay();
}
