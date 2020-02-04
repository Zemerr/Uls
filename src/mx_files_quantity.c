#include "header.h"

int mx_files_quantity(char **files, int trig, t_flags *flag) {
    int count = 0;
    struct stat buf;
    int check;

    for (int i = 0; files[i]; i++) {
        check = mx_link_check(files[i], flag, &buf);
        if (check >= 0) {
            if (((buf.st_mode & S_IFDIR) != S_IFDIR) && (trig == 1))
                count += 1;
            else if (((buf.st_mode & S_IFDIR) == S_IFDIR) && (trig == 2))
                count += 1;
        }
    }
    return count;
}
