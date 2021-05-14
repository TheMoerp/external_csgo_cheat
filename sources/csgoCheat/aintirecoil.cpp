#include "antirecoil.h"

struct Vec3 {
	float x, y, z;

	Vec3 operator+(Vec3 d) {
		return { x + d.x, y + d.y, z + d.z };
	}
	Vec3 operator-(Vec3 d) {
		return { x - d.x, y - d.y, z - d.z };
	}
	Vec3 operator*(float d) {
		return { x * d, y * d, z * d };
	}

	void Normalize() {
		while (y < -180) { y += 360; }
		while (y > 180) { y -= 360; }
		if (x > 89) { x = 89; }
		if (x < -89) { x = -89; }
	}
};

Vec3 oPunch{ 0,0,0 };
void antirecoil() {
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	DWORD enginePointer = mem.ReadMemory<DWORD>(offsets.engineBase + offsets.dwClientState);

	Vec3 viewAngles, aimPunchAngle;
	viewAngles.x = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x0);
	viewAngles.y = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x4);
	viewAngles.z = mem.ReadMemory<float>(localPlayer + offsets.m_vecViewOffset + 0x8);

	aimPunchAngle.x = mem.ReadMemory<float>(localPlayer + offsets.m_aimPunchAngle + 0x0);
	aimPunchAngle.y = mem.ReadMemory<float>(localPlayer + offsets.m_aimPunchAngle + 0x4);
	aimPunchAngle.z = mem.ReadMemory<float>(localPlayer + offsets.m_aimPunchAngle + 0x8);

	int shotsFired = mem.ReadMemory<int>(localPlayer + offsets.m_iShotsFired);

	Vec3 punchAngle = aimPunchAngle * 2;

	if (shotsFired > 1) {
		Vec3 nAngle = viewAngles + oPunch - punchAngle;
		nAngle.Normalize();
		viewAngles = nAngle;
	}
	oPunch = punchAngle;
}