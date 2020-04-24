#include <string>

using namespace std;

class Order {
public:
    Order();
    Order(int newItem, double newPrice);
    void SetOrder(int items, double price);
    int GetOrderID() const;
    int GetOrderItems() const;
    int GenerateOrderID();
    
private:
    //int orderNumGen;
    int orderID;
    int orderItems;
    double orderPrice;
};
