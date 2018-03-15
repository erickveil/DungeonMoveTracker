#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(QTime::currentTime().msec());
    _undoSinceLastRest = _sinceLastRest;
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

    ui->cbConditions->addItem("No Storms");
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
    ui->cbActivities->addItem("Tracking");
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

    _advanceAwakeTime(60);
    /*
    QTime time = _getTime();
    QTime newTime = time.addSecs(60);
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));
    _checkForFatigue();
    _checkLight();
    */
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

void MainWindow::_advanceAwakeTime(int seconds)
{
    _undoSinceLastRest = _sinceLastRest;
    _sinceLastRest = _sinceLastRest.addSecs(seconds);
    _checkForFatigue();

    QTime currentTime = _getTime();
    QTime newTime = currentTime.addSecs(seconds);
    if (currentTime > newTime) { _advanceOneDay(); }
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));

    _checkLight();
}

QString MainWindow::_advanceRestTime(int seconds)
{
    QTime currentTime = _getTime();
    QTime newTime = currentTime.addSecs(seconds);
    QString warning = "";
    if (currentTime > newTime) {
        warning = _advanceOneDay();
    }
    ui->TimeDisplay->setText(newTime.toString("hh:mm"));
    return warning;
}

QString MainWindow::_advanceOneDay()
{
    QString msg = ui->MessageOut->toPlainText();
    QString warning = "";
    ++_daysTraveled;
    ui->tbDaysTraveled->setText(QString::number(_daysTraveled));

    bool ok;
    QString partyStr = ui->tbPartySize->text();
    QString rationStr = ui->tbRations->text();
    int partySize = partyStr.toInt(&ok);
    if (!ok) {
        partySize = 5;
        ui->tbPartySize->setText("5");
    }
    int rations = rationStr.toInt(&ok);
    if (!ok) {
        rations = 0;
        ui->tbRations->setText("0");
    }

    if (!ui->cbGoodberry->isChecked()) {
        int rationsUsed = partySize;
        if (rationsUsed > rations) {
            QString numStarved = QString::number(rationsUsed - rations);
            warning = "\n* Not enough Food. Apply 1 level of exhaustion to "
                + numStarved + " party members.";
            msg += warning;
            ui->tbRations->setText("0");
            ui->MessageOut->setPlainText(msg);
        }
        else {
            rations -= rationsUsed;
            ui->tbRations->setText(QString::number(rations));
        }
    }
    return warning;
}

