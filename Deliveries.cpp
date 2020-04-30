#include "Deliveries.hpp"

Deliveries::Deliveries(){deliveryID = 0;};

Deliveries::Deliveries(int items, double cost) {
    SetDeliveries(items, cost);
};

void Deliveries::SetDeliveries(int items, double cost) {
    deliveryID = GenerateDeliveryID();
    numItems = items;
    costPer = cost;
};

int Deliveries::GetDeliveryID() const {
    return deliveryID;
};

int Deliveries::GetDeliveryItems() const {
    return numItems;
};

double Deliveries::GetCostPerItem() const {
    return costPer;
}

void Deliveries::SetDeliveryItems(int newItemNum) {
    numItems -= newItemNum;
};

int Deliveries::GenerateDeliveryID() {
    return deliveryID + 1;
};
