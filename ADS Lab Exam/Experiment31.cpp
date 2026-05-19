#include <iostream>
using namespace std;

// Student structure
struct Student {
    string name;
    int credits;
};

// Merge function
void merge(Student a[],
           int low,
           int mid,
           int high) {

    Student temp[100];

    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high) {

        if(a[i].credits <
           a[j].credits)

            temp[k++] = a[i++];

        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = temp[i];
}

// Merge Sort
void mergeSort(Student a[],
               int low,
               int high) {

    if(low < high) {

        int mid =
        (low + high) / 2;

        mergeSort(a, low, mid);

        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
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
    mergeSort(s, 0, n - 1);

    // Display sorted list
    cout << "\nStudents Sorted by Credits:\n";

    for(int i = 0; i < n; i++) {

        cout << s[i].name
             << " - "
             << s[i].credits
             << endl;
    }

    return 0;
}