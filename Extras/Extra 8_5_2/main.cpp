//Write a recursive function that adds from m to n

#include <iostream>

int add(int m, int n)
{
    if(m == n)
    {
        return m;
    }

    return n + add(m, n - 1);
}

int main()
{
    std::cout << add(0, 18) << std::endl;
}