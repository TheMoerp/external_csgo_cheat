#include "antiflash.h"


Antiflash::Antiflash() {
	std::cout << "--> Antiflash ready                (Toggle it with NUM_4)" << std::endl;
}


Antiflash::~Antiflash() {}


void Antiflash::run() {
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);

	// Current flash duration. Usually 0
	mFlashDur = mem.ReadMemory<int>(localPlayer + offsets.m_flFlashDuration);

	// Checks if the player is flashed
	if (mFlashDur > 0) {

		// Removes flash effect
		mem.WriteMemory<int>(localPlayer + offsets.m_flFlashDuration, 0);
	}

	// Sleeping time because this feature doesn't need to be fast
	Sleep(10);
}