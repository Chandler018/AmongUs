#include <iostream>
using namespace std;

#define MAX 10
#define INF 9999

int parent[MAX];

// Find parent
int find(int i) {

    while(parent[i])
        i = parent[i];

    return i;
}

// Union operation
void unionSet(int a, int b) {

    parent[b] = a;
}

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
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    int edges = 0;
    int minCost = 0;

    cout << "\nEdges in MST:\n";

    while(edges < n - 1) {

        int min = INF;
        int a = -1, b = -1;

        // Find minimum edge
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(cost[i][j] < min) {

                    min = cost[i][j];

                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        // No cycle
        if(u != v) {

            cout << a << " - "
                 << b << " : "
                 << min << endl;

            minCost += min;

            unionSet(u, v);

            edges++;
        }

        // Remove selected edge
        cost[a][b] =
        cost[b][a] = INF;
    }

    cout << "\nMinimum Cost = "
         << minCost;

    return 0;
}