#include "/home/bigtasty/COSC2436/ArgumentManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>


// struct Node
// {
//     Node* next;
//     int val;
// };

// class stack
// {
//     private:
//     Node* top = nullptr;
//     Node* bottom = nullptr;

//     public:
//     Node* getHead();
//     bool isEmpty();
//     void push(int val);
//     void pop();
//     void printSR(Node* top);
// };

// Node* stack::getHead()
// {
//     if (top == nullptr)
//     {
//         return nullptr;
//     }

//     return top;
// }

// bool stack::isEmpty()
// {
//     if(top == nullptr)
//     {
//         return true;
//     }

//     return false;
// }

// void stack::push(int data)
// {
//     Node* temp = new Node;
//     temp -> val = data;

//     if(isEmpty())
//     {
//         top = temp;
//         bottom = temp;
//     }

//     else
//     {
//         temp -> next = top;
//         top = temp;
//     }
// }

// void stack::pop()
// {
//     Node* cu;

//     if(isEmpty())
//     {
//         return;
//     }

//     else
//     {
//         cu = top;
//         top = top -> next;
//         delete cu;
//     }
// }

// void stack::printSR(Node* top)
// {
//     int i = 0;
//     Node* cu = top;

//     if(isEmpty())
//     {
//         return;
//     }

//     else
//     {
//         if(cu != nullptr)
//         {
//             std::cout << cu -> val << " ";
//             cu = cu -> next;
//             printSR(cu);
//             return;
//         }
//     }
    
// }

bool isValid(std::string input)
{
    stack<char> st;
    if (input.length() <= 0)
    {
        return false;
    }

    else
    {
        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] != ')' || input[i] != '}' || input[i] != ']')
            {
                st.push(input[i]);
            }

            else if ()
            {

            }

        }

        stack<char> st;
    }
}

int main()
{
    //stack myS;
    std::vector<char> arr;

    std::vector<std::string> input = {"34(09)4553(32(345)545)"};

    for (int i = 0; i < input.size(); i++)
    {
        std::string temp = input[i];
        for(int j = 0; j < temp.size(); j++)
        {
            char inChar = temp[j];
        }

            
    }    
}