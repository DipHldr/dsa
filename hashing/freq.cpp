#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)cin>>arr[i];
    int hash[100]={0};

    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    int q;
    while(q--){
        int number;
        cin>>number;
        cout<<"frequency: "<<hash[number]<<endl;
    }    
}