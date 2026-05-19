#include <iostream>
using namespace std;

#define SIZE 10

// Record structure
struct Record {
    string name;
    long long phone;
};

class HashTable {

    Record table[SIZE];

public:

    HashTable() {

        for(int i = 0; i < SIZE; i++)
            table[i].phone = -1;
    }

    // Hash Function
    int hashFunction(string name) {

        return name.length() % SIZE;
    }

    // Insert record
    void insert(string name,
                long long phone) {

        int index =
        hashFunction(name);

        // Linear Probing
        while(table[index].phone != -1)
            index = (index + 1) % SIZE;

        table[index].name = name;
        table[index].phone = phone;
    }

    // Search record
    void search(string name) {

        int index =
        hashFunction(name);

        int start = index;

        while(table[index].phone != -1) {

            if(table[index].name == name) {

                cout << "\nRecord Found";
                cout << "\nName: "
                     << table[index].name;

                cout << "\nPhone: "
                     << table[index].phone;

                return;
            }

            index = (index + 1) % SIZE;

            if(index == start)
                break;
        }

        cout << "\nRecord Not Found";
    }

    // Display table
    void display() {

        cout << "\nHash Table:\n";

        for(int i = 0; i < SIZE; i++) {

            cout << i << " -> ";

            if(table[i].phone != -1)

                cout << table[i].name
                     << " : "
                     << table[i].phone;

            cout << endl;
        }
    }
};

int main() {

    HashTable h;

    int n;

    string name;

    long long phone;

    cout << "Enter number of records: ";
    cin >> n;

    // Insert records
    for(int i = 0; i < n; i++) {

        cout << "\nEnter name: ";
        cin >> name;

        cout << "Enter phone number: ";
        cin >> phone;

        h.insert(name, phone);
    }

    h.display();

    // Search record
    cout << "\nEnter name to search: ";
    cin >> name;

    h.search(name);

    return 0;
}