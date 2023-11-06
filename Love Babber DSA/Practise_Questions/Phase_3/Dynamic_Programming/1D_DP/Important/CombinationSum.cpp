// Link: https://www.codingninjas.com/studio/problems/number-of-ways_3755252
/*
Basically, A set of numbers are given i.e [1, 2, 5] and a target is given say tar = 5.
    You Need to find the possible Number of ways to reach target using the given numbers in array.

NOTE: A variation of the same Question might ask to print all such valid combinations of number.
    Link: https://leetcode.com/problems/combination-sum/ [Use Vector + backtracking to keep track of the path, Logic is same]
*/

#include <bits/stdc++.h>
using namespace std;

// Approach1: Recursive Way...[Depending upon the choice of num, Recursive Tree]
int solve1(vector<int> &num, int tar)
{
    // baseCase:
    if (tar == 0)
    {
        return 1;
    }

    int totWays = 0;
    // Now iterate all the given nums...
    for (int i = 0; i < num.size(); i++)
    {
        // For each Nums we will call the recursion...
        if (tar - num[i] >= 0)
        {                                         // check if the next tar >0 then only make recursive call...
            totWays += solve1(num, tar - num[i]); // Keep track of the ways for all Recursive call for tar.
        }
    }
    return totWays;
}

// Appraoch2: Recursive + Memorization
int solve2(vector<int> &num, int tar, vector<int> &dp)
{
    // baseCase:
    if (tar == 0)
    {
        return 1;
    }

    // Check if the dp already holds the result of tar..
    if (dp[tar] != -1)
        return dp[tar];

    int totWays = 0;
    // Now iterate all the given nums...
    for (int i = 0; i < num.size(); i++)
    {
        // For each Nums we will call the recursion...
        if (tar - num[i] >= 0)
        {                                             // check if the next tar >0 then only make recursive call...
            totWays += solve2(num, tar - num[i], dp); // Keep track of the ways for all Recursive call for tar.
        }
    }
    dp[tar] = totWays;
    return dp[tar];
}

// Approach3: Tabulation Method
int solve3(vector<int> &num, int tar)
{

    // creating a dp vector to keep tack...
    vector<int> dp(tar + 1, 0);

    // Analysising the base case and putting the value...
    dp[0] = 1;

    // Now we will use a loop to process all other target Values...
    for (int k = 1; k <= tar; k++)
    {
        int totWays = 0;
        // Now iterate all the given nums...
        for (int i = 0; i < num.size(); i++)
        {
            // For each Nums we will call the recursion...
            if (k - num[i] >= 0)
            {                              // check if the next tar >0 then only make recursive call...
                totWays += dp[k - num[i]]; // Keep track of the ways for all Recursive call for tar.
            }
        }
        // populating the totalWays for each tar value...
        dp[k] = totWays;
    }

    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // return solve1(num, tar);

    // vector<int> dp(tar+1, -1);
    // return solve2(num, tar, dp);

    return solve3(num, tar);
}

// NOTE: Space optimization is not possible as dp[i] depends upon dp[tar-num[i]] which depends upon num[i] [So not possible]

/*
Logic: Each target will have all nums as choices...

-- Draw a Recursive Tree to get for info on the Appraoch.
Recursive Logic:
    -- You start with target.
    -- Now for target you have k choices. k is the number of elements given in the array.
        NOTE: Before making recursie call, make sure, the target > 0. As we cannot make negative target.
    -- for each Choices, update the target.
    -- baseCase:
        - If tar becomes 0, return 1 as For making tar = 0, we must have used 1 item.
    -- Keep track of the totWays for each recursive calls.

*/