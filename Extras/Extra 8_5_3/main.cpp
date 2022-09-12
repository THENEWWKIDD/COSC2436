//Write a recursive function to print an array
#include <iostream>
#include <vector>

void printWR(std::vector<std::string> input, int index)
{
    if(index < 0 || input.size() == 0)
    {
        return;
    }

    else
    {
        if(index < input.size())
        {
            std::cout << input[index] << " ";
            printWR(input, ++index);
        }
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> stuff;
    stuff.push_back("Hello");
    stuff.push_back("there");
    stuff.push_back("I");
    stuff.push_back("am");
    stuff.push_back("Nathan");
    stuff.push_back("Hunt!");

    printWR(stuff, 0);
}