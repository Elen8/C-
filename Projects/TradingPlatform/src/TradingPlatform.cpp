#include "TradingPlatform.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <thread>
std::shared_ptr<TradingPlatform> TradingPlatform::mInstanceTP;

TradingPlatform::TradingPlatform(MainWindow* ui) : mMW(ui)
{
    mWallet = mWallet->getInstanceOfWallet();
    mRTC = mRTC->getRealTimeCurrency();

    std::thread([this]() {
            while (true) {
                updateGUI();
                std::this_thread::sleep_for(std::chrono::seconds(5)); // Sleep for 5 seconds
            }
        }).detach();
}

void TradingPlatform::updateGUI()
{
    if (mMW && mMW->ui && mRTC) {
        mMW->ui->tableWidget->setRowCount(static_cast<int>(mRTC->m_cryptoData.size()));
        mMW->ui->tableWidget->setColumnCount(2);
        mMW->ui->tableWidget->setColumnWidth(0,175);
        mMW->ui->tableWidget->setColumnWidth(1,130);
        mMW->ui->tableWidget->setHorizontalHeaderLabels({"Crypto Currency", "Price"});

        int row = 0;
        for (const auto& pair : mRTC->m_cryptoData) {
            QTableWidgetItem* keyItem = new QTableWidgetItem(QString::fromStdString(pair.first));
            mMW->ui->tableWidget->setItem(row, 0, keyItem);
            double oldValue{};
            if (mMW->ui->tableWidget->item(row, 1))
            {
                oldValue =  mMW->ui->tableWidget->item(row, 1)->text().toDouble();
            }
            QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(pair.second));
            mMW->ui->tableWidget->setItem(row, 1, valueItem);
            if (oldValue != 0)
            {
                if (oldValue < pair.second)
                    mMW->ui->tableWidget->item(row, 1)->setForeground(Qt::darkGreen);
                else if (oldValue > pair.second)
                    mMW->ui->tableWidget->item(row, 1)->setForeground(Qt::darkRed);
            }
            else
            {
                mMW->ui->tableWidget->item(row, 1)->setBackground(Qt::lightGray);
            }
            row++;
        }
    }
    else {}

    if (mMW->ui->comboBox->count() == 0)
    {
        for (const auto& pair : mRTC->m_cryptoData)
        {
            mMW->ui->comboBox->addItem(QString::fromStdString(pair.first));
            mMW->ui->comboBox_3->addItem(QString::fromStdString(pair.first));
        }

        mMW->ui->tableWidget_2->setRowCount(1);
        mMW->ui->tableWidget_2->setColumnCount(2);
        mMW->ui->tableWidget_2->setColumnWidth(0,175);
        mMW->ui->tableWidget_2->setColumnWidth(1,160);
        mMW->ui->tableWidget_2->setHorizontalHeaderLabels({"Currency", "Amount"});
        QTableWidgetItem* keyItem = new QTableWidgetItem(QString::fromStdString(std::string("USD")));
        mMW->ui->tableWidget_2->setItem(0, 0, keyItem);
        QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(0.0));
        mMW->ui->tableWidget_2->setItem(0, 1, valueItem);
    }
}

std::shared_ptr<Wallet> TradingPlatform::getMyWallet()
{
    return mWallet;
}

std::shared_ptr<RealTimeCurrency> TradingPlatform::getRealTimeCurrencies()
{
    return mRTC;
}

std::shared_ptr<TradingPlatform> TradingPlatform::getInstanceOfTP(MainWindow* ui)
{
    if (!mInstanceTP)
    {
        mInstanceTP = std::shared_ptr<TradingPlatform>(new TradingPlatform(ui));
    }
    return mInstanceTP;
}

void TradingPlatform::buyCrypto(const std::string& cryptoName, double amount)
{
    if (amount > mWallet->getBalance())
    {
        throw std::exception{};
    }
    else
    {
        double cryptoAmount = double(amount / mRTC->m_cryptoData[cryptoName]);
        mWallet->insertCurrency(cryptoName, cryptoAmount);
        mWallet->removeBalance(amount);
    }

}

void TradingPlatform::sellCrypto(const std::string& cryptoName, double amount)
{
    double moneyAmount = amount * mRTC->m_cryptoData[cryptoName];
    mWallet->removeCurrency(cryptoName, amount);
    mWallet->addBalance(moneyAmount);
}

void TradingPlatform::addBalance(double amount)
{
    mWallet->addBalance(amount);
}

void TradingPlatform::removeBalance(double amount)
{
    mWallet->removeBalance(amount);
}

/*For console version
const std::string TradingPlatform::inputCryptoName()
{
    std::cout << "\nInput currency: ";
    std::string inputCrypto;
    std::cin >> inputCrypto;
    std::transform(inputCrypto.begin(), inputCrypto.end(), inputCrypto.begin(), ::toupper);
    while (mRTC->m_cryptoData.find(inputCrypto) == mRTC->m_cryptoData.end())
    {
        std::cout << "\nWrong input, type again: ";
        std::cin >> inputCrypto;
        std::transform(inputCrypto.begin(), inputCrypto.end(), inputCrypto.begin(), ::toupper);
    }
    std::cout << "Crypto found. Price : " << mRTC->m_cryptoData[inputCrypto] << std::endl;

    return inputCrypto;
}

double TradingPlatform::inputAmount()
{
    std::cout << "\nYour balance is " << mWallet->getBalance() << ". How much to spend?($) : ";
    double amount{};
    std::cin >> amount;
    while (amount == 0 || mWallet->getBalance() < amount)
    {
        if (mWallet->getBalance() < amount)
        {
            std::cout << "\nYou don't have this much money.";
        }
        std::cout << "\nWrong input, type again: ";
        std::cin >> amount;
    }
    return amount;
}*/
