#include "Order.hpp"

Order::Order(){};

Order::Order(int newItems) {
    SetOrder(newItems);
}

void Order::SetOrder(int items) {
    orderID = GenerateOrderID();
    qtyNotFilled = items;
    qty = items;
}

int Order::GetOrderID() const {
    return orderID;
}

int Order::GetOrderItems() const {
    return qty;
}

int Order::GetQtyNotFilled() const {
    return qtyNotFilled;
}

void Order::SetQtyNotFilled(int missing) {
    qtyNotFilled = missing;
}

int Order::GenerateOrderID() {
    static int num = 0;
    return ++num;
}
