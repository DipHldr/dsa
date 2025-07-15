#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=1;j<=2*(n-i);j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    int k=n-1;
    for(int i=1;i<=k;i++){
        
        for(int j=1;j<=k-i+1;j++){
            cout<<"*";
        }
        for(int j=1;j<=2*(n-k+i-1);j++){
            cout<<" ";
        }
        for(int j=1;j<=k-i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }

}

