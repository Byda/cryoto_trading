#ifndef MARKET_DATA_HPP
#define MARKET_DATA_HPP

#include <string>

struct PriceData {
    std::string symbol;
    double price;
};

class MarketData {
public:
    MarketData();
    PriceData getPrice(const std::string& symbol);
};

#endif