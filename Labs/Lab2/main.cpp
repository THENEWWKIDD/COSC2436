#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "/home/bigtasty/COSC2436/ArgumentManager.h"

struct element
{
    element* next;

    string value_S;
    int value_I;
    char value_C;
};

class linkedList
{
    private:
    element* head = nullptr;
    element* tail = nullptr;

    public:
    bool isEmpty();
    void printLL(std::vector<string> &in);
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

void linkedList::printLL(std::vector<string> &in)
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
            std::cout << cu -> value_S << " ";
            in.push_back(cu -> value_S);
            cu = cu -> next;
        }

        std::cout << cu -> value_S << std::endl;
        in.push_back(cu -> value_S);
    }
}

void linkedList::addAtBeg(string data)
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
    element* prev = nullptr;
    if(isEmpty())
    {
        return;
    }

    else if(cu->next == nullptr)
    {
        head = nullptr;
    }

    else
    {
        while(cu -> next != nullptr)
        {
            prev = cu;
            cu = cu -> next;
        }
        
        prev -> next = nullptr;
        tail = prev;
        delete cu;
    }

    
}

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    // string input = am.get("input");
    // string output = am.get("output");

    ifstream inPut("input2.txt");
    ofstream outPut("output.txt");

    linkedList listOfElements;

    std::vector<string> regularInput;
    std::vector<string> testSS;
    stringstream out_put;
    string addLoc;
    string temp;
    string type;


    

    getline(inPut, type);
    getline(inPut, addLoc);
    
    while (!inPut.eof())
    {
        getline(inPut, temp);

        temp.erase(remove(temp.begin(), temp.end(), '\n'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '\r'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
        regularInput.push_back(temp);

        temp = "";
    }

    for(int i = 0; i < regularInput.size(); i++)
    {
        string test = regularInput[i];
        
        if(test.find("removetail") != string::npos)
        {
            listOfElements.removeTail();
        }

        else if(test.find("removehead") != string::npos)
        {
            listOfElements.removeHead();
        }

        else if(test != "" && addLoc == "head\r")
        {
            listOfElements.addAtBeg(test);
        }

        else if(test != "" && addLoc == "tail\r" )
        {
            listOfElements.addAtEnd(test);
        }
    }

    listOfElements.printLL(testSS);

    for(int i = 0; i < testSS.size(); i++)
    {
        outPut << testSS[i] << " ";
    }

}
