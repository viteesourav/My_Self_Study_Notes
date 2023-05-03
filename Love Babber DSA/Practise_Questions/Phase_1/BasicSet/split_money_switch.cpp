// This code shows how to use switch to split the money in 100s,50s,20s and 1s
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int amount, st = 100;
    cin >> amount;

    switch (st)
    {
    case 100:
        cout << "You need " << (amount / 100) << "Notes of  100s" << endl;
        amount = amount % 100;
    case 50:
        cout << "You need " << (amount / 50) << "Notes of  50s" << endl;
        amount = amount % 50;
    case 20:
        cout << "You need " << (amount / 20) << "Notes of  20s" << endl;
        amount = amount % 20;
    case 1:
        cout << "You need " << (amount / 1) << "Notes of  1s" << endl;
        amount = amount % 1;
    }

    cout << "********Split completed**********" << endl;

    return 0;
}

/*
Notice:
-- here we are not using break in any of the above cases.
-- So, all the cases runs from top to bottom one by one.

*/
