#include<bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

class solution{

    public:
    int tour(petrolPump p[],int n){
        int deficit=0;
        int balance=0;
        int start=0;

        for(int i=0;i<n;i++){
            balance+=p[i].petrol-p[i].distance;
            if(balance<0){
                start=i+1;
                deficit+=balance;
                balance=0;
            }
        }

            if(balance+deficit>=0){
                return start;
            }

            return -1;
        
    }    
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++){
            cin>>p[i].petrol>>p[i].distance;
        }
        solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
    return 0;
}