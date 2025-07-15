#include<bits/stdc++.h>
using namespace std;
int total(int sum,int n){
    if(n==0){
        return sum;
    }
    total(sum+n,n-1);
}

int total2(int n){
    if(n==0){
        return 0;
    }

    return n+total2(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<total(0,n)<<endl;
    cout<<total2(n);
}