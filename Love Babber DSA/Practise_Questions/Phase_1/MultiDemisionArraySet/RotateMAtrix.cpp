// this is how we rotate a matrix by 90 deg..
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void rorateAllEle(vector<vector<int>> &matrix, int startRow, int endRow, int startCol, int endCol, int noOfSwaps)
    {
        int i = startRow, j = endRow;
        // here i tracks the upperRow and endColumn in ascending Order
        //  j tracks the bottomRow and firstColum in descending Order
        while (noOfSwaps > 0)
        {
            int temp = matrix[startRow][i];
            swap(temp, matrix[i][endCol]);
            swap(temp, matrix[endRow][j]);
            swap(temp, matrix[j][startCol]);
            matrix[startRow][i] = temp;
            i++;
            j--;
            noOfSwaps--;
        }
    }

public:
    void rotate(vector<vector<int>> &matrix)
    {

        // taking the row and column count
        int row = matrix.size();
        int col = matrix[0].size();

        // lets start mark the boundary row and col
        int startRow = 0, endRow = row - 1, startCol = 0, endCol = row - 1;
        int noOfSwaps = row - 1;

        // we will rorate till the rows or the colns collide..
        while (startRow < endRow && startCol < endCol)
        {

            // this function will rorate all elements in the boundary by 90 deg
            rorateAllEle(matrix, startRow, endRow, startCol, endCol, noOfSwaps);

            // we will update the boundary and noOfElementSwaps needed
            startRow++;
            endRow--;
            startCol++;
            endCol--;
            noOfSwaps -= 2; // why 2 because both start and end Col will move towards each other.
        }
    }
};

/*
Logic behind this:

 1 2 3        7 4 1
 4 5 6   -->  8 5 2
 7 8 9        9 6 3

 00 01 02
 10 11 12
 20 21 22

startRow = 0
startCol = 0
endRow = n-1
endCol = n-1

ElementToSwitch = n-1

while(startRow < endRow && startCol < endCol)

RotateAllElemInRing(sR, sC, eR, eC, EleToSwitch);
EleToSwitch -= 2;

startRow++;
startCol++;
endRow--;
endCol--;


//dry run working fine..
RotateAllElemInRing(sR, sC, eR, eC, ele) {

r1 = 0, c1 = 0, r2=3, c2=3
i=r1=0, j =r2 = 3
while(ele > 0)
    temp = arr[r1][i];
    swap(arr[i][c2], temp);
    swap(temp, arr[r2][j]);
    swap(temp, arr[j][c1]);
    arr[r1][i] = temp;
    i++;j--;
    ele--;
end;



first iteration: based on ele.

i=0, j=3, r1 = 0, c1=0, r2=3, c2=3

i = 1, j =2
i= 2, j = 3

temp = 13


second iteration:

i=2, j=1, r1 = 1, c1=1, r2=2, c2=2

temp = 3

01 -> 13
13 -> 31
31 -> 10
10 -> 01



*/