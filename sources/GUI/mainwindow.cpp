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

    // mainwindow connections
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

    // changeSkinLayout connections
    connect(changeSkinLayout->lineAK47, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineAUG, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineAWP, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineCZ75, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineDesartEagle, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineDualBerettas, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineFAMAS, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineFiveSeven, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineG35G1, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineGalilAR, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineGlock18, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineKnifeSkin, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineM249, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineM4A1S, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineM4A4, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineMAC10, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineMAG7, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineMP5SD, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineMP7, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineMP9, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineNegev, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineNova, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineP2000, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineP250, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineP90, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->linePPBizon, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineRevolver, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineSCAR20, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineSG553, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineSSG08, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineSawedOff, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineTec9, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineUMP45, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineUSPS, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
    connect(changeSkinLayout->lineXM1014, SIGNAL(editingFinished()), this, SLOT(SkinlayoutChanged()));
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


void MainWindow::SkinlayoutChanged() {

}
