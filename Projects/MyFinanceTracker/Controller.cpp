#include "Controller.h"


Controller::Controller(Ui::MainWindow* ui, FinanceTracker* financeTracker, QObject* parent)
    : QObject(parent)
    , ui(ui)
    , financeTracker(financeTracker) {
    ui->tableView->setModel(financeTracker->getTableModel());
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int i = 0; i < financeTracker->getTableModel()->rowCount(); ++i) {
      QString value = financeTracker->getTableModel()->data(financeTracker->getTableModel()->index(i, 0)).toString();
      ui->CB_Remove->addItem(value);
      ui->CB_AddExpance->addItem(value);
      ui->CB_EditMaxMount->addItem(value);
    }
    ui->CB_SortMethod->addItem("Name");
    ui->CB_SortMethod->addItem("Max Mount");
    ui->CB_SortMethod->addItem("Current Mount");
}

void Controller::handleAddCategoryButtonClicked()
{
    QString maxMount = ui->LE_MaxMount->text();
    QString category = ui->LE_CategoryName->text();
    if (financeTracker->addCategory(category, maxMount))
    {
        ui->CB_Remove->addItem(category);
        ui->CB_AddExpance->addItem(category);
        ui->CB_EditMaxMount->addItem(category);
    }
}


void Controller::handleAddExpanceReturned()
{
    QString expance = ui->LE_Mount->text();
    QString category = ui->CB_AddExpance->currentText();
    financeTracker->addExpance(category, expance);
    ui->tableView->viewport()->update();
}

void Controller::handleEditMaxMountReturned()
{
    QString maxMount = ui->LE_Mount_2->text();
    QString category = ui->CB_EditMaxMount->currentText();
    financeTracker->addExpance(category, maxMount);
    ui->tableView->viewport()->update();
}

void Controller::handleDeleteCategoryButtonClicked()
{
    QString category = ui->CB_Remove->currentText();
    financeTracker->deleteCategory(category);
    ui->tableView->viewport()->update();
}


void Controller::handleHistoryButtonClicked()
{
    
}

