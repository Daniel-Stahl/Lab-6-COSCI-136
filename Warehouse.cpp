#include "Warehouse.hpp"

void Warehouse::FillOrder(OrderStack& orders, InventoryStack& inventory) {
    orderNode = orders.Peek();
    int qtyMissing = orderNode->order.GetQtyNotFilled();
    Deliveries item = inventory.Peek();
    int items = item.GetDeliveryItems();
    int orderID = orderNode->order.GetOrderID();
    int totalShipped = 0;
    Deliveries testDelivery;
    arraySize = -1;
    Deliveries deliveriesUsed[10];
    
    
    while(!IsOrderFilled() && !inventory.IsEmpty()) {
        arraySize++;
        // exit loop when order is filled
        // when inventory is empty
        // order cant be filled
    
        testDelivery = item;
        
        if (qtyMissing >= items) {
            qtyMissing = qtyMissing - items;
            orderNode->order.SetQtyNotFilled(qtyMissing);
            inventory.Pop();
        } else if (qtyMissing < items) {
            items = items - qtyMissing;
            orderNode->order.SetQtyNotFilled(0);
            item.SetDeliveryItems(items);
            testDelivery.SetDeliveryItems(qtyMissing);
        }
        
        deliveriesUsed[arraySize] = testDelivery;
        totalShipped += testDelivery.GetDeliveryItems();
        
        
        if (!IsOrderFilled() && !inventory.IsEmpty()) {
            item = inventory.Peek();
            items = item.GetDeliveryItems();

        } else if(IsOrderFilled()) {
            cout << "Sending Order# " << orderID << " to shipping!\n";
            orders.Pop();
            // Order gets popped off the stack and exit
        } else {
            // Order isnt filled, but inventory is empty
            // put order back on stack and exit
            
        }
    }
    
    PrintOrderDetails(totalShipped, deliveriesUsed);
    
}

bool Warehouse::IsOrderFilled() const {
    if (orderNode->order.GetQtyNotFilled() == 0)
        return true;
    return false;
}

void Warehouse::PrintOrderDetails(int shipment, Deliveries deliveriesUsed[]) {
    double warehouseCost = 0;
    double customerCost = 0;
    
    for (int x = 0; x <= arraySize; x++) {
        warehouseCost += deliveriesUsed[x].GetCostPerItem() * deliveriesUsed[x].GetDeliveryItems();
        customerCost += ((deliveriesUsed[x].GetCostPerItem() * .5) + deliveriesUsed[x].GetCostPerItem()) * deliveriesUsed[x].GetDeliveryItems();
    }
    
    cout << "Order Number: " << orderNode->order.GetOrderID()
    << "\nQty to Ordered: " << orderNode->order.GetOrderItems()
    << "\nShipped this Shipment: " << shipment
    << "\nQty to be Shipped: " << orderNode->order.GetQtyNotFilled()
    << "\nTotal cost to the Warehouse: " << warehouseCost
    << "\nTotal cost to the Customer: " << customerCost
    << "\nProfit this Shipment: " << customerCost - warehouseCost
    << "\n";
    
    cout << "\nShipment Details:\n"
    << "Delivery #" << setw(15) << "Qty Shipped" << setw(15) << "Unit Price" << setw(25) << "Cost to the Warehouse" << setw(25) << setw(25) << "Cost to the Customer\n";
    
    for (int x = 0; x <= arraySize; x++) {
        cout << right << setw(10) << deliveriesUsed[x].GetDeliveryID() << setw(15) << deliveriesUsed[x].GetDeliveryItems() << setw(15) << deliveriesUsed[x].GetCostPerItem() << setw(25) << deliveriesUsed[x].GetCostPerItem() * deliveriesUsed[x].GetDeliveryItems() << setw(24) << ((deliveriesUsed[x].GetCostPerItem() * .5) + deliveriesUsed[x].GetCostPerItem()) * deliveriesUsed[x].GetDeliveryItems() << "\n";
    }
    
    cout << "\n";
}
