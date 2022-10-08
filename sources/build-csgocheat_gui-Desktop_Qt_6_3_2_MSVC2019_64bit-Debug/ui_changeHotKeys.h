/********************************************************************************
** Form generated from reading UI file 'changeHotKeys.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEHOTKEYS_H
#define UI_CHANGEHOTKEYS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ChangeHotkeys
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QFrame *line;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QKeySequenceEdit *keyWallhack;
    QKeySequenceEdit *keyRadar;
    QKeySequenceEdit *keyAimbot;
    QKeySequenceEdit *keyTrigger;
    QKeySequenceEdit *keySkinchanger;
    QKeySequenceEdit *keyKnifechanger;
    QKeySequenceEdit *keyBhop;
    QKeySequenceEdit *keyNoflash;
    QFrame *line_2;

    void setupUi(QDialog *ChangeHotkeys)
    {
        if (ChangeHotkeys->objectName().isEmpty())
            ChangeHotkeys->setObjectName(QString::fromUtf8("ChangeHotkeys"));
        ChangeHotkeys->resize(229, 396);
        ChangeHotkeys->setMinimumSize(QSize(229, 396));
        ChangeHotkeys->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);\n"
"color: rgb(255, 255, 255);\n"
"QCheckBox:rgb(255, 255, 255);"));
        buttonBox = new QDialogButtonBox(ChangeHotkeys);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 330, 181, 32));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        buttonBox->setFont(font);
        buttonBox->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);
        label = new QLabel(ChangeHotkeys);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 181, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setItalic(false);
        label->setFont(font1);
        line = new QFrame(ChangeHotkeys);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-10, 50, 421, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(ChangeHotkeys);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 71, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        font2.setBold(true);
        label_3->setFont(font2);
        label_4 = new QLabel(ChangeHotkeys);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 71, 16));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        font3.setBold(true);
        font3.setItalic(false);
        label_4->setFont(font3);
        label_5 = new QLabel(ChangeHotkeys);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 130, 71, 16));
        label_5->setFont(font2);
        label_6 = new QLabel(ChangeHotkeys);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 160, 71, 16));
        label_6->setFont(font2);
        label_7 = new QLabel(ChangeHotkeys);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 190, 71, 16));
        label_7->setFont(font2);
        label_8 = new QLabel(ChangeHotkeys);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 220, 71, 16));
        label_8->setFont(font2);
        label_9 = new QLabel(ChangeHotkeys);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 250, 71, 16));
        label_9->setFont(font2);
        label_10 = new QLabel(ChangeHotkeys);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 280, 71, 16));
        label_10->setFont(font2);
        keyWallhack = new QKeySequenceEdit(ChangeHotkeys);
        keyWallhack->setObjectName(QString::fromUtf8("keyWallhack"));
        keyWallhack->setGeometry(QRect(100, 70, 113, 22));
        keyWallhack->setFont(font);
        keyWallhack->setCursor(QCursor(Qt::PointingHandCursor));
        keyRadar = new QKeySequenceEdit(ChangeHotkeys);
        keyRadar->setObjectName(QString::fromUtf8("keyRadar"));
        keyRadar->setGeometry(QRect(100, 100, 113, 22));
        keyRadar->setFont(font);
        keyRadar->setCursor(QCursor(Qt::PointingHandCursor));
        keyAimbot = new QKeySequenceEdit(ChangeHotkeys);
        keyAimbot->setObjectName(QString::fromUtf8("keyAimbot"));
        keyAimbot->setGeometry(QRect(100, 130, 113, 22));
        keyAimbot->setFont(font);
        keyAimbot->setCursor(QCursor(Qt::PointingHandCursor));
        keyTrigger = new QKeySequenceEdit(ChangeHotkeys);
        keyTrigger->setObjectName(QString::fromUtf8("keyTrigger"));
        keyTrigger->setGeometry(QRect(100, 160, 113, 22));
        keyTrigger->setFont(font);
        keyTrigger->setCursor(QCursor(Qt::PointingHandCursor));
        keySkinchanger = new QKeySequenceEdit(ChangeHotkeys);
        keySkinchanger->setObjectName(QString::fromUtf8("keySkinchanger"));
        keySkinchanger->setGeometry(QRect(100, 190, 113, 22));
        keySkinchanger->setFont(font);
        keySkinchanger->setCursor(QCursor(Qt::PointingHandCursor));
        keyKnifechanger = new QKeySequenceEdit(ChangeHotkeys);
        keyKnifechanger->setObjectName(QString::fromUtf8("keyKnifechanger"));
        keyKnifechanger->setGeometry(QRect(100, 220, 113, 22));
        keyKnifechanger->setFont(font);
        keyKnifechanger->setCursor(QCursor(Qt::PointingHandCursor));
        keyBhop = new QKeySequenceEdit(ChangeHotkeys);
        keyBhop->setObjectName(QString::fromUtf8("keyBhop"));
        keyBhop->setGeometry(QRect(100, 250, 113, 22));
        keyBhop->setFont(font);
        keyBhop->setCursor(QCursor(Qt::PointingHandCursor));
        keyNoflash = new QKeySequenceEdit(ChangeHotkeys);
        keyNoflash->setObjectName(QString::fromUtf8("keyNoflash"));
        keyNoflash->setGeometry(QRect(100, 280, 113, 22));
        keyNoflash->setFont(font);
        keyNoflash->setCursor(QCursor(Qt::PointingHandCursor));
        line_2 = new QFrame(ChangeHotkeys);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(-80, 310, 421, 16));
        line_2->setMaximumSize(QSize(421, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        retranslateUi(ChangeHotkeys);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ChangeHotkeys, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ChangeHotkeys, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ChangeHotkeys);
    } // setupUi

    void retranslateUi(QDialog *ChangeHotkeys)
    {
        ChangeHotkeys->setWindowTitle(QCoreApplication::translate("ChangeHotkeys", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ChangeHotkeys", "Hotkeys", nullptr));
        label_3->setText(QCoreApplication::translate("ChangeHotkeys", "wallhack", nullptr));
        label_4->setText(QCoreApplication::translate("ChangeHotkeys", "radar", nullptr));
        label_5->setText(QCoreApplication::translate("ChangeHotkeys", "aimbot", nullptr));
        label_6->setText(QCoreApplication::translate("ChangeHotkeys", "triggerbot", nullptr));
        label_7->setText(QCoreApplication::translate("ChangeHotkeys", "skinchanger", nullptr));
        label_8->setText(QCoreApplication::translate("ChangeHotkeys", "knifechanger", nullptr));
        label_9->setText(QCoreApplication::translate("ChangeHotkeys", "bhop", nullptr));
        label_10->setText(QCoreApplication::translate("ChangeHotkeys", "noflash", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeHotkeys: public Ui_ChangeHotkeys {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEHOTKEYS_H
