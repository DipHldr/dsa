#include<bits/stdc++.h>
using namespace std;

void subSeqSum(int ind,int a[],int sum,int n,int k,vector<int>&seq){
    if(ind==n){
        if(sum==k){
        //print the subsequence
        for(auto it:seq){
            cout<<it<<" ";
        }
        cout<<endl;
    }
        return;
    }
    

    seq.push_back(a[ind]);
    sum+=a[ind];
    subSeqSum(ind+1,a,sum,n,k,seq);
    seq.pop_back();
    sum-=a[ind];
    subSeqSum(ind+1,a,sum,n,k,seq);
}

int main(){
    int arr[]={2,5,2,1,2};
    int k=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>seq;
    subSeqSum(0,arr,0,n,k,seq);
}