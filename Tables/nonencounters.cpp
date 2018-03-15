#include "nonencounters.h"

NonEncounters::NonEncounters()
{

}

QString NonEncounters::universal()
{
    RandomTable table;
    table.addEntry("The shores of a lake lap at the bottoms of hills that "
                   "rise into great rock formations with gaps between them.");
    table.addEntry("Weathered stone steps, overgrown with grass and moss, "
                   "rise a low, circular mound. At its top is a circle of "
                   "standing stones, arranged around a crumbling crypt.");
    table.addEntry("Cresting a rise in the landscape, beyond stand two sharp "
                   "peaks of stone piercing from the ground and bare of "
                   "any vegetation.");
    table.addEntry("Rough stone peaks serrate the landscape ahead.");
    table.addEntry("The ground before you grows hard as the soil gives way to "
                   "bare stone. Shallow puddles of water dot the gray rock.");
    table.addEntry("The land before you drops suddeny, a cliff straight down "
                   "100 feet into a steep hill that drops away from you.");
    table.addEntry("You pass through the bottom of a deep chasm, barely 50 "
                   "feet wide and dark. Ancient and broken columns cluster "
                   "allong the "
                   "natural walls, and crumbled stairways of elder stone "
                   "rise a few feet and break off, leading nowhere.");
    table.addEntry("Spires of stone just from the landscape like great, "
                   "jagged stelagmites. Nooks on their surfaces glow with what "
                   "look like torchlight in the dark, though it is just a "
                   "lichen.");
    table.addEntry("Tall trees blot out the sun, their canopies far overhead.");
    table.addEntry("A sullen fog darkens the trees ahead and a strange silence "
                   "hangs over the land.");
    table.addEntry("Trees with great roots that pull the earth up in mounds "
                   "at their bases, eliminating any flatness this land may "
                   "have once had.");
    table.addEntry("Strange, blocky columns rise hundreds of feet into the "
                   "air. Thirty feet to a side, their bases have been carved "
                   "away like a tree that has been chopped at and abandoned");
    table.addEntry("The land rises up on either side as your way takes you "
                   "into a narrow valley, barely wide enough for two horses "
                   "side by side");
    table.addEntry("The muddy land is criss-crossed in a confusion of hoof "
                   "prints");
    table.addEntry("A narrow vale is cluttered with bones and broken spears. "
                   "An army was trapped and slaughtered here, long ago.");
    table.addEntry("The trees make way, like a dungeon exit that leads to a "
                   "narrow valley with sharp rising hills on either side, "
                   "so thin that mounted riders would have to pass single "
                   "file.");
        table.addEntry("");
    table.addEntry("A stream empties from a nearby lake, flowing past you");
    table.addEntry("The wooden, skeletal ruins of a small town lie ahead");
    table.addEntry("Steep hills, covered in pines, rise up far ahead in the "
                   "distance, and the path you are on appears to lead between "
                   "two of them.");
    table.addEntry("A river winds lazily along your path ahead, wide with "
                   "islands, and tall hills rise up on either side of it, "
                   "the vale choked with trees.");
    table.addEntry("The trail ends at an old, rickety dock that juts out over "
                   "a wide field of mud until it reaches its crumbled end.");
    table.addEntry("The trail leads into a damp, muddy land. Wooden posts have "
                   "been laid down, side by side and sunken into the mire to "
                   "provide a solid continuation of the path.");
    table.addEntry("The land drops steeply away, revealing a wide, shallow "
                   "vale below and a great open sky above");
    table.addEntry("The land stops at an overhang and drops thousands of feet "
                   "below. The wooded vale below rises up again in the "
                   "distance into sharp, jagged peaks of bare stone.");
    table.addEntry("The fog does little to obscure a massive, looming mountain "
                   "ahead.");
    table.addEntry("The trail wraps around the crest of a hill that falls "
                   "sharply to one side. Shielded from the sky by a great oak, "
                   "you can see a forrested mountain rise up from the bottom "
                   "of the hillside.");
    table.addEntry("A great wall once divided this land, but now it is mostly "
                   "a crumbled ruin, with wide gaps and toppled masonry.");
    table.addEntry("What looks to be the formidable stone gates to an ancient "
                   "dungeon loom before you, but as your path takes you around "
                   "them, you can see that is all that is left, the dungeon "
                   "itslef is collapesd, its rubble long ago overgrown. Only "
                   "the doors still stand.");
    table.addEntry("Rolling hills, topped with large, smoth boulders that have "
                   "made way for the growth of old trees");
    table.addEntry("A great cliff stands to one side, and the roar of a "
                   "waterfall feeds the river below. The trail leads to a "
                   "fallen log that bridges the river, a few hundred feet up.");
    table.addEntry("The land dissappears into a great sinkhole, wider around "
                   "than a city. At the far end, a wide river empties into it "
                   "and birds circle overhead.");
    table.addEntry("The world gives way to great, mountainous masses of stone "
                   "with wide, sloping bases with sharp, vertical peaks, like "
                   "massive, natural columns that have been broken off at their "
                   "bases.");
    table.addEntry("The stone shell of a great keep sits against a cliff-face, "
                   "far off in the distance ahead. Just the outer wall stands, "
                   "open to the sky and protecting only the dirt.");
    return table.getRollTableEntry();
}

