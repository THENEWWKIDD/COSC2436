//Write a recursive function that prints from 1-m

//What is the condition to stop? Once you have reached m
//What is the repetition? Printing
//How are you changing the the function call each time? By changing the value of the counting parameter

#include <iostream>


void count(int n, int m) //This is a function that recursively prints from int n to int m
{
    if(n >= m)
    {
        std::cout << n << std::endl;
    }

    else
    {
        //
        std::cout << n << "\t";
        count(n + 1, m);
    }

}

int main()
{
    count(1, 30);
}
