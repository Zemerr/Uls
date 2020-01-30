#include "../inc/header.h"



static void print_year(char **time_arr) {
    mx_printstr(time_arr[1]);
    mx_printstr(" ");    
    if (mx_strlen(time_arr[2]) != 2)
        mx_printstr(" ");
    mx_printstr(time_arr[2]);  
    mx_printstr(" ");
}



static void print_time(struct stat sb, t_flags *flags) {
    char *time_c = NULL;
    char **time_arr = NULL;
    char *hour = NULL;
    char **hour_arr = NULL;
    time_t time_now = time(NULL);
    time_t time = 0;

   if (flags->u)
        time = sb.st_atime;
    else 
        time = sb.st_mtime;

    time_c = ctime(&time);
   
    time_arr = mx_strsplit(time_c, ' ');
    hour = mx_str_copy(time_arr[3]);
    hour_arr = mx_strsplit(hour, ':');



    print_year(time_arr);
    if (time_now - 15811200 > time) {
        mx_printstr(" ");
        time_arr[4][4] = '\0';
        mx_printstr(time_arr[4]);
    }
    else {
        mx_printstr(hour_arr[0]);
        mx_printstr(":");
        mx_printstr(hour_arr[1]);
    }
    mx_printstr(" ");
    mx_del_two_arr(&time_arr, &hour_arr, &hour);
}

static t_acl_trig *create_trig() {
    t_acl_trig *trigers = (t_acl_trig *)malloc(sizeof(t_acl_trig));

    trigers->l_flag = 0;
    trigers->dev_flag = 0;
    trigers->minor = 0;
    trigers->major = 0;
    return trigers;
}

static void print_block(char *my_acl_line, t_lens *my_lens) {
    my_acl_line[10] = ' ';
    mx_printstr("total ");
    mx_printint(my_lens->blocks);
    mx_printstr("\n");
}


void mx_flag_l(char **sort_arr, char *dir_name, t_flags *flags) {
    struct stat sb;
    char my_acl_line[] = "-----------";
    t_lens *my_lens =  mx_for_flagl_one(sort_arr, dir_name);
    t_acl_trig *trigers = create_trig();

    print_block(my_acl_line, my_lens);
    for ( ; *sort_arr != NULL; sort_arr++) {
        char *path_name_1 = NULL;
        int flag = 0;
        if ((*sort_arr)[0] != '/') {
            path_name_1 = mx_strjoin(dir_name, "/");
            path_name_1 = mx_strjoin_two(path_name_1, *sort_arr);
            flag = 1;
        }
        else
            path_name_1 = *sort_arr;
        lstat(path_name_1, &sb);
        mx_for_flagl_two(sb, trigers, path_name_1, my_acl_line);
        mx_print_name_acl(sb, my_acl_line, my_lens, flags);
        mx_print_size_mm(my_lens, sb, trigers, flags);
        print_time(sb, flags);
        mx_print_link_update(path_name_1, trigers, my_acl_line, *sort_arr, flag, flags, dir_name);
        
    }
    free(my_lens);
    free(trigers);
}
