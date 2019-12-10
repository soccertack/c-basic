// Implement atoi

#include <stdio.h>
#include <limits.h>
#include <stdbool.h> // We need it for bool
#include <string.h>
#include <math.h>

int get_max_len() {
    int a = INT_MAX;
    int len = 0;

    while (a) {
        a /= 10;
        len += 1;
    }

    return len;
}

// return nth number from the right - right most is 0
// 1234, 0nd number?
int get_digit(int num, int pos) {

    int digit = num / pow(10, pos);
    return digit % 10;
}

int atoi(const char *str, int *res) {
    const char *curr;
    int total = 0, digit;
    int sign = 1;
    unsigned int max_len = get_max_len();
    unsigned int curr_pos;
    bool need_compare = false;

    if (!str || !res) {
        printf("inv arguments\n");
        return -1;
    }

    curr = str;
    if (*curr == '-') {
        curr += 1;
        sign = -1;
    }

    if (strlen(curr) > max_len) {
        printf("inv string size: %lu\n", strlen(curr));
        return -1;
    }
    else if (strlen(curr) == max_len) {
        need_compare = true;
        curr_pos = max_len - 1;
    }

    while (*curr != '\0') {
        if (*curr >= '0' && *curr <= '9') {
            digit = *curr - '0';

            if (need_compare) {
                if (digit > get_digit(INT_MAX, curr_pos)) {
                    // This can be -INT_MAX
                    if (sign == -1 && curr_pos == 0 
                        && digit == get_digit(INT_MAX, curr_pos) + 1) {

                        *res = INT_MIN;
                        return 0;
                    }
                    else {
                        printf("out of range: sign: %d, %d * 10 +  %d\n", sign, total, digit);
                        printf("curr max digit: %d\n", get_digit(INT_MAX, curr_pos));
                        return -1;
                    }
                } else if (digit < get_digit(INT_MAX, curr_pos))
                    need_compare = false;
            }

            total = total * 10 + digit;
            curr += 1;
            curr_pos -= 1;
        } else {
            printf("invalid character: %c\n", *curr);
            return -1;
        }
    }

    *res = total * sign;

    return 0;
}

#define NUMBER_OF_STRING 10
#define MAX_STRING_SIZE 40

int main() {
    int ret, number, i;

    // it would have been much better if we can pair strings with true/false
    char input_arr[NUMBER_OF_STRING][MAX_STRING_SIZE] =
    { "0",
      "-1",
      "1234",
      "-12345",
      "2147483647",
      "2147483648",
      "-2147483648",
      "-2147483649",
      "-21a3092343",
      "-214 092343",
    };

    for (i = 0 ; i < NUMBER_OF_STRING; i++) {


        printf("Input: %s\n", input_arr[i]);
        ret = atoi(input_arr[i], &number);
        if (ret != 0) {
            printf("Error is returned\n\n");
        } else {
            printf("returned %d\n\n", number);
        }
    }

    return 0;
}
