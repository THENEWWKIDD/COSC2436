#include <iostream>
#include <vector>
#include "/home/bigtasty/COSC2436/ArgumentManager.h"

struct element
{
    element* next;

    string value_S;
    int value_I;
};

class linkedList
{
    private:
    element* head;
    element* tail;

    public:
    bool isEmpty();
    void addAtBeg(string data);
    void addAtEnd(string data);
    void removeHead();
    void removeTail();
};

bool linkedList::isEmpty()
{
    if(head == nullptr)
    {
        return true;
    }

    return false;
}

void linkedList::addAtBeg(string data)
{
    element* temp = new element;
    temp -> value_S = data;

    if(isEmpty())
    {
        temp = new element;
        temp -> value_S = data;
        head = temp;
    }

    else
    {
        temp -> next = head;
        head = temp;
    }
}

void linkedList::addAtEnd(string data)
{
    element* temp = new element;
    temp -> value_S = data;

    if(isEmpty())
    {
        head = temp;
        tail = temp;
    }

    else
    {
        tail -> next = temp;
        tail = temp;
    }
}

void linkedList::removeHead()
{
    element* cu;

    if(isEmpty())
    {
        return;
    }

    else
    {
        cu = head;
        head = head -> next;
        delete cu;
    }
}

void linkedList::removeTail()
{
    element* cu = head;
    if(isEmpty())
    {
        return;
    }

    while(cu -> next != nullptr)
    {
        if(cu -> next = tail)
        {
            tail = cu;
            cu = cu -> next;
            delete cu;
        }
    }
}

int main()
{
    std::vector<string> arr = {"String of stuff"};//, "More stuff in the thing", "I am in danger", "This is being printed right now", "This is a senctence", "Hello there"};

    linkedList listOfElements;

    int i = 0;
    while(i < arr.size())
    {
        addAtBeg[arr[i]];
        i++;
    }

    
}
