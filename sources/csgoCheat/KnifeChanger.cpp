#include <iostream>

#include "KnifeChanger.h"


#define precache_bayonet_ct 90
#define precache_bayonet_t 65

using namespace std;

// Gets the Index Definition by KnifeID
int KnifeChanger::GetKnifeIDef(int _knifeID) {
	switch (_knifeID) {
	case 0:
		return 500;
	case 2:
		return 505;
	case 4:
		return 507;
	case 5:
		return 508;
	case 6:
		return 509;
	case 7:
		return 512;
	case 14:
		return 520;
	case 16:
		return 522;
	default:
		break;
	}
}

void KnifeChanger::Run() {
	while (true) {
		// Get knife data
		int knifeID = weaponSkins.knifeID;
		int knifeIDOffset = knifeID < 10 ? 0 : 1;
		int knifeIDef = GetKnifeIDef(knifeID);
		
		DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);

		// checks if the player is ingame
		if (localPlayer == 0) {
			modelIndex = 0;
			continue;
		}

		// checks if the player joined a new game
		else if (localPlayer != cachedPlayer) {
			modelIndex = 0;
			cachedPlayer = localPlayer;
		}

		short weaponID;
		// Sets the knife skin and Index Definition
		for (int i = 0; i < 13; i++) {
			DWORD curWeapon = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hMyWeapons + i * 0x4) & 0xfff;
			curWeapon = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (curWeapon - 1) * 0x10);
			weaponID = mem.ReadMemory<short>(curWeapon + offsets.m_iItemDefinitionIndex);
			int knifeSkinId = weaponSkins.GetKnifeSkinID(knifeID);
			if (weaponID == 42 || weaponID == 59 || weaponID == knifeIDef) {
				if (modelIndex > 0) {
					mem.WriteMemory<short>(curWeapon + offsets.m_iItemDefinitionIndex, knifeIDef);
					mem.WriteMemory<int>(curWeapon + offsets.m_nFallbackPaintKit, knifeSkinId);
					mem.WriteMemory<int>(curWeapon + offsets.m_nFallbackSeed, 412);
					mem.WriteMemory<DWORD>(curWeapon + offsets.m_nModelIndex, modelIndex);
					mem.WriteMemory<DWORD>(curWeapon + offsets.m_iViewModelIndex, modelIndex);
					mem.WriteMemory<int>(curWeapon + offsets.m_iItemIDHigh, -1);
					mem.WriteMemory<float>(curWeapon + offsets.m_flFallbackWear, 0.0001f);
				}
			}
		}
	
		DWORD activeWeapon = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hActiveWeapon) & 0xfff;
		activeWeapon = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (activeWeapon - 1) * 0x10);
		if (activeWeapon == 0) {
			continue;
		}
		weaponID = mem.ReadMemory<short>(activeWeapon + offsets.m_iItemDefinitionIndex);
		int weaponViewModelID = mem.ReadMemory<int>(activeWeapon + offsets.m_iViewModelIndex);

		if (weaponID == 42) {
			modelIndex = weaponViewModelID + precache_bayonet_ct + knifeID * 3 + knifeIDOffset;
			cout << modelIndex << endl;
		}
		if (weaponID == 59) {
			modelIndex = weaponViewModelID +  precache_bayonet_t + knifeID * 3 + knifeIDOffset;
		}

		DWORD knifeViewModel = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hViewModel) & 0xfff;
		knifeViewModel = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (knifeViewModel - 1) * 0x10);
		if (knifeViewModel == 0) {
			continue;
		} 
		if (weaponID == 42 || weaponID == 59 || weaponID == knifeIDef) {
			mem.WriteMemory<short>(activeWeapon + offsets.m_iItemDefinitionIndex, knifeIDef);
			mem.WriteMemory<DWORD>(knifeViewModel + offsets.m_nModelIndex, modelIndex);
			mem.WriteMemory<DWORD>(knifeViewModel + offsets.m_iViewModelIndex, modelIndex);
		}
	}
}		