#include "/home/bigtasty/COSC2436/ArgumentManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Node
{
    Node* next;
    int val;
};

class stack
{
    private:
    Node* top = nullptr;
    Node* bottom = nullptr;

    public:
    bool isEmpty();
    void push(int val);
    void pop();
    void printSR(Node* top);


};



bool stack::isEmpty()
{
    if(top == nullptr)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void stack::push(int data)
{
    Node* temp = new Node;
    temp -> val = data;

    if(isEmpty())
    {
        top = temp;
        bottom = temp;
    }

    else
    {
        temp -> next = top;
        top = temp;
    }
}

void stack::pop()
{
    Node* cu;

    if(isEmpty())
    {
        return;
    }

    else
    {
        cu = top;
        top = top -> next;
        delete cu;
    }
}

void stack::printSR(Node* top)
{
    int i = 0;
    Node* cu = top;

    if(isEmpty())
    {
        return;
    }

    else
    {
        if(cu != nullptr)
        {
            std::cout << cu -> val << " ";
            cu = cu -> next;
            printSR(cu);
            return;
        }
    }
    
}

int main()
{
    stack myS;
    std::vector<char> arr;

    std::vector<std::string> input = {"34(09)4553(32(345)545)"};

    for (int i = 0; i < input.size(); i++)
    {
        std::string temp = input[i];
        for(int j = 0; j < temp.size(); j++)
        {
            char inChar = temp[j];
            if(temp[i] == '(')
            {
                inChar = temp[i];

                //increment j

                while(inChar != ')')
                {
                    myS.push(temp[i]);
                }

                while(!myS.isEmpty())
                {
                    myS.pop();
                }
            }

            else
            {
                arr.push_back(inChar);
            }
        }    
    }
}