QString MainWindow::_createWanderingMonster()
{
    int tier = ui->sbTier->value();
    if (_lastCrawl == "dungeon") {
        return MonsterTable::dungeonMonster(tier);
    }
    else {
        QString biome = ui->cbTerrain->currentText();
        if (biome == "Plains") {
            return MonsterTable::grasslandsEncounter(tier);
        }
        else if (biome == "Hills") {
            return MonsterTable::hillEncounter(tier);
        }
        else if (biome ==  "Mountains") {
            return MonsterTable::mountainEncounter(tier);
        }
        else if (biome == "Forest (sparse)") {
            return MonsterTable::forestEncounter(tier);

        }
        else if (biome == "Forest (medium)") {
            return MonsterTable::forestEncounter(tier);

        }
        else if (biome == "Forest (dense)") {
            return MonsterTable::forestEncounter(tier);

        }
        /*
        else if (biome == "Swamp") {
            //return MonsterTable::swampEncounter(tier);
            return MonsterTable::grasslandsEncounter(tier);

        }
        else if (biome == "Jungle") {
            return MonsterTable::forestEncounter(tier);
        }
        else if (biome == "Moor") {

            return MonsterTable::grasslandsEncounter(tier);
        }
        else if (biome == "Desert") {
            return MonsterTable::desertEncounter(tier);
        }
        */
        else {
            return MonsterTable::grasslandsEncounter(tier);

        }
    }

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

    int hoursRemaining;
    QString light;

    QString division;
    if (time >= midnightStart && time < moondarkStart)  {
        division = "Midnight";
        hoursRemaining = dawnStart.hour() - time.hour();
        light = QString("Dark: ") + QString::number(hoursRemaining) + " hours until dawn.";
    }
    else if (time >= moondarkStart && time < nightendStart) {
        division = "Moondark";
        hoursRemaining = dawnStart.hour() - time.hour();
        light = QString("Dark: ") + QString::number(hoursRemaining) + " hours until dawn.";
    }
    else if (time >= nightendStart && time < dawnStart) {
        division = "Nightend";
        hoursRemaining = dawnStart.hour() - time.hour();
        light = QString("Dark: ") + QString::number(hoursRemaining) + " hours until dawn.";
    }
    else if (time >= dawnStart && time < morningStart) {
        division = "Dawn";
        hoursRemaining = 0;
        light = QString("Dark: ") + QString::number(hoursRemaining) + " hours until dawn.";
    }
    else if (time >= morningStart && time < highsunStart) {
        division = "Morning";
        hoursRemaining = sunsetStart.hour() - time.hour();
        light = QString("Light: ") + QString::number(hoursRemaining) + " hours until dark.";
    }
    else if (time >= highsunStart && time < afternoonStart) {
        division = "Highsun";
        hoursRemaining = sunsetStart.hour() - time.hour();
        light = QString("Light: ") + QString::number(hoursRemaining) + " hours until dark.";
    }
    else if (time >= afternoonStart && time < duskStart) {
        division = "Afternoon";
        hoursRemaining = sunsetStart.hour() - time.hour();
        light = QString("Light: ") + QString::number(hoursRemaining) + " hours until dark.";
    }
    else if (time >= duskStart && time < sunsetStart) {
        division = "Evening";
        hoursRemaining = sunsetStart.hour() - time.hour();
        light = QString("Light: ") + QString::number(hoursRemaining) + " hours until dark.";
    }
    else if (time >= sunsetStart && time < eveningStart) {
        division = "Sunset";
        hoursRemaining = 0;
        light = QString("Light: ") + QString::number(hoursRemaining) + " hours until dark.";
    }
    else {
        division = "Night";
        hoursRemaining = dawnStart.hour() - time.hour();
        light = QString("Dark: ") + QString::number(hoursRemaining) + " hours until dawn.";
    }

    msg = division
            + "\n" + light
            + "\n------\n" + msg ;
    ui->MessageOut->setPlainText(msg);
}

void MainWindow::_bluffPerception()
{
    bool shouldRoll = _roll(1,100) <= 5;
    if (shouldRoll) {
        QString msg = ui->MessageOut->toPlainText();
        msg += "\n- Have the party roll for perception (for no reason).";
        ui->MessageOut->setPlainText(msg);
    }
}

