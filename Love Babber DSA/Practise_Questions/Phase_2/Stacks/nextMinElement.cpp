// Link: https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=0
/*
    Basically, For each element of the given array, Find the min most element on the right part...
    If min element not there for an element, then store -1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Approach: we will use stack to store right min element
    stack<int> st;
    vector<int> ans(n); // vector to store the ans..

    st.push(-1); // Pushing -1 to stack for the right most element in arr..

    // Traversing the given arr from right to left..
    for (int i = n - 1; i >= 0; i--)
    {

        // take the current element...
        int curr = arr[i];

        // compare with the stack top...
        // case1: If top is smaller, just push curr in stack..
        // case2: If top is larger, follow bellow...
        // top element is larger....[Pop stack till the top <= curr]
        while (!st.empty() && st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top(); // pushing the top in ans using the index of the above for loop.[It will push in backward way]
        st.push(curr);
    }

    return ans;
}

/*
Appraoch/Logic:

    Next min Element

2 3 1 -> 1 1 -1

Stack: -1 1

Next min element of 2 -> 1
Next min element of 3 -> 1
Next min element of 1 -> -1 [For Rightmost element, No min element exist so -1]

Approach: Using a Stack [TC: O(n) SC: O(n)] [Stack will stores the min element for each element.]

 -- Stack we will have initially with -1[For right most ele]
 -- Will traverse the Array from right to left.
 -- For each Element, Check the stack
    -- If ele is samller, That is smallest ele for curr index ele, push stack top in ans arr.
    -- If ele is larger, Pop till it becomes smaller. Push the stack top in the ans arr..
 -- After finding, push the curr index in stack.

Note:
-- Since we are travelling backward, we will push element in ans with index, instead of using push_back and then reversing it.

*/