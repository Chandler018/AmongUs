#include <iostream>
using namespace std;

#define MAX 10
#define INF 9999

int cost[MAX][MAX];

bool visited[MAX];

int n;

int minCost = INF;

// Travelling Salesman Function
void TSP(int city,
         int count,
         int totalCost) {

    // All cities visited
    if(count == n &&
       cost[city][0]) {

        totalCost += cost[city][0];

        if(totalCost < minCost)
            minCost = totalCost;

        return;
    }

    // Visit next city
    for(int i = 0; i < n; i++) {

        if(!visited[i] &&
           cost[city][i]) {

            visited[i] = true;

            TSP(i,
                count + 1,
                totalCost + cost[city][i]);

            visited[i] = false;
        }
    }
}

int main() {

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cin >> cost[i][j];
        }
    }

    // Start from city 0
    visited[0] = true;

    TSP(0, 1, 0);

    cout << "\nMinimum Hamiltonian Cycle Cost = "
         << minCost;

    return 0;
}