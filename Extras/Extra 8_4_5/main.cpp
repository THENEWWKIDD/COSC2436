//Make a function that divides a number using modulus recursively

//EX: 472
//Divides by 100 first
//Divides by 10
//Divides by 1

#include <iostream>
#include "/home/bigtasty/COSC2436/ArgumentManager.h"

void nb(int n, int d )
{
    int numDigits;
    if (n == 0)
    {
        return;
    }

    else
    {
        std::cout << n/d << std::endl;
        nb(n % d, d / 10 );
    }
}

int main(int argc, char* argv[])
{
    nb(472, 100);
}