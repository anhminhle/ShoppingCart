#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include "ListInterface.h"
class ShoppingCart
{
    public:
        ShoppingCart();
        void addItemToEnd(ItemToPurchase item);         //add item to the end of the cart
        bool addItem(ItemToPurchase item, int i);       //add item at position i
        bool removeItem(int i);                         //remove item at position i
        bool displayItem(int i) const;                        //display item at position i
        void displayItems() const;                            //display items from 1 to n (all items)
        bool displayTotalCost(int i) const;                   //display total cost of item at position i
        void displayTotalCostAllItems() const;                  //display total cost of all items
        void displayNumberOfItems() const;                    //display number of items in the cart
        virtual ~ShoppingCart();

    protected:

    private:
        LinkedList cart;
};

#endif // SHOPPINGCART_H
