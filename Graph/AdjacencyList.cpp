#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>>& adjList, int u, int v, bool directed) {
    adjList[u].push_back(v);
    if (!directed) {
        adjList[v].push_back(u); // Add back edge for undirected graph
    }
}

void display(const vector<vector<int>>& adjList, int n) {
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    bool directed;

    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> directed;

    // Initialize an adjacency list with 'n' empty vectors
    vector<vector<int>> adjList(n);

    // Add edges based on user input
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(adjList, u, v, directed);
    }

    cout << "Adjacency List Representation:" << endl;
    display(adjList, n);

    return 0;
}
