#include <string>
#include <iostream>
#include <iomanip>
#include "OrderStack.hpp"
#include "InventoryStack.hpp"

using namespace std;

class Warehouse {
public:
    void AddOrderToStack();
    void AddDeliveryToStack();
    void FillOrder();
    bool IsOrderFilled(OrderStackNode* orderNode) const;
    void PrintOrderDetails(OrderStackNode* orderNode, InventoryStackNode* deliveryHead, int totalShipped, double warehouseCost, double customerCost);
    void PrintOrders();
    
private:
    OrderStack orderStack;
    InventoryStack inventoryStack;
};
