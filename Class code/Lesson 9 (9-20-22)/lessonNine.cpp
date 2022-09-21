#include <iostream>
#include <vector>

//bubble, selection, and insertion sorts
void bubbleSort(std::vector<int> input, int n) //O(n^2)
{
    bool sorted;
    for (int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(input[i])
        }
    }

}

void selectionSort(std::vector<int> input)
{

}

void insertionSort(std::vector<int> input)
{

}

//creating a circular linked list
struct Node
{
    Node* next = nullptr;
    Node* prev = nullptr;
    int data;
};

class linkedList
{
    private:
    Node* head;
    Node* tail;

    public:
    void print();
    void addAtHead();
    void addAtTail();
    void deleteTail();
    void deleteHead();
};



int main()
{
    linkedList list;
}