#include "header.h"

static int count_arr_len(char **arr) {
    int i = 0;

    for (; arr[i]; i++);
    return i;
}

int main(int argc, char **argv) {
    char **file = NULL;
    char *flag = NULL;
    int filec = 0;
    t_flags *flags = NULL;
    int error = 0;

    mx_flag_file_valid(&file, &flag, argv, argc);
    flags = mx_flags_filter(flag);
    filec = count_arr_len(file);
    if (file[0] == NULL) {
        mx_define_flags(".", flags, 1);
    }
    if (file[0] != NULL) {
        if ((*flags).d == 1)
            mx_flag_d(file, flags, ".", filec);
        else
            mx_file_specified(file, flags, ".", &error);
    }
    return error;
}
