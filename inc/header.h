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

typedef struct s_flags {
	char flag;
	struct s_flags *next;
} t_flags;

void mx_files_in_dir(char *dir_name);
int mx_get_ws();
void mx_print_cols(char **arr, int count);
void mx_file_specified(char **files);
int mx_files_quantity(char **files, int trig);
char **mx_dir_arr(char **files);
char **mx_file_arr(char **files);
int mx_file_mode_check(char *file);
char *mx_str_copy(char *src);

#endif
