#include <iostream>

#include "Bhop.h"

Bhop bhop;

using namespace std;

void Bhop::Run() {
	// Get flag
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	int flags = mem.ReadMemory<int>(localPlayer + offsets.m_fFlags);
	
	// Checks if player touches the ground and presses Space
	if ((flags & (1 << 0)) && (GetAsyncKeyState(VK_SPACE) < 0)) {
		// Jumps
		mem.WriteMemory<DWORD>(offsets.clientBase + offsets.dwForceJump, 6);
	}
}