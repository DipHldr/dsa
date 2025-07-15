#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int k=1;
    for(int i=0;i<n;i++){
        if(i%2==0){
            arr[i]=k++;
        }
    }
    for(int i=0;i<n;i++){
        if(i%2!=0){
            arr[i]=k++;
        }
    }

    //checking for correct output
    for(int i=1;i<n;i++){
        if(abs(arr[i]-arr[i-1])==1&&i+1<=n-1)swap(arr[i],arr[i+1]);
    }
    if(n>4||n<2){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    }
    else if(n==4){
        cout<<"2 4 1 3";
    }
    else{
        cout<<"NO SOLUTION";
    }
}