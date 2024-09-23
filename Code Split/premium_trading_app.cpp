#include "premium_trading_app.h"

PremiumTradingApp::PremiumTradingApp() : BasicTradingApp() {}

void PremiumTradingApp::premiumDeposit(double amount) {
    double bonus = (amount > 500) ? 50.0 : 0.0; // Premium users get a bonus for high deposits
    BasicTradingApp::deposit(amount + bonus);
    transactionHistory.push_back("Premium Deposit: $" + std::to_string(amount) + " (Bonus: $" + std::to_string(bonus) + ")");
    std::cout << "Deposited $" << amount << " with a bonus of $" << bonus << ". Current balance: $" << balance << std::endl;
}

void PremiumTradingApp::viewAccountDetails() {
    std::cout << "Premium Account Balance: $" << balance << std::endl;
    BasicTradingApp::viewAccountDetails();
}