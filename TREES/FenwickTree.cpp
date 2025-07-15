#include<bits/stdc++.h>
using namespace std;

class Fenwick{
    int n;
    vector<int>BIT;
    public:
    Fenwick(int n){
        this->n=n;
        BIT.assign(n+1,0);
    }

    void update(int x,int delta){
        while(x<=n){
            BIT[x]+=delta;
            x+=x&(-x);
        }
    }

    void build(vector<int>&arr){
        for(int i=1;i<=n;i++){
            update(i,arr[i]);
        }
    }

    int prefix(int x){
        int sum=0;
        while(x>0){
            sum+=BIT[x];
            x-=x&(-x);
        }

        return sum;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    Fenwick ft(n);
    ft.build(arr);

    cout<<ft.prefix(6)<<endl;
    cout<<ft.prefix(6)-ft.prefix(3-1)<<endl;
    return 0;

}