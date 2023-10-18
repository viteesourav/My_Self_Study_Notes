/*
This Shows basic Insert and Printing of a Graph with some Nodes
    Nodes: 5
    edges: 6 [0-1, 0-4, 1-2, 1-3, 2-3, 3-4]
*/

#include <bits/stdc++.h>
using namespace std;

// A class to handle the insert the edges and Nodes and Print the graph.
// NOTE: using a template class, to make the type of the graph is generic...
template <typename T>
class Graph
{

    unordered_map<T, list<T>> adjacentNodeList;
    bool isDirectedGraph;

public:
    // constructor for creating the type for graph...
    Graph(bool isDirectedGraph)
    {
        this->isDirectedGraph = isDirectedGraph;
    }

    // A function to handle insert the edges in the map...
    void addEdges(T u, T v)
    {

        adjacentNodeList[u].push_back(v); // push the node v for adjacent Node of u..

        // check if the graph is unDirected...
        if (!isDirectedGraph)
        {
            adjacentNodeList[v].push_back(u); // push the node u for adjacent Ndoe of v..
        }
    }

    // a Fucntion to print the node and it list of adjacent Nodes, N1 -> N2, N3, N4 [i.e Node 1 is connected to Node 2,3 and 4]
    void printGraph()
    {

        // Iterate the map...
        for (auto it : adjacentNodeList)
        { // Iterate the map, <N1 -> N2, N3, N4>
            cout << it.first << "--->";
            for (auto ele : it.second)
            { // Iterate the List corresponding to each Node..
                cout << ele << ",";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph<int> gh(false); // Creating a un-directed Graph...

    int m, n;
    cout << "Enter the number of Nodes: " << endl;
    cin >> n;
    cout << "Enter the number of Edges: " << endl;
    cin >> m;

    // Accept all the Nodes Edges...
    for (int i = 0; i < m; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        gh.addEdges(node1, node2); // add the Nodes to the graph..
    }

    gh.printGraph(); // print the graph..

    return 0;
}