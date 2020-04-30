#ifndef ORDER_HEADER
#define ORDER_HEADER

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
    int qty;
    double orderPrice;
    int qtyNotFilled;
    int GenerateOrderID();
};

#endif
