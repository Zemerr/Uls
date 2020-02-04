#include "header.h"

static long long sort_parametr(t_flags *flags, struct stat *info, int index) {
    if ((*flags).S == 1)
        return info[index].st_size;
    else if ((*flags).t == 1) {
        if ((*flags).u == 1)
            return info[index].st_atime;
        return info[index].st_mtime;
    }
    return 0;
}

static long long difference(t_flags *flags, struct stat *buf, int i, int j) {
    long long p1 = sort_parametr(flags, buf, i);
    long long p2 = sort_parametr(flags, buf, j);
    long long dif = 0;

    if ((*flags).r == 1) {
        dif = p1 - p2;
    }
    else if ((*flags).r == 0) {
        dif = p2 - p1;
    }
    return dif;
}

static void swap(struct stat *buf, char **files, int i, int j) {
    char *swap = files[j];
    struct stat buf_swap = buf[j];

    buf[j] = buf[i];
    files[j] = files[i];
    buf[i] = buf_swap;
    files[i] = swap;
}

void mx_upgraded_sort(struct stat *buf, t_flags *flags, char **files) {
    long long dif;

    for (int j = 0; files[j + 1]; j++) {
        for (int i = j + 1; files[i]; i++) {
            dif = difference(flags, buf, i, j);
            if (dif < 0)
                swap(buf, files, i, j);
            if (dif == 0) {
                if ((*flags).r == 0) {
                    if (mx_strcmp(files[i], files[j]) < 0)
                        swap(buf, files, i, j);
                }
                else if ((*flags).r == 1)
                    if (mx_strcmp(files[i], files[j]) > 0)
                        swap(buf, files, i, j);
            }
        }
    }
}
