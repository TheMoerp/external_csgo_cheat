#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream> 

#include "memory.h"


class Config {
private:
	void ReadConfigs();
	void SetConfig(std::string name, std::string value);
	void CreateConfig();
public:
	int aFOV;
	int triggerKey;
	int aimbotKey;
	int wallhackKey;
	int antiflashKey;
	int radarKey;
	int bhopKey;

	int cz75;
	int desertEagle;
	int dualBerettas;
	int fiveSeven;
	int glock18;
	int p2000;
	int p250;
	int tec9;
	int ak47;
	int aug;
	int awp;
	int famas;
	int g3sg1;
	int galilAr;
	int m4a4;
	int scar20;
	int sg553;
	int ssg08;
	int mac10;
	int mp5sd;
	int mp7;
	int mp9;
	int ppBizon;
	int p90;
	int ump45;
	int mag7;
	int nova;
	int sawedOff;
	int xm1014;
	int m249;
	int negev;
	int usps;
	int m4a1s;
	int revolver;

	int knifeID;
	int bayonet;
	int flip;
	int karambit;
	int m9Bayonet;
	int huntsman;
	int falchion;
	int navaja;
	int stiletto;

	void LoadConfigs();
};

extern Config config;