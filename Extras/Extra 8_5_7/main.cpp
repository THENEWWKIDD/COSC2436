//Create a pearl (struct) necklace (class) with the functions "addpearl" and "print"

#include <iostream>

struct pearl
{
    std::string color;
    pearl* hole;
};

class necklace
{
    private:
    pearl* head;

    public:
    void addpearl(std::string c);
    void print();
};

int main()
{

}