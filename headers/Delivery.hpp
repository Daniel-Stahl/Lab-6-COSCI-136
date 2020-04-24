#include <string>
#include "Order.hpp"

using namespace std;

class Delivery {
public:
    Delivery();
    Delivery(string newID, Order newOrder);
    void SetDelivery(string ID, Order order);
    string GetDeliveryID() const;
    Order GetDeliveryOrder() const;

private:
    string deliveryID;
    Order deliveryOrder;
    double cost;
    double total;
    
};
