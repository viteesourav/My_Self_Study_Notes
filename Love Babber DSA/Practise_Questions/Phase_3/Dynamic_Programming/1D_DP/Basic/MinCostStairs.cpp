// Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/
/*
    You have been Given a Array of numbers, representing cost of each Stairs. You Pay the price and then move 1 or 2 Steps which ever is minimum.
    Find the Total Cost to reach the top of the stairs.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Approach1: Use Normal Recursion to Find the solution... TC:O(2^N)
    int solve1(int n, vector<int> &cost)
    {
        // baseCase:
        if (n < 0)
            return 0; // Return 0, if the steps going below index 0.

        // else find the totCost...
        int totCost = cost[n] + min(solve1(n - 1, cost), solve1(n - 2, cost));
        return totCost;
    }

    // Approach2: Use Recursion + Memorization ... TC:O(N) SC: O(N) + O(N)
    int solve2(int n, vector<int> &cost, vector<int> &dp)
    {
        // baseCase:
        if (n < 0)
            return 0; // Return 0, if the steps going below index 0.

        // check if the dp holds the ans for n...
        if (dp[n] != -1)
            return dp[n];

        // else find the totCost...
        dp[n] = cost[n] + min(solve2(n - 1, cost, dp), solve2(n - 2, cost, dp));
        return dp[n];
    }

    // Approach3: Use Tabulation Method[No Recursion]... TC: O(N) SC: O(N)
    int solve3(int n, vector<int> &cost)
    {
        // Lets have a vector to keep track of the steps..
        vector<int> dp(n + 1);

        // Lets intialize the starting the steps..
        dp[0] = cost[0];
        dp[1] = cost[1];

        // lets look for other steps, based on the first 2 steps...
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]); // cost of the step + which ever is minimum step..
        }

        // Now, You want to reach Nth Step, -> You came either from n-1 or n-2 step which ever is smaller..
        return min(dp[n - 1], dp[n - 2]);
    }

    // Approach4: Space Optimization [Removal of the dp vector]... TC: O(N) SC: O(1)
    int solve4(int n, vector<int> &cost)
    {

        // Lets intialize the starting the steps..
        int prevStep1 = cost[0], prevStep2 = cost[1];

        // lets look for other steps, based on the first 2 steps...
        for (int i = 2; i < n; i++)
        {
            int currStep = cost[i] + min(prevStep1, prevStep2); // cost of the step + whichever is minimum step..
            prevStep1 = prevStep2;
            prevStep2 = currStep;
        }

        // Now, You want to reach Nth Step, -> You came either from n-1 or n-2 step which ever is smaller..
        return min(prevStep1, prevStep2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        // Lets have the cost of the destination stair as 0..
        cost.push_back(0);

        // Appraoch1: Recursion...
        //  return solve1(n, cost);

        // Approch2: Recursion + Memorization...
        //  vector<int> dp(n+1, -1);
        //  return solve2(n, cost, dp);

        // Approach3: Tabulation Method
        //  return solve3(n, cost);

        // Approch4: Space Optimization..
        return solve4(n, cost);
    }
};
/*
Logic:
    [1, 100, 1, 1, 1, 100, 1, 1, 100, 1] d
     0   1   2  3  4   5   6  7   8   9  10
    -- Here consider each index as Stairs, You pay the Price and then either move 1 steps or 2 steps [Which ever is minimum]
    -- Now Say you standing at index 10. [You Reached]
        -- You will Probably came to inex 10, either from index 8th or 9th.
        -- And you must have paiid the Price also For that index step.
        -- f[n] = cost[n] + min(f[n-1], f[n-2])
    --base Case:
        -- You cannot go to negative Steps, i.e n >= 0

    Take the Logic:
        1) Recursion Appraoch. TC: O(2^N) SC: O(N)
        2) Memorization Approach. TC: O(N) SC:O(N) + O(N)
        3) Tabualtion Approach. TC: O(N) SC: O(N)
        4) Space Optimization Approach.  TC:O(N) SC:O(1)
*/