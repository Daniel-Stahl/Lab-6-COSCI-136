#include "OrderStack.hpp"

OrderStack::OrderStack() {
    top = -1;
};

bool OrderStack::IsEmpty() const {
    return top == -1;
}

bool OrderStack::IsFull() const {
    return top == stackSize - 1;
}

void OrderStack::Push(Order newOrder) {
    if (IsFull()) {
        cout << "Cant add anymore orders to the stack\n";
    } else {
        top++;
        orders[top] = newOrder;
    }
}
