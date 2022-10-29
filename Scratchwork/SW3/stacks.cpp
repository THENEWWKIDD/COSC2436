#include <iostream>
#include <stack>

struct node
{
    int val;
    node* next;
};

class stack
{
    private:
    node* head = nullptr;
    node* tail = nullptr;

    public:
    //void push(int data);
    //node* pop();
    //void peek();
    //void printLL();
    void infixToPost(std::string data);
    
};

// void stack::push(int data)
// {
//     node* temp = new node;
//     node* cu = head;
//     temp -> val = data;

//     if(head == nullptr)
//     {
//         head = temp;
//     }

//     else
//     {
//         while(cu != nullptr)
//         {
//             cu = cu -> next;
//         }

//         cu = temp;
//     }
// }

void infixToPost(std::string data)
{
    char ch;
    int priority;
    std::string temp = "";
    std::stack <char> st;


    if(data.length() <= 0)
    {
        return;
    }

    for(int i = 0; i < data.length(); i++)
    {
        ch = data[i];
        while(isdigit(ch))
        {
            temp += ch;
            i++;
        }

        if(ch == '*' || ch == '/')
        {
            priority = 1;
        }

        else if(ch == '+' || ch == '-')
        {
            priority = 0;
        }

        

    }
}

int main()
{
    //stack list;
    //list.push(5);

    infixToPost("2 + 7 * 6 - 3 / 4");
}

//Write a function to add into a stack as an array
//Write a stack as a template (main or function)