// Link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/
/*
    Basically, You Given a polygon with N vertex, Each Vertex has some weights. You Need to form Triangles inside the polygon.
    Such that the sum of the weights of the vertex is minimum.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Approach1: Recursive solution using the Recursive Relation.
    int solve1(vector<int> &values, int i, int j)
    {
        // baseCase:
        if (i + 1 == j)
        { // if i and j are adjacent Vertex
            return 0;
        }

        int res = INT_MAX; // to store the min Answer...
        // For Forming a Triangle, lets consider all the vertex between i and j
        for (int k = i + 1; k < j; k++)
        {
            // score of the current Triangle + Recursion will fetch answer from top polygon + from Bottom polygon
            res = min(res, (values[i] * values[k] * values[j] + solve1(values, i, k) + solve1(values, k, j)));
        }
        return res;
    }

    // Appraoch2: Memorization Approach [Top-Down] TC: O(n3) SC: O(n2)
    int solve2(vector<int> &values, int i, int j, vector<vector<int>> &dp)
    {
        // baseCase: If i and j are adjacent Nodes..
        if (i + 1 == j)
        {
            return 0;
        }

        // check if the dp already holds the answer for i and j..
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int res = INT_MAX; // to store the min Answer...
        // For Forming a Triangle, lets consider all the vertex between i and j
        for (int k = i + 1; k < j; k++)
        {
            // score of the current Triangle + Recursion will fetch answer from top polygon + from Bottom polygon
            res = min(res, (values[i] * values[k] * values[j] + solve2(values, i, k, dp) + solve2(values, k, j, dp)));
        }

        dp[i][j] = res; // store the ans for i and j in dp[i][j]

        return dp[i][j];
    }

    // Approch3: Tabulation Method [bottom-up Approch]
    // NOTE: Here we start the index i from n-1 and j from 0.
    int solve3(vector<int> &values)
    {

        // 1. creating the required constraints...
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); // Initialize the 2D dp[i][j]

        // start the loop to iterate from bottom to top...
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            { // i+2, as i=j means just one vertex, j=i+1 is a line so no triangle possible, j= i+2, one traingle possible..
                // The Above loop runs from i-> n-1 to 0 and j from 0 to n-1
                int res = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    res = min(res, (values[i] * values[k] * values[j] + dp[i][k] + dp[k][j]));
                }
                dp[i][j] = res;
            }
        }

        // We need ans for, index i=0 and j=n-1
        return dp[0][n - 1];
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {

        int n = values.size();
        int i = 0, j = n - 1;
        // return solve1(values, i, j);

        // vector<vector<int>> dp(n, vector<int>(n, -1)); //initialize 2D dp[i][j]...
        // solve2(values, i, j, dp);
        // return dp[0][n-1]; //we need answers between the vertex i=0 and j=n-1

        return solve3(values);
    }
};

/*
Appraoch:
    - For a Recursive solution, Need to First Find the Recursive Relation.

      vertex = [a, b, c, d, e, f, g, h]
                i           k        j
    - Now we can assume a and h are adjacent vertex, so no traingle is possible.
    - Lets assume i at vertex a and j at vertex b.
    - BaseCASE: i+1 = j [i.e if j is immediate next node of i, we have visited all vertex]
    - Now if i-j is one side, Then from vertex b to g i can form a Triangle, lets take k that one-by-one consider these available vertex.
    - For instance, Assume k at vertex e, Thus, we have aef as one triangle.
        so for this we will have solve(i, j) = (a*e*f) + solve(i, k) + solve(k, j).
    - Choose the min weights among all the possible k value.

 ** Possiblilty of Space Optimization:
    -- So dp[i][j] depends upon dp[i][k] and dp[k][j], as i can move from n-1 to 0 and j can move from 0 to n and k will be between them.
    -- we cannot furthur reduce the space Complexity for this problem.
*/