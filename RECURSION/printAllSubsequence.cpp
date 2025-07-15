#include<bits/stdc++.h>
using namespace std;

void subSeq(int ind,vector<int>&ds,int a[],int n){
    if(ind==n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        cout<<endl;
        if(ds.size()==0){
        cout<<"{}"<<endl;
    }
        return;
    }

    

    ds.push_back(a[ind]);
    subSeq(ind+1,ds,a,n);
    ds.pop_back();
    subSeq(ind+1,ds,a,n);
}

int main(){
    int arr[]={3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>ds;
    subSeq(0,ds,arr,n);
}