#include "aimbot.h"

Aimbot::Aimbot() {
	std::cout << "--> Autoaim ready                  (Toggle it with NUM_1)" << std::endl;
}

Aimbot::~Aimbot() {

}

void Aimbot::run() {
	// Get localplayer data
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	if (localPlayer) {
		int localPlayerTeam = mem.ReadMemory<int>(localPlayer + offsets.m_iTeamNum);
		// Get enginepointer
		DWORD enginePointer = mem.ReadMemory<DWORD>(offsets.engineBase + offsets.dwClientState);

		float oldDistX = 11111111.0;
		float oldDistY = 11111111.0;

		// Iterate through all entitys
		for (int i = 1; i < 32; i++) {
			DWORD entity = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + i * 0x10);

			// Get entity data
			if (entity == 0) {
				continue;
			}

			int entityTeam = mem.ReadMemory<int>(entity + offsets.m_iTeamNum);
			int entityHealth = mem.ReadMemory<int>(entity + offsets.m_iHealth);
			bool entityDormant = mem.ReadMemory<bool>(entity + offsets.m_bDormant);

			// Reset target data
			int target = 0;
			int targetHealth = 0;
			bool targetDormant = true;
			Vec3 targetPos, localPos;

			// Checks if the entity is an enemy
			if ((localPlayerTeam != entityTeam) && (entityHealth > 0)) {

				// Get localangles
				Vec3 localAngle, entityPos;
				localAngle.x = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x0);
				localAngle.y = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x4);
				localAngle.z = mem.ReadMemory<float>(localPlayer + offsets.m_vecViewOffset + 0x8);

				// Get localposition
				localPos.x = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x0);
				localPos.y = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x4);
				localPos.z = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x8) + localAngle.z;

				DWORD entityBones = mem.ReadMemory<DWORD>(entity + offsets.m_dwBoneMatrix);

				// Get position of the enemy's head
				entityPos.x = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x0C);
				entityPos.y = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x1C);
				entityPos.z = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x2C);


				// Calculate angles
				Vec3 tmp = localPos - entityPos;
				Vec2 angleVec = tmp.CalculateAngles();

				// Calculate distance
				float distX = angleVec.x - localAngle.x;
				if (distX < -89.0) {
					distX += 360.0;
				}
				else if (distX > 89.0) {
					distX -= 360.0;
				}
				if (distX < 0.0) {
					distX = -distX;
				}
				float distY = angleVec.y - localAngle.y;
				if (distY < -180.0) {
					distY += 360.0;
				}
				else if (distY > 180.0) {
					distY -= 360.0;
				}
				if (distY < 0.0) {
					distY = -distY;
				}

				// Checks if the enemys head is in FOV range
				if (distX < (oldDistX - 0.25) && distY < (oldDistY - 0.25) && distX <= config.aFOV && distY <= config.aFOV && distX) {

					// If the bot is ready to target an enemy let the enemy glow
					DWORD curGlowIndex = mem.ReadMemory<DWORD>(entity + offsets.m_iGlowIndex);
					DWORD glowObj = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwGlowObjectManager);
					mem.WriteMemory<float>(glowObj + curGlowIndex * 0x38 + 0x8, 0.0);
					mem.WriteMemory<float>(glowObj + curGlowIndex * 0x38 + 0xC, 2.0);
					mem.WriteMemory<float>(glowObj + curGlowIndex * 0x38 + 0x10, 0.0);

					// target = entity
					oldDistX = distX;
					oldDistY = distY;
					target = entity;
					targetHealth = entityHealth;
					targetDormant = entityDormant;
					targetPos = entityPos;
				}
			}

			// Checks if mouse is clicked
			if (GetAsyncKeyState(VK_LBUTTON) < 0 && localPlayer != 0) {

				// Checks if there is a target set
				if (target != 0 && targetHealth > 0 && targetDormant == false) {

					// Calculate angles
					Vec3 tmp = localPos - targetPos;
					Vec2 angleVec = tmp.CalculateAngles();

					// Normalize angles
					angleVec.Normalize();

					// Aim
					mem.WriteMemory<float>(enginePointer + offsets.dwClientState_ViewAngles, angleVec.x);
					mem.WriteMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x4, angleVec.y);

					Sleep(1);
				}
			}
		}
	}
}
