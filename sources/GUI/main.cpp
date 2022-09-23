#include "mainwindow.h"
#include <iostream>
#include <thread>
#include <windows.h>


#include "memory.h"
#include "wallhack.h"
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


void DelayFeatures() {
    Sleep(10);
    std::cout << "--> Wallhack ready                 (Toggle it with NUM_0)" << std::endl;

    while (true) {
        if (config.wallhackToggle) {
            Wallhack();
        }
    }
}


int main(int argc, char *argv[])
{
    Init();
    // Starts threads
    std::thread DelayThread(DelayFeatures);

    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));
    MainWindow w;
    w.show();
    return a.exec();

    
}
