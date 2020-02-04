#include "header.h"

char **mx_dir_arr(char **files, t_flags *flag) {
    char **dir = NULL;
    int count = mx_files_quantity(files, 2, flag);
    int i = 0;
    int q = 0;
    struct stat buf;

    dir = (char **)malloc(sizeof(char *) * (count + 1));
    for (i = 0; files[i]; i++) {
        count = mx_link_check(files[i], flag, &buf);
        if (count >= 0) {
            if ((buf.st_mode & S_IFMT) == S_IFDIR) {
                dir[q] = mx_strdup(files[i]);
                q++;
            }
        }
    }
    dir[q] = NULL;
    return dir;
}
