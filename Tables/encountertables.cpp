#include "encountertables.h"

EncounterTables::EncounterTables()
{

}


QString EncounterTables::generateActivity()
{
    QString desc;
    desc = "Intelegent activity: " + monsterDowntime() + "\n";
    desc += "Animal activity: " + animalDowntime();
    return desc;
}

QString EncounterTables::monsterDowntime()
{
    RandomTable table;

    table.addEntry("Maintaining weapons and armour");
    table.addEntry("Sparing and training");
    table.addEntry("Cleaning room");
    table.addEntry("Shaving");
    table.addEntry("Enjoying a good meal");
    table.addEntry("Drinking beer");
    table.addEntry("Abusing a subordinate");
    table.addEntry("Tormenting a captive");
    table.addEntry("Slaughtering a animal to eat");
    table.addEntry("Gambling");
    table.addEntry("Making small animals fight for sport and bets");
    table.addEntry("Delousing self");
    table.addEntry("Applying first aid");
    table.addEntry("Cleaning boots");
    table.addEntry("Whining about dungeon conditions and superiors");
    table.addEntry("Punishing a subordinate");
    table.addEntry("Smoking");
    table.addEntry("High on shrooms");
    table.addEntry("Playing a game of skill");
    table.addEntry("Pranking a dorm mate");
    table.addEntry("Lancing a boil");
    table.addEntry("Having a brawl or wrestle");
    table.addEntry("Throwing knives at a target (possibly tied up and alive)");
    table.addEntry("Abusing a animal");
    table.addEntry("Trying to read dungeon time sheet or battle plan");
    table.addEntry("Talking about sweetheart back home (crude artwork or "
                   "memento like hair)");
    table.addEntry("Talking about plans to settle down after this tour of "
                   "duty");
    table.addEntry("Trimming toenails");
    table.addEntry("Grooming for date or meeting with boss");
    table.addEntry("Sitting on bed with a bucket from hangover");
    table.addEntry("Cheering at dancer or stripper");
    table.addEntry("Whittle a piece of wood");
    table.addEntry("Playing dice / Playing knuckle bones");
    table.addEntry("Arm wrestling");
    table.addEntry("Getting a tattoo");
    table.addEntry("Carving artwork on a monster tooth");
    table.addEntry("Telling dirty and/or racist jokes");
    table.addEntry("Picking teeth clean");
    table.addEntry("Cutting hair");
    table.addEntry("Eating a pie");
    table.addEntry("Eating sausages");
    table.addEntry("Eating a turnip");
    table.addEntry("Playing music and intently listening");
    table.addEntry("Reciting poetry");
    table.addEntry("Singing and dancing");
    table.addEntry("Getting drunk on rotgut grog");
    table.addEntry("Talking over local map");
    table.addEntry("Telling ghost stories");
    table.addEntry("Telling battle stories");
    table.addEntry("Eating smoked or dried fish");
    table.addEntry("A spot of cannibalism");
    table.addEntry("Looting a corpse");
    table.addEntry("Braiding hair");
    table.addEntry("Eating coarse moldy bread");
    table.addEntry("Looking at pornographic artwork");
    table.addEntry("Mending boots");
    table.addEntry("Skinning a rat, cat or dog");
    table.addEntry("Playing with pet");
    table.addEntry("Training pet");
    table.addEntry("Teaching a child");
    table.addEntry("Showing off to each other with feats of strength/prowess");
    table.addEntry("Reminiscing");
    table.addEntry("Making fun of humans: 'no after you' 'No! after you!'");
    table.addEntry("Disturbing grooming - removing bones or prosthetics for "
                   "cleaning, checking for lesions");
    table.addEntry("Posing and painting");
    table.addEntry("Weaving, knitting, sewing and other dungeon handicrafts");
    table.addEntry("Debugging battle plans");
    table.addEntry("Mourning over dead comrades body");
    table.addEntry("Teasing a huge foot long spider or scorpion");
    table.addEntry("Kicking about a severed head");
    table.addEntry("Consoling a comrade whose wife left him or some other "
                   "family tragedy");
    table.addEntry("Practicing battle cries");
    table.addEntry("Trying to reach down a drain or air vent for something");
    table.addEntry("Listening to instructions or pep talk from boss");
    table.addEntry("Rolling out dough");
    table.addEntry("Hunting, enraged, for lost keys");
    table.addEntry("Arguing about latest dungeon roster");
    table.addEntry("Reading aloud to illiterate comrades");
    table.addEntry("Talking about who is best god or demon or devil or old "
                   "one");
    table.addEntry("Comparing trophies like ears, fingers, scalps, skulls or "
                   "shrunken heads");
    table.addEntry("Bathing in a barrel or tub or with sponge or with oil and "
                   "scraper");
    table.addEntry("Discussing alignment morality");
    table.addEntry("Sharing recipes for food or poison");
    table.addEntry("Brewing grog in small keg or pumpkin before returning to "
                   "secret hiding spot");
    table.addEntry("Telling funny stories about murder");
    table.addEntry("Practicing drill or battle tactics or dance");
    table.addEntry("Performing sacrifice");
    table.addEntry("Counting coins");
    table.addEntry("Talking about wives and girlfriends and moms");
    table.addEntry("Planning a heist");
    table.addEntry("Kangaroo courtroom against peer who let team down");
    table.addEntry("Planing of stealing rival dorm idol or mascot (an ongoing "
                   "project)");
    table.addEntry("Hazing a new recruit");
    table.addEntry("Impersonating boss or enemies or priest");
    table.addEntry("Sniffing women's stolen clothing");
    table.addEntry("Biting heads off snakes");
    table.addEntry("Flexing muscles to see who is strongest");
    table.addEntry("Dressing in women's clothing for dungeon revue show "
                   "coming soon");
    table.addEntry("Reading name tags aloud from lost hats");
    table.addEntry("Playing board or card game");
    table.addEntry("Torturing a captive");
    table.addEntry("Fending off an invader and winning");
    table.addEntry("Fending off an invader and losing");
    table.addEntry("Escorting a prisoner");
    table.addEntry("Training a pet");
    table.addEntry("Teaching a child");

    return table.getRollTableEntry();
}

