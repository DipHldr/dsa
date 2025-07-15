#include<bits/stdc++.h>
using namespace std;

class heap{

    int arr[100];
    int size;
    public:
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
       size=size+1;
       int index=size;
       arr[index]=val;
       while(index>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[index],arr[parent]);
            index=parent;
        }else{
            return;
        }
       }
    }

    void delete_From_Heap(){
        if(size==0){
            cout<<"nothing to delete\n";
            return;
        }
        arr[1]=arr[size];
        size--;
        
        int i=1;
        while(i<=size){
            int right=2*i+1;
            int left=2*i;
            int largestIndex=i;
            if(right<=size && arr[largestIndex]<arr[right]){
                largestIndex=right;
            }if(left<=size && arr[largestIndex]<arr[left]){
                largestIndex=left;
            }
            if(largestIndex!=i){
                swap(arr[largestIndex],arr[i]);
                i=largestIndex;
            }
            else{
                break;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};
void heapify(int arr[],int n,int i){
    int largest=i;
    int right=2*i+1;
    int left=2*i;
    if(left<n&&arr[largest]<arr[left]){
        largest=left;
    }if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
     swap(arr[size],arr[1]);
     size--;
     heapify(arr,size,1);   
    }
}
int main(){
    
    heap h;
    h.insert(60);    
    h.insert(55);
    h.insert(50);
    h.insert(30);
    h.insert(40);    
    h.insert(20);    
    h.insert(70);
    h.print();
    h.delete_From_Heap();
    h.delete_From_Heap();
    h.print();
    int arr[]={-1,54,53,55,52,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=n/2-1;i>0;i--){
        heapify(arr,n,i);
    }

    cout<<"\nprinting the array\n";
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    heapsort(arr,n);
    cout<<endl;
    // istream_iterator<int> cin_it(cin);
    // istream_iterator<int> eos;
    cout<<"sorted array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    // ostream_iterator<int> cout_it(cout," ");
    // copy(arr+1,arr+n,cout_it);
    return 0;
}