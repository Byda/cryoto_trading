#include "Order.hpp"

Order::Order(const std::string& symbol, OrderType type, double quantity, double price)
    : symbol(symbol), type(type), quantity(quantity), price(price), status(PENDING) {}