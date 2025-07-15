//polynomial rolling rolling hash function
#include<bits/stdc++.h>
using namespace std;

long long performHashing(string& s){
    const int p=31;
    const int m=1e9+9;
    long long hashValue=0;
    long long p_pow=1;

    for(char c:s){
        hashValue=(hashValue + (c-'a'+1)*p_pow)%m;
        p_pow=(p_pow*p)%m;
    }
    return hashValue;
}

int main(){
    string s="Grimoire";
    long long hash=performHashing(s);
    cout<<"The hash for "<<s<<" is "<<hash<<endl;
}