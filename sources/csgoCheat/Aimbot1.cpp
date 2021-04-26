#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Aimbot1.h"

using namespace std;


int TARGET_BONE = 8; //8 = head
int AIM_FOV = 5.0;



void Aimbot::Run() {
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	int localPlayerTeam = mem.ReadMemory<int>(localPlayer + offsets.m_iTeamNum);
	DWORD enginePointer = mem.ReadMemory<DWORD>(offsets.engineBase + offsets.dwClientState);

	DWORD target;
	int oldDistX = 11111111;
	int oldDistY = 11111111;
	//cout << "got local data" << endl;
	for (int i = 1; i < 32; i++) {
		DWORD entity = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + i * 0x10);
		//cout << "------------ found an entity in loop round no. " << i << " ----------" << endl;
		int entityTeam = 0;
		int entityHealth = 0;
		bool entityDormant = false;
		if (entity != 0) {
			try {
				entityTeam = mem.ReadMemory<int>(entity + offsets.m_iTeamNum);
				entityHealth = mem.ReadMemory<int>(entity + offsets.m_iHealth);
				entityDormant = mem.ReadMemory<bool>(entity + offsets.m_bDormant);
				//cout << "got data of the entity" << endl;
			}
			catch(...) {
				//cout << "failed to get the data of the entity" << endl;
			}
		}
		
		float localXAngle;
		float localYAngle;
		float localZAngle;
		float localPos1;
		float localPos2;
		float localPos3;
		float enitityPosX;
		float enitityPosY;
		float enitityPosZ;
		DWORD target = 0;
		int targetHealth = 0;
		bool targetDormant = true;
		float targetPosX = 0.0;
		float targetPosY = 0.0;
		float targetPosZ = 0.0;
		//try {
			if ((localPlayerTeam != entityTeam) && (entityHealth > 0)) {
				//cout << "the entity is a living enemy" << endl;
				// calc pos
				//cout << "reading in localPos..." << endl;
				localXAngle = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x0);
				localYAngle = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x4);
				localZAngle = mem.ReadMemory<float>(localPlayer + offsets.m_vecViewOffset + 0x8);
				localPos1 = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x0);
				localPos2 = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x4);
				localPos3 = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x8) + localZAngle;
				//cout << "localPosX: " << localPos1 << " localPosY: " << localPos2 << " localPosZ: " << localPos3 << endl;
				//cout << "reading in enemyPos..." << endl;
				DWORD entityBones = mem.ReadMemory<DWORD>(entity + offsets.m_dwBoneMatrix);
				float entityPosX = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0xC);
				float entityPosY = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x1C);
				float entityPosZ = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x2C);
				//cout << "enemyPosX: " << entityPosX << " enemyPosY: " << entityPosY << " enemyPosZ: " << entityPosZ << endl;
				//cout << "calculating angles..." << endl;
				// calc angle
				float deltaX = localPos1 - entityPosX;
				float deltaY = localPos2 - entityPosY;
				float deltaZ = localPos3 - entityPosZ;
				float hypotenuse = sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
				float pitch = (float)atan(deltaZ / hypotenuse) * 180.0 / M_PI;
				float yaw = (float)atan(deltaY / deltaX) * 180.0 / M_PI;
				if (deltaX >= 0.0) {
					yaw = yaw + 180.0;
				}
				//cout << "pitch: " << pitch << " yaw: " << yaw << endl;
				//cout << "calculating distance..." << endl;
				// calc dist
				float distX = pitch - localXAngle;
				if (distX < -89.0) {
					distX = distX + 360.0;
				}
				else if (distX > 89.0) {
					distX = distX - 360.0;
				}
				if (distX < 0.0) {
					distX = -distX;
				}
				float distY = yaw - localYAngle;
				if (distY < -180.0) {
					distY = distY + 360.0;
				}
				else if (distY > 180.0) {
					distY = distY - 360.0;
				}
				if (distY < 0.0) {
					distY = -distY;
				}
				

					//cout << "distX: " << distX << " distY: " << distY << endl;
					//cout << "oldDistX: " << oldDistX << " oldDistY: " << oldDistY << endl;
					/*
					DWORD target = 4;
					int targetHealth = 0;
					bool targetDormant = true;
					double targetPosX = 0.0;
					double targetPosY = 0.0;
					double targetPosZ = 0.0;
					*/
					//cout << distX << " < " << oldDistX << " && " << distY << " < " << oldDistY << " && " << distX << " <= " << AIM_FOV << " && " << distY << " <= " << AIM_FOV << endl;
				if (distX < (oldDistX-0.25) && distY < (oldDistY-0.25) && distX <= AIM_FOV && distY <= AIM_FOV && distX) {
					DWORD curGlowIndex = mem.ReadMemory<DWORD>(entity + offsets.m_iGlowIndex);
					DWORD glowObj = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwGlowObjectManager);
					float green = 3.0;
					float red = 0.0;
					mem.WriteMemory<float>(glowObj + curGlowIndex * 0x38 + 0x4, red);
					mem.WriteMemory<float>(glowObj + curGlowIndex * 0x38 + 0x8, green);
					//cout << "save entityData as targetData..." << endl;
					float oldDistX = distX;
					float oldDistY = distY;
					target = entity;
					targetHealth = entityHealth;
					targetDormant = entityDormant;
					targetPosX = entityPosX;
					targetPosY = entityPosY;
					targetPosZ = entityPosZ;
				}
			}


			if (GetAsyncKeyState(VK_LBUTTON) < 0 && localPlayer != 0) {
				//cout << "localPlayer != 0" << endl;
				if (target != 0 && targetHealth > 0 && targetDormant == false) {
					//cout << "target is alive and updated" << endl;
					// recalc angles of target
					//cout << "calculating angles of the target..." << endl;
					float deltaX = localPos1 - targetPosX;
					float deltaY = localPos2 - targetPosY;
					float deltaZ = localPos3 - targetPosZ;
					float hypotenuse = sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
					float pitch = ((double)atan(deltaZ / hypotenuse) * 180.0) / M_PI;
					float yaw = ((double)atan(deltaY / deltaX) * 180.0) / M_PI;
					if (deltaX >= 0.0) {
						yaw = yaw + 180.0;
					}
					//cout << "targetPitch: " << pitch << " targetYaw: " << yaw << endl;
					// normalize angles
					//cout << "normalizing angles..." << endl;
					if (pitch > 89.0) {
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
					}
					//cout << "normalizedPitch: " << pitch << " normalizedYaw: " << yaw << endl;
					// aim
					//cout << "------------------------ AIMING ---------------------------" << endl;
					mem.WriteMemory<float>(enginePointer + offsets.dwClientState_ViewAngles, pitch);
					mem.WriteMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x4, yaw);
				}
			}
		//}
		//catch(...) {
		//	cout << "ex" << endl;
		//}

		
	}
}