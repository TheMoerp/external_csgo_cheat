#include "mainwindow.h"
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
#include "offsets.h"

#include <QApplication>
#include <QStyleFactory>


// Initiates the memory process
void Init() {
    std::cout << "Initiating engine..." << std::endl;
    mem.Setup();
    mem.GetModules();
    offsets.OffsetUpdate();
    config.LoadConfigs();
}


// Fast features
void NoDelayFeatures() {
    while (true) {
        if (config.triggerToggle) {
            Triggerbot();
        }
        if (config.bhopToggle) {
            Bhop();
        }
        if (config.aimbotToggle) {
            Aimbot();
        }
    }
}


// Not so fast features
void DelayFeatures() {
    Sleep(10);
    while (true) {
        if (config.wallhackToggle) {
            Wallhack();
        }
        if (config.radarToggle) {
            Radar();
        }
        if (config.antiflashToggle) {
            antiflash();
        }
        Sleep(1);
    }
}


int main(int argc, char *argv[])
{
    Init();
    // Starts threads
    std::thread DelayThread(DelayFeatures);
    std::thread NoDelayThread(NoDelayFeatures);

    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));
    MainWindow w;
    w.show();
    return a.exec();

    
}
