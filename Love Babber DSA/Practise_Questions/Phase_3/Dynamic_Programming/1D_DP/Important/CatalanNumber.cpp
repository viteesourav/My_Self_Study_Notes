/*
You Need to Find the Nth Catalan Number from the catalan Number Series.

Cn -> C0Cn-1 + C1Cn-2 + C2Cn-3 + C3Cn-4 + ....... + Cn-1C0
                       0 1 2 3  4  5  6
Catalan Number Series: 1 1 2 5 14 42 132 ..........

NOTE: One will go from 0 to n-1 and the other one will from n-1 to 0. Each Represents the number of choices.
        i.e C3 = C0C2       +   C1C1     +     C2C0
                [0 choices.    [1 Choice       [2 choices.
                 2 Choices]      1Choice ]        0 Choices]
*/

// Implementation of Catalan Numbers...
#include <bits/stdc++.h>
using namespace std;

// Appraoch: Recusive Solution...[Loop + Recursion]
// eg: C3 = C0C2 + C1C1 + C2C0
int solve1(int n)
{
    // baseCase:
    if (n == 0 || n == 1)
        return 1; // as C0 and C1 is 1

    int total = 0;

    // Loop n times..
    for (int i = 0; i < n; i++)
    {
        total += solve1(i) * solve1(n - 1 - i); // Recusion will fetch other catalan Value
    }

    return total;
}

// Appraoch2: Optimizing it, Using Recursion + Memorization [Top-Down Appraoch]
int solve2(int n, vector<int> &dp)
{
    // baseCase:
    if (n == 0 || n == 1)
    {
        dp[n] = 1;
        return dp[n];
    }

    // Check if dp already has ans for dp[n] ?
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int total = 0; // holds the total..

    // Loop n times..
    for (int i = 0; i < n; i++)
    {
        total += solve2(i, dp) * solve2(n - 1 - i, dp); // Recusion will fetch other catalan Value
    }

    dp[n] = total;

    return dp[n];
}

// Approach3: No Recursion, Use Matrix Space...
int solve3(int n)
{

    // 0. Handle the base Cases...
    if (n == 0 || n == 1)
        return 1;

    // 1. initialize Matrix of n x n with all 1's... [NOTE: dp[n-1][n-1] will hold Cn's Value ]
    vector<vector<int>> dp(n, vector<int>(n, 1)); // dp matrix of size n x n

    // 2. Start the loop from column wise...
    for (int col = 1; col < n; col++)
    {
        for (int row = col; row < n; row++)
        { // Row starting from the cols
            // case when both row and col are same..
            if (row == col)
            {
                dp[row][col] = dp[row - 1][col - 1] + dp[row][col - 1]; // sum of the left-top and left value.
            }
            else
            {
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1]; // Sum of top and left value.
            }
        }
    }

    return dp[n - 1][n - 1]; // This holds the value for the catalan Number.
}

// Approch: Space Optimization [No Need For Matix, Just use 2 vector] [*** IMP ***]
// Notice: dp[row][col] depends upon previous row and current Row..
// NOTE: replace dp[row] with curr Vector and dp[row-1] with prev Vector [Rest Logic is same]
int solve4(int n)
{
    // 0. Handle the base Cases...
    if (n == 0 || n == 1)
        return 1;

    // 1.Declare the prev and current vector for size n..
    vector<int> prev(n, 0);
    vector<int> curr(n, 0);

    // as per baseCase: update prev[0] and prev[1] and curr[0]
    prev[0] = prev[1] = curr[0] = 1;

    // Iterate the rows...
    for (int i = 1; i < n; i++)
    {
        for (int col = 1; col < n; col++)
        { // Fill the columns...
            // If the col and row index MAtch -> sum previous col's curr and prev
            if (i == col)
            {
                curr[col] = prev[col - 1] + curr[col - 1];
                break;
            }
            else
            {
                curr[col] = prev[col] + curr[col - 1];
            }
        }

        // update the prev to curr Row...
        prev = curr;
    }

    return curr[n - 1];
}

