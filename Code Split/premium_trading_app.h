#ifndef PREMIUM_TRADING_APP_H
#define PREMIUM_TRADING_APP_H

#include "basic_trading_app.h"

class PremiumTradingApp : public BasicTradingApp {
public:
    PremiumTradingApp();
    void premiumDeposit(double amount);
    void viewAccountDetails() override;
};

#endif  // PREMIUM_TRADING _APP_H