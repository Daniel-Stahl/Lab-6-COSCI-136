#include <string>
#include <iostream>
#include "OrderStack.hpp"
#include "InventoryStack.hpp"
#include "Shipping.hpp"

using namespace std;

class Warehouse {
public:
    void FillOrder(OrderStack& orders, InventoryStack& inventory);
    bool IsOrderFilled(Order order) const;
    void SendOrderToShipping(Order order);
    
private:
    OrderStack orders;
    InventoryStack inventory;
    Deliveries delivery;
    Shipping shipping;
    
};
