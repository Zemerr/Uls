#include "header.h"

static int dir_count(char **obj, char *str) {
    char *path = NULL;
    struct stat buff;
    int count = 0;

    for (int i = 0; obj[i]; i++) {
        if (mx_strcmp(obj[i], ".") != 0 && mx_strcmp(obj[i], "..") != 0) {
            path = mx_strjoin(str, obj[i]);
            lstat(path, &buff);
            if ((buff.st_mode & S_IFLNK) != S_IFLNK) {
                if ((buff.st_mode & S_IFDIR) == S_IFDIR)
                    count++;
            }
            mx_strdel(&path);
        }
    }
    return count;
}

static char **dir_in(char **obj, char *str, int count) {
    char **dir = (char **)malloc(sizeof(char *) * (count + 1));
    char *path = NULL;
    struct stat buff;
    int q = 0;

    for (int i = 0; obj[i]; i++) {
        if (mx_strcmp(obj[i], ".") != 0 && mx_strcmp(obj[i], "..") != 0) {
            path = mx_strjoin(str, obj[i]);
            lstat(path, &buff);
                if ((buff.st_mode & S_IFLNK) != S_IFLNK) {
                    if ((buff.st_mode & S_IFMT) == S_IFDIR) {
                        dir[q] = mx_strdup(obj[i]);
                        q++;
                    }
                }
                mx_strdel(&path);
        }
    }
    dir[q] = NULL;
    return dir;
}

static void dir_out(char *str, char **dir, t_flags *flags) {
    char *path = NULL;

    for (int i = 0; dir[i]; i++) {
        path = mx_strjoin(str, dir[i]);
        write(1, "\n", 1);
        write(1, path, mx_strlen(path));
        write(1, ":", 1);
        write(1, "\n", 1);
        mx_define_flags(path, flags, 1);
        mx_strdel(&path);
    }
}

void mx_recursion_call(char **obj, t_flags *flags, char *file_name) {
    char *str = NULL;
    char **dir = NULL;
    int count = 0;

    if (!obj) {
        return;
    }
    if (mx_strcmp(file_name, "/") == 0)
        str = file_name;
    else
        str = mx_strjoin(file_name, "/");
    count = dir_count(obj, str);
    dir = dir_in(obj, str, count);
    dir_out(str, dir, flags);
    mx_del_strarr(&dir);
        if (mx_strcmp(file_name, "/") != 0)
            mx_strdel(&str);
}
