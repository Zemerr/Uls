#ifndef _HEADER_H_
#define _HEADER_H_

#include "../libmx/inc/libmx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <err.h>
#include <dirent.h>



#include <malloc/malloc.h>
#include <pwd.h>
#include <grp.h>

#include <sys/acl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <time.h>



// typedef struct s_flags {
// 	char flag;
// } t_flags;

typedef struct s_flags {
	int a;
	int A;
	int l;
	int G;
	int R;
    int S;
} t_flags;

typedef struct s_lens {
    int first_len;
    int second_len;
    int third_len;
    int minor_len;
    int major_len;
    int forth_len;
    int minor_major_len;
    unsigned long long blocks;
    unsigned int minor;
    unsigned int major;
    int flag_device;
} t_lens;

typedef struct s_acl_trig {
    int l_flag;
    int dev_flag;
    unsigned int minor;
    unsigned int major;
} t_acl_trig;


typedef struct s_sort {
    char *name;
    char *path;

    long long size;
}               t_sort;

void mx_sort_S(char **files, int dir_count, char *file_name);
char **mx_files_in_dir(char *dir_name, char trig, t_flags *flags);
int mx_get_ws();
void mx_print_cols(char **arr, int count);
void mx_file_specified(char **files, t_flags *flags, char *file_name);
int mx_files_quantity(char **files, int trig);
char **mx_dir_arr(char **files);
char **mx_file_arr(char **files);
char mx_file_mode_check(char *file, char *file_name, char *path_name);
char *mx_str_copy(char *src);
void mx_define_flags(char *file_name, t_flags *flags);
void mx_flag_l(char **sort_arr, char *dir_name, t_flags *flags);
int mx_intlen(signed long long num);
void mx_colour_out(char *file, char *file_name, char *path_name);
void mx_flag_g(char **arr, int count, char *file_name);
void mx_recursion_call(char **obj, t_flags *flags, char *file_name);
t_flags *mx_flags_filter(char **argv, int count);
t_lens *mx_for_flagl_one(char **sort_arr, char *dir_name);
char *mx_for_flagl_two(struct stat sb, t_acl_trig *trigers, char *path_name_1, 
char *my_asl_line);
void mx_acl_line(struct stat sb, t_acl_trig *trigers,
char *my_acl_line);
void mx_print_size_mm(t_lens *my_lens, struct stat sb, t_acl_trig *trigers);
void mx_print_name_acl(struct stat sb, char *my_acl_line, t_lens *my_lens);
void mx_print_link_update(char *path_name_1, t_acl_trig *trigers,
char *my_acl_line, char *sort_arr, int flag, t_flags *flags);
void mx_del_two_arr(char ***arr1, char ***arr2, char **str);
char *mx_find_path(char *file, char *file_name, char *path_name);

#endif
