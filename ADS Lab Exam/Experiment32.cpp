#include <iostream>
using namespace std;

// Student structure
struct Student {
    string name;
    int credits;
};

// Swap function
void swap(Student &a,
          Student &b) {

    Student temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(Student s[],
              int low,
              int high) {

    int pivot =
    s[low].credits;

    int i = low + 1;
    int j = high;

    while(i <= j) {

        while(i <= high &&
              s[i].credits <= pivot)

            i++;

        while(s[j].credits > pivot)
            j--;

        if(i < j)
            swap(s[i], s[j]);
    }

    swap(s[low], s[j]);

    return j;
}

// Quick Sort
void quickSort(Student s[],
               int low,
               int high) {

    if(low < high) {

        int p =
        partition(s, low, high);

        quickSort(s, low, p - 1);

        quickSort(s, p + 1, high);
    }
}

int main() {

    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Student s[100];

    // Input records
    for(int i = 0; i < n; i++) {

        cout << "\nEnter student name: ";
        cin >> s[i].name;

        cout << "Enter credits: ";
        cin >> s[i].credits;
    }

    // Sort records
    quickSort(s, 0, n - 1);

    // Display sorted records
    cout << "\nSorted Student Records:\n";

    for(int i = 0; i < n; i++) {

        cout << s[i].name
             << " - "
             << s[i].credits
             << endl;
    }

    return 0;
}