QString EncounterTables::animalDowntime()
{
    RandomTable table;

    table.addEntry("Waiting in ambush");
    table.addEntry("Emerging from a portal");
    table.addEntry("Trying to hide");
    table.addEntry("Hunting or stalking prey");
    table.addEntry("Killing something/someone");
    table.addEntry("Eating");
    table.addEntry("Defecating");
    table.addEntry("Wandering aimlessly");
    table.addEntry("Crying out, howling, or signaling");
    table.addEntry("Playing");
    table.addEntry("Guarding something");
    table.addEntry("Comming right at us!");
    table.addEntry("Staring off into space");
    table.addEntry("Inspecting something invisible");
    table.addEntry("Smelling something intently");
    table.addEntry("Drinking something");
    table.addEntry("Taking a bath");
    table.addEntry("Digging a hole");
    table.addEntry("Burrying something");
    table.addEntry("Running away from party");
    table.addEntry("Rolling on the ground");
    table.addEntry("Fleeing something bigger!");
    table.addEntry("Acting wounded");
    table.addEntry("Protecting eggs/young");
    table.addEntry("Sleeping");

    return table.getRollTableEntry();
}

QString EncounterTables::humanoidAttacksUrban()
{
    RandomTable table;

    table.addEntry("Imagined insult");
    table.addEntry("Mistaken identity");
    table.addEntry("Sacrifice to their demon god");
    table.addEntry("Hired assassin ambush");
    table.addEntry("Party killed their friends in an earlier adventure");
    table.addEntry("Hired mercenaries (less sneaky than the assassin approach)");
    table.addEntry("Madness from illness or magic");
    table.addEntry("Work for one of the party's enemies");
    table.addEntry("Trying to prove themselves as superior and make a name for themselves");
    table.addEntry("Disguised as beggars and the party does not pay them a coin");
    table.addEntry("Press gang for pirate ship");
    table.addEntry("Actually harassing someone else unless the party intervenes");
    table.addEntry("Have the way blocked off and are extracting tolls from everyone before they can pass. (the Watch is never around when you need them).");
    table.addEntry("This is a robbery!");
    table.addEntry("More like an attempted mugging");
    table.addEntry("Challenges the party to a duel");
    table.addEntry("Need to obtain really, really fresh dead bodies in otherwise good physical health for a mage's experiment");
    table.addEntry("Racism");
    table.addEntry("Religious differences");
    table.addEntry("A disagreement of political ideals");
    table.addEntry("Philosophical differences - the party just isn't nihilistic enough for them.");
    table.addEntry("Failure to return a slight nod with any sign of respect.");
    table.addEntry("Having a bad day and need someone to take it out on.");
    table.addEntry("Just looking for a fight.");
    table.addEntry("Drunk.");
    table.addEntry("Hypnotized/charmed into doing it.");
    table.addEntry("Sent by one of the player's backstories to haunt them.");
    table.addEntry("Adolescent foolishness.");
    table.addEntry("The voices told them to.");
    table.addEntry("Not in control of their own body and beg the party to help them the entire time they attack them.");
    table.addEntry("They don't attack, but get the local Watch to think the party is guilty of something they did, perhaps presenting the Watch with a forged 'kill on sight' wanted poster, framing the party as dangerous criminals.");
    table.addEntry("Attempt to lure the party into a dark alley or sewer entrance or abandoned building before attacking.");
    table.addEntry("Don't attack but present the party with a too good to be true once in a lifetime deal that is a scam. Get mock-offended and violent if called out.");
    table.addEntry("Minding their own business, but someone else approaches the party and offers a reward if they initiate the attack.");
    table.addEntry("Stealing from a third party and the players witness it.");
    table.addEntry("Actually mounted and try to run down the party and flee. Hit and run.");
    table.addEntry("Attack from the rooftops with ranged attacks.");
    table.addEntry("Actually just challenge the party to a friendly duel until the other side submits.");
    table.addEntry("Pre-existing fight envelops the party.");
    table.addEntry("Someone shouts something political and the entire street erupts into a riot around the party.");
    table.addEntry("They spot the party, curse, and take off running! Will fight if chased around that corner.");
    table.addEntry("Slavers need slaves.");
    table.addEntry("Drive by shooting from the back of a horse-drawn wagon");
    table.addEntry("They are bounty hunters that have legitimate wanted posters for the whole party. The issuer is not in this town, and the bounty hunters don't care about the party's story. Dead is easier than alive.");
    table.addEntry("Not attacking, but tailing the party. They hang back, but keep the PCs in sight. They will wait a cross the street when the party is in a building. They will follow until provoked. They can be easily lost by trying.");
    table.addEntry("They just don't like wizards/rogues/fighters/whatever class in their town.");
    table.addEntry("Member of the party is in a gang's territory while inadvertently wearing the colors of rival gang.");
    table.addEntry("Chaotic people, spreading chaos for the sake of chaos.");
    table.addEntry("Party has stumbled into a rough part of town.");
    table.addEntry("Strangers ain't welcome in these here parts.");
    table.addEntry("Guerilla tactics : strike with ranged attacks, run and hide, repeat. Leading the party deeper into danger, possibly over traps.");
    table.addEntry("Lure the party through a gate. Leads to another plane or a death trap dungeon. Party must find a way to escape.");

    return table.getRollTableEntry();
}

