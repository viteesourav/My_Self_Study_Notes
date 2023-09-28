// Link: https://leetcode.com/problems/longest-common-prefix/description/
/*
You given a list of strings, You need to find the longest prefix they all have in common
*/
// creating a TrieNode and a Trie class... TC: O(nl) SC:O(l) [Not an optimal Solution, but works]

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char ch;
    TrieNode *alphaList[26]; // Stores address of other possible characters..
    bool isTerminalNode;     // A flag to denote the end of each word.
    int childCount = 0;

    // constructor: All address of Other Nodes should be NULL, and flag is false
    TrieNode(char ch)
    {
        this->ch = ch;
        for (int i = 0; i < 26; i++)
            alphaList[i] = NULL;
        isTerminalNode = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0'); // initializing Trie Root Node with Escape char..
    }

    // Insertion in Trie [uses Recursion]
    void insertUtil(TrieNode *currNode, string word)
    {
        // baseCase:
        if (word.length() == 0)
        {
            currNode->isTerminalNode = true;
            return;
        }

        int index = word[0] - 'a'; // index of the char..

        // If char exist in the list, move there else, create a new one and then move there..
        if (currNode->alphaList[index] == NULL)
        {
            TrieNode *newNode = new TrieNode(word[0]);
            currNode->alphaList[index] = newNode;
            currNode->childCount++;
        }

        currNode = currNode->alphaList[index];

        // call Recursion to insert other chars of the word into Trie..
        insertUtil(currNode, word.substr(1));
    }

    // Insert Word in the Trie...
    void insertInTrie(string word)
    {
        insertUtil(root, word);
    }

    // Now Insertion of all Words in Tries Done, lets find the common prefix..
    // Method to return the longestPrefix...
    string findLongestPrefix(string firstWord)
    {
        string ans = "";

        // traverse the first word...
        for (int i = 0; i < firstWord.length(); i++)
        {
            // take the char..
            char ch = firstWord[i];

            // Now check of the child count is 1 or not for this rootNOde..
            if (root->childCount == 1 && !root->isTerminalNode) // The second condition is to check if any word ends at the currNode, then break it.
            {
                ans.push_back(ch);                // push the char in the ans...
                root = root->alphaList[ch - 'a']; // Move the root to the child Node...
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

class Solution
{
private:
    // Appraoch1: we are for loop Appraoch: TC:O(nl) SC:O(1)
    string solve1(vector<string> &arr)
    {
        string ans = "";

        // check if we have less than 1 string in the arr..
        if (arr.size() < 2)
            return arr[0];

        // take out the first element from the arr..
        string fWord = arr[0];

        // iterate the first word char wise...
        for (int i = 0; i < fWord.size(); i++)
        {
            int flag = true; // a flag to indeticate if all ith char are same or not ?
            for (int index = 1; index < arr.size(); index++)
            {
                if (arr[index][i] != fWord[i])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                ans.push_back(fWord[i]);
            else
                break;
        }
        return ans;
    }

    // Appraoch2: This uses Tries to store all the inputs..
    string solve2(vector<string> &arr)
    {

        Trie *wordTrie = new Trie(); // initialize the trie object..

        // First insert all the words in the Trie..
        for (int i = 0; i < arr.size(); i++)
        {
            wordTrie->insertInTrie(arr[i]);
        }

        string firstWord = arr[0];

        // Now find the longest Prefix...
        return wordTrie->findLongestPrefix(firstWord);
    }

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // return solve1(strs);
        return solve2(strs);
    }
};

/*
Approach:
    1) use simple loop TC: O(nl) SC: O(1)
        -- Take the first word
        -- Now iterate the letters of the first word and the rest of the words, till you find a different match.
        -- If a letter comes in all the words, Push it to ans.
    return ans
    [**DONE**]

    2) use Trie: TC:(nl) SC:O(l) [Takes more space, not ideal approach]
        -- implement a trie.
        -- insert all the words inside it.
        -- traverse char from the first word of the arr using the Root pointer. [Insert all the char who have exactly 1 Node Linked to it]
        -- NOTE: additional check added:
            1) check if the Node has only 1 child.
            2) check if the Node is not a terminal Node. [As if the currNode is a terminal Node i.e a word is ending there, thus break it, No point in checking further]
        -- As you find more, break and come out.
    [**DONE**]
*/