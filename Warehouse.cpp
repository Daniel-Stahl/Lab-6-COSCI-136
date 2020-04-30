#include "Warehouse.hpp"

void Warehouse::FillOrder(OrderStack& orders, InventoryStack& inventory) {
    Order order = orders.Peek();
    Deliveries item = inventory.Peek();
    int items = item.GetDeliveryItems();
    int qtyMissing = order.GetQtyNotFilled();
    
    
    
    while(!IsOrderFilled(order) && !inventory.IsEmpty()) {
        // exit loop when order is filled
        // when inventory is empty
        // order cant be filled
    
        if (qtyMissing >= items) {
            qtyMissing = qtyMissing - items;
            order.SetOrderQty(items);
            inventory.Pop();
        } else if (qtyMissing < items) {
            items = items - qtyMissing;
            order.SetOrderQty(qtyMissing);
            item.SetDeliveryItems(items);
                
            // Send order to shipping
        }
        
        if (order.GetQtyNotFilled() != order.GetOrderItems() && inventory.IsEmpty()) {
            cout << "Order needs " << qtyMissing << " more items\n";
            Order orderTemp = order;
            orders.Pop();
            orders.Push(orderTemp);
        } else {
            cout << "Order filled!\n";
        }
    };
    
};

bool Warehouse::IsOrderFilled(Order order) const {
    if (order.GetQtyNotFilled() == order.GetOrderItems())
        return true;
    return false;
}