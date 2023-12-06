// Link: https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_1062686
/*
MCMS: Matrix Chain Multiplication Problem

Basically You given an Array eg: arr = [2, 4, 3, 2] Here, Matrix A [2 X 4], Matrix B [4 X 3], Matrix C [3 X 2]

Now to Multiply ABC,
    ways:
        1. A (BC) -> [2x4] ([4X3][3X2]) -> (4*3*2) [Operations for multiplying BC] + (2*4*2) [Operation for Multiplying A with new matrix BC]
                                        = 24 + 16 = 40
        2. (AB) C -> ([2x4][4x3]) [3x2] -> (2*4*3) + (2*3*2) = 24 + 12 = 36

    Thus, The Minimum Number of Operation Needed is 36 (Ans)
*/

#include <bits/stdc++.h>
using namespace std;

// Appraoch: Using Tabulation Method [Bottoms Up Approach]
int solve1(vector<int> &arr)
{

    int n = arr.size();

    // 1. creating a dp matrix of size nxn with all values as INT_MAX.
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 2.Now Iterate the col first, then row...
    for (int len = 2; len < n; len++)
    {
        int col = len;
        for (int row = 0; row < n - len; row++)
        {
            // The above set of for loop, make sure, we move in digonal...
            // Now, for number of ways of arrangements,
            dp[row][col] = INT_MAX;
            for (int k = row + 1; k < col; k++)
            { // This k gives the possible combination of Multiplication of matrixes...
                dp[row][col] = min(dp[row][col],
                                   (dp[row][k] + dp[k][col] + (arr[row] * arr[k] * arr[col])));
            }
            col++;
        }
    }

    return dp[0][n - 1]; // The first row, last column will hold the min Operation possible.
}

int minMultiplicationOperations(vector<int> &arr)
{
    return solve1(arr);
}

/*
Ref: https://www.youtube.com/watch?v=-UPo_dzBw1c&t=32s

       0  1  2  3
arr = [2, 4, 3, 2],
    where (0,1) represent Matrix A [2 X 4], (1,2) represent Matrix B [4 X 3], (2,3) represent Matrix C [3 X 2]

Appraoch: Using Tabulation Method.
    1. First You create a 2-D DP with initial Values all as 0.
    2. Next lets iterate the len from 2 to n-1. [From 2 because, to move digonal we need to move from 2 onwards.]
       - define col as len as from here we will start filling the boxes.
       - Next loop for row from 0 to n-len. [This make sure we fill only the dig boxes starting from dp[row][len]]
         - Initialize the dp[row][col] as max value i.e INT_MAX
         - Run a Fow loop k from row+1 to col [This gives all possiblities]
         - dp[row][col] is min of dp[row][col] and (dp[row][k] + dp[k][col] + arr[row]*a[k]*a[col])
    a[0][n-1] will holds the mini Operation needed.
*/