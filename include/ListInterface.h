#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

#include "ItemToPurchase.h"
typedef ItemToPurchase E;

class DNode;

class LinkedList{                           //doubly linked list
public:
    LinkedList();
    ~LinkedList();
    int size() const;                       //size of the list
    bool empty() const;                     //is list empty?
    const E& at(int pos) const;                    //element at position pos
    const E& front() const;                 //element at front
    const E& back() const;                  //element at back
    void addFront(const E& e);              //add element at front
    void addBack(const E& e);               //add element at back
    void addAt(const E& e, int pos);        //add element at position pos
    void removeFront();                     //remove element at front
    void removeBack();                      //remove element at back
    void removeAt(int pos);                 //remove element at pos
    void listReverse(LinkedList& L);        //reverse the list
private:
    DNode* header;                       //head node
    DNode* trailer;                      //tail node
protected:
    void add(const E&e, DNode* v);       //add element before node v
    void remove(DNode* v);               //remove node v
    int sz;                                 //size of the list
};

class DNode{
private:
    E elem;
    DNode* prev;
    DNode* next;
    friend class LinkedList;
};

#endif // LISTINTERFACE_H
