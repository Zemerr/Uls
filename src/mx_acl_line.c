#include "../inc/header.h"

static void f_specifited_one(struct stat sb, t_acl_trig *trigers,
char *my_acl_line) {
    if ((sb.st_mode & S_IFIFO) == S_IFIFO) {
        my_acl_line[0] = 'p';
        }
    if ((sb.st_mode & S_IFCHR) == S_IFCHR) {
        my_acl_line[0] = 'c';
        trigers -> dev_flag = 1;
    }
    if ((sb.st_mode & S_IFDIR) == S_IFDIR) {
        my_acl_line[0] = 'd';
        trigers -> dev_flag = 0;
    }
    if ((sb.st_mode & S_IFBLK) == S_IFBLK) {
        my_acl_line[0] = 'b';
        trigers -> dev_flag = 1;
    }
    if ((sb.st_mode & S_IFREG) == S_IFREG) {
        my_acl_line[0] = '-';
        trigers -> dev_flag = 0;
    }
}

static void f_specifited_two(struct stat sb, t_acl_trig *trigers,
char *my_acl_line) {
    if ((sb.st_mode & S_IFLNK) == S_IFLNK) {
        my_acl_line[0] = 'l';
        trigers -> l_flag = 1;
    }
    if ((sb.st_mode & S_IFSOCK) == S_IFSOCK) {
        my_acl_line[0] = 's';
        trigers -> dev_flag = 0;
        trigers -> l_flag = 0;
    }
}

static void f_specifited_three(struct stat sb, char *my_acl_line) {
    if ((sb.st_mode & S_IRUSR) == S_IRUSR) {
        my_acl_line[1] = 'r';
    }
    if ((sb.st_mode & S_IWUSR) == S_IWUSR) {
        my_acl_line[2] = 'w';
    }
    if ((sb.st_mode & S_IXUSR) == S_IXUSR) {
        my_acl_line[3] = 'x';
    }
    if ((sb.st_mode & S_ISUID) == S_ISUID) {
        my_acl_line[3] = 's';
    }
    if ((sb.st_mode & S_IRGRP) == S_IRGRP) {
        my_acl_line[4] = 'r';
    }
    if ((sb.st_mode & S_IWGRP) == S_IWGRP) {
        my_acl_line[5] = 'w';
    }
    if ((sb.st_mode & S_IXGRP) == S_IXGRP) {
        my_acl_line[6] = 'x';
    }
}

static void f_specifited_four(struct stat sb, char *my_acl_line) {
    if ((sb.st_mode & S_ISGID) == S_ISGID) {
        my_acl_line[6] = 's';
    }

    if ((sb.st_mode & S_IROTH) == S_IROTH) {
        my_acl_line[7] = 'r';
    }
    if ((sb.st_mode & S_IWOTH) == S_IWOTH) {
        my_acl_line[8] = 'w';
    }
    if ((sb.st_mode & S_IXOTH) == S_IXOTH) {
        my_acl_line[9] = 'x';
    }
    if ((sb.st_mode & S_ISVTX) == S_ISVTX) {
        my_acl_line[9] = 't';
    }
}

void mx_acl_line(struct stat sb, t_acl_trig *trigers,
char *my_acl_line) {
    f_specifited_one(sb, trigers, my_acl_line);
    f_specifited_two(sb, trigers, my_acl_line);
    f_specifited_three(sb, my_acl_line);
    f_specifited_four(sb, my_acl_line);
}
