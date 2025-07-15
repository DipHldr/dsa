#include<bits/stdc++.h>
using namespace std;

void reversearr(int a[],int i,int j){
    if(i==j){
        return;
    }
    swap(a[i],a[j]);

    reversearr(a,i+1,j-1);
}

void rev2(int a[],int i,int n){
    if(i==n/2)
    return;

    swap(a[i],a[n-i-1]);

    rev2(a,i+1,n);
}

int main(){
    int a[]={1,2,3,4,5};
    int size=sizeof(a)/sizeof(a[0]);
    // reversearr(a,0,size-1);
    rev2(a,0,size);
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}