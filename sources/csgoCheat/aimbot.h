#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

#include "memory.h"
#include "structures.h"


class Aimbot {
public:
	Aimbot();
	~Aimbot();

	void run();

private:
	// 8 = head
	const int TARGET_BONE = 8;
};