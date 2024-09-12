#include <stdio.h>
int main() {
    int n = 8;
    int a = 0, b = 1, c, sum = 0;

    printf("Sum of numbers at even indexes = ");
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            sum += a;
            printf("%d", a);
            if (i != n) {
                printf("+");
            }
        }
        c = a + b;
        a = b;
        b = c;
    }
    printf("=%d\n", sum);

    return 0;
}

