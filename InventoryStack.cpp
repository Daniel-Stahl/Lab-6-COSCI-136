#include "InventoryStack.hpp"

InventoryStack::InventoryStack() {};

bool InventoryStack::IsEmpty() const {
    return head == nullptr;
};

bool InventoryStack::IsFull(InventoryStackNode* node) const {
    if (!node) {
        return true;
    } else {
        return false;
    }
};

void InventoryStack::Push(Deliveries newDelivery) {
    InventoryStackNode* newNode = new (std::nothrow) InventoryStackNode;
    
    if (!IsFull(newNode)) {
        newNode->delivery = newDelivery;
        newNode->next = nullptr;
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    } else {
        cout << "Cant add anymore orders to the stack, low on memory\n";
    }
};

void InventoryStack::Pop() {
    if (!IsEmpty()) {
        InventoryStackNode* topNode = head;
        head = topNode->next;
        delete topNode;
    } else {
       cout << "Inventory is empty\n";
    }
};

InventoryStackNode* InventoryStack::Peek() {
    if (IsEmpty()) {
        cout << "Inventory is empty\n";
        return nullptr;
    } else {
        return head;
    }
};
