#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include "/home/bigtasty/COSC2436/ArgumentManager.h"

struct Node
{
    Node* next = nullptr;

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
    Node* sorted = nullptr;

    public:
    void sort(std::string type);
    void remove(std::string cred, int &size);
    
    bool isEmpty();
    void printLL();
    void removeHead();
    void duplicateDel();
    void insertionSort(Node* p, std::string data);
    void sortedInsert(Node* p, std::string data);
    void addAtEnd(std::string ID, std::string USR, std::string SCR, std::string GRD, int &size);
    void add(int pos, std::string ID, std::string USR, std::string SCR, std::string GRD, int &size);
    void extractAndPopulate(std::string input, int &size);

    Node* getHead()
    {
        return head;
    }
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

void linkedList::addAtEnd(std::string ID, std::string USR, std::string SCR, std::string GRD, int &size)
{
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
            size++;
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
        size++;
    }
    
}

void linkedList::extractAndPopulate(std::string in_Str, int &size) //Extracting id, username, score, and grade
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
    
    addAtEnd(id, user, score, grade, size);
}

void linkedList::add(int pos, std::string ID, std::string USR, std::string SCR, std::string GRD, int &size)
{
    Node* temp = new Node;
    temp -> id = ID;
    temp -> username = USR;
    temp -> score = SCR;
    temp -> grade = GRD;

    if(isEmpty() && pos != 0)
    {
        return;
        // head = temp;
        // tail = temp;
    }

    else if(isEmpty() && pos == 0)
    {
        addAtEnd(ID, USR, SCR, GRD, size);

        // if(temp -> id == "" || temp -> username == "" || temp -> score == "" || temp -> grade == "")
        // {
        //     return;
        // }

        // else
        // {
        //     head = temp;
        //     tail = temp;
        //     size++;
        // }
    }

    else if(pos > size)
    {
        return;
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

    size++;

    
}

void linkedList::removeHead()
{
    Node* cu;

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

void linkedList::remove(std::string cred, int &size)
{
    Node* cu = head;
    Node* prev = nullptr;

    if(isEmpty())
    {
        return;
    }

    else if(head -> id == cred || head -> username == cred || head -> score == cred ||head -> grade == cred)
    {
        removeHead();
        size--;
    }

    else
    {
        while(cu != nullptr)
        {
            if((cu -> id == cred || cu -> username == cred || cu -> score == cred || cu -> grade == cred))
            {
                break;
            }

            else
            {
                prev = cu;
                cu = cu -> next;
            }
            
        }

        if(cu != nullptr)
        {
            prev -> next = cu -> next;
            delete cu;
            size--;
        }

        else
        {
            delete cu;
            return;
        }
    }


}

void linkedList::sortedInsert(Node* newnode, std::string data)
    {
        if(data == "id")
        {
            if (sorted == NULL || sorted->id >= newnode -> id) 
            {
                newnode -> next = sorted;
                sorted = newnode;
            }
            else 
            {
                Node* current = sorted;
                /* Locate the node before the point of insertion
                */
                while (current->next != NULL && current->next->id < newnode->id)
                {
                    current = current->next;
                }

                newnode->next = current->next;
                current->next = newnode;
            }
        }

        if(data == "username")
        {
            if (sorted == NULL || sorted->username >= newnode->username) 
            {
                newnode->next = sorted;
                sorted = newnode;
            }
            else 
            {
                Node* current = sorted;
                /* Locate the node before the point of insertion
                */
                while (current->next != NULL && current->next->username < newnode->username)
                {
                    current = current->next;
                }

                newnode->next = current->next;
                current->next = newnode;
            }
        }

        if(data == "score")
        {
            if (sorted == NULL || sorted->score >= newnode->score) 
            {
                newnode->next = sorted;
                sorted = newnode;
            }
            else 
            {
                Node* current = sorted;
                /* Locate the node before the point of insertion
                */
                while (current->next != NULL && current->next->score < newnode->score)
                {
                    current = current->next;
                }

                newnode->next = current->next;
                current->next = newnode;
            }
        }

        if(data == "grade")
        {
            if (sorted == NULL || sorted->grade >= newnode->grade) 
            {
                newnode->next = sorted;
                sorted = newnode;
            }
            else 
            {
                Node* current = sorted;
                /* Locate the node before the point of insertion
                */
                while (current->next != NULL && current->next->grade < newnode->grade)
                {
                    current = current->next;
                }

                newnode->next = current->next;
                current->next = newnode;
            }
        }
    }

void linkedList::insertionSort(Node* headref, std::string data)
    {
        sorted = NULL;
        Node* current = headref;
        while (current != NULL) 
        {
            Node* next = current->next;
            sortedInsert(current, data);
            current = next;
        }
        head = sorted;
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
    std::vector<string> arr;
    int sizeOfList = 0;

    while(!inPut.eof())
    {
        getline(inPut, temp);
        temp.erase(remove(temp.begin(), temp.end(), '\n'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '\r'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
        arr.push_back(temp);
        temp = "";
    }

    while(!comm.eof())
    {
        getline(comm, temp);
        temp.erase(remove(temp.begin(), temp.end(), '\n'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '\r'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
        arr.push_back(temp);
        temp = "";
    }

    for(int i = 0; i < arr.size(); i++)
    {
        std::string TBP = arr[i]; //To be parsed

        if(TBP.find("Add") != string::npos)
        {
            //Parse data into credentials
            //list.add();
            std::cout << "Needs to be added" << endl;
        }

        else if(TBP.find("Remove") != string::npos)
        {
            std::string data = TBP.substr(0, TBP.find(":"));
            std::string targetData;
            
            if(data.find("id") != string::npos)
            {
                targetData = TBP.substr(TBP.find(":") + 1, (TBP.find(":") - TBP.find(")")) - 1);
                list.remove(targetData, sizeOfList);
            }

            else if(data.find("username") != string::npos)
            {
                targetData = TBP.substr(TBP.find(":") + 1, (TBP.find(")") - TBP.find(":")) - 1);
                list.remove(targetData, sizeOfList);
            }

            else if(data.find("score") != string::npos)
            {
                targetData = TBP.substr(TBP.find(":") + 1, (TBP.find(":") - TBP.find(")")) - 1);
                list.remove(targetData, sizeOfList);
            }

            else if(data.find("grade") != string::npos)
            {
                targetData = TBP.substr(TBP.find(":") + 1, (TBP.find(":") - TBP.find(")")) - 1);
                list.remove(targetData, sizeOfList);
            }
        }
        
        else if(TBP.find("Sort") != string::npos)
        {

            std::string targetData = TBP.substr(TBP.find("("), (TBP.find("(") - TBP.find(")")) - 1);
            list.insertionSort(list.getHead(), TBP);
            
            //std::cout << "Needs to be sorted" << endl;
        }

        else
        {
            list.extractAndPopulate(TBP, sizeOfList);
        }
    }
    list.printLL();
}