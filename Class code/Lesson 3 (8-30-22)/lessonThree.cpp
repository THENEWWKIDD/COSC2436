#include <iostream>

int main()
{
    //static allocation
    int a = 10;
    std::cout << "slowwwwwwwwww" << std::endl;

    int *p = &a;
    std::cout << ".....fast" << *p << std::endl;
    std::cout << "memory address..." << p << std::endl;
    p = nullptr; //p = 0;

    //dynamic w/ no a

    p = new int;
    *p = 10;

    std::cout << *p;
    p = nullptr;
    p = new int[4];

    for(int i = 0; i < 4; i++)
    {
        p[i] = i * 10;
    }

    for (int i = 0; i < 4; i++)
    {
        std::cout << *p << std::endl;
        p++;
    }

}