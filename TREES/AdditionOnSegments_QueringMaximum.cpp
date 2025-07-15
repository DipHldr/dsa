/*
Adding on segments, querying for maximum¶
Now the modification query is to add a number to all elements in a range, and the reading query is to find the maximum in a range.
*/

#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    vector<int>tree,lazy;
    public:
    SegmentTree(int n){
        this->n=n;
        tree.resize(4*n);
        lazy.resize(4*n);
    }
    void push(int node){
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
        tree[2*node]+=lazy[node];
        tree[2*node+1]+=lazy[node];
        lazy[node]=0;
    }

    void build(vector<int>&arr,int node,int start,int end){
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        else{
            int mid=(start+end)/2;
            build(arr,2*node,start,mid);
            build(arr,2*node+1,mid+1,end);
            tree[node]=max(tree[2*node],tree[2*node+1]);
        }
    }

    void update(int node,int start,int end,int l,int r,int val){
        if(l>r)return;

        if(start==l&&r==end){
            tree[node]+=val;
            lazy[node]+=val;
            return;
        }

        else{
            push(node);
            int mid=(start+end)/2;
            update(2*node,start,mid,l,min(r,mid),val);
            update(2*node+1,mid+1,end,max(l,mid+1),r,val);
            tree[node]=max(tree[2*node],tree[2*node+1]);
        }
    }

    int query(int node,int start,int end,int l,int r){
        if(l>r)return INT_MIN;

        if(l==start&&r==end){
            return tree[node];
        }

        push(node);
        int mid=(start+end)/2;
        
        return max(query(2*node,start,mid,l,min(r,mid)),query(2*node+1,mid+1,end,max(mid+1,l),r));
    }

    void buildTree(vector<int>&arr){
        build(arr,1,1,n);
    }
    void updateTree(int l,int r,int val){
        update(1,1,n,l,r,val);
    }
    int queryTree(int l,int r){
        return query(1,1,n,l,r);
    }

};

int main(){
    int n;
    vector<int>arr={0,1,2,3,4,5,6,7,8,9};
    n=arr.size();
    SegmentTree st(n);
    st.buildTree(arr);
    cout<<st.queryTree(3,6)<<endl;
    st.updateTree(4,4,10);
    cout<<st.queryTree(3,6)<<endl;
    return 0;
}