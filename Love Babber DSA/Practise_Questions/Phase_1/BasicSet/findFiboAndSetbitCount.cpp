#include <bits/stdc++.h>
using namespace std;

// counts the number of setBit i.e 1 in the binary representation of this number.
int countSetBit(int a)
{
    int cnt = 0;
    while (a != 0)
    {
        if (a & 1)
            cnt++;
        a = a >> 1;
    }
    return cnt;
}

// Find the nth number from the fibo series.
int findFibo(int n)
{
    int a = 0, b = 1, i = 3;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    while (1)
    {
        int temp = b;
        b = a + b;
        a = temp;
        if (i == n)
            return b;
        i++;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    cout << findFibo(n) << endl;

    return 0;
}
