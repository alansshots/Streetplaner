#ifndef DIALOGSTREET_H
#define DIALOGSTREET_H

#include <QDialog>

namespace Ui {
class DialogStreet;
}

class DialogStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStreet(QWidget *parent = nullptr);

//    City* neueStadt();
    QString getCity1Name();
    QString getCity2Name();

    ~DialogStreet();

private:
    Ui::DialogStreet *ui;
//    QString city;
//    QString street;
    QString city1Name;
    QString city2Name;
//    int x_koordinate;
//    int y_koordinate;
};

#endif // DIALOGSTREET_H
