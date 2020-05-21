#include "InventoryStack.hpp"

InventoryStack::InventoryStack() { top = -1; };

bool InventoryStack::IsEmpty() const {
    return top == -1;
};

bool InventoryStack::IsFull() const {
    return top == STACK_SIZE - 1;
};

void InventoryStack::Push(Deliveries newDelivery) {
    if (IsFull())
        cout << "Inventory is full\n";
    top++;
    inventory[top] = newDelivery;
};

void InventoryStack::Pop() {
    if (IsEmpty())
        cout << "Inventory is empty\n";
    top--;
};

Deliveries InventoryStack::Peek() {
    return inventory[top];
};





