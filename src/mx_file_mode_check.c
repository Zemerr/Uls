#include "../inc/header.h"

static char dir_check(struct stat buf) {
    char c = '-';

    switch (buf.st_mode & S_IFMT)
    {
        case (S_IFDIR):
            if ((buf.st_mode & S_ISVTX) == S_ISVTX
                && (buf.st_mode & S_IWOTH) == S_IWOTH) {
                c = 'x';
                break;
            }
            if ((buf.st_mode & S_IWOTH) == S_IWOTH) {
                c = 'n';
                break;
            }
            c = 'd';
            break;
    }
    return c;
}

static char second_mode_unit(struct stat buf) {
    char c = '-';

    switch (buf.st_mode & S_IFMT)
    {
        case (S_IFBLK):
            c = 'b';
            break;
        case (S_IFCHR):
            c = 'c';
            break;
        case (S_IFIFO):
            c = 'p';
            break;
    }
    if (c == '-')
        c = dir_check(buf);
    return c;
}

static char file_check(struct stat buf) {
    char c = '-';

    switch (buf.st_mode & S_IFMT)
    {
        case (S_IFREG):
            if ((buf.st_mode & S_IXUSR) == S_IXUSR) {
                if ((buf.st_mode & S_ISUID) == S_ISUID) {
                    c = 'u';
                }
                if ((buf.st_mode & S_ISGID) == S_ISGID) {
                    c = 'g';
                }
                c = 'e';
            }
            else {
                c = 'f';
            }
    }
    return c;
}

static char one_mode_unit(struct stat buf) {
    char c = '-';

    switch (buf.st_mode & S_IFMT)
    {
        case (S_IFSOCK):
            c = 's';
            break;
        case (S_IFLNK):
            c = 'l';
            break;
    }
    if (c == '-')
        c = file_check(buf);
    return c;
}

char mx_file_mode_check(char *file, char *file_name, char *path_name) {
    char c;
    char *filepath1 = NULL;
    char *filepath2 = file;
    struct stat buf;

    if (file_name == NULL)
        filepath2 = path_name;
    else {
        if (mx_strcmp(file_name, file) != 0) {
            filepath1 = mx_strjoin(file_name, "/");
            filepath2 = mx_strjoin(filepath1, file);
        }
    }
    lstat(filepath2, &buf);
    c = one_mode_unit(buf);
        if (c == '-')
            c = second_mode_unit(buf);
        // mx_strdel(&filepath1);
        // mx_strdel(&filepath2);
        return c;
}
