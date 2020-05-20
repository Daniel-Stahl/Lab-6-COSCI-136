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
    int userChoice;
    
    do {

        cout << "Main Menu\n 1) Create Order\n 2) Recieve Delivery\n 3) Fill Order\n 4) Exit program\n Choice: ";
        cin >> userChoice;
        
        switch (userChoice) {
            case 1:
                // Create Order
                int numOfItems;
                
                cout << "\nHow many items ordered? ";
                cin >> numOfItems;
                
                order.SetOrder(numOfItems);
                orders.Push(order);
                
                break;
            case 2:
                // Recieve Delivery
                int itemRecieved;
                double itemCost;
                
                cout << "\nHow many items in delivery? ";
                cin >> itemRecieved;
                
                cout << "\nCost per item? ";
                cin >> itemCost;
                
                delivery.SetDeliveries(itemRecieved, itemCost);
                inventory.Push(delivery);
                
                break;
            case 3:
                // Fill order
                cout << "\nFilling order initiated\n";
                
                if (!orders.IsEmpty())
                    warehouse.FillOrder(orders, inventory);
                cout << "There are no more orders to fulfill\n";
                
                
                 
                break;
            default:
                break;
        }
        
    } while (userChoice != 4);
    
    
}
