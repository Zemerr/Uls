#include "header.h"

char *mx_find_path(char *file, char *file_name) {
    char *filepath1 = NULL;
    char *filepath2 = NULL;

    if (mx_strcmp(file_name, ".") == 0)
        return file;
    filepath1 = mx_strjoin(file_name, "/");
    filepath2 = mx_strjoin(filepath1, file);
    mx_strdel(&filepath1);
    return filepath2;
}
