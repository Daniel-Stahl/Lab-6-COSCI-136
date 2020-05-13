#include "Shipping.hpp"

Shipping::Shipping(){ sizeOfArray = -1; }

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
        
        OrderShipped newShipment;
        newShipment.order = order;
        newShipment.deliveries[sizeOfArray] = delivery;
        shipping[sizeOfArray] = newShipment;
    } else {
        shipping[position].deliveries[sizeOfArray] = delivery;
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
