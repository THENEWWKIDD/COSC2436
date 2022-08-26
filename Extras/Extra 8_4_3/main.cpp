//Write a function that uses recursion to print a factorial
//Hello

#include <iostream>
#include "/home/bigtasty/COSC2436/ArgumentManager.h"

int factorial(int num)
{
    int product = 0;
    if(num == 1)
    {
        product = 1;
        return product;
    }

    else if(num != 1)
    {
        product = num * factorial(num -1);
    }

    return product;

}

int main(int argc, char* argv[])
{
    std::cout << factorial(10) << std::endl;
}