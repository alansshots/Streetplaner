#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "city.h"
#include "street.h"
#include "abstractmap.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    City* neueStadt();
//    QString getCity1Name();
//    QString getCity2Name();

    ~Dialog();

private:
    Ui::Dialog *ui;
    QString city;
    QString street;
//    QString city1Name;
//    QString city2Name;
    int x_koordinate;
    int y_koordinate;
};

#endif // DIALOG_H
