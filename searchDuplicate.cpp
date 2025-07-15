/*Problem: Given a list of n strings si, each no longer than m characters, find all the duplicate strings and divide them into groups.
*/

#include<bits/stdc++.h>
using namespace std;

long long computeHash(string& s){
    const int p=31;
    const int m=1e9+9;
    long long hash_value=0;
    long long p_pow=1;

    for(char c:s){
        hash_value=(hash_value+(c-'a'+1)*p_pow)%m;
        p_pow=(p_pow*p)%m;
    }

    return hash_value;    
}

vector<vector<int>> groupIdenticalStrings(vector<string>s){
    int n=s.size();
    vector<pair<long long,int>>hash(n);
    for(int i=0;i<s.size();i++){
        hash[i]={computeHash(s[i]),i};
    }

    sort(hash.begin(),hash.end());

    vector<vector<int>>groups;
    for(int i=0;i<n;i++){
        if(i==0||hash[i].first!=hash[i-1].first){
            groups.emplace_back();
        }

        groups.back().push_back(hash[i].second);
    }
    return groups;
}

int main(){
    vector<string>s={"apple","banana","apple","banana","orange","cherry"};
    vector<vector<int>>groups=groupIdenticalStrings(s);

    for(auto ele:groups){
        cout<<"( ";
        for(auto it:ele){
            cout<<it<<" ";
        }
        cout<<")"<<endl;
    }
}