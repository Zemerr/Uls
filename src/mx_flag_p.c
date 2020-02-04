#include "header.h"

static void flag_F(char *obj, char *file_name) {
    char c;

    c = mx_file_mode_check(obj, file_name);
        if (c == 'l')
            write(1, "@", 1);
        else if (c == 'e')
            write(1, "*", 1);
        else if (c == 'd')
            write(1, "/", 1);
        else if (c == 's')
            write(1, "=", 1);
        else if (c == 'p')
            write(1, "|", 1);
}

void mx_flag_p(char *obj, t_flags *flags, char *file_name) {
    char c;

    if ((*flags).F == 1)
        flag_F(obj, file_name);
    else {
        c = mx_file_mode_check(obj, file_name);
        if (c == 'd')
            write(1, "/", 1);
    }
}
