#include "Deliveries.hpp"

struct InventoryStackNode {
    Deliveries delivery;
    InventoryStackNode* next;
    InventoryStackNode* prev;
};
