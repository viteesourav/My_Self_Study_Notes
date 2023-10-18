/*
Implement a Directed weighted Graph. Take the 0 as the source Node and find minDistance to all other Nodes..
*/

#include <bits/stdc++.h>
using namespace std;

// Defining a class for the directed Graph..
class Graph
{

    int totalNodes;
    unordered_map<int, list<pair<int, int>>> adjList; // Represent the Graph...

public:
    // constructor to set total Nodes..
    Graph(int n)
    {
        totalNodes = n;
    }

    // method to add edges in the Graph...
    void addEdges(int u, int v, int wt)
    {

        adjList[u].push_back(make_pair(v, wt));
    }

    // method to display the adjList for the Graph...
    void printGraph()
    {
        for (auto node : adjList)
        { // Iterate the adjList Map...
            cout << node.first << "-> ";
            for (auto it : node.second)
            { // Iterate the list of Pairs for each key Node..
                cout << "[" << it.first << " " << it.second << "]"
                     << ", ";
            }
            cout << endl;
        }
    }

    // Method to do the DFS Topology [Recursive]
    void do_dfs_topology(int currNode, stack<int> &st, unordered_map<int, bool> &isVisited)
    {

        // mark the currNode as visited...
        isVisited[currNode] = true;

        // Iterate all the linked Nodes, and if the node is not visited, recursive call...
        for (auto it : adjList[currNode])
        {
            if (!isVisited[it.first])
            { // if the node is not visited...
                do_dfs_topology(it.first, st, isVisited);
            }
        }

        // while coming back, store the node in the stack..
        st.push(currNode);
    }

    // find shortest path to all Nodes from s [source] Node
    unordered_map<int, int> find_minDis(int s)
    {

        // 1. initialise the min_dis with all Nodes INT_MAX
        unordered_map<int, int> min_dis; // stores the min distance..
        for (int i = 0; i < totalNodes; i++)
            min_dis[i] = INT_MAX;

        min_dis[s] = 0; // Start with putting min_dis of source to 0.

        // 2. find the DFS Topology stack...
        stack<int> st;
        unordered_map<int, bool> isVisited;

        do_dfs_topology(s, st, isVisited);

        // 3. Now we process the stack...
        while (!st.empty())
        {

            int topNode = st.top(); // Pop the top Node...
            st.pop();

            if (min_dis[topNode] != INT_MAX)
            { // we can process if it's not infinity..

                // iterate all the Linked Nodes for the topNode...
                for (auto it : adjList[topNode])
                {
                    if (min_dis[topNode] + it.second < min_dis[it.first])
                    {                                                     // if new distance < exisiting dis..
                        min_dis[it.first] = min_dis[topNode] + it.second; // update the distance..
                    }
                }
            }
        }
        return min_dis;
    }
};

int main()
{

    Graph gh(5);

    gh.addEdges(0, 1, 5); // addEdges(u, v, wt of u-v edge)
    gh.addEdges(0, 2, 3);
    gh.addEdges(1, 3, 3);
    gh.addEdges(2, 1, 2);
    gh.addEdges(2, 3, 5);
    gh.addEdges(2, 4, 6);
    gh.addEdges(4, 3, 1);

    gh.printGraph(); // we have the adj List now...
    cout << endl;

    int sourceNode = 0;
    unordered_map<int, int> min_dis = gh.find_minDis(sourceNode);

    cout << "Printing the minDistace of Other Nodes from Source Node: " << endl;
    // Print min_dis to all the Ndoes..
    for (auto it : min_dis)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}

/*
Approach: Topology DFS Stack + MinDistance Calculation

source -> 0, destination -> 3

//AdjList:
0 - [1 5], [2 3]
1 - [3 3]
2 - [1 2], [3 5], [4 6]
3 - x
4 - [3 1]

//find the DFS Topolgy stack...
Topology DFS stack s-> 3 1 4 2 0

//pop the stack and process the minDis Map [Maintain a unorderedmap for tracking the minDistance from source Node.]
//minDis[source] = 0
//minDis[destNode] = if(minDis[s] + edgeDis < minDis[destNode]) --> minDis[destNode] = minDis[s] + edgeDis

            0   1    2    3    4
minDis ->  0  Inf  Inf  Inf  Inf
 s-> 0	       5    3
 s-> 2         5    3    8    9
 s-> 4         5    3    8    9
 s-> 1         5    3    8    9
 s-> 3         5    3    8    9


//You have the minDis for all the Nodes from the Source Node i.e minDis from s= 0 to all other Nodes.
For source at 0:

                0 1 2 3 4
Final minDis -> 0 5 3 8 9

[** DONE **]
*/