void MainWindow::_checkLight()
{
    if (ui->chLightSpell->isChecked()) { return; }

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
        if (road == "Highway") { return baseMove; }
        else if (road == "Road/Trail") { return baseMove; }
        else if (road == "Old Trail") { return baseMove; }
        else {  return baseMove * 0.75; } // trackless
    }
    else if (terrain == "Hills") {
        if (road == "Highway") { return baseMove; }
        else if (road == "Road/Trail") { return baseMove * 0.75; }
        else if (road == "Old Trail") { return baseMove * 0.75; }
        else { return baseMove * 0.5; } // trackless
    }
    else if (terrain == "Mountains") {
        if (road == "Highway") { return baseMove * 0.75; }
        else if (road == "Road/Trail") { return baseMove * 0.75; }
        else if (road == "Old Trail") { return baseMove * 0.75; }
        else { return baseMove * 0.5; } // trackless
    }
    else if (terrain == "Forest (sparse)") {
        if (road == "Highway") { return baseMove; }
        else if (road == "Road/Trail") { return baseMove; }
        else if (road == "Old Trail") { return baseMove; }
        else { return baseMove * 0.5; } // trackless
    }
    else if (terrain == "Forest (medium)") {
        if (road == "Highway") { return baseMove; }
        else if (road == "Road/Trail") { return baseMove; }
        else if (road == "Old Trail") { return baseMove; }
        else { return baseMove * 0.5; } // trackless
    }
    else if (terrain == "Forest (dense)") {
        if (road == "Highway") { return baseMove; }
        else if (road == "Road/Trail") { return baseMove; }
        else if (road == "Old Trail") { return baseMove; }
        else { return baseMove * 0.5; } // trackless
    }
    else if (terrain == "Swamp") {
        if (road == "Highway") { return baseMove;  }
        else if (road == "Road/Trail") { return baseMove * 0.75; }
        else if (road == "Old Trail") { return baseMove * 0.75; }
        else { return baseMove * 0.5; } // trackless
    }
    else if (terrain == "Jungle") {
        if (road == "Highway") { return baseMove; }
        else if (road == "Road/Trail") { return baseMove * 0.75; }
        else if (road == "Old Trail") { return baseMove * 0.75; }
        else { return baseMove * 0.25; } // trackless
    }
    else if (terrain == "Moor") {
        if (road == "Highway") { return baseMove; }
        else if (road == "Road/Trail") { return baseMove; }
        else if (road == "Old Trail") { return baseMove; }
        else { return baseMove * 0.75; } // trackless
    }

    else if (terrain == "Desert") {
        if (road == "Highway") { return baseMove; }
        else if (road == "Road/Trail") { return baseMove * 0.5; }
        else if (road == "Old Trail") { return baseMove * 0.5; }
        else { return baseMove * 0.5; } // trackless
    }
    else { // tundra
        if (road == "Highway") { return baseMove; }
        else if (road == "Road/Trail") { return baseMove * 0.75; }
        else if (road == "Old Trail") { return baseMove * 0.75; }
        else { return baseMove * 0.75; } // trackless
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

    if (isGiant) { moveRate *= 0.75; }
    if (isPoorVisibility) { moveRate *= 0.5; }
    if (isExtremeClimate) { moveRate *= 0.75; }

    if (weather == "Storm") { moveRate *= 0.75; }
    else if (weather == "Storm, powerful") { moveRate *= 0.5; }
    else if (weather == "Hurricane") { moveRate *= 0.1; }

    if (snowCover == "Snow cover") { moveRate *= 0.5; }
    else if (snowCover == "Heavy snow cover") { moveRate *= 0.25; }

    if (activity == "Cautious travel") { moveRate *= 0.75; }
    else if (activity == "Exploration") { moveRate *= 0.5; }
    else if (activity == "Foraging") { moveRate *= 0.5; }
    else if (activity == "Tracking") { moveRate *= 0.5; }
    else if (activity == "Leading Mount") { moveRate *= 0.75; }
    else if (activity == "River Crossing") { moveRate *= 0.75; }
    else if (activity == "Hustling") { moveRate *= 2; }

    return moveRate;

}

