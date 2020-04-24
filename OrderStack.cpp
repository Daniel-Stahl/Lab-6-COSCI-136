#include "OrderStack.hpp"

OrderStack::OrderStack() {
    top = -1;
};

bool OrderStack::IsEmpty() const {
    return top == -1;
}

bool OrderStack::IsFull() const {
    return top == STACK_SIZE - 1;
}

void OrderStack::Push(Order newOrder) {
    if (IsFull()) {
        cout << "Cant add anymore orders to the stack\n";
    } else {
        top++;
        orders[top] = newOrder;
    }
}

void OrderStack::Pop() {
    if (IsEmpty())
        cout << "Stack is empty\n";
    top--;
};

Order OrderStack::Peek() {
    if (IsEmpty())
        cout << "Stack is empty\n";
    return orders[top];
};
