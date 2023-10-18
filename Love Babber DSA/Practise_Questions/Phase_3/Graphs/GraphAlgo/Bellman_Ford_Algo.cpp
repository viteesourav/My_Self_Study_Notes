// Link: https://www.codingninjas.com/studio/problems/bellmon-ford_2041977
/*
Given a Directed Graph, Nodes from 1 to N, edges can have negative weight. Find minDistance from src to all other Nodes.
*/
#include <bits/stdc++.h>
using namespace std;

// Approach: Bellman Ford Algo [since edge weights have negative]
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    // 1. min_dis to keep track of the minimum distance...
    vector<int> min_dis(n + 1, 1e8); // Nodes we consider from 1 to N..

    // Run Loop for n-1 times..
    min_dis[src] = 0; // set the minDistance for source Node -> 0
    for (int i = 1; i < n; i++)
    {
        // Iterate all the given edges...
        for (auto it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            // check the min_distance condition...
            if (min_dis[u] + wt < min_dis[v])
            {
                min_dis[v] = min_dis[u] + wt;
            }
        }
    }

    vector<int> ans(n + 1, 1e8); // Just to return empty vector in case of negative cycle presesnt

    // 2. Additonal Condition check If There exist any negative Cycles...
    for (auto it : edges)
    {
        int u = it[0], v = it[1], wt = it[2];
        // check the min_distance condition...
        if (min_dis[u] != 1e9 && (min_dis[u] + wt < min_dis[v]))
        {
            return ans; // If the above Condition True, Negative cycle exists..
        }
    }

    return min_dis;
}
/*
Approach: TC -> O(m*n) [For n-1 times i am visiting all the m edges]
Implementation:
   NOTE:
   -- You dont need adjList for Bellman Ford Algorithm. You need the edges and it's respective weights.
   -- You need to maintain a Vector to keep track of shortest Distance i.e dis vector. Initialize with Inf i.e INT_MAX, excpet for src Node -> 0
Steps:
   1) If there are N Nodes, You need to Check the below n-1 Times...
      -- For All the edges eg: u ---wt---> v
         if(dist[u] + wt < dist[v]) -> Update the dis[v] = dist[u] + wt;
      [** DONE-> you found the MinDist form Src to all Other Nodes]
   2) To check if There exist a Negative cycle in the Grpah.
      -- Run the above check one more time, If any dis is updating, There exist a negative Cycle, So valid Shortest path won't exist.
*/