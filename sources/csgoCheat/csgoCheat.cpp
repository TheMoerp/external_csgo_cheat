#include <iostream>
#include <thread>
#include <windows.h>

#include "Memory.h"
#include "Bhop.h"
#include "Trigger.h"
#include "Wallhack.h"
#include "SkinChanger.h"
#include "WeaponSkins.h"

using namespace std;

bool triggerToggle = false; // triggerbot off/on
bool whToggle = false;
bool bhobToggle = false;

// initializes the Cheat
void Init() {
    cout << "Initiating engine..." << endl;
    mem.Setup();
    mem.GetModules();
    weaponSkins.ChangeSkinLayout();
}


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
    else if (GetKeyState('C') < 0 && bhobToggle == false) {
        bhobToggle = true;
        cout << "Bhop on" << endl;
        Sleep(50);
    }
    else if (GetKeyState('C') < 0 && bhobToggle == true) {
        bhobToggle = false;
        cout << "Bhop off" << endl;
        Sleep(50);
    }
}


void NoDelayFeatures() {
    cout << "--> Triggerbot ready (Toggle it with V)" << endl;
    cout << "--> Bhop ready       (Toggle it with C)" << endl;
    while (true) {
        if (triggerToggle) {
            trigger.Run();
        }
        if (bhobToggle) {
            bhop.Run();
        }
    }
}

void DelayFeatures() {
    Sleep(10);
    cout << "--> Wallhack ready   (Toggle it with X)" << endl;
    
    while (true) {
        if (whToggle) {
            wh.Run();
        }
        weaponSkins.RandomSkinChanger();
        Sleep(1);
    }
}


void SkinChangerThread() {
    Sleep(30);
    cout << "--> Random skinchanger activated" << endl;
    cout << "" << endl;
    cout << "<-------------------------------------->" << endl;
    cout << "\n\n" << endl;
    cout << "<---- Toggle Log ---->\n" << endl;
    cout << "Triggerbot off\nWallhack off\nBhob off" << endl;

    while (true) {
        skinChanger.Run();
        Sleep(1);
    }
}


int main()
{

    SetConsoleTitle(L"CS:GO Moerper");
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 400, 700, TRUE);

    cout << "             CS:GO Moerper" << endl;
    cout << "<-------------------------------------->" << endl;
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
