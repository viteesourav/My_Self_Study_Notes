// Create a new binary Tree...
/* Methods implemented:
    1) Constructing a BTree from scratch
    2) Printing the tree in a level Order. [WE have a reverse level order also, use stack]
    3) Traversal: Inorder, preOrder and PostOrder
    4) Constructing the BTree from Level Order Nodes Data.

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Construction of a Binary Tree...[using Recursion]
Node *constructBTree(Node *node)
{

    int data;
    // cout<<"Enter the value of Node: ";
    cin >> data;
    node = new Node(data); // crating a Node for the data...

    // baseCase...[If data -1, return from back]
    if (data == -1)
        return NULL;

    // LeftSide Node...
    //  cout<<"Enter data for left for "<< data <<endl;
    node->left = constructBTree(node->left);

    // rightSide Node...
    //  cout<<"Enter data for right for "<< data <<endl;
    node->right = constructBTree(node->right);

    return node;
}

// Printing the elements of the Tree from Root to Leaf nodes, Level-wise from top to bottom...
// Using Queue..
void printLevelOrderTraversal(Node *root)
{

    queue<Node *> tq;
    tq.push(root); // First push whatever is coming in the queue..
    tq.push(NULL); // A seperator to seperate the levels [In output we can print level-wise in new Line]

    // Now loop till the Queue is empty...
    while (!tq.empty())
    {

        Node *temp = tq.front(); // take the first element from left i.e front element.

        // Handle the Sperator to Print in new Line...
        if (temp == NULL)
        {
            cout << endl;
            tq.pop();
            // check if queue has any child Nodes..
            if (!tq.empty())
            {
                tq.push(NULL); // If child are there, push null at end for printing endl at the end.
            }
        }
        else
        {
            cout << temp->data << " "; // print the data..
            tq.pop();                  // pop the element..

            // push the Node on left side of temp inside Queue...
            if (temp->left)
            {
                tq.push(temp->left);
            }

            // push the Node on right side of temp inside Queue...
            if (temp->right)
            {
                tq.push(temp->right);
            }
        }
    }
}

// NOTE: Just Remember the Order of where to call REcursion...

// In-Order Traversal...
void InOrderTraverse(Node *root)
{

    // baseCase: If you reached a NULL node, return from it...
    if (root == NULL)
        return;

    InOrderTraverse(root->left);
    cout << root->data << " ";
    InOrderTraverse(root->right);
}

// Pre-Order Traversal....
void PreOrderTraverse(Node *root)
{

    // baseCase: If you reached a NULL node, return from it...
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreOrderTraverse(root->left);
    PreOrderTraverse(root->right);
}

// PostOrderTraverse....
void PostOrderTraverse(Node *root)
{

    // baseCase: If you reached a NULL node, return from it...
    if (root == NULL)
        return;

    PostOrderTraverse(root->left);
    PostOrderTraverse(root->right);
    cout << root->data << " ";
}

// Creating a binaryTree from printLevelOrderTraversal...
Node *constructBTreeFromLevelOrder()
{
    // LevelOrder mean we need to use queue...
    queue<Node *> qt;
    int data;

    cout << "Enter the root Node: " << endl;
    cin >> data;
    Node *root = new Node(data);
    qt.push(root);

    while (!qt.empty())
    {

        // Holding the front Node in qt in temp, then poping it out...
        Node *tempNode = qt.front();
        qt.pop();

        int val;
        // let take the left NOde data...
        cout << "Enter the Node Value for left of " << tempNode->data << endl;
        cin >> val;
        if (val != -1)
        {
            tempNode->left = new Node(val);
            qt.push(tempNode->left);
        }

        // let take the left NOde data...
        cout << "Enter the Node Value for right of " << tempNode->data << endl;
        cin >> val;
        if (val != -1)
        {
            tempNode->right = new Node(val);
            qt.push(tempNode->right);
        }
    }

    return root;
}

int main()
{

    Node *root = NULL;
    root = constructBTree(root);

    // Level Order Traversal.. [Printing the tree from root level till leaf nodes]
    cout << endl
         << "Printing the Data Level-wise: " << endl;
    printLevelOrderTraversal(root);

    // Inorder Tree Traversal...
    cout << endl
         << "InOrderTraverse: " << endl;
    InOrderTraverse(root);

    // Inorder Tree Traversal...
    cout << endl
         << "PreOrderTraverse: " << endl;
    PreOrderTraverse(root);

    // Inorder Tree Traversal...
    cout << endl
         << "PostOrderTraverse: " << endl;
    PostOrderTraverse(root);

    cout << endl
         << "Implementing a binary tree" << endl;

    Node *root2 = constructBTreeFromLevelOrder();
    cout << "Printing the Data Level-wise: " << endl;
    printLevelOrderTraversal(root2);

    return 0;
}