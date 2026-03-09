#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include "order.h"
#include <queue>
#include <vector>

struct CompareBuy {
    bool operator()(const Order& a, const Order& b) {
        return a.price < b.price;
    }
};

struct CompareSell {
    bool operator()(const Order& a, const Order& b) {
        return a.price > b.price;
    }
};

class OrderBook {
private:
    std::priority_queue<Order, std::vector<Order>, CompareBuy> bids;
    std::priority_queue<Order, std::vector<Order>, CompareSell> asks;

public:
    void addOrder(const Order& order);
    void matchOrders();
};

#endif