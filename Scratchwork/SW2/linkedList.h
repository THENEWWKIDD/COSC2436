#include <iostream>
#include "nodeT.h"

template<typename T>
class linkedList
{
    private:
    node<T>* head = nullptr;

    public:

    node<T>* getHead();
    void addAtEnd(T data);
    void addAtBeg(T data);
    void removeHead();
    void removeEnd();

};

node<T>* linkedList::getHead()
{
    if(head == nullptr)
    {
        return true;
    }

    return false;
}

void linkedList::addAtEnd()
{
    if(isEmpty == true)
    {

    }

    else
    {

    }
}

void linkedList::addAtBeg()
{

}



int main()
{

}