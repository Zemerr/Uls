#include "header.h"

static char *filepath(char *file_name, char *file) {
    char *str = file_name;
    char *path = NULL;

    if (mx_strcmp(file_name, "/") != 0)
        str = mx_strjoin(file_name, "/");
    path = mx_strjoin(str, file);
    if (mx_strcmp(file_name, "/") != 0)
        mx_strdel(&str);
    return path;
}

static struct stat *obj_info(char *file_name, char **files, int size) {
    struct stat *info = (struct stat *)malloc(sizeof(struct stat) * (size));
    char *path = NULL;

    for (int i = 0; i < size; i++) {
        path = filepath(file_name, files[i]);
        lstat(path, &info[i]);
        mx_strdel(&path);
    }
    return info;
}

void mx_flag_sort(char *file_name, char **files, int size, t_flags *flags) {
    struct stat *buf = NULL;

    mx_bubble_sort(files);
    buf = obj_info(file_name, files, size);
    mx_upgraded_sort(buf, flags, files);
    free(buf);
}
