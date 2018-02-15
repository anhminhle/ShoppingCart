#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
    //ctor
}

void ShoppingCart::addItemToEnd(ItemToPurchase item)
{
    cart.addBack(item);
}

bool ShoppingCart::addItem(ItemToPurchase item, int i)
{
    if (i<0 || i>cart.size()){
        return 0;
    }else{
        cart.addAt(item, i);
        return 1;
    }
}

bool ShoppingCart::removeItem(int i)
{
    if (i<0 || i>=cart.size()){
        return 0;
    }else{
        cart.removeAt(i);
        return 1;
    }
}

bool ShoppingCart::displayItem(int i) const
{
    if (i<0 || i>=cart.size()){
        return 0;
    }else{
        cart.at(i).displayItem();
        return 1;
    }
}

void ShoppingCart::displayItems() const{
    if (cart.size()==0){
        std::cout << "Cart is empty!" << std::endl;
    }
    for (int i=0;i<cart.size();i++){
        cart.at(i).displayItem();
    }
}

bool ShoppingCart::displayTotalCost(int i) const{
    if (i<0 || i>=cart.size()){
        return 0;
    }else{
        std::cout << "Total cost of item number " << i << ": " << cart.at(i).getCost() * cart.at(i).getQuantity() << std::endl;
        return 1;
    }
}

void ShoppingCart::displayTotalCostAllItems() const{
    int AllCost = 0;
    for (int i=0;i<cart.size();i++){
        AllCost += cart.at(i).getCost() * cart.at(i).getQuantity();
    }
    std::cout << "Total cost of all items: " << AllCost << std::endl;
}

void ShoppingCart::displayNumberOfItems() const{
    std::cout << "Number of items: " << cart.size() << std::endl;
}

ShoppingCart::~ShoppingCart()
{
    //dtor
}
