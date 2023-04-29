#include <bits/stdc++.h>
using namespace std;

// function to print the 2D-Array
void viewArr(int arr[][3], int rowLen, int colLen)
{
    for (int i = 0; i < rowLen; i++)
    {
        for (int j = 0; j < colLen; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// searching in a 2D array.
bool searchEle(int arr[][3], int rowLen, int colLen, int key)
{
    for (int i = 0; i < rowLen; i++)
    {
        for (int j = 0; j < colLen; j++)
        {
            if (arr[i][j] == key)
                return 1;
        }
    }
    return 0;
}

// finding the RowSum
void rowWiseSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of Row " << i << ": " << sum << endl;
    }
}

// finding the column Sum.
void colWiseSum(int arr[][3], int row, int col)
{
    for (int j = 0; j < col; j++)
    {
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of col " << j << ": " << sum << endl;
    }
}

// finding the largest Row Index
void largestRowSum(int arr[][3], int row, int col)
{
    int maxSum = INT_MIN;
    int maxSumRowIndex = 0;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxSum)
        {
            maxSum = sum;
            maxSumRowIndex = i;
        }
    }
    cout << "Maximum Sum Row is: " << maxSumRowIndex << " with maxSum Value: " << maxSum << endl;
}

int main()
{

    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    viewArr(arr, 2, 3);
    cout << "search a key:" << searchEle(arr, 2, 3, 7) << endl;
    cout << endl;
    rowWiseSum(arr, 2, 3);
    cout << endl;
    colWiseSum(arr, 2, 3);
    cout << endl;
    largestRowSum(arr, 2, 3);
    cout << "MultiDimensional Arrays" << endl;
    return 0;
}
