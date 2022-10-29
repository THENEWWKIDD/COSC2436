#include <iostream>
#include <stack>


void inToPost(std::string data)
{
    char ch;
    std::stack<char> st;
    std::string result;

    for (int i = 0; i < data.length(); i++)
    {
        ch = data[i];
        if(isdigit(data[i]))
        {
            result += data[i];
        }

        else if(data[i] == '(')
        {
            st.push(data[i]);
        }

        else if(data[i] == ')')
        {
            while(!st.empty())
            {
                result += st.top();
                st.pop();
            }
        }

        else
        {
            while(data[i] == '+' || data[i] == '-')
            {
                if(st.empty())
                {
                    st.push(data[i]);
                    break;
                }

                else if(st.top() == '(' || st.top() == ')')
                {
                    st.pop();
                    break;
                }

                else
                {
                    result += st.top();
                    st.pop();
                    
                }
                
            }

            st.push(data[i]);
        }
    }

    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }

    std::cout << result << std::endl;
}


int evalPost(std::string data)
{
    char ch;
    std::stack<int> st;
    for(int i = 0; i < data.length(); i++)
    {
        ch = data[i];
        // if(isdigit(data[i]))
        // {

        // }
    }
    return 0;
}

int main()
{
    inToPost("(6+1)+3-2");

}