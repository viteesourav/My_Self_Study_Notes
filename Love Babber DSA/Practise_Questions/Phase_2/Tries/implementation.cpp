// This Code shows Insertion, Searching and Deletion Operations in a Trie [Efficent Dictionary Implementation]
// NOTE: Here we are handling only lower_case Characters..
// Link: https://www.codingninjas.com/studio/problems/implement-trie_631356
#include <bits/stdc++.h>
using namespace std;

// Structure of Each Node in a Trie...
class TrieNode
{
public:
    char ch;             // Holds the char of the Node..
    TrieNode *arr[26];   // As only 26 alpha we can store...
    bool isTerminalNode; // States if the currNode is a Terminal Node or not ?

    // constructor, we store the current Char, set the arr with all NULL Nodes, and is not a terminal Node by defualt.
    TrieNode(char ch)
    {
        this->ch = ch;
        for (int i = 0; i < 26; i++)
            arr[i] = NULL;
        isTerminalNode = false;
    }
};

// A Seperate class to handle Operations related to Tries..
class Trie
{
public:
    TrieNode *root;

    // Constructor, to start with a root Node having a '\0'...
    Trie()
    {
        root = new TrieNode('\0'); // Creating a Root Node with `\0`
    }

    // Insertion in Trie [Recursion] TC: O(length of the word) [As we will visit all Nodes atleast one]
    void insertUtil(TrieNode *currNode, string word)
    {
        // baseCase: If word we all processed, make the lastNode as TerminalNode and return
        if (word.length() == 0)
        {
            currNode->isTerminalNode = true;
            return;
        }

        // check the index of the first char of word and if its exist or not ?
        int index = word[0] - 'a'; // This gives the index...

        if (currNode->arr[index] == NULL)
        {
            // If the char doesn't exist, create a new Node...
            currNode->arr[index] = new TrieNode(word[0]);
        }

        // update the currNode to the next Node...
        currNode = currNode->arr[index];

        // Recursion will take care of adding other characters....
        insertUtil(currNode, word.substr(1)); // Passes the updated currNode and subString of word from next index...
    }

    // Trie Insert Method, pass the word to insert to Trie Insert Util along with the root Node...
    void insertInTrie(string word)
    {
        insertUtil(root, word);
    }

    // Searching in Trie [Recursion] [Same as insertUtil Function]
    bool searchUtil(TrieNode *currNode, string word)
    {
        // baseCase:
        if (word.length() == 0)
        {
            return currNode->isTerminalNode; // If we searched the whole word, We need to check if the last Node is terminal or not.
        }

        // check the index if the first Char of the word..
        int index = word[0] - 'a';

        // check if at arr[index], that the node exist ? If not exist simply break false..
        if (currNode->arr[index] == NULL)
        {
            return false; // If at arr[index] No entry present...
        }

        // Move the currNode to the next Node and call Recusrion...
        currNode = currNode->arr[index];

        return searchUtil(currNode, word.substr(1)); // Passes the updated currNode and subString of word from next index...
    }

    // Trie search Method...
    bool searchInTrie(string word)
    {
        return searchUtil(root, word);
    }

    // Delete in Trie [Recusrion Approach] TC: O(length of the word)
    void deleteUtil(TrieNode *currNode, string word)
    {
        // basecase:
        if (word.length() == 0)
        { // If you reach the last char of the word, make isTerminal false and return..
            currNode->isTerminalNode = false;
            return;
        }

        // get the index of the first char of the word...
        int index = word[0] - 'a';

        // check of anything exist at that index..
        if (currNode->arr[index] != NULL)
        {
            currNode = currNode->arr[index]; // Move to the node for that character..
        }
        else
        {
            return; // IF char doesn't exist return back...
        }

        // use Recursion to Travel to other char of the word..
        deleteUtil(currNode, word.substr(1)); // Removed the processed char from the word.

        // Now while returning back...
        // check if the currNode has any other char it is pointing...
        int i = 0;
        while (i < 26 && currNode->arr[i] != NULL)
        {
            i++;
        }

        // we traverse the whole char arr, and found no other pointer to any char, we can remove the node...
        if (i == 26)
        {
            delete currNode;
        }
    }

    // Trie Delete Method...
    void deleteInTrie(string word)
    {
        deleteUtil(root, word);
    }

    // StartsWith in Trie [Recursion Appraoch] TC: O(word's length)
    bool startsWithUtil(TrieNode *currNode, string prefix)
    {
        // basecase:
        if (prefix.length() == 0)
        { // If we searched the whole word, return true...
            return true;
        }

        // get the index of the first char of the word...
        int index = prefix[0] - 'a';

        // check of anything exist at that index..
        if (currNode->arr[index] != NULL)
        {
            currNode = currNode->arr[index]; // Move to the node for that character..
        }
        else
        {
            return false; // IF char doesn't exist return false...
        }

        // use Recursion to Travel to other char of the word..
        return startsWithUtil(currNode, prefix.substr(1)); // Removed the processed char from the word.
    }

    // StartsWith Method...
    bool startsWith(string prefix)
    {
        return startsWithUtil(root, prefix);
    }
};

int main()
{
    // Additional Info: How to convert a string to lowercase...............
    //  string str = "SOURAV";
    //  transform(str.begin(), str.end(), str.begin(), ::tolower); //sourav
    //  cout<<str<<endl;

    Trie *t = new Trie();

    t->insertInTrie("bike");
    t->insertInTrie("take");
    t->insertInTrie("car");
    t->insertInTrie("cat");

    cout << "Insertion Completed" << endl;

    cout << "########Searching in Trie" << endl;
    cout << "Check if bike there ? " << t->searchInTrie("bike") << endl;     // Should return 1 [as boot is present]
    cout << "Check if sourav there ? " << t->searchInTrie("sourav") << endl; // should return 0 [as sourav is not present]
    cout << "Check if bik there ? " << t->searchInTrie("bik") << endl;       // should return 0 [as bik is a substr of bike]

    cout << "Check if take there ? " << t->searchInTrie("take") << endl;
    cout << "Check if care there ? " << t->searchInTrie("care") << endl;

    cout << "########Implementing Deletion in trie" << endl;
    cout << "Check if cat there, ##BeforeDeletion ? " << t->searchInTrie("cat") << endl;
    t->deleteInTrie("cat");
    cout << "Check if cat there, ##AfterDeletion ? " << t->searchInTrie("cat") << endl;
    cout << "Check if car there, ##AfterDeletion ? " << t->searchInTrie("car") << endl;

    cout << "##########Implemeting Starts with" << endl;
    cout << "Check if any word exist that starts with ca ? " << t->startsWith("ca") << endl;

    return 0;
}