struct Node
{
    Node* next;
    int data;
};

class linkedList
{
private:
    Node* head;
    Node* tail;
public:

    void isEmpty();
    string reverse(vector<int> inV, int begin, int end);
    void removeHead();
    void removeTail();
    void addAtEnd(int input);
    void addAtBeg(int input);
};


