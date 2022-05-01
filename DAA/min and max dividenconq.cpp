#include<bits/stdc++.h>
using namespace std;
int minE=INT_MAX;
int maxE=INT_MIN;
void minandmax(int arr[], int n, int low, int high){
    if(high-low>1){
        int mid=low+(high-low)/2;
        minandmax(arr, n, low, mid);
        minandmax(arr, n, mid+1, high);
    }
    minE=min(minE, arr[low]<arr[high]?arr[low]:arr[high]);
    maxE=max(maxE, arr[low]>arr[high]?arr[low]:arr[high]);
}
int main(){
    int n=5;
    int arr[]={5,1,6,7,3};
    minandmax(arr, n, 0, 4);
    cout<<"Minimum element: "<<minE<<endl;
    cout<<"Maximum element: "<<maxE;
}
