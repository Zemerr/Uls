#include "../inc/header.h"

static int name_out(char *dir, int trig) {
    int n = 0;

    if (trig == 0) {
        write(1, "\n", 1);
        n = 0;
    }
    else if (trig == 1) {
        write(1, dir, mx_strlen(dir));
        write(1, ":", 1);
        write(1, "\n", 1);
        n = 1;
    }
    return n;
}

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

static int reg_file_out(char **files, t_flags *flags, char *name, int size) {
    char **reg_file = mx_file_arr(files, size, flags);
    int file_count = mx_files_quantity(files, 1);

    if (file_count != 0) {
        if (file_count > 1 && (*flags).f == 0) {
            mx_flag_sort(name, reg_file, file_count, flags);
        }
        if ((*flags).l == 1) {
            mx_flag_l(reg_file, name, flags, 0);
        }
        else if ((*flags).m == 1)
            files_simple_out(reg_file);
        else if ((*flags).one == 1)
            mx_simple_out(reg_file, flags, name);
        else
            mx_print_cols(reg_file, file_count, flags, name);
    }
    mx_del_strarr(&reg_file);
    return file_count;
}

void mx_file_specified(char **files, t_flags *flags, char *name, int size) {
    char **dir = NULL;
    int dir_count = 0;
    int file_count = reg_file_out(files, flags, name, size);
    int trig;

    dir = mx_dir_arr(files);
    dir_count = mx_files_quantity(files, 2);
        if (dir_count > 1 && (*flags).f == 0)
            mx_flag_sort(name, dir, dir_count, flags);
        for (int i = 0; dir[i]; i++) {
            if (i > 0 || file_count != 0)
                trig = name_out(dir[i], 0);
            if (dir_count != 1 || (*flags).R == 1 ||
                file_count > 0 || size > dir_count) {
                trig = name_out(dir[i], 1);
            }
            mx_define_flags(dir[i], flags, trig);
        }
        mx_del_strarr(&dir);
}
