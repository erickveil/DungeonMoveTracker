#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(QTime::currentTime().msec());
    _sinceLastRest.setHMS(0,0,0);

    ui->cbMoveMode->addItem("Human/Elf");
    ui->cbMoveMode->addItem("Dwarf/Halfling");
    ui->cbMoveMode->addItem("Mule");
    ui->cbMoveMode->addItem("Mule under load");
    ui->cbMoveMode->addItem("Horse, Draft");
    ui->cbMoveMode->addItem("Horse, Draft under load");
    ui->cbMoveMode->addItem("Horse, Light");
    ui->cbMoveMode->addItem("Horse, Light under load");
    ui->cbMoveMode->addItem("Warhorse, Medium");
    ui->cbMoveMode->addItem("Warhorse, Medium under load");
    ui->cbMoveMode->addItem("Warhorse, Heavy");
    ui->cbMoveMode->addItem("Warhorse, Heavy under load");
    ui->cbMoveMode->addItem("Riding Dog");
    ui->cbMoveMode->addItem("Riding Dog under load");
    ui->cbMoveMode->addItem("Cart/Wagon");
    ui->cbMoveMode->addItem("Raft");
    ui->cbMoveMode->addItem("Small Boat");

    ui->cbTerrain->addItem("Plains");
    ui->cbTerrain->addItem("Hills");
    ui->cbTerrain->addItem("Mountains");
    ui->cbTerrain->addItem("Forest (sparse)");
    ui->cbTerrain->addItem("Forest (medium)");
    ui->cbTerrain->addItem("Forest (dense)");
    ui->cbTerrain->addItem("Swamp");
    ui->cbTerrain->addItem("Jungle");
    ui->cbTerrain->addItem("Moor");
    ui->cbTerrain->addItem("Desert");
    ui->cbTerrain->addItem("Tundra, frozen");

    ui->cbConditions->addItem("Normal");
    ui->cbConditions->addItem("Storm");
    ui->cbConditions->addItem("Storm, powerful");
    ui->cbConditions->addItem("Hurricane");

    ui->cbSnowCover->addItem("No snow cover");
    ui->cbSnowCover->addItem("Snow cover");
    ui->cbSnowCover->addItem("Heavy snow cover");

    ui->cbActivities->addItem("Normal travel");
    ui->cbActivities->addItem("Cautious travel");
    ui->cbActivities->addItem("Exploration");
    ui->cbActivities->addItem("Foraging");
    ui->cbActivities->addItem("Leading Mount");
    ui->cbActivities->addItem("River Crossing");
    ui->cbActivities->addItem("Hustling");

    ui->cbGroundType->addItem("Very soft ground");
    ui->cbGroundType->addItem("Soft ground");
    ui->cbGroundType->addItem("Firm ground");
    ui->cbGroundType->addItem("Hard ground");

    ui->cbTrackSize->addItem("Fine");
    ui->cbTrackSize->addItem("Diminutive");
    ui->cbTrackSize->addItem("Tiny");
    ui->cbTrackSize->addItem("Small");
    ui->cbTrackSize->addItem("Large");
    ui->cbTrackSize->addItem("Huge");
    ui->cbTrackSize->addItem("Gargantuan");
    ui->cbTrackSize->addItem("Colossal");

    ui->cbRoad->addItem("Highway");
    ui->cbRoad->addItem("Road/Trail");
    ui->cbRoad->addItem("Old Trail");
    ui->cbRoad->addItem("Trackless");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddMin1_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 1 minute to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));
    _checkForFatigue();
    _checkLight();
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
    QTime endOfMarch(4,0);
    QString msg = ui->MessageOut->toPlainText();

    if (_sinceLastRest > endOfMarch && _sinceLastRest <= fullDay) {
        int hoursLeft = fullDay.hour() - _sinceLastRest.hour();
        msg += "\n- About " + QString::number(hoursLeft) + " hours until end of march.";
        ui->MessageOut->setPlainText(msg);
    }
    if (_sinceLastRest > fullDay) {
        msg += "\n- Check for exhaustion.";
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

    msg = division +  "\n------\n" + msg ;
    ui->MessageOut->setPlainText(msg);
}

void MainWindow::_bluffPerception()
{
    bool shouldRoll = _roll(1,100) <= 10;
    if (shouldRoll) {
        QString msg = ui->MessageOut->toPlainText();
        msg += "\n- Have the party roll for perception (for no reason).";
        ui->MessageOut->setPlainText(msg);
    }
}

