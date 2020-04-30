#include "Order.hpp"

Order::Order(){orderID = 0;};

Order::Order(int newItems, double newPrice) {
    SetOrder(newItems, newPrice);
}

void Order::SetOrder(int items, double price) {
    orderID = GenerateOrderID();
    qtyNotFilled = items;
    orderPrice = price;
}

int Order::GetOrderID() const {
    return orderID;
};

int Order::GetOrderItems() const {
    return qty;
};

int Order::GetOrderPrice() const {
    return orderPrice;
};

int Order::GetQtyNotFilled() const {
    return qtyNotFilled - qty;
};

void Order::SetOrderQty(int newQty) {
    qty += newQty;
};

int Order::GenerateOrderID() {
    return orderID + 1;
};
