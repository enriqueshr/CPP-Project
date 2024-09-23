#ifndef BASIC_TRADING_APP_H
#define BASIC_TRADING_APP_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>

class BasicTradingApp {
protected:
    double balance;
    std::map<std::string, double> cryptoHoldings; // Map to hold different cryptos and their amounts
    std::vector<std::string> transactionHistory;

public:
    BasicTradingApp();
    void deposit(double amount);
    void withdraw(double amount);
    void buyCrypto(const std::string &crypto, double amount);
    void sellCrypto(const std::string &crypto, double amount);
    virtual void viewAccountDetails();
    void viewTransactionHistory();
    void clearTransactionHistory();

protected:
    double getRandomPrice() const;
};

#endif  // BASIC_TRADING_APP_H