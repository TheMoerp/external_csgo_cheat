#pragma once
#include "Memory.h"
#include "WeaponSkins.h"

class SkinChanger {
private:
	float wear = 0.0001f; // best wear possible
public:
	void Run();
};

extern SkinChanger skinChanger;