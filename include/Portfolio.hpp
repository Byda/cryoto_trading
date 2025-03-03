#ifndef PORTFOLIO_HPP
#define PORTFOLIO_HPP

#include <map>
#include <string>
#include "Order.hpp"

class Portfolio {
public:
    Portfolio(double initialBalance);
    void update(const std::string& asset, double quantity, double price, OrderType type);
    void display() const;
    double getBalance(const std::string& asset) const;

private:
    std::map<std::string, double> holdings;
};

#endif