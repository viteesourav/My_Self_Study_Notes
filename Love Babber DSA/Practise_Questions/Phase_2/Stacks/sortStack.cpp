// Link: https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?leftPanelTab=0
/* Baiscally,
   Given a stack, sort it without using any other Data structure...
*/
#include <bits/stdc++.h>
using namespace std;

// Fucntion: we have element and stack, we need to push element  in the stack in sorted way
// Appraoch: we will use Recursion to push it at its correct place..
void pushSortedWay(stack<int> &s, int x)
{

    // base case: if stack is empty or stack is not empty and top val is less than x, push
    if (s.empty() || (!s.empty() && s.top() <= x))
    {
        s.push(x); // Push the element..
        return;
    }

    // lets keep the top element on hold and call Recursion...
    int p = s.top();
    s.pop();

    // call Recursion...
    pushSortedWay(s, x);

    // while coming back, just push the element on hold...
    s.push(p);
}

// Approach: REcursion,
// we will hold the element, Recursion and then Push the element in sorted way.
void solve(stack<int> &st)
{

    // baseCase: When the stack is empty, return..
    if (st.empty())
        return;

    // Take out the top element and hold it..
    int peek = st.top();
    st.pop();

    // Now Recursion,
    solve(st);

    // while coming back we will push the element in hold, in sorted way...
    pushSortedWay(st, peek);
};

void sortStack(stack<int> &stack)
{
    // Appraoch: Recursion
    solve(stack);
}

/*

Approach/Logic:

Stort the stack...

    Stack: 5 -2 9 -7 3   ->   9 5 3 -2 -7
           t                   t

Approach: Recursion Approach, we will hold the element and then insert in Sorted way...

    -- Pull the element from the top and hold it.
    -- Call Recursion, Go till the end of the stack...
    -- Now while coming back, While inserting back, insert in sorted way inside the stack. [Another Recursion in Play]

** Stack is sorted **

*/