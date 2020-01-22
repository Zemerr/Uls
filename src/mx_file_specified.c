#include "../inc/header.h"

void mx_file_specified(char **files, t_flags *flags, char *file_name) {
	//вивід без флагів для вказаних файлів;
	char **dir = NULL;
	char **reg_file = NULL;
	int count = 0;

	reg_file = mx_file_arr(files);
			count = mx_files_quantity(files, 1);
			if (count != 0) {
				mx_bubble_sort(reg_file, count);
				if ((*flags).l == 1) {
					mx_flag_l(reg_file, file_name);
				}
				else {
					mx_print_cols(reg_file, count, flags);
				}
			}

	dir = mx_dir_arr(files);

			count = mx_files_quantity(files, 2);
			mx_bubble_sort(dir, count);
			for (int i = 0; dir[i]; i++) {
					write(1, "\n", 1);
					write(1, dir[i], mx_strlen(dir[i]));
					write(1, ":", 1);
					write(1, "\n", 1);
				// printf("%s\n", dir[i]);
				mx_define_flags(dir[i], flags);
				// mx_files_in_dir(dir[i]);
			}
			mx_del_strarr(&dir);

}
