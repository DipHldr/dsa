#include<bits/stdc++.h>
using namespace std;
struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitTime;
};
void show(vector<Process>, int);
int average(vector<Process> processes, int i, int pc)
{
    int sum = 0;
    for (vector<Process>::iterator it = processes.begin(); it !=
                                                                processes.end();
         ++it)
    {
        if (i == 1)
            sum += it->turnaroundTime;
        if (i == 2)
            sum += it->waitTime;
    }
    return double(sum) / pc;
}
bool compareID(const Process &a, const Process &b)
{
    return a.id < b.id;
}
bool compareArrivalTime(const Process &a, const Process &b)
{
    return a.arrivalTime < b.arrivalTime;
}
void fcfs()
{
    int pc;
    cout<< "Enter Process count: ";
    cin >> pc;
    vector<Process> processes;
    int i = pc;
    while (i--)
    {
        Process p;
        cin >> p.id >> p.arrivalTime >> p.burstTime;
        processes.push_back(p);
    }
    sort(processes.begin(), processes.end(), compareID);
    sort(processes.begin(), processes.end(), compareArrivalTime);
    for (int i = 0; i < processes.size(); ++i)
    {
        if (i != 0)
        {
            if (processes[i].arrivalTime <= processes[i - 1].completionTime)
            {
                processes[i].completionTime = processes[i - 1].completionTime +
                                              processes[i].burstTime;
            }
            else
            {
                processes[i].completionTime = processes[i].arrivalTime +
                                              processes[i].burstTime;
            }
        }
        else
        {
            processes[i].completionTime = processes[i].arrivalTime +
                                          processes[i].burstTime;
        }
        processes[i].turnaroundTime = processes[i].completionTime -
                                      processes[i].arrivalTime;
        processes[i].waitTime = processes[i].turnaroundTime - processes
                                                                  [i]
                                                                      .burstTime;
    }
    show(processes, pc);
}
void show (vector<Process> processes, int pc)
{
cout << "\n----------------------------------Process Execution\
Order----------------------------------\n\n";
string names[] = {"Process ID", "Arrival Time", "Burst Time",
                           "Completion Time", "Turn around Time", "Wait time"};
cout << "+" <<setw(names[0].length() + 3) <<setfill('-') << "+"
              <<setw(names[1].length() + 3) <<setfill('-') << "+"
              <<setw(names[2].length() + 3) <<setfill('-') << "+"
              <<setw(names[3].length() + 3) <<setfill('-') << "+"
              <<setw(names[4].length() + 3) <<setfill('-') << "+"
              <<setw(names[5].length() + 3) <<setfill('-') << "+"
              <<endl;
cout << "| " <<setw(names[0].length()) << "Process ID"
              << "\
| "
              <<setw(names[1].length()) << "Arrival Time"
              << " | "
              <<setw(names[2].length()) << "Burst Time"
              << " | "
              <<setw(names[3].length()) << "Completion Time"
              << " | "
              <<setw(names[4].length()) << "Turn around Time"
              << " | "
              <<setw(names[5].length()) << "Wait Time"
              << " |"\
              <<endl;
 cout << "|" <<setw(names[0].length() + 3) <<setfill('-') << "+"
              << setw(names[1].length() + 3) <<setfill('-') << "+"
              << setw(names[2].length() + 3) <<setfill('-') << "+"
              << setw(names[3].length() + 3) <<setfill('-') << "+"
              << setw(names[4].length() + 3) <<setfill('-') << "+"
              << setw(names[5].length() + 3) << setfill('-') << "|"\
              << endl;
    for (const auto &process : processes)
    {
     cout << "|" << setw((names[0].length() + 3) / 2 + 2) << setfill(' ') << process.id << setw((names[0].length() + 3) / 2 - 1) << setfill(' ')
                  << "|" << setw((names[1].length() + 3) / 2 + 2) << setfill(' ') << process.arrivalTime << setw((names[1].length() + 3) / 2 - 1) << setfill(' ')
                  << "|" << setw((names[2].length() + 3) / 2 + 2) << setfill(' ') << process.burstTime << setw((names[2].length() + 3) / 2 - 1) << setfill(' ')
                  << "|" << setw((names[3].length() + 3) / 2 + 2) << setfill(' ') << process.completionTime << setw((names[3].length() + 3) / 2 - 2) << setfill(' ')
                  << "|" << setw((names[4].length() + 3) / 2 + 2) << setfill(' ') << process.turnaroundTime << setw((names[4].length() + 3) / 2 - 1) << setfill(' ')
                  << "|" << setw((names[5].length() + 3) / 2 + 2) << setfill(' ') << process.waitTime << setw((names[5].length() + 3) / 2 - 2) << setfill(' ')
                  << "|" << endl;
    }
 cout << "+" << setw(names[0].length() + 3) << setfill('-') << "+"
              << setw(names[1].length() + 3) << setfill('-') << "+"
              << setw(names[2].length() + 3) << setfill('-') << "+"
              << setw(names[3].length() + 3) << setfill('-') << "+"
              << setw(names[4].length() + 3) << setfill('-') << "+"
              << setw(names[5].length() + 3) << setfill('-') << "+"
              << endl;
 cout << endl
              << setw(60) << setfill(' ') << "Average Turnaround time : " << setw(10) << setfill(' ')
              << average(processes, 1, pc)
              << endl
              << setw(60) << setfill(' ') << "Average\
waiting time : "
              << setw(10) << setfill(' ') << average(processes, 2, pc)
              << endl
              << setw(60) << setfill(' ') << "Scheduling\
Length Ratio : "
              << setw(10) << setfill(' ') << processes[pc - 1].completionTime - processes[0].arrivalTime
              << endl
              << setw(60) << setfill(' ') << "Throughput : " << setw(10) << setfill(' ') << double(pc) / processes[pc - 1].completionTime << endl;
}
int main()
{
    fcfs();
    return 0;
}