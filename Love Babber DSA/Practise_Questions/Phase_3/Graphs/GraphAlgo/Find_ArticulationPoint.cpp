// Link: https://www.codingninjas.com/studio/problems/articulation-point_840708?leftPanelTab=0
/*
Given a undirected Graph, With the number of vertices and all the edges. Print all Articulation Point.
NOTE: Articualtion Point:
    -- Nodes which if removed, creates components in the Graph.
*/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<int, list<int>> adjList;

public:
    // Method to add edges to the graph...
    void addEdges(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printEdges()
    {
        for (auto it : adjList)
        {
            cout << it.first << " -> ";
            for (auto pt : it.second)
            {
                cout << pt << " ";
            }
            cout << endl;
        }
    }

    // Utility Method: To Perform DFS Traversal, and check for Articulation points..
    void do_dfs(int node, int parentNode, int &timer, vector<int> &discTime, vector<int> &low,
                unordered_map<int, bool> &isVisited, set<int> &articulateList)
    {

        // 1. Mark the node as visited and update it's discTime and low..
        isVisited[node] = true;
        discTime[node] = low[node] = timer++; // update discTiem and low and upadte the timer...

        int childCount = 0; // keep Track of child of node..

        // 2. iterate all the adjacent Nodes from adjList..
        for (auto neighbour : adjList[node])
        {
            if (neighbour == parentNode)
            { // If neighbour is the parent Node, SKip it.
                continue;
            }

            if (!isVisited[neighbour])
            { // If neighbour is not visited...
                childCount++;
                do_dfs(neighbour, node, timer, discTime, low, isVisited, articulateList);
                // while BackTracking...
                low[node] = min(low[node], low[neighbour]); // update low of node, in case neighbour Node has any backEdges.
                // check If node is a articulate point or not ?
                if (low[neighbour] >= discTime[node] && parentNode != -1)
                {
                    articulateList.insert(node);
                }
            }
            else
            {
                // If neighbour is already Visited i.e Back Edge Case...
                low[node] = min(low[node], discTime[neighbour]); // upadte the low of current Node...
            }
        }

        // 3.ExtraCase: Check if the source Node is Articulate point or not ?
        if (parentNode == -1 && childCount > 1)
        {
            articulateList.insert(node);
        }
    }

    // Appraoch: DFS + discoveryTime + lowDiscoveryTime Approach...
    void find_ArticulateNodes(set<int> &articulateList, int totalNodes)
    {
        // Initialize the needed DS:
        // Note: Nodes starts from 1 to N, thus we have extended Index of vector.
        vector<int> discTime(totalNodes + 1, -1);
        vector<int> low(totalNodes + 1, -1);
        unordered_map<int, bool> isVisited;

        // Initialize with the timer to count from the Node 1.
        int timer = 0;

        // perform DFS Travesal...
        for (int node = 1; node <= totalNodes; node++)
        { // cover all the Nodes...
            if (!isVisited[node])
            {
                do_dfs(node, -1, timer, discTime, low, isVisited, articulateList);
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n, m;
        cin >> n >> m;

        Graph gh;

        // step1: Create the adjList for the Given Graph...
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            gh.addEdges(u, v);
        }

        // gh.printEdges();

        set<int> articulateList; // List all the Articulate points in Ascending order...

        // Step2: Call the method, store in Set [To have sorted order of Nodes]
        gh.find_ArticulateNodes(articulateList, n); // Method to find Articulate points.

        for (auto it : articulateList)
        {
            cout << it << " ";
        }
        cout << endl;

        t--;
    }
    return 0;
}
/*
Approach: DiscTime + low + isVisited [TC, SC: Linear]
-- DS Needed:
    1) discTime: vector/map, keep tracks of the maxTime needed to Reach a particular Node.
    2) low: vector/map, keep tracks of the miniTime needed to Reach a particular Node.
    3) isVisited: A Map to keep Track, if a node is visited or not.

Logic:
   -- You Do a noraml DFS in the given Graph, maintain a timer, update the timer everytime You visit a new Node.
   -- Also maintain the track of the parent Node.
   -- Update the same in the DiscovertTime DS, and LowDiscoveryTime DS, incement the timer.
   -- Keep track of child for this node.
   -- Iterate all the adjList Nodes for the currNode.
      -- If the node is parent of a currNode -> ignore it.
      -- If the node is Visited but not a parent. i.e Back Edge Condition.[IT means there exisit another path to reach the node, which dont include the currNode]
         -- In this case update the low[currNode] = min(low(node), DiscovertTime(neighbour))
      -- While returning back, 2 Things:
         1) Update the low for the neighbour node: low[neighbour] = min(low(node), low(neighbour)) [the neighbour might form a backedge, thus need to update the low for this node too]
         2) check for Articulation condition: low[neighbour] >= DiscovertTime[node] && parent != -1
            -- If true Node is a Articualate Point, add the node in the Articulate Point List.
         Reason:  This works because, This condition means there exist only one path to the node. If there exisit another path, low would be less.
   -- Check if the node is sorce Node i.e parent is -1 and it's child count > 1
      -- Include source Node in the Articulation Point array.

*/