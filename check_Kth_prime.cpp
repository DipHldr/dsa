#include<bits/stdc++.h>
using namespace std;
int N=86028121;
bool sieve[86028122];
vector<int>ds;
void createSieve(){
    for(int i=2;i<=N;i++){
        sieve[i]=true;
    }

    for(int i=2;i*i<=N;i++){
        if(sieve[i]==true){
            for(int j=i*i;j<=N;j+=i){
                sieve[j]=false;
            }
        }
    }

    for(int i=2;i<=N;i++){
        if(sieve[i]==true){
            ds.push_back(i);
        }
    }

    //to get the size of the array which will we get to be 86028121
    // int limit=5*1000000;
    // int size=0;
    // int cnt=0;
    // for(int i=2;;i++){
    //     if(sieve[i]==true){
    //         cnt++;
    //         if(cnt==limit){
    //             size=i;
    //             break;
    //         }
    //     }
    // }
}
int main(){
createSieve();
int q;
cin>>q;
while(q--){
    int k;
    cin>>k;
    cout<<"Kth prime number is: "<<ds[k-1]<<endl;
}
}
// 7
// 1
// 10
// 100
// 1000
// 10000
// 100000
// 1000000