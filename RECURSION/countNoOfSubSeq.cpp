#include<bits/stdc++.h>
using namespace std;

int countNoOfSubSeq(int ind,int arr[],int sum,int n,int k){
    if(ind>=n){
        if(sum==k)return 1;
        else return 0;
    }

    sum+=arr[ind];
    int l = countNoOfSubSeq(ind+1,arr,sum,n,k);
    sum-=arr[ind];
    int r = countNoOfSubSeq(ind+1,arr,sum,n,k);

    return l+r;
}

int main(){
    int arr[]={3,2,1,4,5};
    int k=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    int res=countNoOfSubSeq(0,arr,0,n,k);
    cout<<res<<endl;
}
