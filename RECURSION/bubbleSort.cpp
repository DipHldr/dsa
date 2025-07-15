#include<iostream>
using namespace std;
void bubbleSort(int* arr,int size){
    if(size==0||size==1)
    return;

    for(int i=0;i<size;i++){
        if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    }

    bubbleSort(arr,size-1);
}
int main(){
    int arr[]={3,2,4,1,5,9,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,size);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
}