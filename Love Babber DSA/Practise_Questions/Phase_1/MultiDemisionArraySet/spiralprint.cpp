#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int row = matrix.size();
        int col = matrix[0].size();
        int eleCount = 0, totEle = row * col;
        vector<int> ans;

        int startRow = 0, startCol = 0, endRow = row - 1, endCol = col - 1;
        // till all the elements are visted
        while (eleCount < totEle)
        {

            // visit all ele in firstRow the update firstRow
            for (int j = startCol; j <= endCol && eleCount < totEle; j++)
            {
                ans.push_back(matrix[startRow][j]);
                eleCount++;
            }
            startRow++;

            // visit all ele in endCol the update endCol
            for (int i = startRow; i <= endRow && eleCount < totEle; i++)
            {
                ans.push_back(matrix[i][endCol]);
                eleCount++;
            }
            endCol--;

            // visit all ele in endRow the update endRow
            for (int j = endCol; j >= startCol && eleCount < totEle; j--)
            {
                ans.push_back(matrix[endRow][j]);
                eleCount++;
            }
            endRow--;

            // visit all ele in startCol the update startCol
            for (int i = endRow; i >= startRow && eleCount < totEle; i--)
            {
                ans.push_back(matrix[i][startCol]);
                eleCount++;
            }
            startCol++;
        }
        return ans;
    }
};

/*
Logic:

  00 01 02
  10 11 12
  20 21 22

  00 01 02 12 22 21 20 10 11


  StartingRow = 00 to 02
  StartingCol= 00 to 20
  EndRow = 20 to 22
  EndCol = 02 to 22

 print starting Row, then SR++; SR =1

 printing ending Col, then EC--; EC= 1

 printing ending ROW, then ER--; ER = 1

 print starting column, then SC++; SC= 1


*/