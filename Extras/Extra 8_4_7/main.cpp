//Write a function that illustrates a recursive function "opening" and "closing"

#include <iostream>
#include "/home/bigtasty/COSC2436/ArgumentManager.h"

void p(int c) //With recursion, whatever comes before the function call gets called while opening the 
{
    if (c == 0)
    {
        return;
    }

    else //keep rep then call the function by changing argument
    {
        std::cout << "Nathan" << std::endl; //This line will run before each instance the recursive function is called
        p(c - 1);
        std::cout << "bye" << std::endl; //This line will run each time the function is recursively called, but after the stop condition has been met
    } 
}

int main(int argc, char* argv[])
{
    p(5);
}