#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QComboBox>

#include "map.h"
#include "mapio.h"
#include "mapionrw.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_testDrawCityBtn_clicked();

    void on_testAddCityBtn_clicked();

    void on_testAddStreetBtn_clicked();

    void on_checkBox_clicked();

    void on_addCityBtn_clicked();

    void on_fillMapBtn_clicked();

    void on_testAbstractMapBtn_clicked();

    void on_testDijkstraBtn_clicked();

    void on_findShortestPathBtn_clicked();

    void on_addStreetBtn_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapio;
    void updateCombo();
};
#endif // MAINWINDOW_H
