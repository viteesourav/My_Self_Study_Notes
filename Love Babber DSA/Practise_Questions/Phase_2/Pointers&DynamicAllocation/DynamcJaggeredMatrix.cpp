// Jaggered MAtrix:
// Matrix which has irregular column lengths for every row.

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int rows;
    cin >> rows;

    // Creating dynamic Jaggered Array
    int **arr = new int *[rows];
    int colCount = 1;
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[colCount++];
    }

    // taking input for jaggered array...
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            // cout<<i<<" "<<j<<endl;
            arr[i][j] = 0;
        }
    }

    // printing jaggered array...
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // releasing the memory from heap.
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    cout << endl;
    cout << "Jaggered Array" << endl;
    return 0;
}