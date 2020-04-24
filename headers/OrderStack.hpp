#include "Order.hpp"
#include <iostream>
#include <string>
#define STACK_SIZE 10

using namespace std;

class OrderStack {
public:
    
    OrderStack();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(Order newOrder);
    void Pop();
    Order Peek();
    
private:
    
    int top;
    Order orders[STACK_SIZE];
    
};

