#include "offsets.h"
#include "patternscan.h"


Offsets offsets;

using namespace std;

void Offsets::OffsetUpdate() {
	DWORD tmp1 = 0, tmp2 = 0;


	tmp1 = FindAddress(hProcess, L"client.dll", "\xBB\x00\x00\x00\x00\x83\xFF\x01\x0F\x8C\x00\x00\x00\x00\x3B\xF8", "x????xxxxx????xx");
	cout << tmp1 << endl;
	tmp2 = mem.ReadInt(tmp1 + 1);
	offsets.dwEntityList = tmp2 - offsets.clientBase;
	cout << dwEntityList << endl;
	

	tmp1 = FindAddress(hProcess, L"client.dll", "\x8B\x0D\x00\x00\x00\x00\x8B\xD6\x8B\xC1\x83\xCA\x02", "xx????xxxxxxx");
	tmp2 = mem.ReadInt(tmp1 + 2);
	offsets.dwForceJump = tmp2 - offsets.clientBase;

	tmp1 = FindAddress(hProcess, L"client.dll", "\xA1\x00\x00\x00\x00\xA8\x01\x75\x4B", "x????xxxx");
	tmp2 = mem.ReadInt(tmp1 + 1);
	offsets.dwGlowObjectManager = tmp2 - offsets.clientBase + 4;

	tmp1 = FindAddress(hProcess, L"client.dll", "\x8D\x34\x85\x00\x00\x00\x00\x89\x15\x00\x00\x00\x00\x8B\x41\x08\x8B\x48\x04\x83\xF9\xFF", "xxx????xx????xxxxxxxxx");
	cout << tmp1 << endl;
	tmp2 = mem.ReadInt(tmp1 + 3);
	offsets.dwLocalPlayer = tmp2 - offsets.clientBase + 4;
	cout << dwLocalPlayer << endl;

	tmp1 = FindAddress(hProcess, L"engine.dll", "\xF3\x0F\x10\x0D\x00\x00\x00\x00\xF3\x0F\x11\x4C\x24\x00\x8B\x44\x24\x20\x35\x00\x00\x00\x00\x89\x44\x24\x0C", "xxxx????xxxxx?xxxxx????xxxx");
	tmp2 = mem.ReadInt(tmp1 + 4);
	offsets.model_ambient_min = tmp2 - offsets.engineBase;
}