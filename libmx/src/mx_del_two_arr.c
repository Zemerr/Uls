#include "libmx.h"

void mx_del_two_arr(char ***arr1, char ***arr2, char **str) {
    mx_del_strarr(arr1);
    mx_del_strarr(arr2);
    mx_strdel(str);
}
