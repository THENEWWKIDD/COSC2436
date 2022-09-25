#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

struct Node
{
    Node* next = nullptr;

    std::string id;
    std::string score;
    std::string grade;
    std::string username;
};

class linkedList
{
    public:
    void sort(std::string type);
    void remove(std::string cred, int &size);
    
    bool isEmpty();
    void printLL();
    Node* getHead();
    void removeHead();
    void cpy(std::vector<std::string> &in);
    void extractAndPopulate(std::string input, int &size);
    void insertionSort(Node* p, std::string data); //Function was modified from a G4G solution
    void sortedInsert(Node* p, std::string data); //Function was modified from a G4G solution

    void addAtEnd(std::string ID, std::string USR, std::string SCR, std::string GRD, int &size);
    void addAtBeg(std::string ID, std::string USR, std::string SCR, std::string GRD, int &size);
    void add(int pos, std::string ID, std::string USR, std::string SCR, std::string GRD, int &size);
    
    private:

    Node* head = nullptr;
    Node* tail = nullptr;
    Node* sorted = nullptr;
};
