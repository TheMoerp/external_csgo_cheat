#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "changeskinlayout.h"
#include "changehotkeys.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("The Moerper external");

    changeSkinLayout = new ChangeSkinLayout(this);
    changeHotkeys = new class ChangeHotkeys(this);

    // Get Objects
    checkWallhack = ui->checkWallhack;
    checkRadar = ui->checkRadar;
    checkAimbot = ui->checkAimbot;
    checkTrigger = ui->checkTrigger;
    checkSkinchanger = ui->checkSkinchanger;
    checkKnifechanger = ui->checkKnifechnager;
    checkBhop = ui->checkBhop;
    checkNoflash = ui->checkNoflash;

    radioRed = ui->radioRed;
    radioGreen = ui->radioGreen;
    radioBlue = ui->radioBlue;

    pushChangeSkin = ui->pushChangeSkin;
    pushChangeKeys = ui->pushChangeKeys;
    pushReset = ui->pushReset;
    pushQuit = ui->pushQuit;

    // Connections
    connect(checkWallhack, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));
    connect(checkRadar, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));
    connect(checkAimbot, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));
    connect(checkTrigger, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));
    connect(checkSkinchanger, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));
    connect(checkKnifechanger, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));
    connect(checkBhop, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));
    connect(checkNoflash, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));

    connect(radioRed, SIGNAL(clicked(bool)), this, SLOT(CheckboxChanged()));
    connect(radioGreen, SIGNAL(clicked(bool)), this, SLOT(CheckboxChanged()));
    connect(radioBlue, SIGNAL(clicked(bool)), this, SLOT(CheckboxChanged()));

    connect(pushChangeSkin, SIGNAL(clicked()), this, SLOT(ChangeSkinlayout()));
    connect(pushChangeKeys, SIGNAL(clicked()), this, SLOT(ChangeHotkeys()));
    connect(pushReset, SIGNAL(clicked()), this, SLOT(Resetproccess()));
    connect(pushQuit, SIGNAL(clicked()), this, SLOT(Quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::CheckboxChanged() {
   wallhackToggle = checkWallhack->isChecked();
   radarToggle = checkWallhack->isChecked();
   aimbotToggle = checkWallhack->isChecked();
   triggerToggle = checkWallhack->isChecked();
   skinchangerToggle = checkWallhack->isChecked();
   knifechangerToggle = checkWallhack->isChecked();
   bhopToggle = checkWallhack->isChecked();
   noflashToggle = checkWallhack->isChecked();

   bool whRedToggle = radioRed->isChecked();
   bool whGreenToggle = radioGreen->isChecked();
   bool whBlueToggle = radioBlue->isChecked();

   if (whRedToggle) {
       whRed = 2.0;
       whGreen = 0.0;
       whBlue = 0.0;
   }
   else if (whGreenToggle) {
       whRed = 0.0;
       whGreen = 2.0;
       whBlue = 0.0;
   }
   else if (whBlueToggle) {
       whRed = 0.0;
       whGreen = 0.0;
       whBlue = 2.0;
   }
}


void MainWindow::CheckboxStatus() {

}


void MainWindow::ChangeSkinlayout() {
   changeSkinLayout->show();
   changeSkinLayout->activateWindow();
}

void MainWindow::ChangeHotkeys() {
    changeHotkeys->show();
    changeHotkeys->activateWindow();
}

void MainWindow::Resetproccess() {

}

void MainWindow::Quit() {

}
