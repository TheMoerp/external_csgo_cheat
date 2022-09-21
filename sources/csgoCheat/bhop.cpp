#include "bhop.h"


Bhop::Bhop() {
	std::cout << "--> Bhop ready                     (Toggle it with NUM_3)" << std::endl;
}


Bhop::~Bhop() {}


void Bhop::run() {
	// Get flag
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	int flags = mem.ReadMemory<int>(localPlayer + offsets.m_fFlags);

	// Checks if player touches the ground and presses Space
	if ((flags & (1 << 0)) && (GetAsyncKeyState(VK_SPACE) < 0)) {
		// Jumps
		mem.WriteMemory<DWORD>(offsets.clientBase + offsets.dwForceJump, 6);
	}
}