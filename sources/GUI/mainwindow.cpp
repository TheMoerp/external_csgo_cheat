#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("The Moerper external");

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

}


void MainWindow::ChangeSkinlayout() {

}

void MainWindow::ChangeHotkeys() {

}

void MainWindow::Resetproccess() {

}

void MainWindow::Quit() {

}

