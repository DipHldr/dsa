#include<bits/stdc++.h>
using namespace std;

int main(){
    using ll=long long;
    ll n;
    cin>>n;

    vector<ll>ans;

    ans.push_back(n);
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }else{
            n=n*3+1;
        }
        ans.push_back(n);
    }

    for(ll i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

