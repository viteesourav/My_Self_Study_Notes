/* This is Another Approach for the Problem:
Find All possible Subsequences of a given String..
abc -> {}, a, b, c, ab, bc, ac, abc.  Total Subsequences: 2^n
*/

#include <bits/stdc++.h>
using namespace std;

// This is finding all the possible subsets using bits logic...
void findAllSubset(string str)
{

    int len = str.length();
    int totalPowerSet = pow(2, len);

    // Now we will iterate through all the Powerset and form the subsets...
    for (int powerset = 0; powerset < totalPowerSet; powerset++)
    {
        string output;
        // for each powerset we will iterate the given str and match with its bit..
        for (int index = 0; index < str.length(); index++)
        {
            if (powerset & (1 << index))
                output.push_back(str[index]);
        }
        cout << output << endl;
    }
}

int main()
{
    string str = "abc";
    findAllSubset(str);
    cout << "Finding subsets using bits Manipulation.";
    return 0;
}

/*

Logic:


  arr = a  b  c

powerSet = 2^3 = 8

cnt  bits  arr
0 - 000 - {}
1 - 001 - c
2 - 010 - b
3 - 011 - bc
4 - 100 - a
5 - 101 - ac
6 - 110 - ab
7 - 111 - abc

Logic to compare is:

Basically each bit's 1 represent that bit index is included and 0 represent that index is not included.
--> Logic to get the index.
if cnt & 1<<index -->
 cnt -> 2 -> 010
 index -> 0, 1<<0 -> 001,  010 & 001 -> 000, nothing selected
index -> 1, 1<<1 -> 010, 010 & 010 -> 010, 2nd index selected.
index -> 2, 1<<2 -> 100, 010 & 100 -> 000, nothing is selected.
and so on.
--> In a count, Whenever something is selected, add that to output String.

*/