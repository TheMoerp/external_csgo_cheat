#include "skinchanger.h"

// Constant precache IDs of the first knife in the precache list
#define precache_bayonet_ct 90
#define precache_bayonet_t 65

using namespace std;


int modelIndex = 0;

void Skinchanger() {
	int knifeID = config.knifeID;
	// The offsets of knifemodels differs after the tenth knife
	int knifeIDOffset = knifeID < 10 ? 0 : 1;
	int knifeItemID = GetKnifeItemDefinitionID(knifeID);

	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	if (localPlayer) {
		// Iterates to every weapon slot (primary, secondary, knife). If the player holds a bomb for example it's set into an weapon slot
		for (int i = 0; i < 8; i++) {
			DWORD curWeapon = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hMyWeapons + i * 0x4) & 0xFFF;
			DWORD curWeaponBase = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (curWeapon - 1) * 0x10);

			if (curWeaponBase != 0) {
				short curWeaponID = mem.ReadMemory<short>(curWeaponBase + offsets.m_iItemDefinitionIndex);

				// Sets everything but skin, modelindex, knifeItemID, seed
				mem.WriteMemory<int>(curWeaponBase + offsets.m_iItemIDHigh, -1);
				mem.WriteMemory<float>(curWeaponBase + offsets.m_flFallbackWear, 0.00001f);

				if (curWeaponID == 42 || curWeaponID == 59 || curWeaponID == knifeItemID) {
					// curWeapon is knife
					if (modelIndex > 0) {
						Item curItem = GetItemByID(knifeItemID);
						int paintKit = curItem.skinID;

						mem.WriteMemory<short>(curWeaponBase + offsets.m_iItemDefinitionIndex, knifeItemID);
						mem.WriteMemory<int>(curWeaponBase + offsets.m_nFallbackSeed, 661);
						mem.WriteMemory<int>(curWeaponBase + offsets.m_nFallbackPaintKit, paintKit);
						mem.WriteMemory<int>(curWeaponBase + offsets.m_nModelIndex, modelIndex);
					}
				}
				else {
					// curWeapon is weapon
					Item curItem = GetItemByID(curWeaponID);
					if (curItem.skinID != 0) {
						int paintKit = curItem.skinID;

						mem.WriteMemory<int>(curWeaponBase + offsets.m_nFallbackSeed, 661);
						mem.WriteMemory<int>(curWeaponBase + offsets.m_nFallbackPaintKit, paintKit);
					}
				}
			}
		}

		// Calculates and sets the modelindex of the knife
		DWORD activeWeapon = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hActiveWeapon) & 0xFFF;
		DWORD activeWeaponBase = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (activeWeapon - 1) * 0x10);
		if (activeWeaponBase != 0) {
			short activeWeaponID = mem.ReadMemory<short>(activeWeaponBase + offsets.m_iItemDefinitionIndex);
			int weaponViewModelID = mem.ReadMemory<int>(activeWeaponBase + offsets.m_iViewModelIndex);

			if (activeWeaponID == 42) {
				// ct team
				modelIndex = weaponViewModelID + precache_bayonet_ct + knifeID * 3 + knifeIDOffset;
			}
			else if (activeWeaponID == 59) {
				// t team
				modelIndex = weaponViewModelID + precache_bayonet_t + knifeID * 3 + knifeIDOffset;
			}
			else if (activeWeaponID != knifeItemID) {
				// no knife
				return;
			}

			DWORD knifeViewModel = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hViewModel) & 0xFFF;
			knifeViewModel = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (knifeViewModel - 1) * 0x10);

			if (knifeViewModel != 0) {
				// Write modelindex
				mem.WriteMemory<DWORD>(knifeViewModel + offsets.m_nModelIndex, modelIndex);
			}
		}
	}
	else {
		modelIndex = 0;
	}
}