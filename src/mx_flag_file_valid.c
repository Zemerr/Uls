#include "header.h"


static void flag_write(char *str, char **flags, int *c) {
    int q = *c;
    for (int i = 1; str[i] != '\0'; i++ && q++) {
        (*flags)[q] = str[i];
        (*c)++;
    }
}



static int count(int n, char **obj, char c) {
    int flag_priorit = 1;
    int flag_count = 0;
    int file_count = 0;

    for (int i = 1; i < n; i++) {
        if (flag_priorit == 1) {
            mx_for_flag_valid(obj[i], &flag_priorit, &file_count, &flag_count);
        }
        else
            file_count++;
    }
    if (c == '-')
        return flag_count;
    return file_count;
}

static void file_arr(char ***file, char **obj, int n) {
    int flag_priority = 1;
    int q = 0;

    *file = (char **)malloc(sizeof(char *) * (count(n, obj, 'f') + 1));
        for (int i = 1; i < n; i++) {
            if (flag_priority == 1) {
                if (mx_strcmp(obj[i], "--") == 0)
                    flag_priority = 0;
                else if (obj[i][0] != '-') {
                    flag_priority = 0;
                    (*file)[q] = mx_str_copy(obj[i]);
                    q++;
                }
            }
            else {
                (*file)[q] = mx_str_copy(obj[i]);
                q++;
            }
        }
        (*file)[q] = NULL;
}

void mx_flag_file_valid(char ***file, char **flags, char **obj, int n) {
    int flag_priority = 1;
    int c = 0;

    *flags = (char *)malloc(sizeof(char) * (count(n, obj, '-') + 1));
    file_arr(file, obj, n);
        for (int i = 1; i < n; i++) {
            if (flag_priority == 1) {
                if (mx_strcmp(obj[i], "--") == 0) 
                    flag_priority = 0;
                else if (obj[i][0] != '-') {
                    flag_priority = 0;
                }
                else {
                    flag_write(obj[i], flags, &c);
                }
            }
        }
     (*flags)[c] = '\0';
}
