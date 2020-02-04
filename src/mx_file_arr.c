#include "header.h"

char **mx_file_arr(char **files, int *error, t_flags *flag) {
    char **reg_file = NULL;
    int count = mx_files_quantity(files, 1, flag);
    int i = 0;
    int q = 0;
    struct stat buf;

    if ((*flag).f != 1)
        mx_bubble_sort(files);
    reg_file = (char **)malloc(sizeof(char *) * (count + 1));
    for (i = 0; files[i]; i++) {
        count = mx_link_check(files[i], flag, &buf);
        if (count < 0)
            mx_print_error_file(files[i], error);
        else if ((buf.st_mode & S_IFDIR) != S_IFDIR) {
            reg_file[q] = mx_strdup(files[i]);
            q++;
        }
    }
    reg_file[q] = NULL;
    return reg_file;
}
