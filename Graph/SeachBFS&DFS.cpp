#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr; // Front of the queue
Node* rear = nullptr;  // Rear of the queue


void enqueue(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = nullptr;

    if (rear == nullptr) {
        // First element in the queue
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
   
}

// Dequeue function 
int dequeue() {
    if (front == nullptr) {
       
        return -1;
    }
    int value = front->data;
    Node* temp = front;
    front = front->next;
    free(temp);
    if (front == nullptr) {
        rear = nullptr; 
    }
  
    return value;
}

// Add an edge
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); 
}

// BFS
void BFS(const vector<vector<int>>& adjList, int start) {
    int n = adjList.size();
    vector<bool> visited(n, false); 

   
    visited[start] = true;
    enqueue(start);

    cout << "BFS traversal starting from node " << start << ": ";
    while (front != nullptr) { // While queue is not empty
        int node = dequeue();
        cout << node << " ";

        // Visit all neighbors of the current node
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                enqueue(neighbor);
            }
        }
    }
    cout << endl;
}

// DFS helper function
void DFSUtil(int node, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    // Visit all neighbors of the current node
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, adjList, visited);
        }
    }
}

// DFS function
void DFS(const vector<vector<int>>& adjList, int start) {
    int n = adjList.size();
    vector<bool> visited(n, false); // Track visited nodes

    cout << "DFS traversal starting from node " << start << ": ";
    DFSUtil(start, adjList, visited);
    cout << endl;
}

int main(){
    int n, m;

    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> adjList(n);

    // Add edges based on user input
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(adjList, u, v);
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
                BFS(adjList, start);
                break;
            case 2:
                DFS(adjList, start);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Choose a correct option.\n";
        }
    } while(choice != 3);

    return 0;
}
