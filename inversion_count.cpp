#include<bits/stdc++.h>
using namespace std;
class segmentTrees
{
public:
    vector<int> seg;
    segmentTrees(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int ind, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r)
    {
        if (high < l || r < low)
            return 0;

        if (low >= l && r >= high)
            return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left+right;
    }
    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind]  += val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = seg[2 * ind + 1]+seg[2 * ind + 2];
    }
};
void solve(){
    int n,q;
    cin>>n;
    int arr[n];
    int mx=-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx=max(mx,arr[i]);
    }
    mx+=1;
    int freq[mx]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    segmentTrees st(mx+1);
    st.build(0,0,mx-1,freq);
    int cnt=0;
    for(int i=0;i<n;i++){
        freq[arr[i]]--;
        st.update(0,0,mx-1,arr[i],-1);
        cnt+=st.query(0,0,mx-1,1,arr[i]-1);
    }
    cout<<cnt<<endl;

}
int main(){
    int n;
    while(n--){
        solve();
    }
    return 0;
}