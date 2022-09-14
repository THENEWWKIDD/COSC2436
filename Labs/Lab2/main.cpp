#include <iostream>
#include <fstream>
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
    element* head = nullptr;
    element* tail = nullptr;

    public:
    bool isEmpty();
    void printLL();
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

void linkedList::printLL()
{
    int i = 0;
    element* cu = head;

    if(head == nullptr)
    {
        std::cout << "This list is empty." << std::endl;
    }

    else
    {
        while(cu -> next != nullptr)
        {
            std::cout << cu -> value_S << std::endl;
            cu = cu -> next;
        }

        std::cout << cu -> value_S << std::endl;
    }
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

int main(int argc, char* argv[])
{
    linkedList listOfElements;

    std::vector<string> regularInput;
    string temp;
    ifstream inPut("input2.txt");
    ofstream outPut("myAns.txt");

    while (!inPut.eof())
    {
        getline(inPut, temp);
        regularInput.push_back(temp);
        temp = "";
    }

    for(int i = 0; i < regularInput.size(); i++)
    {
        if(regularInput[i] != "remove tail" || regularInput[i] != "remove head")
        {
            listOfElements.addAtEnd(regularInput[i]);
        }

        else if(regularInput[i] == "remove tail")
        {
            listOfElements.removeTail();
        }

        else if(regularInput[i] == "remove head")
        {
            listOfElements.removeHead();
        }


        
    }



    //listOfElements.removeHead();
    //listOfElements.printLL();
}