void MainWindow::_checkLight()
{
    QString msg = ui->MessageOut->toPlainText();
    if (_lightSource == "") {
        msg += "\n- No light source.";
        ui->MessageOut->setPlainText(msg);
        return;
    }

    QTime expire;
    int hour;
    int minute;


    if (_lightSource == "candle") {
        hour = _lightLit.hour() + 1;
        minute = _lightLit.minute();
        expire.setHMS(hour, minute, 0);
    }
    else if (_lightSource == "torch") {
        hour = _lightLit.hour() + 1;
        minute = _lightLit.minute();
        expire.setHMS(hour, minute, 0);
    }
    else {
        hour = _lightLit.hour() + 6;
        minute = _lightLit.minute();
        expire.setHMS(hour, minute, 0);
    }

    if (_getTime() < expire) { return; }

    msg += "\n- The " + _lightSource + " is going out.";
    ui->MessageOut->setPlainText(msg);
    _lightSource = "";

}

void MainWindow::_backupLast()
{
    _lastMessage = ui->MessageOut->toPlainText();
    _lastTime = ui->TimeDisplay->text();
}

float MainWindow::_factorTerrainInMove(float baseMove)
{
    QString terrain = ui->cbTerrain->currentText();
    QString road = ui->cbRoad->currentText();
    if (terrain == "Plains") {
        if (road == "Highway") {
            return baseMove;
        }
        else if (road == "Road/Trail") {
            return baseMove;
        }
        else if (road == "Old Trail") {
            return baseMove;
        }
        else { // trackless
            return baseMove * 0.75;
        }
    }
    else if (terrain == "Hills") {
        if (road == "Highway") {
            return baseMove;
        }
        else if (road == "Road/Trail") {
            return baseMove * 0.75;
        }
        else if (road == "Old Trail") {
            return baseMove * 0.75;
        }
        else { // trackless
            return baseMove * 0.5;
        }
    }
    else if (terrain == "Mountains") {
        if (road == "Highway") {
            return baseMove * 0.75;
        }
        else if (road == "Road/Trail") {
            return baseMove * 0.75;
        }
        else if (road == "Old Trail") {
            return baseMove * 0.75;
        }
        else { // trackless
            return baseMove * 0.5;
        }
    }
    else if (terrain == "Forest (sparse)") {
        if (road == "Highway") {
            return baseMove;
        }
        else if (road == "Road/Trail") {
            return baseMove;
        }
        else if (road == "Old Trail") {
            return baseMove;
        }
        else { // trackless
            return baseMove * 0.5;
        }
    }
    else if (terrain == "Forest (medium)") {
        if (road == "Highway") {
            return baseMove;
        }
        else if (road == "Road/Trail") {
            return baseMove;
        }
        else if (road == "Old Trail") {
            return baseMove;
        }
        else { // trackless
            return baseMove * 0.5;
        }
    }
    else if (terrain == "Forest (dense)") {
        if (road == "Highway") {
            return baseMove;
        }
        else if (road == "Road/Trail") {
            return baseMove;
        }
        else if (road == "Old Trail") {
            return baseMove;
        }
        else { // trackless
            return baseMove * 0.5;
        }
    }
    else if (terrain == "Swamp") {
        if (road == "Highway") {
            return baseMove;

        }
        else if (road == "Road/Trail") {
            return baseMove * 0.75;
        }
        else if (road == "Old Trail") {
            return baseMove * 0.75;
        }
        else { // trackless
            return baseMove * 0.5;
        }
    }
    else if (terrain == "Jungle") {
        if (road == "Highway") {
            return baseMove;
        }
        else if (road == "Road/Trail") {
            return baseMove * 0.75;
        }
        else if (road == "Old Trail") {
            return baseMove * 0.75;
        }
        else { // trackless
            return baseMove * 0.25;
        }
    }
    else if (terrain == "Moor") {
        if (road == "Highway") {
            return baseMove;
        }
        else if (road == "Road/Trail") {
            return baseMove;
        }
        else if (road == "Old Trail") {
            return baseMove;
        }
        else { // trackless
            return baseMove * 0.75;
        }
    }

    else if (terrain == "Desert") {
        if (road == "Highway") {
            return baseMove;
        }
        else if (road == "Road/Trail") {
            return baseMove * 0.5;
        }
        else if (road == "Old Trail") {
            return baseMove * 0.5;
        }
        else { // trackless
            return baseMove * 0.5;
        }
    }
    else { // tundra
        if (road == "Highway") {
            return baseMove;
        }
        else if (road == "Road/Trail") {
            return baseMove * 0.75;
        }
        else if (road == "Old Trail") {
            return baseMove * 0.75;
        }
        else { // trackless
            return baseMove * 0.75;
        }
    }
}

