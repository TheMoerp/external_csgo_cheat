#pragma once
#include "Memory.h"
#include "WeaponSkins.h"

class KnifeChanger
{
private:
	int modelIndex = 0;
	int cachedPlayer = 0;

	int GetKnifeIDef(int _knifeID);
public:
	void Run();
};