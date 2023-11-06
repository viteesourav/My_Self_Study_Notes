// Link: https://leetcode.com/problems/perfect-squares/
/*
A number n is given. Find the least possible number of perfect sq needed to reach n.
    eg: 5 -> 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 1^2 = 5 [5 times 1^2 needed]
          -> 1^2 + 2^2 = 1 + 4 = 5 [2 prefect Sq needed]
    Thus 2 should be the output.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Appraoch1: Recursive Solution..
    int solve1(int target)
    {
        // baseCase:
        if (target == 0)
        {
            return 0;
        }

        int mini = INT_MAX; // Keep track of the least no. of ways to reach target...

        // Now lets find the possible sqs which can be used for target...
        for (int i = 1; i * i <= target; i++)
        {
            // Now for each possible sq, we will call recursion..
            if ((target - (i * i)) >= 0)
            {                                           // check if target exist on the positive side..
                int res = solve1(target - (i * i)) + 1; //+1 to keep track of the sq used.
                mini = min(mini, res);                  // Keep track of the mini res value.
            }
        }

        return mini;
    }

    // Appraoch2: Recursive + Memorization...
    int solve2(int target, vector<int> &dp)
    {
        // baseCase:
        if (target == 0)
        {
            return 0;
        }

        // check if dp already holds the result...
        if (dp[target] != -1)
        {
            return dp[target];
        }

        int mini = INT_MAX; // Keep track of the least no. of ways to reach target...
        // Now lets find the possible sqs which can be used for target...
        for (int i = 1; i * i <= target; i++)
        {
            // Now for each possible sq, we will call recursion..
            if ((target - (i * i)) >= 0)
            {                                               // check if target exist on the positive side..
                int res = solve2(target - (i * i), dp) + 1; //+1 to keep track of the sq used.
                mini = min(mini, res);                      // Keep track of the mini res value.
            }
        }

        dp[target] = mini;
        return dp[target];
    }

    // Approach3: Tabulation Method...
    int solve3(int target)
    {
        // lets create the dp array for use...
        vector<int> dp(target + 1, INT_MAX); // need to find min value so initializing with INT_MAX

        // Analysing the base case and popualting the dp initial values..
        dp[0] = 0;

        // We will iterate for each target value from 1 to target...
        for (int k = 1; k <= target; k++)
        {
            int mini = INT_MAX; // Keep track of the least no. of ways to reach target...
            // Now lets find the possible sqs which can be used for target...
            for (int i = 1; i * i <= k; i++)
            {
                // Now for each possible sq, we will call recursion..
                if ((k - (i * i)) >= 0)
                {                                  // check if target exist on the positive side..
                    int res = dp[k - (i * i)] + 1; //+1 to keep track of the sq used.
                    mini = min(mini, res);         // Keep track of the mini res value.
                }
            }
            // Store the ans for kth target in dp[k]
            dp[k] = mini;
        }

        return dp[target];
    }

public:
    // Appraoch: Recursive choice tree [choices are the possible perfect sq.]
    int numSquares(int n)
    {
        // return solve1(n);

        // vector<int> dp(n+1, -1);
        // return solve2(n, dp);

        return solve3(n);
    }
};

// NOTE: Space Optimization is not possible as dp[i] depends upon dp[target-i^2] wwhich is not consistant always.

/*
Logic: Recursive choices Logic

Lets say n is 5
    Now possible perfect sq we can try are 1 and 2 as 3^2 is 9 which is > n.
    -- Now Try all this possible perfect sq if the n-sq. exisits.
        -- call the REcursive Call + 1 to account the sq you used.
        -- Each Recursion will give a number of ways, choose the minimum one.

    Thus, This is Recursive Way, Now we can convert it to Recursive + Memorization, Tabulation and if possible space optimization.

*/