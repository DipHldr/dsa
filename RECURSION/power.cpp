#include<iostream>
using namespace std;
int power(int a,int b){
    if(b==0)
    return 1;
    if(b==1)
    return a;
   int ans=power(a,b/2);
   //if b is even
    if(b%2==0)
    return ans*ans;
    //if  b is odd
    else return a*ans*ans;
}
int main(){
    int a,b;
    cout<<"Enter a and b to find a^b"<<endl;
    cin>>a>>b;
   int res= power(a,b);
   cout<<res<<endl;
   return 0;
}