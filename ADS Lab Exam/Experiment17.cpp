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
    bool visited[100];

public:

    Graph(int v) {

        vertices = v;

        adjList = new Node*[v];

        for(int i = 0; i < v; i++) {

            adjList[i] = NULL;
            visited[i] = false;
        }
    }

    // Add edge
    void addEdge(int src, int dest) {

        Node* newNode = new Node;

        newNode->vertex = dest;
        newNode->next = adjList[src];

        adjList[src] = newNode;

        // Undirected graph
        newNode = new Node;

        newNode->vertex = src;
        newNode->next = adjList[dest];

        adjList[dest] = newNode;
    }

    // BFS Traversal
    void BFS(int start) {

        int queue[100];

        int front = 0, rear = 0;

        visited[start] = true;

        queue[rear++] = start;

        while(front < rear) {

            int current = queue[front++];

            cout << current << " ";

            Node* temp = adjList[current];

            while(temp != NULL) {

                int v = temp->vertex;

                if(!visited[v]) {

                    visited[v] = true;

                    queue[rear++] = v;
                }

                temp = temp->next;
            }
        }
    }
};

int main() {

    int v, e;

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    Graph g(v);

    int src, dest;

    for(int i = 0; i < e; i++) {

        cout << "Enter edge: ";
        cin >> src >> dest;

        g.addEdge(src, dest);
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "\nBFS Traversal: ";

    g.BFS(start);

    return 0;
}