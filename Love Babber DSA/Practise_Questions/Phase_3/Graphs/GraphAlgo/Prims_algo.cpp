// Link: https://www.codingninjas.com/studio/problems/prim-s-mst_1095633
/*
    Given an undirected weighted Graph, Nodes from 1 to N. Find the MST for Graph using Prim's Algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

// ### Optimization:
// A comparator to set the priority Queue to set the pairs as per the first element of the pair..
class Compare
{
public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.first - p2.first;
    }
};

// Approach: key DS + MST bool DS + Parent DS [TC: O(n^2) SC: O(n+m)]
//**(optional) Optimization, using minHeap to find the minEdge of the key DS, [Improved TC: O(n logn)]
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // 1. creating the adjList for the edges..
    unordered_map<int, list<pair<int, int>>> adjList;
    for (auto it : g)
    {
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;

        adjList[u].push_back(make_pair(v, wt));
        adjList[v].push_back(make_pair(u, wt)); // un-direction graph
    }

    // 2. creating the required DS and initialize them...
    unordered_map<int, int> key;    // Keep track of the edges..
    unordered_map<int, bool> isMST; // Keep track of the Nodes already processed for MST.
    unordered_map<int, int> parent; // keep track for the respective parent.
    // ### Optimization...
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap; // structure: <distance, node> [minHeap]

    for (int i = 1; i <= n; i++)
    {
        key[i] = INT_MAX;
        isMST[i] = false;
        parent[i] = -1;
    }

    // 3. Process the source Node and start the algo.. [source -> 1]
    key[1] = 0;
    parent[1] = -1;

    // ## Optimization: Push the key for the source Node in the miniHeap
    minHeap.push(make_pair(0, 1)); //<edgeDistance, node>

    // for (int i = 1; i <= n; i++)
    while (!minHeap.empty()) // ##Optimization.
    {
        // 1.Find the node with the minmum edge from the key DS..
        int minNode;
        int minEdge = INT_MAX;

        // for (auto it : key)
        // { // iterating the key map..
        //     if (!isMST[it.first] && it.second < minEdge)
        //     { // consider nodes where isMST[node]= false
        //         minNode = it.first;
        //         minEdge = it.second;
        //     }
        // }

        // ## Optimization: Pull the edge with the minimum Edge distance and pop it.
        pair<int, int> mini = minHeap.top();
        minHeap.pop();

        minEdge = mini.first;
        minNode = mini.second;

        // 2. Now mark the miniNode as MST Processed..
        isMST[minNode] = true;

        // 3. Now iterate the adjList for the minNode...
        for (auto it : adjList[minNode])
        {
            int v = it.first;
            int wt = it.second;

            // update the key DS and parent Node, if wt < key[v] ans isMST must be false..
            if (!isMST[v] && wt < key[v])
            {
                key[v] = wt;
                parent[v] = minNode;
            }
        }
    }

    // 4. Now you have the parent Map and key Map ready for all the Node..
    // NOTE: Ignore the source Node, as it's Parent is -1
    // Parent Map Strcture: <childNode, ParentNode>, KeyStructure<Node, edgeDistance>
    vector<pair<pair<int, int>, int>> ans;
    for (auto it : parent)
    { // iterate the parent Map..
        if (it.second != -1)
            ans.push_back(make_pair(make_pair(it.second, it.first), key[it.first])); // structure: {{u, v}, wt}
    }

    return ans;
}

/*
-- Needs 3 DS:
    1) A key DS: Stores the min_edge Distance For the given Node, Initialise all with Inf [map or vector]
    2) A MST DS: Keep Track of Nodes which we process for MST. Initialise all with False [map or vector]
    3) A parent DS: Keep Track of Parent Nodes for the Nodes we process for MST. Initialise all with -1 [map or vector]

Appraoch:
    1. Start with the source Node, mark key[source] = 0, parent[source] = -1.
 -Run a loop to cover all Other Nodes.
    2. Iterate the key, find the node with the least distance -> minNode
    3. Update the MST[minNode] = true.
    4. Then Iterate the adjList Node for the minNode.
        -- If the edgeDistance < key[node] and mst[node] is false, update that node's edge in the key DS and update the parent DS
    5. Repeat from step 2.

-- At the end, You have parent DS, containing the node-parent mapping and key DS containing the respective edge details.
-- using this, we can construct a MST. [** DONE **]

   TC: O(n^2) [For finding the minNode, we are iterating again],  SC: O(n+M)

** Optimization:
   -- Have another DS: Priority Queue i.e minHeap, that stores the key DS elements. -> when we pop, we get the node with the least edge.
   -- It will always keep the node with minEdge at the top. -> O(log n) [Fetching minNode is faster]


   TC: O(n log n) [using priority Queue to find minNode], SC: O(n+m) [Optimised]
*/