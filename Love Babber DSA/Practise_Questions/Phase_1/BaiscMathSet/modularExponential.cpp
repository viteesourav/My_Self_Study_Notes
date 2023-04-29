// Using this technique we can find exponential of any number in log(n) time.
/*
Fast Exponential Mthod:
Remove the module part in the below caode and you will find log(n) algo for calculating x^n. (best)
*/

// This problem is to find the res of (x^n)%m.
#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m)
{

    int res = 1;

    while (n > 0)
    {
        // check if n is odd ?
        if (n & 1)
        {
            // worst case: if both res and a is 10^9 then the prod will be higher, int cannot handle so, multiplied by 1LL i.e long long (type-casting)
            res = (1LL * (res % m) * (x % m)) % m; // if odd one extra multiplication by x
        }
        x = (1LL * (x) % m * (x) % m) % m; // if even just keep on multiplying x
        n = n >> 1;                        // update n by dividing by 2.
    }
    return res;
}

/*
LOgic:
Formula:
for a^b --> if b is even then (a^(b/2))^2
        --> if b is odd then (a^(b/2))^2 * a

code Logic: for a^n
-- if n is even keep on multiplying a, and update as n as n/2.
-- if n is odd then return res = res * a.
NOTE: even n starts with even, at the end one time n will be 1 i.e odd, thus it will return the result correct.
eg: 2^5   a^n
res = 1
n= 5 -> odd, res = 1*2 = 2, a = 2*2 = 4, n>>2
n= 2 --> even, 4*4 = 16, n>>2
n= 1, res = 32 (ans)
*/