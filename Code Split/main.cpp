#include "premium_trading_app.h"

int main() {
    PremiumTradingApp app;
    int choice;
    while (true) {
        std::cout << "\n--- King's Premium Growth Fund ---\n";
        std::cout << "1. Deposit Money (with Bonus)\n2. Withdraw Money\n3. Buy Cryptocurrency\n4. Sell Cryptocurrency\n5. View Account Details\n6. View Transaction History\n7. Clear Transaction History\n0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        double amount;
        std::string crypto;
        switch (choice) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                app.premiumDeposit(amount); // Premium deposit
                break;
            case 2:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                app.withdraw(amount);
                break;
            case 3:
                std::cout << "Enter cryptocurrency to buy (e.g., bitcoin, dogecoin): ";
                std::cin >> crypto;
                std::cout << "Enter number of units you want to buy: ";
                std::cin >> amount;
                app.buyCrypto(crypto, amount);
                break;
            case 4:
                std::cout << "Enter cryptocurrency to sell (e.g., bitcoin, dogecoin): ";
                std::cin >> crypto;
                std::cout << "Enter number of units you want to sell: ";
                std::cin >> amount;
                app.sellCrypto(crypto, amount);
                break;
            case 5:
                app.viewAccountDetails();
                break;
            case 6:
                app.viewTransactionHistory();
                break;
            case 7:
                app.clearTransactionHistory();
                break;
            case 0:
                std::cout << "Exiting application." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice! Try again." << std::endl;
        }
    }

    return 0;
}