float MainWindow::_factorMoveConditions(float baseMove)
{
    float moveRate = baseMove;
    bool isGiant = ui->chGiantTerrain->isChecked();
    bool isPoorVisibility = ui->chPoorVis->isChecked();
    bool isExtremeClimate = ui->chColdClimate->isChecked();
    QString snowCover = ui->cbSnowCover->currentText();
    QString weather = ui->cbConditions->currentText();
    QString activity = ui->cbActivities->currentText();

    if (isGiant) {
        moveRate *= 0.75;
    }
    if (isPoorVisibility) {
        moveRate *= 0.5;
    }
    if (isExtremeClimate) {
        moveRate *= 0.75;
    }

    if (weather == "Storm") {
        moveRate *= 0.75;
    }
    else if (weather == "Storm, powerful") {
        moveRate *= 0.5;
    }
    else if (weather == "Hurricane") {
        moveRate *= 0.1;
    }

    if (snowCover == "Snow cover") {
        moveRate *= 0.5;
    }
    else if (snowCover == "Heavy snow cover") {
        moveRate *= 0.25;
    }

    if (activity == "Cautious travel") {
        moveRate *= 0.75;
    }
    else if (activity == "Exploration") {
        moveRate *= 0.5;
    }
    else if (activity == "Foraging") {
        moveRate *= 0.5;
    }
    else if (activity == "Leading Mount") {
        moveRate *= 0.75;
    }
    else if (activity == "River Crossing") {
        moveRate *= 0.75;
    }
    else if (activity == "Hustling") {
        moveRate *= 2;
    }

    return moveRate;

}

void MainWindow::on_AddMin10_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 10 minute to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60 * 10);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

    _checkForFatigue();
    _checkLight();
}

void MainWindow::on_AddMin30_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 30 minute to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60 * 30);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

    _checkForFatigue();
    _checkLight();
}

void MainWindow::on_AddHr1_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 1 hour to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60 * 60);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

    _checkForFatigue();
    _checkLight();
}

void MainWindow::on_AddHr4_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 4 hour to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60 * 60 * 4);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

    _checkForFatigue();
    _checkLight();
}

void MainWindow::on_AddHr8_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 8 hour to time");
    _timeOfDay();
    QTime time = _getTime();
    QTime newTime = time.addSecs(60 * 60 * 8);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

    _checkForFatigue();
    _checkLight();
}

