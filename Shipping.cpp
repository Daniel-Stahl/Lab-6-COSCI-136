#include "Shipping.hpp"

Shipping::Shipping(){ sizeOfArray = -1; sizeOfDel = -1; }

void Shipping::DisplayShipments() {
    
    
    
    // Show data like this
   /* Delivery #    Qty Shipped    Unit Price    Cost to the Warehouse    Cost to the Customer
           621              5           2.5                     12.5                   18.75
           620              3          1.75                     5.25                    7.88
           619              2          5.25                     10.5                   15.75
   */
}

void Shipping::AddOrderToShippments(Order order, Deliveries delivery) {
    // Add order to shipping array
    
    //check if order is unique first
    // if it is then add order and delivery
    // if it is NOT unique then return order position and add delivery to order
    
    int position;
    sizeOfArray += 1;
    
    
    if (!IsOrderUnique(order, position)) {
        sizeOfDel = 0;
        OrderShipped newShipment;
        newShipment.order = order;
        newShipment.deliveries[sizeOfDel] = delivery;
        shipping[sizeOfArray] = newShipment;
    } else {
        sizeOfDel += 1;
        shipping[position].deliveries[sizeOfDel] = delivery;
    }
    
    
    
    
    int x = 0;
    
    for (x = 0; x < sizeOfDel; x++) {
        cout << "Order ID: " << shipping[sizeOfArray].order.GetOrderID() << " items: " << shipping[sizeOfArray].order.GetOrderItems() << "\n" << "Delivery ID: " << shipping[sizeOfArray].deliveries[x].GetDeliveryID() << " QTY: " << shipping[sizeOfArray].deliveries[x].GetDeliveryItems() << "\n";
    }
    
    
}

// Check if order exists in array

bool Shipping::IsOrderUnique(Order order, int& arrayPos) {
    int orderID = order.GetOrderID();
    int x = 0;
    bool found = false;
    
    while (!found && x <= sizeOfArray) {
        if (orderID == shipping[x].order.GetOrderID()) {
            found = true;
            arrayPos = x;
        }
        
        x++;
    }
    
    return found;
}
