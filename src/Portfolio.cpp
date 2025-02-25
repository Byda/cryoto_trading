#include "Portfolio.hpp"
#include <iostream>

Portfolio::Portfolio(double initialBalance) {
    holdings["USDT"] = initialBalance;
}

void Portfolio::update(const std::string& asset, double quantity, double price, OrderType type) {
    if (type == BUY) {
        holdings[asset] += quantity;
        holdings["USDT"] -= quantity * price;
    } else {
        holdings[asset] -= quantity;
        holdings["USDT"] += quantity * price;
    }
}

void Portfolio::display() const {
    std::cout << "Portfolio:\n";
    for (const auto& [asset, amount] : holdings) {
        std::cout << asset << ": " << amount << "\n";
    }
}

double Portfolio::getBalance(const std::string& asset) const {
    auto it = holdings.find(asset);
    return (it != holdings.end()) ? it->second : 0.0;
}