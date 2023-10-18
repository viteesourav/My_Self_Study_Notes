// Link:https://www.codingninjas.com/studio/problems/minimum-spanning-tree_631769?leftPanelTab=0
/*
    Given a Graph, from ndoes 0 to N-1. Find the MST edge weight of the given Graph using khruskal's Algo.
*/
#include <bits/stdc++.h>
using namespace std;

// create Dis-joint set..
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    // initialise the parent and rank..
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Algo to find a Parent of a node..
int findParent(int node, vector<int> &parent)
{
    // check if the node's parent is itself..
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent[node], parent); //** Path Compression Algorithm
}

// Algo to merge 2 nodes..
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    // step1: Find the parent of u and v node...
    u = findParent(u, parent);
    v = findParent(v, parent);

    // step2: Compare the rank of both the parents...
    if (rank[u] == rank[v])
    {
        parent[v] = u; // assign u as the parent of v.
        rank[u]++;     // increment the rank of u
    }
    else if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
}

// custom Sort bool compare to sort the edges based on weights...
bool compare(vector<int> &v1, vector<int> &v2)
{
    return v1[2] < v2[2]; // edge weights at index 2.
}

// Approach: Kruskal's Algo + Dis-joint Sets
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    // first we will crate a disjoint-set..
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    // Krushal's Algorithm...
    // step1: Need a sorted based on edge-wigths..
    sort(edges.begin(), edges.end(), compare);

    int totalMSTweight = 0; // keep track of MST weights..

    // iterate all the nodes..
    for (auto it : edges)
    {
        int u = it[0], v = it[1], wt = it[2];

        // 1. findparent of the nodes..
        u = findParent(u, parent);
        v = findParent(v, parent);

        // 2. check for if both parents are not same...[only process if they have different parent]
        if (u != v)
        {
            totalMSTweight += wt; // Add the edge weights.
            unionSet(u, v, parent, rank);
        }
    }

    return totalMSTweight;
}
/*
Appraoch: Khruskal's algo [TC: O(nlogn) [we are using sort algo to sort the edges] SC: O(N)]
   -- WE need a linear DS, that stores the [edge_weight, u, v] in ascending Order i.e [The elements should be sorted based on their edge weight]
   -- Implement the Dis-joint sets Operation:
      -- DS Needed: Parent vector + Rank Vector
      -- Implement Operations for Dis-joint set:
        1) findParent: [Recursion + use Path compression Algorithm for efficient Approach]
        2) unionSet: [merge 2 nodes, based on their parent's Rank]
   -- Now Run a loop, till we process all the edges,
      1. Find parent of u and v. [use findParent()]
      Case:
         1) If same Parent: They belong to the same MST. [ignore]
         2) If different Parent: Merge both of them using unionSet()
   -- Keep track of the weights while merging 2 nodes.
   -- At the end you will have the Final MST edge wight for the Given Graph [** DONE **]
*/