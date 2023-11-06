// Link: https://www.codingninjas.com/studio/problems/ninja-and-the-fence_3210208
/*
Bascially, You have been given n poles/posts and k distinct colors. You need to paint n posts such that no more than 2 adjacent poles have same color.
    How many ways of acheiving this ?
*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

// utility Function to handle addition and multiplication of with MOD..
int addUtil(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int mulUtil(int a, int b)
{
    return ((a % MOD) * 1LL * (b % MOD)) % MOD; // 1LL is long long int to hold the res of multiplication
}

// Approch1: Recursive Solution [TC: Exponential]
int solve1(int n, int k)
{
    // baseCase:
    // Only 1 poles..
    if (n == 1)
    {
        return k;
    }
    // for 2 poles..
    if (n == 2)
    {
        return k + k * (k - 1);
    }

    // Now For other n, Recursion will fetch me the ans..
    int ans1 = mulUtil(solve1(n - 2, k), k - 1); // For last 2 poles having same color..
    int ans2 = mulUtil(solve1(n - 1, k), k - 1); // For last 2 poles having different color..
    int ans = addUtil(ans1, ans2);

    return ans;
}

// Approch2: Recursive + Memorization Solution [TC: O(N) SC:O(N)+O(N)]
int solve2(int n, int k, vector<int> &dp)
{
    // baseCase:
    // Only 1 poles..
    if (n == 1)
    {
        return k;
    }
    // for 2 poles..
    if (n == 2)
    {
        return k + k * (k - 1);
    }

    // check for ans in the dp vector...
    if (dp[n] != -1)
        return dp[n];

    // Now For other n, Recursion will fetch me the ans..
    int ans1 = mulUtil(solve2(n - 2, k, dp), k - 1); // For last 2 poles having same color..
    int ans2 = mulUtil(solve2(n - 1, k, dp), k - 1); // For last 2 poles having different color..
    dp[n] = addUtil(ans1, ans2);

    return dp[n];
}

// Appraoch3: Tabulation [Getting rid of Recursion]
int solve3(int n, int k)
{
    // initialize the dp array...
    vector<int> dp(n + 1, 0);

    // include the base case in the dp array..
    dp[1] = k;               // For 1 pole
    dp[2] = k + k * (k - 1); // For 2 pole

    // loop till n to find the solution for other poles..
    for (int i = 3; i <= n; i++)
    {
        int ans1 = mulUtil(dp[i - 2], k - 1); // For last 2 poles having same color..
        int ans2 = mulUtil(dp[i - 1], k - 1); // For last 2 poles having different color..
        dp[i] = addUtil(ans1, ans2);
    }

    return dp[n];
}

// Appraoch: Space Optimization TC:O(N) SC:O(N)
// Possible as dp[i] is dependent on dp[i-2] and dp[i-1]
int solve4(int n, int k)
{

    // include the base case in the dp array..
    int prev1 = k;               // For 1 pole
    int prev2 = k + k * (k - 1); // For 2 pole

    // loop till n to find the solution for other poles..
    for (int i = 3; i <= n; i++)
    {
        int ans1 = mulUtil(prev1, k - 1); // For last 2 poles having same color..
        int ans2 = mulUtil(prev2, k - 1); // For last 2 poles having different color..
        int ans = addUtil(ans1, ans2);

        // update the pointers..
        prev1 = prev2;
        prev2 = ans;
    }

    return prev2;
}

// Approach: Fence Painting Algorithm...[f(n) = f(n-2)(k-1) + f(n-1)(k-1)]
int numberOfWays(int n, int k)
{
    // return solve1(n, k);

    // vector<int> dp(n+1, -1);
    // return solve2(n, k, dp);

    // return solve3(n, k);

    return solve4(n, k);
}

/*
Logic: Fence Painting Algorithm [** VVIMP **]
    1) First Finding the Relation
        - Lets say you have 3 colors: R, G, B [k=3]

    case1: if n=1 [only one pole] [_]
        -- No of ways of painting this would be 3 i.e k

    case2: if n=2 [2 poles are there] [_ _]
        1) For 2 poles having same color: i.e RR, GG or BB, Thus only 3 choices i.e k
        2) For 2 poles having different color: kPn [Permutation] i.e 3*2 -> 6 choices i.e k*(k-1)
    Thus, Total Choices for n=2 -> K + K*(K-1)

    case3: if n=3 [3 Poles] [ _ _ _ ]
        -- Lets holds the assumption that we will consider the last 2 poles to have either same or different colors...
        1) last 2 poles having same color
            -- Here for last 2 poles having same Color i.e 3 choices [from n=2, same color] and for each we can select a color that is not selected.
            -- eg: RR, BB, GG -> For each we have 2 options i.e RR can have either B or G as the color of first pole.
        Total: k*(k-1) choices
        2) last 2 Poles having different Color
            -- Okay so total no of ways for the first 2 poles will be form above i.e ans for n=2.
            -- Now to make the last pole different color: we have k-1 options.
        Thus total: fn(n=2) * (k-1) ways.

    case4: if n=4 [4 poles] [ _ _ _ _ ]
        1) last 2 Poles will have the same Color
            -- last 2 poles same color, options: RR, BB, GG i.e 3 ways or K ways
            -- The first 2 poles can have ans from n=2 i.e fn(n=2)
            -- Now to avoid last all 3 poles to have same color, For each Poles from fn(n=2) have k-1 options.
        Thus, Total: fn(n-2)*(k-1) ways.

        2) last 2 poles will have different Color
            -- lets Conside the solution for n=3 i.e fn(n=3) will give all possible combination to paint 3 poles.
            -- we add one more pole, and we have k color option.
            -- to avoid repeat color, we will have k-1 options to paint it.
        Thus, total: fn(n=3)*(k-1) ways.
    Total: fn(4) = fn(2)*(k-1) + fn(3)*(k-1)

    General Reucrsion Relation to Solve this problem:
        fn(n) = fn(n-2)*(k-1) + fn(n-1)*(k-1)

    2) Implement DP Concept: Recursion, Recursion + Memorization, Tabulation, Space Optimization
*/