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

// typedef struct s_flags {
// 	char flag;
// } t_flags;

typedef struct s_flags {
	int a;
	int A;
	int l;
	int G;
	int R;
} t_flags;

char **mx_files_in_dir(char *dir_name, char trig);
int mx_get_ws();
void mx_print_cols(char **arr, int count);
void mx_file_specified(char **files, t_flags *flags, char *file_name);
int mx_files_quantity(char **files, int trig);
char **mx_dir_arr(char **files);
char **mx_file_arr(char **files);
char mx_file_mode_check(char *file, char *file_name);
char *mx_str_copy(char *src);
void mx_define_flags(char *file_name, t_flags *flags);
void mx_flag_l(char **sort_arr, char *dir_name);
int mx_intlen(signed long long num);
void mx_colour_out(char *file, char *file_name);
void mx_flag_g(char **arr, int count, char *file_name);
void mx_recursion_call(char **obj, t_flags *flags, char *file_name);
t_flags *mx_flags_filter(char **argv, int count);

#endif
