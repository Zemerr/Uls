#include "../inc/header.h"


static void flag_check(char *str, int *flag_count) {
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == 'A' || str[i] == 'a' || str[i] == 'l' ||
           str[i] == 'G' || str[i] == 'R' || str[i] == 'S' || str[i] == 't' ||
           str[i] == 'h' || str[i] == 'u' || str[i] == 'r' || str[i] == 'C' ||
           str[i] == '1' || str[i] == 'm') {
            (*flag_count)++;
           }
        else {
            write(2, "usage: uls [-AalGRSthurC1m] [file ...]\n",
                mx_strlen("usage: uls [-lAalGRSthurC1m] [file ...]\n"));
            exit(1);
        }
    }
}

static void flag_write(char *str, char **flags, int *c) {
    int q = *c;
    for (int i = 1; str[i] != '\0'; i++ && q++) {
        (*flags)[q] = str[i];
        (*c)++;
    }
}

void mx_flag_file_valid(char ***file, char **flags, char **obj, int n) {
    int flag_priority = 1;
    int flag_count = 0;
    int file_count = 0;

    int q = 0;
    int c = 0;

    for (int i = 1; i < n; i++) {
        if (flag_priority == 1) {
            if (mx_strcmp(obj[i], "--") == 0) 
                flag_priority = 0;
            else if (obj[i][0] != '-') {
                flag_priority = 0;
                file_count++;
            }
            else 
                flag_check(obj[i], &flag_count);
        }
        else
            file_count++;
    }

    flag_priority = 1;

    *file = (char **)malloc(sizeof(char *) * (file_count+1));
    *flags = (char *)malloc(sizeof(char ) * (flag_count+1));

    for (int i = 1; i < n; i++) {
        if (flag_priority == 1) {
            if (mx_strcmp(obj[i], "--") == 0) 
                flag_priority = 0;
            else if (obj[i][0] != '-') {
                flag_priority = 0;
                (*file)[q] = mx_str_copy(obj[i]);
                q++;
            }
            else {
                flag_write(obj[i], flags, &c);
            }
        }
        else {  
            (*file)[q] = mx_str_copy(obj[i]);
            q++;
            }
        }


     (*file)[q] = NULL;
     (*flags)[c] = '\0';

}