void MainWindow::_doNavigation()
{
    QString msg = ui->MessageOut->toPlainText();
    QString navVal = ui->tbNavMod->text();
    bool ok;
    int navMod = navVal.toInt(&ok);
    if (!ok) {
        navMod = 0;
        ui->tbNavMod->setText("0");
    }
    bool hasNavTools = ui->cbNavTools->isChecked();
    QString terrain = ui->cbTerrain->currentText();
    QString road = ui->cbRoad->currentText();

    int dc;

    if (road == "Highway") {
        ui->MessageOut->setPlainText(msg
                                     + "\n- Navigation: auto success on road.");
        return;
    }
    else if (road == "Road/Trail") {
        ui->MessageOut->setPlainText(msg
                                     + "\n- Navigation: auto success on road.");
        return;
    }
    else if (road == "Old Trail") { dc = 12; }
    else if (terrain == "Plains") { dc = 12; }
    else if (terrain == "Hills") { dc = 14; }
    else if (terrain == "Mountains") { dc = 16; }
    else if (terrain == "Forest (sparse)") { dc = 14; }
    else if (terrain == "Forest (medium)") { dc = 16; }
    else if (terrain == "Forest (dense)") { dc = 18; }
    else if (terrain == "Swamp") { dc = 15; }
    else if (terrain == "Jungle") { dc = 16; }
    else if (terrain == "Moor") { dc = 14; }
    else if (terrain == "Desert") { dc = 12; }
    else {  dc = 12; } // tundra

    bool isPoorVisibility = ui->chPoorVis->isChecked();
    if (isPoorVisibility) { dc += 4; }

    QString activity = ui->cbActivities->currentText();

    if (activity == "Cautious travel") { dc -= 4; }
    else if (activity == "Hustling") { dc += 4; }

    ui->tbNavDc->setText(QString::number(dc));

    int roll1 = _roll(1,20) + navMod;
    int roll2 = _roll(1,20) + navMod;
    int navRoll = roll1;
    if (hasNavTools) { navRoll = roll1 > roll2 ? roll1 : roll2; }
    QString navToolRoll = (hasNavTools) ? ("/" + QString::number(roll2)) : "" ;
    int lostRoll = _roll(1,10);
    QString veerDirection;
    if (lostRoll < 5) {
        veerDirection += "veer left";
    }
    else if (lostRoll > 6) {
        veerDirection += "veer right";
    }
    else {
        veerDirection += "no veer";
    }

    if (navRoll > dc) {
        // success
        msg += "\n- Navigation: " + QString::number(roll1) + navToolRoll
                + " success!";
    }
    else {
        // lost!
        msg += "\n- Navigation: " + QString::number(roll1) + navToolRoll
                + " LOST!\n" + veerDirection;
    }

    ui->MessageOut->setPlainText(msg);
}

void MainWindow::_doTracking()
{
    QString activity = ui->cbActivities->currentText();
    if (activity != "Tracking") { return; }
    QString msg = ui->MessageOut->toPlainText();
    QString ground = ui->cbGroundType->currentText();
    bool isFreshSnow = ui->chFreshSnow->isChecked();
    QString trackSize = ui->cbTrackSize->currentText();
    QString qtyStrVal = ui->tbNumCreatures->text();
    QString ageStrVal = ui->tbTrackAge->text();
    QString rainStrVal = ui->tbRainHours->text();
    bool ok;
    int numTracks = qtyStrVal.toInt(&ok);
    if (!ok) {
        numTracks = 1;
        ui->tbNumCreatures->setText("1");
    }
    int ageTracks = ageStrVal.toInt(&ok);
    if (!ok) {
        ageTracks = 0;
        ui->tbTrackAge->setText("0");
    }
    int hoursRain = rainStrVal.toInt(&ok);
    if (!ok) {
        hoursRain = 0;
        ui->tbRainHours->setText("0");
    }

    int dc;
    int identifyDc;
    if (ground == "Very soft ground") { dc = 5; }
    else if (ground == "Soft ground") { dc = 10; }
    else if (ground == "Firm ground") { dc = 15; }
    else { dc = 20; } // Hard ground


    if (trackSize == "Fine") { dc += 8; }
    else if (trackSize == "Diminutive") { dc += 4; }
    else if (trackSize == "Tiny") { dc += 2; }
    else if (trackSize == "Small") { dc += 1; }
    // medium +0
    else if (trackSize == "Large") { dc -= 1; }
    else if (trackSize == "Huge") { dc -= 2; }
    else if (trackSize == "Gargantuan") { dc -= 4; }
    else if (trackSize == "Colassal"){ dc -= 8; }

    dc += ageTracks;
    dc += hoursRain;

    if (isFreshSnow) { dc += 10; }

    identifyDc = dc;
    dc += (numTracks / 3);

    msg += "\n- Tracking DC: " + QString::number(dc)
            + "\n- Identify Tracks DC: " + QString::number(identifyDc);
    ui->MessageOut->setPlainText(msg);
}

