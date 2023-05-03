/*
Power of 2 --> check if the given integer is a power of 2 ?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // edge case handled
        if (n == 0 || n < 0)
            return false;
        if ((n & n - 1) == 0)
            return true;
        else
            return false;
    }
};

/*
Logic:
If n&n-1 == 0 then its a power of 2 else not.
eg:
16&15 -> 1000 & 0111  -> 0
*/