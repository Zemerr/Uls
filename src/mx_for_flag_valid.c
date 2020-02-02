#include "header.h"

static void flag_check(char *str, int *flag_count) {
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == 'A' || str[i] == 'a' || str[i] == 'l' ||
           str[i] == 'G' || str[i] == 'R' || str[i] == 'S' || str[i] == 't' ||
           str[i] == 'h' || str[i] == 'u' || str[i] == 'r' || str[i] == 'C' ||
           str[i] == '1' || str[i] == 'm' || str[i] == 'o' || str[i] == 'g' ||
           str[i] == 'T' || str[i] == 'd' || str[i] == 'p' || str[i] == 'F' ||
           str[i] == 'f') {
            (*flag_count)++;
           }
        else {
            write(2, "uls: illegal option -- ", 24);
            write(2, &str[i], 1);
            write(2, "\nusage: uls [-AalGRSthurC1mogTdpFf] [file ...]\n", 48);
            exit(1);
        }
    }
}

void mx_for_flag_valid(char *obj, int *flag_priority, int *file_count,
int *flag_count) {
    if (mx_strcmp(obj, "--") == 0)
        *flag_priority = 0;
    else if (obj[0] != '-') {
        *flag_priority = 0;
        (*file_count)++;
    }
    else
        flag_check(obj, flag_count);
}
