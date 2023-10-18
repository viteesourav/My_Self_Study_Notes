// Link: https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_920545%20
/*
Given a Graph, Which is directed. Find if there exist any cycles in the Graph.
*/
#include <bits/stdc++.h>
using namespace std;

// utility Fun to create the adjList...
void createAdjList(unordered_map<int, set<int>> &adjList, vector<vector<int>> &edges, int e)
{
    // Traverse the edges and push in the adjList Map..
    for (auto it : edges)
    {
        int u = it[0], v = it[1];

        adjList[u].insert(v); // Since directed graph..
    }
}

// dfs Function [REcursive]
bool dfs_traversal(int vertex, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &isVisited, unordered_map<int, bool> &dfs_map)
{
    // First mark the incoming Node..
    isVisited[vertex] = true;
    dfs_map[vertex] = true;

    // Now iterate all the nodes for the incoming vertex
    for (auto node : adjList[vertex])
    {
        if (!isVisited[node])
        { // If the node is not visited yet..
            bool isCycle = dfs_traversal(node, adjList, isVisited, dfs_map);
            if (isCycle)
                return true;
        }
        else
        {
            // If the node is visited, check for dfs_map...
            if (dfs_map[node])
                return true;
        }
    }
    dfs_map[vertex] = false; // while done with the dfs_function, unmark the node..

    return false; // If we are done with the above, No Cycle present till vertex Node.
}

// Appraoch: using DFS Traversal...
bool solve1(vector<vector<int>> &edges, int v, int e)
{

    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> isVisited;
    unordered_map<int, bool> dfs_map; // Keep track of the Nodes, moving in-out of the dfs Recursive call.

    // create the adjList..
    createAdjList(adjList, edges, e);

    // We need to cover all the nodes..[0 to v-1]
    for (int vertex = 0; vertex < v; vertex++)
    {
        if (!isVisited[vertex])
        {
            bool isCycle = dfs_traversal(vertex, adjList, isVisited, dfs_map);
            if (isCycle)
            { // If the cycle present..
                return true;
            }
        }
    }
    return false; // If the above loop completed, we have no cycles present.
}

// Appraoch2: Solve using BFS Traversal + Kahn's Algorithm...
bool solve2(vector<vector<int>> &edges, int v, int e)
{

    // lets prepare the adjList...
    unordered_map<int, set<int>> adjList;
    // create the adjList..
    createAdjList(adjList, edges, e);

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

    int cntTotalNodes = 0;

    // 4. Till the Queue is empty, we process...
    while (!qt.empty())
    {
        // Let's pop the front and store in the ans..
        int ele = qt.front();
        qt.pop();

        cntTotalNodes++; // Count the Nodes poping...

        for (auto node : adjList[ele])
        {
            inDeg[node]--;
            if (inDeg[node] == 0)
                qt.push(node);
        }
    }

    // If the total Number of Nodes in Kahn's is not equal to number of vertex, cycle exists
    if (cntTotalNodes != v)
    {
        return true;
    }

    return false; // If we get a valid topology sort, No Cycle present.
}

bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    // return solve1(edges, v, e); // Using DFS Traveral..
    return solve2(edges, v, e); // Using BFS Traveral..
}

/*
Approach:
    1) Using DFS Traversal:  TC, SC: O(m+n) [Node+ edges] [Linear]
        -- We use an bool Map, to keep track of Nodes which are going in-out of the dfs Recusrive call Stack.
        -- Any Node, which is already Visited and also inside the dfs recursive call stack, -> This present a cyclic condition.
    WE need:
        1) AdjList for all the Nodes-edges. [If given in question fine, else prepare it]
        2) A bool map to keep track of visited Nodes.
        3) A bool map to keep track of Nodes going in-out of the dfs_recursive call stack.
        4) A bool dfs recursive Function,
            -- Mark the incoming Node as visited, and also dfs_map as true.
            -- For all the Nodes linked to incoming Node
                -> If the node is not visited, call the bool dfs recursive function -> If this returns false, return false.
                -> If the node is visited and dfs_map is true -> return true [Cycle present]
    [**DONE**]

    2) Using BFS Traversal: [using kahn's Algorithm]
        -- Prepare the adjList Map for the Given Graph.
        -- Prepare a map for the in-degree for all the nodes.
        -- Push all the Nodes with 0 deg in the Queue.
        -- Take a Node Count = 0
        -- Till Queue is empty:
            -- Pop the front Node, increment the count.
            -- Update the in-deg for all the linked Nodes for the front node in adjList.[invalid Topology Sort]
            -- decrement them by 1, if it becomes 0, push them in the queue. [valid topology Sort]
        -- At end,
            check if Node Count is not equal to the total vertex -> Cycle exist. []
            Else Cycle doesn't exist.

*/