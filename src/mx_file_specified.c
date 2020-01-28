#include "../inc/header.h"

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

static int reg_file_out(char **files, t_flags *flags, char *file_name) {
    char **reg_file = mx_file_arr(files);
    int file_count = mx_files_quantity(files, 1);

    if (file_count != 0) {
        if (file_count > 1) {
            mx_flag_sort(file_name, reg_file, file_count, flags);
        }
        if ((*flags).l == 1)
            mx_flag_l(reg_file, file_name, flags);
        else if ((*flags).m == 1)
            files_simple_out(reg_file);
        else if ((*flags).one == 1)
            mx_simple_out(reg_file, flags, file_name);
        else
            mx_print_cols(reg_file, file_count, flags);
    }
    mx_del_strarr(&reg_file);
    return file_count;
}

void mx_file_specified(char **files, t_flags *flags, char *file_name) {
    char **dir = NULL;
    int dir_count = 0;
    int file_count = reg_file_out(files, flags, file_name);

    dir = mx_dir_arr(files);
    dir_count = mx_files_quantity(files, 2);
    if (dir_count > 1) {
        mx_flag_sort(file_name, dir, dir_count, flags);
    }
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
