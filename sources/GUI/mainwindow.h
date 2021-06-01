#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "changeskinlayout.h"
#include <QCheckBox>

class QPushButton;
class QCheckBox;
class QRadioButton;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void CheckboxChanged();
    void CheckboxStatus();
    void ChangeHotkeys();
    void Resetproccess();
    void Quit();
    void ChangeSkinlayout();

private:
    Ui::MainWindow *ui;

    ChangeSkinLayout *changeSkinLayout;

    QCheckBox *checkWallhack, *checkRadar, *checkAimbot, *checkTrigger,
              *checkSkinchanger, *checkKnifechanger, *checkBhop, *checkNoflash;
    QRadioButton *radioRed, *radioGreen, *radioBlue;
    QPushButton *pushChangeSkin, *pushChangeKeys, *pushReset, *pushQuit;
};
#endif // MAINWINDOW_H