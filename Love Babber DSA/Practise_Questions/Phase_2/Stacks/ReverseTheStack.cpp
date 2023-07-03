// Link:https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?leftPanelTab=0
/*
    BAsically, you are given a stack, Reverse the stack without using any other DS.
*/
#include <bits/stdc++.h>
using namespace std;

// function to handle pushing element at the bottom of the stack...
void putElementAtBotton(stack<int> &st, int x)
{

    // This also we will use Recusion to Push the element at the end...
    // base case:
    if (st.empty())
    {
        st.push(x); // once stack is empty, push the element x.
        return;
    }

    // Keep the top element on hold..
    int peek = st.top();
    st.pop();

    // calling recursion...
    putElementAtBotton(st, x);

    // while coming back... we will push back the element that we are holding...
    st.push(peek);
}

// Approach: Recursion we will use, One case we will solve, REst recursion will solve...
// TC: O(n2) SC: O(n) [Why O(n), each Stack, we are sending the same stack by referenec..]
void solve(stack<int> &s)
{

    // base case: When stack becomes empty then return...
    if (s.empty())
        return;

    // We will solve one case, Lets Try putting the top element at bottom !
    int ele = s.top(); // holding the top element..
    s.pop();

    // calling Recursion...
    solve(s); // We assume, Recursion will reverse rest of the elements in stack..

    // Now we have stack that is reversed, and we have an ele at hold...
    // We will try to put the element at the bottom..
    putElementAtBotton(s, ele);
};

void reverseStack(stack<int> &stack)
{
    // Write your code here
    solve(stack);
}

/*
Appraoch/Logic: Recursion [we will solve 1 case, Rest Recursion will handle.]

    -- First, we will take out the top Element from the stack and put it on hold.
    -- Next we call Recursion and assume Rest of the stack is Reversed already...
    -- Now we have a Reversed Stack, and an element on hold, We need to put element at the end..
       -- we will use push element at the bottom logic. [This also uses Recursion to do so]

    --Solved--

*/