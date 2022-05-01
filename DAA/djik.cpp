#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    vector<pair<int,int> > g[n+1];
    g[1].push_back({2,2});
        g[1].push_back({4,1});
        g[2].push_back({1,2});
        g[2].push_back({5,5});
        g[2].push_back({3,4});
        g[3].push_back({2,4});
        g[3].push_back({4,3});
        g[3].push_back({5,1});
        g[4].push_back({1,1});
        g[4].push_back({3,3});
        g[5].push_back({2,5});
        g[5].push_back({3,1});
    priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int,int> > > pq;
    vector<int> distance(n+1, INT_MAX);
    int source=0;
    distance[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        int prev=pq.top().second;
        int dist=pq.top().first;
        pq.pop();
        for(auto it: g[prev]){
            if(distance[prev]+it.second<distance[it.first])
            {
                distance[it.first]=distance[prev]+it.second;
                pq.push(make_pair(distance[it.first], it.first));
            }
        }
    }
    cout<<"Distances: "<<endl;
    for(int i=1; i<n+1; i++)
        cout<<"Node "<<i<<": "<<distance[i]<<endl;
}
