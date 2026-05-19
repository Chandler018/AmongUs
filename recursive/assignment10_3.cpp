#include <iostream>
using namespace std;

#define SIZE 10

struct Node{
    int key;
    Node* next;
};

//Tables
Node* table_chain[SIZE];

int table_linear[SIZE];
int table_quadratic[SIZE];
int table_double[SIZE];

//Counters
int chain_collisions = 0;

int linear_collisions = 0;
int quadratic_collisions = 0;
int double_collisions = 0;

int linear_probes = 0;
int quadratic_probes = 0;
int double_probes = 0;

//Hash Functions
int hash1(int key){
    return key % SIZE;
}

int hash2(int key){
    return 7 - (key % 7);
}

//Insert Chaining
void insert_chaining(int key){
    int index = hash1(key);

    Node* newNode = new Node();
    newNode->key = key;
    newNode->next = NULL;

    if (table_chain[index] == NULL)
    {
        table_chain[index] = newNode;
    }
    else
    {
        chain_collisions++;
        newNode->next = table_chain[index];
        table_chain[index] = newNode;
    }
}

//Linear Probing
void insert_linear(int key){
    int index = hash1(key);

    while (table_linear[index] != -1){
        linear_collisions++;
        linear_probes++;
        index = (index + 1) % SIZE;
    }

    table_linear[index] = key;
}

//Quadratic Probing
void insert_quadratic(int key){
    int index = hash1(key);
    int i = 1;

    while (table_quadratic[index] != -1){
        quadratic_collisions++;
        quadratic_probes++;
        index = (hash1(key) + i * i) % SIZE;
        i++;
    }

    table_quadratic[index] = key;
}

//Double Hashing
void insert_double(int key){
    int index = hash1(key);
    int step = hash2(key);
    int i = 1;

    while (table_double[index] != -1){
        double_collisions++;
        double_probes++;
        index = (index + i * step) % SIZE;
        i++;
    }

    table_double[index] = key;
}

void display_chaining(){
    cout << "\nChaining Table:\n";

    for (int i = 0; i < SIZE; i++){
        cout << i << " -> ";
        Node* temp = table_chain[i];

        while (temp != NULL){
            cout << temp->key << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
}

void display_open(int table[]){
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " : " << table[i] << endl;
    }
}

int main(){
    int keys[] = {23, 45, 13, 27, 88, 92, 31, 54};
    int n = 8;

    // initialize
    for (int i = 0; i < SIZE; i++)
    {
        table_chain[i] = NULL;
        table_linear[i] = -1;
        table_quadratic[i] = -1;
        table_double[i] = -1;
    }

    // insert
    for (int i = 0; i < n; i++)
    {
        insert_chaining(keys[i]);
        insert_linear(keys[i]);
        insert_quadratic(keys[i]);
        insert_double(keys[i]);
    }

    // display
    display_chaining();

    cout << "\nLinear Probing:\n";
    display_open(table_linear);

    cout << "\nQuadratic Probing:\n";
    display_open(table_quadratic);

    cout << "\nDouble Hashing:\n";
    display_open(table_double);

    // load factor
    float load_factor = (float)n / SIZE;

    cout << "\nLoad Factor: " << load_factor << endl;

    cout << "\nChaining Collisions: " << chain_collisions << endl;

    cout << "\nLinear Collisions: " << linear_collisions;
    cout << "\nLinear Probes: " << linear_probes << endl;

    cout << "\nQuadratic Collisions: " << quadratic_collisions;
    cout << "\nQuadratic Probes: " << quadratic_probes << endl;

    cout << "\nDouble Collisions: " << double_collisions;
    cout << "\nDouble Probes: " << double_probes << endl;

    return 0;
}
