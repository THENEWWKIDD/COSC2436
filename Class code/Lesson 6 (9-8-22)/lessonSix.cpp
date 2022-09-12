#include <iostream>

struct letter
{
    char l;
    letter* next;
};

class word
{
    private:
    letter* head;
    letter* tail;

    public:
    
    word()
    {
        head = tail = 0;
    }

    void addatbeg(char i);
    void addatend(char i );
    void deletefrombeg();
    void deletefromend();
    bool searchLL(char v);
    void print();
};

void word::addatbeg(char i)
{
    letter* temp;
    temp -> l = i;

    if(head == 0)
    {
        head = temp;
    }

    else
    {
        temp -> next = head;
        head = temp;
    }

    delete temp;
}

void word::addatend(char i)
{
    letter* cu = head;
    letter* temp;
    temp -> l = i;

    while(cu -> next != nullptr)
    {
        cu = cu -> next;
    }

    tail = cu;

    tail -> next = temp;
    tail = temp;

    delete temp;
}

void word::deletefrombeg()
{
    letter* temp;
    
    temp = head;
    head = head -> next;

    std::cout << temp -> l;
    delete temp;
}

void word::deletefromend()
{
    letter* prev;
    letter* cu = head;

    while(cu -> next != nullptr)
    {
        prev = cu;
        cu = cu -> next;
    }
    
}

void print() //Written iteratively
{
    letter* cu;
    while(cu -> next != nullptr)
    {
        std::cout << cu -> l;
        cu = cu -> next;
    }
}

void printR(letter* cu) //Written recursively
{
    if(cu -> next != nullptr)
    {
        std::cout << cu -> l;
        cu = cu -> next;
        printR(cu);
    }
}

bool word::searchLL(char v)
{
    letter* cu = head;
    while(cu -> next != nullptr)
    {
        if(cu -> l = v)
        {
            return true;
        }

        cu = cu -> next;
    }
}


int main()
{
    word name;


}