#include "../inc/header.h"

char **mx_file_arr(char **files) {
	//повертає масив звичайних файлів;
	char **reg_file = NULL;
	int count = mx_files_quantity(files, 1);
	int i = 0;
	int q = 0;

	if (count == 0)
		return NULL;
	reg_file = (char **)malloc(sizeof(char *) * count + 1);
		for (i = 0; files[i]; i++) {
				if (mx_file_mode_check(files[i]) == 1) {
					reg_file[q] = mx_str_copy(files[i]);
					q++;
				}
		}
		reg_file[q] = NULL;
		return reg_file;
}
