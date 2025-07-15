#include<bits/stdc++.h>
using namespace std;

bool printOnlyOneSubSeq(int ind,int a[],vector<int>&ds,int sum,int n,int k){

    if(ind>=n){
        if(sum==k){
            for(auto it:ds)cout<<it<<" ";
            return true;
        }
        else return false;
    }

    ds.push_back(a[ind]);
    sum+=a[ind];
    if(printOnlyOneSubSeq(ind+1,a,ds,sum,n,k)==true)return true;
    ds.pop_back();
    sum-=a[ind];
    if(printOnlyOneSubSeq(ind+1,a,ds,sum,n,k)==true)return true;

    return false;

}

int main(){
    int arr[]={3,2,1,4,5};
    int k=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>ds;
    printOnlyOneSubSeq(0,arr,ds,0,n,k);
}