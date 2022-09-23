#include <iostream>
#include "myarray.h"

//Use this program as an extra
//Use "credit card wallet as another extra"
//Use "xxclass wallet"
    //main() CreditCard* tiny[2];

myarray::myarray(int s)
{
    size = s;
    elt = new int[size];
}

myarray::~myarray()
{
    delete [] elt;
}


void myarray::add()
{

}

void myarray::print()
{

}

bool myarray::search()
{

}