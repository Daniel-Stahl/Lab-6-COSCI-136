#include <string>
#include <iostream>
#include "OrderStack.hpp"
#include "Order.hpp"

using namespace std;

int main() {
    OrderStack orderStack;
    Order order;
    int numItems;
    double price;
    string id;
    
    cout << "Number of items: ";
    cin >> numItems;
    
    cout << "Price: ";
    cin >> price;
    
    cout << "ID: ";
    cin >> id;
    
    order.SetOrder(id, numItems, price);
    orderStack.Push(order);
    
    
    
}

