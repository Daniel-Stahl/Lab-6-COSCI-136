#include <string>
#include <iostream>
#include "OrderStack.hpp"

using namespace std;

int main() {
    OrderStack orderStack;
    Order order;
    int numItems;
    double price = 0.0;
    int x = 0;
    
    while (x < 10) {
        numItems = x;
        price = 1.0 + price;
        order.SetOrder(numItems, price);
        orderStack.Push(order);
        x++;
    }
    
    Order orderA = orderStack.Peek();
    
    
    cout << orderA.GetOrderID() << "\n";
    orderStack.Pop();
    
    Order orderB = orderStack.Peek();
    cout << orderB.GetOrderID() << "\n";
    
    //order.SetOrder(id, numItems, price);
    
    
    
    
}

