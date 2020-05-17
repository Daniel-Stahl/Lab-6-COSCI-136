//#include "Shipping.hpp"
//
//Shipping::Shipping(){ sizeOfArray = -1; sizeOfDel = -1; }
//
//void Shipping::DisplayShipments(int pos, int deliverySize) {
//    int y;
//    
//    cout << "Order Number: " << shipping[pos].order.GetOrderID()
//    << "\nQty to Ordered: " << shipping[pos].order.GetOrderItems()
//    << "\nShipped this Shipment: " << shipping[pos].order.GetQtyNotFilled()
//    << "\nQty to be Shipped: "
//    << "\nTotoal cost to the Warehouse: "
//    << "\nTotal cost to the Customer: "
//    << "\nProfit this Shipment: "
//    << "\n";
//    
//    cout << "Shipment Details:\n"
//    << "Delivery #" << "Qty Shipped" << "Unit Price" << "Cost to the Warehouse" << "Cost to the Customer\n";
//    for (y = 0; y <= deliverySize; y++) {
//        cout << shipping[pos].deliveries[y].GetDeliveryID() << shipping[pos].deliveries[y].GetDeliveryItems() << "\n";
//    }
//    
//}
//
//void Shipping::AddDeliveryToShipment(Order order, Deliveries delivery) {
//    // Add order to shipping array
//    
//    //check if order is unique first
//    // if it is then add order and delivery
//    // if it is NOT unique then return order position and add delivery to order
//    
//    
//    if (!IsOrderUnique(order)) {
//        sizeOfArray += 1;
//        sizeOfDel = 0;
//        OrderShipped newShipment;
//        newShipment.order = order;
//        newShipment.deliveries[sizeOfDel] = delivery;
//        shipping[sizeOfArray] = newShipment;
//    } else {
//        sizeOfDel += 1;
//        shipping[sizeOfArray].order = order;
//        shipping[sizeOfArray].deliveries[sizeOfDel] = delivery;
//    }
//    
//    DisplayShipments(sizeOfArray, sizeOfDel);
//    
//}
//
//// Check if order exists in array
//
//bool Shipping::IsOrderUnique(Order order) {
//    int orderID = order.GetOrderID();
//    int x = 0;
//    bool found = false;
//    
//    while (!found && x <= sizeOfArray) {
//        if (orderID == shipping[x].order.GetOrderID()) {
//            found = true;
//        }
//        
//        x++;
//    }
//    
//    return found;
//}
