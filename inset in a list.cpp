#include <stdio.h>
#define MAX_SIZE 100 
void insertNumber(int list[], int *size, int number, int position) {
    if (*size >= MAX_SIZE) {
        printf("List is full!\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }
    list[position] = number;
    (*size)++;
}
void printList(int list[], int size) {
    printf("List elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
int main() {
    int list[MAX_SIZE] = {0};
    int size = 0;
    printf("Enter the number of elements already in the list: ");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }
    int number, position;
    printf("Enter the number to insert: ");
    scanf("%d", &number);
    printf("Enter the position to insert the number (0-based index): ");
    scanf("%d", &position);
    insertNumber(list, &size, number, position);
    printList(list, size);
    return 0;
}
