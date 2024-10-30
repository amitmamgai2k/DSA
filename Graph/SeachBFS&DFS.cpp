#include <bits/stdc++.h> 
using namespace std;


void AddEdge(vector<vector<int>>&adjMatrix,int u,int v,bool directed){
    adjMatrix[u][v] = 1;
    if(!directed){
        adjMatrix[v][u]=1;
    }
}
void BFS(const vector<vector<int>>&adjMatrix,int start){
    int n = adjMatrix.size();
    vector<bool>visited(n,false);
    queue <int>q;
    visited[start] = true;
    q.push(start);
    cout<<"BFS traversal starting from node "<<start<<":";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        // visited neighbour
        for (int i = 0;i<n;i++){
            if(adjMatrix[node][i] && !visited[i]){
                visited[i] = true;
                q.push(i);

            }
        }
    }
    cout<<endl;
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

    // Initialize an n x n adjacency matrix with 0s
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    // Add edges based on user input
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        AddEdge(adjMatrix, u, v, directed);
    }

    int start;
    cout << "Enter the starting node for BFS: ";
    cin >> start;
    BFS(adjMatrix, start);

    return 0 ;

}
