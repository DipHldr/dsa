#include<bits/stdc++.h>
using namespace std;

class compare{
    public:
    bool operator()(vector<int>&l,vector<int>&r){
        if(l[1]<r[1])return true;
        else if(l[1]==r[1])return l[0]<r[0];
    }
};

void first_come_first_serve(vector<int>&processId,vector<int>&arrivalTime,vector<int>&burstTime){
    int n=arrivalTime.size();
    int miniAT=INT_MAX,maxiCT=INT_MIN;
    vector<vector<int > >table(n,vector<int>(6,0));
    for(int i=0;i<n;i++){
        miniAT=min(miniAT,arrivalTime[i]);
        table[i][0]=processId[i];
        table[i][1]=arrivalTime[i];
        table[i][2]=burstTime[i];
    }
    sort(table.begin(),table.end(),compare());
    int miniAt=INT_MAX,maxiCt=INT_MIN;
    for(int i=0;i<n;i++){
        miniAt=min(miniAt,table[i][1]);
    }
    int time=miniAt;
    float sumtat=0,sumwt=0;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"Process ID"<<" | "<<"Arrival Time"<<" | "<<"Burst Time"<<" | "<<"Completion time"<<"   |   "<<"TAT"<<"  |   "<<"Waiting Time"<<" |   "<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;   
     for(int i=0;i<n;i++){
        time=max(time,table[i][1]);
        time+=table[i][2];
        table[i][3]=time;
        maxiCt=max(maxiCt,time);
        table[i][4]=table[i][3]-table[i][1];
        table[i][5]=table[i][4]-table[i][2];
        cout<<table[i][0]<<setw(16)<<table[i][1]<<setw(16)<<table[i][2]<<setw(16)<<table[i][3]<<setw(16)<<table[i][4]<<setw(16)<<table[i][5]<<endl;
        sumtat+=table[i][4];
        sumwt+=table[i][5];
    }
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"Average waiting time : "<<sumwt/n<<endl;
    cout<<"Average TAT : "<<sumtat/n<<endl;
    cout<<"Scheduling length : "<<maxiCt-miniAt<<endl;
    cout<<"Throughput : "<<n/(float(maxiCt-miniAt))<<endl;

}

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<int>processId(n);
    vector<int>arrivalTime(n);
    vector<int>burstTime(n);
    for(int i=0;i<n;i++){
        int pId,aT,bT;
        cout<<"Enter process ID, arrival time, burst time : ";
        cin>>pId>>aT>>bT;
        processId[i]=pId;
        arrivalTime[i]=aT;
        burstTime[i]=bT;
    }
    first_come_first_serve(processId,arrivalTime,burstTime);

    return 0;
}