#include <stdio.h>
int isPerfectNumber(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}
int main() {
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    if (number <= 0) {
        printf("Please enter a positive integer.\n");
        return 1; 
    }
    if (isPerfectNumber(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }
    return 0;
}

