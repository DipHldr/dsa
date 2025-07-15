#include<bits/stdc++.h>
using namespace std;
using ll=long long;
class SegmentTree{
    ll n;
    vector<ll>tree;
    public:
    SegmentTree(ll n){
        this->n=n;
        tree.assign(4*n,0);
    }

    void build(vector<ll>&a,ll node,ll start,ll end){
        if(start==end){
            tree[node]=a[start];
            return;
        }
        else{
            int mid=(start+end)/2;
            build(a,2*node,start,mid);
            build(a,2*node+1,mid+1,end);
            tree[node]=tree[2*node]+tree[2*node+1];
        }
    }

    void update(ll node,ll start,ll end,ll idx,ll val){
        if(start==end){
            tree[node]=val;
            return;
        }

        ll mid=(start+end)/2;
        if(idx<=mid)update(2*node,start,mid,idx,val);
        else update(2*node+1,mid+1,end,idx,val);

        tree[node]=tree[2*node]+tree[2*node+1];
    }

    ll query(ll node,ll start,ll end,ll l,ll r){
        if(l>end||r<start)return 0;
        if(l<=start&&end<=r){
            return tree[node];
        }

        ll mid=(start+end)/2;
        return query(2*node,start,mid,l,r )+query(2*node+1,mid+1,end,l,r);
    }

    void pointUpdate(ll idx,ll val){
        update(1,1,n,idx,val);
    }
    ll queryResult(int l,int r){
        return query(1,1,n,l,r);
    }
    void buildTree(vector<ll>& arr){
        build(arr,1,1,n);
    }
};

int main(){
    int n;
    cin>>n;
    vector<ll>arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    SegmentTree st(n);
    st.buildTree(arr);

    cout<<"Before point update: "<<st.queryResult(3,5)<<endl;
    st.pointUpdate(3,10);
    cout<<"After point update:  "<<st.queryResult(3,5)<<endl;
    
}
