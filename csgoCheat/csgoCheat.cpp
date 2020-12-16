#include <iostream>
#include <thread>

#include "Memory.h"
#include "Bhop.h"
#include "Trigger.h"
#include "Wallhack.h"
#include "SkinChanger.h"
#include "WeaponSkins.h"

using namespace std;

bool triggerToggle = false; // triggerbot off/on

// initializes the Cheat
void Init() {
    cout << "Initiating engine" << endl;
    mem.Setup();
    mem.GetModules();
    weaponSkins.ChangeSkinLayout();
}


void toggleFeatures() {
    if (GetKeyState('V') < 0 && triggerToggle == false) {
        triggerToggle = true;
        cout << "Triggerbot turned on." << endl;
    }
    else if (GetKeyState('V') < 0 && triggerToggle == true) {
        triggerToggle = false;
        cout << "Triggerbot turned off." << endl;
    }
}


void NoDelayFeatures() {
    cout << "--> Triggerbot activated (Toggle it with V)" << endl;
    cout << "--> Bhop activated" << endl;
    while (true) {
        if (triggerToggle) {
            trigger.Run();
        }
        
        bhop.Run();
    }
}

void DelayFeatures() {
    Sleep(10);
    cout << "--> Wallhack activated" << endl;
    
    while (true) {
        wh.Run();
        weaponSkins.RandomSkinChanger();
        Sleep(1);
    }
}


void SkinChangerThread() {
    Sleep(20);
    cout << "--> Random skinchanger activated" << endl;
    cout << "" << endl;
    cout << "<------------------------------------>" << endl;
    cout << "" << endl;

    while (true) {
        skinChanger.Run();
        Sleep(1);
    }
}


int main()
{

    SetConsoleTitle(L"CS:GO Moerper");
    cout << "         CS:GO Moerper - LOG" << endl;
    cout << "<------------------------------------>" << endl;
    cout << "waiting for CS:GO..." << endl;

    Init();

    cout << "" << endl;
    cout << "Starting Features..." << endl;
    thread NoDelayThread(NoDelayFeatures);
    thread DelayThread(DelayFeatures);
    thread SkinChangerThread(SkinChangerThread);


    Sleep(20);
    while (true) {
        toggleFeatures();
        Sleep(100);
    }
}
