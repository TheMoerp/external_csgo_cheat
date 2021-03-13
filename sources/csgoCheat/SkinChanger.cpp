#include "SkinChanger.h"

SkinChanger skinChanger;


/* The Function gets the weapon ID of the current weapon. It then picks up a random skin ID for the current weapon and
   paints it on the weapon. It runs in a while-true-loop in order not to keep up the timing which is very important for this function.*/
void SkinChanger::Run() {
	while (true) {
		DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer); // gets the address of the local player
		DWORD weaponEntity = mem.ReadMemory<DWORD>(localPlayer + offsets.m_hActiveWeapon) & 0xFFF; // gets the address of the entity of the active weapon
		DWORD weaponBase = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + (weaponEntity - 1) * 0x10); // gets the weapon base of the active weapon
		int weaponID = mem.ReadMemory<int>(weaponBase + offsets.m_iItemDefinitionIndex); // gets the weapon ID of the active weapon

		int paintKit = weaponSkins.GetSkinID(weaponID); // gets a random skin ID depending on the weapon ID

		int curPaintKit = mem.ReadMemory<int>(weaponBase + offsets.m_nFallbackPaintKit); // gets the current skin ID
		if (curPaintKit != paintKit && curPaintKit != -1) { // checks whether it has to change the skin

			// changes the skin, seed and wear of the current weapon
			mem.WriteMemory<int>(weaponBase + offsets.m_nFallbackPaintKit, paintKit);
			mem.WriteMemory<int>(weaponBase + offsets.m_nFallbackSeed, 420);
			mem.WriteMemory<float>(weaponBase + offsets.m_flFallbackWear, wear);
			mem.WriteMemory<int>(weaponBase + offsets.m_iItemIDHigh, -1);
		}
	}
}