#include<bits/stdc++.h>
using namespace std;

int fibo(int n,int dp[]){
    if(n<=1)return 1;
    if(dp[n]!=-1){
        // cout<<dp[n]<<" ";
        return dp[n];
    }
    dp[n]= fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int dp[n+1];
    fill_n(dp,n+1,-1);

    dp[0]=1;
    dp[1]=1;
    // cout<<dp[2];
    int res=fibo(n,dp);
    cout<<res<<endl;
}