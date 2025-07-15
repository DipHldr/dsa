#include<bits/stdc++.h>
using namespace std;

bool checkPal(string &s,int i){
    int n=s.length();
    if(i>=n/2) return true; 

    if(s[i]!=s[n-i-1])
    return false; 

    checkPal(s,i+1);   
}

int main(){
    string s="aabcbccbdbaa";
    if(checkPal(s,0)){
        cout<<"palindrome"<<endl;
    }else{
        cout<<"not a palindrome"<<endl;
    }
}