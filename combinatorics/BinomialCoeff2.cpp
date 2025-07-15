//binomial coefficient using modular inverse

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5;
long long factorial[MAXN + 1];

long long mod_pow(long long a,long long b,long long m){
    long long res=1;
    while(b){
        if(b&1)res=(res*a)%m;

        a=(a*a)%m;

        b>>=1;
    }

    return res;
}

long long mod_inverse(int a,int m){
    return mod_pow(a,m-2,m);
}

long long binomial_coefficient(long long n,long long k){
    if(k>n)return 0;

    return factorial[n]*mod_inverse(factorial[k],MOD)%MOD*mod_inverse(factorial[n-k],MOD)%MOD;

}



void precompute_factorials(){
    factorial[0]=1;
    for(int i=1;i<=MAXN;++i){
        factorial[i]=(factorial[i-1]*i)%MOD;
    }
}
int main(){
    precompute_factorials();
    int n = 12, k = 3;
    cout << "C(" << n << ", " << k << ") mod " << MOD << " = " << binomial_coefficient(n, k) << "\n";

    return 0;

}