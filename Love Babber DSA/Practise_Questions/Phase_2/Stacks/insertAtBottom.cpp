// Link: https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTab=0
/*
    Basically, You given a stack and an element x, push x at the bottom of stack without using any other DS..
*/

#include <bits/stdc++.h>
using namespace std;

// Appraoch: Recursion on the Elements of the stack, Hold the element, Go Recursion then push it back
// TC: O(n)
void solve(stack<int> &s, int x)
{

    // base case: When we reach at the end...
    if (s.empty())
    {
        s.push(x); // when the stack reaches empty, push x..
        return;
    }

    // Now lets check the top element and popit and hold it...
    int ele = s.top();
    s.pop();

    // Now we will go inside Recursion...
    solve(s, x);

    // While coming back from Recursion, we will add the ele that we are holding..
    s.push(ele);
};

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    // Write your code here.
    // we will solve this using Recursion Approach...
    solve(myStack, x);
    return myStack;
}
