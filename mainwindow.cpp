#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "city.h"
#include "street.h"
#include "dialog.h"
#include "dialogstreet.h"
#include "dijkstra.h"

#include <QString>
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>
#include <cstdlib>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    mapio = new MapIoNrw;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_teste_was_clicked()
{
    qDebug() << "Test Test :) ";

    // Eingegebenen Text aus dem Line Edit
    QString eingabe = ui->lineEdit_teste_was->text();

    bool ok;
    int eingabeAlsZahl = eingabe.toInt(&ok);

    if (ok) {
        int eigabeErhoeht = eingabeAlsZahl + 4;
        // Verwende die Methode .arg() von QString, um den Text einzusetzen
        QString message = QString("Die Zahl erhöht um 4: '%1'!").arg(eigabeErhoeht);

        // Output mittels QMessageBox
        QMessageBox::information(this, "Ergebnis", message);

    } else {
        // Verwende die Methode .arg() von QString, um den Text einzusetzen
        QString message = QString("Du hast '%1' eingegeben!").arg(eingabe);
        // Output mittels QMessageBox
        QMessageBox::information(this, "Eingabe", message);
    }

//    double x = qrand() * 9/RAND_MAX;
//    double y = qrand() * 9/RAND_MAX;
//    double w = qrand() * 9/RAND_MAX;
//    double h = qrand() * 9/RAND_MAX;

    int randomX = std::rand() % 10;
    int randomY = std::rand() % 10;
    int width = std::rand() % 10;
    int height = std::rand() % 10;

    scene.addRect(randomX, randomY, width * 10, height * 10, QPen(Qt::blue), QBrush(Qt::SolidPattern));

}

// Beendet das Programm
void MainWindow::on_actionExit_triggered()
{
    close();
}

// Clear Screen für grafische Darstellung
void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
    updateCombo();
}

// Gibt Informationen über das Praktikum
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    QString titel = "Das RWTH Informatik Praktikum!";
    QString inhalt = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla quis sapien ante. Vestibulum quis malesuada quam, at dapibus libero. Vestibulum at risus a tortor varius congue in quis dolor. Sed at consequat nisi. Aliquam interdum laoreet tempor.";

    msgBox.about(this, titel, inhalt);
}

// Fügt einиге Staеdtе hinzu
void MainWindow::on_testDrawCityBtn_clicked()
{
    City Sliven("Sliven", 0, 0);
    City Aachen("Aachen", 40, 10);

    Sliven.draw(scene);
    Aachen.draw(scene);

}

// Fügt eine Stadt hinzu
void MainWindow::on_testAddCityBtn_clicked()
{
    City c1("city c1", 20,50);
    map.addCity(&c1);
    map.draw(scene);
}

// Fügt Straße hinzu
void MainWindow::on_testAddStreetBtn_clicked()
{

    City Berlin("Berlin", 0, 0);
    City Aachen("Aachen", 30, 60);
    Street street1(&Berlin, &Aachen);
    map.addCity(&Berlin);
    map.addCity(&Aachen);
    Berlin.draw(scene);
    Aachen.draw(scene);
    street1.draw(scene);
}

// Anzeigen und Verstecken von Testknöpfen
void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()==true)
    {
        ui->testDrawCityBtn->hide();
        ui->testAddCityBtn->hide();
        ui->testAddStreetBtn->hide();
        ui->testAbstractMapBtn->hide();
        ui->testDijkstraBtn->hide();
    }

    else if(ui->checkBox->isChecked()==false)
    {
        ui->testDrawCityBtn->show();
        ui->testAddCityBtn->show();
        ui->testAddStreetBtn->show();
        ui->testAbstractMapBtn->show();
        ui->testDijkstraBtn->show();
    }
}

// Hinzufügen einer Stadt nach Benutzer
void MainWindow::on_addCityBtn_clicked()
{
    Dialog dialog;
    int i = dialog.exec();
    qDebug() << "Rückgabewert: " << i;

    if(i == 1)
    {
        City* city = dialog.neueStadt();
        map.addCity(city);
        city->draw(scene);
    }
    else
    {
        qDebug() << "Es wurde keine neue Stadt hinzugefügt";
    }

    updateCombo();
}


// Mehrere Städte hinzufügen (NRW-Karte)
void MainWindow::on_fillMapBtn_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);
    updateCombo();
}

// Abstrakt Map tests
void MainWindow::on_testAbstractMapBtn_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}

// Test ob Dijkstra funkzioniert
void MainWindow::on_testDijkstraBtn_clicked()
{
    Map testMap;

    City *start = new City("start", 0, 0);
    City *transit = new City("transit", 50, 50);
    City *target = new City("target", 0, 100);
    testMap.addCity(start);
    testMap.addCity(transit);
    testMap.addCity(target);

    Street *testStreet1 = new Street(start, transit);
    Street *testStreet2 = new Street(transit, target);
    testMap.addStreet(testStreet1);
    testMap.addStreet(testStreet2);

    testMap.draw(scene);

    QVector<Street*> shortest_path = Dijkstra::search(testMap, start->getName(), target->getName());

    for(auto it = shortest_path.begin(); it != shortest_path.end(); it++)
    {
        (*it)->strassen_id();
    }

    for(auto it = shortest_path.begin(); it != shortest_path.end(); it++)
    {
        (*it)->drawRed(scene);
    }
}

// ComboBox update mit Staedten
void MainWindow::updateCombo()
{
    QVector<City*> temp = map.getCityList();

    while (ui->comboBox1->count() > 0) {
        ui->comboBox1->removeItem(0);
    }
    while (ui->comboBox2->count() > 0) {
        ui->comboBox2->removeItem(0);
    }

    ui->comboBox1->update();
    ui->comboBox2->update();

    for(auto it = temp.begin(); it != temp.end(); it++)
    {
        ui->comboBox1->addItem((*it)->getName());
        ui->comboBox2->addItem((*it)->getName());
    }
}


// Dijkstra Algaritmus benutzen um "Shortest Path" zu finden
void MainWindow::on_findShortestPathBtn_clicked()
{
    map.draw(scene);
    QString start = ui->comboBox1->currentText();
    QString target = ui->comboBox2->currentText();

    if (start == target)
    {
        qDebug() << "please enter a valid destination";
        return;
    }

    QVector<Street*> shortest_path = Dijkstra::search(map, start, target);

    for(auto it = shortest_path.begin(); it != shortest_path.end(); it++)
    {
        (*it)->strassen_id();
    }

    for(auto it = shortest_path.begin(); it != shortest_path.end(); it++)
    {
        (*it)->drawRed(scene);
    }
}


// Hinzufügen einer Straße zwischen zwei von einem Benutzer ausgewählten Städten
void MainWindow::on_addStreetBtn_clicked()
{
    DialogStreet dialogstreet;
    int i = dialogstreet.exec();
    qDebug() << "Der Rückgabewert: " << i;

    if (i == 1)
    {
        QString Name1 = dialogstreet.getCity1Name();
        QString Name2 = dialogstreet.getCity2Name();

        if(map.findCity(Name1) == nullptr || map.findCity(Name2) == nullptr)
        {
            qDebug() << "please enter valid cities!";
            return;
        }

        City* city1 = map.findCity(Name1);
        City* city2 = map.findCity(Name2);

        Street* strasse = new Street(city1, city2);
        if(map.addStreet(strasse))
        {
            strasse->draw(scene);
        }
    }

    else
    {
        qDebug() << "No new street has been added!";
    }
}

