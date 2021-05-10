#include "Antiflash.h"


int flashDur = 0;
void antiflash() {
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	flashDur = mem.ReadMemory<int>(localPlayer + offsets.m_flFlashDuration);
	if (flashDur > 0) {
		mem.WriteMemory<int>(localPlayer + offsets.m_flFlashDuration, 0);
	}
	Sleep(10);
}