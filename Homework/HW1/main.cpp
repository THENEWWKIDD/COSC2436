#include "/home/bigtasty/COSC2436/ArgumentManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<string> deleteSpaces(std::vector<string> input) //function that recusively deletes the spaces in a vector
{
    int i = 0;
    while(i < input.size())
    {
        input[i].erase(std::remove(input[i].begin(), input[i].end(), ' '), input[i].end());
        i++;
    }

    return input;
}

void assignValues(std::vector<string> in_Values) //uses the vector to find letters and assign their number value to their ID placeholder(s)
{
    int position;

    int i = 0;
    while (i != in_Values.size())
    {
        if (in_Values[i] == "#")
        {
            position = i;
        }

        else
        {
            ;
        }
        i++;
    }
    return;
}

int main(int argc, char* argv[])
{
    std::vector<string> condensedInput;
    string temp;
    ifstream inPut("input2.txt");
    ofstream outPut("myAns.txt");

    while (!inPut.eof())
    {
        getline(inPut, temp);
        condensedInput.push_back(temp);
        temp = "";
    }

    deleteSpaces(condensedInput);

    for(int i = 0; i < condensedInput.size(); i++)
    {
        std::cout << condensedInput[i] << std::endl;
    }

    //

}