#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>

enum OrderType { BUY, SELL };
enum OrderStatus { PENDING, FILLED, CANCELLED };

class Order {
public:
    Order(const std::string& symbol, OrderType type, double quantity, double price = 0.0);
    std::string symbol;
    OrderType type;
    double quantity;
    double price;
    OrderStatus status;
};

#endif