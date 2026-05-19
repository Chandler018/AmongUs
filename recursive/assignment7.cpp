#include <iostream>
#include <climits>
using namespace std;

#define MAX 10
#define INF 99999

int V;   // Number of vertices

/* ---------------- DIJKSTRA ---------------- */
void dijkstra(int graph[MAX][MAX], int src) {
    int dist[MAX], visited[MAX] = {0};

    for(int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++) {

        int min = INF, u = -1;

        for(int i = 0; i < V; i++)
            if(!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for(int v = 0; v < V; v++)
            if(!visited[v] && graph[u][v] &&
               dist[u] != INF &&
               dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "\nDijkstra Shortest Distances:\n";
    for(int i = 0; i < V; i++)
        cout << "To " << i << " = " << dist[i] << endl;
}

/* ---------------- BELLMAN FORD ---------------- */
void bellmanFord(int edges[][3], int E, int src) {

    int dist[MAX];

    for(int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for(int i = 1; i <= V - 1; i++)
        for(int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }

    // Check negative cycle
    for(int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "\nGraph contains Negative Weight Cycle!\n";
            return;
        }
    }

    cout << "\nBellman-Ford Shortest Distances:\n";
    for(int i = 0; i < V; i++)
        cout << "To " << i << " = " << dist[i] << endl;
}

/* ---------------- FLOYD WARSHALL ---------------- */
void floydWarshall(int graph[MAX][MAX]) {

    int dist[MAX][MAX];

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    cout << "\nFloyd-Warshall All-Pairs Shortest Path:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // Negative cycle detection
    for(int i = 0; i < V; i++)
        if(dist[i][i] < 0)
            cout << "\nNegative Cycle Detected!\n";
}

/* ---------------- MAIN ---------------- */
int main() {

    V = 4;  // Example: A=0, B=1, C=2, D=3

    int graph[MAX][MAX] = {
        {0,   4,   1, INF},
        {INF, 0,   2,   6},
        {INF, INF, 0,   3},
        {INF, INF, INF, 0}
    };

    int edges[][3] = {
        {0,1,4},
        {0,2,1},
        {1,2,2},
        {1,3,6},
        {2,3,3}
    };

    int E = 5;

    int source = 0;   // A

    dijkstra(graph, source);
    bellmanFord(edges, E, source);
    floydWarshall(graph);

    return 0;
}

