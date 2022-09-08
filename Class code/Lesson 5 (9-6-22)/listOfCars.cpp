#include <iostream>
#include "listOfCars.h"


    bool Dealership::isEmpty(Car* node)
    {

    }
    
    void Dealership::addAtBeg(int year, std::string name, double price, std::string color)
    {
        if(isEmpty())
        {
            head = new Car;
            head -> year = year;
            head -> color = color;
            head -> price = price;
            head -> name = name;
        }

        else
        {
            Car* temp = head;
            temp -> next;
        }
    }

    void Dealership::addAtEnd()
    {

    }

    void Dealership::addAtPos(int position)
    {

    }

    void Dealership::addAtMid()
    {

    }

    void Dealership::addByValue(int year, double price)
    {

    }
    
    void Dealership::deleteNode()
    {

    }

    void Dealership::print()
    {

    }

    void Dealership::search()
    {

    }