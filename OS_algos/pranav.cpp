
#include <iostream>
#include <vector>

using namespace std;

// Function to check if the requested resources can be allocated
bool isSafe(const vector<vector<int>>& max, const vector<vector<int>>& allocation, const vector<int>& available, int numProcesses, int numResources) {
    vector<int> work = available;
    vector<bool> finish(numProcesses, false);
    vector<int> safeSequence;

    int count = 0;
    while (count < numProcesses) {
        bool found = false;
        for (int i = 0; i < numProcesses; ++i) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < numResources; ++j) {
                    if (max[i][j] - allocation[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < numResources; ++j) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    safeSequence.push_back(i);
                    ++count;
                    found = true;
                }
            }
        }
        if (!found)
            break;
    }
    if (count == numProcesses) {
        cout << "System is in safe state.\nSafe sequence: ";
        for (int i = 0; i < numProcesses; ++i) {
            cout << "P" << safeSequence[i] << " | ";
        }
        cout << endl;
        return true;
    }
    else {
        cout << "System is not in safe state.\n";
        return false;
    }
}

int main() {
    int numProcesses, numResources;

    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    cout << "Enter the number of resources: ";
    cin >> numResources;

    // Max matrix: maximum demand of each process
    vector<vector<int>> max(numProcesses, vector<int>(numResources));
    cout << "Enter the maximum demand matrix:\n";
    for (int i = 0; i < numProcesses; ++i) {
        cout << "For process " << i << ": ";
        for (int j = 0; j < numResources; ++j) {
            cin >> max[i][j];
        }
    }

    // Allocation matrix: resources allocated to each process
    vector<vector<int>> allocation(numProcesses, vector<int>(numResources));
    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < numProcesses; ++i) {
        cout << "For process " << i << ": ";
        for (int j = 0; j < numResources; ++j) {
            cin >> allocation[i][j];
        }
    }

    // Available resources
    vector<int> available(numResources);
    cout << "Enter the available resources: ";
    for (int i = 0; i < numResources; ++i) {
        cin >> available[i];
    }

    // Check if the system is in a safe state
    isSafe(max, allocation, available, numProcesses, numResources);

    return 0;
}



