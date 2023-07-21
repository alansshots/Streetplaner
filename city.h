#ifndef CITY_H
#define CITY_H

#include <QDebug>
#include <QGraphicsView>
#include <QString>
#include <QGraphicsTextItem>
#include <QMainWindow>

class City
{
public:
    City(QString name, int x, int y);
    void draw(QGraphicsScene &scene);
    QString getName();
    int getX();
    int getY();
    ~City();

private:
    QString name;
    int x;
    int y;

};

#endif // CITY_H
