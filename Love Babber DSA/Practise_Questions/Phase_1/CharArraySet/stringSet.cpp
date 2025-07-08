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

// Approach 2 -> One freqMap for s1 use as refernce.

bool isPermuation1(string word, int freqMap[])
{
    int temp[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        temp[i] = freqMap[i];
    }

    // update the freqMap with a decrement counter..
    for (int i = 0; i < word.length(); i++)
    {
        temp[word[i] - 'a']--;
    }

    // NOTE: if word is a permutation -> all freq must reduce to zeroes..
    //  eg: "ab" and "ba" will have the same freq.
    for (int i = 0; i < 26; i++)
    {
        if (temp[i] != 0)
            return false;
    }
    return true;
}

bool checkInclusion1(string s1, string s2)
{
    // edge case if, s1 is longer than s2 --> no chance..
    if (s1.length() > s2.length())
        return false;

    // 1. create a charfreq map for s1...
    int charFreq1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        charFreq1[s1[i] - 'a']++;
    }

    // 2. start taking substring of len s1 from s2 and check their freq map..
    int i = 0;
    while (i <= s2.length() - s1.length())
    {
        string subword = s2.substr(i, s1.length());
        if (isPermuation1(subword, charFreq1))
        {
            return true;
        }
        i++;
    }
    return false;
}

/*
    Logic: [another aaproach] --> s2 premutations in s1.
    -> edgecase -> s2 must be <= s1 to procced.
    -> create the freqMap for s2.
    -> loop over s1 ->
        -> find words of substr of size s2. -> subword.
        -> now pass to a checkmethod with subword and freqMap.
        -> In checkmethod --> iterate over the subword and make freqMap for char in decrement.
        eg: "ab" -> in freq map will have a->1, b->1.
            if "ba" or "ab" appeard --> in the freq map it will make a->0 and b->0 [as we are decrementing]
        -> at the end check if all ele inside freq Map 0 or not ?
           -> if yes, subword is a premuation of s2 present in s1.
           -> if no, then it is not.

*/

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