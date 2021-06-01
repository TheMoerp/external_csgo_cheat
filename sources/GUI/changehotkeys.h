#ifndef CHANGEHOTKEYS_H
#define CHANGEHOTKEYS_H

#include <QDialog>
#include "ui_changeHotkeys.h"

class ChangeHotkeys : public QDialog {
    Q_OBJECT

public:
    ChangeHotkeys(QWidget *parent = nullptr);

private:
    Ui::ChangeHotkeys ui;
};

#endif // CHANGEHOTKEYS_H
