#include<iostream>
using namespace std;
 int binarySearch(int* arr,int low,int high,int key){
    if(low>high){
        return -1;        
    }
    int mid=(low+high)/2;
    if(key==arr[mid]){
        return 1;
    }
    if(key<arr[mid]){
        return binarySearch(arr,low,mid-1,key);
    }
    return binarySearch(arr,mid+1,high,key);

 }
 int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(int);
    int n;
    cin>>n;
    int res=binarySearch(arr,0,size-1,n);
    if(res==1)
    cout<<"item found";
    else
    cout<<"item not found";
 }
