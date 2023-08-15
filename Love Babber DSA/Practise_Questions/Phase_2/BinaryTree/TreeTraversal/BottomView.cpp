// Link: https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_893110?leftPanelTab=0
/*
you have a BTree, You are looking from the bottom, Print all the Nodes you can see..
    NOTE: Only last Node at every HD can be seen from Bottom View.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// Approach: Vertical order Travesal: Queue<pair<HD, NodeVal>> + Map<HD, NodeVal>
vector<int> getTopView(TreeNode *root)
{
    vector<int> ans;
    // edge Case:
    if (root == NULL)
        return ans;

    // Queue structure: Queue<pair<HorizontalDistance, Node>>
    queue<pair<int, TreeNode *>> qt;
    map<int, int> mp; // Map Structure: <HD, nodeVal>

    // Push the root node in the Queue, initially, Root's horizontal dist 0
    qt.push(make_pair(0, root));

    // Level Order Traversal...
    while (!qt.empty())
    {
        // Lets bring out the front of the Queue and pop it..
        int currHD = qt.front().first;
        TreeNode *temp = qt.front().second;
        qt.pop();

        // update keys as soon as we get the HD and NodeVal [each HD will contain latest Nodeval]
        mp[currHD] = temp->val;

        // Look for the left and right child..
        if (temp->left)
        {
            qt.push(make_pair(currHD - 1, temp->left));
        }
        if (temp->right)
        {
            qt.push(make_pair(currHD + 1, temp->right));
        }
    }

    // Now iterate the map and store in the ans array...
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }

    return ans;
}

/*
Logic: Use Vertical Order Traversal,
    -- Queue<pair<HD, Node>>, using Level Order Traversal.
    -- Map<HD, NodeValue> -> Push in Map for all HD comes. [**IMP**]
    NOTE: map will store the nodeVals in sorted order of HD. [map will take care...]
    -- Iterate the Map,
        Print the values.
    [**Done**]
*/