#include <iostream>
using namespace std;

#define MAX 20
#define INF 9999

// Edge structure
struct Edge {
    int src, dest, weight;
};

int main() {

    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    Edge e[MAX];

    // Input edges
    for(int i = 0; i < edges; i++) {

        cout << "Enter source, destination and weight: ";
        cin >> e[i].src
            >> e[i].dest
            >> e[i].weight;
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    int distance[MAX];

    // Initialize distances
    for(int i = 0; i < vertices; i++)
        distance[i] = INF;

    distance[source] = 0;

    // Relax edges V-1 times
    for(int i = 1; i <= vertices - 1; i++) {

        for(int j = 0; j < edges; j++) {

            int u = e[j].src;
            int v = e[j].dest;
            int w = e[j].weight;

            if(distance[u] != INF &&
               distance[u] + w < distance[v]) {

                distance[v] =
                distance[u] + w;
            }
        }
    }

    // Check negative cycle
    bool negativeCycle = false;

    for(int j = 0; j < edges; j++) {

        int u = e[j].src;
        int v = e[j].dest;
        int w = e[j].weight;

        if(distance[u] != INF &&
           distance[u] + w < distance[v]) {

            negativeCycle = true;
        }
    }

    // Display result
    if(negativeCycle) {

        cout << "\nNegative Weight Cycle Detected!";
    }

    else {

        cout << "\nShortest Distances:\n";

        for(int i = 0; i < vertices; i++) {

            cout << source
                 << " -> "
                 << i
                 << " = "
                 << distance[i]
                 << endl;
        }
    }

    return 0;
}