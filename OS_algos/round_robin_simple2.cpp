#include <bits/stdc++.h>

using namespace std;

struct Process
{
	int pid;
	int arrivalTime;
	int burstTime;
	int burstTimeRemaining; // the amount of CPU time remaining after each execution
	int completionTime;
	int turnaroundTime;
	int waitingTime;
	bool isComplete;
	bool inQueue;
};

/*
* At every time quantum or when a process has been executed before the time quantum,
* check for any new arrivals and push them into the queue
*/
void checkForNewArrivals(Process processes[], const int n, const int currentTime, queue<int> &readyQueue)
{
	for (int i = 0; i < n; i++)
	{
		Process p = processes[i];
		// checking if any processes has arrived
		// if so, push them in the ready Queue.
		if (p.arrivalTime <= currentTime && !p.inQueue && !p.isComplete)
		{
			processes[i].inQueue = true;
			readyQueue.push(i);
		}
	}
}

/*
* Context switching takes place at every time quantum
* At every iteration, the burst time of the processes in the queue are handled using this method
*/
void updateQueue(Process processes[], const int n, const int quantum, queue<int> &readyQueue, 
int currentTime, int &programsExecuted)
{
	int i = readyQueue.front();
	readyQueue.pop();

	// if the process is going to be finished executing, 
	// ie, when it's remaining burst time is less than time quantum
	// mark it completed and increment the current time
	// and calculate its waiting time and turnaround time
	if (processes[i].burstTimeRemaining <= quantum)
	{
		processes[i].isComplete = true;
		currentTime += processes[i].burstTimeRemaining;
		processes[i].completionTime = currentTime;
		processes[i].waitingTime = processes[i].completionTime - processes[i].arrivalTime - processes[i].burstTime;
		processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;

		if (processes[i].waitingTime < 0)
			processes[i].waitingTime = 0;

		processes[i].burstTimeRemaining = 0;

		// if all the processes are not yet inserted in the queue,
		// then check for new arrivals
		if (programsExecuted != n)
		{
			checkForNewArrivals(processes, n, currentTime, readyQueue);
		}
	}
	else
	{
		// the process is not done yet. But it's going to be pre-empted 
		// since one quantum is used
		// but first subtract the time the process used so far
		processes[i].burstTimeRemaining -= quantum;
		currentTime += quantum;
        

		// if all the processes are not yet inserted in the queue,
		// then check for new arrivals
		if (programsExecuted != n)
		{
			checkForNewArrivals(processes, n, currentTime, readyQueue);
		}
		// insert the incomplete process back into the queue
		readyQueue.push(i);
	}
}

/*
* Just a function that outputs the result in terms of their PID.
*/
void output(Process processes[], const int n)
{
	double avgWaitingTime = 0;
	double avgTurntaroundTime = 0;
	// sort the processes array by processes.PID
	sort(processes, processes + n, [](const Process &p1, const Process &p2)
		{ return p1.pid < p2.pid; });

	for (int i = 0; i < n; i++)
	{
		cout << "Process " << processes[i].pid << ": Waiting Time: " << processes[i].waitingTime << " Turnaround Time: " << processes[i].turnaroundTime << endl;
		avgWaitingTime += processes[i].waitingTime;
		avgTurntaroundTime += processes[i].turnaroundTime;
	}
	cout << "Average Waiting Time: " << avgWaitingTime / n << endl;
	cout << "Average Turnaround Time: " << avgTurntaroundTime / n << endl;
}

/* 
* This function assumes that the processes are already sorted according to their arrival time
*/
void roundRobin(Process processes[], int n, int quantum)
{
	queue<int> readyQueue;
	readyQueue.push(0); // initially, pushing the first process which arrived first
	processes[0].inQueue = true;

	int currentTime = 0; // holds the current time after each process has been executed
	int programsExecuted = 0; // holds the number of programs executed so far

	while (!readyQueue.empty())
	{
		updateQueue(processes, n, quantum, readyQueue, currentTime, programsExecuted);
	}
}

int main()
{
	int n, quantum;

	cout << "Enter the number of processes: ";
	cin >> n;
	cout << "Enter time quantum: ";
	cin >> quantum;

	Process processes[n + 1];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter arrival time and burst time of each process " << i + 1 << ": ";
		cin >> processes[i].arrivalTime;
		cin >> processes[i].burstTime;
		processes[i].burstTimeRemaining = processes[i].burstTime;
		processes[i].pid = i + 1;
		cout << endl;
	}

	// stl sort in terms of arrival time
	sort(processes, processes + n, [](const Process &p1, const Process &p2)
		{ return p1.arrivalTime < p2.arrivalTime; });

	roundRobin(processes, n, quantum);

	output(processes, n);

	return 0;
}
