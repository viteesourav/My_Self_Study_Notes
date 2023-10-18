// Link: https://www.codingninjas.com/studio/problems/shortest-path-in-an-unweighted-graph_981297
/*
    An undirected Graph is given, Its Edges and Node Relation is given. Find the shortest path from 's' Node to Reach 't' node.
*/
#include <bits/stdc++.h>
using namespace std;

// Perform BFS Traversal...
void do_bfs(int sourceNode, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &isVisited, unordered_map<int, int> &parentMap)
{

    queue<int> qt;

    // mark the current node as visited and push in the queue..
    isVisited[sourceNode] = true;
    parentMap[sourceNode] = -1;
    qt.push(sourceNode);

    // Iterate till queue is empty..
    while (!qt.empty())
    {
        // pop the front Node...
        int frontNode = qt.front();
        qt.pop();

        // iterate the linked Nodes for the front Node...
        for (auto it : adjList[frontNode])
        {
            if (!isVisited[it])
            { // if Node is not visited...
                // push inside the queue & mark it visited & update the parent Map..
                qt.push(it);
                isVisited[it] = true;
                parentMap[it] = frontNode;
            }
        }
    }
}

// Appraoch: BFS + Parent Node Tracking TC: O(n+m) SC: O(n+m)
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    vector<int> ans;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> isVisited;
    unordered_map<int, int> parentMap; // Keep track of the Parent Nodes..[index->node, parentMap[index] -> node's parent]

    // 1. creating the adjList...
    for (auto it : edges)
    {
        int u = it.first, v = it.second;

        adjList[u].push_back(v);
        adjList[v].push_back(u); // un-directed Graph..
    }

    // 2. Do BFS from the source node..
    do_bfs(s, adjList, isVisited, parentMap);

    // 3. Now you have the parentMap, lets find the path from destination Node to Source Node..
    int currNode = t;
    ans.push_back(t); // pushing the destination Node..
    while (currNode != s)
    {
        currNode = parentMap[currNode];
        ans.push_back(currNode);
    }

    // reverse the ans...
    reverse(ans.begin(), ans.end());

    return ans;
}

/*
Appraoch: BFS + Parent Tracking
    -- Maintain a Map for Parent Tracking for the All the Nodes.
    -- Do BFS Traversal
    -- While Doing keep track of parent for each Nodes.
    -- IN ParentTrack List,
        -- Start from the dest Node -> Move till source, store the Nodes in the ans.
        -- Reverse the ans.
    [** Shortest Path **]

*/