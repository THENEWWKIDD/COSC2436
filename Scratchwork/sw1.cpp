#include <iostream>
#include <vector>

struct Node
{
    Node* next;
    int data;
};

class linkedList
{
    private:
    Node* head;
    Node* tail;

    
    public:
    int greatestEven(Node* head, int &greatest);
    void addAtEnd(int data);
    Node* getHead();
    bool isEmpty();
};

bool linkedList::isEmpty()
{
    if(head == nullptr)
    {
        return true;
    }

    return false;
}

int linkedList::greatestEven(Node* head, int &greatest) //Starts out at 0
{
    if(head == nullptr)
    {
        return 0;
    }

    else if(head -> data % 2 == 0)
    {
        if(head -> data > greatest)
        {
            greatest = head -> data;
        }
    }

    greatestEven(head -> next, greatest);    

    return greatest;

}

void linkedList::addAtEnd(int data)
{
    Node* temp = new Node;
    temp -> data = data;

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

Node* linkedList::getHead()
{
    if(head != nullptr)
    {
        return head;
    }

    else
    {
        return nullptr;
    }
}

int main()
{
    linkedList list;
    std::vector<int> inV;
    int great = 0;

    inV.push_back(3);
    inV.push_back(4);
    inV.push_back(5);
    inV.push_back(6);
    inV.push_back(7);
    inV.push_back(8);
    inV.push_back(9);

    for(int i = 0; i < inV.size(); i++)
    {
        std::cout << inV[i] << std::endl;
    }

    list.addAtEnd(19);
    list.addAtEnd(3);
    list.addAtEnd(6);
    list.addAtEnd(10);
    list.addAtEnd(9);
    list.addAtEnd(4);
    std::cout << list.greatestEven(list.getHead(), great) << std::endl;


}