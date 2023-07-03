// Basically implementing 2 Stacks in a single Array...
/* NOTE:
    -- TAke an Array, one stack starts from left, Other one start from Right.
    -- For Space Optimization, WE will not fix the size of the stacks to size/2,
       Instead, we will use top index of both the stacks to decide whether its overflow or not ?
*/

#include <bits/stdc++.h>
class TwoStack
{

    int *arr;
    int size;
    int left_Stack;
    int right_Stack;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        // Write your code here.
        size = s;
        left_Stack = -1;
        right_Stack = size;
        arr = new int[size];
    }

    // Push in stack 1.
    void push1(int num)
    {
        // Write your code here.
        if (left_Stack + 1 == right_Stack)
            return; // Stack Overflow Condition...
        left_Stack++;
        arr[left_Stack] = num;
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Write your code here.
        if (right_Stack - 1 == left_Stack)
            return; // Stack Overflow Condition...
        right_Stack--;
        arr[right_Stack] = num;
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Write your code here.
        if (left_Stack == -1)
            return -1; // Stack underflow Condition...
        int eleRemoved = arr[left_Stack];
        left_Stack--;
        return eleRemoved;
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        if (right_Stack == size)
            return -1; // Stack underflow Condition...
        int eleRemoved = arr[right_Stack];
        right_Stack++;
        return eleRemoved;
    }
};
