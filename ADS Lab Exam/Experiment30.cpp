#include <iostream>
using namespace std;

#define SIZE 10

// Node for linked list
struct Node {
    string name;
    long long phone;
    Node* next;
};

class HashTable {

    Node* table[SIZE];

public:

    HashTable() {

        for(int i = 0; i < SIZE; i++)
            table[i] = NULL;
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

        Node* newNode = new Node;

        newNode->name = name;
        newNode->phone = phone;

        newNode->next = table[index];

        table[index] = newNode;
    }

    // Search record
    void search(string name) {

        int index =
        hashFunction(name);

        Node* temp = table[index];

        int comparisons = 0;

        while(temp != NULL) {

            comparisons++;

            if(temp->name == name) {

                cout << "\nRecord Found";

                cout << "\nName: "
                     << temp->name;

                cout << "\nPhone: "
                     << temp->phone;

                cout << "\nComparisons: "
                     << comparisons;

                return;
            }

            temp = temp->next;
        }

        cout << "\nRecord Not Found";
    }

    // Display table
    void display() {

        cout << "\nHash Table:\n";

        for(int i = 0; i < SIZE; i++) {

            cout << i << " -> ";

            Node* temp = table[i];

            while(temp != NULL) {

                cout << temp->name
                     << ":"
                     << temp->phone
                     << " -> ";

                temp = temp->next;
            }

            cout << "NULL\n";
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