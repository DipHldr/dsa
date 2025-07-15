
#include<bits/stdc++.h>
using namespace std;
int N=1000000;
int sieve[1000001];
void createSieve(){
    for(int i=2;i<=N;i++){
        sieve[i]=1;
    }
    for(int i=2;i*i<=N;i++){
        if(sieve[i]==1){
            for(int j=i*i;j<=N;j++){
                if(sieve[j]!=0){
                    sieve[i]++;
                    sieve[j]=0;
                }
            }
        }
    }
}
int main(){
    createSieve();
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        cout<<"output: "<<sieve[n];
    }
}