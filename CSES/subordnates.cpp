#include<bits/stdc++.h>
using namespace std;
const int sz=2e5;
vector<int>children[sz];
int subtree_size[sz];

void dfs_size(int node){
    subtree_size[node]=1;

    for(auto child:children[node]){
        dfs_size(child);
        subtree_size[node]+=subtree_size[child];
    }
}
int main(){
    int N;
    cin>>N;
    for(int i=1;i<N;i++){
        int parent;
        cin>>parent;
        parent--;
        children[parent].push_back(i);
    }

    dfs_size(0);

    for(int i=0;i<N;i++){
        cout<<subtree_size[i]-1;

        if(i!=N-1)cout<<" ";
    }

    return 0;
}