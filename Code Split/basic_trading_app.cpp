#include "basic_trading_app.h"

BasicTradingApp::BasicTradingApp() : balance(0.0) {
    std::srand(std::time(nullptr)); // Seed RNG
}

void BasicTradingApp::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactionHistory.push_back("Deposited: $" + std::to_string(amount));
        std::cout << "Deposited $" << amount << ". Current balance: $" << balance << std::endl;
    } else {
        std::cout << "Invalid amount!" << std::endl;
    }
}

void BasicTradingApp::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        transactionHistory.push_back("Withdrew: $" + std::to_string(amount));
        std::cout << "Withdrew $" << amount << ". Current balance: $" << balance << std::endl;
    } else {
        std::cout << "Invalid or insufficient balance!" << std::endl;
    }
}

void BasicTradingApp::buyCrypto(const std::string &crypto, double amount) {
    double price = getRandomPrice();
    double cost = amount * price;

    if (balance >= cost) {
        balance -= cost;
        cryptoHoldings[crypto] += amount; // Add to crypto holdings
        transactionHistory.push_back("Bought " + std::to_string(amount) + " " + crypto + " at $" + std::to_string(price) + " each");
        std::cout << "Purchased " << amount << " " << crypto << " at $" << price << " each." << std::endl;
    } else {
        std::cout << "Insufficient funds!" << std::endl;
    }
}

void BasicTradingApp::sellCrypto(const std::string &crypto, double amount) {
    double price = getRandomPrice();

    if (cryptoHoldings[crypto] >= amount) {
        cryptoHoldings[crypto] -= amount;
        balance += amount * price;
        transactionHistory.push_back("Sold " + std::to_string(amount) + " " + crypto + " at $" + std::to_string(price) + " each");
        std::cout << "Sold " << amount << " " << crypto << " at $" << price << " each." << std::endl;
    } else {
        std::cout << "Insufficient " << crypto << " to sell!" << std::endl;
    }
}

void BasicTradingApp::viewAccountDetails() {
    std::cout << "Account Balance: $" << balance << std::endl;
    for (const auto &pair : cryptoHoldings) {
        std::cout << pair.first << " Holdings: " << pair.second << std::endl;
    }
}

void BasicTradingApp::viewTransactionHistory() {
    std::cout << "Transaction History:" << std::endl;
    for (const auto &transaction : transactionHistory) {
        std::cout << transaction << std::endl;
    }
}

void BasicTradingApp::clearTransactionHistory() {
    transactionHistory.clear();
    std::cout << "Transaction history cleared!" << std::endl;
}

double BasicTradingApp::getRandomPrice() const {
    return 100 + (std::rand() % 1000) / 10.0; // Random price between $100 and $200
}