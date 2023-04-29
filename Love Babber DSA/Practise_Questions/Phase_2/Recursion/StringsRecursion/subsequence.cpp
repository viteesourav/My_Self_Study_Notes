// Find all Subsequences of the strings...
#include <bits/stdc++.h>
using namespace std;

// This is an recursive function...
void findAllSequence(string str, string outputStr, int index, vector<string> &ans)
{

    // base condition.. till index reaches the end of string..
    if (index >= str.length())
    {
        // add the outputStr to ans only if outputStr is not empty.
        if (outputStr.length() > 0)
            ans.push_back(outputStr); // Store the outputStr in the ans array.
        return;
    }

    // excluiding the character at index.
    findAllSequence(str, outputStr, index + 1, ans);

    // including the character at index
    // need to add the char at index to outputStr.
    outputStr.push_back(str[index]);
    // calling the included part of the recursion..
    findAllSequence(str, outputStr, index + 1, ans);
}

vector<string> subsequences(string str)
{

    // we will try to solve this problem using recurssion...
    vector<string> ans;
    string outputStr;
    findAllSequence(str, outputStr, 0, ans);
    return ans;
}

/*
Example:

Given String: abc

All possible subsequences of abc are :
“a” , “b” , “c” , “ab” , “bc” , “ac”, “abc”

Logic used: using Recursion and Char by char including and excluding at each stage..

*/
