#include <bits/stdc++.h>
using namespace std;

// logic for implementing fibo using Recursion.
int fib(int n)
{

    // base case..
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    // calling the function recursive
    return fib(n - 1) + fib(n - 2);
}

/*
Logic:

fibo series:

0 1 2 3 4 5 6 7
0 1 1 2 3 5 8 13 21

f(n) = f(n-1) + f(n-2)

f(2) = f(1) + f(0) = 1 + 0  = 1 (base case)

so if n==1 => 1 and if n==0 => 0

f(3) = f(2) + f(1) = 1 + 1 = 2

f(4) = f(3) + f(2) = 2 + 1 = 3 ... and so on...

*/