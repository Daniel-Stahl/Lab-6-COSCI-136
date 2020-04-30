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
    InventoryStack inventory;
    Deliveries delivery;
    
    order.SetOrder(3, 1.50);
    orders.Push(order);
    
    order.SetOrder(11, 1.50);
    orders.Push(order);
    
    delivery.SetDeliveries(10, 2.00);
    inventory.Push(delivery);
    
    Order orderA = orders.Peek();
    
    cout << "Main Menu\n 1) Create Order\n 2) Recieve Delivery\n 3) Fill Order\n";
    
    cout << "Orders: " << orderA.GetQtyNotFilled() << "\n";
    
    warehouse.FillOrder(orders, inventory);
    
    cout << "Orders: " << orderA.GetQtyNotFilled() << "\n";
    
    //warehouse.FillOrder(orders, inventory);
    
    Order orderB = orders.Peek();
    
    cout << "Orders: " << orderB.GetQtyNotFilled() << "\n";
}
