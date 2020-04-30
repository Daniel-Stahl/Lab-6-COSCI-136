#include <string>
#include <iostream>
#include "OrderStack.hpp"
#include "InventoryStack.hpp"

using namespace std;

class Warehouse {
public:
    void FillOrder(OrderStack& orders, InventoryStack& inventory);
    bool IsOrderFilled(Order order) const;
    
private:
    OrderStack orders;
    InventoryStack inventory;
    Deliveries delivery;
    
    
};
