// Link: https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770
/*
    Basically, You need to find minimum number of brckets reverse so that an invalid bracket pattern becomes a valid pattern
*/
#include <bits/stdc++.h>
using namespace std;

// Function To Handle the valid Brackets or not ?
void validBrackets(stack<char> &s, string str)
{

    // iterate the string...
    for (int i = 0; i < str.length(); i++)
    {

        char ch = str[i];
        if (ch == '{')
            s.push(ch);
        else
        {
            // If closing bracket...
            // case1: If top is open bracket then pop from stack..
            // case2: if top is another closing bracket...
            if (!s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(ch);
        }
    }
};

int findMinimumCost(string str)
{
    // we will use stack and valid brackets appraoch..
    stack<char> st;

    // calling edge case to see if str len is odd ?
    if (str.length() & 1)
        return -1;

    // Calling a function to validate the str and fill the stack..
    validBrackets(st, str);

    // Now we will analysis the stack...
    if (st.empty())
        return 0; // If stack is empty, no manipulatio needed..
    else
    {
        int countOpenBracket = 0;
        int countClosedBracket = 0;
        // pop and count the element till stack is empty...
        while (!st.empty())
        {
            if (st.top() == '{')
                countOpenBracket++;
            else
                countClosedBracket++;
            st.pop();
        }

        // based on the pattern, general expression for min swaps needed..
        int ans = (countOpenBracket + 1) / 2 + (countClosedBracket + 1) / 2;
        return ans;
    }
}

/*
Approach/Logic:

    Min Cost to make Str Valid

{{{}   -> one swtich from { to } at 2nd pos, Will make the String valid !

Appraoch:

    -- check edge case: If the string length is odd, -> we cannot balance the brackets..
    -- Try to implement balance Parentheis Appraoch. -> Will return the stack.[This will remove the brackets which are balanced already]
    --> Possible Pattern we might see:
        1) {{{{{{{....
        2) }}}}}}.....
        3) }}}}}{{{{{..
    -- In either of this way, total Number has to be even in order to balance it, and formula is:
       (a+1)/2 + (b+1)/2 [a-> no of open brackets, b-> no of closed brackets]

    --- Solved ---
*/