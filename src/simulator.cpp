#include "../include/order.h"
#include "../include/order_book.h"
#include <iostream>
#include <random>

int main()
{

    OrderBook book;

    double mid_price = 100.0;
    int id = 1;
    int num_of_orders = 100;

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> side_dist(0, 1);
    std::normal_distribution<double> price_noise(0.0, 1.0);
    std::uniform_int_distribution<int> qty_dist(1, 10);

    for (int i = 0; i < num_of_orders; i++)
    {

        int side_random = side_dist(generator);

        Side orderSide;

        if (side_random == 0)
            orderSide = Side::BUY;
        else
            orderSide = Side::SELL;

        double noise = price_noise(generator);
        double price = mid_price + noise;

        int quantity = qty_dist(generator);

        Order newOrder(id, orderSide, price, quantity);

        if (orderSide == Side::BUY)
            std::cout << "Generated BUY ";
        else
            std::cout << "Generated SELL ";

        std::cout << "@ " << price << " qty " << quantity << std::endl;

        book.addOrder(newOrder);

        id++;
    }

    return 0;
}