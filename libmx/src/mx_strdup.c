#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
	char *str2 = mx_strnew(mx_strlen(str));
    str2 = mx_strcpy(str2, str);
    return str2;
}

