#include "../include/order_book.h"
#include <iostream>

void OrderBook::addOrder(const Order &order)
{
    if (order.side == Side::BUY)
    {
        bids.push(order);
    }
    else
    {
        asks.push(order);
    }

    matchOrders();
}

void OrderBook::matchOrders()
{
    while (!bids.empty() && !asks.empty())
    {

        Order topBid = bids.top();
        Order topAsk = asks.top();

        if (topBid.price < topAsk.price)
            break;

        int tradeQty = std::min(topBid.quantity, topAsk.quantity);
        double tradePrice = topAsk.price;

        std::cout << "Trade executed: "
                  << tradeQty << " @ "
                  << tradePrice << std::endl;

        bids.pop();
        asks.pop();

        topBid.quantity -= tradeQty;
        topAsk.quantity -= tradeQty;

        if (topBid.quantity > 0)
            bids.push(topBid);

        if (topAsk.quantity > 0)
            asks.push(topAsk);
    }
}