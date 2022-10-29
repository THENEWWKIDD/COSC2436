#include "/home/bigtasty/COSC2436/ArgumentManager.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

struct node
{
    node* next;
    std::string job;
    double val;
};

class queue
{
    private:
    node* head = nullptr;

    public:
    bool isEmpty();
    void enqueue(std::string job, double v);
    void printLL();
    node* getHead();
};

node* queue::getHead()
{
    if(head == nullptr)
    {
        return nullptr;
    }

    return head;
}

bool queue::isEmpty()
{
    if(head == nullptr)
    {
        return true;
    }

    return false;
}

void queue::enqueue(std::string job, double v)
{
    node* temp = new node;
    temp -> job = job;
    temp -> val = v;

    if(isEmpty())
    {
        head = temp;
    }

    else
    {
        node* cu = head;
        node* prev = nullptr;

        if(cu -> val > temp -> val)
        {
            temp -> next = cu;
            head = temp;
        }

        else
        {
            while(cu -> next != nullptr && cu -> val < temp -> val)
            {
                prev = cu;
                cu = cu -> next;
            }

            if(cu -> val > temp -> val)
            {   
                prev -> next = temp;
                temp -> next = cu;
            }

            else if(cu -> val == temp -> val)
            {
                temp -> next = cu -> next;
                cu -> next = temp;
            }

            else
            {
                cu -> next = temp;
            }
        }
    }
}

void queue::printLL()
{
    if(head == nullptr)
    {
        return;
    }

    node* cu = head;
    while(cu != nullptr)
    {
        std::cout << cu -> job << std::endl;
        cu = cu -> next;
    }

    std::cout << std::endl;
}

void intoFile(ofstream& str, node* h)
{
    if(h == nullptr)
    {
        return;
    }

    else
    {
        if(h -> next == nullptr)
        {
            str << h -> job;
        }

        else
        {
            str << h -> job << std::endl;
            intoFile(str, h -> next);
        }

        

    }
}


int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    string input = am.get("input");
    string output = am.get("output");

    ifstream inPut(input);
    ofstream outPut(output);

    queue q;

    std::string temp;
    int value;
    double fVal;
    std::string resultJ;
    std::string resultV;
    


    while (!inPut.eof())
    {
        getline(inPut, temp);
        for(int i = 0; i < temp.size(); i++)
        {
            while(isalpha(temp[i]) || temp[i] == ' ')
            {
                resultJ += temp[i];
                i++;
            }
            resultV += temp[i];
        }        
        fVal = std::stod(resultV);
        q.enqueue(resultJ, fVal);
        temp = "";
        resultJ = "";
        resultV = "";
    }

    intoFile(outPut, q.getHead());
}