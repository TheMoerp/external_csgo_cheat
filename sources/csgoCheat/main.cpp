#include <iostream>
#include <thread>
#include <windows.h>

#include "memory.h"
#include "bhop.h"
#include "triggerbot.h"
#include "wallhack.h"
#include "skinchanger.h"
#include "weapon.h"
#include "aimbot.h"
#include "config.h"
#include "antiflash.h"
#include "radar.h"

using namespace std;

bool triggerToggle = false;
bool whToggle = false;
bool bhobToggle = false;
bool aimbotToggle = false;
bool antiflashToggle = false;
bool radarToggle = false;


// Initiates the memory process
void Init() {
    cout << "Initiating engine..." << endl;
    mem.Setup();
    mem.GetModules();
    config.LoadConfigs();
}


// Toggle features
void toggleFeatures() {
    if (GetKeyState(VK_NUMPAD2) < 0 && triggerToggle == false) {
        triggerToggle = true;
        cout << "Triggerbot on" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD2) < 0 && triggerToggle == true) {
        triggerToggle = false;
        cout << "Triggerbot off" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD0) < 0 && whToggle == false) {
        whToggle = true;
        cout << "Wallhack on" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD0) < 0 && whToggle == true) {
        whToggle = false;
        cout << "Wallhack off" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD3) < 0 && bhobToggle == false) {
        bhobToggle = true;
        cout << "Bhop on" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD3) < 0 && bhobToggle == true) {
        bhobToggle = false;
        cout << "Bhop off" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD1) < 0 && aimbotToggle == false) {
        aimbotToggle = true;
        cout << "Aimbot on" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD1) < 0 && aimbotToggle == true) {
        aimbotToggle = false;
        cout << "Aimbot off" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD4) < 0 && antiflashToggle == false) {
        antiflashToggle = true;
        cout << "Antiflash on" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD4) < 0 && antiflashToggle == true) {
        antiflashToggle = false;
        cout << "Antiflash off" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD5) < 0 && radarToggle == false) {
        radarToggle = true;
        cout << "Radar on" << endl;
        Sleep(100);
    }
    else if (GetKeyState(VK_NUMPAD5) < 0 && radarToggle == true) {
        radarToggle = false;
        cout << "Radar off" << endl;
        Sleep(100);
    }
}


void NoDelayFeatures() {
    cout << "--> Triggerbot ready               (Toggle it with NUM_2)" << endl;
    cout << "--> Autoaim ready                  (Toggle it with NUM_1)" << endl;
    cout << "--> Bhop ready                     (Toggle it with NUM_3)" << endl;

    while (true) {
        if (triggerToggle) {
            Triggerbot();
        }
        if (bhobToggle) {
            Bhop();
        }
        if (aimbotToggle) {
            Aimbot();
        }
        
    }
}


void DelayFeatures() {
    Sleep(10);
    cout << "--> Wallhack ready                 (Toggle it with NUM_0)" << endl;
    cout << "--> Radar ready                    (Toggle it with NUM_5)" << endl;
    cout << "--> Antiflash ready                (Toggle it with NUM_4)" << endl;
    
 
    while (true) {
        if (whToggle) {
            Wallhack();
        }
        if (radarToggle) {
            Radar();
        }
        if (antiflashToggle) {
            antiflash();
        }
        Sleep(1);
    }
}


void SkinChangerThread() {
    Sleep(30);
    cout << "--> Skinchanger activated" << endl;
    cout << "" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "\n\n\n                         Toggle Log" << endl;
    cout << "----------------------------------------------------------\n" << endl;
    cout << "Triggerbot off\nAntiflash off\nWallhack off\nAutoaim off\nRadar off\nBhop off" << endl;

    LoadSkinConfig();
    while (true) {
        Skinchanger();
    }
}


int main()
{
    SetConsoleTitle(L"TheMoerper - external");
    
    // Sets window size
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 500, 700, TRUE);

    cout << "\n                   The Moerper - external" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "waiting for CS:GO..." << endl;

    Init();

    cout << "" << endl;
    cout << "Starting Features..." << endl;
    
    // Starts threads
    thread NoDelayThread(NoDelayFeatures);
    thread DelayThread(DelayFeatures);
    thread SkinChangerThread(SkinChangerThread);

    Sleep(20);
    while (true) {
        toggleFeatures();
        Sleep(50);
    }
}