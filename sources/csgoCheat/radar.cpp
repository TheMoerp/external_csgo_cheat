#include "radar.h"

Radar::Radar() {
	std::cout << "--> Radar ready                    (Toggle it with NUM_5)" << std::endl;
}


Radar::~Radar() {}


void Radar::run() {
	// Iterates to every player entity in the current game
	for (int i = 0; i < 32; i++) {
		DWORD entity = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + i * 0x10);

		if (entity != 0) {
			bool entityIsDormant = mem.ReadMemory<bool>(entity + offsets.m_bDormant);

			// Checks if the current entity is updated
			if (!entityIsDormant) {

				DWORD entityTeam = mem.ReadMemory<DWORD>(entity + offsets.m_iTeamNum);

				// Checks if the entity is an ct or t
				if (entityTeam == 2 || entityTeam == 3) {

					// Sets them as spotted
					mem.WriteMemory<bool>(entity + offsets.m_bSpotted, 1);
				}
			}
		}
	}
}