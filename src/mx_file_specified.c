#include "../inc/header.h"

void mx_file_specified(char **files) {
	//вивід без флагів для вказаних файлів;
	char **dir = NULL;
	char **reg_file = NULL;
	int count = 0;

	reg_file = mx_file_arr(files);
	count = mx_files_quantity(files, 1);
	mx_bubble_sort(reg_file, count);
	mx_print_cols(reg_file, count);
	dir = mx_dir_arr(files);
	count = mx_files_quantity(files, 2);
	mx_bubble_sort(dir, count);
	for (int i = 0; dir[i]; i++) {
		write(1, "\n", 1);
		write(1, dir[i], mx_strlen(dir[i]));
		write(1, ":", 1);
		write(1, "\n", 1);
		mx_files_in_dir(dir[i]);
	}
	mx_del_strarr(&dir);
}
