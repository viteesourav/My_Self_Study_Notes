// Link: https://leetcode.com/problems/sudoku-solver/
/*
 Given a 9x9 matrix, with partially filled boxes with digit bwtween 1 to 9. Fill the other boxes such that
    1) No digit should repeat in the same row
    2) No digit should repeat in the same column
    3) No digit should repeat in the same box of 3x3
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // utility Function to check if it's safe to insert a val in board
    bool isSafe(int row, int col, vector<vector<char>> &board, char val)
    {
        // A loop to iterate the board's indexes from 0 to 8...
        for (int i = 0; i < 9; i++)
        {
            // check for rows...
            if (board[row][i] == val)
                return false;
            // check for columns...
            if (board[i][col] == val)
                return false;
            // check in the 3x3 box...
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
                return false;
        }
        return true;
    }

    // Appraoch: Traverse the matrix + Recursion
    bool solve(vector<vector<char>> &board)
    {
        int n = board[0].size();
        // Traverse the 9x9 matrix...
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // check if the space is empty ?
                if (board[row][col] == '.')
                {
                    // Run a loop to find digit that we can fit in the space...
                    for (int i = 1; i <= 9; i++)
                    {
                        char val = '0' + i;
                        if (isSafe(row, col, board, val))
                        { // If it's safe to insert..
                            board[row][col] = val;
                            if (solve(board))
                            { // Call Recursion...
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.'; // Reverting while backtracking...
                            }
                        }
                    }
                    return false; // If we cannot fit any of the digit from 1 to 9..
                }
            }
        }
        return true; // We are able to insert all the elements...
    }

public:
    // Appraoch: backtracking TC: O(9^m) [m is no of empty spaces], SC: O(1) [No additional space]
    void solveSudoku(vector<vector<char>> &board)
    {
        // call the Recursive function...
        solve(board);
    }
};

/*
Logic: Recursion, Focus on solving just 1 case i.e place 1 digit properly, Rest Assume Recursion is solving for you.

Appraoch: Backtracking[TC: O(9^m), m is the number of empty spaces to fill, TC: O(1) [at max 9^2 calls]]
Steps:
    1) Travers the whole matrix -> use two loops.
    2) If you find a empty space.
        -- Run a for loop to try all digit from 1 to 9.
        --check if a digit is valid at that palce ?
            -- Run a loop a loop i: 1 to 9
            -- row, col is the current positon of the empty space.
            -- In the same Row and col it should not match.
            -- To check in the 3x3 box, board[3*(row/3) + i/3][3*(col/3) + i%3] check if the digit present ?
    3) If safe, push the val and recursive check the other empty space.
        -- If Recusrion returning true, return true..
    4) if Recursion is returning false, do backtrack...
    5) While backtracking, remove the digit that is inserted.
    6) If none of the digit fit in that place. return false.
[**DONE**]
*/