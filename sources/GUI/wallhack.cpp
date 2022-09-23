#include "wallhack.h"

using namespace std;


void Wallhack() {
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	DWORD glowObj = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwGlowObjectManager);
	DWORD localTeam = mem.ReadMemory<DWORD>(localPlayer + offsets.m_iTeamNum);

	// Iterates to every player entity in the current game
	for (int i = 0; i < 32; i++) {
		DWORD entity = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + i * 0x10);

		if (entity == 0) {
			continue;
		}

		// Checks if the current entity is updated
		bool entityIsDormant = mem.ReadMemory<bool>(entity + offsets.m_bDormant);
		if (entityIsDormant) {
			continue;
		}

		DWORD teamID = mem.ReadMemory<DWORD>(entity + offsets.m_iTeamNum);

		// Checks if the entity is a ct or t
		if (teamID != 2 && teamID != 3) {
			continue;
		}

		DWORD currentGlowIndex = mem.ReadMemory<DWORD>(entity + offsets.m_iGlowIndex);
		// Checks if the entity is an enemy
		if (teamID != localTeam) {

			// Sets the glowing color A
			mem.WriteMemory<float>(glowObj + currentGlowIndex * 0x38 + 0x8, config.whRed);
			mem.WriteMemory<float>(glowObj + currentGlowIndex * 0x38 + 0xC, config.whGreen);
			mem.WriteMemory<float>(glowObj + currentGlowIndex * 0x38 + 0x10, config.whBlue);
			mem.WriteMemory<float>(glowObj + currentGlowIndex * 0x38 + 0x14, 1.0f);
			mem.WriteMemory<bool>(glowObj + currentGlowIndex * 0x38 + 0x28, true);
			mem.WriteMemory<bool>(glowObj + currentGlowIndex * 0x38 + 0x29, false);




		}
	}
}
