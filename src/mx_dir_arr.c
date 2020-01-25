#include "../inc/header.h"

char **mx_dir_arr(char **files) {
	char **dir = NULL;
	int count = mx_files_quantity(files, 2);
	int i = 0;
	int q = 0;
	struct stat buf;

	dir = (char **)malloc(sizeof(char *) * (count + 1));
		for (i = 0; files[i]; i++) {
			stat(files[i], &buf);
				if ((buf.st_mode & S_IFMT) == S_IFDIR) {
					dir[q] = mx_strdup(files[i]);
					q++;
				}
		}
		dir[q] = NULL;
		return dir;
}
