#include<bits/stdc++.h>
using namespace std;
void intToWord(int n,string arr[]){
    //base case
    if(n==0){
        return ;
    }
    //processing
    int l=n%10;
    n=n/10;
    //recursion
    intToWord(n,arr);
    //printing
    cout<<arr[l]<<" ";
}
int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    intToWord(n,arr);
}