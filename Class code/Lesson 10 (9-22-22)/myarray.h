#include <iostream>

class myarray
{
    private:
    int size;
    int *elt;
    public:
    myarray(int =10);
    
    void add();
    bool search();
    void print();
};