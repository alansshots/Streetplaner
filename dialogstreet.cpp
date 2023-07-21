#include "dialogstreet.h"
#include "ui_dialogstreet.h"

DialogStreet::DialogStreet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStreet)
{
    ui->setupUi(this);
}

DialogStreet::~DialogStreet()
{
    delete ui;
}


QString DialogStreet::getCity1Name()
{
        city1Name = ui->city1Input->text();

    return city1Name;
}

QString DialogStreet::getCity2Name()
{
        city2Name = ui->city2Input->text();

    return city2Name;
}
