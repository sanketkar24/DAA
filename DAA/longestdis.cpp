#include<bits/stdc++.h>
using namespace std;
int maxd=0;
void MaxDist(int source, int destination, vector<pair<int, int> > adj[], vector<int> &distance){
    for(auto i: adj[source]){
            if(distance[i.first]<distance[source]+i.second)
                distance[i.first]=distance[source]+i.second;
        if(i.first==destination)
            continue;
        MaxDist(i.first, destination, adj, distance);
    }
}
int main(){
    int n=8;
    vector<pair<int,int> > adj[n+1];
    adj[8].push_back({1,2});
    adj[1].push_back({2,3});
    adj[2].push_back({5,4});
    adj[2].push_back({7,3});
    adj[7].push_back({4,5});
    adj[2].push_back({4,1});
    adj[1].push_back({5,1});
    adj[3].push_back({1,4});
    adj[3].push_back({5,2});
    adj[4].push_back({6,3});
    adj[6].push_back({5,4});
    cout<<"Enter source: ";
    int source;
    cin>>source;
    cout<<"Enter destination: ";
    int destination;
    cin>>destination;
    vector<int> distance(n+1,0);
    distance[source]=0;
    MaxDist(source, destination, adj, distance);
    cout<<"Max distance: "<<distance[destination];
}
