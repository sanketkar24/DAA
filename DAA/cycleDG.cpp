#include<bits/stdc++.h>
using namespace std;
#define n 6
bool checkCycle(int node, vector<int> adj[], vector<bool> visited, vector<bool> DFSvisit){
    visited[node]=true;
    DFSvisit[node]=true;
    for(auto it: adj[node]){
        if(!visited[it]){
            if(checkCycle(it, adj, visited, DFSvisit))
                return true;
        }
            else if(DFSvisit[it]==true)
                return true;
    }
    DFSvisit[node]=false;
    return false; 
}
bool DFS(int node, vector<int> adj[]){
    vector<bool> visited(n+1,0);
    vector<bool>DFSvisit(n+1,0);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(checkCycle(i, adj, visited, DFSvisit)==true){
                return true;
            }
        }
    }
    return false;
    
}
void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
}
int main(){
    vector<int> adj[n];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    
    if(DFS(0, adj)==true){
        cout<<"Cycle detected";
    }
    else
        cout<<"No cycle: ";
    
}
