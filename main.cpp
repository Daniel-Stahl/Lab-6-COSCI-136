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

        cout << "Main Menu\n 1) Create Order\n 2) Recieve Delivery\n 3) Fill Order\n 4) Print orders\n 5) Exit Program\n Choice: ";
        cin >> userChoice;
        
        switch (userChoice) {
            case 1:
                // Create Order
                warehouse.AddOrderToStack();
                
                break;
            case 2:
                // Recieve Delivery
                warehouse.AddDeliveryToStack();
                
                break;
            case 3:
                // Fill order
                warehouse.FillOrder();

                break;
            case 4:
                // Print orders in stack
                warehouse.PrintOrders();
                
                break;
            default:
                break;
        }
        
    } while (userChoice != 5);
    
    
}
