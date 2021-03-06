#include "header.h"

static void print_link(char *path_name_1, t_acl_trig *trigers) {    
    char buf_link[1024];

    if (trigers->l_flag == 1) {
        ssize_t len = readlink(path_name_1, buf_link, sizeof(buf_link));
        buf_link[len]='\0';
        mx_printstr(" -> ");
        mx_printstr(buf_link);
        trigers -> l_flag = 0;
    }
    mx_printchar('\n');
}

static void upadate(char *my_acl_line) {
    my_acl_line[0] = '-';
    my_acl_line[1] = '-';
    my_acl_line[2] = '-';
    my_acl_line[3] = '-';
    my_acl_line[4] = '-';
    my_acl_line[5] = '-';
    my_acl_line[6] = '-';
    my_acl_line[7] = '-';
    my_acl_line[8] = '-';
    my_acl_line[9] = '-';
    my_acl_line[10] = ' ';
}

void mx_print_name(char *sort_arr, t_flags *flags, char *dir_name) {
    if ((*flags).G == 1) {
        mx_colour_out(sort_arr, dir_name);
    }
    else
        mx_printstr(sort_arr);
    if ((*flags).p == 1 || (*flags).F == 1)
        mx_flag_p(sort_arr, flags, dir_name);
}


void mx_print_link_update(char *path_name_1, t_acl_trig *trigers,
char *my_acl_line) {
    print_link(path_name_1, trigers);
    upadate(my_acl_line);
    if (trigers->path_flag == 1) {
        mx_strdel(&path_name_1);
        trigers->path_flag = 0;
    }
}

