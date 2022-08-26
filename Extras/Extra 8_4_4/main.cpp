//Write a function that multiplies two numbers using recursion

#include <iostream>
#include "/home/bigtasty/COSC2436/ArgumentManager.h"

int mult(int a, int b)
{
    int sum = 0;
    if (b >= 1 && a >= 1)
    {
        sum = a + mult(a, b - 1);
    }

    return sum;
}

int main(int argc, char* argv[])
{

}