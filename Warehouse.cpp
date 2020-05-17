#include "Warehouse.hpp"

void Warehouse::FillOrder(OrderStack& orders, InventoryStack& inventory) {
    Order order = orders.Peek();
    int qtyMissing = order.GetQtyNotFilled();
    Deliveries item = inventory.Peek();
    int items = item.GetDeliveryItems();
    int orderID = order.GetOrderID();
    int totalShipped = 0;
    Deliveries testDelivery;
    arraySize = -1;
    Deliveries deliveriesUsed[10];
    
    
    while(!IsOrderFilled(order) && !inventory.IsEmpty()) {
        arraySize++;
        // exit loop when order is filled
        // when inventory is empty
        // order cant be filled
    
        testDelivery = item;
        
        if (qtyMissing >= items) {
            qtyMissing = qtyMissing - items;
            order.SetQtyNotFilled(qtyMissing);
            inventory.Pop();
        } else if (qtyMissing < items) {
            items = items - qtyMissing;
            order.SetQtyNotFilled(0);
            item.SetDeliveryItems(items);
            testDelivery.SetDeliveryItems(qtyMissing);
        }
        
        deliveriesUsed[arraySize] = testDelivery;
        totalShipped += testDelivery.GetDeliveryItems();
        
        
        if (!IsOrderFilled(order) && !inventory.IsEmpty()) {
            //cout << "Order# " << orderID << " needs " << qtyMissing << " more item(s)\n";
            
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
    }
    
    PrintOrderDetails(order, totalShipped, deliveriesUsed);
    
}

bool Warehouse::IsOrderFilled(Order order) const {
    if (order.GetQtyNotFilled() == 0)
        return true;
    return false;
}

void Warehouse::PrintOrderDetails(Order order, int shipment, Deliveries deliveriesUsed[]) {
    double warehouseCost = 0;
    double customerCost = 0;
    
    for (int x = 0; x <= arraySize; x++) {
        warehouseCost += deliveriesUsed[x].GetCostPerItem() + deliveriesUsed[x].GetDeliveryItems();
        customerCost += ((deliveriesUsed[x].GetCostPerItem() * .5) + deliveriesUsed[x].GetCostPerItem()) * deliveriesUsed[x].GetDeliveryItems();
    }
    
    cout << "Order Number: " << order.GetOrderID()
    << "\nQty to Ordered: " << order.GetOrderItems()
    << "\nShipped this Shipment: " << shipment
    << "\nQty to be Shipped: " << order.GetQtyNotFilled()
    << "\nTotal cost to the Warehouse: " << warehouseCost
    << "\nTotal cost to the Customer: " << customerCost
    << "\nProfit this Shipment: " << customerCost - warehouseCost
    << "\n";
    
    cout << "Shipment Details:\n"
    << "Delivery #" << setw(15) << "Qty Shipped" << setw(15) << "Unit Price" << setw(15) << "Cost to the Warehouse" << setw(15) << setw(15) << "Cost to the Customer\n";
    
    for (int x = 0; x <= arraySize; x++) {
        cout << right << deliveriesUsed[x].GetDeliveryID() << setw(15) << deliveriesUsed[x].GetDeliveryItems() << setw(15) << deliveriesUsed[x].GetCostPerItem() << setw(15) << deliveriesUsed[x].GetCostPerItem() * deliveriesUsed[x].GetDeliveryItems() << setw(15) << ((deliveriesUsed[x].GetCostPerItem() * .5) + deliveriesUsed[x].GetCostPerItem()) * deliveriesUsed[x].GetDeliveryItems() << "\n";
    }
    
    
}
