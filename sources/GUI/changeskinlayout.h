#ifndef CHANGESKINLAYOUT_H
#define CHANGESKINLAYOUT_H

#include <QDialog>
#include "ui_changeskinlayout.h"

class ChangeSkinLayout : public QDialog {
    Q_OBJECT

public:
    ChangeSkinLayout(QWidget *parent = nullptr);

private:
    Ui::ChangeSkinLayout ui;
};

#endif // CHANGESKINLAYOUT_H
