#include<bits/stdc++.h>
using namespace std;
//trying to implement run length encoding
int main(){
    string s;
    cin>>s;
    int n=s.length();
    int cnt=0;
    string ans;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }else{
            cnt++;
            ans+=to_string(cnt)+s[i];
            cnt=0;
        }
        // cout<<i<<endl;
    }

    int t=s.length();
    t-=1;
    cnt=1;
    while(s[t]==s[t-1]){
        cnt++;
        t--;
    }
    ans+=to_string(cnt)+s[s.length()-1];


    cout<<ans<<endl;

}