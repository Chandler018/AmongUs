#include <iostream>
using namespace std;

// Job structure
struct Job {
    char id;
    int deadline, profit;
};

// Swap function
void swap(Job &a,
          Job &b) {

    Job temp = a;
    a = b;
    b = temp;
}

int main() {

    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job job[100];

    // Input jobs
    for(int i = 0; i < n; i++) {

        cout << "\nEnter Job ID: ";
        cin >> job[i].id;

        cout << "Enter Deadline: ";
        cin >> job[i].deadline;

        cout << "Enter Profit: ";
        cin >> job[i].profit;
    }

    // Sort by profit
    for(int i = 0; i < n - 1; i++) {

        for(int j = i + 1; j < n; j++) {

            if(job[i].profit <
               job[j].profit) {

                swap(job[i], job[j]);
            }
        }
    }

    // Find maximum deadline
    int maxDeadline = 0;

    for(int i = 0; i < n; i++) {

        if(job[i].deadline >
           maxDeadline)

            maxDeadline =
            job[i].deadline;
    }

    char slot[100];

    bool filled[100] = {false};

    int totalProfit = 0;

    // Job Scheduling
    for(int i = 0; i < n; i++) {

        for(int j = job[i].deadline - 1;
            j >= 0; j--) {

            if(!filled[j]) {

                slot[j] = job[i].id;

                filled[j] = true;

                totalProfit +=
                job[i].profit;

                break;
            }
        }
    }

    // Display jobs
    cout << "\nSelected Jobs: ";

    for(int i = 0; i < maxDeadline; i++) {

        if(filled[i])
            cout << slot[i] << " ";
    }

    cout << "\nTotal Profit = "
         << totalProfit;

    return 0;
}