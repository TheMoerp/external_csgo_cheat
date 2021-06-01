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

    changeSkinLayout->LoadSkinConfig();

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

    connect(checkWallhack, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));
    connect(checkRadar, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));
    connect(checkAimbot, SIGNAL(stateChanged(int)), this, SLOT(CheckboxChanged()));
    connect(pushChangeKeys, SIGNAL(clicked()), this, SLOT(ChangeHotkeys()));
    connect(pushReset, SIGNAL(clicked()), this, SLOT(Resetproccess()));
    connect(pushQuit, SIGNAL(clicked()), this, SLOT(Quit()));
    connect(pushChangeSkin, SIGNAL(clicked()), this, SLOT(ChangeSkinlayout()));

    connect(changeSkinLayout->pushConfirm, SIGNAL(accepted()), this, SLOT(SkinlayoutChanged()));
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

    skinDesartEagle = changeSkinLayout->lineDesartEagle->text().toInt();
    skinDualBerettas = changeSkinLayout->lineDualBerettas->text().toInt();
    skinFiveSeven = changeSkinLayout->lineFiveSeven->text().toInt();
    skinGlock18 = changeSkinLayout->lineGlock18->text().toInt();
    skinTec9 = changeSkinLayout->lineTec9->text().toInt();
    skinP2000 = changeSkinLayout->lineP2000->text().toInt();
    skinP250 = changeSkinLayout->lineP250->text().toInt();
    skinUSPS = changeSkinLayout->lineUSPS->text().toInt();
    skinCZ75 = changeSkinLayout->lineCZ75->text().toInt();
    skinRevolver = changeSkinLayout->lineRevolver->text().toInt();
    skinAK47 = changeSkinLayout->lineAK47->text().toInt();
    skinAUG = changeSkinLayout->lineAUG->text().toInt();
    skinAWP = changeSkinLayout->lineAWP->text().toInt();
    skinFAMAS = changeSkinLayout->lineFAMAS->text().toInt();
    skinG35G1 = changeSkinLayout->lineG35G1->text().toInt();
    skinGalilAR = changeSkinLayout->lineGalilAR->text().toInt();
    skinM4A4 = changeSkinLayout->lineM4A4->text().toInt();
    skinSCAR20 = changeSkinLayout->lineSCAR20->text().toInt();
    skinSG553 = changeSkinLayout->lineSG553->text().toInt();
    skinSSG08 = changeSkinLayout->lineSSG08->text().toInt();
    skinM4A1S = changeSkinLayout->lineM4A1S->text().toInt();
    skinMAC10 = changeSkinLayout->lineMAC10->text().toInt();
    skinP90 = changeSkinLayout->lineP90->text().toInt();
    skinMP5SD = changeSkinLayout->lineMP5SD->text().toInt();
    skinUMP45 = changeSkinLayout->lineUMP45->text().toInt();
    skinPPBizon = changeSkinLayout->linePPBizon->text().toInt();
    skinMP7 = changeSkinLayout->lineMP7->text().toInt();
    skinMP9 = changeSkinLayout->lineMP9->text().toInt();
    skinMAG7 = changeSkinLayout->lineMAG7->text().toInt();
    skinSawedOff = changeSkinLayout->lineSawedOff->text().toInt();
    skinNova = changeSkinLayout->lineNova->text().toInt();
    skinXM1014 = changeSkinLayout->lineXM1014->text().toInt();
    skinNegev = changeSkinLayout->lineNegev->text().toInt();
    skinM249 = changeSkinLayout->lineM249->text().toInt();
    skinKnife = changeSkinLayout->lineKnife->text().toInt();

    QString knifeModel = changeSkinLayout->comboKnife->currentText();
    if (knifeModel == "Bayonet") {
        modelKnife = 0;
    }
    else if (knifeModel == "M9 Bayonet") {
        modelKnife = 5;
    }
    else if (knifeModel == "Karambit") {
        modelKnife = 4;
    }
    else if (knifeModel == "Flip knife") {
        modelKnife = 2;
    }
}
