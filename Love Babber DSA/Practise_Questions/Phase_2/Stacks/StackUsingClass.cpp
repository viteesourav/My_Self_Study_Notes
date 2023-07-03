// This Shows the basic Operations of Stack using Arrays and class...
/* Operations:
    1) Push Operation
    2) Pop Operation
    3) peak Element
    4) Stack Empty or Not ?
 */

#include <bits/stdc++.h>
using namespace std;

// Implementation of Stack...
class Stack
{
    // Class proeperties...
    int *arr;
    int size;
    int top_index;

public:
    // parameterised Constructor to handle Object creation..
    Stack(int size)
    {
        this->size = size;
        top_index = -1;
        arr = new int[size]; // assigning memory dynamically
    }

    // Push Operation:
    void push(int data)
    {

        // check if the stack is full or not ?
        if (top_index == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        // Increment the index and store the data..
        top_index++;
        arr[top_index] = data;
    }

    // Pop Operation:
    int pop()
    {

        // check if the stack is empty or not ?
        if (top_index == -1)
        {
            cout << "stack underflow" << endl;
            return -1;
        }

        // store the element to return and decrease the index..
        int eleRemoved = arr[top_index];
        top_index--;
        return eleRemoved;
    }

    // peek element:
    int peek()
    {

        // check if the stack is empty ?
        if (top_index == -1)
        {
            cout << "stack underflow" << endl;
            return -1;
        }

        // return the ele at index...
        return arr[top_index];
    }

    // Check if the stack is empty...
    bool isEmpty()
    {

        if (top_index == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    Stack s(3);
    cout << s.isEmpty() << endl;

    s.push(5);
    s.push(6);
    s.push(7);

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.peek() << endl;
    s.push(12);
    cout << s.peek() << endl;

    cout << "Stack Implemented using Array" << endl;
    return 0;
}