#include<iostream>
using namespace std;
void print(string s){
    cout<<s<<endl;

}
void revstring(int i,int j,string &s){
    // print(s);
    if(j<i){
        return ;
    }
    swap(s[i],s[j]);
   revstring(i+1,j-1,s);
}

int main(){
    string s="abbab";
   revstring(0,s.length()-1,s);
   cout<<s<<endl;
   return 0;
}