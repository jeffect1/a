#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <ctime>
#include <chrono>

#include "Lists.h"

// Parameters
bool const g_colorcodes = true;


std::string printCol(std::string text, std::string type)
{
	// picks color code based on type, and prints out [color]text[/color]
	std::string code     = "";
	std::string code_end = "";
	
	if (g_colorcodes) //if false, no color codes are printed
	{
		if (type == "name")
			code = "[color=#31C398]"; //sort of green/blue
		else if (type == "wpn")
			code = "[color=#008fce]"; //nice blue
		else if (type == "stat")
			code = "[color=#fe0]"; //yellow
		else if (type == "trait")
			code = "[color=#800080]"; //purple
		else if (type == "flawlessly")
			code = "[color=#ffae19]"; //orange
		else if (type == "title")
			code = "[color=#dc1134]"; //red
		else
			return text;
		code_end = "[/color]";
	}

	return code + text + code_end;

}
struct weapon {
	std::string name;
	int dmg;
};

class Player
{
private:

	std::string m_nam;
	std::string m_trt; // trait
	int m_vit; //vitality
	int m_str; //strength
	int m_lck; //luck
	int m_chr; //charisma
	int m_srv; //survival
	int m_all; //alliance
	//int m_wpn; //weapon damage, just added to str automatically
	weapon m_wpn;


public:

	Player()
	{
		m_nam = "";
		m_trt = "";
		m_vit = 0;
		m_str = 0;
		m_lck = 0;
		m_chr = 0;
		m_srv = 0;
		m_all = 0;
		m_wpn = { "", 0 };
	}

	Player(std::string name, int vit, int str, int lck, int chr, int srv){
		m_nam = name;
		m_trt = "";
		m_vit = vit;
		m_str = str;
		m_lck = lck;
		m_chr = chr;
		m_srv = srv;
		m_all = 0;
		m_wpn = { "", 0 };
	}

	Player(std::string name, std::string trait, int vit, int str, int lck, int chr, int srv)
	{
		m_nam = name;
		m_trt = trait;
		m_vit = vit;
		m_str = str;
		m_lck = lck;
		m_chr = chr;
		m_srv = srv;
		m_all = 0;
		m_wpn = { "", 0 };
	}

	std::string getname(){ return printCol(m_nam, "name"); }
	std::string gettrt() { return m_trt; }
	int         getvit() { return m_vit; }
	int         getstr() { return m_str; }
	int         getlck() { return m_lck; }
	int         getchr() { return m_chr; }
	int         getsrv() { return m_srv; }
	int         getall() { return m_all; }

	std::string getwpn_name() { return printCol(m_wpn.name,"wpn"); }
	int         getwpn_dmg(){ return m_wpn.dmg; }

	std::string gettrtout() { return printCol(                m_trt, "stat"); }
	std::string getvitout() { return printCol(std::to_string(m_vit), "stat"); }
	std::string getstrout() { return printCol(std::to_string(m_str), "stat"); }
	std::string getlckout() { return printCol(std::to_string(m_lck), "stat"); }
	std::string getchrout() { return printCol(std::to_string(m_chr), "stat"); }
	std::string getsrvout() { return printCol(std::to_string(m_srv), "stat"); }

	void settrt(std::string m) { m_trt = m; }
	void setname(std::string m) { m_nam = m; }
	void setvit(int m) { m_vit += m; }
	void setstr(int m) { m_str += m; }
	void setlck(int m) { m_lck += m; }
	void setchr(int m) { m_chr += m; }
	void setsrv(int m) { m_srv += m; }
	void setall(int m) { m_all  = m; }
	void setwpn_name(std::string name) { m_wpn.name = name; }
	void setwpn_dmg(int m) { m_wpn.dmg = m; }

};

