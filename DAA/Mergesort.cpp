#include<bits/stdc++.h>
using namespace std;
void Merge(int array[], int low, int mid, int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int array1[n1];
    int array2[n2];
    for(int i=0; i<n1; i++)
        array1[i]=array[low+i];
    for(int i=0; i<n2; i++)
        array2[i]=array[mid+i+1];
    int i=0;
    int j=0;
    int k=low;
    while(i<n1 && j<n2){
        if(array1[i]<=array2[j]){
            array[k]=array1[i];
            i++;
        }
        else{
            array[k]=array2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        array[k]=array1[i];
        i++;
        k++;
    }
    while(j<n2){
        array[k]=array2[j];
        j++;
        k++;
    }
}
void MergeSort(int array[], int low, int high){
    if(high>low){
        int mid=low+ (high-low)/2;
        MergeSort(array, low, mid);
        MergeSort(array, mid+1, high);
        Merge(array, low, mid, high);
    }
}
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int array[]={5,3,6,2,8};
    MergeSort(array, 0, n-1);
    for(int i=0; i<n; i++)
        cout<<array[i]<<" ";
}
