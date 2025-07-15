#include<bits/stdc++.h>
using namespace std;
using ll=long long;
class Fenwick{
    ll n;
    vector<ll>BIT;
    public:
    Fenwick(ll n){
        this->n=n;
        BIT.assign(n+1,0);
    }

    void update(ll x,ll delta){
        while(x<=n){
            BIT[x]+=delta;
            x+=x&(-x);
        }
    }
    void build(vector<ll>&arr){
        for(ll i=1;i<=n;i++){
            update(i,arr[i]);
        }
    }

    ll prefix(ll x){
        ll sum=0;
        while(x>0){
            sum+=BIT[x];
            x-=x&(-x);
        }
        return sum;
    }
};
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    Fenwick ft(n);
    ft.build(arr);
    ll x,y;
    while(k--){
        cin>>x>>y;
        cout<<ft.prefix(y)-ft.prefix(x-1)<<endl;
    }

    return 0;
}