void MainWindow::_calcForage()
{
    QString terrain = ui->cbTerrain->currentText();
    QString road = ui->cbRoad->currentText();

    int dc;
    if (terrain == "Plains") { dc = 12; }
    else if (terrain == "Hills") { dc = 12; }
    else if (terrain == "Mountains") { dc = 18; }
    else if (terrain == "Forest (sparse)") { dc = 14; }
    else if (terrain == "Forest (medium)") { dc = 14; }
    else if (terrain == "Forest (dense)") { dc = 14; }
    else if (terrain == "Swamp") { dc = 16; }
    else if (terrain == "Jungle") { dc = 14; }
    else if (terrain == "Moor") { dc = 16; }
    else if (terrain == "Desert") { dc = 20; }
    else {  dc = 18; } // tundra

    if (road == "Highway") { dc += 10; }
    else if (road == "Road/Trail") { dc += 5; }
    else if (road == "Old Trail") { dc += 2; }


    bool isPoorVisibility = ui->chPoorVis->isChecked();
    if (isPoorVisibility) { dc += 2; }

    QString activity = ui->cbActivities->currentText();

    if (activity == "Foraging") {
        ui->tbForage->setText(QString::number(dc));
    }
    else  {
        ui->tbForage->setText("");
    }

}

void MainWindow::_calcHexProgress(int progressMiles)
{
    _undoTotalMilesMoved = _totalMilesMoved;
    _undoMilesMovedInHex = _milesMovedInHex;
    _undoMilesLeft = _milesLeft;

    bool isTurning = ui->chHexNearExit->isChecked();
    int totalHexDistance = isTurning ? 6 : 12;

    QString msg = ui->MessageOut->toPlainText();
    _totalMilesMoved += progressMiles;
    _milesMovedInHex += progressMiles;
    if (_milesMovedInHex >= totalHexDistance) {
        int hexesMoved = _milesMovedInHex / totalHexDistance;
        _milesMovedInHex = _milesMovedInHex - (hexesMoved * totalHexDistance);
        msg += "\n- NEW HEX: Check key!";
        ui->MessageOut->setPlainText(msg);
    }
    ui->tbHexProgress->setText(QString::number(_milesMovedInHex));
    _milesLeft = totalHexDistance - _milesMovedInHex;
    ui->tbMilesLeft->setText(QString::number(_milesLeft));

}

int MainWindow::_getSpotDistance()
{
    int dist;
    QString terrain = ui->cbTerrain->currentText();
    if (terrain == "Plains") { dist = _roll(6, 6) * 40; }
    else if (terrain == "Hills") { dist = _roll(2, 6) * 10; }
    else if (terrain == "Mountains") { dist = _roll(4, 10) * 10; }
    else if (terrain == "Forest (sparse)") { dist = _roll(3, 6) * 10; }
    else if (terrain == "Forest (medium)") { dist = _roll(2, 8) * 10; }
    else if (terrain == "Forest (dense)") { dist = _roll(2, 6) * 10; }
    else if (terrain == "Swamp") { dist = _roll(6, 6) * 10; }
    else if (terrain == "Jungle") { dist = _roll(2, 6) * 10; }
    else if (terrain == "Moor") { dist = _roll(2, 8) * 10; }
    else if (terrain == "Desert") { dist = _roll(6, 6) * 20; }
    else {  dist = _roll(6, 6) * 20; } // tundra

    return dist;

}



void MainWindow::on_AddMin10_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 10 minute to time");
    _advanceAwakeTime(60*10);
    _timeOfDay();
}

void MainWindow::on_AddMin30_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 30 minute to time");
    _advanceAwakeTime(60*30);
    _timeOfDay();
}

void MainWindow::on_AddHr1_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 1 hour to time");
    _advanceAwakeTime(60*60);
    _timeOfDay();
}

void MainWindow::on_AddHr4_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 4 hour to time");
    _advanceAwakeTime(60*60*4);
    _timeOfDay();
}

void MainWindow::on_AddHr8_clicked()
{
    _backupLast();
    ui->MessageOut->setPlainText("- Added 8 hour to time");
    _advanceAwakeTime(60*60*8);
    _timeOfDay();
}

