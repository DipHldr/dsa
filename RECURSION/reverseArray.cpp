#include<bits/stdc++.h>
using namespace std;

void reverseArr(int a[],int i,int j){
    if(i==j){
        return;
    }
    
    swap(a[i],a[j]);
    reverseArr(a,i+1,j-1);
}

void reverseArr2(int arr[],int i,int n){
    if(i==n/2)return;
    swap(arr[i],arr[n-i-1]);
    reverseArr2(arr,i+1,n);
}
int main(){
int arr[]={1,2,3,4,5};
int n=sizeof(arr)/sizeof(arr[0]);
// reverseArr(arr,0,n-1);
reverseArr2(arr,0,n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}