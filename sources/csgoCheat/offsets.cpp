#include "offsets.h"
#include "patternscan.h"


Offsets offsets;

using namespace std;


void Offsets::OffsetUpdate() {
	DWORD tmp1 = 0, tmp2 = 0;

	// dwEntityList
	tmp1 = FindAddress(hProcess, L"client.dll", "\xBB\x00\x00\x00\x00\x83\xFF\x01\x0F\x8C\x00\x00\x00\x00\x3B\xF8", "x????xxxxx????xx");
	tmp2 = mem.ReadInt(tmp1 + 1);
	offsets.dwEntityList = tmp2 - offsets.clientBase;

	// dwForceJump
	tmp1 = FindAddress(hProcess, L"client.dll", "\x8B\x0D\x00\x00\x00\x00\x8B\xD6\x8B\xC1\x83\xCA\x02", "xx????xxxxxxx");
	tmp2 = mem.ReadInt(tmp1 + 2);
	offsets.dwForceJump = tmp2 - offsets.clientBase;

	// dwGlowObjectManager
	tmp1 = FindAddress(hProcess, L"client.dll", "\xA1\x00\x00\x00\x00\xA8\x01\x75\x4B", "x????xxxx");
	tmp2 = mem.ReadInt(tmp1 + 1);
	offsets.dwGlowObjectManager = tmp2 - offsets.clientBase + 4;

	// dwLocalPlayer
	tmp1 = FindAddress(hProcess, L"client.dll", "\x8D\x34\x85\x00\x00\x00\x00\x89\x15\x00\x00\x00\x00\x8B\x41\x08\x8B\x48\x04\x83\xF9\xFF", "xxx????xx????xxxxxxxxx");
	tmp2 = mem.ReadInt(tmp1 + 3);
	offsets.dwLocalPlayer = tmp2 - offsets.clientBase + 4;

	// dwClientState
	tmp1 = FindAddress(hProcess, L"engine.dll", "\xA1\x00\x00\x00\x00\x33\xD2\x6A\x00\x6A\x00\x33\xC9\x89\xB0", "x????xxxxxxxxxx");
	tmp2 = mem.ReadInt(tmp1 + 1);
	offsets.dwClientState = tmp2 - offsets.engineBase;
}