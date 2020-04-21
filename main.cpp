#include <string>
#include <iostream>
#define orderSize 0
#define deliverySize 0
using namespace std;

class Order {
public:
    Order();
    Order(string newID, int newItem);
    void SetOrder(string ID, int items);
    string GetOrderID() const;
    int GetOrderItems() const;
    
private:
    string orderID;
    int orderItems;
    double price;
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
    
};

class WarehouseStack {
public:
    WarehouseStack();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(Order newOrder);
    
private:
    int top;
    Order orders[orderSize];
    Delivery deliveries[deliverySize];
    
};

int main() {
    
}

/*
 ******** ORDER CLASS ********
*/

Order::Order(){};

Order::Order(string newID, int newItems) {
    SetOrder(newID, newItems);
}

void Order::SetOrder(string ID, int items) {
    orderID = ID;
    orderItems = items;
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

WarehouseStack::WarehouseStack() { top = -1; };

bool WarehouseStack::IsEmpty() const {
    return top == -1;
}

bool WarehouseStack::IsFull() const {
    return top == orderSize - 1;
}

void WarehouseStack::Push(Order newOrder) {
    if (IsEmpty()) {
        <#statements#>
    }
}

// END WAREHOSUE STACK CLASS
