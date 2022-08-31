#include "/home/bigtasty/COSC2436/ArgumentManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<string> deleteSpaces(std::vector<string> inputVector, int index) //function that recusively deletes the spaces in a vector
{
    //Loop through the each element (string) of inputVector
    int i = 0;
    std::vector<char> discardVector;
    string selectedStr = inputVector[index];
    while (i < selectedStr.size())
    {
        if(selectedStr[i] == ' ' || selectedStr[i] == '\n')
        {
            discardVector.push_back(selectedStr[i]);
            i++;
        }

        else
        {
            
            i++;
        }
        
    }
    
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
    std::vector<string> regularInput;
    string temp;
    ifstream inPut("input2.txt");
    ofstream outPut("myAns.txt");

    while (!inPut.eof())
    {
        getline(inPut, temp);
        regularInput.push_back(temp);
        temp = "";
    }

    deleteSpaces(regularInput, 0);

    for(int i = 0; i < regularInput.size(); i++)
    {
        std::cout << regularInput[i] << std::endl;
    }

    //

}