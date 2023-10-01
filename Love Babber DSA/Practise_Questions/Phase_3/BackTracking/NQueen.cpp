// Link: https://leetcode.com/problems/n-queens/
/*
    You have Given a nxn Chess board and N queens. Find all Possiblities of placing all the N Queens in the board.
    Such That No Queen attacks each other.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Utility Fucntion, to check if Queen can be placed or not ?
    bool isSafe(int row, int col, vector<vector<int>> &board, int n)
    {
        // Need to check 3 things:
        int i = row, j = col;

        // 1. In the same row no Queen should be there...
        while (j >= 0)
        {
            if (board[i][j] == 1)
                return false;
            j--;
        }

        // 2. In the lower-left diagonal...
        i = row;
        j = col;
        while (i < n && j >= 0)
        {
            if (board[i][j] == 1)
                return false;
            i++;
            j--;
        }

        // 3. In the upper-left digonal....
        i = row, j = col;
        while (i >= 0 && j >= 0)
        {
            if (board[i][j] == 1)
                return false;
            i--;
            j--;
        }
        return true; // safe to place the queen...
    }

    // Utlitly function to Store the ans from the board...
    void captureQueens(vector<vector<int>> &board, vector<vector<string>> &ans, int n)
    {
        vector<string> res;
        for (int row = 0; row < n; row++)
        {
            string str = "";
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == 1)
                    str.push_back('Q');
                else
                    str.push_back('.');
            }
            res.push_back(str);
        }
        ans.push_back(res);
    }

    // Recursion + Backtracking [Column-wise]
    void solve(int col, vector<vector<int>> &board, vector<vector<string>> &ans, int n)
    {
        // base case: If we are done with last Column, store the ans and return...
        if (col == n)
        {
            captureQueens(board, ans, n);
            return;
        }

        // lets start a loop over the all the boxes in a column...
        for (int row = 0; row < n; row++)
        {
            // check if it's safe to place the Queen ?
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 1;           // Queen placed..
                solve(col + 1, board, ans, n); // Call Recursion to handle other columns...
                board[row][col] = 0;           // While returning, remove the Queen placed
            }
        }
    }

public:
    // Appraoch: BackTracking...
    vector<vector<string>> solveNQueens(int n)
    {
        // we need a nxn board...
        vector<vector<int>> board(n, vector<int>(n, 0)); // creates a nxn board with all element 0.
        vector<vector<string>> ans;

        // Lets call the recursion function with first column...
        solve(0, board, ans, n);

        return ans;
    }
};

/*
Logic: Recursion, Focus on solving just 1 case i.e place 1 queen at safe place, Rest Assume Recursion is solving for you.
Appraoch: BackTracking TC: O(n!) SC: O(n^2)
    -- Basically, we need to put one Queen in every Columns, we need to find which Row the Queen is safe.
    -- Use Recursion
        -- starts with the first column.
        -- Loop All the boxes Down that column,
            -- Check if the Queen is safe to place there ?
            -- Condition for safe:
                1) That Row should not contain any other Queen.
                2) That Column should not contain any other Queen [Not needed to check, as we fill from left to right]
                3) The up-left diagonal should not contain any Queen. [row-1, col-1]
                4) The down-left diagonal should not contain any Queen. [row+1, col-1]
            NOTE: Just we need to check if Queen is placed on the left side, as we are filling Queen from left to right.
            -- If safe put the Queen at that place,
            -- Call Recursion.
            -- If you reach the last column, Store the answer.
            -- While backtracking, Remove the Queen.
        [**DONE**]

    Optimization:
        -- For checking the is safe to place the Queen, It is taking O(N) time, It can be reduced to O(1).
        -- Use HashMap to <position, bool if queen placed>
        --  1) For Row check,
              --> store the x cordianate in the hashmap, that says a Queen is placed there..
            2) For down-left digonal check,
              --> store the  [sum of the x and y coordinate of the Queen Placed], It will block the diagonal
            3) For the up-left diagonal check,
                -> store the [n-1 + col-row], col and row are the coordinate of the Queen placed.

    Thus, The isSafe Complexity we reduced it From O(N) to O(1) using Map [Extra space we took].
*/