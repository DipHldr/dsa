#include<bits/stdc++.h>
using namespace std;
class info{
    public:
    int open,close,full;
    info(){
        open=0;
        close=0;
        full=0;
    }
    info(int _open,int _close,int _full){
        open=_open;
        close=_close;
        full=_full;
    }
};
info merge(info left,info right){
    info ans= info(0,0,0);
    ans.full=left.full+right.full+min(left.open,right.close);
    ans.open=left.open+right.open-min(left.open,right.close);
    ans.close=left.close+right.close-min(left.open,right.close);

    return ans;
}
void build(int ind,int low,int high,string s,info seg[]){
    if(low==high){
        seg[ind] = info(s[low]=='(',s[low]==')',0);
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,s,seg);
    build(2*ind+2,mid+1,high,s,seg);
    seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);

}
info query(int ind,int low,int high,int l,int r,info seg[]){
    if(r<low||high<l)return info();
    if(low>=l&&high<=r)return seg[ind];
    int mid=(low+high)/2;
    info left=query(2*ind+1,low,mid,l,r,seg);
    info right=query(2*ind+2,mid+1,high,l,r,seg);
    return merge(left,right);
}
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    info seg[4*n];
    build(0,0,n-1,s,seg);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        info ans=query(0,0,n-1,l,r,seg);
        cout<<"ans: "<<ans.full*2<<endl;
    }

}
int main(){
    solve();
    return 0;
}