#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>>& adjList, int u, int v, bool directed) {
    adjList[u].push_back(v);
    if (!directed) {
        adjList[v].push_back(u); // Add back edge for undirected graph
    }
}

void BFS(const vector<vector<int>>& adjList, int start) {
    int n = adjList.size();
    vector<bool> visited(n, false); // Track visited nodes
    queue<int> q;                    // Queue for BFS traversal

    // Start BFS from the given start node
    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting from node " << start << ": ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Visit all neighbors of the current node
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
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

    vector<vector<int>> adjList(n);

    // Add edges based on user input
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(adjList, u, v, directed);
    }

    int start;
    cout << "Enter the starting node for BFS: ";
    cin >> start;
    BFS(adjList, start);

    return 0;
}
