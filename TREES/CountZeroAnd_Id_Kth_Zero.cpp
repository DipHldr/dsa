#include<bits/stdc++.h>
using namespace std;

using ll=long long;

class SegmentTree{
    int n;
    vector<int>tree;
    void build(vector<int>&arr,int node,int start,int end){
        if(start==end){
            tree[node]=(arr[start]==0);
            return;
        }
        else{
            int mid=(start+end)/2;
            build(arr,2*node,start,mid);
            build(arr,2*node+1,mid+1,end);

            tree[node]=tree[2*node]+tree[2*node+1];
        }
    }

    void update(int node,int start,int end,int idx,int val){
        if(start==end){
            tree[node]=(val==0);
        }

        int mid=(start+end)/2;
        if(mid<=idx)update(2*node,start,mid,idx,val);
        else update(2*node+1,mid+1,end,idx,val);

        tree[node]=tree[2*node]+tree[2*node+1];
    }

    int query(int node,int start,int end,int l, int r){
        if(l>end||r<start)return 0;
        if(l<=start && end<=r)return tree[node];

        int mid=(start+end)/2;
        return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
    }

    int kthZero(int node,int start,int end,int k){
        if(k>tree[node])return -1;

        if(start==end)return start;

        int mid=(start+end)/2;
        if(tree[2*node]>=k){
            return kthZero(2*node,start,mid,k);
        }else{
            return kthZero(2*node+1,mid+1,end,k-tree[2*node]);
        }
    }
    public:
    SegmentTree(int n){
        this->n=n;
        tree.assign(4*n,0);
    }
    void buildTree(vector<int>&arr){
        build(arr,1,1,n);
    }

    void updateTree(int idx,int val){
        update(1,1,n,idx,val);
    }

    int queryTree(int l,int r){
        return query(1,1,n,l,r);
    }

    int findKthZero(int k){
        return kthZero(1,1,n,k);
    }
    
};

int main(){
    int n;
    // cin>>n;

    // vector<int>arr(n+1,0);
    // for(int i=1;i<=n;i++)cin>>arr[i];

    vector<int>arr={0,2,0,2,0,4,0,0,0,4,6,5,8,0,3};
    n=arr.size();
    SegmentTree st(n);
    st.buildTree(arr);
    cout<<st.queryTree(4,9)<<endl;
    cout<<st.findKthZero(6)<<endl;

    return 0;
}