#pragma region Roster List
//vit/str/lck/chr/srv
std::vector<Player> roster
{
	{ "Jeff",      2, 3, 0, 10, 10 },
	{ "Ultra", "retarded",    6, 2, 1, 1, 1 }, //sorry Ultra
	{ "Sera",  "thief" ,         5, 5, 5, 5, 5 },
	{ "Zero", "creeper",      5, 5, 5, 5, 5 },
	{ "Xaos", "xaos_luck",    4, 4, 8, 6, 3 },
	{ "Raw",   "cannibal",               7, 7, 4, 4, 4 },
	{ "Suzy", "succubus",     5, 5, 1, 5, 3 },
	{ "Adam", "berserker",    10, 1, -1, -1, -5 },
	{ "Mark", "goliath",      7, 8, 1, 1, 6 },
	{ "Jand",  "twiddle",   4, 5, 4, 6, 4 },
	{ "Fluffy",   5, 5, 5, 5, 5 },
	{ "Username", 2, 2, 2, 2, 2 },
	{ "Liam",     5, 5, 3, 9, 3 },
	{ "Dyst",     4, 4, 4, 7, 5 },
	{ "Watson",   5, 7, 1, 3, 7 },
	{ "Jacob",    7, 7, 2, 2, 6 },
	{ "Chilli",   4, 4, 4, 5, 7 },
	{ "Cap",      20,1,10, 1, 1 },
	{ "Dylan",    5, 6, 6, 6, 3 },
	{ "Beans",    6, 5, 4, 3, 2 },
	{ "Profk",    5, 3, 4, 7, 5 },
	{ "JonFire",  4, 4, 6, 5, 3 },
	{ "Clay",     7, 8, 3, 8, 3 },
	{ "Wen",      5, 2, 3, 5, 5 },
	{ "Jim",      5, 5, 5, 5, 5 },
	/*{ "DannyB",   5, 5, 5, 5, 5 },
	{ "Brie",     7, 7, 5,10, 2 },
	{ "Falco",    6, 2, 4, 5, 5 },
	{ "Jessica",  4, 5, 6, 5, 2 },
	{ "Zithy",    2, 2, 2, 2, 2 },
	{ "Frag",     4, 4,10, 1, 2 },
	{ "Randa",    1, 1,18, 1, 1 },
	{ "Omega",    4, 4, 5, 5, 5 },
	{ "Champ",    2, 3, 4, 5, 6 },
	{ "Rich",     3, 4, 5, 6, 2 },
	{ "Bacon",    4, 4, 5, 5, 6 },
	{ "Nick",     4, 6, 2, 6, 4 },
	{ "Shibe",    9, 3, 6, 5, 2 },
	{ "Nameless", 5, 5, 5, 5, 5 },
	{ "Killtz",   5, 5, 5, 5, 5 },
	{ "Toz",      5, 5, 5, 5, 5 },
	{ "Ghokle",   5, 5, 5, 5, 5 },
	{ "Jazz",     5, 5, 5, 5, 5 },
	{ "Stever",   5, 5, 5, 5, 5 },
	{ "Evan",     5, 5, 5, 5, 5 },
	{ "Fort",     1, 1, 1, 1, 1 },
	{ "Ash",      5, 5, 5, 5, 5 },
	{ "Slash",    5, 5, 5, 5, 5 },
	{ "Hombre",   5, 5, 5, 5, 5 },
	{ "Lai",      5, 5, 5, 5, 5 },
	{ "Dave",     5, 5, 5, 5, 5 },
	{ "Fox",      5, 5, 5, 5, 5 },
	{ "Maps",     1,-1,-5,-1,-1 },*/
};

#pragma endregion

void printStats(Player x)
{
	std::cout << "\n" << x.getname() << ": \n";
	std::cout << "Vit: " << x.getvitout();
	std::cout << "\tStr: " << x.getstrout();
	//std::cout << "\nLck: " << x.getlckout();
	//std::cout << "\nChr: " << x.getchrout();
	//std::cout << "\nSrv: " << x.getsrvout();
}
void printStats(std::vector<Player> &roster)
{
	for (size_t i = 0; i < roster.size(); i++)
	{
		printStats(roster[i]);
	}
}
int Roll(int min, int max)
{
	// Rolls a number between min and max... obviously //
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX)+1.0);  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
int minimum(int x, int y){
	if (x > y) return y;
	else return x;}
int maximum(int x, int y){
	if (x > y) return x;
	else return y;}
void deletePlayers(std::vector<Player> &roster)
{
	// sweeps through the entire vector of Players and deletes anyone with vitality <= 0 //
	for (int i = roster.size() - 1; i >= 0; i--)
		if (roster[i].getvit() <= 0)
			roster.erase(roster.begin() + i);	
}
void swap(std::vector<Player> &roster, int i, int j)
{
	// just for sorting the Player vector
	Player third;
	third = roster[i];
	roster[i] = roster[j];
	roster[j] = third;
}

