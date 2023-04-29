#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0, end = row * col - 1;

        // using the BS logic
        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            if (matrix[mid / col][mid % col] == target) // this is how you get the matrix indices from mid value.
                return true;

            if (matrix[mid / col][mid % col] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};

/*
Logic:
Searching in 2D matrix using Binary Search


  1   3  5  7
 10  11 16 20    row -> 3
 23  30 34 60    col -->4

 0 1 2 3 4   5  6 7  8  9  10 11
 1 3 5 7 10 11 16 20 23 30 34 60
 s           m                 e

m = 5,  a[m]= a[row][col] = 11

row -> 5/4 --> 1
col -> 5%4 --> 1

*/