#include "OrderStackNode.hpp"
#include <iostream>
#include <string>

using namespace std;

class OrderStack {
public:
    OrderStack();
    bool IsEmpty() const;
    bool IsFull(OrderStackNode* node) const;
    void Push(Order newOrder);
    void Pop();
    OrderStackNode* Peek();
    
private:
    OrderStackNode* head = nullptr;
    OrderStackNode* tail = nullptr;
};

