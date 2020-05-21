#include <string>
#include <iostream>
#include <iomanip>
#include "OrderStack.hpp"
#include "InventoryStack.hpp"

using namespace std;

class Warehouse {
public:
    void FillOrder(OrderStack& orders, InventoryStack& inventory);
    bool IsOrderFilled() const;
    void PrintOrderDetails();
    
private:
    OrderStackNode* orderNode;
    InventoryStackNode* deliveryNode;
    InventoryStackNode* deliveryHead;
    double warehouseCost = 0;
    double customerCost = 0;
    int totalShipped = 0;
    
};
