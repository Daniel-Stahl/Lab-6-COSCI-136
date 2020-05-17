#include "Order.hpp"
#include "Deliveries.hpp"
#include <iostream>
#define SHIPPING_SIZE 20
#define DELIVERY_SIZE 10

using namespace std;

class Shipping {
public:
    Shipping();
    void AddOrderToShippments(Order order, Deliveries delivery);
    void DisplayShipments(int pos, int deliverySize);
    bool IsOrderUnique(Order order, int& arrayPos);
    
    
private:
    struct OrderShipped {
        int shipmentId;
        Order order;
        Deliveries deliveries[DELIVERY_SIZE];
    };
    
    int sizeOfArray;
    int sizeOfDel;
    OrderShipped shipping[SHIPPING_SIZE];
    
    
    
    
};
