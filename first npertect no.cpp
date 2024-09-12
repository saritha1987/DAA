#include <stdio.h>
int is_perfect_number(int num) {
    int sum_divisors = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum_divisors += i;
        }
    }
    return sum_divisors == num;
}
void first_n_perfect_numbers(int n) {
    int count = 0;
    int num = 1;
    printf("First %d perfect numbers are: ", n);
    while (count < n) {
        if (is_perfect_number(num)) {
            printf("%d, ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}
int main() {
    int N = 3;
    first_n_perfect_numbers(N);

    return 0;
}