void MainWindow::on_pbShortRest_clicked()
{
    _backupLast();
    QString msg = "- Short Rest Attempt...";
    QString warning = "";

    // dungeon resting
    if (_lastCrawl == "dungeon") {
        int minutesRested = 0;
        bool restFail = false;
        for (int i = 0; i < 3; ++i) {
            warning = _advanceRestTime(60*20);
            minutesRested += 20;
            if (_roll(1,8) == 1) {
                restFail = true;
                // TODO: insert _createWandering monster or encounter here
                msg += QString::number(minutesRested)
                    + " minutes pass in dungeon.\nInterrupted: Wandering monster";
                break;
            }
        }
        if (!restFail) {
            msg += "\n1 hour Short Rest in dungeon complete!";
            _bluffPerception();
            _undoSinceLastRest = _sinceLastRest;
            _sinceLastRest.setHMS(0,0,0);
        }
    }
    else if (_lastCrawl == "hex") {
        bool restFail = false;
        int failTime = 1;
        if (_roll(1,8) == 1) {
            restFail = true;
            failTime = _roll(1,3) * 10;
        }

        if (restFail) {
            failTime = _roll(1,3) * 10;
            warning = _advanceRestTime(60*20*failTime);
                // TODO: insert _createWandering monster or encounter here
            msg += QString::number(failTime)
                    + " minutes pass in hex.\n- Interrupted: Wandering monster";
        }
        else {
            warning = _advanceRestTime(60*60);
            msg += "\n1 hour Short Rest in hex complete!";
            _bluffPerception();
            _undoSinceLastRest = _sinceLastRest;
            _sinceLastRest.setHMS(0,0,0);
        }
    }
    else { // city, other
        warning = _advanceRestTime(60*60);

        msg += "\n1 hour Short Rest complete!";
        _bluffPerception();
        _undoSinceLastRest = _sinceLastRest;
        _sinceLastRest.setHMS(0,0,0);
    }

    msg += warning;
    ui->MessageOut->setPlainText(msg);

    _timeOfDay();
    _checkLight();
}

void MainWindow::on_pbLongRest_clicked()
{
    _backupLast();
    QString msg = "- Long Rest Attempt...";
    QString warning = "";
    if (_lastCrawl == "dungeon") {
        bool isInterrupted = false;
        for (int turn = 0; turn < 24; ++turn) {
            int totalMinutesRested = turn * 20;
            int hoursRested = qFloor(totalMinutesRested / 60);
            int minutesRested = totalMinutesRested - (hoursRested * 60);
            isInterrupted = _roll(1,8) == 1;
            if (isInterrupted) {
                // TODO: insert _createWandering monster or encounter here
                msg += "\n"
                        + QString::number(hoursRested)
                        + " hours and "
                        + QString::number(minutesRested)
                        + " minutes pass in dungeon.\n- Interrupted: Wandering "
                          "monster";
                break;
            }

            warning = _advanceRestTime(60*20);
        }
        if (!isInterrupted) {
            msg += "\n8 hour dungeon Long Rest complete!";
            _undoSinceLastRest = _sinceLastRest;
            _sinceLastRest.setHMS(0,0,0);
            _bluffPerception();
        }
    }
    else if (_lastCrawl == "hex") {
        bool isInterrupted = _roll(1,8) <= 2;
        int hoursRested = (isInterrupted) ? _roll(1,8) : 8;
        warning = _advanceRestTime(60*60*hoursRested);
        if (isInterrupted) {
                // TODO: insert _createWandering monster or encounter here
            msg += "\n" + QString::number(hoursRested)
                    + " hours pass in hex.\n- Interrupted: Wandering monster";
        }
        else {
            msg += "\n8 hour hex Long Rest complete!";
            _undoSinceLastRest = _sinceLastRest;
            _sinceLastRest.setHMS(0,0,0);
            _bluffPerception();
        }
    }
    else {
        msg += "\n8 hour Long Rest complete!";
        warning = _advanceRestTime(60*60*8);
        _undoSinceLastRest = _sinceLastRest;
        _sinceLastRest.setHMS(0,0,0);
            _bluffPerception();
    }

    msg += warning;
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
    QString msg = "- Move " + turnMoveStr + " squares (" + feetMoveStr
            + " feet)";

    if (_roll(1,8) == 1) {

                // TODO: insert _createWandering monster or encounter here
        msg += "\n- Wandering monster";
    }


    ui->MessageOut->setPlainText(msg);

    _advanceAwakeTime(60*20);
    _timeOfDay();
    _bluffPerception();
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

    bool isLocationHidden = ui->chHiddenLoc->isChecked();
    bool isHiddenLocationFound = _roll(1,8) == 1 && _roll(1,20) <= 10;

    bool isExplorationSuccess = false;
    if (ui->cbActivities->currentText() == "Exploration") {
        if (!isEncounter) {
            isExplorationSuccess = _roll(1,8) == 1 && _roll(1,20) <= 10;
            if (!isExplorationSuccess) {
                isExplorationSuccess = _roll(1,8) == 1 && _roll(1,20) <= 10;
            }
        }
    }

    if (isEncounter) {
        bool isLocation = _roll(1,20) <= 10;
        if (isLocation) {
            if (isLocationHidden && isHiddenLocationFound) {
                // TODO: insert _createWandering monster or encounter here
                msg += "\n- Hidden Hex Location Discovered";
            }
            else {
                // TODO: insert _createWandering monster or encounter here
                msg += "\n- Non-hidden Hex Location Discovered";
            }
        }
        else {
            int tracks = _roll(1,100);
            int lair = _roll(1,100);
                // TODO: insert _createWandering monster or encounter here
            msg += "\n- Random Encounter. Tracks check: "
                    + QString::number(tracks)
                    + ", Lair check: " + QString::number(lair)
                    + "\nCHECK HEX, NOT ENCOUNTER";
        }
        int distance = _getSpotDistance();
        msg += "\n  Encounter Distance: " + QString::number(distance) + " ft";

    }
    else if (isExplorationSuccess) {
        if (isLocationHidden && isHiddenLocationFound) {
                // TODO: insert _createWandering monster or encounter here
            msg += "\n- Exploration success: Hidden Hex Location Found.";
        }
        else if (isLocationHidden && !isHiddenLocationFound) {
            msg += "\n- Exploration partial success: Non-hidden Hex Location "
                   "Found.";
        }
        else {
            msg += "\n- Exploration success: Non-hidden Hex Location found.";
        }
    }

    ui->MessageOut->setPlainText(msg);

    _advanceAwakeTime(60*60*4);
    _timeOfDay();
    _calcHexProgress(watchMoveMiles);
    _bluffPerception();
    _doNavigation();
    _doTracking();
    _calcForage();
}