int main()
{

    int n;

    cout << "Enter the Number: ";
    cin >> n;

    // int res = solve1(n); //Recursive...

    // Recursion + Memorization...
    //  vector<int> dp(n+1, -1); //n+1 as i need to access the nth index.
    //  int res = solve2(n, dp);

    // //View the Content of the dp...[Prints all Catalan Numbers from 0 to n]
    // for(auto it: dp) {
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    // Matrix logic [No REcursion]
    //  int res = solve3(n);

    // No Matrix logic [using 2 Vector, Space Optimized]
    int res = solve4(n);

    cout << "Catalan( " << n << " ): " << res;
    return 0;
}

/*
Implementation:
    1) Noraml Recursive Manner. [Exponentail Time Complexity]
        -- baseCase: If n is 1 or 0, C0 and C1 is 1 so return 1
        -- for Finding Cn:
            -- Run a For Loop n times.
            -- REcursion will fetch me the catalan Number for other valuse of n.
        -- return total.

    2) Recursion with Memorization [Top-Down Approach]
        -- use dp to store the result of Recursion.
        -- before Loop, check if dp holds the Result or not ?

    3) Using Matrix Space. [No REcursion]
        -- We use a matrix: nxn, initialize with all with 1.
        -- we start proccessing,
            sum at i,j will be, Sum of all the values in the in i-1th row till jth col.
            -- In code this can be done using 2 nested for loop, col wise.
        -- The Digonal will hold the value of all catalan Numbers.

    4) Space Optimization [SC: O(N), No Matrix Needed] [*** Optimized Approach ***]
        -- Notice, we just need the previous row and current Row.
        -- So Remove the matrix and maintain 2 vectors of size n.
        -- Little bit, Logic will change,
           --> 2 Cases:
                if

Approach using Catalan Number in Questions: [Link: https://www.youtube.com/watch?v=0pTN0qzpt-Y]

    Logic: Take the Question, Put Arrangement for sample inputs, by either placing inside or outside.
        -- If the values are similar to catlan number pattern, than the this code can be used.

    1) No of Possible BSTs based on number of Nodes. -> Cn
        -- Given number of Nodes. How many arrangment of BSTs can be there ?
        -- 1 Node -> only 1 Arrangment is possible.
           2 Nodes -> A and B -> 2 Arrangments are possible.
           3 Nodes -> A, B and C -> 5 Arrangments are possible.
            A -> BC [B and C are on the left side as B &C < A can be arranged in 2 ways i.e C2] i.e C0C2
            A <- B -> C [This is one arrangment on either side]  i.e C1C1
            C -> AB [A and B are on the right side as A &B > C can be arranged in 2 ways i.e C2] i.e C2C0
        so Possible ways: C0C2 + C1C1 + C2C0 -> C3 i.e Cn

    2) No of ways of Arranging valid N-parenthesis based on given set of Parenthesis. -> Cn
        -- You given N sets of Paranethesis, How many ways you can arrange it ?
           [Something you might have Alphabets included, ignore them they are just to confuse]

        -- 1 set is given -> 1 way ()
           2 set is given -> ()
            - 2 ways, 1. Either you put 1 inside and 0 outside -> C1C0
                       2. Wither you put 0 inside and 1 outside -> C0C1
           3 Set is given -> ()
            - 3 ways, 1. Either you put 0 inside and 2 outside -> C0C2
                      2. Either you put 1 inside and 1 outside -> C1C1
                      3. Eitehr you put 2 inside and 0 outside -> C2C0
        so Possible ways: C1C2 + C1C1 + C2C1 -> C3 i.e Cn

    3) Mountain Ranges [Possible ways to Arrange Mountains to stay above ground/sea-level] -> Cn
        -- You given upHills and downHills, How many possible way you can make a mountain to stay above ground.
        -- This question is same as PArenthisis question. Same logic, Inside of open bracket use upHill and closed bracket use down hill.

    4) Number of convex Polygon. -> Cn-2 [**VIMP**]
        -- You given a N sided polygon. Find out how mnay Triangles can we form inside it.
        -- Take Cases: Min sides we need for a polygon is 3.
            For 3 sides -> Only 1 triangle possible and it is itself.
            For 4 sides -> 2 triangles are possible. -> C0C1 + C1C0 i.e C2
            For 5 sides -> 3 ways possbile -> C0C2 + C1C1 + C2C0 i.e C3
        so, The Number of possble Convexes or Triangle inside a Polygon is given by Cn-2 wher n is the number of sides.




*/