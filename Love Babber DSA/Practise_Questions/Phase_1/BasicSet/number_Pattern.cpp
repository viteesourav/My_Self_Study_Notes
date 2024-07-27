#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    // Examples of few pattern code:  NOTE: See the code and make the pattern.
    // int t = 1;
    //  for(int k=1;k<=n;k++) {
    //      for(int p=0;p<k;p++) {
    //          cout<<k-p<<" ";
    //      }
    //      cout<<endl;
    //  }

    // for(int k=1; k<=n;k++) {
    //     for(int p=1;p<=k;p++) {
    //         cout<<(char)(65+n-k+p-1)<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int k=1;k<=n;k++) {
    //     for(int p=1; p<=k-1;p++) cout<<" "<<" ";
    //     for(int j=0; j<=n-k; j++) cout<<k+j<<" ";
    //     cout<<endl;
    // }

    // Little difficult one but intersenting pattern.
    // Pattern 1:
    // for (int k = 1; k <= n; k++)
    // {
    //     for (int p = 1; p <= n - k; p++)
    //         cout << " "
    //              << " ";
    //     for (int j = 0; j < k; j++)
    //         cout << j + 1 << " ";

    //     for (int r = 1; r <= k - 1; r++)
    //         cout << k - r << " ";
    //     for (int c = 1; c <= n - k; c++) // This for loop is optional, tailing spaces print are not necessary.
    //         cout << " "
    //              << " ";
    //     cout << endl;
    // }

    // pattern 2:
    for (int k = 1; k <= n; k++)
    {

        for (int p = 1; p <= n - k + 1; p++)
            cout << p << " ";
        for (int j = n - k + 2; j <= n; j++)
            cout << "*"
                 << " ";

        for (int p = 1; p <= k - 1; p++)
            cout << "*"
                 << " ";
        for (int j = 1; j <= n - k + 1; j++)
            cout << n - k + 2 - j << " ";

        cout << endl;
    }

    return 0;
}

/*
Conclusion: 
    -- Mostly the pattern linked with n, row and col, 
    -- approach to find Formula, Take one row, col, see how the values are increasing or decreasing based n and previous rows..
    -- It will take some time, Trial and error, Try to frame the formula
    -- This formula, basically works on n, row and col.
*/

/*Output: Pattern 1:

4
      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1

Output pattern 2:
5
1 2 3 4 5 5 4 3 2 1
1 2 3 4 * * 4 3 2 1
1 2 3 * * * * 3 2 1
1 2 * * * * * * 2 1
1 * * * * * * * * 1
*/

/*Logic: pattern1:
    + 1 2 3 4  5 6 7
    1  _ _ _ 1  _ _ _
    2  _ _ 1 2  1 _ _
    3  _ 1 2 3  2 1 _
    4  1 2 3 4  3 2 1

Logic Pattern2:

   +  1 2 3 4 5   6 7 8 9 10
   1  1 2 3 4 5   5 4 3 2 1
   2  1 2 3 4 *   * 4 3 2 1
   3  1 2 3 * *   * * 3 2 1
   4  1 2 * * *   * * * 2 1
   5  1 * * * *   * * * * 1
*/