#include <stdio.h>
#include <limits.h>
void optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];
    int root[n][n];
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        root[i][i] = i;
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += freq[k];
            }

            for (int r = i; r <= j; r++) {
                int leftCost = (r > i) ? cost[i][r - 1] : 0;
                int rightCost = (r < j) ? cost[r + 1][j] : 0;
                int totalCost = leftCost + rightCost + sum;

                if (totalCost < cost[i][j]) {
                    cost[i][j] = totalCost;
                    root[i][j] = r;
                }
            }
        }
    }
    printf("Cost of the Optimal Binary Search Tree: %d\n", cost[0][n - 1]);
    printf("Root Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", root[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    optimalBST(keys, freq, n);

    return 0;
}