void dmgup(Player &x)
{

	std::string wpn;
	int diceroll = Roll(1, 20) + x.getlck();
	int wpn_dmg = 0;

	if (diceroll >= 21)
	{
		wpn = weapondmgup3[Roll(0, weapondmgup3.size() - 1)];
		wpn_dmg = 3;
	}
	else if (diceroll > 13)
	{
		wpn = weapondmgup2[Roll(0, weapondmgup2.size() - 1)];
		wpn_dmg = 2;
	}
	else
	{
		wpn = weapondmgup1[Roll(0, weapondmgup1.size() - 1)];
		wpn_dmg = 1;
	}

	std::cout << x.getname() << " finds" << printCol(wpn,"wpn");
	// check if the weapon they found is better:
	if (wpn_dmg > x.getwpn_dmg())
	{
		x.setstr(wpn_dmg - x.getwpn_dmg());
		x.setwpn_dmg(wpn_dmg - x.getwpn_dmg());
		x.setwpn_name(wpn);
		std::cout << " [i]. Damage up.[/i] " << x.getstrout();
	}
	else
		std::cout << ", but leaves it on the ground.";
	std::cout << "\n\n";

}
void combat1v1(std::vector<Player> &roster, Player &x, Player &y)
{
	// the 2 players will take turns hitting each other, doing 1 damage each time. //

	std::string killword = combatword[Roll(0, combatword.size() - 1)];
	Player winner;
	Player loser;
	int hpx = x.getvit();
	int hpy = y.getvit();

	while (x.getvit() != 0 && y.getvit() != 0) //while no one's dead, roll the dice and see who loses 1 vit
	{
		if (x.getstr() - y.getstr() + Roll(1, 20) >= 10)
			y.setvit(-1);
		else
			x.setvit(-1);
	}

	if (x.getvit() <= 0)
	{

		winner = y;
		loser = x;
	}
	else
	{

		winner = x;
		loser = y;
	}

	std::cout << winner.getname() << killword << loser.getname();


	if (winner.gettrt() == "insane")
	{
		std::cout << combatfinisher_sad[Roll(0, combatfinisher_sad.size() - 1)];
		std::cout << "\n\n";
		deletePlayers(roster);
		return;
	}

	if (x.getvit() == hpx || y.getvit() == hpy)
	{
		std::cout <<  printCol(" flawlessly","flawlessly");
		if (winner.getwpn_dmg() != 0)
			std::cout << " with" << winner.getwpn_name();
	}

	else if (Roll(0, 1) == 0 || winner.getwpn_dmg() == 0)
		std::cout << combatfinisher[Roll(0, combatfinisher.size() - 1)];

	else
		std::cout << " with" << winner.getwpn_name();

	std::cout << " [i]Current Health:[/i] " << winner.getvitout() << "\n\n";
	deletePlayers(roster);
}

void combat3(std::vector<Player> &roster, Player &x, Player &y, Player &z)
{

}

void survival(Player &x)
{
	// Roll the dice, and get one of several outcomes. Probably needs rebalancing //
	int diceroll = Roll(1, 52) + 3*x.getsrv() + x.getlck();
	std::string survival;

	if (diceroll > 74)
	{
		survival = survivalrareevent[0];
		x.setvit(5);
		x.setstr(5);
		x.setlck(-5);
	}
	else if (diceroll > 60)
	{
		survival = survivalmajor[Roll(0, survivalmajor.size() - 1)];
		x.setvit(2);
	}
	else if (diceroll > 50)
	{
		survival = survivalminor[Roll(0, survivalminor.size() - 1)];
		x.setvit(1);
	}
	else if (diceroll > 40)
		survival = nothinghappens[Roll(0, nothinghappens.size() - 1)];
	
	else if (diceroll > 30 )
	{
		survival = accidentminor[Roll(0, accidentminor.size() - 1)];
		x.setvit(maximum(-x.getvit()+1, -1));
		// ^ this ensures they don't die from this accident. otherwise the flavor text won't make as much sense
	}
	else if (diceroll > 19 )
	{
		survival = accidentmajor[Roll(0, accidentmajor.size() - 1)];
		x.setvit(maximum(-x.getvit()+1, -2));
		// ^ this ensures they don't die from this accident. otherwise the flavor text won't make as much sense
	}
	else if (diceroll == 15)
	{
		x.settrt("insane");
		std::cout << x.getname() << " has gone insane.\n\n";
		return;
	}
	else
	{
		survival = accidentfatal[Roll(0, accidentfatal.size() - 1)];
		x.setvit(-x.getvit());
	}

	std::cout << x.getname() << survival;
	if (x.getvit() > 0)
		std::cout << " [i]Current health:[/i] " << x.getvitout();
	std::cout << "\n\n";
}

