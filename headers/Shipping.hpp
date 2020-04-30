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
    struct OrderShipped {
        int shipmentId;
        Order order;
    };
    
    int sizeOfArray;
    OrderShipped shipping[];
    
    
    
    
};
