// Link: https://www.codingninjas.com/studio/problems/topological-sort_982938
/*
    A DAG [Directed Acyclic Graph] is Given. Need to Find Valid Topology Sorted Nodes using DFS Traversal
        For all the Edges u---> v, In the topology sorted Nodes, u must come before v.
*/
#include <bits/stdc++.h>
using namespace std;

// DFS Traversal [Recursive]
void dfs_traverse(int vertex, unordered_map<int, list<int>> &adjList, vector<bool> &isVisited, stack<int> &node_stack)
{

    // Mark the incoming Node...
    isVisited[vertex] = true;

    // Now call Dfs_traverse Recursive for all Linked Nodes...
    for (auto node : adjList[vertex])
    {
        if (!isVisited[node])
        {
            dfs_traverse(node, adjList, isVisited, node_stack);
        }
    }

    // After the process is done for vertex Node, Push it in the stack...
    node_stack.push(vertex);
}

// Appraoch: DFS_Traversal + Stack
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    vector<int> ans;
    unordered_map<int, list<int>> adjList;
    vector<bool> isVisited(v); // A Vector of bool for all v nodes..
    stack<int> node_stack;

    // First lets create the adjList...
    for (auto it : edges)
    {
        int u = it[0], v = it[1];

        adjList[u].push_back(v); // it's a directed graph i.e u --> v
    }

    // We will cover all the Nodes...
    for (int vertex = 0; vertex < v; vertex++)
    {
        if (!isVisited[vertex])
        {
            dfs_traverse(vertex, adjList, isVisited, node_stack);
        }
    }

    // After proccessing all the vertex, lets create the ans...
    while (!node_stack.empty())
    {
        ans.push_back(node_stack.top());
        node_stack.pop();
    }

    return ans;
}

/*
Appraoch: Using DFS Traversal [TC, SC: Linear]
    -- Use a Stack.
    -- While Returning back form the dfs Recursive function, Just store the Node.
    -- Print all the Nodes. [Topology Sorted Order]
*/