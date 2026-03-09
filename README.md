# Limit Order Book Simulator (C++)

A simplified simulation of an electronic **Limit Order Book (LOB)** and matching engine written in **C++**.
This project models how modern electronic exchanges match buy and sell orders using price–time priority.

The simulator generates random orders and feeds them into the order book, where a matching engine executes trades whenever the best bid crosses the best ask.

---

## Key Concepts Demonstrated

* Limit Order Book data structure
* Matching engine logic
* Event-driven order processing
* Priority queues for bid/ask management
* Partial order fills
* Randomized market simulation

This project is inspired by the core mechanics used in **electronic trading systems and quantitative trading infrastructure**.

---

## Project Structure

```
limit-order-book-simulator

include/
    order.h
    order_book.h

src/
    order_book.cpp
    simulator.cpp

tests/
    test.cpp

README.md
```

### Folder Description

**include/**
Core data structures and class definitions.

**src/**
Implementation of the matching engine and simulation logic.

**tests/**
Manual testing program for entering orders via standard input.

---

## How the Matching Engine Works

The order book maintains two priority queues:

**Bids (Buy Orders)**
Highest price has highest priority.

**Asks (Sell Orders)**
Lowest price has highest priority.

When a new order arrives:

```
if best_bid >= best_ask
    execute trade
```

Trade quantity:

```
min(bid_quantity, ask_quantity)
```

Orders are updated or removed depending on the remaining quantity.

---

## Market Simulation

The simulator generates random market orders using statistical distributions:

* **Side:** Uniform distribution (BUY / SELL)
* **Price:** Normal distribution around a reference mid-price
* **Quantity:** Uniform distribution between 1 and 10

Price model:

```
price = mid_price + noise
noise ~ Normal(0, σ)
```

This produces realistic fluctuations around the reference price.

---

## Example Output

```
Generated SELL @ 99.48 qty 6
Generated BUY @ 100.08 qty 8
Trade executed: 7 @ 99.07
Trade executed: 1 @ 99.48
Generated BUY @ 100.26 qty 4
Trade executed: 4 @ 99.48
```

---

## How to Compile

Compile the simulator:

```
g++ src/order_book.cpp src/simulator.cpp -o simulator
```

Run the simulation:

```
./simulator
```

---

## Manual Testing

Compile the test driver:

```
g++ src/order_book.cpp tests/test.cpp -o engine
```

Run:

```
./engine
```

Example input:

```
1 BUY 100 5
2 SELL 100 3
```

Output:

```
Trade executed: 3 @ 100
```

---

## Future Improvements

* Market maker strategy
* Inventory tracking
* Profit & Loss (PnL) calculation
* Order cancellation support
* Price-level order book implementation
* Performance benchmarking

---

## Learning Outcomes

Through this project I explored:

* Order matching algorithms
* Market microstructure fundamentals
* Event-driven system design
* C++ STL data structures for trading systems
* Simulation of financial markets

---

## Author

Nilesh Das
BTech CSE — IIT Guwahati
