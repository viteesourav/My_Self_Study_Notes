// Link: https://www.codingninjas.com/studio/problems/rat-in-a-maze_1215030?leftPanelTab=0
/*
Given a 2-D Space matrix, as 1 [The box is open] and 0 [the box is closed], Possible Movements: D, L, R, U
    Find all Possible Path form 0,0 to n-1,n-1. [Path must be in Lexiographical/alphabetical Order]
*/

#include <bits/stdc++.h>
using namespace std;

// utility Function: Checks if that particular movement is possible ?
bool isPossible(int x, int y, vector<vector<int>> &arr, vector<vector<bool>> &isVisited, int n)
{
    // Needs to check 3 things: ALl True then only move..
    // 1.If the new coordiante is inside the matrix bound
    // 2. If the path is open.
    // 3. If the path is not visited yet..
    if (((x >= 0 && x < n) && (y >= 0 && y < n)) && (arr[x][y] == 1) && (!isVisited[x][y]))
    {
        return true;
    }
    return false;
}

// Approach: Backtracking Appraoch, TC: O(4^(n*n)) SC: O(n*n)
void solve(int currX, int currY, vector<vector<int>> &arr, int n, vector<vector<bool>> &isVisited, string &path, vector<string> &ans)
{
    // baseCase: When you reach your destination, store the path and return
    if (currX == n - 1 && currY == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // check all the possible movement in order: D L R U
    // Down
    if (isPossible(currX + 1, currY, arr, isVisited, n))
    {
        // Now if the path is possible...
        path.push_back('D');                                   // Add the Operation in the path..
        isVisited[currX + 1][currY] = true;                    // Make the next Node is visited..
        solve(currX + 1, currY, arr, n, isVisited, path, ans); // REcursion Find the whole path..
        path.pop_back();                                       // While coming back, remove the path
        isVisited[currX + 1][currY] = false;                   // Make the Node notVisited during coming back..
    }

    // Left
    if (isPossible(currX, currY - 1, arr, isVisited, n))
    {
        // Now if the path is possible...
        path.push_back('L');                                   // Add the Operation in the path..
        isVisited[currX][currY - 1] = true;                    // Make the next Node is visited..
        solve(currX, currY - 1, arr, n, isVisited, path, ans); // REcursion Find the whole path..
        path.pop_back();                                       // While coming back, remove the path
        isVisited[currX][currY - 1] = false;                   // Make the Node notVisited during coming back..
    }

    // Right
    if (isPossible(currX, currY + 1, arr, isVisited, n))
    {
        // Now if the path is possible...
        path.push_back('R');                                   // Add the Operation in the path..
        isVisited[currX][currY + 1] = true;                    // Make the next Node is visited..
        solve(currX, currY + 1, arr, n, isVisited, path, ans); // REcursion Find the whole path..
        path.pop_back();                                       // While coming back, remove the path
        isVisited[currX][currY + 1] = false;                   // Make the Node notVisited during coming back..
    }

    // UP
    if (isPossible(currX - 1, currY, arr, isVisited, n))
    {
        // Now if the path is possible...
        path.push_back('U');                                   // Add the Operation in the path..
        isVisited[currX - 1][currY] = true;                    // Make the next Node is visited..
        solve(currX - 1, currY, arr, n, isVisited, path, ans); // REcursion Find the whole path..
        path.pop_back();                                       // While coming back, remove the path
        isVisited[currX - 1][currY] = false;                   // Make the Node notVisited during coming back..
    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> isVisited(n, vector<bool>(n, 0)); // Creates a 2-D matrix with all flag set to false.
    string path = "";

    // check if the rat's starting position is open ?
    if (arr[0][0] != 1)
        return ans;

    // call the BAcktracking Appraoch...
    int currX = 0, currY = 0;
    isVisited[currX][currY] = true; // mark the starting position visited...
    solve(currX, currY, arr, n, isVisited, path, ans);

    return ans;
}

/*
Logic: Recursion, Focus on solving just 1 case, Rest Assume Recursion is solving for you.

Appraoch: use BackTracking [TC: O(4^(m*n)) [For each box, we can have 4 possible path, SC: O(m*n)]]
    -- Take a Visited Array, to keep track of the visited space.
    -- Check if 0,0 is avaiable [edgeCase Check], if available, mark it as visited Box
    -- Traverse the given space [REcursion]
        -- At every box, Check for all possible conditions to Move, record the move,call Recursion.
        -- Conditions to allowed Movement:
            1) The new box must be within Bound of the matrix.
            2) The new box must not be already Visited.
            3) The new box must be allowed space in the given matrix.
        -- If all condition satisfy, You are allowed to move to that box.

    NOTE:
        -- Here taking extra Space m*n for the isVisited matrix. This can be avoided by just updating the same matrix with negative to mark the box visited.
        Ref: Check the Same problem solution under Recursion Series.

*/