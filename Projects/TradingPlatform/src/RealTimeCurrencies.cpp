#include "RealTimeCurrencies.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <map>
#include <QString>
#include <QProcess>
#include <QFile>
#include <QDebug>

std::shared_ptr<RealTimeCurrency> RealTimeCurrency::m_InstanceRTC;

std::shared_ptr<RealTimeCurrency> RealTimeCurrency::getRealTimeCurrency()
{
    if (!m_InstanceRTC)
    {
        m_InstanceRTC = std::shared_ptr<RealTimeCurrency>(new RealTimeCurrency());
    }
    return m_InstanceRTC;
}

RealTimeCurrency::RealTimeCurrency()
{
    std::thread([this]() {
            while (true) {
                getCryptoData();
                std::this_thread::sleep_for(std::chrono::seconds(5)); // Sleep for 5 seconds
            }
        }).detach();
}

void RealTimeCurrency::getCryptoData() {
    QString scriptPath = "C:/Users/tonoyan/OneDrive - Synopsys, Inc/Documents/RealTimeCryptoWallet/test.py";

    // Create a QProcess to run the Python script
    QProcess process;
    process.start("python", QStringList() << scriptPath);

    if (!process.waitForFinished()) {
        qWarning() << "Error: Failed to execute the Python script.";
        exit(1);
    }

    QFile file("C:/Users/tonoyan/OneDrive - Synopsys, Inc/Documents/RealTimeCryptoWallet/crypto_dataQT.csv");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Error: Unable to open the CSV file.";
        exit(1);
    }

    QTextStream in(&file);

    // Read data from the CSV file and populate the map
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 2) {
            QString key = parts[0];
            double value = parts[1].toDouble();
            m_cryptoData[key.toStdString()] = value;
        }
    }

    // Close the CSV file
    file.close();
}

std::string RealTimeCurrency::printRTCTable()
{
    std::string output;
    for (const auto& pair : m_cryptoData) {
        output += pair.first + " : " + std::to_string(pair.second) + "\n";
    }
    return output; 
}

std::ostream& operator<<(std::ostream& os, RealTimeCurrency& rtc)
{
    return os << rtc.printRTCTable();
}
