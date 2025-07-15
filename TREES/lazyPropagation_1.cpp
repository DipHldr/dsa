#include<bits/stdc++.h>
using namespace std;
using ll=long long;

class SegmentTree{
    ll n;
    vector<ll>tree;
     void build(vector<ll>&arr,ll node,ll start,ll end){
        if(start==end){
            tree[node]=arr[start];
            
        }
        else{
            ll mid=(start+end)/2;
            build(arr,2*node,start,mid);
            build(arr,2*node+1,mid+1,end);
            tree[node]=0;
        }
    }

    void lazyUpdate(ll node,ll start,ll end,ll l,ll r,ll add){
        if(l>r)return;

        if(l==start&&r==end){
            tree[node]+=add;
            
        }
        else{
             ll mid=(start+end)/2;
        lazyUpdate(2*node,start,mid,l,min(r,mid),add);
        lazyUpdate(2*node+1,mid+1,end,max(l,mid+1),r,add);
        }       
    }

    ll getVal(ll node,ll start,ll end,ll idx){
        if(start==end)return tree[node];

        ll mid=(start+end)/2;
        if(idx<=mid)return tree[node]+getVal(2*node,start,mid,idx);
        else return tree[node]+getVal(2*node+1,mid+1,end,idx);
    }
    public:
    SegmentTree(ll n){
        this->n=n;
        tree.resize(4*n);
    }
    void buildTree(vector<ll>&arr){
        build(arr,1,1,n);
    }
    void updateTree(ll l,ll r,ll add){
        lazyUpdate(1,1,n,l,r,add);
    }

    ll getValTree(ll idx){
        return getVal(1,1,n,idx);
    }
};

int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll>arr(n+1);
    for(ll i=1;i<=n;i++)cin>>arr[i];
    // vector<ll>arr={0,1,2,3,4,5,6,7,8,9};
    // n=arr.size();
    SegmentTree st(n);
    st.buildTree(arr);

    while(q--){
       ll x;
       cin>>x;
       if(x==1){
        ll a,b,val;
        cin>>a>>b>>val;
        st.updateTree(a,b,val);
       }else{
        ll k;
        cin>>k;
        cout<<st.getValTree(k)<<endl;
       }
    }


    // cout<<st.getValTree(4)<<endl;
    // st.updateTree(3,5,7);
    // cout<<st.getValTree(3)<<endl;
    // cout<<st.getValTree(4)<<endl;
    // cout<<st.getValTree(5)<<endl;

    return 0;

    
}