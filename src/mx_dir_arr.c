#include "../inc/header.h"

char **mx_dir_arr(char **files) {
	///створює масив з папками і сортує за алфавітом;
	char **dir = NULL;
	int count = mx_files_quantity(files, 2);
	int i = 0;
	int q = 0;

	// if (count == 0)
	// 	return NULL;
	dir = (char **)malloc(sizeof(char *) * count + 1);
		for (i = 0; files[i]; i++) {
				if (mx_file_mode_check(files[i]) == 'd') {
					dir[q] = mx_str_copy(files[i]);
					q++;
				}
		}
		dir[q] = NULL;
		return dir;
}
