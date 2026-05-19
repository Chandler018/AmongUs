#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int heap[100];

    // Build Min Heap
    for(int i = 0; i < n; i++) {

        cout << "Enter marks: ";
        cin >> heap[i];

        int child = i;

        // Heapify upward
        while(child > 0) {

            int parent =
            (child - 1) / 2;

            if(heap[parent] >
               heap[child]) {

                int temp = heap[parent];

                heap[parent] =
                heap[child];

                heap[child] = temp;

                child = parent;
            }

            else
                break;
        }
    }

    // Display heap
    cout << "\nMin Heap:\n";

    for(int i = 0; i < n; i++)
        cout << heap[i] << " ";

    // Minimum marks
    cout << "\n\nMinimum Marks = "
         << heap[0];

    return 0;
}