// Link: https://leetcode.com/problems/valid-parentheses/description/
/*
    Basically, Check if the given parenthesis set is valid or not using stack...
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {

        // We will use stack to solve this...
        stack<char> st;

        // iterating the given String...
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '{' || ch == '[' || ch == '(')
            {
                // If any starting bracket is found -> push in stack...
                st.push(ch);
            }
            else
            {
                // If any closing bracket is found -> Check...
                if (st.empty()) // check if the stack is empty..
                    return false;
                else if ((st.top() == '{' && ch == '}') || (st.top() == '[' && ch == ']') || (st.top() == '(' && ch == ')'))
                {
                    st.pop();
                }
                else
                {
                    return false; // If mismatch between top and ch, then not balanced...
                }
            }
        }

        // check if the stack is empty or not ?
        if (st.empty())
            return true;
        return false;
    }
};