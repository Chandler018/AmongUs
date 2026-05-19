#include <iostream>
using namespace std;

#define MAX 10
#define INF 9999

int main() {

    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[MAX][MAX];

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cin >> cost[i][j];

            // Replace 0 with INF
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    int distance[MAX];
    bool visited[MAX];

    // Initialize
    for(int i = 0; i < n; i++) {

        distance[i] = cost[source][i];

        visited[i] = false;
    }

    distance[source] = 0;

    visited[source] = true;

    // Dijkstra Algorithm
    for(int count = 1; count < n - 1; count++) {

        int min = INF;
        int nextVertex;

        // Find minimum distance vertex
        for(int i = 0; i < n; i++) {

            if(!visited[i] &&
               distance[i] < min) {

                min = distance[i];

                nextVertex = i;
            }
        }

        visited[nextVertex] = true;

        // Update distances
        for(int i = 0; i < n; i++) {

            if(!visited[i] &&
               min + cost[nextVertex][i]
               < distance[i]) {

                distance[i] =
                min + cost[nextVertex][i];
            }
        }
    }

    // Display shortest distances
    cout << "\nShortest Distances:\n";

    for(int i = 0; i < n; i++) {

        cout << source
             << " -> "
             << i
             << " = "
             << distance[i]
             << endl;
    }

    return 0;
}