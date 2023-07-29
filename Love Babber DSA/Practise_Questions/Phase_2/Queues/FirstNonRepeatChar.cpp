// Link: https://www.codingninjas.com/studio/problems/first-unique-character-in-a-string_893404?leftPanelTab=0
/*
First Non-Repeating Char in Stream
Basically, As we add char to the stream, for left side see which is the first char that is unique. Add that char to the output.
examples :
a a b c   ->  a b b
b b a b c b c a b  -> b a a a a a
b a b -> b b a
*/

#include <bits/stdc++.h>
using namespace std;

vector<char> firstNonRepeating(string stream)
{
    vector<char> ans;
    // Approach: WE will use one freqMap and one Queue to solve this problem...
    unordered_map<char, int> freqMap;
    queue<char> q;

    // Now we will traverse the given stream...
    for (int i = 0; i < stream.size(); i++)
    {

        // lets update the freqMap as we read a new char...
        freqMap[stream[i]]++;

        // lets push the char into the queue...
        q.push(stream[i]);

        // now use a loop, till the queue is not empty...
        while (!q.empty())
        {
            // check if the char at front is repeating ?
            if (freqMap[q.front()] > 1)
                q.pop();
            else
            {
                // If the char is not repeating...
                ans.push_back(q.front()); // store the non-repeating in the ans.
                break;
            }
        }
    }
    return ans;
}

/*
Appraoch: (freqMap + Queue)

Steps:
    -- First make a freqmap for the incoming chars.
    -- Push the char inside the qeueue.
    -- Run a loop till, the queue is empty OR you find a char which is not repeating...
       -- Push the non-repeating char inside the ans.
    *DONE*
*/