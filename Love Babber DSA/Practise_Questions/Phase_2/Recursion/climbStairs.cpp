// You can take only take either 1 or 2 steps to reach the top of the stair
// possible ways you can do that
#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
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

/*
Logic:

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