void sortPlayers_chr(std::vector<Player> &roster)
{
	// sorts player roster by charisma, in increasing order //
	for (size_t i = 0; i < roster.size() - 1; i++)
		for (size_t j = i + 1; j < roster.size() ; j++)
			if (roster[i].getchr() > roster[j].getchr())
				swap(roster, i, j);
	// I know this is inefficient shut up //
}
void jumblePlayers(std::vector<Player> &roster)
{
	// inefficient, but works. don't judge me //
	std::vector<Player> clone{ roster.size() };
	size_t count = 0;
	while (count < roster.size())
	{
		int ran = Roll(0, roster.size() - 1); // get random player 
		if (roster[ran].getvit() != 0) // ensure they're not dead
		{
			clone[count] = roster[ran]; // clone 
			roster[ran].setvit(-roster[ran].getvit()); // kill player in original array
			count++;
		}
	}
	for (size_t j = 0; j < clone.size(); j++) // now copy clone (which is randomized) to original roster
		roster[j] = clone[j];
}
void jumblePlayers(std::vector<Player> &roster, int a, int b)
{

	std::vector<Player> clone{roster.size() };
	int count = 0;
	while (count < b-a+1)
	{
		int ran = Roll(0, b-a+1); // get random player 
		if (roster[ran].getvit() != 0) // ensure they're not dead
		{
			clone[count] = roster[ran]; // clone 
			roster[ran].setvit(-roster[ran].getvit()); // kill player in original array
			count++;
		}
	}
	for (int j = 0; j < b-a+1; j++) // now copy clone (which is randomized) to original roster
		roster[j] = clone[j];
}

// Trait Functions //
void succubus(std::vector<Player> &roster, int i, int j)
{

	roster[i].setvit(1);
	roster[i].setchr(Roll(-1, 0));
	roster[j].setvit(-1);
	if (roster[j].getvit() <= 0)
		std::cout << roster[i].getname() << printCol(" drains the life out of ", "trait") << roster[j].getname();
	else
		std::cout << roster[i].getname() << printCol(" drains some life out of ", "trait") << roster[j].getname();
	std::cout << ". " << roster[i].getname() << printCol("'s", "name") << " HP: " << roster[i].getvitout() << "\n\n";
}
void retarded(std::vector<Player> &roster, int i)
{


	std::cout << roster[i].getname() << printCol(" goes full retard", "trait");
	roster[i].setvit(-1);
	if (roster[i].getvit() == 0)
		std::cout << printCol(" and dies.", "trait");
	else
		std::cout << ". HP: " << roster[i].getvitout();
	std::cout << "\n\n";
}
void berserker(std::vector<Player> &roster, int i)
{

	if (roster[i].getvit() == 1)
		return; //need at least 2 hp to go berserk

	roster[i].setvit(-1);
	roster[i].setstr(Roll(0,2));
	std::cout  <<roster[i].getname() << printCol(" goes berserk.","trait") << " HP: " << roster[i].getvitout() << " Str: " << roster[i].getstrout() << "\n\n";
}
void cannibal(std::vector<Player> &roster, int i)
{
	int j;
	if (i == 0)
		j = 1;
	else
		j = i - 1;

	if (Roll(0, 2) < 1)
	{
		std::cout << roster[i].getname() << printCol(" cannibalizes ", "trait") << roster[j].getname() << " after they fall asleep";
		roster[j].setvit(-roster[j].getvit());
		roster[i].setvit(1);
	}
	else
	{
		std::cout << roster[i].getname() << printCol(" attempts to cannibalize ", "trait") << roster[j].getname() << ", but is caught and runs away";
		roster[i].setchr(-roster[i].getchr() + 1); //sets charisma to 1 since everyone knows
	}
	std::cout << ".\n\n";
}
void thief(std::vector<Player> &roster, int i)
{
	int j;
	if (i > 1)
		j = 0;
	else
		j = i + 1;
	if (roster[j].getwpn_dmg() == 0)
	{
		std::cout << roster[i].getname() << printCol(" attempts to steal a weapon from ", "trait") << roster[j].getname() << ", but " << roster[j].getname() << " doesn't have one\n\n";
		return;
	}

	std::cout << roster[i].getname() << printCol(" steals ", "trait") << roster[j].getwpn_name() << " from " << roster[j].getname();
	if (roster[j].getwpn_dmg() > roster[i].getwpn_dmg())
	{
		roster[i].setwpn_name(roster[j].getwpn_name());
		roster[i].setwpn_dmg(roster[j].getwpn_dmg());
	}
	else
	{
		std::cout << " and destroys it";
	}

	roster[j].setstr(-roster[j].getwpn_dmg());
	roster[j].setwpn_name("");
	roster[j].setwpn_dmg(0);
	std::cout << ".\n\n";
}
void twiddle(std::vector<Player> &roster, int i)
{
	std::cout << roster[i].getname() << printCol("twiddles", "trait");
	std::cout << ".\n\n";
}

