class Item {
public:
    Item();
    Item(int numItems, double newPrice);
    void SetInventory(int items, double price);
    
private:
    int numItems;
    double cost;
    
};
