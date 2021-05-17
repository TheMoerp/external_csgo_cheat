#include "aimbot.h"

using namespace std;


const int TARGET_BONE = 8;

void Aimbot() {
	// Get localplayer data
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	if (localPlayer) {
		int localPlayerTeam = mem.ReadMemory<int>(localPlayer + offsets.m_iTeamNum);
		// Get enginepointer
		DWORD enginePointer = mem.ReadMemory<DWORD>(offsets.engineBase + offsets.dwClientState);

		oldDistX = 11111111.0;
		oldDistY = 11111111.0;

		// Iterate through all entitys
		for (int i = 1; i < 32; i++) {
			DWORD entity = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + i * 0x10);

			int entityTeam, entityHealth;
			bool entityDormant;
			// Get entity data
			if (entity != 0) {
				try {
					entityTeam = mem.ReadMemory<int>(entity + offsets.m_iTeamNum);
					entityHealth = mem.ReadMemory<int>(entity + offsets.m_iHealth);
					entityDormant = mem.ReadMemory<bool>(entity + offsets.m_bDormant);
				}
				catch (...) {
					continue;
				}
			}

			// Reset target data
			int target = 0;
			int targetHealth = 0;
			bool targetDormant = true;
			Vec3 targetPos, localPos;

			// Checks if the entity is an enemy
			if ((localPlayerTeam != entityTeam) && (entityHealth > 0)) {
				// Get localangles and localpositions
				Vec3 localAngle, entityPos;
				localAngle.x = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x0);
				localAngle.y = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x4);
				localAngle.z = mem.ReadMemory<float>(localPlayer + offsets.m_vecViewOffset + 0x8);
				/*float localXAngle = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x0);
				float localYAngle = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x4);
				float localZAngle = mem.ReadMemory<float>(localPlayer + offsets.m_vecViewOffset + 0x8);*/
				localPos.x = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x0);
				localPos.y = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x4);
				localPos.z = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x8) + localAngle.z;
				/*localPos1 = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x0);
				localPos2 = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x4);
				localPos3 = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x8) + localZAngle;*/

				// Get position of the enemy's head
				DWORD entityBones = mem.ReadMemory<DWORD>(entity + offsets.m_dwBoneMatrix);
				entityPos.x = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0xC);
				entityPos.y = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x1C);
				entityPos.z = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x2C);
				/*float entityPosX = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0xC);
				float entityPosY = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x1C);
				float entityPosZ = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x2C);*/

				// Calculate angles
				Vec2 angleVec = (localPos - entityPos).CalculateAngles();
				/*float deltaX = localPos1 - entityPosX;
				float deltaY = localPos2 - entityPosY;
				float deltaZ = localPos3 - entityPosZ;
				float hypotenuse = sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
				float pitch = (float)atan(deltaZ / hypotenuse) * 180.0 / M_PI;
				float yaw = (float)atan(deltaY / deltaX) * 180.0 / M_PI;
				if (deltaX >= 0.0) {
					yaw = yaw + 180.0;
				}*/

				// Calculate distance
				float distX = angleVec.x - localAngle.x;
				if (distX < -89.0) {
					distX = distX + 360.0;
				}
				else if (distX > 89.0) {
					distX = distX - 360.0;
				}
				if (distX < 0.0) {
					distX = -distX;
				}
				float distY = angleVec.y - localAngle.y;
				if (distY < -180.0) {
					distY = distY + 360.0;
				}
				else if (distY > 180.0) {
					distY = distY - 360.0;
				}
				if (distY < 0.0) {
					distY = -distY;
				}

				// Checks if the enemys head is in FOV range
				if (distX < (oldDistX - 0.25) && distY < (oldDistY - 0.25) && distX <= config.aFOV && distY <= config.aFOV && distX) {
					// If the bot is ready to target an enemy let the enemy glow
					DWORD curGlowIndex = mem.ReadMemory<DWORD>(entity + offsets.m_iGlowIndex);
					DWORD glowObj = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwGlowObjectManager);
					mem.WriteMemory<float>(glowObj + curGlowIndex * 0x38 + 0x4, config.alR);
					mem.WriteMemory<float>(glowObj + curGlowIndex * 0x38 + 0x8, config.alG);
					mem.WriteMemory<float>(glowObj + curGlowIndex * 0x38 + 0xC, config.alB);

					// target = entity
					oldDistX = distX;
					oldDistY = distY;
					target = entity;
					targetHealth = entityHealth;
					targetDormant = entityDormant;
					targetPos = entityPos;
					/*targetPosX = entityPosX;
					targetPosY = entityPosY;
					targetPosZ = entityPosZ;*/
				}
			}

			// Checks if mouse is clicked
			if (GetAsyncKeyState(VK_LBUTTON) < 0 && localPlayer != 0) {
				// Checks if there is a target set
				if (target != 0 && targetHealth > 0 && targetDormant == false) {
					// Calculate angles
					Vec2 angleVec = (localPos - entityPos).CalculateAngles();
					/*float deltaX = localPos1 - targetPosX;
					float deltaY = localPos2 - targetPosY;
					float deltaZ = localPos3 - targetPosZ;
					float hypotenuse = sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
					float pitch = ((double)atan(deltaZ / hypotenuse) * 180.0) / M_PI;
					float yaw = ((double)atan(deltaY / deltaX) * 180.0) / M_PI;
					if (deltaX >= 0.0) {
						yaw = yaw + 180.0;
					}*/

					// Normalize angles
					angleVec.Normalize();
					/*if (pitch > 89.0) {
						pitch = pitch - 360.0;
					}
					if (pitch < -89.0) {
						pitch = pitch + 360.0;
					}
					if (yaw > 180.0) {
						yaw = yaw - 360.0;
					}
					if (yaw < -180.0) {
						yaw = yaw + 360.0;
					}*/

					// Aim
					mem.WriteMemory<float>(enginePointer + offsets.dwClientState_ViewAngles, angleVec.x);
					mem.WriteMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x4, angleVec.y);
					Sleep(1);
				}
			}
		}
	}
}