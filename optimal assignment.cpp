#include <stdio.h>
#include <limits.h>
#define N 4  
typedef struct {
    int cost;           
    int assignment[N];   
    int level;          
} State;
int branchAndBound(int cost[N][N], State state, int assigned[], int n, int minCost);
void printAssignment(int assignment[], int n);
int branchAndBound(int cost[N][N], State state, int assigned[], int n, int minCost) {
    if (state.level == n) {
        if (state.cost < minCost) {
            minCost = state.cost;
            printAssignment(state.assignment, n);
        }
        return minCost;
    }

    for (int i = 0; i < n; i++) {
        if (!assigned[i]) {
            State newState = state;
            newState.cost += cost[state.level][i];
            newState.assignment[state.level] = i;
            newState.level++;
            assigned[i] = 1;
            minCost = branchAndBound(cost, newState, assigned, n, minCost);
            assigned[i] = 0;
        }
    }
    return minCost;
}
void printAssignment(int assignment[], int n) {
    printf("Optimal assignment:\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d assigned to Agent %d\n", i, assignment[i]);
    }
    printf("\n");
}
int main() {
    int cost[N][N] = {
        {10, 2, 8, 6},
        {5, 7, 12, 10},
        {6, 12, 14, 9},
        {8, 6, 10, 11}
    };
    State initialState = {0, {-1, -1, -1, -1}, 0}; 
    int assigned[N] = {0}; 
    int minCost = INT_MAX;

    minCost = branchAndBound(cost, initialState, assigned, N, minCost);

    printf("Minimum cost: %d\n", minCost);

    return 0;
}
