#include "header.h"

static void files_simple_out(char **files) {
    int w_s = mx_get_ws();
    int size = 0;

    for (int i = 0; files[i]; i++) {
        size = mx_strlen(files[i]);
        if (w_s < (size + 2)) {
            w_s = mx_get_ws();
            write(1, "\n", 1);
        }
        write(1, files[i], size);
        write(1, ", ", 2);
        if (!files[i + 1])
            write(1, "\n", 1);
        w_s -= (size + 2);
    }
}

void mx_flag_d(char **files, t_flags *flags, char *name, int count) {
    if (count > 1 && (*flags).f == 0) {
        mx_flag_sort(name, files, count, flags);
    }
    if ((*flags).l == 1) {
        mx_flag_l(files, name, flags, 0);
    }
    else if ((*flags).m == 1)
        files_simple_out(files);
    else if ((*flags).one == 1)
        mx_simple_out(files, flags, name);
    else
        mx_print_cols(files, count, flags, name);
}
