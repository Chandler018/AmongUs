#include <iostream>
using namespace std;

// User structure
struct User {
    string name;
    int comments;
};

int main() {

    int n;

    cout << "Enter number of users: ";
    cin >> n;

    User user[100];

    // Input details
    for(int i = 0; i < n; i++) {

        cout << "\nEnter name: ";
        cin >> user[i].name;

        cout << "Enter comments: ";
        cin >> user[i].comments;
    }

    int maxIndex = 0;
    int minIndex = 0;

    // Find maximum and minimum comments
    for(int i = 1; i < n; i++) {

        if(user[i].comments >
           user[maxIndex].comments)

            maxIndex = i;

        if(user[i].comments <
           user[minIndex].comments)

            minIndex = i;
    }

    // Display result
    cout << "\nUser with Maximum Comments:";
    cout << "\nName: "
         << user[maxIndex].name;

    cout << "\nComments: "
         << user[maxIndex].comments;

    cout << "\n\nUser with Minimum Comments:";
    cout << "\nName: "
         << user[minIndex].name;

    cout << "\nComments: "
         << user[minIndex].comments;

    return 0;
}