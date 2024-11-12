#include <iostream>
#include <cstdlib>
using namespace std;
// Node structure for linked list (used in adjacency list and queue)
struct Node {
    int data;
    Node* next;
};
// Global variables for graph representation
int numVertices;
Node** adjLists; // Adjacency list
bool* visited;   // Visited array for DFS and BFS
// Function to create and add an edge to the adjacency list
void addEdge(int u, int v) {
    // Add edge u -> v
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = adjLists[u];
    adjLists[u] = newNode;
    // Since the graph is undirected, add edge v -> u
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = u;
    newNode->next = adjLists[v];
    adjLists[v] = newNode;
}
// Queue functions for BFS
Node* queueFront = nullptr;
Node* queueRear = nullptr;
void enqueue(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = nullptr;

    if (queueRear == nullptr) {
        queueFront = queueRear = temp;
    } else {
        queueRear->next = temp;
        queueRear = temp;
    }
}
int dequeue() {
    if (queueFront == nullptr) {
        return -1;
    }
    int value = queueFront->data;
    Node* temp = queueFront;
    queueFront = queueFront->next;
    if (queueFront == nullptr) {
        queueRear = nullptr;
    }
    free(temp);
    return value;
}
// BFS function
void BFS(int start) {
    // Reset visited array
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
    enqueue(start);
    visited[start] = true;
    cout << "BFS traversal starting from node " << start << ": ";
    while (queueFront != nullptr) {
        int node = dequeue();
        cout << node << " ";
        // Visit all neighbors
        Node* temp = adjLists[node];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(adjVertex);
            }
            temp = temp->next;
        }
    }
    cout << endl;
}
// DFS utility function (recursive)
void DFSUtil(int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";
    Node* temp = adjLists[vertex];
    while (temp) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex);
        }
        temp = temp->next;
    }
}
// DFS function
void DFS(int start) {
    // Reset visited array
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
    cout << "DFS traversal starting from node " << start << ": ";
    DFSUtil(start);
    cout << endl;
}
int main() {
    int m;
    cout << "Enter the number of nodes: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> m;
    // Allocate memory for adjacency list and visited array
    adjLists = (Node**)malloc(numVertices * sizeof(Node*));
    visited = (bool*)malloc(numVertices * sizeof(bool));
    // Initialize adjacency list and visited array
    for (int i = 0; i < numVertices; i++) {
        adjLists[i] = nullptr;
        visited[i] = false;
    }
    // Add edges based on user input
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(u, v);
    }
    int start, choice;
    cout << "Enter the starting node for BFS and DFS: ";
    cin >> start;
    do {
        cout << "\nSelect Traversal:\n";
        cout << "1. Breadth First Search\n";
        cout << "2. Depth First Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                BFS(start);
                break;
            case 2:
                DFS(start);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Choose a correct option.\n";
        }
    } while(choice != 3);
    // Free allocated memory
    for (int i = 0; i < numVertices; i++) {
        Node* temp = adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(adjLists);
    free(visited);

    return 0;
}
