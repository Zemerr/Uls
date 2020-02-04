#include "header.h"

char *mx_str_copy(char *src) {
    char *copy = NULL;
    int size = mx_strlen(src);
    int i = 0;

    copy = (char *)malloc(sizeof(char) * (size + 1));
    for (i = 0; i < size; i++) {
        copy[i] = src[i];
    }
    copy[i] = '\0';
    return copy;
}
