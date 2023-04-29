// Example of Sieve of Erathosthenes.
//  Problem: Find the count of prime numbers strictly less than n;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        // this is I assume all numbers are prime in the begining...
        vector<bool> primeSet(n + 1, true);

        // handle the case of 0 and 1
        primeSet[0] = primeSet[1] = false;
        int count = 0;
        for (int i = 2; i < n; i++)
        {

            if (primeSet[i])
            {
                count++; // increase the count if you find a prime number.

                // basically all the numbers coming ahead divisible by i am making them prime set false.
                int j = i * 2;
                while (j < n)
                {
                    primeSet[j] = false;
                    j = j + i;
                }
            }
        }
        return count;
    }
};

/*
Logic:

sieve of eratosthenes

-- assume all are prime no.
-- mark all ele that are divisible by current ele as non-prime.
-- at the end left out numbers are prime.

n= 20

p p   p   p        p     p           p     p
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
_   _   _   _ _ _     _     _   _  _    _


TimeComplexity Analysis:

for 2 we remove all 2-multipled elements : n/2;
for 3 we remove all 3-miltipled ele: n/3 and so on...

n/2 + n/3 + n/5 + 1/7 +......+ n/n-1

n (1/2 + 1/3 + 1/5+ 1/7 + ....) => n (Harmonic progression of prime numbers) => nlog(logn)  (THis is the TC)


*/