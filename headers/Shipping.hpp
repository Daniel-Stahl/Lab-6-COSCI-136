#include "Order.hpp"
#include <iostream>
#define SHIPPING_SIZE 20

using namespace std;

class Shipping {
public:
    Shipping();
    void AddOrderToShippments(Order order);
    void DisplayShipments();
    
    
private:
    int shipmentID;
    Order order[SHIPPING_SIZE];
    
    
    
};
