// Link: https://www.codingninjas.com/studio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151
/*
Given a directed Graph. With n vertiecs and m edges. Find the count of all the Strongly connected SCC[Strongly connected Components] present.
*/
#include <bits/stdc++.h>
using namespace std;

// utility Method to find the DFS topology Stack [Dfs Traversal]
void do_TopologyDfs(int node, unordered_map<int, list<int>> &adjList,
                    unordered_map<int, bool> &isVisited, stack<int> &topo_stack)
{
    // Mark the incoming Node visited...
    isVisited[node] = true;

    // iterate all neighbour nodes...
    for (auto nbr : adjList[node])
    {
        if (!isVisited[nbr])
        {
            do_TopologyDfs(nbr, adjList, isVisited, topo_stack);
        }
    }

    // while returning, push the node in the Stack..
    topo_stack.push(node);
}

// A recursive Simple DFS Traversal in Graph...
void do_dfs(int node, unordered_map<int, list<int>> &transposeAdjList, unordered_map<int, bool> &isVisited)
{
    // mark the incoming Node as visited...
    isVisited[node] = true;

    // Iterate all the nbrNodes...
    for (auto nbr : transposeAdjList[node])
    {
        if (!isVisited[nbr])
        {
            do_dfs(nbr, transposeAdjList, isVisited);
        }
    }
}

// Approach: DFS Topology Stack + Transpose + DFS Traversal [TC, SC: O(N+E)]
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // 1. Let's have the adjList...
    unordered_map<int, list<int>> adjList;
    for (auto it : edges)
    {
        int u = it[0], v = it[1];

        adjList[u].push_back(v); // directed Graph i.e u -> v
    }

    // 2. DFS Topology Stack
    stack<int> topo_stack;
    unordered_map<int, bool> isVisited;

    // iterate all the nodes...
    for (int i = 0; i < v; i++)
    {
        if (!isVisited[i])
        {
            do_TopologyDfs(i, adjList, isVisited, topo_stack);
        }
    }

    // 3. transpose the Given Graph.. u->v to v->u
    unordered_map<int, list<int>> transposeAdjList;
    for (auto it : adjList)
    { // iterate the map...
        for (auto pt : it.second)
        { // iterate the neighbour nodes list...
            transposeAdjList[pt].push_back(it.first);
        }
    }

    // 4.Now again do the DFS Traversal till we process all Stack Nodes..
    isVisited.clear(); // clear the isvisited Map
    int scc_Count = 0; // Track the count of Strongly Connected Nodes...
    while (!topo_stack.empty())
    {
        // Take the top Node from the stack, pop it also..
        int topNode = topo_stack.top();
        topo_stack.pop();

        // If the topNode is not Visited...
        if (!isVisited[topNode])
        {
            scc_Count++;
            do_dfs(topNode, transposeAdjList, isVisited);
        }
    }
    return scc_Count;
}
/*
Logic: 3 Steps:
   1) First you need to Find the DFS Topology Stack for the Given Graph.
   2) Reverse all the edges in the Graph. i.e u -> v to v->u for all the Nodes. [also Called as Transpose the Graph]
   3) Now Based on the Stack Nodes, You Do noraml DFS traversal
      -- EAch DFS Traversal will Print all the strongly connected Nodes belong to a particular Component.
*/