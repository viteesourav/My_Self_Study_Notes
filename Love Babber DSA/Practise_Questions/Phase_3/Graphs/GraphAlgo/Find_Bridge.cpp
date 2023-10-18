// Link: https://www.codingninjas.com/studio/problems/bridges-in-graph_893026
/*
Given a graph, We need to Identify all the bridge edges exisit in the graph.
    BridgeEdge: A Edge in the Graph which on remove, splits the Graph into Components.
*/
#include <bits/stdc++.h>
using namespace std;

// Fucntion to Handle: DFS Traversal + Bridge Detection
void dfs(int node, int parent, int &timer, unordered_map<int, list<int>> &adjList, vector<int> &discTime,
         vector<int> &low, unordered_map<int, bool> &isVisited, vector<vector<int>> &ans)
{

    // 1. First mark the node as visited and upate the disTime and low with timer..
    isVisited[node] = true;
    discTime[node] = low[node] = timer++; // increment the timer..

    // 2. Iterate all the neighbour for node form adjList...
    for (auto neighbour : adjList[node])
    {
        if (neighbour == parent) // ignore if the neighbour is paentNode.
            continue;

        if (!isVisited[neighbour])
        {
            // If the neighbour is not visited yet..
            dfs(neighbour, node, timer, adjList, discTime, low, isVisited, ans);
            // While backTracking:
            low[node] = min(low[node], low[neighbour]); // Update low, incase the neighbour has back-edge.
            if (low[neighbour] > discTime[node])
            { // Bridge-Check Condition..
                vector<int> res;
                res.push_back(node);
                res.push_back(neighbour);
                ans.push_back(res); // store the [u, v] bridge edge in ans
            }
        }
        else
        {
            // If the neighbour is already visited...[** Back-edge Condition **]
            low[node] = min(low[node], discTime[neighbour]);
        }
    }
}

// Appraoch: DiscoveryTime + lowDiscoveryTime Appraoch. [TC: O(E+V) SC: O(E+V), Linear]
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{

    // 1.Creating the adjList for the given Graph..
    unordered_map<int, list<int>> adjList;
    for (auto it : edges)
    {
        int u = it[0], v = it[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u); // since, undirected graph.
    }

    // 2. Initialise the ds needed..
    vector<int> discTime(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> isVisited;

    int timer = 0;

    vector<vector<int>> ans;
    // 3. Perform DFS Traversal...[cover all the 0 to V-1 Nodes]
    for (int node = 0; node < v; node++)
    {
        if (!isVisited[node])
        {
            dfs(node, -1, timer, adjList, discTime, low, isVisited, ans);
        }
    }

    return ans;
}
/*
Implementation: TC: O(N+V) SC: O(N) [Liner]
   -- 3 Data Structure needed:
      1) DiscoveryTime: can be vector or map, keep track of the maxTime taken to reach a particualr Node.
      2) Low: can be vector or map, keep track of the miniTime taken to reach a particualr Node.
      3) Visited: A map keep tracks of the visited Nodes.
Logic:
   -- You Do a noraml DFS in the given Graph, maintain a timer, update the timer everytime You visit a new Node.
   -- Also maintain the track of the parent Node.
   -- Update the same in the DiscovertTime DS, and LowDiscoveryTime DS.
   -- Iterate all the adjList Nodes for the currNode.
      -- If the node is parent of a currNode -> ignore it.
      -- If the node is Visited but not a parent. i.e Back Edge Condition.[IT means there exisit another path to reach the node, which dont include the currNode]
         -- In this case update the low[node] = min(low(node), DiscovertTime(neighbour))
      -- While returning back, 2 Things:
         1) Update the low for the neighbour node: low[node] = min(low(node), low(neighbour)) [the neighbour might form a backedge, thus need to update the low for this node too]
         2) check for bridge condition: low[neighbour] > DiscovertTime[node]
            -- If true Bridge Exist.
            -- This works because, This condition means there exist only one path to the node. If there exisit another path, low would be less.
   [** DONE **]
*/