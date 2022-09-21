#pragma once
#include <iostream>
#include "memory.h"
#include "weapon.h"
#include "structures.h"


class Skinchanger {
public:
	Skinchanger();
	~Skinchanger();

	void run();

private:
	int mModelIndex = 0;
};