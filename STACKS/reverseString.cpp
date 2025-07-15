#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<char>s;
    string str="Hello World";
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }

    string rev="";

    while(!s.empty()){
        rev.push_back(s.top());
        s.pop();
    }
    cout<<"reversed String: "<<rev<<endl;
    return 0;
}