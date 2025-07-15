#include<iostream>
using namespace std;
bool isPalindrome(int i,int j,string s){
    if(j<i)
    return true;

    if(s[i]!=s[j])
    return false;
   
   return isPalindrome(i+1,j-1,s);
}
int main(){
    string s="aabbccbbaa";
    // bool res=isPalindrome(0,s.length()-1,s);
    if(isPalindrome(0,s.length()-1,s)){
        cout<<"is Palindrome "<<endl;
    }else{
        cout<<"Not a palindrome "<<endl;
    }
    return 0;
}