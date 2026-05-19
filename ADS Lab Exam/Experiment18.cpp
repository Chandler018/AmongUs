#include <iostream>
using namespace std;

// Node for adjacency list
struct Node {
    int vertex;
    Node* next;
};

// Graph class
class Graph {

    int vertices;
    Node** adjList;
    int degree[100];

public:

    Graph(int v) {

        vertices = v;

        adjList = new Node*[v];

        for(int i = 0; i < v; i++) {

            adjList[i] = NULL;
            degree[i] = 0;
        }
    }

    // Add friendship
    void addEdge(int src, int dest) {

        Node* newNode = new Node;

        newNode->vertex = dest;
        newNode->next = adjList[src];

        adjList[src] = newNode;

        newNode = new Node;

        newNode->vertex = src;
        newNode->next = adjList[dest];

        adjList[dest] = newNode;

        degree[src]++;
        degree[dest]++;
    }

    // User with maximum friends
    void maxFriends() {

        int max = degree[0];
        int user = 0;

        for(int i = 1; i < vertices; i++) {

            if(degree[i] > max) {

                max = degree[i];
                user = i;
            }
        }

        cout << "\nUser with Maximum Friends: "
             << user;

        cout << "\nNumber of Friends: "
             << max;
    }
};

int main() {

    int v, e;

    cout << "Enter number of users: ";
    cin >> v;

    cout << "Enter number of friendships: ";
    cin >> e;

    Graph g(v);

    int src, dest;

    for(int i = 0; i < e; i++) {

        cout << "Enter friendship: ";
        cin >> src >> dest;

        g.addEdge(src, dest);
    }

    g.maxFriends();

    return 0;
}