// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
/*
Basically, You given towers of different heights, Find the max area of a rectangle that is possible...

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // function to Handle the Finding of next min element on Right...[stack is used]
    // TC: O(n)
    vector<int> CalRightMinArr(vector<int> &arr, int n)
    {
        // NOTE: we will store index in stack, and comapre the values...
        stack<int> st;
        st.push(-1); // for the right most element..
        vector<int> rightmin(n);

        // loop from right to left..
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];

            // check in the stack..
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            rightmin[i] = st.top(); // Add in the ans array in the reverse order...
            st.push(i);             // update the stack by adding the current index..
        }
        return rightmin;
    };

    // function to Handle the Finding of next min element on left...[stack is used]
    // TC: O(n)
    vector<int> CalLeftMinArr(vector<int> &arr, int n)
    {
        // NOTE: we will store index in stack, and comapre the values...
        stack<int> st;
        st.push(-1); // for the left most element..
        vector<int> leftmin(n);

        // loop from left to right..
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];

            // check in the stack..
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            leftmin[i] = st.top(); // Add in the ans array in the reverse order...
            st.push(i);            // update the stack by adding the current index..
        }
        return leftmin;
    };

    // Aprroach2: Solving using finding the next min element index on Right and left Logic...
    int solve(vector<int> &heights)
    {

        int n = heights.size(); // number of towers given..

        // Find the right most min index for each element...
        vector<int> rightMinArr(n);
        rightMinArr = CalRightMinArr(heights, n);

        // Find the left most min index for each element...
        vector<int> leftMinArr(n);
        leftMinArr = CalLeftMinArr(heights, n);

        // now we know the for an element, which is the index of min val on left and right...
        int maxArea = INT_MIN;
        // iterate over all the elements...
        for (int i = 0; i < n; i++)
        {
            // To avoid negative area...
            // basically if its the smallest, then we can take till the end of the heights size..
            if (rightMinArr[i] == -1)
            {
                rightMinArr[i] = n;
            }

            // For an element..
            int height = heights[i];
            int width = rightMinArr[i] - leftMinArr[i] - 1; // This is the horizontal spread..

            int newArea = height * width;
            maxArea = max(maxArea, newArea); // Take the max possible Area...
        }
        return maxArea;
    };

public:
     int solve3(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st;   //tracks <index, height>

        //iterate in the histogram....
        for(int i=0; i<heights.size(); i++) {

            int start = i;  //The current bar starts at ith index..

            // If stack already holds any elements and it's height > height[i] => the hight in stack's top cannot to extend to right => so pop them...
            while(!st.empty() && st.top().second > heights[i]) {
                pair topHeight = st.top();
                st.pop();
                maxArea = max(maxArea, topHeight.second * (i - topHeight.first)); // currentArea = bar height * (current index - bar's index) => update max Area.
                start = topHeight.first;  // we update the current bar starting to left, since left bar height > curr bar height.
            }
            st.push({start, heights[i]});  //push the current bar starting index and it's height.
        }

        //there might be some element left in stack ==> these bars can extend till the end of heights list..
        while(!st.empty()) {
            pair topHeight = st.top();
            int area = topHeight.second * (heights.size() - topHeight.first);
            maxArea = max(maxArea, area);
            st.pop();
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        // we will solve it using stack and left and right next min element Logic...
        // return solve(heights);
        return solve3(heights);
    }
};

/*
Approach/Logic:

Largest Rect in Histogram [Area of the max Rectangle]


2 1 5 6 2 3  -> Plot this all heights with width 1, Find max possible area of rect.

Approach 3: [Most Optimised Approach] -> O(n), O(n)

 0 1 2 3 4 5
 2 1 5 6 2 3

initial:
    1. a variable maxArea -> tracks the max possible area.
    2. a stack => <index, height> => stores bar's starting index [as the bar can be extended to left if possible] and it's height.
Steps:
    1. Start iterating in the histogram.
        1. Lets assume, the starting index of curr Height is ==> start.
        2. Now If the stack is not empty and the height at top > curr Height [i.e the stack's top bar hieght cannot be extended to right, as the curr Height is smaller]
            -> Pop the bar from stack.
            -> Calculate the area of the popped bar => bar's height * (currentIndex - bar's index) [current index because => we are measuring area from the current index point]
            -> update maxArea.
            -> NOw for the curr bar, since the popped bar height is greater i.e we can extend the curr bar to left ==> update start as the popped bar's index.
        3. After all this, We may have any element left in stack.
            -> This means for these bars -> they can extend till the end of the no of height given,
            -> Find area of these => bar's height * (len(height) - bar's index);
            -> update maxArea.
            -> Pop form the stack.
        4. You have the max possible Area in the histogram.




Appraoch 1: Brute Force [TC: O(n2) ] --> I will extend the bar to it's left and right till i can, then find the area..

 0 1 2 3 4 5
 2 1 5 6 2 3

 Area -> height * breadth. [height of the bars are constant, the breadth is varying...]

 -- Run on For lop on the index...
 -- For each element, look on right part, can you extend the bar towards right, If yes, Do it and track the index. let sat m
 -- look left on its left part till you can extend the bar towards left, do it and track the index, let say at index n.
 -- Now we form a rectangle, width: m-n-1 and height will value at element.
 -- compare for all elements and find the max possible area.





 
Appraoch2: Using Stack and next min element on the left and right side... [TC: O(n) SC: O(n)]

 0 1 2 3 4 5
 2 1 5 6 2 3

-1, represent no min element on right side...

 leftMinArr:
  0  1 2 3 4 5
 -1 -1 1 2 1 4

 rightMinArr:
  0  1 2 3  4  5
  1 -1 4 4 -1 -1  -> represents the index where the val is min.

 -- Use stack to Find the left mins and right min for all the elements.

 -- For each element, Find the right min element position, let say at index m
 -- Find the left min element position, let say at index n.

 -- Now we form a rectangle, width: m-n-1 and height will value at element.
 -- compare for all elements and find the max possible area.
 -- Iterate through them For each element and Find the max area of rect.


*/