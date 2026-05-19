#include <iostream>
#include <vector>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

void sortJobs(vector<Job> &jobs) {
    int n = jobs.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(jobs[j].profit < jobs[j + 1].profit) {
                swap(jobs[j], jobs[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter Job ID, Deadline, Profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sortJobs(jobs);

    int maxDeadline = 0;
    for(const auto &job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<int> slot(maxDeadline, -1);
    int totalProfit = 0;

    for(int i = 0; i < jobs.size(); i++) {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "\nJob Schedule:\n";
    for(int i = 0; i < maxDeadline; i++) {
        cout << "Slot " << i + 1 << ": ";
        if(slot[i] != -1) {
            cout << "Job " << jobs[slot[i]].id
                 << " (Profit: " << jobs[slot[i]].profit << ")";
        } else {
            cout << "Empty";
        }
        cout << endl;
    }

    cout << "Total Profit = " << totalProfit << endl;

    return 0;
}