QString NonEncounters::mountain()
{
    RandomTable table;

    table.addEntry("Had to make their way accross a ledge on the side of a sheer cliff.");
    table.addEntry("An ice bridge spans a chasm.");
    table.addEntry("An ancient, stone bridge spanning a chasm.");
    table.addEntry("The ruined shell of some ancient structure, surrounded by crumbling columns");
    table.addEntry("A tangled maze of old, not-maintained trails that required a lot of backtracking.");
    table.addEntry("Climbing hand over hand up a steep incline was required.");
    table.addEntry("Scrambling over loose gravel and rocks that provide precarious footing.");
    table.addEntry("Intermittent rumblings and minor earthquakes.");
    table.addEntry("Various tiny caves that are homes to small animals such as lizards or birds.");
    table.addEntry("Sparce shrubbery, some of which have red berries");
    table.addEntry("A wooded area of the mountainside");
    table.addEntry("An old trail winds up the mountainside");
    table.addEntry("Have to scramble around large outcroppings of rocks and boulders");
    table.addEntry("A heavy gale blows over the landscape, directly against the directoin of travel");
    table.addEntry("A heavy wind blows at the party's backs the whole way, until they round an outcropping of rock");
    table.addEntry("A large overhang shileds the party from the sky as they pass this way");
    table.addEntry("A wide ledge winds around the edge of a long, sheer cliff");
    table.addEntry("A high cliff blocks the way with sparse footholds for climbing");
    table.addEntry("A rope bridge sways precariously in the wind");
    table.addEntry("A fallen tree crosses a shallow ravine");
    table.addEntry("A flock of mountain goats crosses the party's path");
    table.addEntry("The way plateaus and a herd of aurochs lounge about, munching the sparse grass");
    table.addEntry("A sparse wood of thin trees dot the sloped mountainside");
    table.addEntry("A pass through steep inclines on either side");
    table.addEntry("The party crosses a ride, climbing up one side and down the other");
    table.addEntry("The party crosses several short riges that require climbing up one and down the other, over and over");
    table.addEntry("The party traverses the length of a long, high ridge");
    table.addEntry("The way goes throug a tunnel that's more of a crack in the mountainside");
    table.addEntry("The way goes through the bottom of a deep chasm.");
    table.addEntry("A path moves along one side of a chasm, crosses a stone bridge to the otherside, and continues");
    table.addEntry("Rough carved steps wind up the side of a cliff");
    table.addEntry("A whiteout blizzard or heavy storm cuts vision down to nothing");
    table.addEntry("Frequent small stones continuously fall from the higher ground, occasionally striking a character");
    table.addEntry("Buzzards circle overhead the entire time the party travels this route");
    table.addEntry("The party comes accross the frozen body of a human dressed in rags");
    table.addEntry("Little lizzards scurry out of the path of the party as it crosses this area");
    table.addEntry("The party reaches a ledge that provides a breathtaking view of the lowlands beyond the mountain");
    table.addEntry("The party ascends into a cloud, and wanders in circles for a while before proceeding");
    table.addEntry("A wind kicks up dust and many small, rocks, abrassively whipping against the party for a while.");
    table.addEntry("The party follows a mountain stream for a way");
    table.addEntry("A waterfall pours down a cliff and into a small lake before emptying down the mountain.");
    table.addEntry("The party climbs to a plateau that is shaped like a bowl. Many mountain streams empty into a small lake, and the skeleton of an old wall looms at the far side.");
    table.addEntry("Cliffs drop thousands of feet on either side");
    table.addEntry("A sheer drop falls thousands of feet to one side, and the "
                   "sky is blotted out by the overhanging mountain above as "
                   "you make your way along a great notch, etched into its "
                   "side.");
    table.addEntry("Squat shrubs collect around the bases of boulders that are "
                   "so frequent that you have to wind your way around them.");

    table.addEntry("Massive spires of moss-covered stone jut from the land, with "
                   "a fog that rolls between them, leaving just the vegetation-"
                   "speckeled tops visible.");
    table.addEntry(universal(), 10);

    return table.getRollTableEntry();
}


