#include "/home/bigtasty/COSC2436/ArgumentManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stack>

int priority(char inCh)
{
    if(inCh == '*' || inCh == '/')
    {
        return 2;
    }

    else if(inCh == '+' || inCh == '-')
    {
        return 1;
    }

    else
    {
        return -1;
    }

}

string pemdas(std::string inStr)
{
    stack<char> myS;
    char temp;
    string result;

    for(int i = 0; i < inStr.length(); i++)
    {
        temp = inStr[i];

        if(isdigit(temp))
        {
            result += temp;
        }

        else if(temp == '(')
        {
            myS.push(temp);
        }

        else if(temp == ')')
        {
            while(myS.top() != '(')
            {
                result.push_back(myS.top());
                myS.pop();
            }

            myS.pop();
        }

        else
        {
            while(!myS.empty() && priority(temp) <= priority(myS.top()))
            {
                result.push_back(myS.top());
                myS.pop();
            }
            myS.push(temp);
        }
    }

    while(!myS.empty())
    {
        result.push_back(myS.top());
        myS.pop();
    }

    return result;

}

double evaluatePostfix(string s) {
  stack<int> st;

  for (int i=0; i<s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9')
      st.push(s[i] - '0');
    else {
      double val1 = st.top(); st.pop();
      double val2 = st.top(); st.pop();
      switch (s[i]) {
        case '+': st.push(val2 + val1); break;
        case '-': st.push(val2 - val1); break;
        case '*': st.push(val2 * val1); break;
        case '/': st.push(val2 / val1); break;
      }
    }
  }
  return st.top();
}


// void pemdas(std::string inStr)
// {
//     double numParenthesis = 0;
//     bool inParenthesis = false;
//     std::vector<char> arr;

//     for (int i = 0; i < inStr.size(); i++)
//     {
//         if(isdigit(inStr[i]))
//         {
//             arr.push_back(inStr[i]);
//         }

//         else
//         {
//             //check if in parenthesis
//             if(inStr[i] == '(')
//             {
//                 inParenthesis = true;
//                 numParenthesis++;

//                 while(inParenthesis = true)
//                 {
//                     if(inStr[i]== ')')
//                     {
//                         numParenthesis--;
//                         if(numParenthesis == 0)
//                         {
//                             inParenthesis = false;
//                         }
//                     }

//                     else
//                     {
//                         //pop the current
//                         while (priority(inStr[i]) <= priority(peek() -> val))
//                         {
//                             //place into end string
//                             arr.push_back(peek() -> val);

//                             //pop() the top
//                             pop();

//                             i++;
//                         }
//                     }

//                 }
//             }

//             //

//             else
//             {
//                 if(priority(inStr[i]) <= priority(peek() -> val))
//                 {
//                     arr.push_back(peek() -> val);

//                     pop();

//                     i++;
//                 }
                
//             }
//         }
//     }
// }


int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    stack<char> myS;
    int openP = 0;
    std::string temp;
    double posOfX;
    double x;
    std::string xFuncA;
    std::string xFuncB;
    double finalVal;
    double result;

    std::vector<string> regularInput;
    string input = am.get("input");
    string output = am.get("output");

    ifstream inPut(input);
    ofstream outPut(output);
    
    while (!inPut.eof())
    {
        getline(inPut, temp);
        temp.erase(remove(temp.begin(), temp.end(), '\n'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '\r'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    }
    
    if (temp.substr(0, 1) == "x")
    {
        xFuncA = temp.substr(1, 1);
        finalVal = stod(temp.substr(temp.find("=") + 1));
        temp = temp.substr(2, temp.find("=")-2);
    }

    else
    {
        xFuncB = temp.substr(temp.find("x") -1, 1);
        finalVal = stod(temp.substr(temp.find("=") + 1));
        temp = temp.substr(0, temp.find("x") - 1);
    }

    std::string postEval = pemdas(temp);

    result = evaluatePostfix(postEval);

    if(xFuncA.length() >= 1)
    {
        if(xFuncA == "*")
        {
            x = finalVal / result;
        }

        else if(xFuncA == "/")
        {
            x = finalVal * result;
        }

        else if(xFuncA == "+")
        {
            x = finalVal - result;
        }

        else
        {
            x = finalVal + result;
        }
    }

    else if (xFuncB.length() >= 1)
    {
        if(xFuncB == "*")
        {
            x = finalVal / result;
        }

        else if(xFuncB == "/")
        {
            x = result / finalVal;
        }

        else if(xFuncB == "+")
        {
            x = finalVal - result;
        }

        else
        {
            x = result - finalVal;
        }
    }

    outPut << fixed;
    outPut << setprecision(2) << x;

    //if the priority of the operator in the stack is higher than the current one, push
    //if the priority of the operator in the stack is lower than or equal to the current one, pop
    //parenthesis operators are immediately popped after closing parenthesis is the current one


    
}