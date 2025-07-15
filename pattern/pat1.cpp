#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2==0)
        cout<<"0";
        else cout<<"1";
        for(int j=2;j<=i;j++){
            if(i%2==0){
                if(j%2!=0){
                    cout<<"0";
                }else{
                    cout<<"1";
                }
            }else{
                if(j%2==0){
                    cout<<"0";
                }else{
                    cout<<"1";
                }
            }
            
        }
        cout<<endl;
    }
}
