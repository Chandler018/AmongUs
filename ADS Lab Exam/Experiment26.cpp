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

    // Floyd-Warshall Algorithm
    for(int k = 0; k < n; k++) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(cost[i][k] + cost[k][j]
                   < cost[i][j]) {

                    cost[i][j] =
                    cost[i][k] + cost[k][j];
                }
            }
        }
    }

    // Display shortest path matrix
    cout << "\nShortest Path Matrix:\n";

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(cost[i][j] == INF)
                cout << "INF ";

            else
                cout << cost[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}