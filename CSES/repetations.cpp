#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int count=1;
    int maxi=INT_MIN;

    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1])count++;
        else count=1;

          maxi=max(maxi,count);
    }
    if(s.length()>1){
    cout<<maxi<<" ";
    }
    else{
        cout<<1<<" ";
    }
}