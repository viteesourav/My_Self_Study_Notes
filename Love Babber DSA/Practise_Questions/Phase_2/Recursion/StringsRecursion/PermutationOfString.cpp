/*[V.Important Question]
Find All permutation of the Strings.
abc -> abc, acb, bac, bca, cab, cba.  Total Permutation: n! where n is the len of String.

Another Varaition:
Find all the Permutations of the given array.
--> Same logic.
*/

#include <bits/stdc++.h>
using namespace std;
// This is a Recursion call with Backtracking implemented...
void solve(string &str, vector<string> &ans, int index)
{

    // baseCase...
    if (index >= str.length()) // If index exceeds the len of String.
    {
        ans.push_back(str); // store the update str value in ans.
        return;
    }

    // a loop to iterate from index pos till end of Str
    for (int i = index; i < str.length(); i++)
    {
        // swaping the ith char with index char
        swap(str[index], str[i]);
        // now call the recursive function with the next index value
        solve(str, ans, index + 1);
        // now while Returning you update the str to original str before swaping [backtracking]
        swap(str[index], str[i]);
    }
}

vector<string> generatePermutations(string &str)
{
    // we will use Recursion logic here to solve this....
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    sort(ans.begin(), ans.end()); // lexicograpgical order
    return ans;
}

/*

abc -> _ _ _

Logic:
    -- So you have the string, and index that points to the start and then the ans Vector.
    -- Now For the first place, we can fill that place with 3 options, either a or b or c i.e  a _ _ or b _ _ or c _ _
    -- For the next place, we can fill with the left to charactres.
    Consider for the case, a _ _ , second last place can be filled with b or c. i,e  a b _ or a c _
    -- This is acheived using Recursion.

Approach:
    -- Each stage, you basically swap all the chars with the all char infront of char at index.
    -- For each a Recursive call is triggered. to Solve furthure down.
    -- After the recursion call part, we are converting the string back to how it was, Thus swaping the char at ith and index again. [backtracking]

NOTE: draw Recursion tree following the logic to get a better understanding.
-- Also, At the end back-tracking is also used to return to the noramlcase while moving up the tree.

*/