#include <bits/stdc++.h>
using namespace std;
#define ll long long

// fast Power... using For Loop
ll fastPow(int a, int b)
{
    ll res = 1;
    while (b > 0)
    {
        // cout<<a<<" "<<b<<endl;
        if (b & 1)
        { // same as b%2 != 0, checks odd or not
            // if odd
            res = res * a;
            // cout<<"res Value: "<<res<<endl;
        }
        a = a * a;
        b = b >> 1; // same as b= b/2
    }
    return res;
}

// Same Recursion Approach, going as per the formule...
ll fastPow3(int a, int b)
{
    cout << a << " " << b << endl;
    // baseCase:
    if (b == 0)
        return 1; // anything to the power zero is 1.
    if (b == 1)
        return a; // a^1 will be a only

    int ans = fastPow3(a, b / 2);

    // now check if b is odd or even
    if (b & 1)
    {
        return a * ans * ans;
    }
    else
    {
        return ans * ans;
    }
}
/*
Dry Run:

As per formule:

 a^b ->
 if b is odd -> a * (a^b/2) * (a^b/2)
 If b is even -> (a^b/2) * (a^b/2);

 fn(3, 11) -> fn(3, 5) -> 243, 3*243*243 = 177147
 fn(3, 5) -> fn(3, 2) -> 9, 3*9*9 = 243
 fn(3, 2) -> fn(3, 1) --> 3 , 3*3 = 9
 fn(3, 1) [BC hit] --> 3
*/

int main()
{
    int x, y;
    cin >> x >> y;
    // using Fast Pow using loops
    cout << fastPow(x, y) << endl;
    // using Fast Pow using Recursion.
    cout << fastPow2(x, y) << endl;
    cout << "Basic Math Recursion" << endl;
    return 0;
}
