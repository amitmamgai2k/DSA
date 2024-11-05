#include <bits/stdc++.h>
using namespace std;

void AddEdge(vector<vector<pair<int,int>>>& adj, int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}

vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int start) {
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;
    set<pair<int,int>> st;
    st.insert({0, start});

    while (!st.empty()) {
        auto top = st.begin();
        int topNode = top->second;
        st.erase(top);

        for (auto neighbour : adj[topNode]) {
            int neighbourNode = neighbour.first;
            int neighbourWeight = neighbour.second;

            if (dist[topNode] + neighbourWeight < dist[neighbourNode]) {
                st.erase({dist[neighbourNode], neighbourNode});
                dist[neighbourNode] = dist[topNode] + neighbourWeight;
                st.insert({dist[neighbourNode], neighbourNode});
            }
        }
    }
    return dist;
}

vector<int> parent, rankArray;

void initialize(int n) {
    parent.resize(n);
    rankArray.resize(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

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

bool compareEdges(const vector<int>& edge1, const vector<int>& edge2) {
    return edge1[2] < edge2[2];
}

vector<vector<int>> kruskalMST(int V, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    initialize(V);
    vector<vector<int>> mst;
    
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        if (find(u) != find(v)) {
            mst.push_back(edge);
            unionSets(u, v);
        }
    }
    return mst;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);
    vector<vector<int>> edges;

    cout << "Enter edges (u v weight): " << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
        AddEdge(adj, u, v, weight);
    }

    int choice;
    cout << "Choose an algorithm:\n1. Dijkstra\n2. Kruskal\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int start;
        cout << "Enter starting node for Dijkstra: ";
        cin >> start;

        vector<int> dist = dijkstra(V, adj, start);
        cout << "Distances from starting node " << start << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
        }
    } else if (choice == 2) {
        vector<vector<int>> mst = kruskalMST(V, edges);
        cout << "Edges in the MST:\n";
        int totalWeight = 0;
        for (const auto& edge : mst) {
            cout << edge[0] << " - " << edge[1] << " (Weight: " << edge[2] << ")\n";
            totalWeight += edge[2];
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
