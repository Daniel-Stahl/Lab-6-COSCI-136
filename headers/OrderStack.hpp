#include "Order.hpp"
#include <iostream>
#include <string>
#define stackSize 10

using namespace std;

class OrderStack {
public:
    OrderStack();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(Order newOrder);
    //pop
    //peak

private:
    int top;
    Order orders[stackSize];
    
};

