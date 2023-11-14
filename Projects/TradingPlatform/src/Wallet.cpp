#include "Wallet.h"
#include <string>

std::shared_ptr<Wallet> Wallet::mInstanceWallet;

Wallet::Wallet()
{
    mybalance = 0;
}

std::shared_ptr<Wallet> Wallet::getInstanceOfWallet()
{
    if (!mInstanceWallet)
    {
        mInstanceWallet = std::shared_ptr<Wallet>(new Wallet());
    }
    return mInstanceWallet;
}


void Wallet::insertCurrency(const std::string& type, double amount)
{
    double balance;
    if (amount < 0)
    {
        throw std::exception{};
    }

    if (myCurrencies.count(type) == 0) // not there yet
    {
        balance = 0;
    }
    else { // is there 
        balance = myCurrencies[type];
    }
    balance += amount;
    myCurrencies[type] = balance;
}

bool Wallet::removeCurrency(const std::string& type, double amount)
{
    if (amount < 0)
    {
        throw std::exception{};
    }
    if (myCurrencies.count(type) == 0)
    {
        throw std::exception{};
    }
    else { 
        if (containsCurrency(type, amount))
        {
            myCurrencies[type] -= amount;
            return true;
        }
        else 
            throw std::exception{};
    }
}

bool Wallet::containsCurrency(const std::string& type, double amount)
{
    if (myCurrencies.count(type) == 0) // not there yet
        return false;
    else
        return myCurrencies[type] >= amount;
}

void Wallet::addBalance(double amount)
{
    if (amount < 0)
    {
        throw std::exception{};
    }
    mybalance += amount;
}

void Wallet::removeBalance(double amount)
{
    if (amount < 0 || mybalance < amount)
    {
        throw std::exception{};
    }
    mybalance -= amount;
}

double Wallet::getBalance()
{
    return mybalance;
}

double Wallet::getValue(std::string cryptoName)
{
    return myCurrencies[cryptoName];
}

std::string Wallet::printWallet()
{
    std::string s;
    for (std::pair<std::string, double> pair : myCurrencies)
    {
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + std::to_string(amount) + "\n";
    }
    return s;
}

std::ostream& operator<<(std::ostream& os, Wallet& wallet)
{
    return os << wallet.printWallet();
}
