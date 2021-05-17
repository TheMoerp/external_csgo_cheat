#include "antiflash.h"


int flashDur = 0;
void antiflash() {
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);

	// Current flash duration. Usually 0
	flashDur = mem.ReadMemory<int>(localPlayer + offsets.m_flFlashDuration);

	// Checks if the player is flashed
	if (flashDur > 0) {

		// Removes flash effect
		mem.WriteMemory<int>(localPlayer + offsets.m_flFlashDuration, 0);
	}

	// Sleeping time because this feature doesn't need to be fast
	Sleep(10);
}
