// Link: https://leetcode.com/problems/house-robber-ii/
/*
A Robber is there, He goes to a place where n houses are there in a circele [First and last house are adjacent] each with some amount of money.
    Condition: He cannot rob adjacent Houses.
Thus, Maximise the Sum he can rob.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Appraoch: Non-Adjacent Element max Sum logic [Space optimised Appraoch] TC: O(N) SC:O(1)
    int solve(vector<int> &nums)
    {
        int n = nums.size();

        int prev1 = 0;       // this holds maxSum for the n-2th position...
        int prev2 = nums[0]; // this holds maxSum for the n-1th position...

        // loop thorugh rest of the elements..
        for (int i = 1; i < n; i++)
        {
            int includeSum = nums[i] + prev1; // includeSum = Element's Value + maxSum of n-2th post
            int excludeSum = 0 + prev2;       // excludeSum = 0 + maxSum of n-1th post
            int maxSum = max(includeSum, excludeSum);

            // update prev1 and prev2...
            prev1 = prev2;
            prev2 = maxSum;
        }

        return max(prev1, prev2); // returning the max for Sum at n-2th post and n-1th post for nth post
    }

public:
    int rob(vector<int> &nums)
    {
        // Approach: Non-Adjacent Max_sum Approach...
        int n = nums.size();

        // EdgeCase: If there is just 1 house...
        if (n == 1)
            return nums[0];

        // Now As the first and last house are adjacent, we cannot consider both of them together...
        vector<int> nums1(n - 1), nums2(n - 1);
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                nums1.push_back(nums[i]); // case1: Except last house push all.
            }
            if (i != 0)
            {
                nums2.push_back(nums[i]); // case2: Except the first element push all
            }
        }

        // max of the Result of nums1 and nums2 is the ans..
        return max(solve(nums1), solve(nums2));
    }
};
/*
Logic: Implementation of nonAdjacent Max Sum Approach. [We will use the Space Optimised bottoms up Approach]
    -- If the First House and last house are adajacent, we cannot Consider both of them at once.
        -- sum1 -> Include all the houses except the last house.
        -- sum2 -> Include all the houses except the first house.
        -- Find the max of sum1 and sum2 -> Ans.
Approach:
    - Given a series of numbers, 2 choices for each Numbers...
      1) If considered, IncludeSum = element's Val + MaxSum of the 2nd previous Elements.
      2) If not considered, excludeSum = 0 [since not considering the element] + MaxSum of the previous Elements.
    - Max of IncludeSum and excludeSum is the MaxSum possible for the currElement.
*/