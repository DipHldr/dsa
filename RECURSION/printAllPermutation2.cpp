#include<bits/stdc++.h>
using namespace std;

//print all permutations withour repeatations
void printAllPermut(int arr[],vector<vector<int>>&ans,vector<int>&temp,int freq[],int n){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }    

    for(int i=0;i<n;i++){
        if(!freq[i]){
            freq[i]=1;
            temp.push_back(arr[i]);
            printAllPermut(arr,ans,temp,freq,n);
            freq[i]=0;
            temp.pop_back();
        }
    }
}

int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>>ans;
    vector<int>temp;
    int freq[n];
    for(int i=0;i<n;i++)freq[i]=0;

    printAllPermut(arr,ans,temp,freq,n);

    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

}