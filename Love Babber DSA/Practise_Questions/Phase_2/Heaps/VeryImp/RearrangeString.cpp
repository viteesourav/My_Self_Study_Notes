// Link: https://leetcode.com/problems/reorganize-string/description/
/*
You Given a String, You need to Return a new String such that no 2 adjacent Charater are same.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Appraoch: char freq + maxHeap..
    string reorganizeString(string s)
    {

        string ans = "";
        // lets first store the freq of each char in the string....
        vector<int> strFreq(26, 0); // A vector, with all 26 elements initialize to 0

        // iterating the given string...
        for (int i = 0; i < s.size(); i++)
        {
            strFreq[s[i] - 'a']++; // s[i]-'a' gets the index of a char..
            // check for edge case...
            if (strFreq[s[i] - 'a'] > (s.size() + 1) / 2) // If any freq exceed the limit, return empty str...
                return "";
        }

        // Now we have the freq of each character, lets push in the maxheap...
        priority_queue<pair<int, char>> max_heap;

        // Lets push pairs in max_heap, Element pattern: <frequency, character>
        for (int i = 0; i < strFreq.size(); i++)
        {
            // push in heap only if the freq is present...
            if (strFreq[i] != 0)
                max_heap.push(make_pair(strFreq[i], ('a' + i))); //'a' + i -> the char at index 'i'
        }

        // Lets process till the heap has 1 element left...
        while (max_heap.size() > 1)
        {
            // Take out top 2 elements from the heap and pop them resp...
            pair<int, char> ele1 = max_heap.top();
            max_heap.pop();
            pair<int, char> ele2 = max_heap.top();
            max_heap.pop();

            cout << "###1: " << ele1.first << " " << ele1.second << endl;
            cout << "###2: " << ele2.first << " " << ele2.second << endl;

            // Now lets add the top 2 ele to ans and reduce the freq...
            ans.push_back(ele1.second);
            ele1.first--;
            ans.push_back(ele2.second);
            ele2.first--;

            // Push the element back inside the queue if the freq > 1...
            if (ele1.first > 0)
                max_heap.push(ele1);
            if (ele2.first > 0)
                max_heap.push(ele2);
        }

        // Add the left out element in heap to ans...
        while (!max_heap.empty())
        {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return ans;
    }
};

/*
Logic:
    -- WE need to take the max 2 characters everyTime and put them together. and repeat this
    -- If any char freq exceeds (n+1)/2 then it's not possible to Rearrange them to avoid adjacent similar characters.

Appraoch: TC: O(nlogn) [Iterating all elements and pushing in the heap], SC: O(n) [A Heap we are using]
    -- Lets First take the freq of each character from the string.
    -- Now since the alpha range is from 0 to 26. we can map it using vector and just simply iterating the given string.
    -- While freq calculation, if any char exceeds the limit [freq > n+1/2], REarrangement is not possible.
    -- After mapping is done,
        -- Consider a maxHeap and push the character and it's frequency as pair in maxHeap.
    -- Run till The heap's size > 1,
        -- Everytime, take the 2 top element and append to ans String..
        -- Decrement the freq and push it back to maxHeap.
    -- At the end, Whatever left in the heap
        -- Push the Element in the ans String.
    [**DONE**]
*/