/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labVisuals;
    QCheckBox *checkRadar;
    QLabel *labMain;
    QFrame *lineH1;
    QFrame *lineV1;
    QLabel *labShooting;
    QCheckBox *checkAimbot;
    QFrame *lineV2;
    QLabel *labMisc;
    QLabel *labSkinchanger;
    QCheckBox *checkSkinchanger;
    QCheckBox *checkKnifechnager;
    QFrame *lineV3;
    QCheckBox *checkBhop;
    QCheckBox *checkNoflash;
    QFrame *lineH2;
    QPushButton *pushChangeSkin;
    QPushButton *pushChangeKeys;
    QCheckBox *checkWallhack;
    QCheckBox *checkTrigger;
    QRadioButton *radioRed;
    QRadioButton *radioGreen;
    QRadioButton *radioBlue;
    QPushButton *pushQuit;
    QPushButton *pushReset;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(471, 308);
        MainWindow->setMinimumSize(QSize(471, 308));
        MainWindow->setMaximumSize(QSize(471, 308));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);\n"
"color: rgb(255, 255, 255);\n"
"QCheckBox:rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labVisuals = new QLabel(centralwidget);
        labVisuals->setObjectName(QString::fromUtf8("labVisuals"));
        labVisuals->setGeometry(QRect(20, 80, 71, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        font.setPointSize(15);
        font.setBold(false);
        font.setKerning(true);
        labVisuals->setFont(font);
        checkRadar = new QCheckBox(centralwidget);
        checkRadar->setObjectName(QString::fromUtf8("checkRadar"));
        checkRadar->setGeometry(QRect(20, 200, 72, 19));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        checkRadar->setFont(font1);
        checkRadar->setCursor(QCursor(Qt::PointingHandCursor));
        labMain = new QLabel(centralwidget);
        labMain->setObjectName(QString::fromUtf8("labMain"));
        labMain->setGeometry(QRect(80, 20, 311, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        font2.setPointSize(22);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        labMain->setFont(font2);
        labMain->setStyleSheet(QString::fromUtf8("\n"
"border-color: rgb(255, 255, 255);"));
        lineH1 = new QFrame(centralwidget);
        lineH1->setObjectName(QString::fromUtf8("lineH1"));
        lineH1->setGeometry(QRect(-10, 60, 541, 16));
        lineH1->setFrameShape(QFrame::HLine);
        lineH1->setFrameShadow(QFrame::Sunken);
        lineV1 = new QFrame(centralwidget);
        lineV1->setObjectName(QString::fromUtf8("lineV1"));
        lineV1->setGeometry(QRect(103, 80, 20, 131));
        lineV1->setFrameShape(QFrame::VLine);
        lineV1->setFrameShadow(QFrame::Sunken);
        labShooting = new QLabel(centralwidget);
        labShooting->setObjectName(QString::fromUtf8("labShooting"));
        labShooting->setGeometry(QRect(130, 70, 81, 41));
        labShooting->setFont(font);
        checkAimbot = new QCheckBox(centralwidget);
        checkAimbot->setObjectName(QString::fromUtf8("checkAimbot"));
        checkAimbot->setGeometry(QRect(130, 110, 72, 19));
        checkAimbot->setFont(font1);
        checkAimbot->setCursor(QCursor(Qt::PointingHandCursor));
        lineV2 = new QFrame(centralwidget);
        lineV2->setObjectName(QString::fromUtf8("lineV2"));
        lineV2->setGeometry(QRect(220, 80, 20, 131));
        lineV2->setFrameShape(QFrame::VLine);
        lineV2->setFrameShadow(QFrame::Sunken);
        labMisc = new QLabel(centralwidget);
        labMisc->setObjectName(QString::fromUtf8("labMisc"));
        labMisc->setGeometry(QRect(400, 80, 71, 16));
        labMisc->setFont(font);
        labSkinchanger = new QLabel(centralwidget);
        labSkinchanger->setObjectName(QString::fromUtf8("labSkinchanger"));
        labSkinchanger->setGeometry(QRect(250, 70, 111, 41));
        labSkinchanger->setFont(font);
        checkSkinchanger = new QCheckBox(centralwidget);
        checkSkinchanger->setObjectName(QString::fromUtf8("checkSkinchanger"));
        checkSkinchanger->setGeometry(QRect(250, 110, 91, 19));
        checkSkinchanger->setFont(font1);
        checkSkinchanger->setCursor(QCursor(Qt::PointingHandCursor));
        checkKnifechnager = new QCheckBox(centralwidget);
        checkKnifechnager->setObjectName(QString::fromUtf8("checkKnifechnager"));
        checkKnifechnager->setGeometry(QRect(250, 140, 91, 19));
        checkKnifechnager->setFont(font1);
        checkKnifechnager->setCursor(QCursor(Qt::PointingHandCursor));
        checkKnifechnager->setTabletTracking(false);
        checkKnifechnager->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"gridline-color: rgb(255, 255, 255);"));
        lineV3 = new QFrame(centralwidget);
        lineV3->setObjectName(QString::fromUtf8("lineV3"));
        lineV3->setGeometry(QRect(370, 80, 20, 131));
        lineV3->setFrameShape(QFrame::VLine);
        lineV3->setFrameShadow(QFrame::Sunken);
        checkBhop = new QCheckBox(centralwidget);
        checkBhop->setObjectName(QString::fromUtf8("checkBhop"));
        checkBhop->setGeometry(QRect(400, 110, 72, 19));
        checkBhop->setFont(font1);
        checkBhop->setCursor(QCursor(Qt::PointingHandCursor));
        checkNoflash = new QCheckBox(centralwidget);
        checkNoflash->setObjectName(QString::fromUtf8("checkNoflash"));
        checkNoflash->setGeometry(QRect(400, 140, 72, 19));
        checkNoflash->setFont(font1);
        checkNoflash->setCursor(QCursor(Qt::PointingHandCursor));
        lineH2 = new QFrame(centralwidget);
        lineH2->setObjectName(QString::fromUtf8("lineH2"));
        lineH2->setGeometry(QRect(-10, 220, 551, 16));
        lineH2->setFrameShape(QFrame::HLine);
        lineH2->setFrameShadow(QFrame::Sunken);
        pushChangeSkin = new QPushButton(centralwidget);
        pushChangeSkin->setObjectName(QString::fromUtf8("pushChangeSkin"));
        pushChangeSkin->setGeometry(QRect(250, 180, 111, 21));
        pushChangeSkin->setFont(font1);
        pushChangeSkin->setCursor(QCursor(Qt::PointingHandCursor));
        pushChangeKeys = new QPushButton(centralwidget);
        pushChangeKeys->setObjectName(QString::fromUtf8("pushChangeKeys"));
        pushChangeKeys->setGeometry(QRect(10, 240, 91, 21));
        pushChangeKeys->setFont(font1);
        pushChangeKeys->setCursor(QCursor(Qt::PointingHandCursor));
        checkWallhack = new QCheckBox(centralwidget);
        checkWallhack->setObjectName(QString::fromUtf8("checkWallhack"));
        checkWallhack->setGeometry(QRect(20, 110, 72, 19));
        checkWallhack->setFont(font1);
        checkWallhack->setCursor(QCursor(Qt::PointingHandCursor));
        checkTrigger = new QCheckBox(centralwidget);
        checkTrigger->setObjectName(QString::fromUtf8("checkTrigger"));
        checkTrigger->setGeometry(QRect(130, 140, 72, 19));
        checkTrigger->setFont(font1);
        checkTrigger->setCursor(QCursor(Qt::PointingHandCursor));
        radioRed = new QRadioButton(centralwidget);
        radioRed->setObjectName(QString::fromUtf8("radioRed"));
        radioRed->setGeometry(QRect(30, 130, 61, 19));
        radioRed->setFont(font1);
        radioRed->setCursor(QCursor(Qt::PointingHandCursor));
        radioGreen = new QRadioButton(centralwidget);
        radioGreen->setObjectName(QString::fromUtf8("radioGreen"));
        radioGreen->setGeometry(QRect(30, 150, 61, 19));
        radioGreen->setFont(font1);
        radioGreen->setCursor(QCursor(Qt::PointingHandCursor));
        radioBlue = new QRadioButton(centralwidget);
        radioBlue->setObjectName(QString::fromUtf8("radioBlue"));
        radioBlue->setGeometry(QRect(30, 170, 61, 21));
        radioBlue->setFont(font1);
        radioBlue->setCursor(QCursor(Qt::PointingHandCursor));
        pushQuit = new QPushButton(centralwidget);
        pushQuit->setObjectName(QString::fromUtf8("pushQuit"));
        pushQuit->setGeometry(QRect(410, 240, 51, 21));
        pushQuit->setFont(font1);
        pushQuit->setCursor(QCursor(Qt::PointingHandCursor));
        pushReset = new QPushButton(centralwidget);
        pushReset->setObjectName(QString::fromUtf8("pushReset"));
        pushReset->setGeometry(QRect(300, 240, 91, 21));
        pushReset->setFont(font1);
        pushReset->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 471, 20));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labVisuals->setText(QCoreApplication::translate("MainWindow", "Visuals", nullptr));
        checkRadar->setText(QCoreApplication::translate("MainWindow", "radar", nullptr));
        labMain->setText(QCoreApplication::translate("MainWindow", "The Moerper external", nullptr));
        labShooting->setText(QCoreApplication::translate("MainWindow", "Shooting", nullptr));
        checkAimbot->setText(QCoreApplication::translate("MainWindow", "aimbot", nullptr));
        labMisc->setText(QCoreApplication::translate("MainWindow", "Misc", nullptr));
        labSkinchanger->setText(QCoreApplication::translate("MainWindow", "Skinchanger", nullptr));
        checkSkinchanger->setText(QCoreApplication::translate("MainWindow", "skinchanger", nullptr));
        checkKnifechnager->setText(QCoreApplication::translate("MainWindow", "knifechanger", nullptr));
        checkBhop->setText(QCoreApplication::translate("MainWindow", "bhop", nullptr));
        checkNoflash->setText(QCoreApplication::translate("MainWindow", "noflash", nullptr));
        pushChangeSkin->setText(QCoreApplication::translate("MainWindow", "change skinlayout", nullptr));
        pushChangeKeys->setText(QCoreApplication::translate("MainWindow", "change hotkeys", nullptr));
        checkWallhack->setText(QCoreApplication::translate("MainWindow", "wallhack", nullptr));
        checkTrigger->setText(QCoreApplication::translate("MainWindow", "triggerbot", nullptr));
        radioRed->setText(QCoreApplication::translate("MainWindow", "red", nullptr));
        radioGreen->setText(QCoreApplication::translate("MainWindow", "green", nullptr));
        radioBlue->setText(QCoreApplication::translate("MainWindow", "blue", nullptr));
        pushQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        pushReset->setText(QCoreApplication::translate("MainWindow", "Reset proccess", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
