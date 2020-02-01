#include "header.h"

static t_acl_trig *create_trig(char *my_acl_line) {
    t_acl_trig *trigers = (t_acl_trig *)malloc(sizeof(t_acl_trig));

    my_acl_line[10] = ' ';
    trigers->l_flag = 0;
    trigers->dev_flag = 0;
    trigers->minor = 0;
    trigers->major = 0;
    trigers->path_flag = 0;
    return trigers;
    
}

static void print_block(t_lens *my_lens) {
    mx_printstr("total ");
    mx_printint(my_lens->blocks);
    mx_printstr("\n");
}

static char *build_path(char *dir_name, t_acl_trig *trigers, char *sort_arr,
struct stat *sb) {
    char *path_name_1 = NULL;

    if (sort_arr[0] != '/') {
        path_name_1 = mx_strjoin(dir_name, "/");
        path_name_1 = mx_strjoin_two(path_name_1, sort_arr);
        trigers->path_flag = 1;
    }
    else
        path_name_1 = sort_arr;
    lstat(path_name_1, *(&sb));
    return path_name_1;
}

void mx_flag_l(char **sort_arr, char *dir_name, t_flags *flags) {
    struct stat sb;
    char my_acl_line[] = "-----------";
    t_lens *my_lens =  mx_for_flagl_one(sort_arr, dir_name);
    t_acl_trig *trigers = create_trig(my_acl_line);

    print_block(my_lens);
    for ( ; *sort_arr != NULL; sort_arr++) {
        char *path_name_1 = build_path(dir_name, trigers, *sort_arr, &sb);
        mx_for_flagl_two(sb, trigers, path_name_1, my_acl_line);
        mx_print_name_acl(sb, my_acl_line, my_lens, flags);
        mx_print_size_mm(my_lens, sb, trigers, flags);
        mx_print_time(sb, flags);
        mx_print_name(*sort_arr, flags, dir_name);
        mx_print_link_update(path_name_1, trigers, my_acl_line);
    }
    free(my_lens);
    free(trigers);
}
