#ifndef STREET_H
#define STREET_H

#include<QGraphicsView>
#include<QGraphicsItem>
#include "city.h"

class Street
{
public:
    Street(City* city1, City* city2);

    void draw(QGraphicsScene &scene);
    City* getCity1() const;
    City* getCity2() const;
    void drawRed(QGraphicsScene &scene);
    void strassen_id();

    ~Street();

private:
    City* city1;
    City* city2;
};

#endif // STREET_H
