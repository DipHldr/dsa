#include<bits/stdc++.h>
using namespace std;

void insertionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0&&arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main(){
    int arr[]={3,2,4,6,5,2,9,7,5,4};
    int size=sizeof(arr)/sizeof(arr[0]);

    insertionsort(arr,size);
    for(auto i:arr){
        cout<<i<<" "; 
    }
}