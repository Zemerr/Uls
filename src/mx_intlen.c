#include "../inc/header.h"

int mx_intlen(signed long long num) {
    int len = 1;
    
    while (num > 9) {
        num = num/10;
        len++;
    }

    return len;
}
