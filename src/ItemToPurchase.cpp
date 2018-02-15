#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase()
{
    //ctor
}

ItemToPurchase::ItemToPurchase(std::string inDescription, int inCost, int inQuantity)
{
    //ctor
    description = inDescription;
    cost = inCost;
    quantity = inQuantity;
}

std::string ItemToPurchase::getDescription() const{
    return description;
}

int ItemToPurchase::getCost() const{
    return cost;
}

int ItemToPurchase::getQuantity() const{
    return quantity;
}

void ItemToPurchase::displayItem() const{
    std::cout << "Item Description: " << description << std::endl;
    std::cout << "Cost: " << cost << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
}

ItemToPurchase::~ItemToPurchase()
{
    //dtor
}
