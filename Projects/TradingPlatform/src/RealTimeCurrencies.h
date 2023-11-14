#pragma once
#include <map>
#include <string>
#include <memory>


class RealTimeCurrency
{
public:
    std::map<const std::string, double> m_cryptoData;

    /** for console version */
    std::string printRTCTable();
    friend std::ostream& operator<<(std::ostream& os, RealTimeCurrency&);
    /** ************************************************************** */

    static std::shared_ptr<RealTimeCurrency> getRealTimeCurrency();
    
    RealTimeCurrency(RealTimeCurrency const&)		= delete;
    RealTimeCurrency(RealTimeCurrency&&)			= delete;
    void operator = (RealTimeCurrency const&)		= delete;

private:
	RealTimeCurrency();
	static std::shared_ptr<RealTimeCurrency> m_InstanceRTC;

    /** get crypto data which is being updated every 5 seconds */
	void getCryptoData();
};