QString EncounterTables::creatureAttacksUrban()
{
    RandomTable table;

    table.addEntry("Crawls out of sewer");
    table.addEntry("Springs from a dark alley");
    table.addEntry("Escapes from a cage, container, or leash");
    table.addEntry("Lurks in a nearby abandoned building");
    table.addEntry("Attacking an innocent bystander");
    table.addEntry("Magic gate just opens and deposits them");
    table.addEntry("Summoning spell goes off. Summoner unseen.");
    table.addEntry("People running towards party, chaced by creature.");
    table.addEntry("Tears arround the corner suddenly, face to face with party");
    table.addEntry("Bursts out of a building. Dead bodies inside.");
    table.addEntry("Currently being fought by other adventurers");
    table.addEntry("Currently being fought by the Watch or Guard");
    table.addEntry("A nobleman watches his creatures attack with glee from afar.");
    table.addEntry("Summoning spell gone ary.");

    return table.getRollTableEntry();
}

QString EncounterTables::motivation()
{
    RandomTable table;

    table.addEntry("Searching for a sanctuary, a place to rest", 2);
    table.addEntry("Looking to Conquer the dungeon or area, or obtain the same "
                   "goal as the PCs", 3);
    table.addEntry("Seek an item in the dungeon or area", 3);
    table.addEntry("Seeking to Slay a rival nearby", 3);
    table.addEntry("Hiding from enemies", 2);
    table.addEntry("Recovering from battle", 2);
    table.addEntry("Avoiding danger", 2);
    table.addEntry("Seeking wealth", 3);
    table.addEntry(monsterDowntime(), 6);

    return table.getRollTableEntry();
}