QString NonEncounters::plains()
{
    RandomTable table;

    table.addEntry("An endless field of short grass over a flat landscape, punctuated by tall, grey boulders");
    table.addEntry("Grass so tall that even a human can't see over it");
    table.addEntry("Sparce grass over a russet, dirt field, littered wth rocks and a few shrubs");
    table.addEntry("A large, granite rock formation juts out of the landscape and must be circumvented");
    table.addEntry("Streams crisscross the area");
    table.addEntry("An unmapped, shallow river crosses the party's path");
    table.addEntry("The landscape is interrupted by a wide chasm, spanned by an old, crumbling stone bridge");
    table.addEntry("The way leads tha party down the bottom of a wide chasm");
    table.addEntry("The landscape rises up 10-20 feet up rocky cliffs on either side of the party's path");
    table.addEntry("The landscape drops and the party must climb down a 1-200 foot cliff to the plains below");
    table.addEntry("Many copese of trees, little clusters dot the landscape");
    table.addEntry("The way is sparsely cluttered with thin trees");
    table.addEntry("The way takes the party through a small wood");
    table.addEntry("The way passes through a small, thick wood");
    table.addEntry("The party follows a babling brook for a while");
    table.addEntry("Ruddy red soil contrasts bright green foliage for the whole watch");
    table.addEntry("The ground softens, and eventually gives way to shallow water, out of which the tall grass grows");
    table.addEntry("The party must circumvent a small lake");
    table.addEntry("Old, abandoned farmlands, the old properties edged by short, knee-high walls of piled stone");
    table.addEntry("The party passes a distant, abandoned farmnouse, overgown with weeds and dirt");
    table.addEntry("A crumbled ruins of a barn");
    table.addEntry("The grasslands are broken up by gently rolling hills");
    table.addEntry("The land for this watch grows hard and cracked");
    table.addEntry("A stiff breeze blows in from the west");
    table.addEntry("A mist clings to the ground about the party's feet");
    table.addEntry("An obscuring fog makes progress difficult");
    table.addEntry("Light seasonal percipitaton");
    table.addEntry("A torrential downpour drenches the party for the duration of this watch");
    table.addEntry("Moisture clings to the grass in this region, soaking through everybody's boots and making the cuffs of everyone's trousers uncomfortably wet");
    table.addEntry("A field of wildflowers");
    table.addEntry("Field rats plague this region");
    table.addEntry("Creeper tangles the ground about the party's feet");
    table.addEntry("A gusty gale opposes the party the whole watch");
    table.addEntry("A strong wind presses at the party's backs");
    table.addEntry("A lone scarecrow is passed along the way");
    table.addEntry("A mesa blocks the party's path and must be circumvented");
    table.addEntry("The area is dotted with the scattered ruins of an ancient culture. Only chunks of weathered masonry remains");
    table.addEntry("The party passes through a region of ash, where a grassfire has recently burned down all of the vegetation.");
    table.addEntry("A pile of busted and weathered wooden lumber is all that denotes the location of some sort of ruined building");
    table.addEntry("A wide field of tree stumps where a forrest once stood");
    table.addEntry("Saplings are sprouted up all over, as if a new forrest were growing in this area");
    table.addEntry("A large orderly farm field grows here, but with no sign of a farmhouse or any farmers");
    table.addEntry("The region is full of charred stumps of trees. This was once a forrest that has recentl burned down");
    table.addEntry("An old wooden bridge crossing over nothing");
    table.addEntry("A rickety old bridge spans a chasm");
    table.addEntry("A covered bridge spans a small river");
    table.addEntry("A small pond populated by ducks and koi");
    table.addEntry("The land gives way to a desolate moor.");
    table.addEntry("Patches of short, stumpy grass cluster about the shallow "
                   "pools of water in the otherwise flat and muddy landscape");
    table.addEntry("Colorless stones cluster about the short grass in these "
                   "rolling hills.");
    table.addEntry("Rows of taller grass crisscross the shorter grass as it "
                   "seems the whole land is tilted in one direction.");
    table.addEntry("The foot of a small mountain rises sharply out of the "
                   "landscape ahead.");
    table.addEntry("The flat, wattery land reflects the sky, broken up by "
                   "ancient stone  arches made from age-worn masonry. Relief "
                   "statues that once adorned them have been weather beaten "
                   "into vaguely humanoid shapes.");
    table.addEntry("Thick, rolling clouds gather overhead, more massive than "
                   "any mountain range. They grow dark near the horison, where "
                   "you can see distant rainfall.");
    table.addEntry("A muddy trail cuts throug waist-high grass. A single "
                   "cyprus stands from the field ahead, and a cluster of "
                   "shorter trees gathers in the distance to one side.");
    table.addEntry("The flat landscape gives way to a wide treeline, near the "
                   "horizion.");
    table.addEntry("As you crest a hill, you get a breathtaking view, high "
                   "over the flat land that stretches seemingly forever beyond.");
    table.addEntry("Flat, grassy land is broken up by great plateaus that rise,"
                   "scattered about until the horizon.");
    table.addEntry(universal(), 10);



    return table.getRollTableEntry();
}

QString NonEncounters::forest()
{
   RandomTable table;

   table.addEntry("Deciduous trees give way to a clearing, where thick pines "
                  "take up the forrest on the other side.");
   table.addEntry("The tree canopy makes way for a rare view of the sky.");
    table.addEntry("Tall, thick-trunked trees with peeling bark straddle "
                   "either side of a puddle-riddled path.");
   table.addEntry("Grassy undergrowth covers the forest floor with clusters of "
                  "ferns and wads of brambles.");
   table.addEntry("A clearing makes way, and in its center stands a solitary "
                  "archway. A cold, unused firepit was dug at its base a "
                  "long time ago.");
   table.addEntry("Cold mountains of stone rise up on either side asn the "
                  "forest collects in the valley between them, "
                  "the trees impenitrable through their canopy.");
   table.addEntry(universal(), 10);

   return table.getRollTableEntry();
}

