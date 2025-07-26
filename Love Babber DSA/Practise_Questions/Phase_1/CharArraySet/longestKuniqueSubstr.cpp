/*
 https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

 Problem: [** Medium **]
    You are given a string s consisting only lowercase alphabets and an integer k.
    Your task is to find the length of the longest substring that contains exactly k distinct characters.  if no substring exits -> return -1.
*/
#include <bits/stdc++.h>;
using namespace std;

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        int ans = INT_MIN;

        // need a set to track distinct element, and map to track the freq.
        unordered_set<char> track;
        vector<int> charMap(26, 0);

        int l = 0, r = 0;

        while (r < s.length())
        {
            // inset in set till we have k distinct elements...
            track.insert(s[r]);
            charMap[s[r] - 'a']++;

            if (track.size() == k)
            {
                ans = max(ans, r - l + 1);
            }

            // do it till the set has more distinct elements than k...
            while (track.size() > k)
            {

                charMap[s[l] - 'a']--; // remove from visited freq map..

                // check if any visited char freq becomes zero, we need to remove that from set..
                for (int i = 0; i < 26; i++)
                {
                    if (charMap[i] == 0 && track.count('a' + i))
                    {
                        track.erase('a' + i);
                    }
                }
                l++;
            }

            r++;
        }

        return ans == INT_MIN ? -1 : ans;
    }
};

/*
Logic and dry run:

  k -> 3

          l
  a a b a c b e b e b e
                      r

  set ->  b , c, e
  map ->
    a -> 0
    b -> 3
    c -> 1
    e -> 3

Steps:
    1. have an set -> track the distinct elements as you move from left to right.
       have an charSet -> track the freq of those elements.
    2. While moving:
        1. If the set size == k i.e you have exactly k distinct elements in range Left, right
            -> calculate the max length of the window.
        2. While we have the size of set > k
            -> you remove the left element from the map.
            -> Watch the map -> If there exist a key whose freq is 0 but it exist on set ---> remove it from set.
            -> move the right point.
    3. retuen the ans.

*/