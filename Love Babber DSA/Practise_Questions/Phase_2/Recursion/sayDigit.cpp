// say out the Digit loud,
// 421 -> four two one

#include <bits/stdc++.h>
using namespace std;

// say Digit
void sayDigit(int n)
{

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // base case:
    if (n == 0)
        return;

    int digit = n % 10;

    // calling the recursive function.
    sayDigit(n / 10);

    cout << arr[digit] << " ";
}

int main()
{
    sayDigit(421);
    return 0;
}

/*
Dry Run:
4 2 1

f(421), digit = 1
f(42), digit = 2
f(4), digit = 4
f(0) => (base case hit)

*/