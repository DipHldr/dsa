#include<iostream>
using namespace std;
bool isSorted(int* arr, int size){
    if(size==0||size==1)
    return true;

    if(arr[0]>arr[1])
    return false;

    bool istrue=isSorted(arr+1,size-1);
    return istrue;
}
int main(){
    int arr[]={5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    bool ans=isSorted(arr,size);
    if(ans)
    cout<<"array is sorted"<<endl;
    else
    cout<<"array is unsorted"<<endl;
    return 0;
}