using namespace std;

class Deliveries {
public:
    Deliveries();
    Deliveries(int items, double cost);
    void SetDeliveries(int items, double cost);
    int GetDeliveryID() const;
    int GetDeliveryItems() const;
    double GetCostPerItem() const;
    int GenerateDeliveryID();
    
private:
    int deliveryID;
    int numItems;
    double costPer;
};
