#include<bits/stdc++.h>
using namespace std;

//print all permutations with repetations;
void printPermutation(int arr[],vector<vector<int>>&ans,vector<int>&temp,int n){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<n;i++){
        temp.push_back(arr[i]);
        printPermutation(arr,ans,temp,n);
        temp.pop_back();
    }
}
int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>temp;
    vector<vector<int>>ans;
    printPermutation(arr,ans,temp,n);

    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}