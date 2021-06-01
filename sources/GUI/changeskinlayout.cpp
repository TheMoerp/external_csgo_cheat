#include "changeskinlayout.h"
#include <QScreen>

ChangeSkinLayout::ChangeSkinLayout(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    setWindowTitle("Skinlayout");
}
