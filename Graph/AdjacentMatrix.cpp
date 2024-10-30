#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &mat, int i, int j, bool directed) {
    mat[i][j] = 1;
    if (!directed) {
        mat[j][i] = 1; // Only add reverse edge if undirected
    }
}

void displayMatrix(const vector<vector<int>> &mat) {
    int V = mat.size();
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
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

    // Create an n x n matrix initialized to 0 (no edges)
    vector<vector<int>> mat(n, vector<int>(n, 0));

    // Add edges based on user input
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(mat, u, v, directed);
    }

    cout << "Adjacency Matrix Representation:" << endl;
    displayMatrix(mat);

    return 0;
}
