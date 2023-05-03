/*
Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1 [Imp]

Baically you have given a matrix, with zeros and ones. You at (0,0), Print all possible navigation to Reach (n-1, n-1).
Solution is implemented using REcursion and backtracking the path logic.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // This is a function that checks if the new index specified is safe to move ?
    bool isSafe(vector<vector<int>> &m, int n, int xpos, int ypos)
    {
        // 3 things to check is path is valid ?
        //  x and y should be inside the array limits,
        //  path should be marked as 1
        //  path should not be negative.
        if ((xpos >= 0 && xpos < n) && (ypos >= 0 && ypos < n) && m[xpos][ypos] == 1 && m[xpos][ypos] > 0)
        {
            return true;
        }
        return false;
    }

    // This is a recursive function...
    void solve(vector<vector<int>> &m, int n, int curX, int curY, vector<string> &ans, string path)
    {

        // base condition: When we reach the end
        if (curX == n - 1 && curY == n - 1)
        {
            ans.push_back(path); // putting the current path in the ans.
            return;
        }

        // NOTE: postion marked as -1 is already visited.
        // we will mark the current position as -1.
        m[curX][curY] = -m[curX][curY];

        // Logic to search for a valid path..
        // Is Going Down SAfe ?
        if (isSafe(m, n, curX + 1, curY))
        {
            path.push_back('D'); // Since a safe path, insert the direction.
            solve(m, n, curX + 1, curY, ans, path);
            path.pop_back(); // Backtracking, Removing the Direction from path, when we return.
        }

        // Is Going Left SAfe ?
        if (isSafe(m, n, curX, curY - 1))
        {
            path.push_back('L'); // Since a safe path, insert the direction.
            solve(m, n, curX, curY - 1, ans, path);
            path.pop_back(); // Backtracking, Removing the Direction from path, when we return.
        }

        // Is Going Right SAfe ?
        if (isSafe(m, n, curX, curY + 1))
        {
            path.push_back('R'); // Since a safe path, insert the direction.
            solve(m, n, curX, curY + 1, ans, path);
            path.pop_back(); // Backtracking, Removing the Direction from path, when we return.
        }

        // Is Going Up SAfe ?
        if (isSafe(m, n, curX - 1, curY))
        {
            path.push_back('U'); // Since a safe path, insert the direction.
            solve(m, n, curX - 1, curY, ans, path);
            path.pop_back(); // Backtracking, Removing the Direction from path, when we return.
        }

        // While returning from current position, Make the visited path, unVisted.
        m[curX][curY] = abs(m[curX][curY]);
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {

        // we will solve the problem using Recursion and backtrackingt the path...
        vector<string> ans;
        int curX = 0, curY = 0; // current source x and y position.
        // edge case check if the Source position is zero
        if (m[curX][curY] == 0)
            return ans;

        string path = ""; // this will hold the path we are following...

        solve(m, n, curX, curY, ans, path);

        // sorting the final ans array as required by the qustion..
        sort(ans.begin(), ans.end());

        return ans;
    }
};

/*
Approach:
    -- So you at the source vertex of the Matrix, need to move to end of the matrix.
    -- Poosible directions you can take at any point of time.
       Down -> x++, y
       Left -> x, y--
       Right -> x, y++
       Up -> x--, y
    -- NOte: To prevent coming behind from the path where we came, WE will mark the visted index as -1.
    -- So at any index, Safe conditions to move to the next Path ?
       -- the new index should be inside the array limits
       -- the new index should be allowed to go into, i.e it should be 1.
       -- the new index should not be neagtive, because negative means, that the path we alrady visitied.
    -- Update the path with direction, and Rest REcursion will take care of.
NOTE: While coming back, Make sure, we mark the path as not visited as, we are coming back, we should mark the current path as unVisited.
Reason:
  If you are standing at a position, and you find no valid path, then you go back, Therefore, we wrote the part to make the current path
  as unvisted at the end, after checking possiblity of all the paths from the current path.
*/