#include "Order.hpp"

struct OrderStackNode {
    Order order;
    OrderStackNode* next;
    OrderStackNode* prev;
};
