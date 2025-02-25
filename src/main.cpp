#include "MarketData.hpp"
#include "Order.hpp"
#include "Portfolio.hpp"
#include <iostream>

int main() {
    MarketData market;
    Portfolio portfolio(10000.0);

    while (true) {
        std::cout << "\n1. Check Price\n2. Place Order\n3. View Portfolio\n4. Exit\nChoice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string symbol;
            std::cout << "Enter symbol (e.g., BTCUSDT): ";
            std::cin >> symbol;
            PriceData data = market.getPrice(symbol);
            std::cout << symbol << " Price: " << data.price << "\n";
        } else if (choice == 2) {
            std::string symbol;
            double qty;
            int type;
            std::cout << "Symbol: ";
            std::cin >> symbol;
            std::cout << "Quantity: ";
            std::cin >> qty;
            std::cout << "0 for Buy, 1 for Sell: ";
            std::cin >> type;

            PriceData data = market.getPrice(symbol);
            Order order(symbol, static_cast<OrderType>(type), qty, data.price);
            portfolio.update(symbol, qty, data.price, order.type);
            std::cout << "Order placed!\n";
        } else if (choice == 3) {
            portfolio.display();
        } else if (choice == 4) {
            break;
        }
    }
    curl_global_cleanup();
    return 0;
}