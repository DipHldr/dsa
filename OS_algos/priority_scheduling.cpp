#include <bits/stdc++.h>
using namespace std;
class Process
{
public:
    int p_id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int response_time;

    Process() : p_id(-1), arrival_time(-1), burst_time(-1), priority(-1), remaining_burst_time(-1), completion_time(-1), turn_around_time(-1), waiting_time(-1), response_time(-1) {}
    Process(int id, int at, int bt, int pt) : p_id(id), arrival_time(at), burst_time(bt), priority(pt), remaining_burst_time(bt), completion_time(-1), turn_around_time(-1), waiting_time(-1), response_time(-1) {}
};
class compare
{
public:
    bool operator()(Process &left, Process &right)
    {
        if (left.arrival_time < right.arrival_time || (left.arrival_time == right.arrival_time && left.p_id < right.p_id))
            return true;
        return false;
    }
};

class compare_priority
{
public:
    bool operator()(pair<Process, int> &below, pair<Process, int> &above)
    {
        if (below.first.priority < above.first.priority ||
         (below.first.priority == above.first.priority && (below.first.arrival_time > above.first.arrival_time
          || (below.first.arrival_time == above.first.arrival_time && (below.first.p_id > above.first.p_id)))))
            return true;
        return false;
    }
};
void calc_wt_tat(vector<Process> &processes, float &avg_tat, float &avg_wt, float &avg_res_time, float &scheduling_len, float &throughput)
{
    int n = processes.size();
    avg_tat = avg_res_time = avg_wt = scheduling_len = throughput = 0;
    for (int i = 0; i < n; i++)
    {
        processes[i].turn_around_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;
        avg_tat += processes[i].turn_around_time;
        avg_wt += processes[i].waiting_time;
        avg_res_time += processes[i].response_time;
        scheduling_len = max(scheduling_len, (float)processes[i].completion_time);
    }
    avg_tat /= n;
    avg_res_time /= n;
    avg_wt /= n;
    throughput = n / scheduling_len;
}

string pad(string st, int n = 19)
{
    int left = n - st.size();
    int l = left / 2 + left % 2;
    string ans(l, ' ');
    string temp(left - l, ' ');
    ans += st + temp;
    return ans;
}

void print_table(vector<Process> &processes)
{
    int n = processes.size();
    cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
    cout << "|" << pad("Process ID") << "|" << pad("Arrival time") << "|" << pad("Burst Time") << "|" << pad("Priority") << "|" << pad("Completion Time") << "|" << pad("TAT") << "|" << pad("Waiting Time") << "|" << pad("Response Time") << "|\n";
    cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
    for (int i = 0; i < n; i++)
    {
        cout << "|" << pad(to_string(processes[i].p_id)) << "|" << pad(to_string(processes[i].arrival_time)) << "|" << pad(to_string(processes[i].burst_time)) << "|" << pad(to_string(processes[i].priority)) << "|" << pad(to_string(processes[i].completion_time)) << "|" << pad(to_string(processes[i].turn_around_time)) << "|" << pad(to_string(processes[i].waiting_time)) << "|" << pad(to_string(processes[i].response_time)) << "|\n";
    }
    cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
}

void print_gantt_chart(vector<pair<int, int>> &gantt_chart, int sc_len)
{
    cout << "GANTT CHART : \n";
    int padding = 10;
    int ex = 0;
    for (int i = 0; i < gantt_chart.size(); i++)
    {
        ex += (to_string(gantt_chart[i].second).size() - 1);
    }
    string line(padding * gantt_chart.size() + gantt_chart.size() + 1 + ex, '-');
    cout << line << endl;
    for (int i = 0; i < gantt_chart.size(); i++)
    {
        string extra = "";
        if (to_string(gantt_chart[i].second).size() >= 2)
            extra.assign(to_string(gantt_chart[i].second).size(), ' ');
        cout << "|" << extra << pad("P" + to_string(gantt_chart[i].first), 10);
    }
    cout << "|\n";
    cout << line << endl;
    for (int i = 0; i < gantt_chart.size(); i++)
    {
        cout << gantt_chart[i].second << pad("", 10);
    }
    cout << sc_len << endl;
}
void priority_scheduling(vector<Process> &processes)
{
    int n = processes.size();
    vector<pair<int, int>> gantt_chart;
    sort(processes.begin(), processes.end(), compare());
    priority_queue<pair<Process, int>, vector<pair<Process, int>>, compare_priority> ready_queue;
    int time = processes[0].arrival_time;
    int counter = 0;
    while (counter < n && time == processes[counter].arrival_time)
        ready_queue.push({processes[counter], counter++});
    while (!ready_queue.empty())
    {
        auto top = ready_queue.top();
        ready_queue.pop();
        Process current_process = top.first;
        int position = top.second;
        if (gantt_chart.empty() || (gantt_chart.back().first != current_process.p_id))
            gantt_chart.push_back({current_process.p_id, time});
        // else if (gantt_chart.back().first == current_process.p_id)
        //     gantt_chart.back().second = time;
        if (processes[position].response_time == -1)
            processes[position].response_time = time - processes[position].arrival_time;
        int next_at = -1;
        int left = -1;
        if (counter < n)
        {
            next_at = processes[counter].arrival_time;
            left = next_at - time;
        }
        if (next_at == -1 || processes[position].remaining_burst_time <= left)
        {
            time += processes[position].remaining_burst_time;
            processes[position].remaining_burst_time = 0;
            processes[position].completion_time = time;
        }
        else
        {
            processes[position].remaining_burst_time -= left;
            time += left;
        }
        while (counter < n && processes[counter].arrival_time <= time)
            ready_queue.push({processes[counter], counter++});
        if (processes[position].completion_time == -1)
            ready_queue.push({processes[position], position});
        if (ready_queue.empty() && counter < n)
        {
            time = processes[counter].arrival_time;
            while (counter < n && processes[counter].arrival_time <= time)
                ready_queue.push({processes[counter], counter++});
        }
    }
    float avg_tat, avg_wt, avg_res_time, scheduling_len, throughput;
    calc_wt_tat(processes, avg_tat, avg_wt, avg_res_time, scheduling_len, throughput);
    print_table(processes);
    print_gantt_chart(gantt_chart, scheduling_len);
    cout << "Average Turn Around Time : " << avg_tat << endl;
    cout << "Average Waiting Time     : " << avg_wt << endl;
    cout << "Average Response Time    : " << avg_res_time << endl;
    cout << "Scheduling Length        : " << scheduling_len << endl;
    cout << "Throughput               : " << throughput << endl;
}

int main()
{
    // CASE 1:
    vector<Process> processes = {Process(0, 0, 12, 1), Process(1, 2, 5, 2), Process(2, 4, 10, 3)};
    priority_scheduling(processes);
    // CASE 2:
    int n;
    cout << "Enter number of processes : ";
    cin >> n;
    processes.clear();
    processes.resize(n);
    int id = 0;
    for (auto &process : processes)
    {
        process.p_id = id;
        cout << "Enter arrival time and burst time and priority for process " << id++ << " : ";
        cin >> process.arrival_time >> process.burst_time >> process.priority;
        process.remaining_burst_time = process.burst_time;
    }
    priority_scheduling(processes);
    return 0;
}