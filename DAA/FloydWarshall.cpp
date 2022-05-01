#include<bits/stdc++.h>
using namespace std;
#define v 4
#define INF INT_MAX
void printArray(int distance[v][v]){
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(distance[i][j]==INF)
                cout<<"NA\t";
            else
                cout<<distance[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void FloydW(int graph[v][v]){
    int distance[v][v];
    for(int i=0; i<v; i++)
    for(int j=0; j<v; j++){
        distance[i][j]=graph[i][j];
    }
    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(distance[i][j]>distance[i][k]+distance[k][j] && distance[i][k]!=INF && distance[k][j]!=INF){
                    distance[i][j]=distance[i][k]+distance[k][j];
                }
            }
        }
    }
    printArray(distance);
    
    
}
int main(){
    int graph[v][v] = { { 0, 5, INF, 10 },
                            { INF, 0, 3, INF },
                            { INF, INF, 0, 1 },
                            { INF, INF, INF, 0 } };
    FloydW(graph);
}
