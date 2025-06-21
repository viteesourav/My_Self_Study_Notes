// Link: https://leetcode.com/problems/valid-anagram/description/
/*
Problem:
    check if given two strings are anagram ? --> they must have the same charcters..
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        // lets use the static char freq table...
        vector<int> freq(26, 0);

        // iterate the first string and update the freq table...
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        // iterate the second string and update the freq table...
        for (int i = 0; i < t.length(); i++)
        {
            freq[t[i] - 'a']--;
        }

        // Now, Iterate the freq, and check if for index, if it's < 0
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};