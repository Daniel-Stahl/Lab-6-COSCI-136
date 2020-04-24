#include "Delivery.hpp"

Delivery::Delivery(){};

Delivery::Delivery(string newID, Order newOrder) {
    SetDelivery(newID, newOrder);
};

void Delivery::SetDelivery(string ID, Order order) {
    deliveryID = ID;
    deliveryOrder = order;
};

string Delivery::GetDeliveryID() const {
    return deliveryID;
};

Order Delivery::GetDeliveryOrder() const {
    return deliveryOrder;
};
