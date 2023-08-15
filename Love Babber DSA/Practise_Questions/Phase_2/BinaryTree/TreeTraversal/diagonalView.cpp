// Link: https://www.codingninjas.com/studio/problems/diagonal-traversal-of-a-binary-tree_920477?leftPanelTab=0
/*
    Basically, you have a tree, and you need to print data in a diag manner.
    NOTE: When you move right, all nodes falls under same diag, As you move left, Nodes falls under a new diag.
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

// Approach: Level Order Traversal, Queue + Map to store the digonal and corresponding NodeVals
vector<int> solve(TreeNode *root)
{

    vector<int> ans;

    // edgeCase:
    if (root == NULL)
        return ans;

    // Queue structure: <diag, Node>
    queue<pair<int, TreeNode *>> qt;
    map<int, vector<int>> mt; // Map Structure: <diag, List of Nodes>

    // push the root into Queue..
    qt.push(make_pair(0, root)); // Root's at dig 0 [lets assume]

    // Level Order Traversal
    while (!qt.empty())
    {
        // Take the front of queue and pop it..
        int currDig = qt.front().first;
        TreeNode *temp = qt.front().second;
        qt.pop();

        // Lets insert Node values into the map, as per diagonal..
        mt[currDig].push_back(temp->data);

        // Lets see for left and right child..
        // NOTE: If moving right, keep diag same, when moving left dig+1. [**IMP**]
        if (temp->left)
        {
            qt.push(make_pair(currDig + 1, temp->left));
        }
        if (temp->right)
        {
            qt.push(make_pair(currDig, temp->right));
        }
    }

    // Now lets traverse the map and store in ans..
    for (auto i : mt)
    {
        for (auto j : i.second)
        {                     // i.second is a vector, we are iterating it.
            ans.push_back(j); // pulling values from vector and storing in ans.
        }
    }

    return ans;
}

// Appraoch2: Recursive + tracking the diagonal [fastest Appraoch]
void solveRecursive(TreeNode *node, map<int, vector<int>> &mt, int diag)
{

    // baseCase:
    if (node == NULL)
        return;

    // store the node val alongside its diag
    mt[diag].push_back(node->data);

    // Recursion, Go to left and Go to right...
    solveRecursive(node->left, mt, diag + 1); // increment the diag, as we move left
    solveRecursive(node->right, mt, diag);    // keep diag same.
}

/*
Logic:
    Start from root Node, As you move toward right, keep the diag same. As you move left, increase the diag

Appraoch 1: Level Order Traversal + Map [slower, NOt Preffered]
    -- Queue: <currentDiag, Node>
    -- Map: <diag, List all nodes in that diag>
    -- till queue is empty
        -- Perform Level Order Travesal...
        -- Push the diags and nodes in the map after we pop the node from the queue.
        -- If we move right, keep the diag same.
        -- If we move left, diag+1.
    -- iterate the map, Pull the values into a vectore and return.
    [**DONE**]

Appraoch2: Recursion + diagonal Tracking...
    -- In Recursion Function
        -- recursive function takes, currentNode, map <diag, Vector of all the Nodesval> and current diag
        -- push the val into the map in the vector againt its current diag
        -- as you recursive,
            in left, increment the diag
            in right, keep it same.
    -- Once Recursion Done, iterate the map ans push the values in res and return.
 [**DONE**]

*/