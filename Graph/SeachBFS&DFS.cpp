#include <bits/stdc++.h> 
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

void DFS(const vector<vector<int>>& adjList, int start) {
    int n = adjList.size();
    vector<bool> visited(n, false); // Track visited nodes

    cout << "DFS traversal starting from node " << start << ": ";
    DFSUtil(start, adjList, visited);
    cout << endl;
}


int main(){
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

    int start,choice;
    cout << "Enter the starting node for BFS: ";
    cin >> start;
    do{
       cout << "Select Traversal :\n";
        cout << "1. Breadth First Search\n";
        cout << "2. Depth First Search\n";
     cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    switch(choice){
        case 1:
         BFS(adjList, start);
         break;
        case 2:
        DFS(adjList,start);
        break;
        default:
        cout<<"Choose correct option"<<endl;
    }
    }while(choice!=3);
    
   

    return 0 ;

}







