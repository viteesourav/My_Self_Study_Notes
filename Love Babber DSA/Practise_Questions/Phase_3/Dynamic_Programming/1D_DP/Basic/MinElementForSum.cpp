// Link: https://www.codingninjas.com/studio/problems/minimum-elements_3843091
/*
You are given a List of numbers i.e 1, 2, 3 and a target Sum = 7.
    Find the min number of elements needed to reach the targetSum. i.e 3+3+1 -> 7 i.e min 3 elements needed for 7.

NOTE: This Question is similar to Min Coins where elements are Coins availble and target Sum is the amount We need to Reach.
*/
#include <bits/stdc++.h>
using namespace std;

// Appraoch1: Recursive Solution TC: O(2^N)
int solve1(int n, vector<int> &num, int targetSum)
{
    // BaseCase:
    if (targetSum == 0)
        return 0; // For making sum of 0, we need 0 coins..
    if (targetSum < 0)
        return INT_MAX; // For handling cases, sum goes into negative

    int mini = INT_MAX; // Keep track of the minCoins needed...

    // Now lets run a loop at all the elements choice we have in nums..
    for (int i = 0; i < n; i++)
    {
        int minCoins = solve1(n, num, targetSum - num[i]); // Recursive call for each Coin's choice...
        // Check if minCoins is not INF..
        if (minCoins != INT_MAX)
        {
            // we will update mini...
            mini = min(mini, minCoins + 1); //+1 we did in order to include the nums[i]th coin...
        }
    }

    return mini;
}

// Appraoch2: Recursion + Memorization, TC: O(targetSum * n) SC:O(targetSum)+O(targetSum)
int solve2(int n, vector<int> &num, int targetSum, vector<int> &dp)
{
    // NOTE: dp vector will keep Track of minCoins needed for each Amount Value...
    // baseCase:
    if (targetSum == 0)
        return 0; // For making sum of 0, we need 0 coins..
    if (targetSum < 0)
        return INT_MAX; // For handling cases, sum goes into negative

    int mini = INT_MAX; // Keep track of the minCoins needed...

    // Check if dp already hold's the mini Coins required for targetSum..
    if (dp[targetSum] != -1)
        return dp[targetSum];

    // Now lets run a loop at all the elements choice we have in nums..
    for (int i = 0; i < n; i++)
    {
        int minCoins = solve2(n, num, targetSum - num[i], dp); // Recursive call for each Coin's choice...
        // Check if minCoins is not INF..
        if (minCoins != INT_MAX)
        {
            // we will update mini...
            mini = min(mini, minCoins + 1); //+1 we did in order to include the nums[i]th coin...
        }
    }

    // upadte the dp vector -> the miniCoins needed to reach targetSum..
    dp[targetSum] = mini;
    return dp[targetSum];
}

// Approach3: Tabulation [Replace the Recursion with a loop] TC:O(targetSum* n) SC:O(taegetSum)
int solve3(int n, vector<int> &num, int targetSum)
{

    // First lets have a vector to keep Track of minCoins for each Amounts..
    vector<int> dp(targetSum + 1, INT_MAX); // Since Bottom Up Approach, Initially, we take all Amounts need INf Coins..

    // For targetSum 0, we need 0 coins..
    dp[0] = 0;

    // Logic: for each Amount form 1 to targetSum, we need to explore all choices we have and update dp vector...
    for (int amount = 1; amount <= targetSum; amount++)
    {
        // Now For each Amount, we have n Elements to choose from...
        for (int j = 0; j < n; j++)
        {
            // check if amount-coins is Negative And dp[amount-coin] Cannot be Inf as Inf+1 -> Int overflow...
            if (amount - num[j] >= 0 && dp[amount - num[j]] != INT_MAX)
            {
                // Min Coins needed for amount i.e dp[amount] is minimum between dp[amount] and it's child in the Recursive Tree i.e dp[amount- coinValue]
                dp[amount] = min(dp[amount], dp[amount - num[j]] + 1);
            }
        }
    }

    // The above will create the mini coins required for all the amounts from 0 to targetSum...
    return dp[targetSum];
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();

    // Approach1: Recursive Way...
    //  int ans = solve1(n, num, x);

    // Approach2: Recursion + Memorization...
    //  vector<int> dp(x+1, -1); //A Vector to track minCoins for each Amount Value..
    //  int ans = solve2(n, num, x, dp);

    // Approach3: Tabulation.. [**VVIMP**]
    int ans = solve3(n, num, x);

    // Check if the ans is INF, IF yes, No possible combination of coins exist for target Sum...
    if (ans != INT_MAX)
        return ans;
    return -1;
}

/*
NOTE: For this, There is no Space optimization we can do. Why ?
    -- dp[amount] = min(dp[amount], dp[amount-num[j]]) // here dp[amount-num[j]] depends upon the coins value...
    -- Thus, we cannot remove the dp vector, as it depends upon the number of coins given.
    -- Thus, No Possible way to reduce this Tabulation to Space Optimized Approach.
*/

/*
logic:
    -- If we start at target Sum i.e 7, For 7 we Have 3 options i.e either 1 or 2 or 3.
    -- Down the Tree for each time we pick a coin, the Sum value reduce and we reach close to 0. [A Recursive Tree is formed, We need to implement this]
Implementation:
    -- For Base Case:
        - If targetSum in the Tree is 0 -> return 0 [since we need 0 coins to reach Sum 0]
        - If targetSum is going in negative -> Return Inf i.e INT_MAX.
    -- Now For each Elements/Coins availble, Recursive call the function, with updatedTargetSum i.e targetSum-coin's value.
    -- It will Return an ans, check if ans is not Inf
        - then update the min to keep track of the number of coins we are using...
    NOTE: This works because, the Recursive fun returns min Number of coin to reach targetSum, You simply taking the min of Coins needed in each choice.

Sovle using all 4 Approaches: Recursion, Memorization, Tabulation and Space Optimization
*/