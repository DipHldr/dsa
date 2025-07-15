#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    a[0]=0;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }

        sort(a,a+n);

        int ans=n;
        for(int i=1;i<n;i++){
            if(a[i]!=i){
                ans=i;
                break;
            }
        }

    cout<<ans<<" ";
}

