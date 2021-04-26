#pragma once
#include "Memory.h"
#include "WeaponSkins.h"

class KnifeChanger
{
private:
	int paintKit = 558;
	int bayonet_ct = 90;
	int bayonet_t = 65;

	int gut_off = 3;
	int classic_off = 1;
	int flip_off = 2;
	int karambit_off = 4;
	int m9_bayonet_off = 5;
	int huntsman_off = 6;
	int falchion_off = 7;
	int navaja_off = 14; // +1
	int stiletto_off = 16; //+1

	int GetKnifeIDef(int _knifeID);
public:
	void Run();
};