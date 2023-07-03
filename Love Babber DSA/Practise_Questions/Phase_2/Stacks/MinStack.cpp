/* Basically,
  Design a new Class using a stack, This class should have additional method that will retrun the min stack Elemenet at a  given instance
  NOTE: TC should be O(1) and SC should be O(1)
2 ways:
  1) Use the computation of miniVal based on previous miniVal and elements.
  2) Use pairs to store the element and miniVal on each Push Operation in the stack.

*/

// Approach 1: Using the computation method where we are trying the fetch the previous miniVal based on Formula...
// Link: https://www.codingninjas.com/studio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465
#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
    // Define the data members.
    stack<int> st;
    int miniVal;
    /*----------------- Public Functions of SpecialStack -----------------*/
public:
    void push(int val)
    {
        // check if the stack is empty ?
        if (st.empty())
        {
            // If stack is empty, push the element and update the miniVal
            st.push(val);
            miniVal = val;
        }
        else
        {
            // If stack already have some elements, check if curr Element < miniVal ?
            if (val < miniVal)
            {
                long long modifiedVal = 2 * val - miniVal;
                st.push(modifiedVal);
                miniVal = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    int pop()
    {
        // Check if the stack is underflowing ??
        if (st.empty())
            return -1;

        // Taking the current top element and updating the minVal
        int currTop = st.top();
        st.pop();
        if (currTop > miniVal)
        {
            return currTop;
        }
        else
        {
            int prevMin = miniVal;
            miniVal = (2 * miniVal - currTop);
            return prevMin;
        }
    }

    int top()
    {
        // Check if the stack is underflowing ??
        if (st.empty())
            return -1;

        // Now top, we will compare the element in stack and miniVal
        int currTop = st.top();
        if (currTop > miniVal)
            return currTop;
        else
            return miniVal;
    }

    bool isEmpty()
    {
        return st.empty();
    }

    int getMin()
    {
        // Check if the stack is underflowing ??
        if (st.empty())
            return -1;

        return miniVal;
    }
};

// Appraoch 2: useing Pair to store the element and minVal in stack.[while pushing and poping, update miniVal]
class MinStack
{
    stack<pair<int, int>> st;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        // When Pushing into the stack,
        // check is the stack is empty ?
        if (st.empty())
        {
            // If stack is empty,
            st.push(make_pair(val, val)); // Push val and miniVal as same Value..
        }
        else
        {
            // If stack already has data...
            int miniVal = min(st.top().second, val); // compare the val and miniVal, update miniVal.
            st.push(make_pair(val, miniVal));        // push the element and miniVal.
        }
    }

    void pop()
    {
        // Check for underflow Condition:
        if (st.empty())
            return;
        // When Poping out of the stack, simply pop it out
        st.pop();
    }

    int top()
    {
        // Check for underflow Condition:
        if (st.empty())
            return -1;
        // Take the top element from Stack and return the first element of the pair.
        return st.top().first;
    }

    int getMin()
    {
        // Check for underflow Condition:
        if (st.empty())
            return -1;
        // Take the top element from Stack and return the second element of the pair.
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*
Min Stack

Appraoch 1: [Use the Formula during push and pop to Remember previous mini] [TC: O(1), SC: O(N) [stack used][ignoring this, SC: O(1), no additonal space used]

-- In this Appraoch, Take a mini, and store the INT_MAX in it at first.

1) Push:

  -- If the stack is empty, Then push the element and update the min to element.
  -- IF the element < min, Update min and push[2*element - min]
     ELSE just push the element.

2) POP:

  -- If the top is > min then just pop it.
  -- IF top < min, then update min as [2*min - top] -> takes to previous min Value.
  -- Pop the element.

3) TOP:
   -- If the top > min, just retrun the top.
   -- If top < min, then return min -> That represent the top Value.

Problem:
-- If too high val is passed, then multiply 2 is taking the val out of bound.
-- Basically,
If we want to avoid Operations, we should follow Approach 3


Appraoch 2: [Use pairs<int, int> type in stack] TC: O(1) SC: O(N) [since using a stack] [ignoring this it will SC: O(1), no additional space]

-- We defined a stack with elements as pair of currVal and the miniVal at that time.

1) PUSH:
-- Check if the stack is empty ?
   if empty, Push both currVal and miniVal as the currVal.
   if not empty, Take the top from the stack, compare the second element of pair with currVal, store the currVal and miniVal.

2) POP: Just POP the stack, no update needed.

3) TOP: return the first element of the pair.

4) GetMin: Return the the second element of the pair.
*/