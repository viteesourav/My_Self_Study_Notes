// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
/*
Basically, You have a Tree, Print the Nodes in Vertical order from left to Right.
Special Condition is Question:
    If 2 Nodes are in the same LEvel and same HD, we need to Print Node in sorted order.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        // edge case handle:
        if (root == NULL)
            return ans;

        // Queue for level Order Traversal, stores <<HD, lvel>, Node>
        queue<pair<pair<int, int>, TreeNode *>> qt;
        map<int, map<int, vector<int>>> mp; // Map to store <hd, map<level, listOfNodeValues>>

        // AT root Node, level is 0 and HD is also 0
        qt.push(make_pair(make_pair(0, 0), root));

        // Special Condition Given in Problem: Nodes at same Level of the Tree must be sorted.[Map will take care of the ordering]
        // Start level Order Traversal...
        while (!qt.empty())
        {
            // take the front from the queue and pop it..
            pair<int, int> currPos = qt.front().first; // Fetch the position of current Node.
            // currPos: <HD, level>
            int currHD = currPos.first;
            int currLvl = currPos.second;

            TreeNode *temp = qt.front().second;
            qt.pop();

            // Storing in the map..
            mp[currHD][currLvl].push_back(temp->val);

            // look for left and right child and push it into the queue...
            if (temp->left)
                qt.push(make_pair(make_pair(currHD - 1, currLvl + 1), temp->left)); // If going left, HD decrement by 1
            if (temp->right)
                qt.push(make_pair(make_pair(currHD + 1, currLvl + 1), temp->right)); // If going right, HD increment by 1
        }

        // Now Map holds all the Nodes with there respective HD in sorted order..
        for (auto i : mp)
        {
            vector<int> temp;
            // here i will give a map with <level, listnodeValues>
            for (auto j : i.second)
            {
                // Sort the vector before we take out the Node Values..
                sort(j.second.begin(), j.second.end());
                // iterating the vector...
                for (auto k : j.second)
                {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp); // Fetch the listnodevalues from the inner map
        }

        return ans;
    }
};

/*
Logic:
    --Assume we have y axis as the level of the Tree and node's Position are represented on the Number Line.
        Based on this, map is used
            key: Horizontal Distance from the root Node
            value: Have another Map that stores, <NodeLevel, List of all Node Values>
    -- Queue used in Level order: <pair<currentNodeHD, currentNodeLvl>, Node>

NOTE: we are using map, It will sort the keys by default, So when we iterate, we retrive keys in sorted order.

Appraoch:
    -- We need to do a level Order Traversal on the given tree, Needs a Queue.
    -- we will have a map to track the Nodesval with there respective Lvl based on the horizontal distance from root Node.
    -- First push the root Node and its level against its Horizontal Distance in the map.
    -- While doing level order Traversal,
        -- Whenever we take the temp as the front of the queue, check its horizontal distance and its level
        -- based on it, push it into the map. [NOTE: For Map,  key is HD, value is another map with key as lvl and value as Vector of node elements]
        -- If we look for left Child, horizontal distance will decrement by 1, level+1
        -- If we look for right Child, horizontal distance will increment by 1, level+1
    -- iterate the map
        -- This gives the map based on HD, with level as key and value as vector.
        -- sort the vector. [**special Condition**]
        -- the iterate the vector and store all the elements for all the levels.
    -- Push the copied keys into the res Vector.
[**DONE**]
*/