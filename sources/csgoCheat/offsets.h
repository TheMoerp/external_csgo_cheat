#pragma once
#include <Windows.h>


class Offsets
{

public:
	DWORD m_bSpotted = 0x93D;
	DWORD m_clrRender = 0x70;
	DWORD m_fFlags = 0x104;
	DWORD m_flFlashDuration = 0xA420;
	DWORD m_iCrosshairId = 0xB3E8;
	DWORD m_iGlowIndex = 0xA438;
	DWORD m_iTeamNum = 0xF4;
	DWORD m_iHealth = 0x100;
	DWORD m_hMyWeapons = 0x2DF8;
	DWORD m_iItemDefinitionIndex = 0x2FAA;
	DWORD m_OriginalOwnerXuidLow = 0x31C0;
	DWORD m_nFallbackPaintKit = 0x31C8;
	DWORD m_nFallbackSeed = 0x31CC;
	DWORD m_flFallbackWear = 0x31D0;
	DWORD m_iAccountID = 0x2FC8;
	DWORD m_iEntityQuality = 0x2FAC;
	DWORD m_iItemIDHigh = 0x2FC0;
	DWORD m_szCustomName = 0x303C;
	DWORD m_hActiveWeapon = 0x2EF8;
	DWORD m_bDormant = 0xED;
	DWORD m_hViewModel = 0x32F8;
	DWORD m_iViewModelIndex = 0x3240;
	DWORD m_nModelIndex = 0x258;
	DWORD m_vecOrigin = 0x138;
	DWORD m_vecViewOffset = 0x108;
	DWORD m_dwBoneMatrix = 0x26A8;
	DWORD m_aimPunchAngle = 0x302C;
	DWORD m_iShotsFired = 0xA390;
	DWORD model_ambient_min = 0x58D05C;

	DWORD dwClientState_ViewAngles = 0x4D90;
	DWORD dwClientState = 0;		// patternscan
	DWORD dwLocalPlayer = 0;		// patternscan
	DWORD dwEntityList = 0;			// patternscan
	DWORD dwForceJump = 0;			// patternscan
	DWORD dwGlowObjectManager = 0;  // patternscan


	DWORD processID = 0;
	HANDLE hProcess = 0;
	DWORD clientBase = 0;
	DWORD engineBase = 0;

	void OffsetUpdate();
};

extern Offsets offsets; 
