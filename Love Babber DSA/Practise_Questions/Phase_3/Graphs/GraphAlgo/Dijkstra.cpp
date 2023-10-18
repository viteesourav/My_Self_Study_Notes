// Link: https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_920469
/*
    Given a undirected weighted Graph i.e the node-edgeList, Find the min_dis from Node 0 to all Other Nodes.
    [** Use Dijkstra Algo **]
*/

#include <bits/stdc++.h>
using namespace std;

// Appraoch: min_dis Map + set to keep track of path.. TC,SC: O(vertices + edges)
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    // 1. lets first create the adjList Map...
    // syntax of adjList: map<u, list<pair<v, edgeWeight>>>, u and v are the nodes.
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0], v = vec[i][1], wt = vec[i][2];
        adjList[u].push_back(make_pair(v, wt));
        adjList[v].push_back(make_pair(u, wt)); // it's a bi-directional edge...
    }

    // 2. lets create the min_dis map that we need to update..
    vector<int> min_dis(vertices);
    for (int i = 0; i < vertices; i++) // Initialize all min_dis as Inf/INT_MAX..
        min_dis[i] = INT_MAX;

    min_dis[source] = 0; // Marked the min_dis for source node as 0.

    // create a set and insert it..
    set<pair<int, int>> nodeSet; // set<pair<distance, node>>
    nodeSet.insert(make_pair(0, source));

    // 3. Process the set till it's empty...
    while (!nodeSet.empty())
    {
        // Take out the pair with the min edge_wt...
        auto minEle = *(nodeSet.begin()); // take the first ele from the set
        nodeSet.erase(nodeSet.begin());   // remove from the set.

        // iterate the adjList and check the linked Nodes...
        for (auto it : adjList[minEle.second])
        {
            if (minEle.first + it.second < min_dis[it.first]) // If the new dis is less than the dis at min_dis, Update it.
            {
                // check if the set already holds it.first node, if yes remove it.
                auto record = nodeSet.find(make_pair(min_dis[it.first], it.first));

                if (record != nodeSet.end())
                { // if found, remove it..
                    nodeSet.erase(record);
                }

                min_dis[it.first] = minEle.first + it.second;
                nodeSet.insert(make_pair(min_dis[it.first], it.first));
            }
        }
    }

    return min_dis;
}

/*
Appraoch:
-- You need:
      1) The adjList for the given Graph.
      2) A min_Distance Map for all the Nodes initialized with all Inf.
      3) A DS that stores the pair<distance, node> [Stores in such a way, we can always pull out the ele with min edge_weight]
         -- 2 Possible DS we can use:
            1) set<>: Stores the ele in sorted way i.e the first element will be always smaller.
            2) priority_queue i.e min_heap: When we pop, we always get the min element from the heap.

   Logic: [we will use set here to store the <distance, node> pair]
      -- Start with source node, make the min_dis of source Node 0, and push the same in the Set/minHeap.
      -- Now till the heap is empty
         -- Pull the node with least edge_weight from the set/minHeap.
         -- calculate the new dis, if it's less than the dis stored in min_dis map, update the min_dis map for the node.
*/