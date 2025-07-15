#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    int cnt=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            cnt++;
            if(n/i!=i){
                cnt++;
            }
        }
        if(cnt>2)false;
    }

    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int>ans;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            if(isPrime(i))ans.push_back(i);
            if(n/i!=i){
                if(isPrime(n/i))ans.push_back(n/i);
            }
        }
    }

    sort(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
}