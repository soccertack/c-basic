#include <stdio.h>
#include <limits.h>
#include <errno.h>

#define IS_DIGIT(x) ((x) >= '0' && (x) <= '9')
#define ISALPHA(x) (0)
#define ISUPPER(c) (0)

long strtol(const char *nptr, char **endptr, int base) {

    const char *s = nptr;
    int c;
    unsigned long acc;
    unsigned long cutoff;
    int neg = 0, any, cutlim;

    printf("endptr: %p\n", (void *)endptr);
    do {
        c = *s++;
    } while (c == ' ');

    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;

    if ((base == 0 || base == 16) &&
        c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }

    if (base == 0)
        base = c == '0' ? 8 : 10;

    cutoff = neg ? -(unsigned long) LONG_MIN : LONG_MAX;
    cutlim = cutoff % (unsigned long)base;
    cutoff /= base;

    for (any = 0, acc = 0; ; c = *s++) {
        if (IS_DIGIT(c)) {
            c -= '0';
        } else if (ISALPHA(c))
            c -= ISUPPER(c) ? 'A' - 10 : 'a' - 10;
        else
            break;

        if (c >= base) {
            any = -1;
            break;
        }

        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
            printf("acc: %lu\n", acc);
        }
    }

    if (any < 0) {
        acc = neg? LONG_MIN : LONG_MAX;
        errno = ERANGE;
    } else if (neg)
        acc = -acc;

    printf("long max: %ld, long_min: %ld\n", LONG_MAX, LONG_MIN);
    printf("cutoff: %lu\n", cutoff);
    printf("acc: %lu\n", (unsigned long)acc);

    return acc;
}

int main() {
    long abc;
    printf("strtol\n");
    errno = 0;
    abc = strtol("-1", NULL, 10);
    if (errno)
        printf("error: %d\n", errno);
    else
        printf("returned %ld\n", abc);
    return 0;
}
