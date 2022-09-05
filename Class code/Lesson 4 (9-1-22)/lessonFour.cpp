#include <iostream>

struct Student
{
    double gpa;
    int age;
    Student* next; //New student pointer
};

struct pearl
{
    std::string color;
    pearl* hole;
}

class necklace
{
    private:
    pearl* head;

    public:
    necklace()
    {
        head = nullptr;
    }

    void addpearl(string c);
    void print();
};

int main()
{

    Student* p;
    p = new Student;
    p -> next = new Student;

    p -> age = 20;
    p -> gpa = 3.45;

    p -> next -> age = 30;
    p -> next -> gpa = 2.5;

    Student* head = p; //Saves the head of the list of students
    p = p -> next; //Initializes the next value as the head

    std::cout << p -> age << std::endl;
    std::cout << p -> gpa << std::endl;

    delete p;

    //Creates a dynamic array of student objects
    Student* p = new Student[5];


    //For the pearl necklace example
    necklace mine;
    mine.addpearl("yellor");
    mine.addpearl("red");
    mine.addpearl("blue");
    mine.addpearl("white");

    mine.print();
    


}