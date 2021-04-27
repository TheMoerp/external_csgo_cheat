#pragma once
#include "Memory.h"

class Aimbot
{
private:
	const int TARGET_BONE = 8;
	const int AIM_FOV = 5;
	const float AIM_COLOR_R = 0.0;
	const float AIM_COLOR_G = 2.0;
	const float AIM_COLOR_B = 0.0;

	float oldDistX;
	float oldDistY;

	int entityTeam;
	int entityHealth;
	bool entityDormant;

	float localPos1;
	float localPos2;
	float localPos3;

	DWORD target;
	int targetHealth;
	bool targetDormant;
	float targetPosX;
	float targetPosY;
	float targetPosZ;

public:
	void Run();
};

