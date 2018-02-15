#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
#include <iostream>

class ItemToPurchase
{
    public:
        ItemToPurchase();   //constructor
        ItemToPurchase(std::string inDescription, int inCost, int inQuantity);  //constructor
        std::string getDescription() const;     //description
        int getCost() const;                    //cost
        int getQuantity() const;                //quantity
        void displayItem() const;               //display the item
        virtual ~ItemToPurchase();              //destructor

    protected:

    private:
        std::string description;                //description
        int cost;                               //cost
        int quantity;                           //quantity
};

#endif // ITEMTOPURCHASE_H
