// Link: https://www.codingninjas.com/studio/problems/implement-a-phone-directory_1062666?leftPanelTab=0
/*
Bascially, You have Given a couple of words. You need to implement dynamic search.
    Dynamic search -> as you type the word to search, For each char you type it should show all the suggestions.
*/
#include <bits/stdc++.h>
using namespace std;

// Defines the structure of each Node in the Trie...
class TrieNode
{
public:
    char ch;
    TrieNode *arr[26];
    bool isTerminalNode;
    int childCount;

    TrieNode(char ch)
    {
        this->ch = ch;
        for (int i = 0; i < 26; i++)
            arr[i] = NULL;
        isTerminalNode = false;
        childCount = 0;
    }
};

// Tri class to handle the operations on Trie...
class Trie
{
    TrieNode *root;

public:
    // Constructor for initialize root Node with '\0' character
    Trie()
    {
        root = new TrieNode('\0');
    }

    // Handle insertion in Trie...[Recursion]
    void insertUtil(TrieNode *currNode, string word)
    {
        // baseCase:
        if (word.length() == 0)
        {
            currNode->isTerminalNode = true;
            return;
        }

        // Find the index of the first char of the word..
        int charIndex = word[0] - 'a';

        // check if currNode holds thats char or not ?
        if (currNode->arr[charIndex] == NULL)
        {
            currNode->arr[charIndex] = new TrieNode(word[0]); // create a new TrieNode with the char.
            currNode->childCount++;
        }

        // Move the currNode to the firstChar Node and call Recursion..
        currNode = currNode->arr[charIndex];
        insertUtil(currNode, word.substr(1)); // Recursion call to process other char of the word.
    }

    // Insert in the Trie...
    void insertInTrie(string word)
    {
        insertUtil(root, word);
    }

    // Method to find all possible words from root Node...
    // Using Recursion...
    void findAllWords(TrieNode *currNode, vector<string> &searchRes, string &prefixWord)
    {
        // baseCase:
        // Check if it's terminal Node ? Append to searched word result
        if (currNode->isTerminalNode)
        {
            searchRes.push_back(prefixWord);
            if (currNode->childCount == 0)
            { // check if no furthur child exist, return back..
                return;
            }
        }

        // Let's iterate all the char List for the currNode...
        for (int i = 0; i < 26; i++)
        {
            if (currNode->arr[i] != NULL)
            {
                prefixWord.push_back(currNode->arr[i]->ch);
                findAllWords(currNode->arr[i], searchRes, prefixWord);
                prefixWord.pop_back();
            }
        }
    }

    // Method to handle the searching based on WordPrefix..
    void findAllSuggestion(vector<vector<string>> &ans, string queryStr)
    {
        string prefixWord;
        TrieNode *prevNode;
        TrieNode *currNode = root;
        for (int i = 0; i < queryStr.length(); i++)
        {
            vector<string> suggestionList;
            prefixWord.push_back(queryStr[i]);

            int charIndex = queryStr[i] - 'a'; // Fetching the character index...

            // check if the root contains the prefix char ?
            if (currNode->arr[charIndex] != NULL)
            {
                prevNode = currNode;
                currNode = prevNode->arr[charIndex];
                findAllWords(currNode, suggestionList, prefixWord);
            }
            else
            {
                break;
            }
            ans.push_back(suggestionList);
        }
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    vector<vector<string>> ans;

    Trie *t = new Trie(); // Created a Trie with root as '\0'

    // Step1: Let insert all the words in the Trie...
    for (int i = 0; i < contactList.size(); i++)
    {
        t->insertInTrie(contactList[i]);
    }

    // Step2: Iterate the search query one by one...
    t->findAllSuggestion(ans, queryStr);

    return ans;
}

/*
Approach: using Trie [as word Dictionary] TC: O(m*n*m) SC: O(m*n) [m is the average length of Word, n is total no of words]
    -- Trie Implementation:
        -- Create a class for each Node in the Trie, includes ch, array pointer for all chars, isTerminalNode, childCount.
        -- Create a Trie Class to initialize a Trie with root as '\0'
    -- Step1: Insert all the words in the Trie.
    -- Step2:
        -- You have queryStr, take the char one by one.
        -- Maintain a Prev and curr Node Pointer to traverse the Trie.
        -- For a Node that matchs the char, Find all the possible words from that Node [Travese all Nodes till isTerminal is true]
        -- when we reach isTerminalNode-> true, insert the word in the record.
    -- Do this for all the chars for the queryStr.
*/