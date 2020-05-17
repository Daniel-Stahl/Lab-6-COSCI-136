#include "Shipping.hpp"

Shipping::Shipping(){ sizeOfArray = -1; sizeOfDel = -1; }

void Shipping::DisplayShipments(int pos, int deliverySize) {
    int y;
    
    cout << "Order ID: " << shipping[pos].order.GetOrderID() << " items: " << shipping[pos].order.GetOrderItems() << " Missing: " << shipping[pos].order.GetQtyNotFilled() << "\n";
    
    for (y = 0; y <= deliverySize; y++) {
        cout << "Delivery ID: " << shipping[pos].deliveries[y].GetDeliveryID() << " QTY: " << shipping[pos].deliveries[y].GetDeliveryItems() << "\n";
    }
    
}

void Shipping::AddOrderToShippments(Order order, Deliveries delivery) {
    // Add order to shipping array
    
    //check if order is unique first
    // if it is then add order and delivery
    // if it is NOT unique then return order position and add delivery to order
    
    int position = 0;
    
    if (!IsOrderUnique(order, position)) {
        sizeOfArray += 1;
        sizeOfDel = 0;
        OrderShipped newShipment;
        newShipment.order = order;
        newShipment.deliveries[sizeOfDel] = delivery;
        shipping[sizeOfArray] = newShipment;
    } else {
        sizeOfDel += 1;
        shipping[position].order = order;
        shipping[position].deliveries[sizeOfDel] = delivery;
    }
    
    DisplayShipments(position, sizeOfDel);
    
//    int x = 0;
//    int y = 0;
//    for (x = 0; x <= sizeOfArray; x++) {
//        cout << "Order ID: " << shipping[x].order.GetOrderID() << " items: " << shipping[x].order.GetOrderItems() << " Missing: " << shipping[x].order.GetQtyNotFilled() << "\n";
//
//        for (y = 0; y <= sizeOfDel; y++) {
//            cout << "Delivery ID: " << shipping[x].deliveries[y].GetDeliveryID() << " QTY: " << shipping[x].deliveries[y].GetDeliveryItems() << "\n";
//        }
//    }
    
    
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