void MainWindow::on_pbShortRest_clicked()
{
    _backupLast();
    QString msg = "- Short Rest Attempt...";

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
        int failTime = 1;
        if (_roll(1,8) == 1) {
            restFail = true;
            failTime = _roll(1,3) * 10;
        }

        QTime time = _getTime();

        if (restFail) {
            failTime = _roll(1,3) * 10;
            QTime newTime = time.addSecs(60 * 20 * failTime);
            ui->TimeDisplay->setText(newTime.toString("hh:mm"));
            msg += QString::number(failTime)
                    + " minutes pass in hex.\n- Interrupted: Wandering monster";
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

    _checkLight();
}

void MainWindow::on_pbLongRest_clicked()
{
    _backupLast();
    QString msg = "- Long Rest Attempt...";
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
                        + " minutes pass in dungeon.\n- Interrupted: Wandering "
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
                    + " hours pass in hex.\n- Interrupted: Wandering monster";
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
    _checkLight();
}

void MainWindow::on_pbDungeonMove_clicked()
{
    _backupLast();
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
    QString msg = "- Move " + turnMoveStr + " squares (" + feetMoveStr + " feet)";

    if (_roll(1,8) == 1) {
        msg += "\n- Wandering monster";
    }


    ui->MessageOut->setPlainText(msg);

    QTime startTime = _getTime();
    QTime endTime = startTime.addSecs(60 * 20);
    _sinceLastRest = _sinceLastRest.addSecs(60 * 20);
    _checkForFatigue();
    ui->TimeDisplay->setText(endTime.toString("hh:mm"));
    _timeOfDay();
    _bluffPerception();
    _checkLight();
}

void MainWindow::on_pbHexMove_clicked()
{
    _backupLast();
    _lastCrawl = "hex";
    QString mrStr = ui->MoveRate->text();
    bool ok;
    int moveRate = mrStr.toInt(&ok);
    if (!ok) {
        ui->MessageOut->setPlainText("Invalid Movement Rate");
        ui->MoveRate->setText("30");
        return;
    }

    float baseMove = (moveRate / 2.5);
    float terrainMove = _factorTerrainInMove(baseMove);
    float conditionMove = _factorMoveConditions(terrainMove);
    int watchMoveMiles = (int)conditionMove;

    double watchMoveHex = watchMoveMiles / 12.0;
    QString watchMoveStr = QString::number(watchMoveMiles);
    QString hexMoveStr = QString::number(watchMoveHex, 'f', 2);

    ui->HPW->setText(hexMoveStr);
    ui->tbMilesPerWatch->setText(watchMoveStr);


    QString msg = "- Move " + watchMoveStr + " miles (" + hexMoveStr + " hex)";

    bool isEncounter = _roll(1,8) == 1;
    if (isEncounter) {
        bool isLocation = _roll(1,100) <= 50;
        if (isLocation) {
            msg += "\n- Hex Location Encounter (make second encounter check if "
                   "location is hidden, or 2 checks if exploring)";
        }
        else {
            int tracks = _roll(1,100);
            int lair = _roll(1,100);
            msg += "\n- Random Encounter. Tracks check: " + QString::number(tracks)
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
    _checkLight();
}

void MainWindow::on_pbUrbanMove_clicked()
{
    _backupLast();
    _lastCrawl = "city";
    QString msg = "- Move 1 neighborhood";

    QTime startTime = _getTime();
    QTime endTime = startTime.addSecs(60 * 30);
    _sinceLastRest = _sinceLastRest.addSecs(60 * 30);
    ui->TimeDisplay->setText(endTime.toString("hh:mm"));

    bool isEncounter = _roll(1,6) == 1;
    if (isEncounter) {
        bool isLocation = _roll(1,100) <= 10;
        if (isLocation) {
            msg += "\n- Random Hook to neighborhood adventure.";
        }
        else {
            msg += "\n- Random Encounter.";
        }
    }

    ui->MessageOut->setPlainText(msg);
    _timeOfDay();
    _bluffPerception();
    _checkLight();
}

void MainWindow::on_pbForceRest_clicked()
{
    _backupLast();
        _sinceLastRest.setHMS(0,0,0);
        ui->MessageOut->setPlainText("- The party feels refreshed!");
        _timeOfDay();
}

void MainWindow::on_pbTorch_clicked()
{
    _backupLast();
    QTime time = _getTime();
    _lightLit = time;
    _lightSource = "torch";
    QString msg = ui->MessageOut->toPlainText();
    msg += "\n- Lit a torch.";
    ui->MessageOut->setPlainText(msg);
}

void MainWindow::on_pbCandle_clicked()
{
    _backupLast();
    QTime time = _getTime();
    _lightLit = time;
    _lightSource = "candle";
    QString msg = ui->MessageOut->toPlainText();
    msg += "\n- Lit a candle";
    ui->MessageOut->setPlainText(msg);
}

void MainWindow::on_pbLamp_clicked()
{
    _backupLast();
    QTime time = _getTime();
    _lightLit = time;
    _lightSource = "lamp";
    QString msg = ui->MessageOut->toPlainText();
    msg += "\n- Lit a lamp";
    ui->MessageOut->setPlainText(msg);
}

// undo button
void MainWindow::on_pushButton_clicked()
{
    if (_lastMessage != "") { ui->MessageOut->setPlainText(_lastMessage); }
    if (_lastTime != "") { ui->TimeDisplay->setText(_lastTime); }
}

void MainWindow::on_cbMoveMode_currentTextChanged(const QString &arg1)
{

    if (arg1 == "Human/Elf") {
        ui->MoveRate->setText("30");
    }

    else if (arg1 == "Dwarf/Halfling") {
        ui->MoveRate->setText("25");

    }

    else if (arg1 == "Mule") {
        ui->MoveRate->setText("30");

    }

    else if (arg1 == "Mule under load") {
        ui->MoveRate->setText("20");

    }

    else if (arg1 == "Horse, Draft") {
        ui->MoveRate->setText("50");

    }

    else if (arg1 == "Horse, Draft under load") {
        ui->MoveRate->setText("35");

    }

    else if (arg1 == "Horse, Light") {
        ui->MoveRate->setText("60");

    }

    else if (arg1 == "Horse, Light under load") {
        ui->MoveRate->setText("40");

    }

    else if (arg1 == "Warhorse, Medium") {
        ui->MoveRate->setText("50");

    }

    else if (arg1 == "Warhorse, Medium under load") {
        ui->MoveRate->setText("35");

    }

    else if (arg1 == "Warhorse, Heavy") {
        ui->MoveRate->setText("50");

    }

    else if (arg1 == "Warhorse, Heavy under load") {
        ui->MoveRate->setText("35");

    }

    else if (arg1 == "Riding Dog") {
        ui->MoveRate->setText("40");

    }

    else if (arg1 == "Riding Dog under load") {
        ui->MoveRate->setText("20");

    }

    else if (arg1 == "Cart/Wagon") {
        ui->MoveRate->setText("20");

    }

    else if (arg1 == "Raft") {
        ui->MoveRate->setText("5");

    }

    else if (arg1 == "Small Boat") {
        ui->MoveRate->setText("10");

    }
    else {

    }


}
