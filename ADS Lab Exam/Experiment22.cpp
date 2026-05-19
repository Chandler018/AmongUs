#include <iostream>
using namespace std;

#define INF 9999

int main() {

    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cin >> cost[i][j];

            // Replace 0 with INF
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    bool visited[10] = {false};

    visited[0] = true;

    int edges = 0;
    int minCost = 0;

    cout << "\nEdges in MST:\n";

    while(edges < n - 1) {

        int min = INF;
        int a = -1, b = -1;

        for(int i = 0; i < n; i++) {

            if(visited[i]) {

                for(int j = 0; j < n; j++) {

                    if(!visited[j] &&
                       cost[i][j] < min) {

                        min = cost[i][j];

                        a = i;
                        b = j;
                    }
                }
            }
        }

        cout << a << " - "
             << b << " : "
             << min << endl;

        minCost += min;

        visited[b] = true;

        edges++;
    }

    cout << "\nMinimum Cost = "
         << minCost;

    return 0;
}