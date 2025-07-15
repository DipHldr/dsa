#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={-1,-2,-3,-4,-5};
    sort(arr.begin(),arr.end());
    for(auto x:arr)
    cout<<x<<" ";
}