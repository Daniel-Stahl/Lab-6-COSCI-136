#ifndef DELIVERIES_HEADER
#define DELIVERIES_HEADER

using namespace std;

class Deliveries {
public:
    Deliveries();
    Deliveries(int items, double cost);
    void SetDeliveries(int items, double cost);
    int GetDeliveryID() const;
    int GetDeliveryItems() const;
    double GetCostPerItem() const;
    void SetDeliveryItems(int newItemNum);
    
private:
    int deliveryID;
    int numItems;
    double costPer;
    int GenerateDeliveryID();
};

#endif
