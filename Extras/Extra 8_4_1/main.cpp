#include <iostream>
#include "/home/bigtasty/COSC2436/ArgumentManager.h"


//This program prints the number of arguments passed into main, as well as the arguments themselves.
int main (int argc, char* argv[])
{
    int i = argc;
    for (int j = i; j > 0; j--)
    {
        std::cout << argv[j-1] << std::endl;
        
    }
    std::cout << "The number of arguments is: " << argc << std::endl;
}