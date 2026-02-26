#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparison function to sort jobs by profit descending
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[100];
    int maxDeadline = 0;

    cout << "Enter Job ID, Deadline, Profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Sort jobs by profit (descending)
    sort(jobs, jobs + n, cmp);

    char result[100];       // store job sequence
    bool slot[100] = {0};   // mark free slots

    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (from last possible slot)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                break;
            }
        }
    }

    cout << "\nJob sequence: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i])
            cout << result[i] << " ";
    }

    // Calculate total profit
    int totalProfit = 0;
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) {
            for (int j = 0; j < n; j++)
                if (jobs[j].id == result[i])
                    totalProfit += jobs[j].profit;
        }
    }

    cout << "\nTotal Profit: " << totalProfit;

    return 0;
}

