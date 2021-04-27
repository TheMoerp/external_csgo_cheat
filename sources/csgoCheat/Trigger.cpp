#include <iostream>

#include "Trigger.h"

using namespace std;
Trigger trigger;


void Trigger::Run()
{
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

	int triggerInterval = GetRecoveryTime(localPlayer);
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


int Trigger::GetRecoveryTime(DWORD _localPlayer) {
	DWORD weaponEntity = mem.ReadMemory<DWORD>(_localPlayer + offsets.m_hActiveWeapon) & 0xFFF; 
	DWORD weaponBase = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (weaponEntity - 1) * 0x10);
	int weaponID = mem.ReadMemory<int>(weaponBase + offsets.m_iItemDefinitionIndex);

	switch (weaponID) { 
	case 1:
		return desertEagle;
	case 2:
		return dualBerettas;
	case 3:
		return fiveSeven;
	case 4:
		return glock18;
	case 7:
		return ak47;
	case 8:
		return aug;
	case 9:
		return awp;
	case 10:
		return famas;
	case 11:
		return g3sg1;
	case 13:
		return galilAr;
	case 14:
		return m249;
	case 16:
		return m4a4;
	case 17:
		return mac10;
	case 19:
		return p90;
	case 23:
		return mp5sd;
	case 24:
		return ump45;
	case 25:
		return xm1014;
	case 26:
		return ppBizon;
	case 27:
		return mag7;
	case 28:
		return negev;
	case 29:
		return sawedOff;
	case 30:
		return tec9;
	case 32:
		return p2000;
	case 33:
		return mp7;
	case 34:
		return mp9;
	case 35:
		return nova;
	case 36:
		return p250;
	case 38:
		return scar20;
	case 39:
		return sg553;
	case 40:
		return ssg08;
	case 63:
		return cz75;
	case 262204:
		return m4a1s;
	case 262205:
		return usps;
	default:
		return 0;
	}
}


