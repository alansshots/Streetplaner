#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

City* Dialog::neueStadt()
{
    city = ui->stadtName->text();
    qDebug() << city;
    bool ok;

    x_koordinate = ui->xKoordinate->text().toInt(&ok);

    if (ok == false)
    {
        qDebug() << "please inter a valid integer!";
    }
    qDebug() << x_koordinate;

    y_koordinate = ui->yKoordinate->text().toInt(&ok);
    if (ok == false)
    {
        qDebug() << "please inter a valid integer!";
    }
    qDebug() << y_koordinate;

    return  new City(city, x_koordinate, y_koordinate);
}

//QString Dialog::getCity1Name()
//{
////    city1Name = ui->city1->text();

//    return city1Name;
//}

//QString Dialog::getCity2Name()
//{
////    city2Name = ui->city2->text();

//    return city2Name;
//}