/* Possibilities:
 * neighborhood adventure
 */
QString EncounterTables::generateUrbanEncounter(int tier)
{
    // 1 on 1d6 during the day, 2 during the night.

    int encounterType = Dice::roll(1,100);
    QString encounter;
    if (encounterType < 50) {
        encounter = MonsterTable::urbanEncountersUnique();
        encounter += "\n";
        bool isNormal = Dice::roll(1,6) < 4;
        encounter += (isNormal) ? "- Innocuous" : "- Nefarius";
    }
    else if (encounterType < 75) {
        encounter = MonsterTable::urbanEncounterXge(tier);
        /*
        encounter += "\n- Intellegent motive: " + humanoidAttacksUrban() + "\n";
        encounter += "- Creature motive: " + creatureAttacksUrban() + "\n";
        encounter += "- Friendly motive: " + friendlyHumanoidUrbanActivity() + "\n";
        encounter += (roll(1,6) < 4) ? "(friendly)" : "(hostile)";
        */

    }
    //else if (encounterType < 90) {
    else {
        encounter = "City Landmark";
    }
    return encounter;

    /*
    else if (encounterType < 95) {
        // NPC/watch/guard needs help/hostile
    }
    else if (encounterType < 97) {
        encounter = "Side Quest Hook";
    }
    else {
        encounter = "Neighborhood Adventure.";
    }
    */

}

QString EncounterTables::generateUrbanEncounterNight(int tier)
{
        QString encounter = MonsterTable::urbanEncounterXge(tier);
        /*
        encounter += "\n- Intellegent motive: " + humanoidAttacksUrban() + "\n";
        encounter += "- Creature motive: " + creatureAttacksUrban() + "\n";
        */
        return encounter;
}

QString EncounterTables::friendlyHumanoidUrbanActivity()
{
    RandomTable table;

    table.addEntry("Trying to avoid enemy that is looking for them.");
    table.addEntry("Fighting enemy and winning");
    table.addEntry("Fighting enmy and losing");
    table.addEntry("Looking for someone");
    table.addEntry("Investigating a case/crime");
    table.addEntry("Looking to hire adventurers");
    table.addEntry("Looking for directions (headded party's way)");
    table.addEntry("Looking to be hired");
    table.addEntry("Needs a favor");
    table.addEntry("Simple greeting");
    table.addEntry("Passing on a rumor or news");
    table.addEntry("New in town, looking for companions");
    table.addEntry("Adventure hook:" + AdventureTables::adventureHook(), 3);

    return table.getRollTableEntry();
}

