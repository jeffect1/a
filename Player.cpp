#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

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

	std::string getname(){ return "[color=#31C398]" + m_nam + "[/color]"; }
	std::string gettrt() { return m_trt; }
	int         getvit() { return m_vit; }
	int         getstr() { return m_str; }
	int         getlck() { return m_lck; }
	int         getchr() { return m_chr; }
	int         getsrv() { return m_srv; }
	int         getall() { return m_all; }

	std::string getwpn_name() { return "[color=#008fce]" + m_wpn.name + "[/color]"; }
	int         getwpn_dmg(){ return m_wpn.dmg; }

	std::string gettrtout() { return "[color=#fe0](" + m_trt + ")[/color]"; }
	std::string getvitout() { return "[color=#fe0](" + std::to_string(m_vit) + ")[/color]"; }
	std::string getstrout() { return "[color=#fe0](" + std::to_string(m_str) + ")[/color]"; }
	std::string getlckout() { return "[color=#fe0](" + std::to_string(m_lck) + ")[/color]"; }
	std::string getchrout() { return "[color=#fe0](" + std::to_string(m_chr) + ")[/color]"; }
	std::string getsrvout() { return "[color=#fe0](" + std::to_string(m_srv) + ")[/color]"; }

	void settrt(std::string m) { m_trt = m; }
	void setname(std::string m) { m_nam = m; }
	void setvit(int m) { m_vit += m; }
	void setstr(int m) { m_str += m; }
	void setlck(int m) { m_lck += m; }
	void setchr(int m) { m_chr += m; }
	void setsrv(int m) { m_srv += m; }
	void setall(int m) { m_all = m; }
	void setwpn_name(std::string name) { m_wpn.name = name; }
	void setwpn_dmg(int m) { m_wpn.dmg = m; }

};