void traitEvents(std::vector<Player> &roster, int i)
{
	//size_t trials = roster.size();
	//jumblePlayers(roster);

		int j;
		if (i > 0)
			j = i - 1;
		else
			j = i + 1;

		if (roster[i].gettrt() == "succubus")	
			succubus(roster, i, j);
		else if (roster[i].gettrt() == "retarded")
			retarded(roster, i);
		else if (roster[i].gettrt() == "berserker")
			berserker(roster, i);
		else if (roster[i].gettrt() == "thief")
			thief(roster, i);
		else if (roster[i].gettrt() == "cannibal")
			cannibal(roster, i);
		else if (roster[i].gettrt() == "twiddle")
			twiddle(roster, i);
		else
			return;


}



void dayEvents(std::vector<Player> &roster)
{
	int trials;
	size_t threshold = 6;
	jumblePlayers(roster);

	if (roster.size() > threshold)
	{
		trials = minimum(8,roster.size() / 3);
		for (int i = 0; i < trials; i++)
		{
			sortPlayers_chr(roster);
			//jumblePlayers(roster, 0, trials);
			combat1v1(roster, roster[i], roster[i + 1]);
			deletePlayers(roster);
		}
	}
	else
	{

		std::cout << "Ultimate Showdown! Everyone fights until there's only 1 left standing.\n\n";
		while (roster.size() > 1)
		{
			jumblePlayers(roster);
			//std::cout << roster[0].getname() << " vs " << roster[1].getname() << ": ";
			combat1v1(roster, roster[0], roster[1]);
			deletePlayers(roster);

		}
	}
}
void nightEvents(std::vector<Player> &roster)
{
	
	int trials = roster.size();
	//std::cout << trials << "\n";
	jumblePlayers(roster);

	for (int i = 0; i < trials; i++)
	{
		if (roster[i].gettrt() != "" && Roll(0, 1) == 0)
			traitEvents(roster, i);
		else if (Roll(1, 5) > 4)
			dmgup(roster[i]);
		else
			survival(roster[i]);
		
	}
	deletePlayers(roster);
}


std::string Battle(std::vector<Player> roster)
{
	// also note: function passes roster by value and not reference, so we can simulate battle endlessly if we need to (makes copy of roster, so it doesn't get completely deleted)
	// The function where everything exciting happens!//
	int day_counter = 0;
	int index=0;
	do
	{
		if (index == 0)
		{
			std::cout << "\n\n" << printCol("***** Preperation Day *****", "title") << "\n\n";
			nightEvents(roster);
		}


		if (index % 2 == 0)
		{
			std::cout << "\n\n" << printCol("***** Day " + std::to_string(++day_counter) + " *****","title") << "\n\n";
			dayEvents(roster);
		}
		else
		{
			std::cout << "\n\n" << printCol("***** Night " + std::to_string(day_counter) + " *****", "title") << "\n\n";
			nightEvents(roster);
		}
		index++;
		deletePlayers(roster);


	} while (roster.size() > 1);

	if (roster[0].getvit() == 0)
		return "Everyone died!\n0";
	else
		return roster[0].getname() + " is the winner of the bloodbath!\n";
}

int main(){

	srand(static_cast<unsigned int>(time(0))); // For Roll function
	std::cout << Battle(roster);

	return 0;
}