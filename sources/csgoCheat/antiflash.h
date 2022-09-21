#pragma once
#include <Windows.h>
#include "memory.h"


class Antiflash {
public:
	Antiflash();
	~Antiflash();

	void run();

private:
	int mFlashDur = 0;
};