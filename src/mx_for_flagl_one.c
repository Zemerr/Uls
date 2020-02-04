#include "header.h"

static void count_first_colum(t_lens *my_lens, struct stat sb) {
    struct passwd *user_info = NULL;
    struct group *gruop_info;

    if (my_lens->first_len < mx_intlen(sb.st_nlink))
        my_lens->first_len = mx_intlen(sb.st_nlink);
    user_info = getpwuid(sb.st_uid);
    if (my_lens->second_len < mx_strlen(user_info->pw_name)) {
        my_lens->second_len = mx_strlen(user_info->pw_name);
    }
    gruop_info = getgrgid(sb.st_gid);
    if (gruop_info != NULL) {
        if (my_lens->third_len < mx_strlen(gruop_info->gr_name))
            my_lens->third_len = mx_strlen(gruop_info->gr_name);
        }
        else {
            if (my_lens->third_len < mx_intlen(user_info->pw_gid))
                my_lens->third_len = mx_intlen(user_info->pw_gid);
        }
}

static void count_second_colum(t_lens *my_lens, struct stat sb) {
    if (((sb.st_mode & S_IFCHR) == S_IFCHR 
        || (sb.st_mode & S_IFBLK) == S_IFBLK)
        && (sb.st_mode & S_IFDIR) != S_IFDIR
        && (sb.st_mode & S_IFREG) != S_IFREG
        && (sb.st_mode & S_IFLNK) != S_IFLNK) {
            my_lens->flag_device = 1;
        }
    if (my_lens->forth_len < mx_intlen(sb.st_size))
        my_lens->forth_len = mx_intlen(sb.st_size);
}

static t_lens *create_struckt() {
    t_lens *my_lens = (t_lens *)malloc(sizeof(t_lens));

    my_lens->first_len = 0;
    my_lens->second_len = 0;
    my_lens->third_len = 0;
    my_lens->minor_len = 0;
    my_lens->major_len = 0;
    my_lens->forth_len = 0;
    my_lens->blocks = 0;
    my_lens->flag_device = 0;

    return my_lens;
}

static char *build_path_l(char *dir_name, int *flag, char *sort_arr) {
    char *path_name_1 = NULL;

    if (sort_arr[0] != '/') {
        path_name_1 = mx_strjoin(dir_name, "/");
        path_name_1 = mx_strjoin_two(path_name_1, sort_arr);
        *flag = 1;
    }
    else
        path_name_1 = sort_arr;
    return path_name_1;
}

t_lens *mx_for_flagl_one(char **sort_arr, char *dir_name) {
    struct stat sb;
    t_lens *my_lens = create_struckt();
    int flag = 0;

    for (int i = 0; sort_arr[i] != NULL; i++) {
        char *path_name_1 = build_path_l(dir_name, &flag, sort_arr[i]);
        lstat(path_name_1, &sb);
        count_first_colum(my_lens, sb);
        count_second_colum(my_lens, sb);
        my_lens->blocks += sb.st_blocks;
        if (flag == 1) {
            mx_strdel(&path_name_1);
            flag = 0;
        }
    }
    return my_lens;
}
