//Write a function that prints from one number to another forward and backward recursively

#include <iostream>
#include "/home/bigtasty/COSC2436/ArgumentManager.h"

int count(int num1, int num2)
{
    if(num1 <= num2)
    {
        std::cout << num2 << std::endl;
        count(num1, num2 - 1);
        return 0;
    }

    else
    {
        return 0;
    }

}

int main(int argc, char* argv[])
{
    std::cout << count(1, 10) << std::endl;
}