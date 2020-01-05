#include "../inc/libmx.h"

static char *character_change(int start, int size, int n, char *c) {
    int rem = 0;
    int div = 10;

    for (int i = size - 1; i >= start; i--) {
        rem = n / div;
        c[i] = (n % div) + 48;
        n = rem;
    }
    return c;
}

static char *check(int number) {
    if (number == 0) {
        return "0";
    }
    if (number == -2147483648) {
        return "-2147483648";
    }
    return NULL;
}

static char *neg_check(int n, int start, char *c, int size) {
    if (n < 0) {
        size = size + 1;
        c = mx_strnew(size);
        c[0] = '-';
        n = -1 * n;
        start = 1;
    }
    else if (n > 0) {
        c = mx_strnew(size);
    }
    return c;
}

char *mx_itoa(int number) {
    int n = number;
    int size = 0;
    char *c = check(number);
    int start = 0;

    if (c != NULL) {
        return c;
    }
    for (; number != 0; size++) {
        number = number / 10;
    }
    c = neg_check(n, start, c, size);
    c = character_change(start, size, n, c);
    return c;
}
