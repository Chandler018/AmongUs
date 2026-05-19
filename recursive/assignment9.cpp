#include <iostream>
using namespace std;

struct Node {
    string name;
    string phone;
    Node* next;
};

struct Client {
    string name;
    string phone;
};

class HashTable {
    int size;
    Client *linear;
    Node **chain;

public:

    HashTable(int s) {
        size = s;

        linear = new Client[size];
        chain = new Node*[size];

        for(int i=0;i<size;i++) {
            linear[i].name = "";
            chain[i] = NULL;
        }
    }

    //ASCII SUM
    int asciiSum(string name) {
        int sum = 0;

        for(int i=0;i<name.length();i++) {
            sum += int(name[i]);
        }

        return sum; 
    }

    //HASH FUNCTION
    int hashFunc(string name) {
        return asciiSum(name) % size;
    }

    //INSERT LINEAR PROBING
    void insertLinear(string name, string phone) {

        int idx = hashFunc(name);

        cout<<"\nInserting "<<name;
        cout<<"\nASCII Sum = "<<asciiSum(name);
        cout<<"\nInitial Hash Index = "<<idx<<endl;

        int original = idx;

        while(linear[idx].name != "") {

            cout<<"Collision at idx "<<idx<<endl;

            idx = (idx + 1) % size;

            cout<<"Trying idx "<<idx<<endl;

            if(idx == original) {
                cout<<"Hash table full\n";
                return;
            }
        }

        linear[idx].name = name;
        linear[idx].phone = phone;

        cout<<"Inserted at index "<<idx<<endl;
    }

    //INSERT CHAINING
    void insertChain(string name, string phone) {

        int idx = hashFunc(name);

        Node *temp = new Node;
        temp->name = name;
        temp->phone = phone;
        temp->next = NULL;

        if(chain[idx] == NULL) {
            chain[idx] = temp;
        }
        else {

            Node *ptr = chain[idx];

            while(ptr->next != NULL) {
                ptr = ptr->next;
            }

            ptr->next = temp;
        }
    }

    //SEARCH LINEAR
    int searchLinear(string name) {

        int idx = hashFunc(name);
        int comparisons = 1;

        while(linear[idx].name != name) {

            idx = (idx + 1) % size;
            comparisons++;

            if(linear[idx].name == "")
                break;
        }

        return comparisons;
    }

    //SEARCH CHAINING
    int searchChain(string name) {

        int idx = hashFunc(name);
        int comparisons = 0;

        Node *ptr = chain[idx];

        while(ptr != NULL) {

            comparisons++;

            if(ptr->name == name)
                break;

            ptr = ptr->next;
        }

        return comparisons;
    }

    //DISPLAY LINEAR TABLE
    void displayLinear() {

        cout<<"\n\nLinear Probing Table\n";

        for(int i=0;i<size;i++) {

            cout<<i<<" -> ";

            if(linear[i].name != "")
                cout<<linear[i].name<<" : "<<linear[i].phone;

            cout<<endl;
        }
    }

    //DISPLAY CHAINING TABLE
    void displayChain() {

        cout<<"\nChaining Table\n";

        for(int i=0;i<size;i++) {

            cout<<i<<" -> ";

            Node *ptr = chain[i];

            while(ptr != NULL) {

                cout<<"("<<ptr->name<<","<<ptr->phone<<") ";
                ptr = ptr->next;
            }

            cout<<endl;
        }
    }
};

int main() {

    int size,n;
    string name,phone;

    cout<<"Enter hash table size: ";
    cin>>size;

    HashTable ht(size);

    cout<<"Enter number of clients: ";
    cin>>n;

    for(int i=0;i<n;i++) {

        cout<<"\nEnter Name: ";
        cin>>name;

        cout<<"Enter Phone: ";
        cin>>phone;

        ht.insertLinear(name,phone);
        ht.insertChain(name,phone);
    }

    ht.displayLinear();
    ht.displayChain();

    cout<<"\n\nSearch Comparisons\n";

    for(int i=0;i<n;i++) {

        cout<<"\nEnter name to search: ";
        cin>>name;

        cout<<"Linear Probing Comparisons: "<<ht.searchLinear(name)<<endl;
        cout<<"Chaining Comparisons: "<<ht.searchChain(name)<<endl;
    }

    return 0;
}
