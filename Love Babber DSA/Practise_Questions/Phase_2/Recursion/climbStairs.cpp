// You can take only take either 1 or 2 steps to reach the top of the stair
// possible ways you can do that
#include <bits/stdc++.h>
using namespace std;

// Recursive solution... O(2^n)
int climbStairsRecusrion(int n)
{

    // base case:
    if (n < 0)
        return 0; // if stairs is below ground.
    if (n == 0)
        return 1; // if you are standing on the base stair

    // You are in a stair, you could come to that stair in possible 2 ways
    //  either from the last stair or from the last 2 stair.
    //  why ? since you are allowed to take either 1 or 2 stair.
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// Dp Solution: O(n)
class Solution
{
public:
    int climbStairs(int n)
    {
        // edgeCase:
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        // 1. initializing a dp matrix that stores no of ways we can reach to top from nth stair.
        vector<int> dp(n + 1, 0);

        // 2. If you already at the top i.e nth stair or you are at the n-1th stair you got only 1 way to reach to top.
        dp[n] = dp[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            // no of wys at nth stair ==> no of ways of n+1th stair [if 1 step is taken] + no of ways of n+2th stair [if 2 step is taken].
            dp[i] = dp[i + 1] + dp[i + 2];
        }

        // at the bottom stair, we will have total ways to reach to top.
        return dp[0];
    }
};

/*
Optimal Logic: DP solution using memorization.
Steps:
    1. edgecase:
        - If we just have 1 stair => we can do it in 1 way only.
        - If we just have 2 stairs => we can do it in 2 ways only.
    2.  n =5,
        If we are at 5th step => no of ways to top => 1 way.
        If we are at 4th step => no of ways to top => 1 way.
        If we are at 3rd step => no of ways to top => either you go to 4th stair or 5th stair => chancesAt(4) + chancesAt(5) => 1 + 1 => 2 ways.
        If we are at 2nd step => no of ways to top => either you go to 3rd stair or 4th stair => chancesAt(3) + chancesAt(4) => 2 + 1 => 3 ways.
        If we are at 1st step => no of ways to top => either you go to 2nd stair or 3rd stair => chancesAt(2) + chancesAt(3) => 3 + 2 => 5 ways.
        If we are at 0th step => no of ways to top => either you go to 1st stair or 2nd stair => chancesAt(1) + chancesAt(2) => 5 + 3 => 8 ways.  [ans]

*/

/*
Logic: Recurisve approach.

n = 5

steps i can take: 1 step or 2 steps.
        n
0 1 2 3 4
1 2 3 4 5
i

How could you reach the last stair ?

-- either from the immediate last stair or from the 2nd last stair.

f(n) = f(n-1) + f(n-2)

Base Case:

n < 0 --> return 0  if the stairs in below ground,

n = 0  --> return 1, if you are at the base stair

Dry Run for n=5

0 1 2 3 4 5

f(n) = f(n-1) + f(n-2)

f(5) = f(4) + f(3) = 5 + 3 = 8 (ans)
f(4) = f(3) + f(2) = 3 + 2 = 5
f(3) = f(2) + f(1) = 2 + 1 = 3
f(2) = f(1) + f(0) = 1 + 1 = 2 (base case hit)
f(1) = f(0) + f(-1) = 1 + 0  = 1 (base case hit)
f(0) ->base case hit. => 1

*/