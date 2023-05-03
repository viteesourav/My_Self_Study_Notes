#include <bits/stdc++.h>
using namespace std;
long long findPower(int n)
{
    // base condition
    if (n == 0)
        return 1;
    // breaking it into recurssive functions r
    return findPower(n - 1) * 2;
}
long long findFactorail(int n)
{
    // base condition
    if (n == 0)
        return 1;
    return n * findFactorail(n - 1);
}
void printCount(int n)
{
    if (n == 0)
        return;
    // cout<<n<<" "; //This runs as a part of tail recurssion
    printCount(n - 1);
    cout << n << " "; // This runs as a part of head recurssion.
}

int main()
{
    int n;
    cin >> n;
    cout << "Power Value is: " << findPower(n) << endl;
    cout << "Factorial Value is: " << findFactorail(n) << endl;
    printCount(n);
    cout << endl;
    cout << "REcurssion" << endl;
    return 0;
}