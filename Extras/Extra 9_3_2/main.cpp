//Create a linear search algorithm

#include <iostream>

struct node
{
    node* next;
    int val;
};

class list
{
    private:
    node* head;

    public:
    bool search(int k);
};

bool list::search(int key) //Write recursively
{

    node* cu = head;
    
    while(cu -> val != key && cu -> next != nullptr)
    {
        cu = cu -> next;
    }

    if (cu -> next == nullptr)
    {
        return false;
    }

    else
    {
        return true;
    }
}

int main()
{
    
    list stuff;
    std::string input;

    std::cout << "What would you like to place into the linked list?" << std::endl;
    std::cout << "Please only use character values." << std::endl;
    std::cout << "Use 'end' to indicate that you have finished your input." << std::endl;

    std::cin >> input;

    while (input != "end" || input != "End" || input != "END")
    {
        std::cin >> input;
    }
    


}
