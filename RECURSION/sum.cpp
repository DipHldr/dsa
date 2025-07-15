#include<iostream>
using namespace std;
int add(int size,int* arr){
   if(size==0){
    return 0;
   }
   if(size==1){
    return arr[0];
   }
   int rem=add(size-1,arr+1);
   int sum=arr[0]+rem;
   return sum; 
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    // int res=0;
    int sum=add(size,arr);
    cout<<sum<<endl;
    return 0;
}