#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Aimbot1.h"

using namespace std;


int TARGET_BONE = 8; //8 = head
int AIM_FOV = 120.0;



void Aimbot::Run() {
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer);
	int localPlayerTeam = mem.ReadMemory<int>(localPlayer + offsets.m_iTeamNum);
	DWORD enginePointer = mem.ReadMemory<DWORD>(offsets.engineBase + offsets.dwClientState);

	DWORD target;
	int oldDistX = 11111111;
	int oldDistY = 11111111;

	for (int i = 1; i < 32; i++) {
		DWORD entity = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + i * 0x10);

		int entityTeam = 0;
		int entityHealth = 0;
		bool entityDormant = false;
		cout << "i have to get entity data" << endl;
		if (entity != 0) {
			try {
				cout << "enitiy data" << endl;
				entityTeam = mem.ReadMemory<int>(entity + offsets.m_iTeamNum);
				entityHealth = mem.ReadMemory<int>(entity + offsets.m_iHealth);
				entityDormant = mem.ReadMemory<bool>(entity + offsets.m_bDormant);
			}
			catch(...) {
				cout << "ex" << endl;
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
		DWORD target = 4;
		int targetHealth = 0;
		bool targetDormant = true;
		double targetPosX = 0.0;
		double targetPosY = 0.0;
		double targetPosZ = 0.0;
		try {
			if ((localPlayerTeam != entityTeam) && (entityHealth > 0)) {
				cout << "its an enemy" << endl;
				// calc pos
				localXAngle = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x0);
				localYAngle = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x4);
				localZAngle = mem.ReadMemory<float>(enginePointer + offsets.dwClientState_ViewAngles + 0x8);
				localPos1 = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x0);
				localPos2 = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x4);
				localPos3 = mem.ReadMemory<float>(localPlayer + offsets.m_vecOrigin + 0x8);

				DWORD entityBones = mem.ReadMemory<DWORD>(entity + offsets.m_dwBoneMatrix);
				float entityPosX = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0xC);
				float entityPosY = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x1C);
				float entityPosZ = mem.ReadMemory<float>(entityBones + 0x30 * TARGET_BONE + 0x2C);
				cout << "epX: " << entityPosX << " epY: " << entityPosY << " epZ: " << entityPosZ << endl;
				cout << "got the enemy pos" << endl;

				// calc angle

					float deltaX = localPos1 - entityPosX;
					float deltaY = localPos2 - entityPosY;
					float deltaZ = localPos3 - entityPosZ;
					float hypotenuse = sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
					double pitch = atan(deltaZ / hypotenuse) * 180 / M_PI;
					double yaw = atan(deltaY / deltaX) * 180 / M_PI;
					if (deltaX >= 0.0) {
						yaw = yaw + 180;
					}
					cout << "got the angle" << endl;
					cout << "pitch: " << pitch << " yaw: " << yaw << endl;
					// calc dist
					double distX = pitch - localXAngle;
					if (distX < -89.0) {
						distX = distX + 360;
					}
					else if (distX > 89.0) {
						distX = distX - 360;
					}
					if (distX < 0.0) {
						distX = -distX;
					}
					double distY = yaw - localYAngle;
					if (distY < -89.0) {
						distY = distY + 360;
					}
					else if (distY > 89.0) {
						distY = distY - 360;
					}
					if (distY < 0.0) {
						distY = -distY;
					}
					cout << "got the distance" << endl;

					cout << "new x: " << distX << " new y: " << distY << endl;
					cout << "old x: " << oldDistX << " old y: " << oldDistY << endl;
					/*
					DWORD target = 4;
					int targetHealth = 0;
					bool targetDormant = true;
					double targetPosX = 0.0;
					double targetPosY = 0.0;
					double targetPosZ = 0.0;
					*/
					cout << distX << " < " << oldDistX << " && " << distY << " < " << oldDistY << " && " << distX << " <= " << AIM_FOV << " && " << distY << " <= " << AIM_FOV << endl;
					if (distX < oldDistX && distY < oldDistY && distX <= AIM_FOV && distY <= AIM_FOV) {
						cout << "giving target data" << endl;
						double oldDistX = distX;
						double oldDistY = distY;
						target = entity;
						targetHealth = entityHealth;
						targetDormant = entityDormant;
						targetPosX = entityPosX;
						targetPosY = entityPosY;
						targetPosZ = entityPosZ;
					}
				}
				if (localPlayer != 0) {
						if (target != 0 && targetHealth > 0 && targetDormant == false) {
							cout << "calculating target pos" << endl;
							// recalc angles of target
							double deltaX = localPos1 - targetPosX;
							double deltaY = localPos2 - targetPosY;
							double deltaZ = localPos3 - targetPosZ;
							double hypotenuse = sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
							double pitch = atan(deltaZ / hypotenuse) * 180 / M_PI;
							double yaw = atan(deltaY / deltaX) * 180 / M_PI;
							if (deltaX >= 0.0) {
								yaw = yaw + 180;
							}
							// normalize angles
							if (pitch > 89) {
								pitch = pitch - 360;
							}
							if (pitch < -89) {
								pitch = pitch + 360;
							}
							if (pitch > 180) {
								pitch = pitch - 360;
							}
							if (pitch < -180) {
								pitch = pitch + 360;
							}
						
							// aim
							cout << "---- AIMING ----" << endl;
							mem.WriteMemory<double>(enginePointer + offsets.dwClientState_ViewAngles, pitch);
							mem.WriteMemory<double>(enginePointer + offsets.dwClientState_ViewAngles + 0x4, yaw);
						}
				}
		}
		catch(...) {
			cout << "ex" << endl;
		}

		
	}
}