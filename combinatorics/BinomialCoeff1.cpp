//find nCr
#include<bits/stdc++.h>
using namespace std;

long long solve(int n,int k){
    if(k>n)return -1;
    long long res=1;
    for(int i=n-k+1;i<=n;i++){
        res*=i;
    }
    for(int i=2;i<=k;i++){
        res/=i;
    }

    return res;
}


int main(){
    int n,k;
    cin>>n>>k;
    long long ans=solve(n,k);
    cout<<ans<<endl;
}