#include <bits/stdc++.h> 
using namespace std;

//Create AdjacencyList
void AddEdge(vector<vector<pair<int,int>>>&adj,int u,int v,int weight){
    adj[u].push_back({v,weight});
    adj[v].push_back({u,weight});

}
vector<int>dijkstra(int V,vector<vector<pair<int,int>>>&adj,int start){
    //create distance array
    vector<int>dist(V,INT_MAX);
    dist[start] = 0;
    // set to store pairs of (distance,node)
    set<pair<int,int>>st;
    st.insert({0,start});
    while(!st.empty()){
        auto top = st.begin();
        int topNode = top->second;
        st.erase(top);

        // traverse on the all neighbours
        for(auto neighbour:adj[topNode]){
            int NeighBourNode = neighbour.first; 
            int NeighBourWeight = neighbour.second;

            //check if a shorter path to v is found
            if(dist[topNode]+NeighBourWeight<dist[NeighBourNode]){

                // if v is already in the set with an old distance,remove it
                st.erase({dist[NeighBourNode],NeighBourNode})

                //update the distance to this neighbour
                dist[NeighBourNode] = dist[topNode]+NeighBourWeight;
                // Insert the new (distance,node )pair into the set
                st.insert({dist[NeighBourNode],NeighBourNode});

            }

        }
        return dist;
    }

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

// Disjoint set arrays
vector<int> parent, rankArray;

// Initialize disjoint set
void initialize(int n) {
    parent.resize(n);
    rankArray.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// Find function with path compression
int find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);  // Path compression
    }
    return parent[u];
}

// Union function with union by rank
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU != rootV) {
        if (rankArray[rootU] > rankArray[rootV]) {
            parent[rootV] = rootU;
        } else if (rankArray[rootU] < rankArray[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rankArray[rootU]++;
        }
    }
}

// Comparator function to sort edges by weight
bool compareEdges(const vector<int>& edge1, const vector<int>& edge2) {
    return edge1[2] < edge2[2];
}

// Kruskal's MST function
vector<vector<int>> kruskalMST(int V, vector<vector<int>>& edges) {
    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Step 2: Initialize the disjoint set
    initialize(V);

    // Step 3: Construct the MST
    vector<vector<int>> mst;
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // Check if u and v are in different sets
        if (find(u) != find(v)) {
            mst.push_back(edge);  // Add edge to MST
            unionSets(u, v);      // Union the sets
        }
    }
    return mst;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter edges (u v weight): " << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    vector<vector<int>> mst = kruskalMST(V, edges);

    cout << "Edges in the MST:\n";
    int totalWeight = 0;
    for (const auto& edge : mst) {
        cout << edge[0] << " - " << edge[1] << " (Weight: " << edge[2] << ")\n";
        totalWeight += edge[2];
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}

