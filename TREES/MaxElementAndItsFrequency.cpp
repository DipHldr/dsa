#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
class SegmentTree{
    int n;
    vector<pii>tree;
    pii combine(pii& a,pii& b){
        if(a.first>b.first)return a;
        if(b.first>a.first)return b;

        return {a.first,a.second+b.second};
    }
    void build(vector<int>&arr,int node,int start,int end){
        if(start==end){
            tree[node]={arr[start],1};
            return;
        }
        else{
            int mid=(start+end)/2;
            build(arr,2*node,start,mid);
            build(arr,2*node+1,mid+1,end);

            tree[node]=combine(tree[2*node],tree[2*node+1]);
        }
    }
    void update(int node,int start,int end,int idx,int val){
        if(start==end){
            tree[node]={val,1};
            return;
        }

        int mid=(start+end)/2;
        if(idx<=mid)update(2*node,start,mid,idx,val);
        else update(2*node+1,mid+1,end,idx,val);

        tree[node]=combine(tree[2*node],tree[2*node+1]);
    }

    pii get_max(int node,int start,int end,int l,int r){
        if(l>end||r<start)return {INT_MIN,-1};

        if(l<=start&&end<=r){
            return tree[node];
        }

        int mid=(start+end)/2;
        return max(get_max(2*node,start,mid,l,r),get_max(2*node+1,mid+1,end,l,r));
    }
    public:
    SegmentTree(int n){
        this->n=n;
        tree.assign(4*n,{0,0});
    }

    void buildTree(vector<int>&arr){
        build(arr,1,1,n);
    }

    void updateTree(int idx,int val){
        update(1,1,n,idx,val);
    }

    pii getMaxValAndFrequency(int l,int r){
        return get_max(1,1,n,l,r);
    }
};

int main(){
    int n;
    // cin>>n;
    vector<int>arr={0,4,8,2,4,8,8,3,8,5,8,2,8,6};
    n=arr.size();
    SegmentTree st(n-1);
    st.buildTree(arr);
    pii t=st.getMaxValAndFrequency(1,n-1);
    cout<<"The max value is: "<<t.first<<endl;
    cout<<"And its frequency is: "<<t.second<<endl;
    return 0;
}