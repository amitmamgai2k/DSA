#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;     // To store the root parent of each element
vector<int> rankArray;  // To store the rank of each element

// Initialize the Disjoint Set with `n` elements
void initialize(int n) {
    parent.resize(n);
    rankArray.resize(n, 0); // Initially, all ranks are 0
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each element is its own parent
    }
}

// Find function with path compression
int find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]); // Path compression
    }
    return parent[u];
}

// Union function with union by rank
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    // Only union if `u` and `v` are in different sets
    if (rootU != rootV) {
        // Union by rank
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

// Utility function to check if two nodes are in the same set
bool isConnected(int u, int v) {
    return find(u) == find(v);
}

int main() {
    int n = 5; // Number of elements
    initialize(n);

    // Union some pairs of elements
    unionSets(0, 1);
    unionSets(1, 2);
    unionSets(2,3);
    unionSets(3, 4);

    // Check connectivity
    cout << "Is 0 connected to 2? " << (isConnected(0, 2) ? "Yes" : "No") << endl;
    cout << "Is 0 connected to 4? " << (isConnected(0, 4) ? "Yes" : "No") << endl;

    // Output the representative of each element
    for (int i = 0; i < n; i++) {
        cout << "Parent of " << i << " is: " << find(i) << endl;
    }

    return 0;
}
