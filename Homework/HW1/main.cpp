#include "/home/bigtasty/COSC2436/ArgumentManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void deleteSpaces(std::vector<string> &inputVector) //add int index later for recursive call
{

    if(inputVector.empty())
    {
        std::cout << "Please make sure the input file is populated!" << std::endl;
        return;
    }

    else
    {
        for(int index = 0; index < inputVector.size(); index++)
        {
            inputVector[index].erase(remove(inputVector[index].begin(), inputVector[index].end(), ' '), inputVector[index].end());
            inputVector[index].erase(remove(inputVector[index].begin(), inputVector[index].end(), '\t'), inputVector[index].end());
            inputVector[index].erase(remove(inputVector[index].begin(), inputVector[index].end(), '\n'), inputVector[index].end());
            inputVector[index].erase(remove(inputVector[index].begin(), inputVector[index].end(), '\r'), inputVector[index].end());
            //deleteSpaces(inputVector, outputVector, index + 1);
        }
        
    }

    for (int i = 0; i < inputVector.size(); i++)
    {
        if(inputVector[i].size() <= 1)
        {
            inputVector.erase(inputVector.begin() + i);
            i--;
        }
    }

    // for(int i = 0; i < inputVector.size(); i++)
    // {
    //     outputVector.push_back(inputVector[i]);
    // }

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
    std::vector<string> condensedInput;
    string temp;
    ifstream inPut("input2.txt");
    ofstream outPut("myAns.txt");

    while (!inPut.eof())
    {
        getline(inPut, temp);
        regularInput.push_back(temp);
        temp = "";
    }

    deleteSpaces(regularInput);

    for(int i = 0; i < regularInput.size(); i++)
    {
        std::cout << regularInput[i] << std::endl;
    }

    //assignValues(regularInput);

}