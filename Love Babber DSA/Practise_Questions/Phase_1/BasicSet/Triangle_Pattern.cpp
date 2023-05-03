#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    cout << "Your Pattern is: " << endl;
    for (int i = 0; i < n / 2; i++)
    {
        for (int k = 0; k < i; k++)
        {
            cout << " "
                 << " ";
        }
        for (int j = i; j < n - i; j++)
        {
            cout << '*' << " ";
        }
        for (int k = n - i; k < n; k++)
        {
            cout << " "
                 << " ";
        }
        cout << endl;
    }

    for (int i = 0; i <= n / 2; i++)
    {
        for (int k = 0; k < (n / 2) - i; k++)
            cout << " "
                 << " ";
        for (int k = (n / 2) - i; k <= n / 2; k++)
            cout << "*"
                 << " ";
        for (int k = n / 2; k < (n / 2) + i; k++)
            cout << "*"
                 << " ";
        for (int k = (n / 2) + i; k < n - 1; k++)
            cout << " "
                 << " ";
        cout << endl;
    }

    return 0;
}

/*
Ouput for the above code:

* * * * * * * * * *
  * * * * * * * *
    * * * * * *
      * * * *
        * *
          *
        * * *
      * * * * *
    * * * * * * *
  * * * * * * * * *
* * * * * * * * * * *

*/