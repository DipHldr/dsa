#include<iostream>
using namespace std;
bool linearSearch(int size,int* arr,int x){
    if(size==0){
        return false;
    }
    if(arr[0]==x){
        return true;
    }
    return linearSearch(size-1,arr+1,x);
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int e=52;
   if(linearSearch(size,arr,e)){
    cout<<"element "<<e<<" found"<<endl;
   }else{
   cout<<"Element "<<e<<" not found"<<endl;
   }

   return 0;
}