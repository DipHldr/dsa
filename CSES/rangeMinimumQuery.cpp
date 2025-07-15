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

    ll query(int node,int start,int end,int ql,int qr){
        if(ql>end||qr<start)return INT_MAX;

        if(ql<=start && end<=qr)return tree[node];

        int mid=((start+end)>>1);
        return min(query(2*node,start,mid,ql,qr),query(2*node+1,mid+1,end,ql,qr));
    }

    void buildTree(vector<int>&arr){
        build(arr,1,1,n);
    }

    ll queryResult(int l,int r){
        return query(1,1,n,l,r);
    }
};

int main(){
    int n,x;
    cin>>n>>x;
    SegmentTree st(n);
    vector<int>arr(n+1,0);
    for(int i=1;i<=n;i++)cin>>arr[i];

    st.buildTree(arr);
    while(x--){
        int l,r;
        cin>>l>>r;
        cout<<st.queryResult(l,r)<<endl;
    }

    return 0;


}