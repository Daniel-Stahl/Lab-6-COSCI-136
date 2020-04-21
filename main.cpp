#include <string>
#include <iostream>
#define stackSize 10
using namespace std;

class Order {
public:
    Order();
    Order(string newID, int newItem, double newPrice);
    void SetOrder(string ID, int items, double price);
    string GetOrderID() const;
    int GetOrderItems() const;
    
private:
    string orderID;
    int orderItems;
    double orderPrice;
};

class Delivery {
public:
    Delivery();
    Delivery(string newID, int newItems);
    void SetDelivery(string ID, int items);
    string GetDeliveryID() const;
    int GetDeliveryItems() const;

private:
    string deliveryID;
    int deliveryItems;
    double cost;
    double total;
    
};

class Inventory {
public:
    Inventory();
    Inventory(int numItems, double newPrice);
    void SetInventory(int items, double price);
    
private:
    int numItems;
    double cost;
    
};

class OrdersStack {
public:
    OrdersStack();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(Order newOrder);
    
private:
    int top;
    Order orders[stackSize];
    
};

class ItemStack {
    
};

int main() {
    
}

/*
 ******** ORDER CLASS ********
*/

Order::Order(){};

Order::Order(string newID, int newItems, double newPrice) {
    SetOrder(newID, newItems, newPrice);
}

void Order::SetOrder(string ID, int items, double price) {
    orderID = ID;
    orderItems = items;
    orderPrice = price;
}

string Order::GetOrderID() const {
    return orderID;
};

int Order::GetOrderItems() const {
    return orderItems;
};

// END ORDER CLASS

/*
 ******** DELIVERY CLASS *********
*/

Delivery::Delivery(){};

Delivery::Delivery(string newID, int newItems) {
    SetDelivery(newID, newItems);
};

void Delivery::SetDelivery(string ID, int items) {
    deliveryID = ID;
    deliveryItems = items;
};

string Delivery::GetDeliveryID() const {
    return deliveryID;
};

int Delivery::GetDeliveryItems() const {
    return deliveryItems;
};

// END DELIVERY CLASS

/*
 ******* WAREHOUSE STACK CLASS *******
*/

OrdersStack::OrdersStack() { top = -1; };

bool OrdersStack::IsEmpty() const {
    return top == -1;
}

bool OrdersStack::IsFull() const {
    return top == stackSize - 1;
}

void OrdersStack::Push(Order newOrder) {
    if (IsFull()) {
        cout << "Cant add anymore orders to the stack\n";
    } else {
        top++;
        orders[top] = newOrder;
    }
}

// END WAREHOSUE STACK CLASS
