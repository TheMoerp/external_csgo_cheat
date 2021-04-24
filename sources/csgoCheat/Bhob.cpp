#include <iostream>

#include "Bhop.h"

Bhop bhop;

using namespace std;

void Bhop::Run() {
	int flags = mem.ReadMemory<int>(mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer) + offsets.m_fFlags);
	
	if ((flags & (1 << 0)) && (GetAsyncKeyState(VK_SPACE) < 0)) {
		cout << (flags & (1 << 0)) << endl;
		mem.WriteMemory<DWORD>(offsets.clientBase + offsets.dwForceJump, 6);
	}
}