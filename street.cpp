#include "street.h"

Street::Street(City* city1, City* city2):
    city1(city1), city2(city2)
{

}

void Street::draw(QGraphicsScene &scene)
{
    int x1 = (city1)->getX();
    int y1 = (city1)->getY();
    int x2 = (city2)->getX();
    int y2 = (city2)->getY();

    QPen Pen;
    Pen.setColor(Qt::blue);
    Pen.setWidth(2);
    scene.addLine(x1, y1, x2, y2, Pen);
}

City* Street::getCity1() const
{
    return city1;
}

City* Street::getCity2() const
{
    return city2;
}

void Street::strassen_id()
{
    qDebug() << "Verbindung zwischen " << city1->getName() << " und " << city2->getName();
}

void Street::drawRed(QGraphicsScene &scene)
{
    int x1 = (city1)->getX();
    int y1 = (city1)->getY();
    int x2 = (city2)->getX();
    int y2 = (city2)->getY();

    QPen Pen;
    Pen.setColor(Qt::red);
    Pen.setWidth(3);
    scene.addLine(x1, y1, x2, y2, Pen);
}

Street::~Street()
{

}
