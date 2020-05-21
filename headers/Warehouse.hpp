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
    void PrintOrderDetails(int shipment, Deliveries deliveriesUsed[]);
    
private:
    int arraySize;
    OrderStackNode* orderNode;
    
};
