// Link: https://www.codingninjas.com/studio/problems/dfs-traversal_630462
/*
    You Given a Disconnected Graph [Graph may or maynot have multiple Components], Do DFS Traversal.
*/

#include <bits/stdc++.h>
using namespace std;

// Utility function to create the adjacent List...
void createAdjList(unordered_map<int, set<int>> &adjList, vector<vector<int>> &edges, int E)
{
    // iterate the edges list and push in the map...
    for (auto it : edges)
    {
        adjList[it[0]].insert(it[1]);
        adjList[it[1]].insert(it[0]); // since its undirected, i.e bi directional edges..
    }
}

// Recursive Function to traverse and print all Nodes..
void print_dfs(int node, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &isVisited, vector<int> &res)
{

    // first you store the node value in the res array & mark the Node visited...
    res.push_back(node);
    isVisited[node] = true;

    // Run a loop in the adjList for the node and call Recursion...
    for (auto vertex : adjList[node])
    {
        if (!isVisited[vertex])
        { // if the vertex is not visited...
            print_dfs(vertex, adjList, isVisited, res);
        }
    }
}

// Approach: REcursion + Maps[vistied Map + adjacentListMap]
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;

    unordered_map<int, set<int>> adjList; // keep tracks for Nodes-edges...
    unordered_map<int, bool> isVisited;   // keep track of visited Nodes...

    // creates the adjacent List for the graph...
    createAdjList(adjList, edges, E);

    // Since Disconnected Graph, lets have a loop to check all the Nodes...
    for (int vertex = 0; vertex < V; vertex++)
    {
        if (!isVisited[vertex])
        { // if node is not visited, process it..
            vector<int> res;
            print_dfs(vertex, adjList, isVisited, res);
            ans.push_back(res);
        }
    }

    return ans;
}

/*
Logic: [use Recursion]
    -- You Start with the source Node, You move and print all the Nodes one by one using Recursion.
    NOTE: If disconnected Graph, Run a loop to cover all the Nodes.

Appraoch: TC: O(n) SC: O(n) [n -> number of Nodes]
    Step1: If not given, Prepare a adjacent List using map or if Nodes are int, You can use 2-D Vector to store the Nodes and edges.
    Step2: Prepare a isVisited Map for all the Nodes, to keep Track.
    Step3: use Recursion,
        -- For each Node, Call Recursion to Process all the Nodes in the Adjacent List.
    **DONE**
*/