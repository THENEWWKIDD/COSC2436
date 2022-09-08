#include "/home/bigtasty/COSC2436/ArgumentManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
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

void assignValues(std::vector<string> &in_Values, int index) //uses the vector to find letters and assign their number value to their ID placeholder(s)
{
    std::vector<string> letterVector;
    std::vector<string> numVector;
    std::vector<char> genVector;
    std::stringstream letter;
    std::string letterCpy;
    std::stringstream number;
    std::string numCpy;

    std::string temp = in_Values[index];
    for(int i = 0; i < temp.find("id"); i++)
    {
        if (temp[i] != ';')
        {
            genVector.push_back(temp[i]);
        }
    }

    for(int i = 0; i < genVector.size(); i++)
    {
        if (isalpha(genVector[i]))
        {
            letter << genVector[i];
        }

        else if(isdigit(genVector[i]))
        {
            number << genVector[i];
            // while (isdigit(genVector[i]))
            // {
            //     number << genVector[i];
            //     i++;
            // }
        }

        letter >> letterCpy;
        number >> numCpy;
        
        if(letterCpy != "")
        {
            letterVector.push_back(letterCpy);
        }
        
        if(numCpy != "")
        {
            numVector.push_back(numCpy);
        }
        

        letter.str(std::string());
        number.str(std::string());
    }
}




int main(int argc, char* argv[])
{
    std::vector<string> regularInput;
    std::vector<string> condensedInput;
    string temp;
    ifstream inPut("input2.txt");
    ofstream outPut("myAns.txt");
    ifstream cmdFile("command2.txt");

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

    assignValues(regularInput, 0);
}
