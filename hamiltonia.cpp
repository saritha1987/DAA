#include <stdio.h>
#define V 4  
void printSolution(int path[]) {
    printf("Hamiltonian Circuit exists: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);  
}
int isSafe(int graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][path[pos]] == 0) {
        return 0;
    }
    for (int i = 0; i < pos; i++) {
        if (path[i] == path[pos]) {
            return 0;
        }
    }

    return 1;
}
int hamCycleUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        return (graph[path[pos - 1]][path[0]] == 1);
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(graph, path, v)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1)) {
                return 1;
            }
            path[pos] = -1;
        }
    }
    return 0;
}
int hamCycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == 0) {
        printf("No Hamiltonian Circuit exists\n");
        return 0;
    }
    printSolution(path);
    return 1;
}
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };

    hamCycle(graph);

    return 0;
}
