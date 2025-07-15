#include<bits/stdc++.h>
using namespace std;
void printAllPermut(int ind,vector<int>arr,vector<vector<int>>&ans,int n){
    if(ind==n){
        ans.push_back(arr);
        return;
    }
    for(int i=ind;i<n;i++){
        swap(arr[i],arr[ind]);
        printAllPermut(ind+1,arr,ans,n);
        swap(arr[i],arr[ind]);
    }

}
int main(){
    vector<int>arr={1,2,3};
    int n=arr.size();
    vector<vector<int>>ans;
    printAllPermut(0,arr,ans,n);

    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}