/*
Given an integer array nums, return the number of non-empty subarrays with the leftmost element of the subarray not larger than other elements in the subarray.
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
#define  pii pair<int,int>
int LeftSubarrayMin(int n){
    stack<pii>st;
    vector<int>next_element(n,n);
    for(int i=0;i<n;i++){
        while(!st.empty()&&st.top().second>arr[i]){
            next_element[st.top().first]=i;
            st.pop();
        }
        st.push({i,arr[i]});
    }
    int res=0;
    for(int i=0;i<n;i++){
        res+=next_element[i]-i;
    }
    return res;
}


int main(){
    int n;
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    int t=LeftSubarrayMin(n);
    cout<<t<<endl;

}