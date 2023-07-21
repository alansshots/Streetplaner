#include "dialogShortPath.h"
#include "ui_dialogShortPath.h"

DialogShortPath::DialogShortPath(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShortPath)
{
    ui->setupUi(this);
}

DialogShortPath::~DialogShortPath()
{
    delete ui;
}
