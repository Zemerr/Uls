#include "header.h"

int mx_link_check(char *file, t_flags *flag, struct stat *buf) {
    int check = 0;

    if ((*flag).l == 0) {
        check = stat(file, &(*buf));
    }
    else
    {
        check = lstat(file, &(*buf));
    }
    return check;
}
