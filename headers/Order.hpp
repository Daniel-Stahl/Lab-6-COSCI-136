#include <string>

using namespace std;

class Order {
public:
    Order();
    Order(int newItem);
    void SetOrder(int items);
    int GetOrderID() const;
    int GetOrderItems() const;
    int GetQtyNotFilled() const;
    void SetQtyNotFilled(int missing);
    
private:
    int orderID;
    int qty;
    int qtyNotFilled;
    int GenerateOrderID();
};