void MainWindow::on_pbUrbanMove_clicked()
{
    _backupLast();
    _lastCrawl = "city";
    QString msg = "- Move 1 neighborhood";

    _advanceAwakeTime(60*30);

    bool isEncounter = _roll(1,6) == 1;
    if (isEncounter) {
        bool isLocation = _roll(1,100) <= 10;
                // TODO: insert _createWandering monster or encounter here
        if (isLocation) { msg += "\n- Random Hook to neighborhood adventure."; }
        else { msg += "\n- Random Encounter."; }
    }

    ui->MessageOut->setPlainText(msg);
    _timeOfDay();
    _bluffPerception();
    _checkLight();
}

void MainWindow::on_pbForceRest_clicked()
{
    _backupLast();
    _undoSinceLastRest = _sinceLastRest;
    _sinceLastRest.setHMS(0,0,0);
    ui->MessageOut->setPlainText("- The party feels refreshed!");
    _timeOfDay();
}

void MainWindow::on_pbTorch_clicked()
{
    QString msg = ui->MessageOut->toPlainText();

    QString torchStr = ui->tbTorches->text();
    bool ok;
    int numTorches = torchStr.toInt(&ok);
    if (!ok) {
        numTorches = 0;
        ui->tbTorches->setText("0");
    }
    if (numTorches <= 0) {
        msg = QString("** NO TORCHES **") + "\n" + msg;
        ui->tbTorches->setText("0");
        ui->MessageOut->setPlainText(msg);
        return;
    }
    else {
        --numTorches;
        ui->tbTorches->setText(QString::number(numTorches));
    }

    _backupLast();
    QTime time = _getTime();
    _lightLit = time;
    _lightSource = "torch";
    msg += "\n- Lit a torch.";
    ui->MessageOut->setPlainText(msg);
}

