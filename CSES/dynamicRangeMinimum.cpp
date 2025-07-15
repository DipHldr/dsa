#include<bits/stdc++.h>
using namespace std;
using ll=long long;

class SegmentTree{
    int n;
    vector<ll>tree;
    public:
    SegmentTree(int n){
        this->n=n;
        tree.assign(4*n,0);
    }

    void build(vector<int>&arr,int node,int start,int end){
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        else{
            int mid=((start+end)>>1);
            build(arr,2*node,start,mid);
            build(arr,2*node+1,mid+1,end);
            tree[node]=min(tree[2*node],tree[2*node+1]);
        }
    }
    void update(int node,int start,int end,int idx,int val){
        if(start==end){
            tree[node]=val;
            return;
        }

        int mid=((start+end)>>1);
        if(idx<=mid)update(2*node,start,mid,idx,val);
        else update(2*node+1,mid+1,end,idx,val);

        tree[node]=min(tree[2*node],tree[2*node+1]);
    }

    ll query(int node,int start,int end,int l,int r){
        if(l>end||r<start)return LLONG_MAX;

        if(l<=start&&end<=r)return tree[node];

        int mid=((start+end)>>1);
        return min(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
    }

    void buildTree(vector<int>&arr){
        build(arr,1,1,n);
    }

    void updateTree(int idx,int val){
        update(1,1,n,idx,val);
    }

    ll queryTree(int l,int r){
        return query(1,1,n,l,r);
    }
};

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    SegmentTree st(n);

    st.buildTree(arr);

    while(x--){
        int p,q,r;
        cin>>p>>q>>r;
        if(p==1){
            st.updateTree(q,r);
        }else{
            cout<<st.queryTree(q,r)<<endl;
        }
    }

    return 0;
}