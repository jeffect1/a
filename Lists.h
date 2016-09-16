#ifndef LISTS_H
#define LISTS_H



static std::vector<std::string> combatword = {
	" kills ",
	" defeats ",
	" murders ",
};

static std::vector<std::string> combatfinisher = {
	" swiftly.",
	" expertly.",
	" with expertise.",
	" by pushing them over a cliff.",
	" by mercifully piercing them in the heart.",
	" by decapitation.",
	" by suffocation.",
	" by dropping a large rock on their head.",
	" by disembowelment.",
	" by throwing them off a cliff.",
	" by swift decapitation.",
	" by stabbing them in the neck.",
	" by snapping their neck.",
	" by strangulation.",
	" by bashing their head with a nearby rock.",
	" by drowning them in a nearby pond.",
	" by pushing them into a spike pit.",
	" by splitting their skull open.",
	" by pushing them into a fire trap.",
	" by stabbing them in the face.",
	" by bludgeoning them to death.",
	" by jabbing a knife into their chest.",
};

static std::vector<std::string> combatfinisher_sad = {
	" gruesomely.",
	" by bashing their head open and scooping out their brains.",
	" by ripping their face in half.",
	" by aggressively stabbing their face repeatedly.",
	" by recklessly bludgeoning them to death.",
	" by gutting them mercilessly.",
	" by chopping off their limbs, and letting them bleed to death.",
	" by slicing their belly and ripping out their entrails.",
	" by chopping off their legs and beating them to death with them.",
};

static std::vector<std::string> weapondmgup1 = {
	" a 2x4",
	" a rusty chain",
	" a screwdriver",
	" a sawblade",
	" a railroad spike",
	" a pocket knife",
	" a crowbar",
	" a wrench",
	" a hammer",
	" a pair of scissors",
};

static std::vector<std::string> weapondmgup2 = {
	" a rusty sword",
	" a mace",
	" a broad axe",
	" a spear",
	" a switchblade",
	" a cordless drill",
	" a shovel",
	" a set of nunchucks",
	" a razorblade",
};

static std::vector<std::string> weapondmgup3 = {
	" a warhammer",
	" a flail",
	" a broadsword",
	" a glaive",
	" a katana",
	" a crossbow",

};

static std::vector<std::string> survivalrareevent = {" injects a mysterious syringe into their veins and becomes invigorated!",};

static std::vector<std::string> survivalmajor = {
	" finds a first aid kit and uses it to tend to some wounds",
	" successfully tracks down a deer and spends the night feasting on venison.",
	" sets up a hammock high in the trees and has a restful nap.",
	" manages to steal some honey from a beehive.",
	" traps a wild boar.",
	" finds a syringe loaded with steroids.",
};

static std::vector<std::string> survivalminor = {
	" finds a tree bearing fruit.",
	" goes hunting and catches a rabbit.",
	" kills a grouse with a crude bow and arrow.",
	" eats a snackbar.",
	" catches a trout with a net.",
	" carefully cooks some wild mushrooms for a delicious meal.",
	" drinks some fresh water.",
};

static std::vector<std::string> nothinghappens = {
	" sets up an arrow trap.",
	" sets up a bear trap.",
	" finds a vacant cave to sleep in for the night.",
	" attempts to hunt for deer, but fails.",
	" successfully fends off a pack of wolves.",
	" passes the time by whittling.",
};

static std::vector<std::string> accidentminor = {
	" trips and hits their head on a rock.",
	" burns themselves with boiling water.",
	" eats some undercooked food and gets mild food poisoning.",
	" cuts their hand with a knife",
	" fails to find water and becomes dehydrated.",
	" catches a fever.",
	" gets a rash from poison ivy.",
	" gets lost in the woods.",

};

static std::vector<std::string> accidentmajor = {
	" eats some mildly poisonous berries.",
	" suffers from a concussion after hitting their head on a rock.",
	" falls in a spike pit, but narrowly avoids death.",
	" falls victim to a live bear trap.",
	" gets chewed up by a cougar, but manages to fight it off.",
	" eats wild mushrooms and becomes sick.",
	" triggers a fire trap, but manages to stop, drop and roll in time.",
	" is bitten by a non-venemous snake.",
	" falls and is pierced by a dirty needle lying on the ground.",
};

static std::vector<std::string> accidentfatal = {
	" dies from a severe fever.",
	" starves to death.",
	" gets mauled alive by a vicious boar.",
	" falls into a spike pit.",
	" dies from an arrow to the face after triggering a trap.",
	" attempts to escape and gets shot.",
	" burns to a crisp from a fire trap.",
	" fails to build a shelter and freezes to death at night.",
	" gets devourved by a pack of wolves.",
	" eats a highly poisonous mushroom and becomes paralyzed from the neck down.",
	" is bitten by a rattlesnake.",
	" is bitten by a blackwidow.",
};

std::vector<std::string> cannibalword = {
	" devours a fallen victim.",
	" eats the heart of a fallen player.",
	" consumes what's left of a decaying corpse.",
	" eats the brains of a freshly killed human.",
};




#endif