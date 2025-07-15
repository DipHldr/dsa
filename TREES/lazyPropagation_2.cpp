#include<bits/stdc++.h>
using namespace std;
using ll=long long;
class SegmentTree{
    int n;
    vector<int>tree;
    vector<bool>marked;
    void build(vector<int>&arr,int node,int start,int end){
        if(start==end){
            tree[node]=arr[start];
        }
        else{
            int mid=(start+end)/2;
            build(arr,2*node,start,mid);
            build(arr,2*node+1,mid+1,end);
        }
    }

    void push(int node){
        if(marked[node]){
            tree[2*node]=tree[2*node+1]=tree[node];
            marked[2*node]=marked[2*node+1]=true;
            marked[node]=false;
        }
    }

    void update(int node,int start,int end,int l,int r,int val){
        if(l>r)return;

        if(l==start&&r==end){
            tree[node]=val;
            marked[node]=true;
        }
        else{
            push(node);
            int mid=(start+end)/2;
            
            update(2*node,start,mid,l,min(r,mid),val);
            update(2*node+1,mid+1,end,max(l,mid+1),r,val);
        }
    }

    int get(int node,int start,int end,int pos){
        if(start==end)return tree[node];

        int mid=(start+end)/2;
        push(node);
        if(pos<=mid)return get(2*node,start,mid,pos);
        else return get(2*node+1,mid+1,end,pos);
    }
    public:
    SegmentTree(int n){
        this->n=n;
        tree.resize(4*n);
        marked.assign(4*n,false);
    }
    void buildTree(vector<int>&arr){
        build(arr,1,1,n);
    }

    void updateTree(int l,int r,int val){
        update(1,1,n,l,r,val);
    }

    int getVal(int pos){
        return get(1,1,n,pos);
    }
};

int main(){
    int n;
    // cin>>n;
    // vector<int>arr(n+1);
    // for(int i=0;i<n;i++)cin>>arr[i];
    vector<int>arr={0,1,2,3,4,5,6,7,8,9};
    n=arr.size();

    SegmentTree st(n);
    st.buildTree(arr);
    cout<<st.getVal(5)<<endl;
    st.updateTree(4,6,21);
    cout<<st.getVal(4)<<endl;
    cout<<st.getVal(5)<<endl;
    cout<<st.getVal(6)<<endl;
    cout<<st.getVal(7)<<endl;

    return 0;
}