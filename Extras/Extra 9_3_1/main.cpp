//Create a circular linked list that says "I love cplusplus"
//Have a function called "deleteEveryOther" that deletes every other character in the linked list
//Return the remaining character and the number of rounds that it took

#include <iostream>

struct letter //use a circular linked list
{
    letter* next;
    char data;
};

class word
{
    private:
    letter* head;
    letter* tail;

    public:
    void delEveryOther();
    void add(char t);
};

void word::delEveryOther()
{
    int counter = 0;
}

void word::add(char t)
{
    letter* temp;
    temp -> data = t;

    if(head == nullptr)
    {
        head = new letter;
        head -> data = t;
        tail = head;
    }

    else
    {
        
    }
}

int main()
{
    word quote;

    quote.add('I');
    quote.add(' ');
    quote.add('l');
    quote.add('o');
    quote.add('v');
    quote.add('e');
    quote.add(' ');
    quote.add('c');
    quote.add('p');
    quote.add('l');
    quote.add('u');
    quote.add('s');
    quote.add('p');
    quote.add('l');
    quote.add('u');
    quote.add('s');

    while ()
    {
        quote.delEveryOther();
    }

}