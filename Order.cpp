#include "Order.hpp"

Order::Order(){};

Order::Order(string newID, int newItems, double newPrice) {
    SetOrder(newID, newItems, newPrice);
}

void Order::SetOrder(string ID, int items, double price) {
    orderID = ID; // Set id automatically
    orderItems = items;
    orderPrice = price;
}

string Order::GetOrderID() const {
    return orderID;
};

int Order::GetOrderItems() const {
    return orderItems;
};
