#include<iostream>
#include<stack>
using namespace std;

bool ispar(const string &s)
{
    stack<char> stk;
    for(int i = 0; i < s.length(); i++)
    {
        // Push opening brackets onto the stack
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stk.push(s[i]);
        }
        else
        {
            // Check if stack is empty or top of stack doesn't match the closing bracket
            if(!stk.empty() && 
               ((stk.top() == '(' && s[i] == ')') ||
                (stk.top() == '{' && s[i] == '}') ||
                (stk.top() == '[' && s[i] == ']')))
            {
                stk.pop(); // If it matches, pop the top
            }
            else
            {
                return false; // If it doesn't match, return false
            }
        }
    }
    return stk.empty(); // If stack is empty, all brackets are balanced
}

int main()
{
    string s = "{()}[]";
    if(ispar(s)){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}
