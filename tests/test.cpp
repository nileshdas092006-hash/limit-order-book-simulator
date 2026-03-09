#include "../include/order.h"
#include "../include/order_book.h"
#include<iostream>
#include <string>

int main(){
    OrderBook book;
    int id;
    std::string side;
    double price;
    int quantity;
    while (std::cin>>id>>side>>price>>quantity)
    {
        Side orderSide;
        if (side == "BUY"){
            orderSide = Side::BUY;
        }
        else
        {
            orderSide = Side::SELL;
        }
        Order newOrder(id, orderSide, price, quantity);
        book.addOrder(newOrder);
    }
    return 0;
}