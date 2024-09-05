#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int start = 0, end;

    printf("Enter a string: ");
    scanf("%s", str);  
    end = strlen(str) - 1;  
    while (start < end) {
        if (str[start] != str[end]) {
            printf("%s is not a palindrome.\n", str);
            return 0;
        }
        start++;
        end--;
    }

    printf("%s is a palindrome.\n", str);
    return 0;
}
