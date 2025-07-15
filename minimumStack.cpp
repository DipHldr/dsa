#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={3,7,5,9,1,7,2,9};
    stack<pair<int,int>>st;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        int new_elem=arr[i];
        int new_min=(st.empty())?new_elem:min(new_elem,st.top().second);

        st.push({new_elem,new_min});
    }

    while(!st.empty()){
        cout<<st.top().first<<"  "<<st.top().second<<endl;
        st.pop();
    }

    return 0;
}