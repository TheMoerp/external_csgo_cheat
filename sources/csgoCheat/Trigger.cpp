#include "Trigger.h"

using namespace std;


void Triggerbot() {
	INPUT down;
	down.mi.dx = 0;
	down.mi.dy = 0;
	down.type = INPUT_MOUSE;
	down.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	down.mi.time = 0;
	down.mi.dwExtraInfo = 0;

	INPUT up;
	up.mi.dx = 0;
	up.mi.dy = 0;
	up.type = INPUT_MOUSE;
	up.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	up.mi.time = 0;
	up.mi.dwExtraInfo = 0;


	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	DWORD crosshair = mem.ReadMemory<DWORD>(localPlayer + offsets.m_iCrosshairId);
	DWORD crosshairEntity = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (crosshair - 1) * 0x10);

	DWORD weaponEntity = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hActiveWeapon) & 0xFFF;
	DWORD weaponBase = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (weaponEntity - 1) * 0x10);
	int weaponID = mem.ReadMemory<int>(weaponBase + offsets.m_iItemDefinitionIndex);
	
	Item curWeapon = GetItemByID(weaponID);
	int triggerInterval = curWeapon.rstTime;

	if (crosshairEntity != 0) {
		int localPlayerTeam = mem.ReadMemory<int>(localPlayer + offsets.m_iTeamNum);
		int crosshairEntityTeam = mem.ReadMemory<int>(crosshairEntity + offsets.m_iTeamNum);

		if ((crosshairEntityTeam == 2 || crosshairEntityTeam == 3) && localPlayerTeam != crosshairEntityTeam) {
			SendInput(1, &down, sizeof(down));
			Sleep(25);
			SendInput(1, &up, sizeof(up));
			Sleep(triggerInterval);
		}
	}
}