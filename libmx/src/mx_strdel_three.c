#include "../inc/libmx.h"

void mx_strdel_three(char **str1, char **str2, char **str3) {
    if (*str1 != NULL){
        free(*str1);
        *str1 = NULL;
    }
    if (*str2 != NULL){
        free(*str2);
        *str2 = NULL;
    }
    if (*str3 != NULL){
        free(*str3);
        *str3 = NULL;
    }
}
