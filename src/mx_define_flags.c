#include "header.h"

static int determine_size(char **arr) {
    int size = 0;

    if (!arr)
        return 0;
    for (int i = 0; arr[i] != NULL; i++) {
        size++;
    }
    return size;
}

static char **data(t_flags *flag, char *file_name) {
    char trig;
    char **obj_arr = NULL;

    if ((*flag).a == 1) {
        trig = 'a';
    }
    if ((*flag).A == 1) {
        trig = 'A';
    }
    obj_arr = mx_files_in_dir(file_name, trig, flag);
    return obj_arr;
}

static void print(t_flags *flags, char **obj_arr, int size, char *file_name) {
    if ((*flags).l == 1) {
        mx_flag_l(obj_arr, file_name, flags);
    }
    else if ((*flags).G == 1 && ((*flags).m == 0 && (*flags).one == 0)) {
        mx_flag_g(obj_arr, size, file_name);
    }
    else if ((*flags).m == 1 || (*flags).one == 1) {
        mx_simple_out(obj_arr, flags, file_name);
    }
    else {
        mx_print_cols(obj_arr, size, flags);
    }
}

void mx_define_flags(char *file_name, t_flags *flags) {
    char **obj_arr = data(flags, file_name);
    int size = determine_size(obj_arr);

    if (!obj_arr) {
        return;
    }
    print(flags, obj_arr, size, file_name);
        if ((*flags).R == 1) {
                mx_recursion_call(obj_arr, flags, file_name);
        }
        mx_del_strarr(&obj_arr);
}
