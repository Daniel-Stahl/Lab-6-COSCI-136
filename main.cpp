#include <string>
#include <iostream>
#include "Warehouse.hpp"

using namespace std;

void MainMenu();

int main() {
    
    MainMenu();

}

void MainMenu() {
    Warehouse warehouse;
    OrderStack orders;
    Order order;
    Order orderB;
    InventoryStack inventory;
    Deliveries deliveryA;
    Deliveries deliveryB;
    
   
    
    order.SetOrder(3);
    orders.Push(order);
    
    orderB.SetOrder(1);
    orders.Push(orderB);
    
    deliveryA.SetDeliveries(1, 2.00);
    inventory.Push(deliveryA);
    
    deliveryB.SetDeliveries(3, 2.00);
    inventory.Push(deliveryB);
    
    cout << "Main Menu\n 1) Create Order\n 2) Recieve Delivery\n 3) Fill Order\n";
    
    warehouse.FillOrder(orders, inventory);
    warehouse.FillOrder(orders, inventory);
    
    
}
