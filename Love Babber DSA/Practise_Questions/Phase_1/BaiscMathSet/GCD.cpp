// Implementation of Euclid's MEthods. --> Finding GCD of 2 numbers
// Formula: gcd
#include <bits/stdc++.h>
using namespace std;

// method1: iterative way...
int findGCD(int a, int b)
{

    // which ever becomes zero first return other one.
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // till a and b are euqal, keep reducing the bigger number by subtraction.
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a; // If case a and b are not zero and equal.
}

// Method2: Recurrsive way, clean and fast way...
int findGCD2(int a, int b)
{
    if (b == 0)
        return a;
    return findGCD2(b, a % b);
}