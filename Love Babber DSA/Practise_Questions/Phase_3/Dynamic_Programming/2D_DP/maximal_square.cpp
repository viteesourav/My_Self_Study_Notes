// Link:https://leetcode.com/problems/maximal-square/description/
/*
Basically, You given a binary Matrix. You need to form square block of 1's. Find the max area of the possible sq block.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Appraoch1: REcursive Solution [TC:O(2^N), choice of expanding the sq to right, dignonal and bottom] TC: exponential
    int solve1(vector<vector<char>> &matrix, int row, int col, int &maxi)
    {
        // baseCase: check for outofBound condition
        if (row >= matrix.size() || col >= matrix[0].size())
        {
            return 0;
        }

        // say you at (0,0) Now Recursion will bring Answer from right, digonal and bottom...
        int right = solve1(matrix, row, col + 1, maxi);
        int dig = solve1(matrix, row + 1, col + 1, maxi);
        int bottom = solve1(matrix, row + 1, col, maxi);

        // Check if the current place is 1 or not ?
        if (matrix[row][col] == '1')
        {
            // Now each right, dig, bottom says how many 1's are present in that direction, Take min among them we can form a square.
            int ans = min(right, min(dig, bottom)) + 1; //+1, to include the 1 at current position.
            maxi = max(maxi, (ans * ans));              // update maxi based on ans.
            return ans;                                 // Returns the 1's present...
        }
        else
        {
            return 0; // As this i,j cannot be include in the sq..
        }
    };

    // Appraoch2: REcursion + Memorization [Use Vector + Recursion Approach] TC: O(N*M) SC: O(N*M)*O(N*M)
    int solve2(vector<vector<char>> &matrix, vector<vector<int>> &dp, int row, int col, int &maxi)
    {
        // baseCase: Index out of bound check...
        if (row >= matrix.size() || col >= matrix[0].size())
        {
            return 0;
        }

        // Check if the dp already holds the value for the current row and col ?
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // Recursion will fetch from right, dig and bottom...
        int right = solve2(matrix, dp, row, col + 1, maxi);
        int dig = solve2(matrix, dp, row + 1, col + 1, maxi);
        int bottom = solve2(matrix, dp, row + 1, col, maxi);

        // Check if the current spot is 1 or not ?
        if (matrix[row][col] == '1')
        {
            // update the ans in dp[i][j]....
            dp[row][col] = min(right, min(dig, bottom)) + 1;
            maxi = max(maxi, (dp[row][col] * dp[row][col])); // update the max tracker...
        }
        else
        {
            dp[row][col] = 0; // If current place is 0 then sq not possible.
        }

        return dp[row][col];
    }

    // Appraoch 3: Tabulation Method [Non-Recursive Approach] TC: O(N*M) SC: O(N*M)
    void solve3(vector<vector<char>> &matrix, int &maxi)
    {

        int row = matrix.size(), col = matrix[0].size();

        // 1. create a dp vector...[NOTE: +1 because, if i is row-1 then i=row will go out of bound, thus to handle this case]
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0)); // Intitalize the matrix with all 0.

        // 2.as per base case: if matrix is mxn then matrix[m][n] = 0; -> This is already done above...

        // 3.start a for loop and copy the logic... [Bottom-up Approach]
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {

                // Find the right,dig and bottom from the dp matrix...
                int right = dp[i][j + 1];
                int dig = dp[i + 1][j + 1];
                int bottom = dp[i + 1][j];

                // Check if the current spot is 1 or not ?
                if (matrix[i][j] == '1')
                {
                    // update the ans in dp[i][j]....
                    dp[i][j] = min(right, min(dig, bottom)) + 1;
                    maxi = max(maxi, (dp[i][j] * dp[i][j])); // update the max tracker...
                }
                else
                {
                    dp[i][j] = 0; // If current place is 0 then sq not possible.
                }
            }
        }
    }

    // Appraoch 4: Space Optimization TC:O(N*M) SC:O(M) M for the number of columns.
    // Based on Analysis: dp[i][j] depends upon ith and i+1th Row, Thus we can maintain 2 sperate vector representing each row..
    void solve4(vector<vector<char>> &matrix, int &maxi)
    {

        int row = matrix.size(), col = matrix[0].size();

        // 1.Start with 2 seperate vectors for each 2 rows of the dp...
        vector<int> curr(col + 1, 0); // represent dp[i] th row
        vector<int> next(col + 1, 0); // represent dp[i+1]th row

        // 2.start a for loop and copy the logic... [Bottom-up Approach]
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {

                // Find the right,dig and bottom from the dp matrix...
                int right = curr[j + 1];
                int dig = next[j + 1];
                int bottom = next[j];

                // Check if the current spot is 1 or not ?
                if (matrix[i][j] == '1')
                {
                    // update the ans in dp[i][j]....
                    curr[j] = min(right, min(dig, bottom)) + 1;
                    maxi = max(maxi, (curr[j] * curr[j])); // update the max tracker...
                }
                else
                {
                    curr[j] = 0; // If current place is 0 then sq not possible.
                }
            }
            // After processing one row, we need to update next and curr...
            next = curr;
        }
    }

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maxi = 0;
        int i = 0, j = 0;

        // Recursive Appraoch:
        //  solve1(matrix, i, j, maxi);

        // Memorization:
        //  vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1)); //dp[i][j], whole matrix initialized with -1
        //  solve2(matrix, dp, i, j, maxi);

        // Tabulation:
        //  solve3(matrix, maxi);

        // Space Optimization:
        solve4(matrix, maxi);

        return maxi;
    }
};

/*
Appraoch:
    NOTE:
        -- Based on the logic of Recursive solution, Memeorization[top-down], tabulation[bottom-up] and space optimization can be figured out.
    Recursive Solution: [Imporatant]
        -- So You have a binary matrix with 1's and 0's.
        -- Now you sanding at a postion i,j.
        -- you have 3 possible Options:
            1) Move right ->  [i], [j+1]
            2) Move digonal -> [i+1], [j+1]
            3) Move Bottom -> [i+1], [j]
        -- Recursion will fetch the values of these 3 cases.
        -- Now Check if current place is 0 or 1. if 0 then no possibility of any sq.
        -- If it is 1,
            -- then take the min of right, bottom and dig. + 1  -> Gives you side of the square possible.
            -- Find the area, and keep track of the max area of such possible squares.
*/