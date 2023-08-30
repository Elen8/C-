#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    financeTracker = new FinanceTracker(this);
    controller = new Controller(ui, financeTracker, this);

    connect(financeTracker->getTableModel(), &QSqlTableModel::dataChanged, [this]()
    {
        ui->tableView->reset();
    });

    connect(ui->B_AddCategory, &QPushButton::clicked, controller, &Controller::handleAddCategoryButtonClicked);
    connect(ui->LE_Mount, &QLineEdit::returnPressed, controller, &Controller::handleAddExpanceReturned);
    connect(ui->LE_MaxMount, &QLineEdit::returnPressed, controller, &Controller::handleEditMaxMountReturned);
    connect(ui->B_RemoveCategory, &QPushButton::clicked, controller, &Controller::handleDeleteCategoryButtonClicked);
    
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CB_SortMethod_currentIndexChanged(int index)
{
    qDebug() << index;
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(index, Qt::AscendingOrder);
    ui->tableView->viewport()->update();
}


void MainWindow::on_CB_ShowMode_currentIndexChanged(int index)
{
    ui->stackedWidget_2->setCurrentIndex(index);

}
