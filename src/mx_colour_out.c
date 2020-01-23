#include "../inc/header.h"

static void color_mode_two(char c) {
    switch(c)
    {
        case('x'):
            write(1, "\33[0;30;42m", mx_strlen("\33[0;30;42m"));
            break;
        case('u'):
            write(1, "\33[0;30;41m", mx_strlen("\33[0;30;41m"));
            break;
        case('s'):
            write(1, "\33[0;32m", mx_strlen("\33[0;32m"));
            break;
        case('g'):
            write(1, "\33[0;30;44m", mx_strlen("\33[0;30;44m"));
            break;
        case('n'):
            write(1, "\33[0;30;41m", mx_strlen("\33[0;30;41m"));
            break;
        case('-'):
            write(1, "\33[0;34m", mx_strlen("\33[0;34m"));
            break;
    }
}

static void color_mode_one(char c) {
    switch(c)
    {
        case('d'):
            write(1, "\33[0;34m", mx_strlen("\33[0;34m"));
            break;
        case('f'):
            break;
        case('l'):
            write(1, "\33[0;35m", mx_strlen("\33[0;35m"));
            break;
        case('e'):
            write(1, "\33[0;31m", mx_strlen("\33[0;31m"));
            break;
        case('c'):
            write(1, "\33[0;34;43m", mx_strlen("\33[0;34;43m"));
            break;
        case('b'):
            write(1, "\33[0;34;46m", mx_strlen("\33[0;34;46m"));
            break;
    }
}

void mx_colour_out(char *file, char *file_name, char *path_name) {
    char c = mx_file_mode_check(file, file_name, path_name);
    write(1, "\33[0m", mx_strlen("\33[0m"));
    color_mode_one(c);
    color_mode_two(c);
    write (1, file, mx_strlen(file));
    write(1, "\33[0m", mx_strlen("\33[0m"));
}
