#include <bits/stdc++.h>
using namespace std;

// removing substring from a string....
string removeOccurrences(string s, string part)
{
    // method1: using substr and compare method.
    //  int i=0;
    //  while(i<s.length()) {
    //      // cout<<s.substr(i, part.length())<<endl;
    //      if(s.substr(i, part.length()).compare(part) == 0) {
    //          s.erase(i, part.length());
    //          i=0;
    //      }else i++;
    //  }

    // method 2: using find method
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

bool compareOccurance(string s2, int start, int end, int count[])
{
    // here i need to loop over the window and check if the freq mach with count table.
    int temp[26];
    for (int i = 0; i < 26; i++)
        temp[i] = count[i];
    cout << start << " " << end << endl;
    for (int i = start; i < end; i++)
    {
        if (temp[s2[i] - 'a'] == 0)
            return false; // if the char is not atall visted.
        else
            temp[s2[i] - 'a']--; // To avoid comparision of the same char again, mark the visit
    }
    return true; // If all the char match i.e line 6 never ran. Thus pemutation detected.
}

// Finding if the permutation of s1 is present in s2
bool checkInclusion(string s1, string s2)
{

    if (s1.length() > s2.length())
        return false;
    // we will use the flat freq table approach.
    int count[26] = {0};
    // lets create the freq table for the s1
    for (int i = 0; i < s1.length(); i++)
        count[s1[i] - 'a']++;

    int i = 0;
    int windowSize = s1.length();
    while (i <= s2.length() - s1.length())
    {
        if (compareOccurance(s2, i, (i + windowSize), count))
            return true;
        i++;
    }
    return false;
}

// VEry Very Important Question: (String compression)
int compress(vector<char> &chars)
{

    // declaring the indexes we need.
    int n = chars.size();
    int i = 0;
    int ansIndex = 0; // we will store the result in the same array.

    // start a loop with i and j=i+1
    while (i < n)
    {
        int j = i + 1;
        // check for continuos set of chars
        while (j < n && chars[i] == chars[j])
            j++;

        chars[ansIndex++] = chars[i];
        int count = j - i; // This many times char[i] was continuos.
        if (count > 1)
        {
            // we need to push the digit inside.
            string num = to_string(count);
            for (char ch : num)
                chars[ansIndex++] = ch;
        }
        i = j; // New char begins from index j
    }
    return ansIndex; // returning the new length.
}