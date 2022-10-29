//Implimenting heapify and min/max heap
//Build a heap
//Heap Sort
//

#include <iostream>
#include <algorithm>

void heapify(int arr[], int a, int n)
{
    //Compare the children to the parent 
    //Choose the larger of the two
    //Swap with the parent depending on which is larger of the two
}

void heapSort(int a, int n, int arr[])
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[n]);
        heapify(arr, a, n);
    }
}


int main()
{

}