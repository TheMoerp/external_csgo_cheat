#include <iostream>

#include "KnifeChanger.h"


#define precache_bayonet_ct 90
#define precache_bayonet_t 65

using namespace std;

const int itemIDHigh = -1;
const int entityQuality = 3;
const float fallbackWear = 0.0001f;
DWORD cachedPlayer = 0;
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


		int knifeID = weaponSkins.knifeID;
		int knifeSkinId = weaponSkins.GetKnifeSkinID(knifeID);
		int knifeIDOffset = knifeID < 10 ? 0 : 1;
		int knifeIDef = GetKnifeIDef(knifeID);
		
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
				DWORD fallbackPaint = paintKit;

				if (weaponID == 42 || weaponID == 59 || weaponID == knifeIDef) {
					if (modelIndex > 0) {
						mem.WriteMemory<short>(curWeapon + offsets.m_iItemDefinitionIndex, knifeIDef);
						mem.WriteMemory<int>(curWeapon + offsets.m_nFallbackPaintKit, knifeSkinId);
						mem.WriteMemory<DWORD>(curWeapon + offsets.m_nModelIndex, modelIndex);
						mem.WriteMemory<DWORD>(curWeapon + offsets.m_iViewModelIndex, modelIndex);
						//mem.WriteMemory<int>(curWeapon + offsets.m_iEntityQuality, entityQuality);
						mem.WriteMemory<int>(curWeapon + offsets.m_iItemIDHigh, itemIDHigh);
						mem.WriteMemory<float>(curWeapon + offsets.m_flFallbackWear, fallbackWear);

					}
				}
			}
		DWORD activeWeapon = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hActiveWeapon) & 0xfff;
		activeWeapon = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (activeWeapon - 1) * 0x10);
		if (activeWeapon == 0) {
			continue;
		}
		short weaponID = mem.ReadMemory<short>(activeWeapon + offsets.m_iItemDefinitionIndex);
		int weaponViewModelID = mem.ReadMemory<int>(activeWeapon + offsets.m_iViewModelIndex);
		if (weaponID == 42) {
			modelIndex = weaponViewModelID + precache_bayonet_ct + knifeID * 3 + knifeIDOffset;//- (449 - 539);
			cout << modelIndex << endl;
		}
		if (weaponID == 59) {
			modelIndex = weaponViewModelID +  precache_bayonet_t + knifeID * 3 + knifeIDOffset;//- (449 - 539);
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