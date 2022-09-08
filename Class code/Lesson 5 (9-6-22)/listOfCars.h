#include <iostream>

struct Car
{
    int year;
    double price;
    std::string name;
    std::string color;

    Car* next;
    
};

class Dealership
{
    private:
    Car* head;
    
    public:

    void addAtBeg(int year, std::string name, double price, std::string color);
    void addAtEnd();
    void addAtPos(int position);
    void addAtMid();
    void addByValue(int year, double price);
    bool isEmpty();
    void deleteNode();
    void print();
    void search();
};