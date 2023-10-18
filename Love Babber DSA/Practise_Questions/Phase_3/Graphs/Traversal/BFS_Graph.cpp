// Link: https://www.codingninjas.com/studio/problems/bfs-in-graph_973002
/*
Given a Graph, with the total number of vertexs and the adjacent List, Do the BFS Traversal...
NOTE:
    1) It is not a disconnected Graph [So, No need to iterate all the Vertex], It is also a directed graph.
    2) ADjacent List for Nodes and Edges. [Already Given in the Question]
    3) isVisted Map
    4) A Queue to process all the Nodes.
*/

#include <bits/stdc++.h>
using namespace std;

// utilityFun to create the adjacentEdgeMap... [NOT Needed, Already Given in the Question]
//  void createAdjacentMap(unordered_map<int, list<int>>& adjacentNodesMap, vector<vector<int>>& adj) {

//     //iterating the given Node-edges Links..
//     for(int i=0; i< adj.size(); i++) {
//         int u = adj[i][0], v = adj[i][1];
//         // cout<<u<<" "<<v<<endl;

//         //push in the adjacentNodesMap...
//         adjacentNodesMap[u].push_back(v); //directed_graph...
//     }
// }

// utlity fun to run bfs from the starting Node...
void bfs(int vertex, vector<vector<int>> &adj, unordered_map<int, bool> &vistedNodes, vector<int> &ans)
{

    queue<int> qt;

    // push the vertex in the queue and mark the vertex as visted...
    qt.push(vertex);
    vistedNodes[vertex] = true;

    // Now loop till queue is empty...
    while (!qt.empty())
    {
        // Pop the front element from Queue...
        int ele = qt.front();
        qt.pop();
        ans.push_back(ele); // push the popped node in the ans...

        // Iterate all the adjacent Nodes in for the poped Node and push in queue..
        for (auto it : adj[ele])
        {
            // check if it's already visted or not ?
            if (!vistedNodes[it])
            {
                qt.push(it);            // push the Node in the queue...
                vistedNodes[it] = true; // Mark the Node pushed in Queue as visited..
            }
        }
    }
}

// Appraoch: adjacentListMap + vistiedNodesMap + Queue... TC: O(n+m) SC: O(n+m)
vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int> ans;

    // unordered_map<int, list<int>> adjacentNodesMap; //NOTE: Not needed in this question..
    unordered_map<int, bool> visitedNodes;

    // NOTE: Not needed as, in the question already adjVector List we have...
    // Create the adjacentNodesMap from the given adjacentEdges...
    //  createAdjacentMap(adjacentNodesMap, adj);

    // iterate all the Nodes for the graph...[Not Needed as, This is not a disconnected Graph]
    // NOTE: Here Loop make sure, All Nodes from 0 to n are traversed atleast once..
    //  for(int i=0; i<n; i++) {
    //      //check if the node is already visted or not ?
    //      if(!visitedNodes[i]) {
    //          bfs(i, adj, visitedNodes, ans);
    //      }
    //  }

    bfs(0, adj, visitedNodes, ans);

    return ans;
}

/*
Logic:
    -- You start with the first Node, Print the Node, Push adjacent Node in the Queue, then take out the first NOde and Repeat the Procee till Queue is empty.
    NOTE: If disconnected Graph, Run a loop to cover all the Nodes.

Appraoch: TC: O(n+m) SC:O(n+m) [n is number of Nodes, m is number of edges]
    Step1: If not given, Prepare a adjacent List using map or if Nodes are int, You can use 2-D Vector to store the Nodes and edges.
    Step2: Prepare a isVisited Map for all the Nodes, to keep Track.
    Step3: Insert the first node in the Queue, Mark the Node as Visited.
        -- Till the Queue is Empty, Pop the front Node, print it, Push it's adjacent Nodes in the Queue.
    **DONE**
*/
