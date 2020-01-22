#include "../inc/header.h"

char **mx_dir_arr(char **files) {
	///створює масив з папками і сортує за алфавітом;
	char **dir = NULL;
	int count = mx_files_quantity(files, 2);
	int i = 0;
	int q = 0;
	struct stat buf;
	// if (count == 0)
	// 	return NULL;
	dir = (char **)malloc(sizeof(char *) * count + 1);
		for (i = 0; files[i]; i++) {
			stat(files[i], &buf);
				if ((buf.st_mode & S_IFMT) == S_IFDIR) {
					// printf("dir = %d ", q);
					dir[q] = mx_str_copy(files[i]);
					q++;
				}
		}
		dir[q] = NULL;
		return dir;
}
