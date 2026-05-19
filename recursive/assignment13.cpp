#include <iostream>
#include <climits>
using namespace std;

#define INF 1000000

int n = 4;

int dist[4][4] = {
    {-1, 10, 15, 20},
    {10, -1, 35, 25},
    {15, 35, -1, 30},
    {20, 25, 30, -1}
};

int dp[1<<4][4];

int tsp(int mask, int pos) {

    if(mask == (1<<n) - 1) {
        if(dist[pos][0] == -1)
            return INF;  
        return dist[pos][0];
    }

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for(int city = 0; city < n; city++) {

        if((mask & (1<<city)) == 0 && dist[pos][city] != -1) {

            int newAns = dist[pos][city] +
                         tsp(mask | (1<<city), city);

            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {

    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            dp[i][j] = -1;

    int result = tsp(1, 0);

    if(result >= INF)
        cout << "No valid TSP cycle exists";
    else
        cout << "Minimum cost: " << result;

    return 0;
}
