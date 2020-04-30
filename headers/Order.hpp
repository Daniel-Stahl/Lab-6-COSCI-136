#include <string>

using namespace std;

class Order {
public:
    Order();
    Order(int newItem, double newPrice);
    void SetOrder(int items, double price);
    int GetOrderID() const;
    int GetOrderItems() const;
    int GetOrderPrice() const;
    int GetQtyNotFilled() const;
    void SetOrderQty(int newQty);
    
private:
    int orderID;
    int qty = 0;
    double orderPrice;
    int qtyNotFilled;
    int GenerateOrderID();
};
