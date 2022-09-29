#include <iostream>
#include <vector>
#include "myarray.h"

myarray::myarray(int s)
{
    size = s;
    elt = new int[size];
}

struct Node
{
    Node* next;
    int val;
};

class LinkedList
{
    private:
    Node* head;
    Node* tail;

    public:
    void insertAtBegC(int value);
    void insertAtEndC(int value);
    void insertAtMidC_value(int value);

};

bool linearSearch(std::vector<int> inV, int key)
{ 
    int i = 0;
    while(inV[i] != key && i < inV.size())
    {
        i++;
    }

    if(inV[i] == key)
    {
        return true;
    }

    return false;
}

bool binarySearch(std::vector<int> inV, int low, int high, int key)
{
    int mid = (high + low) / 2;

    if(key == inV[high] || key == inV[low] || key == inV[mid])
    {
        return true;
    }

    else if(key > inV[mid])
    {
        low = mid;
        binarySearch(inV, low, high, key);
    }

    else if(key < inV[mid])
    {
        high = mid;
        binarySearch(inV, low, high, key);
    }

    return false;
}

void LinkedList::insertAtBegC(int value)
{
    Node* temp = new Node;
    temp -> val;

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        temp -> next = head;
        head = temp;
        tail -> next = head;
    }
}

void LinkedList::insertAtEndC(int value)
{
    Node* temp = new Node;

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        tail -> next = temp;
        tail = temp;
        tail -> next = head;
    }
}

void LinkedList::insertAtMidC_value(int value)
{
    
}

int main()
{
    myarray A;
    myarray B(12);

    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 30};

    std::cout << linearSearch(arr, 12) << std::endl;

    std::cout << binarySearch(arr, 0, arr.size(), 17) << std::endl;


}