#include<bits/stdc++.h>
using namespace std;
#define n 5


void swap(int *xp, int *yp)
{
int temp = *xp;
*xp = *yp;
*yp = temp;
}
void SolveContLoad(){
cout<<"Enter number of containers: ";
int n;
cin>>n;
vector<int> weight(n);
for(int i=0; i<n; i++)
cin>>weight[i];
sort(weight.begin(), weight.end());
cout<<"Enter max capacity: ";
int c;
cin>>c;
int index=0;
int res=0;
while(c>0){
if(c>weight[index]){
c-=weight[index];
index++;
res++;
}
else{
cout<<"Max containers: "<<res<<endl;
return;
}
}
}



void Knapsack01(){
cout<<"Enter number of conatiners: ";
int n;
cin>>n;
vector<int> profit(n);
vector<int> weight(n);
vector<double> ratiopw;
cout<<"Enter Profit and Weight:"<<endl;
for(int i=0; i<n; i++){
cout<<"PROFIT: ";
cin>>profit[i];
cout<<"WEIGHT: ";
cin>>weight[i];
ratiopw.push_back(profit[i]/weight[i]);
}
cout<<"Enter max weight: ";
int maxw;
cin>>maxw;
for (int i = 0; i < n-1; i++)
for (int j = 0; j < n-i-1; j++)
if (ratiopw[j] < ratiopw[j+1]){
swap(&profit[j], &profit[j+1]);
swap(&weight[j], &weight[j+1]);
double temp=ratiopw[j];
ratiopw[j]=ratiopw[j+1];
ratiopw[j+1]=temp;
}
int itr=0;
int result=0;
while(maxw>0 && itr<n){
if(weight[itr]<=maxw){
result+=profit[itr];
maxw-=weight[itr];
}
itr++;
}
cout<<"Max Profit: "<<result<<endl;
}



void TopologicalSort(){





}


void addEdge(int v, int u, vector<int> Graph[]){
    Graph[v].push_back(u);
}
vector<int> doTopologicalSort()
{
    vector<int> L;
    vector<int> Graph[n];
    addEdge(1,2,Graph);
    addEdge(1,4, Graph);
    addEdge(2,1,Graph);
    addEdge(2,5, Graph);
    addEdge(2,3, Graph);
    addEdge(3,2,Graph);
    addEdge(3,4,Graph);
    addEdge(3,5,Graph);
    addEdge(4,1,Graph);
    addEdge(4,3,Graph);
    addEdge(5,2,Graph);
    addEdge(5,3,Graph);
    // get the total number of nodes in the graph
    int n = Graph.size();
 
    vector<int> indegree = Graph.indegree;
 
    // Set of all nodes with no incoming edges
    vector<int> S;
    for (int i = 0; i < n; i++)
    {
        if (!indegree[i]) {
            S.push_back(i);
        }
    }
 
    while (!S.empty())
    {
        // remove node `n` from `S`
        int n = S.back();
        S.pop_back();
 
        // add `n` at the tail of `L`
        L.push_back(n);
 
        for (int m: graph.adjList[n])
        {
            // remove an edge from `n` to `m` from the graph
            indegree[m] -= 1;
 
            // if `m` has no other incoming edges, insert `m` into `S`
            if (!indegree[m]) {
                S.push_back(m);
            }
        }
    }
 
    // if a graph has edges, then the graph has at least one cycle
    for (int i = 0; i < n; i++)
    {
        if (indegree[i]) {
            return {};
        }
    }
 
    return L;
}


int main(){
SolveContLoad();
Knapsack01();
}
