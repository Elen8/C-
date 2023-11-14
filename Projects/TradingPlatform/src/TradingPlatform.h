#pragma once
#include <map>
#include <iostream>
#include <memory>
#include "Wallet.h"
#include "mainwindow.h"
#include "RealTimeCurrencies.h"

class TradingPlatform
{
public:
    /** buy crypto and add to wallet */
    void buyCrypto(const std::string& cryptoName, double amount);

    /** sell crypto and remove from wallet */
    void sellCrypto(const std::string& cryptoName, double amount);

    /** aadd balance to the wallet */
    void addBalance(double amount);

    /** remove balance from the wallet */
    void removeBalance(double amount);

    /** get crypto data */
    std::shared_ptr<RealTimeCurrency> getRealTimeCurrencies();

    /** get the wallet */
    std::shared_ptr<Wallet> getMyWallet();

    static std::shared_ptr<TradingPlatform> getInstanceOfTP(MainWindow* ui);

    TradingPlatform(TradingPlatform const&)     = delete;
    TradingPlatform(TradingPlatform&&)          = delete;
    void operator = (TradingPlatform const&)    = delete;

protected:
    TradingPlatform(MainWindow* ui);

private:
    /** update GUI every 5 seconds */
    void updateGUI();

    static std::shared_ptr<TradingPlatform> mInstanceTP;

    std::shared_ptr<Wallet> mWallet;
    std::shared_ptr<RealTimeCurrency> mRTC;
    MainWindow* mMW;
};
