// This problem, we have the Matrix given has all rows sorted and all columns sorted.
#include <bits/stdc++.h>
using namespace std;

// This is my Approach.(using Binary Search)........... O(nlog(n))

class Solution
{
private:
    bool checkEle(vector<vector<int>> &matrix, int row, int col, int target)
    {
        // if the target present in attached Row to that diagonal
        if (matrix[row][0] <= target)
        {
            int start = 0, end = col;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (matrix[row][mid] == target)
                    return true;
                if (matrix[row][mid] < target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        } // if the target present in attached col to that diagonal
        if (matrix[0][col] <= target)
        {
            // BS in the colElements
            int start = 0, end = row;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (matrix[mid][col] == target)
                    return true;
                if (matrix[mid][col] < target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int row = matrix.size();
        int col = matrix[0].size();

        int i = row - 1, j = col - 1;

        // we will traverse the diagonal.
        while (i >= 0 && j >= 0)
        {

            // if the target present in diagonal
            if (matrix[i][j] == target)
                return true;

            // check if ele is present in attached row or column
            if (checkEle(matrix, i, j, target))
                return true;

            // not present in both the case
            i--;
            j--;
        }
        return false;
    }
};

/* Logic:
 We will traverse in the diagonal from
 bottom-right to top-left

 check if ele is == target -> return true.
 else
 Check if in that row if the ele < target -> target might Present
  -- Put binary search and see.
Check if in that col if the ele < target -> target might Present
  -- put binary search and see.

else at the end return false.
*/

// Babber Sir's Approach...............**Best Solution with O(n)

bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int row = matrix.size();
    int col = matrix[0].size();

    int i = 0, j = col - 1; // i keeps track of the row and j keeps track of the col.

    while (i < row && j >= 0)
    {

        if (matrix[i][j] == target)
            return 1;
        // If current ele < target then only we will ++ row and see in that col, else col--
        if (matrix[i][j] < target)
            i++;
        else
            j--;
    }
    return 0;
}
