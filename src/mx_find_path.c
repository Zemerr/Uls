#include "../inc/header.h"

char *mx_find_path(char *file, char *file_name, char *path_name) {
    char *filepath1 = NULL;
    char *filepath2 = file;

    if (mx_strcmp(file_name, ".") == 0)
        filepath2 = file;
    else if (file_name == NULL)
        filepath2 = path_name;
    else {
        if (mx_strcmp(file_name, file) != 0) {
            filepath1 = mx_strjoin(file_name, "/");
            filepath2 = mx_strjoin(filepath1, file);
        }
    }
    if (file_name != NULL && mx_strcmp(file_name, ".") != 0)
        mx_strdel(&filepath1);
    return filepath2;
}
