#include <string>

using namespace std;

class Order {
public:
    Order();
    Order(string newID, int newItem, double newPrice);
    void SetOrder(string ID, int items, double price);
    string GetOrderID() const;
    int GetOrderItems() const;
    
private:
    string orderID;
    int orderItems;
    double orderPrice;
};
