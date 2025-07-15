#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    vector<vector<int>>tree;

    void build(vector<int>&arr,int node,int start,int end){
        if(start==end){
            tree[node]={arr[start]};
        }
        else{
            int mid=(start+end)/2;
            build(arr,2*node,start,mid);
            build(arr,2*node+1,mid+1,end);

            merge(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),
            tree[2*node+1].end(),back_inserter(tree[node]));
        }
    }

    int query(int node,int start,int end,int l,int r,int x){
        if(l>end||r<start)return INT_MAX;

        if(l<=start&&end<=r){
            vector<int>::iterator it=lower_bound(tree[node].begin(),tree[node].end(),x);
            if(it!=tree[node].end()){
                return *it;
            }
            return INT_MAX;
        }

        int mid=(start+end)/2;
        return min(query(2*node,start,mid,l,r,x),
        query(2*node+1,mid+1,end,l,r,x));
    }
    public:
    SegmentTree(int n){
        this->n=n;
        tree.resize(4*n);
    }

    void buildTree(vector<int>&arr){
        build(arr,1,1,n);
    }
    int queryTree(int l,int r,int x){
        return query(1,1,n,l,r,x);
    }
};

int main(){
    int n;
    // cin>>n;
    // vector<int>arr(n+1);
    // for(inti=1;i<n;i++)cin>>arr[i];
    vector<int>arr={0,6,2,9,5,3,8,4,7};
    n=arr.size();
    SegmentTree st(n);
    st.buildTree(arr);
    cout<<st.queryTree(2,6,4)<<endl;
    
}