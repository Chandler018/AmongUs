#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of students!" << endl;
        return 0;
    }

    // Max Heap
    priority_queue<int> maxHeap;
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int mark;

    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++) {
        cin >> mark;

        // Insert into both heaps
        maxHeap.push(mark);
        minHeap.push(mark);
    }

    cout << "\nMaximum marks: " << maxHeap.top() << endl;
    cout << "Minimum marks: " << minHeap.top() << endl;

    return 0;
}
