#include "Order.hpp"

Order::Order(){qty = 0; orderPrice = 0;};

Order::Order(int newItems) {
    SetOrder(newItems);
}

void Order::SetOrder(int items) {
    orderID = GenerateOrderID();
    qtyNotFilled = items;
}

int Order::GetOrderID() const {
    return orderID;
}

int Order::GetOrderItems() const {
    return qty;
}

int Order::GetOrderPrice() const {
    return orderPrice;
}

int Order::GetQtyNotFilled() const {
    return qtyNotFilled;
}

void Order::SetOrderQty(int newQty) {
    qty += newQty;
}

void Order::SetOrderPrice(double newPrice) {
    orderPrice += newPrice;
}

void Order::SetQtyNotFilled(int missing) {
    qtyNotFilled = missing;
}

int Order::GenerateOrderID() {
    static int num = 0;
    return ++num;
}
