#ifndef _HEADER_H_
#define _HEADER_H_

#include "libmx/libmx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <err.h>
#include <dirent.h>
#include <malloc/malloc.h>
#include <pwd.h>
#include <grp.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <time.h>




#define O_RDWR          0x0002
#define TIOCGWINSZ      _IOR('t', 104, struct winsize)  /* get window size */
#define XATTR_NOFOLLOW   0x0001     /* Don't follow symbolic links */
#define ACL_TYPE_EXTENDED   0x00000100
#define IFMT 0170000
#define IFIFO 0010000
#define IFCHR 0020000
#define IFDIR 0040000
#define IFBLK 0060000
#define IFREG 0100000
#define IFLNK 0120000
#define IFSOCK 0140000
#define IRWXU 0000700
#define IRUSR 0000400
#define IWUSR 0000200
#define IXUSR 0000100
#define IRWXG 0000070
#define IRGRP 0000040
#define IWGRP 0000020
#define IXGRP 0000010
#define IRWXO 0000007
#define IROTH 0000004
#define IWOTH 0000002
#define IXOTH 0000001
#define ISUID 0004000
#define ISGID 0002000
#define ISVTX 0001000
#define ISBLK(m) (((m) & IFMT) == IFBLK)
#define ISCHR(m) (((m) & IFMT) == IFCHR)
#define ISDIR(m) (((m) & IFMT) == IFDIR)
#define ISFIFO(m) (((m) & IFMT) == IFIFO
#define ISREG(m) (((m) & IFMT) == IFREG)
#define ISLNK(m) (((m) & IFMT) == IFLNK)
#define ISSOCK(m) (((m) & IFMT) == IFSOCK)
#define major(x)        ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define minor(x)        ((int32_t)((x) & 0xffffff))

typedef struct s_flags {
	int a;
	int A;
	int l;
	int G;
	int R;
    int S;
    int t;
    int h;
    int u;
    int r;
    int C;
    int c;
    int one;
    int m;
    int g;
    int o;
    int T;
} t_flags;

typedef struct s_lens {
    int first_len;
    int second_len;
    int third_len;
    int minor_len;
    int major_len;
    int forth_len;
    unsigned long long blocks;
    int flag_device;
} t_lens;

typedef struct s_acl_trig {
    int l_flag;
    int dev_flag;
    unsigned int minor;
    unsigned int major;
    int path_flag;
} t_acl_trig;


typedef struct s_sort {
    char *name;
    char *path;
    long long size;
} t_sort;

void mx_sort_S(char **files, int dir_count, char *file_name);
char **mx_files_in_dir(char *dir_name, char trig, t_flags *flags);
int mx_get_ws();
void mx_print_cols(char **arr, int count, t_flags *flags);
void mx_file_specified(char **files, t_flags *flags, char *file_name, int size);
int mx_files_quantity(char **files, int trig);
char **mx_dir_arr(char **files);
char **mx_file_arr(char **files, int size);
char mx_file_mode_check(char *file, char *file_name);
char *mx_str_copy(char *src);
void mx_define_flags(char *file_name, t_flags *flags);
void mx_flag_l(char **sort_arr, char *dir_name, t_flags *flags);
int mx_intlen(signed long long num);
void mx_colour_out(char *file, char *file_name);
void mx_flag_g(char **arr, int count, char *file_name);
void mx_recursion_call(char **obj, t_flags *flags, char *file_name);
t_flags *mx_flags_filter(char *str);
t_lens *mx_for_flagl_one(char **sort_arr, char *dir_name);
char *mx_for_flagl_two(struct stat sb, t_acl_trig *trigers, char *path_name_1, 
char *my_asl_line);
void mx_acl_line(struct stat sb, t_acl_trig *trigers,
char *my_acl_line);
void mx_print_size_mm(t_lens *my_lens, struct stat sb, t_acl_trig *trigers,
t_flags *flags);
void mx_print_name_acl(struct stat sb, char *my_acl_line, t_lens *my_lens,
t_flags *flags);
void mx_del_two_arr(char ***arr1, char ***arr2, char **str);
char *mx_find_path(char *file, char *file_name);
void mx_flag_sort(char *file_name, char **files, int size, t_flags *flags);
void mx_upgraded_sort(struct stat *info, t_flags *flags, char **files);
void mx_simple_out(char **files, t_flags *flag, char *file_name);
void mx_print_error_file(char *error_file);
void mx_flag_file_valid(char ***file, char **flags, char **obj, int n);
void mx_print_link_update(char *path_name_1, t_acl_trig *trigers,
char *my_acl_line);
void mx_print_name(char *sort_arr, t_flags *flags, char *dir_name);
void mx_print_time(struct stat sb, t_flags *flags);
char *mx_for_flag_h(long i);


#endif
