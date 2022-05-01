#include<bits/stdc++.h>
using namespace std;
#define n 8
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void merge(int array[], int low, int mid, int high){
    int n1,n2;
    n1=mid-low+1;
    n2=high-mid;
    int array1[n1];
    int array2[n2];
    for(int i=0; i<n1; i++){
        array1[i]=array[low+i];
    }
    for(int i=0; i<n2; i++){
        array2[i]=array[mid+i+1];
    }
    int index=low;
    int ptr1=0;
    int ptr2=0;
    while(ptr1<n1 && ptr2<n2){
        if(array1[ptr1]<array2[ptr2]){
            array[index]=array1[ptr1];
            ptr1++;
        }
        else{
            array[index]=array2[ptr2];
            ptr2++;
        }
        index++;
    }
    while(ptr1<n1){
        array[index]=array1[ptr1];
        index++;
        ptr1++;
    }
    while(ptr2<n2){
        array[index]=array2[ptr2];
        ptr2++;
        index++;
    }
}
void mergesort(int array[], int low, int high){
    if(high>low){
        int mid=low+ (high-low)/2;
        mergesort(array, low, mid);
        mergesort(array, mid+1, high);
        merge(array, low, mid, high);
    }
}
int main(){
    vector<int> adj[n+1];
    addEdge(adj, 8, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 7);
    addEdge(adj, 7, 4);
    addEdge(adj, 2, 4);
    addEdge(adj, 5, 1);
    addEdge(adj, 3, 1);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 6, 5);
    int degree[n+1];
    for(int i=1; i<=n; i++){
        degree[i]=adj[i].size();
    }
    for(int i=1; i<n+1; i++){
        cout<<"Degree of "<<i<<": "<<degree[i]<<endl;
    }
    mergesort(degree, 0, n);
    cout<<"------------SORTED---------------"<<endl;
    for(int i=1; i<n+1; i++){
        cout<<"Degree of "<<i<<": "<<degree[i]<<endl;
    }
    
}
