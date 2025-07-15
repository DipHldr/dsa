#include<bits/stdc++.h>
using namespace std;
void print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int partition(vector<int>&v,int low,int high){
    int pivot=v[low];
    int i=low;
    int j=high;
    while(i<j){
        while(v[i]<=pivot&&i<=high-1){
            i++;
        }
        while(v[j]>pivot&&j>=low+1){
            j--;
        }
        if(i<j)swap(v[i],v[j]);
    }
    swap(v[low],v[j]);
    return j;
}
void qs(vector<int>&v,int low,int high){
    if(low<high){
        int pIndex=partition(v,low,high);
        qs(v,low,pIndex-1);
        qs(v,pIndex+1,high);
    }
}
int main(){
vector<int>v={1,7,2,5,3,4,6};
int n=v.size();
qs(v,0,n-1);
print(v);

}