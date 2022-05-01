#include<bits/stdc++.h>
using namespace std;
int partitionA(int array[],int low,int high){
    int pivot=array[low];
    int ptr1=low;
    int ptr2=high;
    while(ptr1<ptr2)
    {
        while(array[ptr1]<=pivot){
            ptr1++;
        }
        while(array[ptr2]>pivot){
            ptr2--;
        }
        if(ptr1<ptr2)
            swap(array[ptr1],array[ptr2]);
    }
    swap(array[low],array[ptr2]);
    return ptr2;
}
void quicksort(int array[], int low, int high){
    if(high>low){
        int pi=partitionA(array, low, high);
        quicksort(array, low, pi-1);
        quicksort(array, pi+1, high);
    }
}
int main(){
    int array[]={4,3,6,2,7,1};
    quicksort(array, 0, 5);
    for(auto i:array)
        cout<<i<<" ";
}
