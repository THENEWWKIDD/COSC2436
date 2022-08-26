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

void p(int c) //With recursion, whatever comes before the function call gets called while opening the 
{
    if (c == 0)
    {
        return;
    }

    else //keep rep then call the function by changing argument
    {
        std::cout << "Nathan" << std::endl;
        p(c - 1);
        std::cout << "bye" << std::endl;
    } 
}

int mult(int a, int b)
{
    int sum = 0;
    if (b >= 1 && a >= 1)
    {
        sum = a + mult(a, b - 1);
    }

    return sum;
}

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

//Recursive factorial function
int main(int argc, char* argv[])
{
    int input = 0;
    std::cout << "Please choose an intger: ";
    std::cin >> input;
    std::cout << "The factorial of " << input << " is " << std::endl;
    std::cout << factorial(input) << std::endl;

    p(4);

    nb(472, 100);

    mult(45, 10);
}