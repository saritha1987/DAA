#include <stdio.h>
#define MAX_ITEMS 100
void containerLoader(int items[], int n, int capacity) {
    int total = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j] < items[j + 1]) {
                int temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    printf("Items loaded into the container:\n");
    for (int i = 0; i < n; i++) {
        if (total + items[i] <= capacity) {
            total += items[i];
            printf("%d ", items[i]);
        }
    }
    printf("\nTotal loaded: %d\n", total);
}
int main() {
    int items[MAX_ITEMS];
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the sizes of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }
    printf("Enter the container capacity: ");
    scanf("%d", &capacity);
    containerLoader(items, n, capacity);

    return 0;
}
