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
    Node* head = nullptr;
    Node* tail = nullptr;

    public:
    void remove();
    bool isEmpty();
    void printLL();
    void duplicateDel();
    void addAtEnd(std::string ID, std::string USR, std::string SCR, std::string GRD);
    void add(int pos, std::string ID, std::string USR, std::string SCR, std::string GRD);
    void extractAndPopulate(std::string input);
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
            std::cout << cu -> username << " ";
            std::cout << cu -> score << " ";
            std::cout << cu -> grade << " ";
            std::cout << std::endl;
            cu = cu -> next;
        }

        std::cout << cu -> id << " ";
        std::cout << cu -> username << " ";
        std::cout << cu -> score << " ";
        std::cout << cu -> grade << " ";
        std::cout << std::endl;
    }
}

void linkedList::addAtEnd(std::string ID, std::string USR, std::string SCR, std::string GRD)
{
    int count;
    //temp -> value_S = data;
    Node* temp = new Node;
    temp -> id = ID;
    temp -> username = USR;
    temp -> score = SCR;
    temp -> grade = GRD;

    if(isEmpty())
    {
        if(temp -> id == "" || temp -> username == "" || temp -> score == "" || temp -> grade == "")
        {
            return;
        }

        else
        {
            head = temp;
            tail = temp;
        }
    }

    else if(temp -> id == "" || temp -> username == "" || temp -> score == "" || temp -> grade == "")
    {
        return;
    }

    else
    {
        tail -> next = temp;
        tail = temp;
    }
    count + 1;
}

void linkedList::extractAndPopulate(std::string in_Str) //Extracting id, username, score, and grade
{
    std::string findAndDelete = in_Str;
    std::string data;
    std::string id;
    std::string user;
    std::string score;
    std::string grade;

    if(findAndDelete.substr(0, findAndDelete.find(':')) == "[id")
    {
        findAndDelete.erase(0, findAndDelete.find(':') + 1);
        data = findAndDelete.substr(0, findAndDelete.find(';'));
        id = data;
        findAndDelete.erase(0, findAndDelete.find(';') + 1);
        data = "";
    }

    if(findAndDelete.substr(0, findAndDelete.find(':')) == "username")
    {
        findAndDelete.erase(0, findAndDelete.find(':') + 1);
        data = findAndDelete.substr(0, findAndDelete.find(';'));
        user = data;
        findAndDelete.erase(0, findAndDelete.find(';') + 1);
        data = "";
    }

    if(findAndDelete.substr(0, findAndDelete.find(':')) == "score")
    {
        findAndDelete.erase(0, findAndDelete.find(':') + 1);
        data = findAndDelete.substr(0, findAndDelete.find(';'));
        score = data;
        findAndDelete.erase(0, findAndDelete.find(';') + 1);
        data = "";
    }

    if(findAndDelete.substr(0, findAndDelete.find(':')) == "grade")
    {
        findAndDelete.erase(0, findAndDelete.find(':') + 1);
        data = findAndDelete.substr(0, findAndDelete.find(']'));
        grade = data;
        findAndDelete.erase(0, findAndDelete.find(']') + 1);
        data = "";
    }
    
    addAtEnd(id, user, score, grade);
}

void linkedList::add(int pos, std::string ID, std::string USR, std::string SCR, std::string GRD)
{
    Node* temp = new Node;
    temp -> id = ID;
    temp -> username = USR;
    temp -> score = SCR;
    temp -> grade = GRD;

    if(isEmpty())
    {
        return;
        // head = temp;
        // tail = temp;
    }

    else if(temp -> id == "" || temp -> username == "" || temp -> score == "" || temp -> grade == "")
    {
        return;
    }

    Node* cu = head;
    Node*  prev = nullptr;
    int position = 0;

    while (cu != nullptr)
    {
        if(pos == position)
        {
            return;
        }

        prev = cu;
        cu = cu -> next;
        position;
    }

    prev -> next = temp;

    
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

    list.extractAndPopulate(arr[0]);
    list.extractAndPopulate(arr[1]);
    list.extractAndPopulate(arr[2]);
    list.extractAndPopulate(arr[3]);
    list.extractAndPopulate(arr[4]);


    list.printLL();


    
}