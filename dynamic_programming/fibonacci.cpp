#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    if(n<=1)return n;

    return fibo(n-1)+fibo(n-2);
}

//memoisation
int fibomem(int n,int dp[]){
    if(n<=1)return n;

    if(dp[n]!=-1)return dp[n];

    dp[n]=fibomem(n-1,dp)+fibomem(n-2,dp);

    return dp[n];
}

//tabulation
int fibotab(int n){
    vector<int>dp(n+1,0);
    dp[0]=0;dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}
//space optimization
int fiboSpaceOptimization(int n){
    int prev=1,prev2=0,curr;
    for(int i=2;i<=n;i++){
        curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return curr;
}
int main(){
    int n;
    cin>>n;

    
    int dp[n+1];
    memset(dp,-1,sizeof dp);

    dp[0]=0;dp[1]=1;
    int res2=fibomem(n,dp);
    cout<<"Using memoisation: "<<res2<<endl;


    int res3=fibotab(n);
    cout<<"Using Tabulation: "<<res3<<endl;

    int res4=fiboSpaceOptimization(n);
    cout<<"Applying space optimisation: "<<res3<<endl;

    int res1=fibo(n);
    cout<<"Just using recursion: "<<res1<<endl;
}