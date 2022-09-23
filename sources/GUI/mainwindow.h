#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCheckBox>
#include <QMainWindow>
#include "changeskinlayout.h"
#include "changehotkeys.h"
#include <QPushButton>


class QPushButton;
class QCheckBox;
class QRadioButton;
class ChangeHotkeys;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Skinchanger settings
    int skinDesartEagle, skinDualBerettas, skinFiveSeven, skinGlock18, skinTec9, skinP2000, skinP250, skinUSPS, skinCZ75, skinRevolver,
        skinAK47, skinAUG, skinAWP, skinFAMAS, skinG35G1, skinGalilAR, skinM4A4, skinSCAR20, skinSG553, skinSSG08, skinM4A1S,
        skinMAC10, skinP90, skinMP5SD, skinUMP45, skinPPBizon, skinMP7, skinMP9,
        skinMAG7, skinSawedOff, skinNova, skinXM1014, skinNegev, skinM249, skinKnife;
    int modelKnife;

    // Hotkey settings
    int wallhackKey, radarKey, aimbotKey, triggerKey, skinchangerKey, knifechangerKey, bhopKey, noflashKey;

private slots:
    void CheckboxChanged();
    void CheckboxStatus();
    void ChangeHotkeys();
    void Resetproccess();
    void Quit();
    void ChangeSkinlayout();

    void SkinlayoutChanged();

private:
    Ui::MainWindow *ui;

    ChangeSkinLayout *changeSkinLayout;
    class ChangeHotkeys *changeHotkeys;

    QCheckBox *checkWallhack, *checkRadar, *checkAimbot, *checkTrigger,
              *checkSkinchanger, *checkKnifechanger, *checkBhop, *checkNoflash;
    QRadioButton *radioRed, *radioGreen, *radioBlue;
    QPushButton *pushChangeSkin, *pushChangeKeys, *pushReset, *pushQuit;
};
#endif // MAINWINDOW_H
