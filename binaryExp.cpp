#include<bits/stdc++.h>
using namespace std;

//find a^b;

long long binpow(long long a,long long b){
    if(b==0)return 1;

    long long res=binpow(a,b/2);

    //if b odd
    if(b%2){
        return res*res*a;
    }else{
        //if b even
        return res*res;
    }

}

int main(){
    long long dig=13;
    cout<<binpow(dig,12);
}