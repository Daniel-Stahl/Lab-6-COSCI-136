#include <string>
#include <iostream>
#include "OrderStack.hpp"
#include "InventoryStack.hpp"

using namespace std;

int main() {
    OrderStack orderStack;
    Order order;
    InventoryStack inventory;
    Deliveries deliveries;
    int numItems;
    double price = 0.0;
    int x = 0;
    
    while (x < 11) {
        numItems = x;
        price = 1.0 + price;
        order.SetOrder(numItems, price);
        deliveries.SetDeliveries(numItems + 10, (price + 3) * 3);
        orderStack.Push(order);
        inventory.Push(deliveries);
        x++;
    }
    
    Order orderA = orderStack.Peek();
    
    cout << "Order ID " << orderA.GetOrderID() << "\n";
    cout << "Number of items " << orderA.GetOrderItems() << "\n";
    cout << "Cost per item " << orderA.GetOrderPrice() << "\n";
    
    orderStack.Pop();
    
    Order orderB = orderStack.Peek();
    cout << "\nOrder ID " << orderB.GetOrderID() << "\n";
    cout << "Number of items " << orderB.GetOrderItems() << "\n";
    cout << "Cost per item " << orderB.GetOrderPrice() << "\n";
    
    Deliveries deliveryA = inventory.Peek();
    
    cout << "\nDelivery ID " << deliveryA.GetDeliveryID() << "\n";
    cout << "Number of items " << deliveryA.GetDeliveryItems() << "\n";
    cout << "Cost per item " << deliveryA.GetCostPerItem() << "\n";
    
    inventory.Pop();
    
    Deliveries deliveryB = inventory.Peek();
    cout << "\nDelivery ID " << deliveryB.GetDeliveryID() << "\n";
    cout << "Number of items " << deliveryB.GetDeliveryItems() << "\n";
    cout << "Cost per item " << deliveryB.GetCostPerItem() << "\n";
    

    
    
    
    
    
    
}

