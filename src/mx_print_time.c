#include "../inc/header.h"


static void print_date(char **time_arr) {
    mx_printstr(time_arr[1]);
    mx_printstr(" ");
    if (mx_strlen(time_arr[2]) != 2)
        mx_printstr(" ");
    mx_printstr(time_arr[2]);  
    mx_printstr(" ");
}


static char *create_time_str(struct stat sb, t_flags *flags,
time_t *time_file) {
    char *time_c = NULL;

    if (flags->u)
        *time_file = sb.st_atime;
    else
        *time_file = sb.st_mtime;
    time_c = ctime(&(*time_file));
    return time_c;
}

static void print_year(char **time_arr) {
    mx_printstr(" ");
    time_arr[4][4] = '\0';
    mx_printstr(time_arr[4]);
}

static void print_year_hour(t_flags *flags, time_t time_file, char **time_ar) {
    char *hour = mx_str_copy(time_ar[3]);
    char **hour_arr = mx_strsplit(hour, ':');

    if (flags->T != 1) {
        if (time(NULL) - 15811200 > time_file) {
            print_year(time_ar);
        }
        else {
            mx_printstr(hour_arr[0]);
            mx_printstr(":");
            mx_printstr(hour_arr[1]);
        }
    }
    else {
        mx_printstr(hour);
        print_year(time_ar);
    }
    mx_del_strarr(&hour_arr);
    mx_strdel(&hour);
}

void mx_print_time(struct stat sb, t_flags *flags) {
    time_t time_file = 0;
    char *time_c = create_time_str(sb, flags, &time_file);
    char **time_arr = mx_strsplit(time_c, ' ');

    print_date(time_arr);
    print_year_hour(flags, time_file, time_arr);
    mx_printstr(" ");
    mx_del_strarr(&time_arr);
}
