// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
/*
    You given a BTree, You need to Flattern the Tree into Linked List with nodes as Pre-Prder Traversal.
    NOTE: Do this in SC: O(1) i.e Morris Traversal.
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
    // Approach: Morris Traversal, Inorder Predecessor Node Detection.[TC: O(N), SC: O(1)]
    void flatten(TreeNode *root)
    {
        // First the base case check, if root is NULL
        if (root == NULL)
            return;

        TreeNode *currNode = root;

        // Loop till the currNdoe's is NULL
        while (currNode != NULL)
        {
            // If the Left exist for the currNode...
            if (currNode->left)
            {
                // Find the Predecessor's Node for the currNode...
                TreeNode *predNode = currNode->left; // Move one left Node..

                while (predNode->right != NULL) // Continue moving to right till its NULL
                    predNode = predNode->right;

                // Now connect to predNode to left of the currNode...
                predNode->right = currNode->right;

                // for currNode, Break the link to right child,
                currNode->right = currNode->left; // point right link to left child.
                currNode->left = NULL;            // Make the left child as null
            }
            // update currentNode as the next Node on right..
            currNode = currNode->right;
        }
    }
};

/*
TC: O(N)
SC: O(1) [As no Recursion or additional DS used]
Approach:
    -- Pre-order: Node -Left- Right [For a node, First lets connect Left and Right, then Node and left]
    -- Logic: use Morish Traversal [find the inorder Predecessor Node]
    -- Loop till the currNode is not NULL,
        -- Check if the left Exist for currNode. If yes,
            -- Take the currNode.
            -- If the left exist for CurrNode, Find the Predecessor Node.
                -- First go left and then go right till right becomes Null.
            -- Now Connect Predecessor Node to currNode's Right Node.
            -- update the currNode's Right to currNode's left and Make currNode's Left as Null.
    -- Update currNode as currNode's right.
    -- Thus, The links are Modified and Tree is flattern.
*/