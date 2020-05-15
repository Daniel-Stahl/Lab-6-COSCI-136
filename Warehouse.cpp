#include "Warehouse.hpp"

void Warehouse::FillOrder(OrderStack& orders, InventoryStack& inventory) {
    Order order = orders.Peek();
    int qtyMissing = order.GetQtyNotFilled();
    
    
    Deliveries testDelivery;
    
    while(!IsOrderFilled(order) && !inventory.IsEmpty()) {
        // exit loop when order is filled
        // when inventory is empty
        // order cant be filled
        
        
        Deliveries item = inventory.Peek();
        int items = item.GetDeliveryItems();
        
        
        
    
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
            item.SetDeliveryItems(items);
            
            
            testDelivery.SetDeliveryItems(qtyMissing);
            
            shipping.AddOrderToShippments(order, testDelivery);
            
            
            
            
            
        }
        
//        if (!IsOrderFilled(order) && inventory.IsEmpty()) {
//            cout << "Order needs " << qtyMissing << " more items\n";
//
//        } else {
//            cout << "Sending Order to shipping!\n";
//            shipping.AddOrderToShippments(order, item);
//            orders.Pop();
//        }
    };
    
}

bool Warehouse::IsOrderFilled(Order order) const {
    if (order.GetQtyNotFilled() == order.GetOrderItems())
        return true;
    return false;
}

void Warehouse::SendOrderToShipping(Order order) {
    
}
