// Link: https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_1062670
/*
You given a undirected, possible disconnected Graph with N Vertex and m Edges, Also Given All Nodes-edge Links.
    Find if there exist any cycles in any component of the Given Graph.

eg:        1 - 2       4 - 5 - 6
               |           |   |
               3           7 - 8 - 9

    -- Here a cycle exists in the Node 5-6-7-8.
*/

#include <bits/stdc++.h>
using namespace std;

// Utitlity Fucntio to prepare the adj List...
void createAdjList(unordered_map<int, set<int>> &adjList, vector<vector<int>> &edges, int m)
{

    // iterate the edges and push in the map..
    for (auto it : edges)
    {
        int u = it[0], v = it[1];

        adjList[u].insert(v);
        adjList[v].insert(u); // since, It's an undirected graph
    }
}

// BFS Traveral with cycle detection Logic: [using queue]
bool do_bfs(int vertex, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &isVisited, unordered_map<int, int> &parentNodeMap)
{

    queue<int> qt; // we use a queue in BFS Traveral..

    // lets push the first element in queue and update: isVisited and parentNodeMap
    qt.push(vertex);
    isVisited[vertex] = true;
    parentNodeMap[vertex] = -1;

    // Loop till we have the queue empty ?
    while (!qt.empty())
    {

        // pop the front Node...
        int frontNode = qt.front();
        qt.pop();

        // Now push the Nodes attached to frontNode from the adjList..
        for (auto Node : adjList[frontNode])
        {
            if (!isVisited[Node])
            { // If the Node is not Visited yet, push it, update isVisited & parentNodeMap
                qt.push(Node);
                isVisited[Node] = true;
                parentNodeMap[Node] = frontNode;
            }
            else
            {
                // If the Node is already Visited -> check if that is not the parent Node of frontNode..
                if (parentNodeMap[frontNode] != Node)
                    return false;
            }
        }
    }
    return true; // If the Queue is getting empty at the end, No Loops Present.
}

// Solution with BFS Traversal..
string solve1(vector<vector<int>> &edges, int n, int m)
{
    string ans;

    // First lets have the required:
    unordered_map<int, set<int>> adjList;  // Create the adj List from the given node-edge Details
    unordered_map<int, bool> isVisited;    // checks if a Node is Already Visited ?
    unordered_map<int, int> parentNodeMap; // Keeps track of parent of the curr Node.

    // Create the adj List...
    createAdjList(adjList, edges, m);

    // It's a disconnected Graph, we need to cover all the Vertex from 1 to N
    for (int vertex = 1; vertex <= n; vertex++)
    {
        if (!isVisited[vertex])
        {                                                                     // If a node is not visited...
            bool isCycle = do_bfs(vertex, adjList, isVisited, parentNodeMap); // checks if cycle exists ?
            if (!isCycle)
                return "Yes"; // If exist, return Yes
        }
    }
    return "No"; // If the above loop completed i.e No Cycles exist.
}

// DFS Traveral with cycle detection Logic: [using Recursion]
bool do_dfs(int vertex, int parentNode, unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &isVisited, unordered_map<int, int> &parentNodeMap)
{

    // First we process the vertex...
    isVisited[vertex] = true;
    parentNodeMap[vertex] = parentNode;

    // Now for each of the Nodes in adjList for the vertex, process them Recursive...
    for (auto node : adjList[vertex])
    {
        if (!isVisited[node])
        {                                                                           // if Not visited...
            bool isCycle = do_dfs(node, vertex, adjList, isVisited, parentNodeMap); // node will be the vertex and vertex will become parent...
            if (!isCycle)                                                           // if any cycle exists, retrun false...
                return false;
        }
        else
        {
            // If its already Visted..check if the parent of Node is other than vertex...
            if (parentNodeMap[vertex] != node)
            {
                return false;
            }
        }
    }
    return true; // If loop over successfully, there is no cycle.
}

// Solution with DFS Traversal..
string solve2(vector<vector<int>> &edges, int n, int m)
{
    string ans;

    // First lets have the required:
    unordered_map<int, set<int>> adjList;  // Create the adj List from the given node-edge Details
    unordered_map<int, bool> isVisited;    // checks if a Node is Already Visited ?
    unordered_map<int, int> parentNodeMap; // Keeps track of parent of the curr Node.

    // Create the adj List...
    createAdjList(adjList, edges, m);

    // It's a disconnected Graph, we need to cover all the Vertex from 1 to N
    for (int vertex = 1; vertex <= n; vertex++)
    {
        if (!isVisited[vertex])
        {                                                                         // If a node is not visited...
            bool isCycle = do_dfs(vertex, -1, adjList, isVisited, parentNodeMap); // Note: For First Node, Parent we default it to -1.
            if (!isCycle)
                return "Yes"; // If exist, return Yes
        }
    }
    return "No"; // If the above loop completed i.e No Cycles exist.
}

// Appraoch: Graph Traveral(BFS/DFS) + Map to Track the Parent Nodes...
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{

    // return solve1(edges, n, m); //Solve using BFS Travesal..

    return solve2(edges, n, m); // Solve using DFS Travesal..
}

/*
Logic:
    -- We will use Both Traversal and ParentMap Track to Solve this.
     Case:
         1) If the Node is Visted Already and it's a parent of the current node in the map, Ignore the Node.
         2) If the Node is Visted but Node is not the parent of the current Node, Cycle exists. [**IMP**]

    1) BFS:
        -- Required:
            1) An Adjacent List for all the Nodes of the Graph.
            2) A isVisted Map for Keep track of visted Nodes.
            3) A Queue to Process the Nodes.
            4) A ParentMap to track the Parent of any Nodes
        NOTE: For Node's whose Parent Don't exist, we can put -1 as it's PArent Node.
** Taking eg of the above and dry Run: [BFS Traveral]
    1 - 2
    2 - 1, 3
    3 - 2
    4 - 5
    5 - 4, 6, 7
    6 - 5, 8
    7 - 5, 8
    8 - 6, 7, 9
    9 - 8

    isVisted:

    1 - T
    2 - T
    3 - T
    4 - T
    5 - T
    6 - T
    8 - T
    7 - T -> Here when it try to check for Node 5

    parentMap:

    1 -> -1
    2 -> 1
    3 -> 2
    4 -> -1
    5 -> 4
    6 -> 5
    8 -> 6
    7 -> 8

    => Node 5 is already visted and parent of 7 is 8, Thus, A cycle exists

    2) DFS:
        -- Required:
            1) An Adjacent List for all the Nodes of the Graph.
            2) A isVisted Map for Keep track of visted Nodes.
            3) A Recursive Function, to Traverse all the Nodes, One by one and return if there exisit a cycle or Not..
            4) A ParentMap to track the Parent of any Nodes
        NOTE: For Node's whose Parent Don't exist, we can put -1 as it's PArent Node.
*/