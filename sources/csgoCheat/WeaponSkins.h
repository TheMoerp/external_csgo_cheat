#pragma once
#include "Memory.h"

class WeaponSkins {
private:
	bool alive = true;

	int getRandomSkinID(int *_skinStock, int _length);
	bool AliveCheck();
public:
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
	int usp;
	int m4a1s;

	int GetSkinID(int _weaponID);
	void ChangeSkinLayout();
	void RandomSkinChanger();
};

extern WeaponSkins weaponSkins;