void MainWindow::on_pbCandle_clicked()
{
    QString msg = ui->MessageOut->toPlainText();

    QString torchStr = ui->tbCandles->text();
    bool ok;
    int numTorches = torchStr.toInt(&ok);
    if (!ok) {
        numTorches = 0;
        ui->tbCandles->setText("0");
    }
    if (numTorches <= 0) {
        msg = QString("** NO CANDLES **") + "\n" + msg;
        ui->tbCandles->setText("0");
        ui->MessageOut->setPlainText(msg);
        return;
    }
    else {
        --numTorches;
        ui->tbCandles->setText(QString::number(numTorches));
    }

    _backupLast();
    QTime time = _getTime();
    _lightLit = time;
    _lightSource = "candle";
    msg += "\n- Lit a candle";
    ui->MessageOut->setPlainText(msg);
}

void MainWindow::on_pbLamp_clicked()
{
    QString msg = ui->MessageOut->toPlainText();

    QString torchStr = ui->tbLampOil->text();
    bool ok;
    int numTorches = torchStr.toInt(&ok);
    if (!ok) {
        numTorches = 0;
        ui->tbLampOil->setText("0");
    }
    if (numTorches <= 0) {
        msg = QString("** NO LAMP OIL **") + "\n" + msg;
        ui->MessageOut->setPlainText(msg);
        ui->tbLampOil->setText("0");
        return;
    }
    else {
        --numTorches;
        ui->tbLampOil->setText(QString::number(numTorches));
    }

    _backupLast();
    QTime time = _getTime();
    _lightLit = time;
    _lightSource = "lamp";
    msg += "\n- Lit a lamp";
    ui->MessageOut->setPlainText(msg);
}

// undo button
void MainWindow::on_pushButton_clicked()
{
    // show last message
    if (_lastMessage != "") { ui->MessageOut->setPlainText(_lastMessage); }
    if (_lastTime != "") { ui->TimeDisplay->setText(_lastTime); }

    // show last hex progress
    _totalMilesMoved = _undoTotalMilesMoved;
    _milesMovedInHex = _undoMilesMovedInHex;
    _milesLeft = _undoMilesLeft;
    ui->tbHexProgress->setText(QString::number(_milesMovedInHex));
    ui->tbMilesLeft->setText(QString::number(_milesLeft));

    // undo fatigue
    _sinceLastRest = _undoSinceLastRest;
}

void MainWindow::on_cbMoveMode_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Human/Elf") { ui->MoveRate->setText("30"); }
    else if (arg1 == "Dwarf/Halfling") { ui->MoveRate->setText("25");  }
    else if (arg1 == "Mule") { ui->MoveRate->setText("30");  }
    else if (arg1 == "Mule under load") { ui->MoveRate->setText("20");  }
    else if (arg1 == "Horse, Draft") { ui->MoveRate->setText("50");  }
    else if (arg1 == "Horse, Draft under load") { ui->MoveRate->setText("35"); }
    else if (arg1 == "Horse, Light") { ui->MoveRate->setText("60");  }
    else if (arg1 == "Horse, Light under load") { ui->MoveRate->setText("40"); }
    else if (arg1 == "Warhorse, Medium") { ui->MoveRate->setText("50");  }
    else if (arg1 == "Warhorse, Medium under load") { ui->MoveRate->setText("35"); }
    else if (arg1 == "Warhorse, Heavy") { ui->MoveRate->setText("50");  }
    else if (arg1 == "Warhorse, Heavy under load") { ui->MoveRate->setText("35"); }
    else if (arg1 == "Riding Dog") { ui->MoveRate->setText("40"); }
    else if (arg1 == "Riding Dog under load") { ui->MoveRate->setText("20");  }
    else if (arg1 == "Cart/Wagon") { ui->MoveRate->setText("20");  }
    else if (arg1 == "Raft") { ui->MoveRate->setText("5");  }
    else if (arg1 == "Small Boat") { ui->MoveRate->setText("10");  }
    else {  }
}
