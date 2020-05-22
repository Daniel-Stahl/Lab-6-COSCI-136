#include "InventoryStackNode.hpp"
#include <string>
#include <iostream>

using namespace std;

class InventoryStack {
public:
    InventoryStack();
    bool IsEmpty() const;
    bool IsFull(InventoryStackNode* node) const;
    void Push(Deliveries newDelivery);
    void Pop();
    InventoryStackNode* Peek();
    
private:
    InventoryStackNode* head = nullptr;
    
};
