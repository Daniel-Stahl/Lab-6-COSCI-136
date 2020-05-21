#include "Warehouse.hpp"

void Warehouse::FillOrder(OrderStack& orders, InventoryStack& inventory) {
    orderNode = orders.Peek();
    deliveryNode = inventory.Peek();
    int qtyMissing = orderNode->order.GetQtyNotFilled();
    int deliveryItems = deliveryNode->delivery.GetDeliveryItems();
    int orderID = orderNode->order.GetOrderID();
    InventoryStackNode* tempDeliveryNode;
    InventoryStackNode* deliveryUsed;
    
    while(!IsOrderFilled() && !inventory.IsEmpty()) {
        // exit loop when order is filled
        // when inventory is empty
        // order cant be filled
    
        tempDeliveryNode = deliveryNode;
        
        if (qtyMissing >= deliveryItems) {
            qtyMissing = qtyMissing - deliveryItems;
            orderNode->order.SetQtyNotFilled(qtyMissing);
            inventory.Pop();
        } else if (qtyMissing < deliveryItems) {
            deliveryNode->delivery.SetDeliveryItems(deliveryItems - qtyMissing);
            orderNode->order.SetQtyNotFilled(0);
            tempDeliveryNode->delivery.SetDeliveryItems(qtyMissing);
        }
        
        deliveryUsed = tempDeliveryNode;
        deliveryUsed->next = deliveryHead;
        deliveryHead = deliveryUsed;
        totalShipped += tempDeliveryNode->delivery.GetDeliveryItems();
        
        warehouseCost += tempDeliveryNode->delivery.GetCostPerItem() * tempDeliveryNode->delivery.GetDeliveryItems();
        customerCost += ((tempDeliveryNode->delivery.GetCostPerItem() * .5) + tempDeliveryNode->delivery.GetCostPerItem()) * tempDeliveryNode->delivery.GetDeliveryItems();
        
        
        if (!IsOrderFilled() && !inventory.IsEmpty()) {
            deliveryNode = inventory.Peek();
            deliveryItems = deliveryNode->delivery.GetDeliveryItems();

        } else if(IsOrderFilled()) {
            cout << "Sending Order# " << orderID << " to shipping!\n";
            orders.Pop();
            // Order gets popped off the stack and exit
        } else {
            // Order isnt filled, but inventory is empty
            // put order back on stack and exit
            
        }
    }
    
    PrintOrderDetails();
    
}

bool Warehouse::IsOrderFilled() const {
    if (orderNode->order.GetQtyNotFilled() == 0)
        return true;
    return false;
}

void Warehouse::PrintOrderDetails() {
    
    cout << "Order Number: " << orderNode->order.GetOrderID()
    << "\nQty to Ordered: " << orderNode->order.GetOrderItems()
    << "\nShipped this Shipment: " << totalShipped
    << "\nQty to be Shipped: " << orderNode->order.GetQtyNotFilled()
    << "\nTotal cost to the Warehouse: " << warehouseCost
    << "\nTotal cost to the Customer: " << customerCost
    << "\nProfit this Shipment: " << customerCost - warehouseCost
    << "\n";
    
    cout << "\nShipment Details:\n"
    << "Delivery #" << setw(15) << "Qty Shipped" << setw(15) << "Unit Price" << setw(25) << "Cost to the Warehouse" << setw(25) << setw(25) << "Cost to the Customer\n";
    
    while (deliveryHead != nullptr) {
        cout << right << setw(10) << deliveryHead->delivery.GetDeliveryID()
        << setw(15) << deliveryHead->delivery.GetDeliveryItems()
        << setw(15) << deliveryHead->delivery.GetCostPerItem()
        << setw(25) << deliveryHead->delivery.GetCostPerItem() * deliveryHead->delivery.GetDeliveryItems()
        << setw(24) << ((deliveryHead->delivery.GetCostPerItem() * .5) + deliveryHead->delivery.GetCostPerItem()) * deliveryHead->delivery.GetDeliveryItems()
        << "\n";
        
        deliveryHead = deliveryHead->next;
        
    }
    
    cout << "\n";
}
