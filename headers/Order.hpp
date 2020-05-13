#ifndef ORDER_HEADER
#define ORDER_HEADER

#include <string>

using namespace std;

class Order {
public:
    Order();
    Order(int newItem);
    void SetOrder(int items);
    int GetOrderID() const;
    int GetOrderItems() const;
    int GetOrderPrice() const;
    void SetOrderPrice(double newPrice);
    int GetQtyNotFilled() const;
    void SetOrderQty(int newQty);
    void SetQtyNotFilled(int missing);
    
private:
    int orderID;
    int qty;
    double orderPrice;
    int qtyNotFilled;
    int GenerateOrderID();
};

#endif
