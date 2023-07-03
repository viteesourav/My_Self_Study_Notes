// Links: https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0
/*
    Basically you are given an Operation, Detect if the bracket has redundant bracket or not ?
eg: ((a+b))  -> Redundant Bracket
    (a+b) -> Valid Bracket
*/

#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    // We will iterate the string taking out character one by one...
    for (int i = 0; i < s.length(); i++)
    {

        char ch = s[i]; // take out the charcter...

        // if it's a open bracket or any Operation push it in stack..
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            // If closed bracket...
            // case1: when we have the stack is empty..
            // case2 : when we have the top element as (
            // case3: we have operation in stack.
            if (st.empty() || (!st.empty() && st.top() == '('))
                return true;
            else
            {
                // we have few operations in the stack..
                while (!st.empty() && st.top() != '(')
                {
                    st.pop(); // pop out all the operations..
                }
                if (!st.empty())
                    st.pop(); // pop the open bracket also...
            }
        }
    }

    return false; // If It didn't catch above, then not redundant..
}

/*
Approach/Logic:

Redundant Brackets

 (a+c*b)+(c))  ---> trur
 (a + b) ---> false
 ((a + b))   --> true

If we have any operation inside the closing and opening brackets then okay if not then its Reduendant.

Appraoch: Normal Loop Appraoch.

 -- We will iterate the string.. If any open bracket or operator, push it in stack.
 -- If we get any alphabet, ignore.
 -- If we get closing bracket, pop all operator till it gets to open bracket, Pop Open bracket also.
 -- IF we have no operator and Jsut closing bracket then -> Redundant Branckets

 -- At the end If nothing detected then -> Valid Brackets.

 ** DONE **   [Possible we need to check edge cases here...]

*/
