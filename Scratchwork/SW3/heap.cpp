//Max heap
//Min heap
//Heapify
//Heap Sort

#include <iostream>
#include <algorithm>


void heapifyMn(int arr[], int i, int size)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    int smallest = i;

    if(arr[L] <= size && arr[L] < arr[i])
    {
        smallest = arr[L];
    }


    if(arr[R] <= size && arr[R] < arr[smallest])
    {
        smallest = arr[R];
        heapifyMn(arr, smallest, size);
    }

    if(smallest != i)
    {
        std::swap(arr[smallest], arr[i]);
        heapifyMn(arr, smallest, size);
    }
}

void heapifyMx(int arr[], int i, int size)
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    int largest = i;

    if (arr[L] <= size && arr[L] > arr[i])
    {
        largest = arr[L];
    }

    if(arr[R] <= size && arr[R] > arr[largest])
    {
        largest = arr[R];
    }

    if(largest != i)
    {
        std::swap(arr[L], arr[i]);
        heapifyMx(arr, largest, size);
    }
}

void maxHeap(int arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
    {
        heapifyMx(arr, i, n);
    }

    for(int i = n - 1 ; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
    }
}

void minHeap(int arr[], int n)
{
    for(int i = n/2 - 1; i >= 1; i--)
    {
        heapifyMn(arr, i, n);
    }

    for(int i = n - 1; i >= 1; i--)
    {
        std::swap(arr[0], arr[i]);
    }
}


int main()
{

}

