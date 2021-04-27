#include <iostream>

#include "Bhop.h"

Bhop bhop;

using namespace std;

void Bhop::Run() {
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	int flags = mem.ReadMemory<int>(localPlayer + offsets.m_fFlags);
	
	if ((flags & (1 << 0)) && (GetAsyncKeyState(VK_SPACE) < 0)) {
		mem.WriteMemory<DWORD>(offsets.clientBase + offsets.dwForceJump, 6);
	}
}