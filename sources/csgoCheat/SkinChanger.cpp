#include <iostream>
#include "SkinChanger.h"

SkinChanger skinChanger;
using namespace std;


void SkinChanger::Run() {
	while (true) {
		DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
		DWORD weaponEntity = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hActiveWeapon) & 0xFFF;
		DWORD weaponBase = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (weaponEntity - 1) * 0x10);
		int weaponID = mem.ReadMemory<int>(weaponBase + offsets.m_iItemDefinitionIndex);
		int paintKit = weaponSkins.GetSkinID(weaponID);
		int curPaintKit = mem.ReadMemory<int>(weaponBase + offsets.m_nFallbackPaintKit);
		
		if (curPaintKit != paintKit && curPaintKit != -1) { 
			mem.WriteMemory<int>(weaponBase + offsets.m_nFallbackPaintKit, paintKit);
			mem.WriteMemory<int>(weaponBase + offsets.m_nFallbackSeed, 661);
			mem.WriteMemory<float>(weaponBase + offsets.m_flFallbackWear, wear);
			mem.WriteMemory<int>(weaponBase + offsets.m_iItemIDHigh, -1);
		}
	}
}