// Link: https://www.codingninjas.com/studio/problems/count-derangements_873861
/*
You have an array say {0, 1, 2}, Find the number of possible arrangements where non of the elements are at there original place.
    i.e for above 2 possible de-arrangment available: {2, 0, 1} and {1, 2, 0}.
*/
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

// Appraoch1: Recursion [F(n) = (n-1)*(f(n-2) + f(n-1))]
long long int solve1(int n)
{
    // baseCase:
    if (n == 1)
        return 0; // If only 1 element, no dearrangment possible.
    if (n == 2)
        return 1; // If only 2 elements, only 1 dearrangment possible.

    // Now use Recursion and Realtion to fint the ans..
    long long int ans = (n - 1) * ((solve1(n - 2) % MOD) + (solve1(n - 1) % MOD)) % MOD;

    return ans % MOD;
}

// Appraoch2: Recursion + Memorization...
long long int solve2(int n, vector<long long int> &dp)
{
    // baseCase:
    if (n == 1)
        return 0; // If only 1 element, no dearrangment possible.
    if (n == 2)
        return 1; // If only 2 elements, only 1 dearrangment possible.

    // After baseCase, check if dp already holds the value ?
    if (dp[n] != -1)
        return dp[n];

    // Now use Recursion and Realtion to fint the ans..
    dp[n] = ((n - 1) * ((solve2(n - 2, dp) % MOD) + (solve2(n - 1, dp) % MOD)) % MOD) % MOD;

    return dp[n];
}

// Appraoch3: Tabulation..[Get Rid of the REcursion]
long long int solve3(int n)
{
    // Lets keep a track vector..
    vector<long long int> dp(n + 1, 0); // initially all holds 0.

    // baseCase things initialization...
    dp[1] = 0; // For n=1, no de-arrangments present.
    dp[2] = 1; // for n=2, only 1 de-arrangments present..

    // Now for rest of the elements iterate..
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((i - 1) * (dp[i - 2] % MOD + dp[i - 1] % MOD) % MOD) % MOD;
    }

    // at the end, return the ans at nth index...
    return dp[n];
}

// Appraoch4: Space Optimization..dp[n] depends upon dp[n-2] and dp[n-1] [Possible]
long long int solve4(int n)
{

    // baseCase things initialization...
    long long int prev1 = 0; // For n=1, no de-arrangments present.
    long long int prev2 = 1; // for n=2, only 1 de-arrangments present..

    if (n == 1)
        return prev1;
    if (n == 2)
        return prev2;

    // Now for rest of the elements iterate..
    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int tot = (first + second) % MOD;

        long long int ans = ((i - 1) * tot) % MOD;
        prev1 = prev2;
        prev2 = ans;
    }

    // at the end, return the ans at nth index...
    return prev2;
}

long long int countDerangements(int n)
{
    // return solve1(n);

    // vector<long long int> dp(n+1, -1);
    // return solve2(n, dp);

    // return solve3(n);

    return solve4(n);
}
/*
Logic:
    - First we need to find a REcursive Realtion for this problem.
    - So say there are n elements, we need to place in n boxes of an array.
    1) take an element, what will be possiblities of placeing this element ?
        ans = (n-1) * [Optimized solution of all other elements]
        -- Why n-1 ? 0 we cannot keep in 0th index, i.e available spaces is n-1.

    2) For Optimized solution for placing other Elements there are 2 cases:
        1) Case1: You have choose an element and decided to put at index i, [possiblity index i will hold some element]
            - so we swap values at both the indexes.
            - Now, how many element and how many available spaces are left ? -> n-2  [since 2 space occupies by i and element]
            - i.e f(n-2) [we have n-2 element to place at n-2 places]

        2) Case2: You have choose an element and want to put at index anywhere other than it's own.
             - so you put the element at index i, but you dont want to put i at element's position.
             - Now, how many elements including i and how many available spaces are left ? -> n-1  [since 1 space occupies by element]
             - i.e f(n-1) [we have n-1 elements to place at n-1 spaces]

    Thus the from 1 and 2, combined Recursion Relation: f(N) = (n-1) * [f(n-1) + f(n-2)].

-- Now Use appraoch for 1-D, Reucrsion, Recursion + Memeorization, tabulation, space Optimization.

*/