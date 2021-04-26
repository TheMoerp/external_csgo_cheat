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


int KARAMBIT_T = 77;
int HUNTSMAN_T = 83;
int M9_BAYONET_T = 80;
int GUT_T = 74;
int FLIP_T = 71;
int CLASSIC_T = 68;
int BAYONET_T = 65;
int NAVAJA_T = 108;
int STILETTO_T = 114;



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
			
			for (int i = 0; i < 13; i++) {
				DWORD curWeapon = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hMyWeapons + i * 0x4) & 0xfff;
				curWeapon = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (curWeapon - 1) * 0x10);
				short weaponID = mem.ReadMemory<short>(curWeapon + offsets.m_iItemDefinitionIndex);
				//cout << weaponID << endl;
				DWORD fallbackPaint = paintKit;

				if (weaponID == 42 || weaponID == 59 || weaponID == knifeIDef) {
					if (modelIndex > 0) {
						mem.WriteMemory<short>(curWeapon + offsets.m_iItemDefinitionIndex, knifeIDef);
						mem.WriteMemory<DWORD>(curWeapon + offsets.m_nModelIndex, modelIndex);
						mem.WriteMemory<DWORD>(curWeapon + offsets.m_iViewModelIndex, modelIndex);
						mem.WriteMemory<int>(curWeapon + offsets.m_iEntityQuality, entityQuality);
						mem.WriteMemory<int>(curWeapon + offsets.m_iItemIDHigh, itemIDHigh);
						mem.WriteMemory<int>(curWeapon + offsets.m_nFallbackPaintKit, 419);
						mem.WriteMemory<float>(curWeapon + offsets.m_flFallbackWear, fallbackWear);

					}
				}
				
				
			//	cout << "set skin" << endl;
				
			}
			
		
			//cout << "skin set!!" << endl;
		DWORD activeWeapon = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hActiveWeapon) & 0xfff;
		activeWeapon = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (activeWeapon - 1) * 0x10);
		if (activeWeapon == 0) {
			//cout << "activeWeapon == 0" << endl;
			continue;
		}
		short weaponID = mem.ReadMemory<short>(activeWeapon + offsets.m_iItemDefinitionIndex);
		int weaponViewModelID = mem.ReadMemory<int>(activeWeapon + offsets.m_iViewModelIndex);
		//cout << weaponViewModelID << endl;
		if (weaponID == 42) {
			modelIndex = weaponViewModelID + 90;//- (449 - 539);
		}
		if (weaponID == 59) {
			modelIndex = weaponViewModelID + 65;//- (449 - 539);
		}
		//cout << modelIndex << endl;

		/*
		if (weaponID == 59 && weaponViewModelID > 0) {
			cout << "set model" << endl;
			modelIndex = weaponViewModelID + KARAMBIT_T;
			mem.WriteMemory<short>(weaponID + offsets.m_iItemDefinitionIndex, knifeIDef);
			mem.WriteMemory<DWORD>(weaponID + offsets.m_nModelIndex, modelIndex);
			mem.WriteMemory<DWORD>(weaponID + offsets.m_iViewModelIndex, modelIndex);
			mem.WriteMemory<int>(weaponID + offsets.m_iEntityQuality, entityQuality);
		}
		else if (weaponID == 42 && weaponViewModelID > 0) {
			modelIndex = weaponViewModelID + 102;
			mem.WriteMemory<short>(weaponID + offsets.m_iItemDefinitionIndex, knifeIDef);
			mem.WriteMemory<DWORD>(weaponID + offsets.m_nModelIndex, modelIndex);
			mem.WriteMemory<DWORD>(weaponID + offsets.m_iViewModelIndex, modelIndex);
			mem.WriteMemory<int>(weaponID + offsets.m_iEntityQuality, entityQuality);
		}
		*/
		//else if (weaponID != knifeIDef || modelIndex == 0) {
		//	cout << "weaponID != knifeIDef || modelIndex == 0" << endl;
		//	continue;
			
		//}

		DWORD knifeViewModel = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hViewModel) & 0xfff;
		knifeViewModel = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (knifeViewModel - 1) * 0x10);
		if (knifeViewModel == 0) {
			//cout << "knifeViewModel == 0" << endl;
			continue;
			
		} 
		//cout << "modelindex: " << modelIndex << endl;
		//cout << "-------set----------" << endl;
		if (weaponID == 42 || weaponID == 59 || weaponID == knifeIDef) {
			mem.WriteMemory<short>(activeWeapon + offsets.m_iItemDefinitionIndex, knifeIDef);
			mem.WriteMemory<DWORD>(knifeViewModel + offsets.m_nModelIndex, modelIndex);
			mem.WriteMemory<DWORD>(knifeViewModel + offsets.m_iViewModelIndex, modelIndex);
		}
	}
}		