#include <stdio.h>
#include <limits.h>
#define N 4  
int tsp(int dist[N][N], int pos, int visited, int dp[N][1 << N]) {
    if (visited == (1 << N) - 1) {  
        return dist[pos][0];  
    }
    if (dp[pos][visited] != -1) {
        return dp[pos][visited]; 
    }
    int minCost = INT_MAX;
    for (int city = 0; city < N; city++) {
        if (!(visited & (1 << city))) {
            int newCost = dist[pos][city] + tsp(dist, city, visited | (1 << city), dp);
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }
    dp[pos][visited] = minCost; 
    return minCost;
}
int main() {
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int dp[N][1 << N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
        }
    }
    int minCost = tsp(dist, 0, 1, dp);
    printf("Minimum cost: %d\n", minCost);
    return 0;
}

