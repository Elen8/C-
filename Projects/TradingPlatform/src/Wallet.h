#pragma once
#include <iostream>
#include <map>
#include <memory>


class Wallet
{
public:
    /** insert currency to the wallet */
    void insertCurrency(const std::string& type, double amount);

    /** remove currency from the wallet */
    bool removeCurrency(const std::string& type, double amount);

    /** check if the wallet contains this much currency or more */
    bool containsCurrency(const std::string& type, double amount);

    /** balance by dollars  **/
    void addBalance(double amount);

    /** remove balance by dollars*/
    void removeBalance(double amount);

    /** get value by name*/
    double getValue(const std::string cryptoName);

    /** get balance*/
    double getBalance();

    /** for console version */
    std::string printWallet();
    friend std::ostream& operator<<(std::ostream& os, Wallet& wallet);
    /** ************************************************************** */

    static std::shared_ptr<Wallet> getInstanceOfWallet();

private:
    Wallet();
    static std::shared_ptr<Wallet> mInstanceWallet;

    std::map<const std::string, double> myCurrencies;
    double mybalance = 0;
};
