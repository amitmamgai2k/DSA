#include <iostream>
#define INF 999999 // Represents infinity for unreachable paths
using namespace std;
struct Edge {
    int src, dest, weight;
};
// Function to perform Dijkstra's Algorithm
void dijkstra(int graph[100][100], int vertices, int source) {
    int dist[100]; // Distance array to store shortest path from source
    bool visited[100]; // Visited array to mark processed vertices
    // Initialize distances as "infinity" and visited as false
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[source] = 0;
    // Main Dijkstra loop
    for (int i = 0; i < vertices - 1; i++) {
        // Find the minimum distance vertex from unprocessed vertices
        int minDist = INF, u = -1;
        for (int j = 0; j < vertices; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        visited[u] = true; // Mark the picked vertex as processed
        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " \t " << (dist[i] == INF ? "INF" : to_string(dist[i])) << "\n";
    }
}
// Helper function for Kruskal's Algorithm: Find set of element i
int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}
// Helper function for Kruskal's Algorithm: Union of two sets
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}
// Function to perform Kruskal's Algorithm
void kruskal(int V, int E, Edge edges[]) {
    // Sort edges by weight using simple bubble sort
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    int parent[100], rank[100];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    Edge mst[100]; // Array to store MST edges
    int mstWeight = 0;
    int mstIndex = 0;
    for (int i = 0; i < E && mstIndex < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int setU = find(parent, u);
        int setV = find(parent, v);
        // If including this edge doesn't form a cycle, include it in MST
        if (setU != setV) {
            mst[mstIndex++] = edges[i];
            mstWeight += edges[i].weight;
            unionSets(parent, rank, setU, setV);
        }
    }
    cout << "Edges in Minimum Spanning Tree:\n";
    for (int i = 0; i < mstIndex; i++) {
        cout << mst[i].src << " -- " << mst[i].dest << " == " << mst[i].weight << endl;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    int adjMatrix[100][100]; // Adjacency matrix for Dijkstra's algorithm
    Edge edges[100]; // Edge list for Kruskal's algorithm

    // Initialize adjacency matrix with 0 (no edge)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter each edge as source, destination, and weight:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // For undirected graph
        edges[i] = {u, v, w}; // Store the edge for Kruskal's
    }
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Dijkstra's Shortest Path\n";
        cout << "2. Kruskal's Minimum Spanning Tree\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int source;
            cout << "Enter source vertex for Dijkstra's Algorithm: ";
            cin >> source;
            dijkstra(adjMatrix, V, source);
            break;
        }
        case 2:
            kruskal(V, E, edges);
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 3);
    return 0;
}
