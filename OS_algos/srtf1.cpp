#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int p_id;
    int arrival_time;
    int burst_time;
    int r_burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int response_time;
    Process(int id, int arrival_time, int burst_time) : p_id(id), arrival_time(arrival_time), burst_time(burst_time), r_burst_time(burst_time), completion_time(-1), turn_around_time(-1), waiting_time(-1), response_time(-1) {}
};

class compare_arrival_time
{
public:
    bool operator()(Process &left, Process &right)
    {
        if (left.arrival_time < right.arrival_time || (left.arrival_time == right.arrival_time && left.p_id < right.p_id))
            return true;
        return false;
    }
};

class compare_rburst_time
{
public:
    bool operator()(pair<Process, int> &below, pair<Process, int> &above)
    {
        if (below.first.r_burst_time > above.first.r_burst_time || (below.first.r_burst_time == above.first.r_burst_time && (below.first.arrival_time > above.first.arrival_time || (below.first.arrival_time == above.first.arrival_time && below.first.p_id > above.first.p_id))))
            return true;
        return false;
    }
};

void calc_waiting_time_turn_around_time(vector<Process> &processes, float &avg_turn_around_time, float &avg_waiting_time, float &avg_res_time, float &scheduling_len, float &throughput)
{
    int n = processes.size();
    avg_turn_around_time = avg_res_time = avg_waiting_time = scheduling_len = throughput = 0;
    for (int i = 0; i < n; i++)
    {
        processes[i].turn_around_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;
        avg_turn_around_time += processes[i].turn_around_time;
        avg_waiting_time += processes[i].waiting_time;
        avg_res_time += processes[i].response_time;
        scheduling_len = max(scheduling_len, (float)processes[i].completion_time);
    }
    avg_turn_around_time /= n;
    avg_res_time /= n;
    avg_waiting_time /= n;
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
    cout << "|-------------------------------------------------------------------------------------------------------------------------------------------|\n";
    cout << "|" << pad("Process ID") << "|" << pad("Arrival time") << "|" << pad("Burst Time") << "|" << pad("Completion Time") << "|" << pad("Turn Around Time") << "|" << pad("Waiting Time") << "|" << pad("Response Time") << "|\n";
    cout << "|-------------------------------------------------------------------------------------------------------------------------------------------|\n";
    for (int i = 0; i < n; i++)
    {
        cout << "|" << pad(to_string(processes[i].p_id)) << "|" << pad(to_string(processes[i].arrival_time)) << "|" << pad(to_string(processes[i].burst_time)) << "|" << pad(to_string(processes[i].completion_time)) << "|" << pad(to_string(processes[i].turn_around_time)) << "|" << pad(to_string(processes[i].waiting_time)) << "|" << pad(to_string(processes[i].response_time)) << "|\n";
    }
    cout << "|-------------------------------------------------------------------------------------------------------------------------------------------|\n";
}

void print_gantt_chart(vector<pair<int, int>> &gantt_chart, int sc_len)
{
    cout << "GANTT CHART : \n";
    int padding = 10;
    string line(padding * gantt_chart.size() + gantt_chart.size() + 1, '-');
    cout << line << endl;
    for (int i = 0; i < gantt_chart.size(); i++)
    {
        cout << "|" << pad("P" + to_string(gantt_chart[i].first), 10);
    }
    cout << "|\n";
    cout << line << endl;
    for (int i = 0; i < gantt_chart.size(); i++)
    {
        cout << gantt_chart[i].second << pad("", 10);
    }
    cout << sc_len << endl;
}

void SRTF(vector<Process> &processes)
{
    vector<pair<int, int>> gantt_chart;
    int n = processes.size();
    sort(processes.begin(), processes.end(), compare_arrival_time());
    priority_queue<pair<Process, int>, vector<pair<Process, int>>, compare_rburst_time> ready_queue;
    int time = processes[0].arrival_time;
    int counter = 0;
    while (counter < n && processes[counter].arrival_time == time)
        ready_queue.push({processes[counter], counter++});
    while (!ready_queue.empty())
    {
        pair<Process, int> top = ready_queue.top();
        ready_queue.pop();
        Process current_process = top.first;
        int position = top.second;
        if (gantt_chart.empty() || gantt_chart.back().first != position)
            gantt_chart.push_back({position, time});
        if (current_process.response_time == -1)
        {
            current_process.response_time = processes[position].response_time = time - processes[position].arrival_time;
        }
        int next_time = -1;
        if (counter < n)
            next_time = processes[counter].arrival_time;
        if (next_time == -1)
        {
            time += current_process.r_burst_time;
            processes[position].completion_time = time;
        }
        else
        {
            int left = next_time - time;
            if (current_process.r_burst_time <= left)
            {
                time += current_process.r_burst_time;
                processes[position].completion_time = time;
            }
            else
            {
                time += left;
                processes[position].r_burst_time -= left;
                current_process.r_burst_time -= left;
                ready_queue.push({current_process, position});
            }
        }
        if (ready_queue.empty() && counter < n)
            time = processes[counter].arrival_time;
        while (counter < n && time == processes[counter].arrival_time)
            ready_queue.push({processes[counter], counter++});
    }
    float avg_turn_around_time, avg_waiting_time, avg_res_time, scheduling_len, throughput;
    calc_waiting_time_turn_around_time(processes, avg_turn_around_time, avg_waiting_time, avg_res_time, scheduling_len, throughput);
    print_table(processes);
    print_gantt_chart(gantt_chart, scheduling_len);
    cout << "Average Turn Around Time : " << avg_turn_around_time << endl;
    cout << "Average Waiting Time     : " << avg_waiting_time << endl;
    cout << "Average Response Time    : " << avg_res_time << endl;
    cout << "Scheduling Length        : " << scheduling_len << endl;
    cout << "Throughput               : " << throughput << endl;
}

int main()
{
    // CASE 1:
    vector<Process> processes = {Process(0, 0, 10), Process(1, 1, 5), Process(2, 2, 1)};
    SRTF(processes);
    return 0;
}