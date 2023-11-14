#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TradingPlatform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::shared_ptr<TradingPlatform> newTP = newTP->getInstanceOfTP(this);
    mTP = mTP->getInstanceOfTP(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void raiseError(const QString& errorMessage)
{
    QMessageBox messageBox;
    messageBox.setText(errorMessage);
    messageBox.setWindowTitle("Warning");
    messageBox.exec();
}


void MainWindow::on_LEBuyAmount_returnPressed()
{
    if (ui->LEBuyAmount->text().isEmpty() || ui->comboBox->currentText() == "")
    {
        raiseError("Fill all blanks!");
        return;
    }
    bool isNumber;
    double number = ui->LEBuyAmount->text().toDouble(&isNumber);
    if (isNumber)
    {
        try
        {
            mTP->buyCrypto(ui->comboBox->currentText().toStdString(), number);
        }
        catch (const std::exception& e)
        {
            raiseError("Wrong amount!!!");
            return;
        }

        int row = ui->tableWidget_2->rowCount();
        bool found = false;
        for (int i = 0; i < row; ++i)
            if (ui->tableWidget_2->item(i, 0)->text() == ui->comboBox->currentText())
            {
                found = true;
                double amount = mTP->getMyWallet()->getValue(ui->comboBox->currentText().toStdString());
                QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(amount));
                ui->tableWidget_2->setItem(i, 1, valueItem);
            }

        if (!found)
        {
            ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
            QTableWidgetItem* nameItem = new QTableWidgetItem(ui->comboBox->currentText());
            ui->tableWidget_2->setItem(row, 0, nameItem);
            double amount = mTP->getMyWallet()->getValue(ui->comboBox->currentText().toStdString());
            QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(amount));
            ui->tableWidget_2->setItem(row, 1, valueItem);
        }

        QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(ui->tableWidget_2->item(0,1)->text().toDouble() - number));
        ui->tableWidget_2->setItem(0, 1, valueItem);
    }


}

void MainWindow::on_LESellAmount_returnPressed()
{
    if (ui->LEBuyAmount->text().isEmpty() || ui->comboBox->currentText() == "")
    {
        raiseError("Fill all blanks!");
        return;
    }
    bool isNumber;
    double number = ui->LESellAmount->text().toDouble(&isNumber);
    if (isNumber)
    {
        try
        {
            mTP->sellCrypto(ui->comboBox->currentText().toStdString(), number);
        }
        catch (const std::exception& e)
        {
            raiseError("Wrong amount!!!");
            return;
        }

        int row = ui->tableWidget_2->rowCount();
        for (int i = 0; i < row; ++i)
        {
            qDebug() << ui->tableWidget_2->item(i, 0)->text();
            if (ui->tableWidget_2->item(i, 0)->text() == ui->comboBox->currentText())
            {
                if (mTP->getMyWallet()->getValue(ui->comboBox->currentText().toStdString()) == 0)
                {
                    ui->tableWidget_2->removeRow(i);
                }
                else
                {
                    double amount = mTP->getMyWallet()->getValue(ui->comboBox->currentText().toStdString());
                    QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(amount));
                    ui->tableWidget_2->setItem(i, 1, valueItem);
                }
                break;
            }
        }
        QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(mTP->getMyWallet()->getBalance()));
        ui->tableWidget_2->setItem(0, 1, valueItem);
    }
}

void MainWindow::on_LEAddtoWalletAmount_returnPressed()
{
    if (ui->LEAddtoWalletAmount->text().isEmpty())
    {
        raiseError("Fill all blanks!");
        return;
    }

    bool isNumber;
    double number = ui->LEAddtoWalletAmount->text().toDouble(&isNumber);
    if (isNumber)
    {
        mTP->addBalance(number);
        number = ui->tableWidget_2->item(0,1)->text().toDouble() + number;
        QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(number));
        ui->tableWidget_2->setItem(0, 1, valueItem);
    }
}

void MainWindow::on_LERemovefromWalletAmount_returnPressed()
{
    if (ui->LERemovefromWalletAmount->text().isEmpty())
    {
        raiseError("Fill all blanks!");
        return;
    }
    bool isNumber;
    double number = ui->LERemovefromWalletAmount->text().toDouble(&isNumber);
    if (isNumber)
    {
        qDebug() << ui->tableWidget_2->item(0,1)->text().toDouble();
        qDebug() << number;

        try
        {
            mTP->removeBalance(number);
        }
        catch (const std::exception& e)
        {
            raiseError("Wrong amount!!!");
            return;
        }
        QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(mTP->getMyWallet()->getBalance()));
        ui->tableWidget_2->setItem(0, 1, valueItem);
    }
}
