#include "ListInterface.h"

LinkedList::LinkedList(){
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
    sz = 0;
}

LinkedList::~LinkedList(){
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

const E& LinkedList::at(int pos) const{
    DNode * node = header->next;
    int i = 0;
    for(;node && node->next && i < pos; node = node->next, ++i) {}
    return node->elem;
}

int LinkedList::size() const{
    return sz;
}

bool LinkedList::empty() const{
    return (header->next == trailer);
}

const E& LinkedList::front() const{
    return header->next->elem;
}

const E& LinkedList::back() const{
    return trailer->prev->elem;
}

void LinkedList::add(const E&e, DNode* v){
    DNode* u = new DNode;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = v->prev = u;
    sz++;
}

void LinkedList::addFront(const E&e){
    add(e,header->next);
}

void LinkedList::addBack(const E&e){
    add(e,trailer);
}

void LinkedList::addAt(const E&e, int pos){
    DNode * node = header->next;
    int i = 0;
    for(;node && node->next && i < pos; node = node->next, ++i) {}
    add(e, node);
}

void LinkedList::remove(DNode* v){
    DNode* u = v->prev;
    DNode* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
    sz--;
}

void LinkedList::removeFront(){
    remove(header->next);
}

void LinkedList::removeBack(){
    remove(trailer->prev);
}

void LinkedList::removeAt(int pos){
    DNode * node = header->next;
    int i = 0;
    for(;node && node->next && i < pos; node = node->next, ++i) {}
    remove(node);
}

void LinkedList::listReverse(LinkedList&L){
    LinkedList T;
    while (!L.empty()){
        E s = L.front();
        L.removeFront();
        T.addFront(s);
    }
    while (!T.empty()){
        E s = T.front();
        T.removeFront();
        L.addBack(s);
    }
}
