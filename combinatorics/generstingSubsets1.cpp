#include<bits/stdc++.h>
using namespace std;
vector<int>subset;
void search(string str,int index=-1,string curr=""){
    int n=str.length();
    if(index==n)
      return;
  cout<<curr<<" ";
    for(int i=index+1;i<n;i++){
        curr+=str[i];
        search(str,i,curr);
        curr.erase(curr.length()-1);
    }
    return;
}

void powerSet(string str,int index=0,string curr=""){
    int n=str.length();
    if(index==n){
    cout<<curr<<" ";
    return;
    }

    powerSet(str,index+1,curr+str[index]);
    powerSet(str,index+1,curr);
}

int main()
{
    string str = "abc";
    // search(str);
    powerSet(str);
    return 0;
}