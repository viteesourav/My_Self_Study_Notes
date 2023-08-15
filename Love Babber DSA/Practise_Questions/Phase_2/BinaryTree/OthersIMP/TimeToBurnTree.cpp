// Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
/*
 A BTree is given and a node is given. IF this node gets burnned/infected, How much time it takes for all Nodes to get burn/infected
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
private:
    // Fucntion to generate a Map of node-parentNode Map and find the targetNode..
    // Appraoch: Recursion [TC: O(n) SC: O(n)]
    void createNodeParentMapping(TreeNode *node, unordered_map<TreeNode *, TreeNode *> &nodeParentMap, int start, TreeNode *&targetNode)
    {
        // BaseCase: If you reach a Null Node, just return back
        if (node == NULL)
            return;

        // Check if currentNode is the targetNode..
        if (node->val == start)
            targetNode = node;

        // Check if left or right child exist and store in map
        if (node->left)
        {
            nodeParentMap[node->left] = node; // Store the leftNode -> currentNode [i.e parentNode]
        }
        if (node->right)
        {
            nodeParentMap[node->right] = node; // Store the rightNode -> currentNode [i.e parentNode]
        }

        // call Recursion to left and right child...
        createNodeParentMapping(node->left, nodeParentMap, start, targetNode);
        createNodeParentMapping(node->right, nodeParentMap, start, targetNode);
    }

    // Function that handles the burning of the Tree.. TC: O(N) SC:O(N)
    int findTimeToBurn(TreeNode *root, TreeNode *targetNode, unordered_map<TreeNode *, TreeNode *> &nodeParentMap)
    {
        int timeTaken = 0;
        // Lets have a map to keep track of visited Nodes and queue to track burn Nodes..
        unordered_map<TreeNode *, bool> isVisitedNode;
        queue<TreeNode *> qt;

        // push the targetNode inside the Queue and visited Node...
        qt.push(targetNode);
        isVisitedNode[targetNode] = true;

        // Now lets check till the queue is empty..
        while (!qt.empty())
        {
            // Lets have a flag to check if any elements got added in queue...
            bool isnewNodeAdded = false;
            int size = qt.size();
            // Now process all the Nodes present in the queue..
            for (int i = 0; i < size; i++)
            {
                // Take out the front of Queue and pop it..
                TreeNode *currNode = qt.front();
                qt.pop();

                // Find all adjacent Node for currNode, If they are not visited, add them in Queue
                if (currNode->left && !isVisitedNode[currNode->left])
                {
                    // If left Node exist...
                    isnewNodeAdded = true;
                    qt.push(currNode->left);
                    isVisitedNode[currNode->left] = true;
                }
                if (currNode->right && !isVisitedNode[currNode->right])
                {
                    // If right node exist...
                    isnewNodeAdded = true;
                    qt.push(currNode->right);
                    isVisitedNode[currNode->right] = true;
                }
                if (nodeParentMap[currNode] && !isVisitedNode[nodeParentMap[currNode]])
                {
                    // If parent Node exist...
                    isnewNodeAdded = true;
                    qt.push(nodeParentMap[currNode]);
                    isVisitedNode[nodeParentMap[currNode]] = true;
                }
            }

            // If any newNode got added, increment the timeTaken...
            if (isnewNodeAdded)
                timeTaken++;
        }
        return timeTaken;
    }

public:
    // Appraoch: 3 Step Process... TC:O(N) SC: O(N)
    int amountOfTime(TreeNode *root, int start)
    {
        // Check the edge case Of root Node being NULL...
        if (root == NULL)
            return 0;

        // 1) create and store a node-parent mapping for all Node, 2) Find the Node with start Value.
        unordered_map<TreeNode *, TreeNode *> nodeParentMap;
        TreeNode *targetNode = new TreeNode();
        createNodeParentMapping(root, nodeParentMap, start, targetNode);

        // 3) Implement the burn Algorithm to find the timeTaken..
        return findTimeToBurn(root, targetNode, nodeParentMap);
    }
};

/*
    Idea:
        -- If a node get burned then all adjacent Nodes will also get burned.
        -- Adjacent Nodes i.e left Child, right child, parent Node.

    Logic: 3 Step Appraoch:
        1) Create a map For every node with its parent Node, to keep track of parent's of a node.
            -- Use recursion to Traverse the Tree.
            -- Use hashMap to store the node->parent mapping.
            -- TC: O(N) [all Nodes we visit once], SC: O(N) [max dept of the tree]
        2) Traverse to the given Node.
            -- Can be combined with Step 1. While traversing, If we find the target Node Just return it.
        3) Burn Calculation Algo: [Map + Queue]
            -- Have a map to keep track of visited Nodes.
            -- Have Queue to keep track of burned Nodes.
            -- Push the root Node inside the Qeueue.
            -- Till Queue is empty,
                -- Get the No of elements inside the queue,
                -- For each Elements,
                    -- Get the Front Node form Queue, pop it from the queue.
                    1) Find the adjacent nodes of Front Node [use the leftChild, rightChild and parentNode [use parentNodeMapping]]
                    2) Check if they are not visited insert into the Queue.
                -- If any Insertion happened inside the queue. [means New Node added in queue to burn], Increment the time.
            -- Return the time.
    [** DONE **]
*/