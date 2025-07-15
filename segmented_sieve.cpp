#include<bits/stdc++.h>
using namespace std;
int n=1000000;
bool sieve[1000001];
void createSieve(){
    for(int i=2;i<=n;i++){
        sieve[i]=true;
    }

    for(int i=2;i*i<=n;i++){
        if(sieve[i]==true){
            for(int j=i*i;j<=n;j+=i){
                sieve[j]=false;
            }
        }
    }
}

vector<int> generatePrimes(int N){
    vector<int>p;
    for(int i=2;i<=N;i++){
        if(sieve[i]==true)
        p.push_back(i);
    }
    return p;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        //step 1: generate all primes till sqrt of r
        vector<int>primes=generatePrimes(sqrt(r));
        //step 2:
        //make a dummy array of size r-l+1 and mark everyone as 1
        int dummy[r-l+1];
        for(int i=0;i<r-l+1;i++){
            dummy[i]=1;
        } 

        //step 3:
        // for all prime numbers mark all its multiple as 0
        for(auto pr:primes){
            int firstMultiple= (l/pr)*pr;
            if(firstMultiple<l)firstMultiple+=pr;
            for(int j=max(firstMultiple,pr*pr);j<=r;j+=pr){
                primes[j-l]=0;
            }
        }

        //step 4:
        //get all the prime numbers
        for(int i=l;i<=r;i++){
            if(dummy[i-l]==1){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}