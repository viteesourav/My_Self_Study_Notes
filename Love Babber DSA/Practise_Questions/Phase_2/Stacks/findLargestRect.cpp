// Link: https://leetcode.com/problems/maximal-rectangle/description/
/*
You have been given a binary matrix. You need to find the max Area of rect possible.
Note: Here in the question the elements in matrix are char,
so additional steps: create a new matrix v with all element as int and then solve...

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // fucntion to help finding the nextRightmin element index...
    vector<int> findNextRightmin(vector<int> arr, int n)
    {

        stack<int> st; // Note: Here stack just keep track of the index...
        st.push(-1);
        vector<int> nextMinRight(n);

        // now traverse the char array from right to left...
        for (int i = n - 1; i >= 0; i--)
        {

            // check the stack...
            while (st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nextMinRight[i] = st.top();
            st.push(i);
        }
        return nextMinRight;
    };

    // fucntion to help finding the nextLeftmin element index...
    vector<int> findNextLeftmin(vector<int> arr, int n)
    {

        stack<int> st; // Note: Here stack just keep track of the index...
        st.push(-1);
        vector<int> nextMinLeft(n);

        // now traverse the char array from right to left...
        for (int i = 0; i < n; i++)
        {

            // check the stack...
            while (st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nextMinLeft[i] = st.top();
            st.push(i);
        }
        return nextMinLeft;
    }

    // function to help find the max possible histogram from a given Row...
    int maxAreaHistogram(vector<int> arr)
    {
        // This we will Findout using the stack and finding the nextminElement on left and Right side...
        int n = arr.size();
        // Lets find the nextLeftmin and nextRigthmin index...
        vector<int> nextLeftArr(n);
        nextLeftArr = findNextLeftmin(arr, n); // This will have the nextLeftmin element index's

        vector<int> nextRightArr(n);
        nextRightArr = findNextRightmin(arr, n); // This will have the nextRightmin element index's

        // now we will iterate the array and find the max possible histogram area...
        int area = INT_MIN;

        for (int i = 0; i < n; i++)
        {

            int height = arr[i]; // Get the height of the histogram...

            // check the edge case for the width cal..
            if (nextRightArr[i] == -1)
                nextRightArr[i] = n;

            int width = nextRightArr[i] - nextLeftArr[i] - 1; // This gives the width of the histogram..
            int currArea = height * width;
            area = max(area, currArea); // stors the max possible histogram area..
        }
        return area;
    };

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {

        // Appraoch: we will try to solve this problem using the max Area in histogram Algo..
        // TC:O(nxm)  SC: O(m) where n is no of rows and m is no of columns.

        // Converting the given char matrix to int matrix...
        vector<vector<int>> v(matrix.size());

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                v[i].push_back(matrix[i][j] - 48);
            }
        }

        // Appraoch starts from here....

        int maxArea = maxAreaHistogram(v[0]); // area for the first Row

        // Now we will iterate over the remanining Row...
        for (int i = 1; i < v.size(); i++)
        {

            // For the new base Row we will update the Row elements...
            for (int j = 0; j < v[i].size(); j++)
            {

                ////update currRowele + previousRowElements...
                // Note: update only when the curr row ele is not zero
                if (v[i][j] != 0)
                    v[i][j] = v[i][j] + v[i - 1][j];
                else
                    v[i][j] = 0;

                // now we have the updated Row, lets find the max possible area..
                int area = maxAreaHistogram(v[i]);

                maxArea = max(maxArea, area); // compare and store the maxArea...
            }
        }
        return maxArea;
    }
};

/*
Appraoch/Logic:

Max Rectangle in Binary Matrix

Logic:
-- Using the elements in a given Row, we will prepare a histogram and Try to find the max rect in that Histogram.
-- Once we know the max area of that Row, We will move the base to next Row i.e Now the Histogram is made up of Current Row and the previous Row.
-- then Find the Area, and store maxArea

[Done]

Appraoch: [We will use the logic For Finding max Area in Histogram]

 -- First we will travese the given matrix row by row.
 -- Find the max possible area for the elements in the First Row.
 -- Loop Over Row by Row:
    -- Update the Row element as sum of elements from Previos Row.
NOTE: If currenet Row element is 0, Then Simply put 0, no need to add previous Row
    -- Find the max possible area for current Row.
    -- Store the max Area and return it
[Done]



*/