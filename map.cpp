#include "map.h"

Map::Map()
{

}

void Map::addCity(City* stadt)
{
    liste_staedte.append(stadt);
    qDebug() << stadt->getName() << "wurde zur Karte hinzugefügt";
}

City* Map::findCity(const QString cityName) const
{
    for(QVector<City*>::const_iterator it = liste_staedte.begin(); it != liste_staedte.end(); it++)
    {
        if ((*it)->getName() == cityName)
        {
            return *it;
        }
    }

    return nullptr;
}

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector <Street*> CityStreetList;
    for(QVector<Street*>::const_iterator it = liste_strassen.begin(); it != liste_strassen.end(); it++)
    {
        if(city == (*it)->getCity1() || city == (*it)->getCity2())
        {
            CityStreetList.append(*it);
        }
    }

    return CityStreetList;
}

QVector<City*> Map::getCityList()
{
    return liste_staedte;
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (city == street->getCity1())
    {
        return street->getCity2();
    }

    else if (city == street->getCity2())
    {
        return street->getCity1();
    }

    else
    {
        return nullptr;
    }
}

double Map::getLength(const Street* street) const
{
    double x1 = street->getCity1()->getX();
    double x2 = street->getCity2()->getX();
    double y1 = street->getCity1()->getY();
    double y2 = street->getCity2()->getY();

    double x_laenge = abs(x2 - x1);
    double y_laenge = abs(y2 - y1);

    double length = sqrt(x_laenge*x_laenge + y_laenge*y_laenge);

    return length;
}

bool Map::addStreet(Street* strasse)
{
    City* city1 = strasse->getCity1();
    City* city2 = strasse->getCity2();

    if (findCity(city1->getName()) != nullptr && findCity(city2->getName()) != nullptr)
    {
        liste_strassen.append(strasse);
        return true;
    }

    else
    {
        return false;
    }
}

void Map::draw(QGraphicsScene &scene)
{
//    for(QVector<City*>::iterator it = liste_staedte.begin(); it != liste_staedte.end(); it++)
//    {
//        QPen pen(Qt::red);
//        pen.setWidth(2);

//        QString city = (*it)->getName();
//        int x = (*it)->getX();
//        int y = (*it)->getY();

//        scene.addEllipse(x, y, 12, 12, pen, QBrush(Qt::yellow, Qt::SolidPattern));

//        QGraphicsTextItem* text = scene.addText(city);
//        text->setPos(x, y);
//    }

    for (auto city : liste_staedte)
    {
        city->draw(scene);
    }
    if (!liste_strassen.isEmpty())
    {
        for (auto strasse : liste_strassen)
        {
            strasse->draw(scene);
        }
    }
}

Map::~Map()
{

}
