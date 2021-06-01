#ifndef CHANGESKINLAYOUT_H
#define CHANGESKINLAYOUT_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>
#include <fstream>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include "ui_changeskinlayout.h"

class QLineEdit;
class QComboBox;
class QDialogButtonBox;

class ChangeSkinLayout : public QDialog {
    Q_OBJECT

public:
    ChangeSkinLayout(QWidget *parent = nullptr);

    QLineEdit *lineAK47, *lineAUG, *lineAWP, *lineCZ75, *lineDesartEagle, *lineDualBerettas, *lineFAMAS, *lineFiveSeven,
              *lineG35G1, *lineGalilAR, *lineGlock18, *lineKnifeSkin, *lineM249, *lineM4A1S, *lineM4A4, *lineMAC10, *lineMAG7,
              *lineMP5SD, *lineMP7, *lineMP9, *lineNegev, *lineNova, *lineP2000, *lineP250, *lineP90, *linePPBizon, *lineRevolver,
              *lineSCAR20, *lineSG553, *lineSSG08, *lineSawedOff, *lineTec9, *lineUMP45, *lineUSPS, *lineXM1014, *lineKnife;
    QComboBox *comboKnife;
    QDialogButtonBox *pushConfirm;

    void LoadSkinConfig();

private:
    Ui::ChangeSkinLayout ui;

    void SaveSkinLayout();
};

#endif // CHANGESKINLAYOUT_H
