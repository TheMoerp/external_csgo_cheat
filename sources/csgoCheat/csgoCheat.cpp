#include <iostream>
#include <thread>
#include <windows.h>

#include "Memory.h"
#include "Bhop.h"
#include "Trigger.h"
#include "Wallhack.h"
#include "SkinChanger.h"
#include "WeaponSkins.h"
#include "Aimbot1.h"
#include "KnifeChanger.h"

using namespace std;

bool triggerToggle = false;
bool whToggle = false;
bool bhobToggle = false;
bool rsToggle = false;
bool aimbotToggle = false;

// Initiates the memory process
void Init() {
    cout << "Initiating engine..." << endl;
    mem.Setup();
    mem.GetModules();
}

// Toggle features
void toggleFeatures() {
    if (GetKeyState('V') < 0 && triggerToggle == false) {
        triggerToggle = true;
        cout << "Triggerbot on" << endl;
        Sleep(50);
    }
    else if (GetKeyState('V') < 0 && triggerToggle == true) {
        triggerToggle = false;
        cout << "Triggerbot off" << endl;
        Sleep(50);
    }
    else if (GetKeyState('X') < 0 && whToggle == false) {
        whToggle = true;
        cout << "Wallhack on" << endl;
        Sleep(50);
    }
    else if (GetKeyState('X') < 0 && whToggle == true) {
        whToggle = false;
        cout << "Wallhack off" << endl;
        Sleep(50);
    }
    else if (GetKeyState('N') < 0 && bhobToggle == false) {
        bhobToggle = true;
        cout << "Bhop on" << endl;
        Sleep(50);
    }
    else if (GetKeyState('N') < 0 && bhobToggle == true) {
        bhobToggle = false;
        cout << "Bhop off" << endl;
        Sleep(50);
    }
    else if (GetKeyState('L') < 0 && rsToggle == false) {
        rsToggle = true;
        cout << "Random skinchanger on" << endl;
        Sleep(50);
    }
    else if (GetKeyState('L') < 0 && rsToggle == true) {
        rsToggle = false;
        cout << "Random skinchanger off" << endl;
        Sleep(50);
    }
    else if (GetKeyState('C') < 0 && aimbotToggle == false) {
        aimbotToggle = true;
        cout << "Aimbot on" << endl;
        Sleep(50);
    }
    else if (GetKeyState('C') < 0 && aimbotToggle == true) {
        aimbotToggle = false;
        cout << "Aimbot off" << endl;
        Sleep(50);
    }
}


void NoDelayFeatures() {
    cout << "--> Triggerbot ready      (Toggle it with V)" << endl;
    cout << "--> Autoaim ready         (Toggle it with C)" << endl;
    cout << "--> Bhop ready            (Toggle it with N)" << endl;

    Aimbot aimbot;
    while (true) {
        
        if (triggerToggle) {
            trigger.Run();
        }
        if (bhobToggle) {
            bhop.Run();
        }
        if (aimbotToggle) {
            aimbot.Run();
        }
    }
}

void DelayFeatures() {
    Sleep(10);
    cout << "--> Wallhack ready        (Toggle it with X)" << endl;
    
 
    while (true) {
        if (whToggle) {
            wh.Run();
        }
        if (rsToggle) {
            weaponSkins.RandomSkinChanger();
        }
        else {
            weaponSkins.StandartSkinLayout();
        }
        Sleep(1);
    }
}


void SkinChangerThread() {
    Sleep(30);
    cout << "--> Skinchanger activated (Toggle Randomness with L)" << endl;
    cout << "" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "\n\n\n                      Toggle Log" << endl;
    cout << "----------------------------------------------------\n" << endl;
    cout << "Triggerbot off\nWallhack off\nAutoaim off\nBhop off" << endl;
    
    while (true) {
        skinChanger.Run();
    }
}

void KnifeChangerThread() {
    KnifeChanger knifeChanger;
    while (true) {
        knifeChanger.Run();
    }
}

int main()
{
    SetConsoleTitle(L"CS:GO Moerper");
    
    // Sets window size
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 450, 700, TRUE);

    cout << "\n                     The Moerper" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "waiting for CS:GO..." << endl;

    Init();

    cout << "" << endl;
    cout << "Starting Features..." << endl;
    
    // Starts threads
    thread NoDelayThread(NoDelayFeatures);
    thread DelayThread(DelayFeatures);
    thread SkinChangerThread(SkinChangerThread);
    thread KnifeChangerThread(KnifeChangerThread);

    Sleep(20);
    while (true) {
        toggleFeatures();
        Sleep(50);
    }
}
