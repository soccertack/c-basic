// Implement atoi

#include <stdio.h>
#include <limits.h>
#include <stdbool.h> // We need it for bool

int atoi(const char *str, int *res) {
    const char *curr;
    int total = 0, digit;
    int sign = 1;

    if (!str || !res)
        return -1;

    curr = str;

    if (*curr == '-') {
        curr += 1;
        sign = -1;
    }

    while (*curr != '\0') {
        if (*curr >= '0' && *curr <= '9') {
            digit = *curr - '0';
            total = total * 10 + digit;
            curr += 1;
        } else {
            return -1;
        }
    }

    *res = total * sign;

    return 0;
}

int main() {
    int ret;
    int number;
    char in[] = "-54321";
    //printf("int max: %d\n", INT_MAX);

    ret = atoi(in, &number);
    if (ret != 0) {
        printf("Error is returned\n");
        return -1;
    }

    printf("returned %d\n", number);

    return 0;
}
