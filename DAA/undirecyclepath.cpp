#include<bits/stdc++.h>
using namespace std;
#define n 5
vector<int> path;
int countE;
bool cycleDFS(int node, int parent, vector<int> adj[], vector<bool>& visited){
    visited[node]=true;
    for(auto it: adj[node]){
        if(!visited[it]){
            if(cycleDFS(it, node, adj, visited)==true){
                return true;
            }
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}
void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> adj[n];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 2);
    addEdge(adj, 4, 1);
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(cycleDFS(i,-1,adj, visited)){
                countE++;
                cout<<"Cycle found";
            }
        }
    }
    cout<<"The number of loops: "<<countE;
}

