#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
//#include <QtCharts>
#include "Controller.h"
#include "Finance.h"

//QT_CHARTS_USE_NAMESPACE

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

    void on_CB_SortMethod_currentIndexChanged(int index);

    void on_CB_ShowMode_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    FinanceTracker*  financeTracker;
    Controller* controller;
};
#endif // MAINWINDOW_H
