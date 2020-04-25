#include "Deliveries.hpp"
#include <string>
#include <iostream>
#define STACK_SIZE 10

using namespace std;

class InventoryStack {
public:
    InventoryStack();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(Deliveries newDelivery);
    void Pop();
    Deliveries Peek();
    
private:
    int top;
    Deliveries inventory[STACK_SIZE];
    
};
