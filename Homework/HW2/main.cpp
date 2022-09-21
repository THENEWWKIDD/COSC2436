#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include "/home/bigtasty/COSC2436/ArgumentManager.h"

struct Node
{
    Node* next;

    string id;
    string score;
    string grade;
    string username;
};

class linkedList
{
    private:
    Node* head;
    Node* tail;


    public:
    
    void remove();
    bool isEmpty();
    void addAtEnd(Node* temp);
    void add(int pos, Node* temp);
    void extractAndPopulate(std::string input, Node* p);

    void printLL();
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
    Node* cu = head;

    if(head == nullptr)
    {
        std::cout << "This list is empty." << std::endl;
    }

    else
    {
        while(cu -> next != nullptr)
        {
            std::cout << cu -> id << " ";
            std::cout << cu -> score << " ";
            std::cout << cu -> grade << " ";
            std::cout << cu -> username << " ";
            //in.push_back(cu -> value_S);
            cu = cu -> next;
        }
            
        std::cout << cu -> id << " ";
        std::cout << cu -> score << " ";
        std::cout << cu -> grade << " ";
        std::cout << cu -> username << " ";
        //in.push_back(cu -> value_S);
    }
}

void linkedList::extractAndPopulate(std::string in_Str, Node* p) //Extracting id, username, score, and grade
{
    std::string findAndDelete = in_Str;
    std::string data;

    if(findAndDelete.substr(0, findAndDelete.find(':')) == "[id")
    {
        findAndDelete.erase(0, findAndDelete.find(':') + 1);
        data = findAndDelete.substr(0, findAndDelete.find(';'));
        p -> id = data;
        findAndDelete.erase(0, findAndDelete.find(';') + 1);
        data = "";
    }

    if(findAndDelete.substr(0, findAndDelete.find(':')) == "username")
    {
        findAndDelete.erase(0, findAndDelete.find(':') + 1);
        data = findAndDelete.substr(0, findAndDelete.find(';'));
        p -> username = data;
        findAndDelete.erase(0, findAndDelete.find(';') + 1);
        data = "";
    }

    if(findAndDelete.substr(0, findAndDelete.find(':')) == "score")
    {
        findAndDelete.erase(0, findAndDelete.find(':') + 1);
        data = findAndDelete.substr(0, findAndDelete.find(';'));
        p -> score = data;
        findAndDelete.erase(0, findAndDelete.find(';') + 1);
        data = "";
    }

    if(findAndDelete.substr(0, findAndDelete.find(':')) == "grade")
    {
        findAndDelete.erase(0, findAndDelete.find(':') + 1);
        data = findAndDelete.substr(0, findAndDelete.find(']'));
        p -> grade = data;
        findAndDelete.erase(0, findAndDelete.find(']') + 1);
        data = "";
    }
    
    if(isEmpty())
    {
        head = p;
        //tail = p;
    }
}

void linkedList::addAtEnd(Node* temp)
{
    //temp -> value_S = data;

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

void linkedList::add(int pos, Node* temp)
{
    //Node* temp = new Node;
    //temp -> value_S = data;

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


int main(int argc, char* argv[])
{
    linkedList list;

    ArgumentManager am(argc, argv);

    // string input = am.get("input1.txt");
    // string command = am.get("command1.txt");
    // string output = am.get("output1.txt");

    ifstream inPut("input1.txt");
    ifstream comm("command1.txt");
    ofstream outPut("output1.txt");

    Node* student = new Node;
    int i = 0;
    std::string temp;
    std::vector<string> arr; // = {[id:1234;username:john;score:100;grade:A]};

    while(!inPut.eof())
    {
        getline(inPut, temp);
        temp.erase(remove(temp.begin(), temp.end(), '\n'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '\r'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
        arr.push_back(temp);
        temp = "";
    }

    list.extractAndPopulate(arr[0], student);
    list.extractAndPopulate(arr[1], student -> next);
    list.extractAndPopulate(arr[2], student -> next -> next);
    list.extractAndPopulate(arr[3], student -> next -> next -> next);

    list.printLL();
}