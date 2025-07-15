#include<iostream>
using namespace std;
void f1(int n){
    if(n==0){
        return;
    }
    cout<<"name"<<endl;
    f1(n-1);
}
void f2(int i,int n){
    
    cout<<i<<endl;
    if(i==n){
        return;
    }
    f2(i+1,n);
}
void f3(int n){
   if(n<1)
   return;

   f3(n-1);
   cout<<n<<endl;
}

void f4(int i,int n){
    
    if(i>n){
        return;
    }
    f4(i+1,n);
    cout<<i<<endl;    
}
int main(){
    int n;
    cin>>n;
    // f1(n);
    // f2(1,n);
    // f3(n);
    f4(1,n);
}