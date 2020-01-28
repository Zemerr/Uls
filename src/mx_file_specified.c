#include "../inc/header.h"

static int reg_file_out(char **files, t_flags *flags, char *file_name, int size) {
    char **reg_file = mx_file_arr(files, size);
    int file_count = mx_files_quantity(files, 1);

    if (file_count != 0) {
        if ((*flags).S == 1 || (*flags).t == 1) {
            mx_flag_sort(file_name, reg_file, file_count, flags);
        }
            // mx_sort_S(reg_file, file_count, file_name);
        // }
        else
            mx_bubble_sort(reg_file, file_count);
        if ((*flags).l == 1)
            mx_flag_l(reg_file, file_name, flags);
        else if ((*flags).G == 1)
            mx_flag_g(reg_file, file_count, file_name);
        else
            mx_print_cols(reg_file, file_count);
    }
    mx_del_strarr(&reg_file);
    return file_count;
}

void mx_file_specified(char **files, t_flags *flags, char *file_name, int size) {
    char **dir = NULL;
    int dir_count = 0;

    int file_count = reg_file_out(files, flags, file_name, size);
    dir = mx_dir_arr(files);
    dir_count = mx_files_quantity(files, 2);
    if ((*flags).S == 1 || (*flags).t == 1) {
        mx_flag_sort(file_name, dir, dir_count, flags);
    }
        // mx_sort_S(dir, dir_count, file_name);
    // }
    else
        mx_bubble_sort(dir, dir_count);
    for (int i = 0; dir[i]; i++) {
        if (i > 0 || file_count != 0)
            write(1, "\n", 1);
        if (dir_count != 1 || (*flags).R == 1 || file_count > 0) {
            write(1, dir[i], mx_strlen(dir[i]));
            write(1, ":", 1);
            write(1, "\n", 1);
        }
        mx_define_flags(dir[i], flags);
    }
    mx_del_strarr(&dir);
}
