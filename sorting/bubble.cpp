#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[],int n){
    for(int i=n-1;i>=1;i--){
        int didswap=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap=1;
            }
            
        }
        if(didswap==0)
        break;
    }
}

int main(){
    int arr[]={5,1,3,2,8,7,0,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}