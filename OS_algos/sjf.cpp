#include <bits/stdc++.h>
using namespace std;

class process
{
    public:
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    process():pid(-1), arrival_time(-1), burst_time(-1), completion_time(-1), turnaround_time(-1), waiting_time(-1), response_time(-1) {}
    process(int id,int at,int bt):pid(id),arrival_time(at),burst_time(bt),completion_time(-1),turnaround_time(-1), waiting_time(-1), response_time(-1){}

};
void printChart(vector<process>p){
    int n=p.size();
cout << "#P\t"
         << "AT\t"
         << "BT\t"
         << "ST\t"
         << "CT\t"
         << "TAT\t"
         << "WT\t"
         << "RT\t"
         << "\n"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].arrival_time << "\t" 
        << p[i].burst_time << "\t" << p[i].start_time << "\t" 
        << p[i].completion_time << "\t" << p[i].turnaround_time << "\t" 
        << p[i].waiting_time << "\t" << p[i].response_time << "\t"
        << "\n"
        << endl;
    }
    
}
void SJF(vector<process>p){
    int n=p.size();
    float avg_turnaround_time, avg_waiting_time, avg_response_time, cpu_utilisation, throughput;
    int total_turnaround_time = 0, total_waiting_time = 0, total_response_time = 0, total_idle_time = 0, is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));

    cout<<setprecision(2)<<fixed;

    int current_time = 0, completed = 0, prev = 0;

    while (completed != n)
    {
        int idx = -1;
        int mn = 10000000;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && is_completed[i] == 0)
            {
                if (p[i].burst_time < mn)
                {
                    mn = p[i].burst_time;
                    idx = i;
                }
                if (p[i].burst_time == mn)
                {
                    if (p[i].arrival_time < p[idx].arrival_time)
                    {
                        mn = p[i].burst_time;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            p[idx].start_time = current_time;
            p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            p[idx].response_time = p[idx].start_time - p[idx].arrival_time;

            total_turnaround_time += p[idx].turnaround_time;
            total_waiting_time += p[idx].waiting_time;
            total_response_time += p[idx].response_time;
            total_idle_time += p[idx].start_time - prev;

            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].completion_time;
            prev = current_time;
        }
        else
        {
            current_time++;
        }
    }

    int min_arrival_time = 10000000, max_completion_time = -1;
    for (int i = 0; i < n; i++)
    {
        min_arrival_time = min(min_arrival_time, p[i].arrival_time);
        max_completion_time = max(max_completion_time, p[i].completion_time);
    }

    avg_turnaround_time = (float)total_turnaround_time / n;
    avg_waiting_time = (float)total_waiting_time / n;
    avg_response_time = (float)total_response_time / n;
    cpu_utilisation = ((max_completion_time - total_idle_time) / (float)max_completion_time) * 100;
    throughput = float(n) / (max_completion_time - min_arrival_time);
    printChart(p);
    cout<<endl<<endl;
    cout << "Average Turnaround Time = " << avg_turnaround_time << endl;
    cout << "Average Waiting Time = " << avg_waiting_time << endl;
    cout << "Average Response Time = " << avg_response_time << endl;
    cout << "CPU Utilization = " << cpu_utilisation << "%" << endl;
    cout << "Throughput = " << throughput << " process/unit time" << endl;

    cout<<endl<<endl;
}

int main(){
    int n;
    vector<process>p={process(0,1,2),process(2,5,3),process(4,3,6),process(3,8,6)};
    SJF(p);    

    p.clear();

    cout << "Enter the number of processes: ";
    cin >> n;
    p.resize(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].arrival_time;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].burst_time;
        p[i].pid = i + 1;
        cout << endl;
    }
    SJF(p);  
}