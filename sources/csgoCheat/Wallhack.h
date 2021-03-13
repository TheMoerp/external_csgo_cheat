#pragma once
#include "Memory.h"

class Wallhack {
private:
	float red = 2.0;
	float green = 0.0;
	float blue = 0.0;
public:
	void Run();
};

extern Wallhack wh;
