/*B. Implement quick sort for sorting students credits they received in last 2 years and
display the names of top 3 students.*/
#include <iostream>
using namespace std;

struct Student{
    string name;
    int credits;
};

void swap(Student &a, Student &b){
    Student temp = a;
    a = b;
    b = temp;
}

//Partition
int partition(Student arr[], int low, int high){
    int pivot = arr[high].credits;
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j].credits > pivot){ // descending order
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

//Quick Sort
void quickSort(Student arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    Student students[] = {
        {"Tanmay", 120},
        {"Rohan", 150},
        {"Vishal", 110},
        {"Kushagra", 170},
        {"Kaustubh", 140}
    };

    int n = 5;

    quickSort(students, 0, n - 1);

    cout << "Top 3 Students:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << students[i].name << " - " << students[i].credits << endl;
    }

    return 0;
}
