// Link: https://www.codingninjas.com/studio/problems/cut-into-segments_1214651
/*
    You have given a rod of length n, and length of segment x, y and z. Find the max number of segment that rod can be cut into.
*/
#include <bits/stdc++.h>
using namespace std;

// Appraoch1: Recursion [TC: Exponential]
int solve1(int n, int &x, int &y, int &z)
{
    // baseCase:
    if (n == 0)
        return 0; // If the len of rod becomes zero..
    if (n < 0)
        return INT_MIN; // If len of rod, return -INF..

    // Now for each segment we will find the segments possible..
    int xSegCount = solve1(n - x, x, y, z) + 1; //+1 as the current seg will be taken in account...
    int ySegCount = solve1(n - y, x, y, z) + 1; //+1 as the current seg will be taken in account...
    int zSegCount = solve1(n - z, x, y, z) + 1; //+1 as the current seg will be taken in account...

    // Now let's take the max of these...
    int ans = max(xSegCount, max(ySegCount, zSegCount));

    // return the max of the segCount of all the 3 segments...
    return ans;
}

// Appraoch2: Recursion + Memorization...
int solve2(int n, int &x, int &y, int &z, vector<int> &dp)
{
    // baseCase:
    if (n == 0)
        return 0; // If the len of rod becomes zero..
    if (n < 0)
        return INT_MIN; // If len of rod, return -INF..

    // After baseCase, check if dp already holds the result..
    if (dp[n] != -1)
        return dp[n];

    // Now for each segment we will find the segments possible..
    int xSegCount = solve2(n - x, x, y, z, dp) + 1; //+1 as the current seg will be taken in account...
    int ySegCount = solve2(n - y, x, y, z, dp) + 1; //+1 as the current seg will be taken in account...
    int zSegCount = solve2(n - z, x, y, z, dp) + 1; //+1 as the current seg will be taken in account...

    // Now let's take the max of these...
    dp[n] = max(xSegCount, max(ySegCount, zSegCount));

    // return the max of the segCount of all the 3 segments...
    return dp[n];
}

// Appraoch3: Tabulation [No Recursion, Looping + Vector Track]
int solve3(int n, int &x, int &y, int &z)
{

    // Lets define a dp vector keep track of the maxSegment for each n len Rod..
    vector<int> dp(n + 1, INT_MIN); // initially, all we nth Rod needs -Inf seg..

    // lets handle the starting conditions...
    dp[0] = 0; // for rod len 0, number of seg needed is 0.

    // now lets use a loop 1 to n...[For below logic take ref from Recursive sol..]
    for (int i = 1; i <= n; i++)
    {

        // Find the segment cut possible for each segment len...
        // Find the maxSeg amoung x, y and z.. update at dp[i]
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    // int ans = solve1(n, x, y, z);

    // vector<int> dp(n+1, -1); //n+1 because we need to find result for nth index.
    // int ans = solve2(n, x, y, z, dp);

    int ans = solve3(n, x, y, z);

    // Check if ans < 0 i.e it is not possible to divide rod using x,y,z segments.
    if (ans < 0)
        return 0;
    return ans;
}

/*
NOTE: Space Optimization is not possible here, as we see, dp[n] depends upon dp[i-x], dp[i-y] and dp[i-z]
    -- here x,y and z can be anything, thus the relation is not consitant enough to represnt using variables.
*/

/*
Appraoch:
    --> So length of rod is n, and length of each segment is x, y and z...
    --> For each rod segment,
        --> You have 3 options i.e either you cut in x or y or z units. [REcursion will handle this..]
    --> Out of the 3 options, For max Segment, consider the recursion result which gives the max unit.
    -> base CASE:
        -> say if n is 0 -> no of segment needed will be zero.
        -> If the n is going negative -> return -INF i.e INT_MIN.

Appraoch: [In recursion only n is changing, x,y&z are fixed thus 1D DP]
    1) REcursion Appraoch [Find the Recursive relation + Recursion]
    2) Recursion + Memorization Appraoch [Store the result of the REcusion in a dp]
    3) Tabulation [use vector + Use loop, take reference from the Recursive solution and find the relation]
    4) Space Optimization. [If possible to reduce the solution to variable. only if the realtion of dp[n] is consistant]
*/