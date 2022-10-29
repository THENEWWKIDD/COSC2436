#include <iostream>

struct node
{
    int val;
    node* next;
};

class LL
{
    private:
    node* head = nullptr;
    node* tail = nullptr;

    public:
    node* reversePairs(node* H);
    void addAtEnd(int data);
    node* getHead();
    void printLL();
    
};

void LL::addAtEnd(int data)
{
    node* temp = new node;
    temp -> val = data;

    if(head == nullptr)
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

node* LL::reversePairs(node* H)
{
    bool setH = true;
    node* cu = H;
    node* prev = cu;
    node* temp = cu -> next;

    if(head == nullptr)
    {
        return nullptr;
    }

    while(cu != nullptr)
    {
        if(cu -> next != nullptr)
        {
            cu -> next = temp -> next;
        }
        
        temp -> next = cu;

        if(setH == true)
        {
            head = temp;
            setH = false;
        }

        else
        {
            prev = cu;
            prev -> next = temp;
        }

        cu = cu -> next;
        temp = cu -> next;

    }

    return head;
}

void LL::printLL()
{
    node* cu = head;
    if(head == nullptr)
    {
        std::cout << "The list is not built or does not have a head!" << std::endl;
    }

    else
    {
        while(cu != nullptr)
        {
            std::cout << cu -> val << std::endl;
            cu = cu -> next;
        }
    }
}

node* LL::getHead()
{
    if (head == nullptr)
    {
        return nullptr;
    }

    return head;
}


int main()
{
    LL list;

    list.addAtEnd(2);
    list.addAtEnd(4);
    list.addAtEnd(6);
    list.addAtEnd(8);
    
    list.printLL();

}