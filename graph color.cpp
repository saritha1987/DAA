#include <stdio.h>
#include <stdbool.h>
#define V 4 
bool isSafe(int graph[V][V], int color[], int vertex, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}
bool graphColoring(int graph[V][V], int color[], int vertex, int m) {
    if (vertex == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, vertex, c)) {
            color[vertex] = c;
            if (graphColoring(graph, color, vertex + 1, m)) {
                return true;
            }
            color[vertex] = 0; 
        }
    }
    return false;
}
void printSolution(int color[]) {
    printf("Solution exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d --> Color %d\n", i, color[i]);
    }
}
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int color[V] = {0};  
    int m;  
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    if (graphColoring(graph, color, 0, m)) {
        printSolution(color);
    } else {
        printf("Solution does not exist\n");
    }
    return 0;
}
