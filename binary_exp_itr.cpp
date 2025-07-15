#include<iostream>
using namespace std;
long long solve(int a, int b){
    long long result=1;
    while(b){
        if(b&1){
            result=result*a;
        }
        a=a*a;
        b>>=1;
    }
    return result;
}
int main(){
    long long n=solve(2,12);
    cout<<n;
    return 0;
}
