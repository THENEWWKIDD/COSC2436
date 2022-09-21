#include <iostream>
#include <vector>

void bubbleSortV1(std::vector<int> arr, int n) 
{
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(7);
    arr.push_back(17);
    arr.push_back(6);
    bubbleSortV1(arr, 0);
}