// Link: https://www.codingninjas.com/studio/problems/topological-sort_982938
/*
    A DAG [Directed Acyclic Graph] is Given. Need to Find Valid Topology Sorted Nodes using BFS Traversal
        For all the Edges u---> v, In the topology sorted Nodes, u must come before v.

    ** Kahn's Algorthim ** [using the in-Degree of the graph]
*/

#include <bits/stdc++.h>
using namespace std;

// Appraoch: BFS_Traversal + Kahn's Algo [inorder-degree]
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    vector<int> ans;

    // 1) Preparing the adjList...
    unordered_map<int, list<int>> adjList;
    for (auto it : edges)
    {
        int u = it[0], v = it[1];

        adjList[u].push_back(v); // since directed graph..
    }

    // 2. Prepare the in-degree for all the Nodes...
    vector<int> inDeg(v, 0);
    for (auto it : adjList)
    { // Traverse the adjList Map...
        for (auto node : it.second)
        {                  // Traverse the List for a particular Node in the adjList map..
            inDeg[node]++; // Store the freq of node..
        }
    }

    // 3. Store all the Nodes with 0 in-deg in the Queue..
    queue<int> qt;
    for (int index = 0; index < inDeg.size(); index++)
    {
        if (inDeg[index] == 0)
            qt.push(index); // Push the Nodes with 0 In-deg in the Queue...
    }

    // 4. Till the Queue is empty, we process...
    while (!qt.empty())
    {
        // Let's pop the front and store in the ans..
        int ele = qt.front();
        qt.pop();
        ans.push_back(ele);

        for (auto node : adjList[ele])
        {
            inDeg[node]--;
            if (inDeg[node] == 0)
                qt.push(node);
        }
    }

    return ans;
}

/*
Appraoch: Kahn's Algorithm
    Steps:
    1) Prepare the adjList Map for the Nodes and edges.
    2) Prepare the in-Degree Vector For All the Nodes. [Traverse the adjList, prepare it]
    3) Push all the Nodes with 0 in-degree in the Queue.
    4) till the Queue is empty:
        -- Pop the front, Store in the ans.
        -- For all Linked Nodes for Front, reduce the in-degree by 1.
        -- If any Node's in-degree is 0 -> Push it in the Queue.
    [**DOne**]

*/