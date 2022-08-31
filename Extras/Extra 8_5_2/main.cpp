//Write a recursive function that adds from int n to 1

#include <iostream>

int add(int n)
{
    int sum;
    if(n == 1 || n == 0)
    {
        sum = n;
        return sum;
    }

    else if(n > 1)
    {
        sum = sum + n;
        add(n-1);
    }

    return sum;
}

int main()
{
    std::cout <<add(14) << std::endl;
}