// Link: https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261
/*
    You Given a List of n Elements. Find the max Sum possible for the Elements which are not adjacent to Each Other...
*/
#include <bits/stdc++.h>
using namespace std;

// Approach1: Recursion appraoch [TC: Exponential]
int solve1(vector<int> &nums, int n, int currIndex)
{
    // baseCase:
    if (currIndex < 0)
    { // If the currIndex goes below 0 index....
        return 0;
    }

    // Now for element at currIndex, 2 options: Either include it or don't include it...
    // If you include, includeSum is currIndex value and value of the next element will be 2nd element from currIndex towards left.
    // If you exlude, excludeSum is 0 and the next element can be the immediate previous element.
    int includeSum = nums[currIndex] + solve1(nums, n, currIndex - 2);
    int excludeSum = 0 + solve1(nums, n, currIndex - 1);

    // Recusrion will fetch be the max of include and exclude Sum for currIndex.
    return max(includeSum, excludeSum);
}

// Appraoch2: Recursion + Memorization.. TC:O(N) SC:O(N) + O(N)
int solve2(vector<int> &nums, int n, int currIndex, vector<int> &dp)
{
    // baseCase:
    if (currIndex < 0)
    { // If the currIndex Exceeds the nums size..
        return 0;
    }

    // Check if the dp alreday hold the maxSum for currIndex...
    if (dp[currIndex] != -1)
        return dp[currIndex];

    // Now for element at currIndex, 2 options: Either include it or don't include it...
    // If you include, includeSum is currIndex value and value of the next element will be 2nd element from currIndex towards left.
    // If you exlude, excludeSum is 0 and the next element can be the immediate previous element.
    int includeSum = nums[currIndex] + solve2(nums, n, currIndex - 2, dp);
    int excludeSum = 0 + solve2(nums, n, currIndex - 1, dp);

    // Recusrion will fetch be the max of include and exclude Sum for currIndex.
    // Store the max of include and exlude Sum in the dp[currIndex]...
    dp[currIndex] = max(includeSum, excludeSum);
    return dp[currIndex];
}

// Approach3: Tabulation Approach [TC: O(N) SC:O(N)]
int solve3(vector<int> &nums, int n)
{

    // lets create a dp Vector...
    vector<int> dp(n + 1, 0);

    // For the first element, the maxSum Possible is the element itself..
    dp[0] = nums[0];

    // Now we will use a loop to determine maxSum possible for other elements...
    // For any position, IncludeSum add dp value from 2 step back and current value..
    //  and excludeSum takes currentValue as 0 [since we are excluding] and takes the immediate left value.
    for (int i = 1; i < n; i++)
    {
        int includeSum = nums[i] + dp[i - 2]; // NOTE: dp[i-2] for i=1 is dp[-1] -> 0 [It wont have any garbage value, for out of range indexs, vector stores 0]
        int excludeSum = 0 + dp[i - 1];
        dp[i] = max(includeSum, excludeSum);
        // cout<<i<<" "<<includeSum<<" "<<excludeSum<<endl; //You can see how data is getting populated here...
    }

    // return the max Sum at n-1th place...
    return dp[n - 1];
}

// Space Optimization...TC:O(N) SC:O(1)
int solve4(vector<int> &nums, int n)
{
    // First lets start with the values for prev1 and prev2..
    int prev1 = 0;       // this hold i-2th index value..
    int prev2 = nums[0]; // this holds i-1th index value..

    // iterate from index 1 to n, find the include and excludeSum -> upadte prev1 and prev2
    for (int i = 1; i < n; i++)
    {
        int includeSum = nums[i] + prev1; // since incldue sum depends upon i-2th value..
        int excludeSum = 0 + prev2;       // since exclude sum depends upon i-1th value...
        int maxi = max(includeSum, excludeSum);

        // upate the prev1 and prev2...
        prev1 = prev2;
        prev2 = maxi;
    }

    return prev2; // prev2 will hold the maxSum at n-1th index...
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    // Appraoch1: using Recursion..
    //  return solve1(nums, n, n-1);  //we start from right to left...

    // Appraoch2: Recursion + Memorization..
    //  vector<int> dp(n+1, -1);
    //  return solve2(nums, n, n-1, dp);

    // Approach3: Tabulation..
    //  return solve3(nums, n);

    // Approach4: Space Optimization..
    return solve4(nums, n);
}
/*
Logic:
    -- For each Element, it has 2 choices:
        1) If we consider it:
            -- WE are not allowed to take the next Element, we need to consider the second previous element.[Going right to left in the list]
            -- In Include case: IncludeSum = element's Value + Recursion will fetch the max Sum if this is considered.
        2) If we don't consider it:
            -- If we Dont consider, Then we are allowed to take the previous Element. [Going right to left in the list]
            -- In Exlude case: ExcludeSum = 0 [as we are not considering the curr Element] + Recursion will fetch the max Sum for the next Element.
        -- Now we have both Include and Exclude Sum -> max will give the answer...
    BaseCase:
        -- You start from right to left. If the index < 0 -> Return 0. [since negative index we shouldn't process]
*/