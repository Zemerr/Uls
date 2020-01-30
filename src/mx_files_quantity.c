#include "../inc/header.h"

int mx_files_quantity(char **files, int trig) {
    int count = 0;
    struct stat buf;

    if (trig == 1) {
        for (int i = 0; files[i]; i++) {
            if (lstat(files[i], &buf) >= 0) {
                if ((buf.st_mode & S_IFDIR) != S_IFDIR) {
                    count += 1;
                }
            }
        }
    }
    if (trig == 2) {
        for (int i = 0; files[i]; i++) {
            lstat(files[i], &buf);
            if ((buf.st_mode & S_IFDIR) == S_IFDIR)
                count += 1;
        }
    }
    return count;
}
