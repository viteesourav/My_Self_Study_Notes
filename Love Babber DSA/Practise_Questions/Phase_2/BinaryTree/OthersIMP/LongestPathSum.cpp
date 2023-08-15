// Link: https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
/*
    In BTree, Take the longest path from root to Leaf Nodes and Return the max sum possible..
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
private:
    // Appraoch1: Recursion and Tracking noOfNodes and Sum and maxSum...
    void solveRecursion(Node *node, int sum, int noOfNodes, int &maxNodePath, int &maxSum)
    {

        // EdgeCase: If node Reached Null...
        if (node == NULL)
        {
            // If noOFNodes in current path exceeds the maxNodePAth
            if (noOfNodes > maxNodePath)
            {
                maxNodePath = noOfNodes;
                maxSum = sum;
            }
            else if (noOfNodes == maxNodePath)
            { // If both Nodes are at same lvl
                maxSum = max(maxSum, sum);
            }
            return; // Retrun back from the leaf node...
        }

        // update the sum with the current Node Data...
        sum += node->data;

        // REcursion, traverse left and right..
        solveRecursion(node->left, sum, noOfNodes + 1, maxNodePath, maxSum);
        solveRecursion(node->right, sum, noOfNodes + 1, maxNodePath, maxSum);
    }

    // Approach2: Level Order Traversal...
    int solve2(Node *root)
    {
        // check for edgeCase..
        if (root == NULL)
            return 0;

        queue<pair<Node *, pair<int, int>>> qt; // Stores: <Node, <currLevel, sumTillCurrNode> >
        pair<int, int> pt = make_pair(0, 0);    // Stores: <maxLevel, maxSum>

        // store the root Node...
        qt.push(make_pair(root, make_pair(0, root->data))); // At rootNode, lvl =0 and sum is root Node value

        // Level Order Travesal
        while (!qt.empty())
        {
            // Take the front of the queue and pop it..
            Node *temp = qt.front().first;
            //<Node, <currLevel, SumtillCurrLevel > >
            int currLvl = qt.front().second.first;
            int currSum = qt.front().second.second;
            qt.pop();

            // NOw lets update the maxSum and level..
            if (currLvl > pt.first)
            {
                pt.first = currLvl;
                pt.second = currSum;
            }
            else if (currLvl == pt.first)
            {
                pt.second = max(pt.second, currSum);
            }

            // Look for left and right child...
            if (temp->left != NULL)
            {
                qt.push(make_pair(temp->left, make_pair(currLvl + 1, currSum + temp->left->data)));
            }
            if (temp->right != NULL)
            {
                qt.push(make_pair(temp->right, make_pair(currLvl + 1, currSum + temp->right->data)));
            }
        }

        // Now after we processed all Nodes...
        return pt.second; // This stores maxSum;
    }

public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        // Appraoch 1:
        // int maxSum = INT_MIN;
        // int sum = 0;
        // int noOfNodes = 0, maxNodePath = 0;
        // solveRecursion(root, sum, noOfNodes, maxNodePath, maxSum); // For the root Node, NoOfNodes =1 and maxSum = NodeVal
        // return maxSum;
        // Appraoch2:
        return solve2(root);
    }
};

/*

Appraoch1: REcursion and track the sum and totalNoOfNodes... [Preferred]
    -- Recursion Function: Node, noOfNode, sumAtCurrNode, maxLenght, maxSum.
    -- EdgeCAse: if the Null
        -- Check if the noOfNodes > maxLength -> store the sum in maxSum.
        -- Check if the noOfNodes = maxLength => store the max between sum and maxSum
        -- and return back..
    -- Update the sum at the currentNode.
    -- Recursion call for left and right child.
[**DONE**]

Appraoch2: Use Level Order Traversal,
        -- Queue: <Node, <currLevel, SumAtCurrNode > >
        -- a pair to keep Track of <maxlevel, maxSum>
    -- start the level Order Traversal...
    -- condition for updating maxLevel and maxSum you check..
        -- Check if the currLvl > maxLevel -> store the sum in maxSum.
        -- Check if the currLvl = maxLevel => store the max between sum and maxSum
    -- return the second half of the pair we stored that contains the maxSum.
[**DONE**]
*/