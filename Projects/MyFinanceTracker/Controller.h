#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Finance.h"
#include "ui_mainwindow.h"
#include "History.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(Ui::MainWindow* ui, FinanceTracker* financeTracker, QObject* parent = nullptr);

public slots:
    void handleAddCategoryButtonClicked();
    void handleAddExpanceReturned();
    void handleEditMaxMountReturned();
    void handleDeleteCategoryButtonClicked();
    void handleHistoryButtonClicked();
    
private:
    Ui::MainWindow* ui;
    FinanceTracker* financeTracker;
    History* history;
};


#endif // CONTROLLER_H
