#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }

    int findUparent(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node]=findUparent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ult_u=findUparent(u);
        int ult_v=findUparent(v);

        if(ult_u==ult_v)return;

        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }else if(rank[ult_v]<rank[ult_u]){
            parent[ult_v]=ult_u;
        }else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }

    }

    void unionBySize(int u,int v){
        int ult_u=findUparent(u);
        int ult_v=findUparent(v);

        if(ult_u==ult_v)return;

        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }else if(size[ult_v]<size[ult_u]){
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }

    }
};

int main(){
    DisjointSet ds(7);

    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findUparent(3)==ds.findUparent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }

    ds.unionByRank(3,7);

    if(ds.findUparent(3)==ds.findUparent(7)){
        cout<<"Same"<<endl;
    }else{
        cout<<"Not same"<<endl;
    }



}