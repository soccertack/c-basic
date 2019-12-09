// Implement atoi

#include <stdio.h>
#include <limits.h>

int atoi(const char *str, int *res) {
    const char *curr;
    int total = 0, digit;

    if (!str || !res)
        return -1;

    curr = str;

    while (*curr != '\0') {
        if (*curr >= '0' && *curr <= '9') {
            digit = *curr - '0';
            total = total * 10 + digit;
            curr += 1;
        } else {
            return -1;
        }
    }

    *res = total;

    return 0;
}

int main() {
    int ret;
    int number;
    char in[] = "54321";
    //printf("int max: %d\n", INT_MAX);

    ret = atoi(in, &number);
    if (ret != 0) {
        printf("Error is returned\n");
        return -1;
    }

    printf("returned %d\n", number);

    return 0;
}
