#include <stdio.h>
#include <stdbool.h>

bool checkPerfectNumber(int n) {
    if (n <= 1) {
        return false;
    }

    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum == n;
}

int main() {
    int num = 28; 
    if (checkPerfectNumber(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}
