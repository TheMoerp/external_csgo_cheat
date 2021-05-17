#include "radar.h"

void Radar() {
	for (int i = 0; i < 32; i++) {
		DWORD entity = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + i * 0x10);

		if (entity != 0) {
			bool entityIsDormant = mem.ReadMemory<bool>(entity + offsets.m_bDormant);

			if (!entityIsDormant) {

				DWORD entityTeam = mem.ReadMemory<DWORD>(entity + offsets.m_iTeamNum);

				if (entityTeam == 2 || entityTeam == 3) {
					mem.WriteMemory<bool>(entity + offsets.m_bSpotted, 1);
				}
			}
		}
	}
}