#include <iostream>

#include "KnifeChanger.h"


#define precache_bayonet_ct 87
#define precache_bayonet_t 63

using namespace std;

const short knifeIDef = 500;
const int knifeID = 0;
const int itemIDHigh = -1;
const int entityQuality = 3;
const float fallbackWear = 0.0001f;
DWORD cachedPlayer = 0;
int knifeIDOffset = knifeID < 10 ? 0 : 1;
DWORD modelIndex = 0;







void KnifeChanger::Run() {
	while (true) {




		DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
		if (localPlayer == 0) {
			modelIndex = 0;
			continue;
		}
		else if (localPlayer != cachedPlayer) {
			modelIndex = 0;
			cachedPlayer = localPlayer;
		}
		/*
		if (paintKit > 0 && modelIndex > 0) {
			for (int i = 0; i < 8; i++) {
				DWORD curWeapon = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hMyWeapons + i * 0x4) & 0xfff;
				curWeapon = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (curWeapon - 1) * 0x10);
				short weaponID = mem.ReadMemory<short>(curWeapon + offsets.m_iItemDefinitionIndex);
				cout << weaponID << endl;
				DWORD fallbackPaint = paintKit;
				if (weaponID == -13108) {
					cout << "yes" << endl;
					mem.WriteMemory<short>(curWeapon + offsets.m_iItemDefinitionIndex, knifeIDef);
					mem.WriteMemory<DWORD>(curWeapon + offsets.m_nModelIndex, modelIndex);
					mem.WriteMemory<DWORD>(curWeapon + offsets.m_iViewModelIndex, modelIndex);
					mem.WriteMemory<int>(curWeapon + offsets.m_iEntityQuality, entityQuality);
				}
				mem.WriteMemory<int>(curWeapon + offsets.m_iItemIDHigh, itemIDHigh);
				mem.WriteMemory<int>(curWeapon + offsets.m_nFallbackPaintKit, 576);
				mem.WriteMemory<float>(curWeapon + offsets.m_flFallbackWear, fallbackWear);
			}
		}
		*/
	
		DWORD activeWeapon = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hActiveWeapon) & 0xfff;
		activeWeapon = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (activeWeapon - 1) * 0x10);
		if (activeWeapon == 0) {
			continue;
		}
		short weaponID = mem.ReadMemory<short>(activeWeapon + offsets.m_iItemDefinitionIndex);
		int weaponViewModelID = mem.ReadMemory<int>(activeWeapon + offsets.m_iViewModelIndex);
		if (weaponID == 59 && weaponViewModelID > 0) {
			modelIndex = weaponViewModelID + 77; // 92 // 89 // 86 perfect // 83 perfect // 80 perfect // 77 perfect // 74 perfect // 71 // 3er abstannd
			//cout << "modelIndex: " << modelIndex << endl;
			mem.WriteMemory<short>(weaponID + offsets.m_iItemDefinitionIndex, knifeIDef);
			mem.WriteMemory<DWORD>(weaponID + offsets.m_nModelIndex, modelIndex);
			mem.WriteMemory<DWORD>(weaponID + offsets.m_iViewModelIndex, modelIndex);
			mem.WriteMemory<int>(weaponID + offsets.m_iEntityQuality, entityQuality);
		}
		else if (weaponID != knifeIDef || modelIndex == 0) {
			continue;
		}

		DWORD knifeViewModel = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hViewModel) & 0xfff;
		knifeViewModel = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (knifeViewModel - 1) * 0x10);
		if (knifeViewModel == 0) {
			continue;
		}
		
		mem.WriteMemory<DWORD>(knifeViewModel + offsets.m_nModelIndex, modelIndex);
		mem.WriteMemory<short>(weaponID + offsets.m_iItemDefinitionIndex, knifeIDef);
		mem.WriteMemory<DWORD>(weaponID + offsets.m_nModelIndex, modelIndex);
		mem.WriteMemory<DWORD>(weaponID + offsets.m_iViewModelIndex, modelIndex);
		mem.WriteMemory<int>(weaponID + offsets.m_iEntityQuality, entityQuality);
		//mem.WriteMemory<int>(activeWeapon + offsets.m_iItemIDHigh, itemIDHigh);
		//mem.WriteMemory<int>(activeWeapon + offsets.m_nFallbackPaintKit, 576);
		//mem.WriteMemory<float>(activeWeapon + offsets.m_flFallbackWear, fallbackWear);
	}
}		