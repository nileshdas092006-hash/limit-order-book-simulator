#ifndef ORDER_H
#define ORDER_H

enum class Side {
    BUY,
    SELL
};

struct Order {
    int id;
    Side side;
    double price;
    int quantity;

    Order(int id, Side side, double price, int quantity)
        : id(id), side(side), price(price), quantity(quantity) {}
};

#endif