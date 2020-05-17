#include "Warehouse.hpp"

void Warehouse::FillOrder(OrderStack& orders, InventoryStack& inventory) {
    Order order = orders.Peek();
    int qtyMissing = order.GetQtyNotFilled();
    Deliveries item = inventory.Peek();
    int items = item.GetDeliveryItems();
    int orderID = order.GetOrderID();
    
    Deliveries testDelivery;
    
    while(!IsOrderFilled(order) && !inventory.IsEmpty()) {
        // exit loop when order is filled
        // when inventory is empty
        // order cant be filled
    
        testDelivery = item;
        
        if (qtyMissing >= items) {
            qtyMissing = qtyMissing - items;
            order.SetOrderQty(items);
            order.SetQtyNotFilled(qtyMissing);
            shipping.AddOrderToShippments(order, testDelivery);
            inventory.Pop();
        } else if (qtyMissing < items) {
            items = items - qtyMissing;
            order.SetOrderQty(qtyMissing);
            order.SetQtyNotFilled(0);
            item.SetDeliveryItems(items);
            
            
            
            testDelivery.SetDeliveryItems(qtyMissing);
            shipping.AddOrderToShippments(order, testDelivery);
              
        }
        
        if (!IsOrderFilled(order) && !inventory.IsEmpty()) {
            cout << "Order# " << orderID << " needs " << qtyMissing << " more item(s)\n";
            // Grab new item
            item = inventory.Peek();
            items = item.GetDeliveryItems();

        } else if(IsOrderFilled(order) && !inventory.IsEmpty()) {
            cout << "Sending Order# " << orderID << " to shipping!\n";
            orders.Pop();
            // Order gets popped off the stack and exit
        } else {
            // Order isnt filled, but inventory is empty
            // put order back on stack and exit
            
        }
    };
    
}

bool Warehouse::IsOrderFilled(Order order) const {
    if (order.GetQtyNotFilled() == 0)
        return true;
    return false;
}

void Warehouse::SendOrderToShipping(Order order) {
    
}
