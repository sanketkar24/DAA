#include<bits/stdc++.h>
using namespace std;
void DFS(int node, int destination,vector<int> adj[], vector<bool> &visited, vector<bool> &DFSvisit, int &count){
    cout<<node<<"-";
    for(auto it: adj[node]){
        if(it==destination){
            count++;
            cout<<endl;
        }
        else
            DFS(it, destination, adj, visited, DFSvisit, count);
    }
}
int main(){
    int n=8;
    vector<int> adj[n+1];
    adj[8].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(5);
    adj[2].push_back(7);
    adj[7].push_back(4);
    adj[2].push_back(4);
    adj[1].push_back(5);
    adj[3].push_back(1);
    adj[3].push_back(5);
    adj[4].push_back(6);
    adj[6].push_back(5);
    cout<<"Enter source: ";
    int source;
    cin>>source;
    cout<<"Enter destination: ";
    int destination;
    cin>>destination;
    vector<bool>visited(n+1,0);
    vector<bool>DFSvisit(n+1,0);
    int count=0;
        DFS(source, destination, adj, visited, DFSvisit, count);
    cout<<"\nCount: "<<count;
}
