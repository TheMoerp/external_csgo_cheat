#include "wallhack.h"

using namespace std;


void Wallhack() {

	DWORD glowObj = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwGlowObjectManager);
	DWORD localTeam = mem.ReadMemory<DWORD>(mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer) + offsets.m_iTeamNum);

	for (int i = 0; i < 32; i++) {

		DWORD playerEntity = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + i * 0x10);

		if (playerEntity == 0) {
			continue;
		}

		if (mem.ReadMemory<bool>(playerEntity + offsets.m_bDormant)) {
			continue;
		}

		DWORD teamID = mem.ReadMemory<DWORD>(playerEntity + offsets.m_iTeamNum);

		if (teamID != 2 && teamID != 3) {
			continue;
		}

		DWORD currentGlowIndex = mem.ReadMemory<DWORD>(playerEntity + offsets.m_iGlowIndex);

		if (teamID != localTeam) {
			mem.WriteMemory<float>(glowObj + currentGlowIndex * 0x38 + 0x4, config.whR);	
			mem.WriteMemory<float>(glowObj + currentGlowIndex * 0x38 + 0x8, config.whG);
			mem.WriteMemory<float>(glowObj + currentGlowIndex * 0x38 + 0xC, config.whB);
			mem.WriteMemory<float>(glowObj + currentGlowIndex * 0x38 + 0x10, 1);
			mem.WriteMemory<bool>(glowObj + currentGlowIndex * 0x38 + 0x24, true);
			mem.WriteMemory<bool>(glowObj + currentGlowIndex * 0x38 + 0x25, false);
		}
	}
}