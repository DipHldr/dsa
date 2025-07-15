#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int st=n;
    for(int i=0;i<=n;i++){
        for(char ch='A'+st;ch<='A'+n-1;ch++){
            cout<<ch;
        }
        st--;
        cout<<endl;
    }
}