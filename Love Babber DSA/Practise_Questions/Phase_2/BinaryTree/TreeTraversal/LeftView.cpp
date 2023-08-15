// Link: https://www.codingninjas.com/studio/problems/left-view-of-binary-tree_625707?leftPanelTab=0
/*
you have a BTree, You are looking from the left, Print all the Nodes you can see..
    NOTE: Only first Node at every level can be seen from Left View.
*/

#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

// Apraoch: Level Order Traversal + MAP<level, NodeVal>
void printLeftView(BinaryTreeNode *root)
{
    // edgeCase:
    if (root == NULL)
        return;

    // Queue strcuture: <currNodeLevel, Node>
    queue<pair<int, BinaryTreeNode *>> qt;
    map<int, int> mp; // Map Structure: <level, NodeVal>

    // lets push the root Node...
    qt.push(make_pair(0, root)); // At root Node, Level is 0

    // level Order Traversal
    while (!qt.empty())
    {

        // Lets bring the front of the queue and pop it..
        int currLvl = qt.front().first;
        BinaryTreeNode *temp = qt.front().second;
        qt.pop();

        // Lets push in the map, only if the lvl not present..
        if (!mp.count(currLvl))
        {
            mp[currLvl] = temp->data;
        }

        // Look for the left and right child..[Whenever we move down to child, lvl increment by 1]
        if (temp->left)
            qt.push(make_pair(currLvl + 1, temp->left));
        if (temp->right)
            qt.push(make_pair(currLvl + 1, temp->right));
    }

    // iterate the map and print the vals..
    cout << endl;
    for (auto i : mp)
    {
        cout << i.second << " ";
    }
}

// Appraoch2: Using Recursion and level Tracking
void solveRecursion(BinaryTreeNode *root, vector<int> &ans, int currLvl)
{
    // BaseCase:
    if (root == NULL)
        return;

    // To check for new level...
    if (currLvl == ans.size())
    {
        cout << root->data << " ";
        ans.push_back(root->data);
    }

    // REcursion, precess the left and right child..
    solveRecursion(root->left, ans, currLvl + 1);
    solveRecursion(root->right, ans, currLvl + 1);
}

/*
Appraoch1:
Logic: Use LEvel order Traversal,
    -- Queue<pair<lvl, Node>>, using Level Order Traversal.
    -- Map<lvl, NodeValue> -> Push in Map only when a new lvl comes, else ignore it.
    NOTE: map will store the nodeVals in sorted order of lvl. [map will take care...]
    -- Iterate the Map,
        Print the values.
    [**Done**]

Appraoch2 : [Use Recrsion] [faster than level Order Traversal]
    -- Track the level and have vector,
    -- Whenever we move to new level, level will be equal to size of the vector.
        so, push the data and done.
    -- look for left and right child.
    [**Done**]
*/